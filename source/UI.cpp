#include "UI.hpp"
#include "Exam.hpp"
#include <iostream>
#include <stdlib.h> // system 명령어 사용
#include <string.h> // strcmp 명령어 사용
#include <string>

using namespace std;

// c++에서 echo -e(개행문자 사용)는 인식되지 않으며 자동 적용되어있는 상태이다
// \"를 써야 따옴표가 인식된다
// -n(끝에서 개행하지 않음)은 자동 적용되어있지 않다

// ★★★
// 아래 함수와 tput을 같이 사용할 경우 의미가 없을지라도 반드시 개행을 진행해야
// 합니다. 그렇지 않으면 tput 명령어가 모두 무시됩니다!!!

void screen_Output() {
    system("clear");
    Header();
    print_Hyphen(WIDTH, COLOR_MAIN_STRING, "T");
    for (int i = 0; i < HEIGHT - 3; i++)
        blank_Frame(WIDTH - 2);
    print_Hyphen(WIDTH, COLOR_MAIN_STRING, "T");
} // 화면 초기화 및 인터페이스의 전체적인 틀 출력

void Header() {
    string str = "Linux Tutorial";
    print_String(str, COLOR_HEADER);
    print_Blank(WIDTH - str.length(), COLOR_HEADER, "T");
} // 인터페이스의 상단 바 출력

void print_String(string content, string color, string T_F) {
    cout << "\033[" + color + content + "\033[0m";
    newLine(T_F);
} // 색 있는 글자 출력("글자", "글자 색깔", "T")
// T 또는 t 입력 시 공백 출력 후 개행, 이외의 입력 혹은 입력하지 않을시 무시
// 글자 색깔은 "(배경number;색number)m" 입력 ex) "46;30m"

void print_Blank(int num, string color, string T_F) {
    string blank;
    for (int i = 0; i < num; i++)
        blank.append(" ");
    print_String(blank, color);
    newLine(T_F);
} // 입력받은 숫자만큼 공백 출력 ("숫자" "(배경number;색number)m" "t")
// T 또는 t 입력 시 공백 출력 후 개행, 이외의 입력 혹은 입력하지 않을시 무시

void print_Hyphen(int print_length, string color, string T_F) {
    string num_hyphen;
    for (int i = 0; i < print_length; i++)
        num_hyphen.append("-"); /* code */
    print_String(num_hyphen, color);
    newLine(T_F);
} // 입력받은 숫자만큼 - 출력 후 개행 (출력할 - 갯수, "글자 색깔")
// T 또는 t 입력 시 공백 출력 후 개행, 이외의 입력 혹은 입력하지 않을시
// 무시print_String

void newLine(string T_F) {
    if (strcmp(T_F.data(), "T") == 0 || strcmp(T_F.data(), "t") == 0)
        cout << endl;
    else
        return;
} // T 또는 t 입력 시 공백 출력 후 개행, 이외의 입력은 무시
// 함수 내에서 사용자의 입력에 따라 동작하기 위한 목적으로 만든 함수

void blank_Frame(int num) {
    print_String("|", COLOR_MAIN_STRING);
    print_Blank(num, COLOR_MAIN_STRING);
    print_String("|", COLOR_MAIN_STRING, "T");
} // 인터페이스에서 공간이 빈 한 줄 생성

// void indicate_Exams_Types() {
//     system("tput sc");
//     system("tput cup 2 1");
//     print_String(LIST1, COLOR_MAIN_STRING, "T");
//     system("tput cup 3 1");
//     print_String(LIST2, COLOR_MAIN_STRING, "T");
//     system("tput cup 21 1");
//     print_String(LIST_END, COLOR_MAIN_STRING, "T");

//     system("tput rc");
// } // cout에 endl을 쓰지 않을 경우 tput이 제대로 동작되지 않음
// // 문제 목록을 화면에 출력하는 함수

// void check_Command() {
//     Exam exam1(EXAM_PRACTICE,
//                "echo 명령어를 이용하여 hello world 를 출력하시오 ",
//                "echo (문구) 을(를)이용하세요", "echo", "echo hello world");

//     Exam exam2(EXAM_PRACTICE,
//                "cat 명령어를 이용하여 sampleText 파일을 출력하시오 ",
//                "cat (파일이름) 을(를)이용하세요", "cat", "cat sampleText");

