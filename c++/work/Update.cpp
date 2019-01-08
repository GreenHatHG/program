#include "Student.h"
#include <iostream>
using namespace std;

//学生学号和考勤信息
const bool addAttendance()
{
    if(stu.stuN == studentNum)
    {
        cout << "存储人数过多" << endl;
        return false;
    }
    int num;
    Attendance tmp;
    cout << "请输入你要添加的学生的班级序号" << endl;
    cin >> num;
    cout << "请输入周数" << endl;
    cin >> tmp.week;
    cout << "请输入星期数" << endl;
    cin >> tmp.day;
    cout << "请输入第几节课" << endl;
    cin >> tmp.lession;
    cout << "请输入出勤情况" << endl;
    cout << "1－到场，2－迟到，3－旷课，4－请假" << endl;
    cin >> tmp.attendance;
    stu.student[num].attend[att.week]=att;
    cout << "添加成功" << endl;
    return true;
}
