/*

微信声音锁8位随机数生成算法

我观察到的规律是:8位数字是从[0,1,2,3,4,5,6,7,8,9]无放回连续随机抽取8次得到的结果.
考虑到微信声音锁需要尽可能测量用户读取数字的声音,以上规律符合这个考虑.

注意需要用-std=c++11.

*/

#include <random>
#include <iostream>
#include <vector>
using namespace std;

vector<int> weixin();             //生成微信格式的8位随机数
int myrandom(int start, int end); //生成指定范围的随机数(均匀分布)

int main()
{
    // 获得微信格式的8位随机数
    vector<int> res = weixin();
    // 输出结果
    for (auto x : res)
    {
        cout << x;
    }
    cout << endl;
}

//生成指定范围的随机数(均匀分布)
int myrandom(int start, int end)
{
    std::random_device rd;  // 将用于为随机数引擎获得种子
    std::mt19937 gen(rd()); // 以播种标准 mersenne_twister_engine
    std::uniform_int_distribution<> dis(start, end);
    return dis(gen);
}

vector<int> weixin()
{
    // 原始10个数字
    vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // 最终结果的8个数字
    vector<int> v2;

    // 算法核心:
    // 1:每次无放回的从v1中随机抽取一个数字,并放到v2中.
    // 2:连续操作8次,那么v2中存放的即为本次生成结果.
    int end = 9;
    for (int end = 9; end > 2; end--) //每轮循环,end减1,当end等于2时,退出循环.
    {
        int local = myrandom(0, end); //利用myrangdom在[0,end]生成int形随机数,即为抽取数字的位置.
        v2.push_back(v1.at(local));   // 从v1中抽取数字并放入v2中.
        v1.erase(v1.begin() + local); // 无放回抽取,所以要从v1中删除已经抽取的数字
    }

    return v2;
}
