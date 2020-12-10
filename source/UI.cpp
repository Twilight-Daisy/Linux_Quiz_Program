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
