#include "Exam.hpp"
#include "UI.hpp"
#include "UserData.hpp"
#include <iostream>
#include <signal.h>
#include <sstream> //a library addad by me
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <vector>

void screen_Output_Client(vector<string> vec); // added by me

#define MAX_SHM_SIZE 512

using namespace std;
char *strToChar(string str);
void signalHandler(int signum);
void inputAnswer(void);
void showExam(Exam *exam);

pid_t myPid;

key_t myKey = 0;
int msqid = 0;
char name[MAX_NAME_LEN + 1];
MsgUserData userData;
MsgExamData examData;
vector<UserData> users;

key_t shmKey = 0;
int shmId = 0;
Exam *exam;

bool isConnected = 0;

int main(int argc, char const *argv[]) {
    myPid = getpid();
    // initial msgqueue
    myKey = ftok("userConn", 3);
    int msqid = msgget(myKey, IPC_CREAT);

    // initial sharedmem
    shmKey = ftok("examState", 4);
    shmId = shmget(shmKey, MAX_SHM_SIZE, IPC_CREAT);
    exam = (Exam *)shmat(shmId, NULL, 0);

    signal(SIGUSR1, signalHandler);
    while (1) {
        if (!isConnected) {
            cout << "닉네임을 입력해주세요 : ";
            scanf("%s", name);
            fflush(stdout);
            fflush(stdin);

            memset(&userData, 0x00, sizeof(MsgUserData));
            userData.mtype = MSG_DATA_TYPE;
            userData.pid = myPid;
            strcpy(userData.name, name);
            msgsnd(msqid, &userData, MSG_DATA_SIZE, 0);
            isConnected = 1;
            pause();
        } else {
            string str;
            getline(cin, str);
            memcpy(name, str.c_str(), MAX_NAME_LEN);
            fflush(stdout);
            fflush(stdin);
            memset(&examData, 0x00, sizeof(MsgExamData));
            examData.mtype = MSG_EXAM_TYPE;
            examData.pid = myPid;
            strcpy(examData.answer, name);
            msgsnd(msqid, &examData, MSG_DATA_SIZE, 0);
        }
    }
    return 0;
}

char *strToChar(string str) {

    std::vector<char> writable(str.begin(), str.end());
    writable.push_back('\0');
    char *ptr = &writable[0];
    return ptr;
}
void signalHandler(int signum) {
    if (signum == SIGUSR1) {
        system("clear");
        showExam(exam);
    }
}
void inputAnswer(void) {
    cout << "답: ";
    scanf("%s", name);
    fflush(stdout);
    fflush(stdin);
    cout << "debug1" << endl;
    memset(&examData, 0x00, sizeof(MsgExamData));
    examData.mtype = MSG_EXAM_TYPE;
    examData.pid = myPid;
    cout << "debug2" << endl;
    strcpy(examData.answer, name);
    msgsnd(msqid, &examData, MSG_DATA_SIZE, 0);
    cout << "debug3" << endl;
}

// A Block code added by me (Client.cpp + Ui.cpp)
void screen_Output_Client(vector<string> tstlst) {
    string str1, str2;
    int ypos = 2;
    screen_Output();

    if (tstlst[1].length() > WIDTH - 2) {
        str1 = tstlst[1].substr(0, WIDTH - 2);
        str2 = tstlst[1].substr(WIDTH - 1, tstlst[1].length());
        for (int i = 0; i < 3; i++) {
            string cursor_positioin = "tput cup " + to_string(ypos) + " 1";
            system(cursor_positioin.c_str());
            if (i == 1) {
                print_String(str1, COLOR_MAIN_STRING, "T");
                ypos++;
                string cursor_positioin = "tput cup " + to_string(ypos) + " 1";
                system(cursor_positioin.c_str());
                print_String(str2, COLOR_MAIN_STRING, "T");
                ypos++;
                continue;
            } // length가 긴 문제를 두개로 분할하여 출력
            print_String(tstlst[i], COLOR_MAIN_STRING, "T");
            ypos++;
        }
    } else {
        for (int i = 0; i < 3; i++) {
            string cursor_positioin = "tput cup " + to_string(ypos) + " 1";
            system(cursor_positioin.c_str());
            print_String(tstlst[i], COLOR_MAIN_STRING, "T");
            ypos++;
        }
    }
    string cursor_positioin = "tput cup " + to_string(ypos - 1) + " " +
                              to_string(tstlst[2].length() + 1);
    system(cursor_positioin.c_str());
    system("tput sc");

    ypos = HEIGHT - 6;
    for (int i = 3; i < tstlst.size(); i++) {
        string cursor_positioin = "tput cup " + to_string(ypos) + " 1";
        system(cursor_positioin.c_str());
        print_String(tstlst[i], COLOR_MAIN_STRING, "T");
        ypos++;
    }
    system("tput rc");
}
//--------------------------------------------------
// Changed for dsiplaying a qustion and a questions number
void showExam(Exam *exam) {

    vector<string> printstr;
    string a, b, c;
    int nn = (exam->getNum());
    stringstream sts;
    sts << nn;
    string out_string = sts.str();
    a = ("Number : " + out_string);
    b = ("Question : " + exam->getDes());
    c = ("Answer : ");
    printstr.push_back(a);
    printstr.push_back(b);
    printstr.push_back(c);

    // user정보들 디버깅용
    users = exam->getUserInfo();
    for (int i = 0; i < users.size(); i++) {
        string s = "userPid : " + to_string(users.at(i).getPid()) +
                   ", userName : " + users.at(i).getName() +
                   ", userScore : " + to_string(users.at(i).getScore());
        printstr.push_back(s);
    }
    // user정보들 디버깅용

    screen_Output_Client(printstr);
}
