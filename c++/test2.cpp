#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    char arr[10];
    arr[0] = '1';
    while(cin.getline(arr + 1, sizeof(arr)))
    {
        cout << arr << endl;
    }
    return 0;
}
