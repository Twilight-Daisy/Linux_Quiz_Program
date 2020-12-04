#include <string>
#include <string.h>
#include <vector>
#include "UserData.hpp"
using namespace std;

#define MAX_NAME_LEN 100
#define MAX_USER_SIZE 6

class Exam
{
public:
    Exam();
    Exam(int num, string description, string hint, string answer);
    
    int getNum();
    string getDes();
    string getHint();
    string getAnswer();
    vector<UserData> getUserInfo();
    int getUsersSize();

    
    void setNum(int num);
    void setDes(string desc);
    void setHint(string hint);
    void setAnswer(string answer);
    void setUserInfo(vector<UserData> userInfo);

    void printExam(void);

private:
    int num;
    char description[MAX_NAME_LEN+1];
    char hint[MAX_NAME_LEN+1];
    char answer[MAX_NAME_LEN+1];
    UserDataStruct userInfo[MAX_USER_SIZE];
    int userInfoSize;
};
