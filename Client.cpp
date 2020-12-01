<<<<<<< HEAD
<<<<<<< HEAD
#include "Exam.hpp"
#include "UserData.hpp"
#include <iostream>
#include <signal.h>
#include <sstream> //a library addad by me
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
=======
=======
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
#include "UserData.hpp"
#include "Exam.hpp"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
<<<<<<< HEAD
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
=======
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/types.h>
<<<<<<< HEAD
<<<<<<< HEAD
#include <vector>

// ui
const int WIDTH = 83;
const int HEIGHT = 27;

const string COLOR_HEADER = "46;30m";
const string COLOR_MAIN_STRING = "47;30m";
const string COLOR_EMPHASIS_STRING = "40;37m";

const string LIST1 = "1. echo 명령어 이용";
const string LIST2 = "2. cat 명령어 이용";
const string LIST_END = "3. 프로그램 종료";

void screen_Output();
void Header();
void print_String(string content, string color = "0m", string T_F = "F");
void print_Blank(int num, string color = "0m", string T_F = "F");
void print_Hyphen(int print_length, string color = "0m", string T_F = "F");
void newLine(string T_F);
void blank_Frame(int num);
void screen_Output2(vector<string> &vec); // added by me

#define MAX_SHM_SIZE 512

using namespace std;
char *strToChar(string str);
=======
=======
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
#include <iostream>
#include <string>
#include <vector>

#define MAX_SHM_SIZE 512

using namespace std;
char* strToChar(string str);
<<<<<<< HEAD
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
=======
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
void signalHandler(int signum);
void inputAnswer(void);
void showExam(Exam *exam);

pid_t myPid;

key_t myKey = 0;
int msqid = 0;
<<<<<<< HEAD
<<<<<<< HEAD
char name[MAX_NAME_LEN + 1];
=======
char name[MAX_NAME_LEN+1];
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
=======
char name[MAX_NAME_LEN+1];
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
MsgUserData userData;
MsgExamData examData;

key_t shmKey = 0;
int shmId = 0;
Exam *exam;

bool isConnected = 0;

