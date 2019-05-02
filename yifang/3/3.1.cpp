
#include <iostream>
using namespace std;

bool check(int num);

int main(int argc, char const *argv[])
{
    cout << "please input num:";
    int num;
    cin >> num;
    bool result = check(num);
    cout << "result is:" << result << endl;
    return 0;
}

bool check(int num)
{
    int n = -1; //商
    int m = -1; // 余数
    bool _10 = false;
    bool result = true;

    int last_m = -1;
    while (n != 0)
    {
        n = num / 2;
        m = num % 2;
        num = n;

        cout << "m:" << m << ",";
        cout << "last_m:" << last_m << endl;

        if (last_m == 1 && m == 0)
            _10 = true;            //出现10组合;
        if (_10 == true && m == 1) // 出现10组合后又出现1
        {
            result = false;
        }
        last_m = m;
    };
    return result;
}
