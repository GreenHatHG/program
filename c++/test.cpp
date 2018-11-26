参考：
[http://www.cnblogs.com/wuqianling/p/5387099.html](http://www.cnblogs.com/wuqianling/p/5387099.html)
```c++
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 1e2;

/*
函数SubStract功能： 
用长度为len1的大整数num1减去长度为len2的大整数num2 
结果存在num1中，返回值代表结果的长度 
不够减：返回-1 ， 正好够：返回0
*/    
int sub(int *num1, int len1, int *num2, int len2)
{
    if(len1 < len2)
        return -1;

    if(len1 == len2) //两数字位数相同时，对比哪个数大
    {
        for(int i = len1 - 1; i >= 0; i--)
        {
            if(num1[i] > num2[i]) //num1大，满足条件
                break;
            else if(num1[i] < num2[i]) //当n2大于n1时，此时不够减，返回－1
                return -1;
        }
    }

    for(int i = 0; i <= len1 - 1; i++) //减法操作
    {
        num1[i] -= num2[i];
        if(num1[i] < 0) //需要借位
        {
            num1[i] += 10;
            num1[i + 1]--;
        }
    }

    for(int i = len1 - 1;i >= 0; i--) //去除前导0，查找结果最高位。
    {
        if(num1[i])
            return i + 1;
    }
    return 0; //两数相等时返回0
}

/* 大数除法---结果不包括小数点 
num1 / num2  
ans:结果数组,商，存放计算的结果，
即：num1/num2=ans
返回数组ans的有效长度，即商的位数 
*/ 
int division(char* num1, char* num2, char* ans)
{
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int num_a[MAXN] = {0};
    int num_b[MAXN] = {0};
    int num_c[MAXN] = {0};

    for(int i = 0; i < len1; i++) //将字符数字每个数字处理为int，然后倒序存在另外一个数组
        num_a[i] = num1[len1 - i - 1];
    for(int i = 0; i < len2; i++)
        num_b[i] = num2[len2 - i - 1];

    if(len1 < len2) //如果被除数小于除数，直接返回-1，表示结果为0
        return -1;
    
    int dvalue = len1 - len2; //两大数相差位数
    
    //进行扩展，不是一个个减，而是以其10的倍数减，刚开始扩展到与被除数相等的位数，即相当于乘以10的x次方
    for(int i = len1 - 1; i >= 0; i--) 
    {
        if(i >= dvalue)
            num_b[i] = num_b[i - dvalue];
        else
            num_b[i] = 0;
    }
    
    len2 = len1;
    int n;
    //进行减法
    for(int i = 0; i <= dvalue; i++)
    {
    	//num_b + i代表不断尝试10的x次方,因为其后面为0,故相当于乘以10的x次方
        while((n = sub(num_a, len1, num_b + i, len2 - i)) >= 0) //不断尝试将除数扩大来减
        {
            len1 = n;
            num_c[dvalue - i]++; 
            //对应的结果位数++，刚开始加的位数很大，比如百位，然后除数逐渐减少，对应的就会加在十位个位
        }
    }
    
    int j;
	//跳过高位0，获取商的位数
    for(j = MAXN - 1; j >= 0; j--)
    {
        if(num_c[j] != 0)
            break;
    }
    int len = -1; //商的位数
    if(j >= 0)
        len = j + 1;
    //因为得到的结果是倒序的，故倒序将结果复制到ans数组
    for(int i = 0; j >= 0; i++, j--)
        ans[i] = num_c[j];
    ans[j] = '\0';
    return len;
}

int main()
{
    char num1[MAXN] = "1234567899876543210";
    char num2[MAXN] = "20160415123025";
    char ans[MAXN];

    int len = division(num1, num2, ans);
    if(len >= 0)
    {
        for(int i = 0; i < len; i++)
            cout << ans[i];
    }
    else
        cout << "0";
    return 0;
}
```








