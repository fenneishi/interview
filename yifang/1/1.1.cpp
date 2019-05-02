/*

楼层高度计算公式:high= (n*(BAD_LEVEL-1)+m)*M; 
其中:
n:输入层号除以4的商
m:输入层号除以4个余数

所以本算法可以在O(1)时间复杂度内完成.

*/

#include <iostream>
using namespace std;

const int M = 3;           //楼层高度
const int MAX_LEVEL = 100; // 最高层号
const int MIN_LEVEL = 1;   // 最低层号
const int BAD_LEVEL = 4;   // 不吉利数字

int high(int level);

int main(int argc, char const *argv[])
{
    cout << "请输入老王的楼层号:";
    int level;
    cin >> level;
    cout << "老王目前的高度为:" << high(level);
    return 0;
}

// 算法复杂度:O(1)
int high(int level)
{

    // 剔除错误高度(输入层号过高,过小,或者是不吉利数字)
    if (level > MAX_LEVEL || level < MIN_LEVEL || level % BAD_LEVEL == 0)
    {
        return -1;
    }

    //计算楼层高度
    int high;
    int n = level / BAD_LEVEL;            // 输入层号除以4的商
    int m = level % BAD_LEVEL;            // 输入层号除以4个余数
    high = (n * (BAD_LEVEL - 1) + m) * M; // 楼层高度计算公式

    return high;
}