int main(int argc, char const *argv[])
{
    myPid = getpid();
<<<<<<< HEAD
<<<<<<< HEAD
    // initial msgqueue
    myKey = ftok("userConn", 3);
    int msqid = msgget(myKey, IPC_CREAT);

    // initial sharedmem
    shmKey = ftok("examState", 4);
    shmId = shmget(shmKey, MAX_SHM_SIZE, IPC_CREAT);
    exam = (Exam *)shmat(shmId, NULL, 0);
=======
=======
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
    //initial msgqueue
    myKey = ftok("userConn", 3);
    int msqid = msgget(myKey, IPC_CREAT);

    //initial sharedmem
    shmKey = ftok("examState",4);
    shmId = shmget(shmKey,MAX_SHM_SIZE,IPC_CREAT);
    exam = (Exam*)shmat(shmId, NULL, 0);
<<<<<<< HEAD
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
=======
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292

    signal(SIGUSR1, signalHandler);
    while (1)
    {
<<<<<<< HEAD
<<<<<<< HEAD
        if (!isConnected)
        {
=======
        if(!isConnected){
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
=======
        if(!isConnected){
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
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
<<<<<<< HEAD
<<<<<<< HEAD
        }
        else
        {
=======
        }else{
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
=======
        }else{
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
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

<<<<<<< HEAD
<<<<<<< HEAD
char *strToChar(string str)
{

    std::vector<char> writable(str.begin(), str.end());
    writable.push_back('\0');
    char *ptr = &writable[0];
=======
char* strToChar(string str){

    std::vector<char> writable(str.begin(), str.end());
    writable.push_back('\0');
    char* ptr = &writable[0];
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
=======
char* strToChar(string str){
    
    std::vector<char> writable(str.begin(), str.end());
    writable.push_back('\0');
    char* ptr = &writable[0];
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
    return ptr;
}
void signalHandler(int signum)
{
    if (signum == SIGUSR1)
<<<<<<< HEAD
<<<<<<< HEAD
    {
=======
    {
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
=======
    {   
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
        system("clear");
        showExam(exam);
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
void inputAnswer(void)
{
=======
void inputAnswer(void){
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
=======
void inputAnswer(void){
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
    cout << "답: ";
    scanf("%s", name);
    fflush(stdout);
    fflush(stdin);
<<<<<<< HEAD
<<<<<<< HEAD
    cout << "debug1" << endl;
    memset(&examData, 0x00, sizeof(MsgExamData));
    examData.mtype = MSG_EXAM_TYPE;
    examData.pid = myPid;
    cout << "debug2" << endl;
    strcpy(examData.answer, name);
    msgsnd(msqid, &examData, MSG_DATA_SIZE, 0);
    cout << "debug3" << endl;
}

// ui
void screen_Output()
{
    system("clear");

    Header();

    print_Hyphen(WIDTH, COLOR_MAIN_STRING, "T");

    for (int i = 0; i < HEIGHT - 3; i++)
        blank_Frame(WIDTH - 2);
    print_Hyphen(WIDTH, COLOR_MAIN_STRING, "T");

} // 화면 초기화 및 인터페이스의 전체적인 틀 출력

void Header()
{
    string str = "Linux Tutorial";
    print_String(str, COLOR_HEADER);
    print_Blank(WIDTH - str.length(), COLOR_HEADER, "T");
} // 인터페이스의 상단 바 출력

void print_String(string content, string color, string T_F)
{
    cout << "\033[" + color + content + "\033[0m";
    newLine(T_F);
}
// 색 있는 글자 출력("글자", "글자 색깔", "T")
// T 또는 t 입력 시 공백 출력 후 개행, 이외의 입력 혹은 입력하지 않을시 무시
// 글자 색깔은 "(배경number;색number)m" 입력 ex) "46;30m"

void print_Blank(int num, string color, string T_F)
{
    string blank;
    for (int i = 0; i < num; i++)
        blank.append(" ");
    print_String(blank, color);
    newLine(T_F);
}
// 입력받은 숫자만큼 공백 출력 ("숫자" "(배경number;색number)m" "t")
// T 또는 t 입력 시 공백 출력 후 개행, 이외의 입력 혹은 입력하지 않을시 무시

void print_Hyphen(int print_length, string color, string T_F)
{
    string num_hyphen;
    for (int i = 0; i < print_length; i++)
        num_hyphen.append("-"); /* code */
    print_String(num_hyphen, color);
    newLine(T_F);
}
// 입력받은 숫자만큼 - 출력 후 개행 (출력할 - 갯수, "글자 색깔")
// T 또는 t 입력 시 공백 출력 후 개행, 이외의 입력 혹은 입력하지 않을시
// 무시print_String

void newLine(string T_F)
{
    if (strcmp(T_F.data(), "T") == 0 || strcmp(T_F.data(), "t") == 0)
        cout << endl;
    else
        return;
} // T 또는 t 입력 시 공백 출력 후 개행, 이외의 입력은 무시
// 함수 내에서 사용자의 입력에 따라 동작하기 위한 목적으로 만든 함수

void blank_Frame(int num)
{
    print_String("|", COLOR_MAIN_STRING);
    print_Blank(num, COLOR_MAIN_STRING);
    print_String("|", COLOR_MAIN_STRING, "T");
}

// A Block code added by me (Client.cpp + Ui.cpp)
void screen_Output2(vector<string> &tstlst)
{
    int count = 0;
    system("clear");
    Header();
    print_Hyphen(WIDTH, COLOR_MAIN_STRING, "T");
    for (int i = 0; i < tstlst.size(); i++)
    {
        print_String("|", COLOR_MAIN_STRING);
        print_String(tstlst[i], COLOR_MAIN_STRING);
        print_Blank(WIDTH - 2 - tstlst[i].length(), COLOR_MAIN_STRING);
        print_String("|", COLOR_MAIN_STRING);
        count++;
        cout << "\n";
    }
    for (int i = 0; i < HEIGHT - count - 3; i++)
    {
        print_String("|", COLOR_MAIN_STRING);
        print_String("", COLOR_MAIN_STRING);
        print_Blank(WIDTH - 2, COLOR_MAIN_STRING);
        print_String("|", COLOR_MAIN_STRING);
        cout << "\n";
    }
    print_Hyphen(WIDTH, COLOR_MAIN_STRING, "T");
}
//--------------------------------------------------
// Changed for dsiplaying a qustion and a questions number
void showExam(Exam *exam)
{

    vector<string> printstr;
    string a, b, c;
    int nn = (exam->getNum());
    stringstream sts;
    sts << nn;
    string out_string = sts.str();
    a = ("Number:" + out_string);
    b = ("Question:" + exam->getDes());
    c = ("Answer:");

    printstr.push_back(a);
    printstr.push_back(b);
    printstr.push_back(c);
    screen_Output2(printstr);
}
=======
=======
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
    cout <<"debug1"<<endl;
    memset(&examData, 0x00, sizeof(MsgExamData));
    examData.mtype = MSG_EXAM_TYPE;
    examData.pid = myPid;
    cout <<"debug2"<<endl;
    strcpy(examData.answer, name);
    msgsnd(msqid, &examData, MSG_DATA_SIZE, 0);
    cout <<"debug3"<<endl;
}
void showExam(Exam *exam){
    cout << "Num : " << exam->getNum() <<endl;
    cout << "문제 : " << exam->getDes() << endl;
    cout << "답 : " << endl;
<<<<<<< HEAD
}
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
=======
}
>>>>>>> 11501d76af92fdd8c9d2952a8f40ede1507c8292