//     int num;
//     while (1) {
//         system("tput sc");
//         system("tput cup 23 1");
//         print_String("메뉴를 선택하세요 : ", COLOR_MAIN_STRING);

//         cout << "\033[" + COLOR_MAIN_STRING;
//         cin >> num;
//         cout << "\033[0m" << endl;

//         system("tput cup 25 0");
//         blank_Frame(WIDTH - 2);
//         // cin을 입력받으면 출력했던 줄 빈칸으로 초기화

//         if (cin.fail()) {
//             cin.clear();
//             cin.ignore(256, '\n');
//             screen_Output();
//             indicate_Exams_Types();
//             system("tput cup 25 1");
//             print_String("숫자를 입력하세요.", COLOR_EMPHASIS_STRING, "T");
//             system("tput rc");
//             continue;
//         } // 숫자 외 입력 예외처리

//         switch (num) {
//         case 1:
//             cin.ignore(4, '\n');
//             system("tput rc");
//             indicate_Exams(LIST1, exam1);
//             screen_Output();
//             indicate_Exams_Types();
//             continue;
//         case 2:
//             cin.ignore(4, '\n');
//             system("tput rc");
//             indicate_Exams(LIST2, exam2);
//             screen_Output();
//             indicate_Exams_Types();
//             continue;
//         case 3:
//             system("tput cup 25 1");
//             print_String("프로그램을 종료합니다.", COLOR_EMPHASIS_STRING,
//             "T"); system("tput rc"); exit(1);
//         default:
//             screen_Output();
//             indicate_Exams_Types();
//             system("tput cup 25 1");
//             print_String("입력된 번호와 일치하는 목록이 없습니다.",
//                          COLOR_EMPHASIS_STRING, "T");
//             system("tput rc");
//             continue;
//         }
//     }
// } // 사용자에게 숫자를 입력받고 실행하는 함수

// void indicate_Exams(Exam exam) {
//     int error = 0;
//     string input;
//     const char *c = input.c_str();
//     while (1) {
//         system("tput sc");
//         screen_Output();

//         if (error) {
//             system("tput cup 11 1");
//             system("echo -n \"\033[47;30m\"");
//             system(c);
//             system("tput cup 25 1");
//             print_String("틀렸습니다!! 다시 입력해주세요.",
//                          COLOR_EMPHASIS_STRING, "T");
//         }

//         system("tput cup 2 1");
//         print_String(header, COLOR_MAIN_STRING, "T");
//         system("tput cup 3 1");
//         print_String(exam.getDes(), COLOR_MAIN_STRING, "T");
//         system("tput cup 4 1");
//         print_String("------------힌트------------", COLOR_MAIN_STRING, "T");
//         system("tput cup 5 1");
//         print_String(exam.getHint(), COLOR_MAIN_STRING, "T");
//         system("tput cup 6 1");
//         print_String("----------실행 예시----------", COLOR_MAIN_STRING,
//         "T"); system("tput cup 7 1"); system("echo -n \"\033[47;30m\"");
//         system(exam.getAnswer().c_str());

//         system("tput cup 9 1");
//         print_String("명령어 입력 : ", COLOR_MAIN_STRING);
//         cout << "\033[" + COLOR_MAIN_STRING;
//         getline(cin, input);
//         cout << "\033[0m" << endl;

//         c = input.c_str();
//         if (input == exam.getAnswer()) {
//             system("tput cup 11 0");
//             for (int i = 11; i < HEIGHT - 1; i++)
//                 blank_Frame(WIDTH - 2);
//             // 오답일 때 출력하는 공간 전체를 빈칸으로 초기화
//             system("tput cup 11 1");
//             system("echo -n \"\033[47;30m\"");
//             system(c);
//             system("tput cup 24 1");
//             print_String("맞았습니다!!!", COLOR_EMPHASIS_STRING, "T");
//             system("tput cup 25 1");
//             print_String("Enter를 누르면 메인화면으로 돌아갑니다.",
//                          COLOR_EMPHASIS_STRING, "T");
//             system("tput rc");
//             char ch;
//             while (1) {
//                 cin.get(ch);
//                 if (ch == '\n')
//                     return;
//             }
//         } else {
//             error = 1;
//             system("tput rc");
//             continue;
//         }
//     }
// } // 문제를 출력하는 함수
