#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

typedef long long ll;
struct Attendance //考勤信息结构体
{
    int week; //第几周
    int day; //星期几
    int lession; //第几节课
    //出勤情况：
    //1－出勤，2－迟到，3－旷课，4－请假
    int attendance;
    double rate; //出勤率
    //考勤信息是否有效，如果考勤信息被删除，则该考勤信息无效
    bool effectiveness;
};

struct Student //学生个人信息结构体
{
    int number; //班里序号
    ll id; //学号
    string name; //姓名
    //管理员权限：
    //1：管理员，2：班委，3：班级成员
    int permission; 
    Attendance attend[20]; //第几周的考勤情况
};

extern int studentNum; //最多学生人数
typedef struct //线性表存储考勤信息
{
    Student student[70];
    int stuN; //线性表当前长度
}Stu;

extern Stu stu; //定义全局变量

//设置班级成员为班委;
const bool setCommittee(const ll id);

//添加班里序号为n的学生的考勤信息
const bool addAttendance(const int num, const Attendance att);

//删除学号为id的学生的考勤信息
bool Delete(ll id);

//修改学号为id的学生的考勤信息
bool Modify(ll id, Attendance attend);

//查找学号为id的学生的第d周考勤信息
bool Find(ll id, int d);

//统计每个学生第d周出勤率
double Rate(int d);

//对每个学生第d周出勤率进行排序
bool Sort(int d);

//对全班学生第d周的出勤率进行浏览
bool rateAll(int d);

//显示管理员操作页面
void Administrator();
#endif
