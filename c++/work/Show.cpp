#include <iostream>
#include "Student.h"
using namespace std;

void Administrator()
{
    int select1 = 0, select2 = 0;
    cout << "请选择你的要选择的功能" << endl;
    cout << "1.班级成员信息管理" << endl;
    cout << "2.考勤信息管理" << endl;
    cout << "0.退出" << endl;
    cin >> select1;
    switch(select1)
    {
        case 0:
            return;
        case 1:
            break;
        case 2:
            cout << "1.添加考勤信息" << endl;
            cin >> select2;
            switch(select2)
            {
                case 1:
                    addAttendance();
                    break;
            }
    }
}
