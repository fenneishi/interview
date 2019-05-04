
#if !defined(RANDOMMATRIX01_H_)
#define RANDOMMATRIX01_H_

#include "Common.h"

// 随机01矩阵生成器
class RandomMatrix01
{
  public:
    vector<vector<int> > martrix;
    int rows;
    int cols;

  public:
    int random(int start, int end)
    {
        std::random_device rd;  // 将用于为随机数引擎获得种子
        std::mt19937 gen(rd()); // 以播种标准 mersenne_twister_engine
        std::uniform_int_distribution<> dis(start, end);
        return dis(gen);
    }

    void buildRandomMatrix01()
    {
        for (size_t row = 0; row < rows; row++)
        {
            vector<int> temp;
            for (size_t col = 0; col < cols; col++)
            {
                temp.push_back(random(0, 1));
            }
            martrix.push_back(temp);
        }
    }

    RandomMatrix01(int _rows, int _cols) : rows(_rows), cols(_cols)
    {
        buildRandomMatrix01();
    };

    void show()
    {
        for (size_t row = 0; row < rows; row++)
        {
            for (size_t col = 0; col < cols; col++)
            {
                cout<<martrix[row][col]<<" ";
            }
            cout<<endl;
        }
    }
};

#endif // RANDOMMATRIX01_H_
