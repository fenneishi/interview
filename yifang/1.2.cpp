
# include<iostream>
using namespace std;


const int M=3;
const int MAX_LEVEL=100;
const int MIN_LEVEL=1;
const int BAD_LEVEL=4;
const int HALF_LEVEL=50;
const int HALF_HIGh=190;


int high(int level);
int high1(int level);



int main(int argc, char const *argv[])
{
    for(int i=-5;i<=105;i++)
    {   
        cout<<i<<"-------"<<"high1:"<<high1(i)<<"--------"<<"high3:"<<high(i)<<"--------"<<"high1-high3:"<<high1(i)-high3(i)<<endl;
    }
    return 0;
}


// O(n)
int  high1(int level)
{
    // 剔除错误高度
    if(level>MAX_LEVEL||level<MIN_LEVEL||level%BAD_LEVEL==0)
    {
        // cout<<"bad level:";
        return -1;
    }

    // 计算老王高度
    int high=0;
    for(int i=1;i<=level;i++)
    {
        if(i%BAD_LEVEL==0)
            continue;
        else 
            high+=M;
    }
    return high;
}


// O(1)
int high(int level)
{

    // 剔除错误高度
    if (level > MAX_LEVEL || level < MIN_LEVEL || level % BAD_LEVEL == 0)
    {
        // cout << "bad level:";
        return -1;
    }


    //计算老王高度
    int high;
    //如果最底层编号为1;
    int n = level/BAD_LEVEL;
    int m = level%BAD_LEVEL;
    high= (n*(BAD_LEVEL-1)+m)*M;
    // 如果最低层编号大于1;

    return high;
}