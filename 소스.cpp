#include <iostream>
#include <string>
#include "Exam.h"

using namespace std;

void printExam(Exam exam);

int main()
{
    system("clear");
   
    Exam exam1(EXAM_PRACTICE, "���� �ڽ��� ��ġ�ϴ� ���丮�� ����Ͻÿ� ", "_rint _orking _irectory", "pwd", "pwd /home/ubuntu");

    Exam exam2(EXAM_PRACTICE, "Practice1�� ���丮 �������� ���� �� �������� ����ϼ���  ", "_ist _egments", "ls", "ls code/ game/ git/ lib/ workspace/");

    Exam exam3(EXAM_PRACTICE, "Practice2�� ���丮 ������, game ���丮�� �̵��Ͻÿ�  ", "_hange _irectory", "cd game/", "cd game/");

    Exam exam4(EXAM_PRACTICE, "Practice3�� ���丮����, �ٽ� home ���丮�� �̵��Ͻÿ�  ", "_hange _irectory ~", "cd ~", "cd ~ /home/ubuntu");

    Exam exam5(EXAM_PRACTICE, "Practice4�� ���丮����, dir1 ���丮�� �����Ͻÿ�  ", "_ake _irectory dir1 ", "mkdir dir1", "mkdir dir1\nls dir1/");

    Exam exam6(EXAM_PRACTICE, "Practice5���� ������ ���丮 dir1�� dat ���� file1�� �����ϰ� ����Ͻÿ�  ", " _____ (file name).dat", "touch file1.dat ls", "ls\nfile1.dat");
    
    Exam exam7(EXAM_PRACTICE, "Practice5���� ������ ���丮����, ���� ���丮�� dir2 ���丮�� �����Ͻÿ�  ", "_ake _irectory -p  ", "mkdir -p dir1/dir2", "(blank)");

    Exam exam8(EXAM_PRACTICE, "Practice7���� ������ ���丮 ������ �������� �������� ��Ÿ���ÿ�  ", " ____ (parent directory)/ ", "tree dir1/", "dir1\n��_____dir2\n��__file1");

    Exam exam9(EXAM_PRACTICE, "Practice7���� ������ ���丮���� dir1�� ���丮 ���� ��ɾ�� �����Ͻÿ�  ", " _move dir, ���� ���丮�� �Բ� �����Ͻÿ� ", "rmdir -p dir1/dir2/", "rmdir: failed to remove 'dir1/dir2/': Directory not empty");

    Exam exam10(EXAM_PRACTICE, "Practice8���� �߰ߵ� ������ �����ϰ� ����Ͻÿ�  ", "������ �ִ� ���丮�� ���� ��ɾ ����Ͻÿ� ", "rm -r dir1/ ls", "$ ");

 

    cout << "Practice 1" << endl;
    printExam(exam1);
    cout << endl;
    cout << endl;
    cout << "Practice 2" << endl;
    printExam(exam2);
    cout << endl;
    cout << endl;
    cout << "Practice 3" << endl;
    printExam(exam3);
    cout << endl;
    cout << endl;
    cout << "Practice 4" << endl;
    printExam(exam4);
    cout << endl;
    cout << endl;
    cout << "Practice 5" << endl;
    printExam(exam5);
    cout << endl;
    cout << endl;
    cout << "Practice 6" << endl;
    printExam(exam6);
    cout << endl;
    cout << endl;
    cout << "Practice 7" << endl;
    printExam(exam7);
    cout << endl;
    cout << endl;
    cout << "Practice 8" << endl;
    printExam(exam8);
    cout << endl;
    cout << endl;
    cout << "Practice 9" << endl;
    printExam(exam9);
    cout << endl;
    cout << endl;
    cout << "Practice 10" << endl;
    printExam(exam10);


    return 0;
}

void printExam(Exam exam) {
    cout << exam.getDes() << endl;
    cout << "------------��Ʈ------------ " << endl;
    cout << exam.getHint() << endl;
    cout << "----------���� ����---------- " << endl;
    system(exam.getAnswer().c_str());

    while (1)
    {
        cout << endl;
        cout << "��ɾ� �Է� : ";
        string input;
        getline(cin, input);
        const char* c = input.c_str();
        if (input == exam.getAnswer())
        {
            system(input.c_str());
            cout << "�¾ҽ��ϴ�!!" << endl;
            break;
        }
        else
        {
            system(c);
            cout << "Ʋ�Ƚ��ϴ�!! �ٽ� �Է����ּ���." << endl;
            continue;
        }
    }
}