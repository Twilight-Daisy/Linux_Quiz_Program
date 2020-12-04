#include <string>

using namespace std;

const int WIDTH = 83;  // 가로 길이
const int HEIGHT = 27; // 세로 길이

const string COLOR_HEADER = "46;30m";
const string COLOR_MAIN_STRING = "47;30m";
const string COLOR_EMPHASIS_STRING = "40;37m";
// 색상 코드

void screen_Output();
void Header();
void print_String(string content, string color = "0m", string T_F = "F");
void print_Blank(int num, string color = "0m", string T_F = "F");
void print_Hyphen(int print_length, string color = "0m", string T_F = "F");
void newLine(string T_F);
void blank_Frame(int num);
