#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream file("exams_translated.txt");
    if (true == file.is_open())
    {
        std::string s;
        while (file)
        {
            getline(file, s);
            if(s.empty())
                continue;
            int num = s.find(".");
            if(num!=-1){
                cout << "num : " << s.substr(0,num) << ", 문제 : " << s.substr(num+1) << endl;;    
            }else{
                cout <<"답 : "<< s << endl;
            }
            // std::cout << s << std::endl;
        }
        file.close();
    }
    else { std::cout << "file open fail" << std::endl; }

    return 0;
}