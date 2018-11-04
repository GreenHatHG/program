#include <iostream>
#include <regex>
#include <string>
#include <cmath>
using namespace std;

int main()
{
   // string str = "123x^2+12*x-154=0"; //123,12,-154
   // string str = "x^2+12*x-154=0"; //1, 12, -154
   // string str = "-x^2+12*x=0";  //-1, 12, 0
   // string str = "x^2+x-1=0"  //1, 0, -1
   // string str = "x^2=0"; //1, 0 , 0
   // string str = "x^2+3=0"; //1, 0, 3
    string str;
    cin >> str;
    smatch result[3];
    regex pattern1(".*(?=x\\^2)");   
    regex pattern2("[+-]\\d*(?=\\*x)");
    regex pattern3("[+-]\\d*(?=\\=0)");
    string::const_iterator iterStart = str.begin();
    string::const_iterator iterEnd = str.end();

    string tmpA, tmpB, tmpC;
    regex_search(iterStart, iterEnd, result[0], pattern1);
    tmpA = (result[0][0] == "" ? "1" : (string)result[0][0]);
    if(tmpA == "-")
        tmpA += "1";
    
    regex_search(iterStart, iterEnd, result[1], pattern2);
    tmpB = (result[1][0] == "" ? "0" : (string)result[1][0]);
    if(tmpB == "+")
        tmpB = "1";
    if(tmpB == "-")
        tmpB = "-1";

    regex_search(iterStart, iterEnd, result[2], pattern3);
    tmpC = (result[2][0] == "" ? "0" : (string)result[2][0]);
    
    int a, b, c;
    istringstream isA(tmpA);
    isA >> a;
    istringstream isB(tmpB);
    isB >> b;
    istringstream isC(tmpC);
    isC >> c;   
    /*
    cout << tmpA << " " << tmpB << " " << tmpC << endl;
    cout << a << endl << b << endl << c << endl;
    */
    
    int tmp = b*b - 4*a*c;
    if(tmp == 0)
        cout << "x1=x2=" << -b << "/" << 2*a << endl;
    else if(tmp < 0)
        cout << "No" << endl;
    else
    {
        int flag = 0;
        if(sqrt(tmp) == (int)sqrt(tmp))
            flag = 1;
        if(flag)
        {
            int flag1 = 0, flag2 = 0;
            if(-b-sqrt(tmp) < 0)
                flag1 = 1;
            if(-b+sqrt(tmp) < 0)
                flag2 = 1;
            if(flag1 && !flag2)  
                cout << "x1=(" << -b-sqrt(tmp) << ")/" << 2*a 
                    << " " << "x2=" << -b+sqrt(tmp) << "/" << 2*a << endl;
            else  if(!flag1 &&flag2)
                cout << "x1=" << -b-sqrt(tmp) << "/" << 2*a 
                   << " " << "x2=(" << -b+sqrt(tmp) << ")/" << 2*a << endl;
            else if(flag1 && flag2)
                cout << "x1=(" << -b-sqrt(tmp) << ")/" << 2*a 
                    << " " << "x2=(" << -b+sqrt(tmp) << ")/" << 2*a << endl;
            else
                cout << "x1=" << -b-sqrt(tmp) << "/" << 2*a 
                    << " " << "x2=" << -b+sqrt(tmp) << "/" << 2*a << endl;
        }
        else
            cout << "x1=(" << -b << "-sqrt(" << tmp  << "))/" << 2*a 
                << " " << "x2=(" << -b << "+sqrt(" << tmp << "))/" << 2*a << endl;
    }
    return 0;
}