#include "common.h"




// 每个数字1，即为一个Node
class Node
{
public:
    int row;   // 行号，第一行为0
    int col;   // 列好，第一行为1
    int left;  // 左连续极点的列号
    int right; // 右连续极点的列号码
    int high;

public:
    Node() : row(0), col(0), left(0), right(0), high(0){};
    // Node(int _row, int _col): row(_row), col(_col){};
    Node(int _row, int _col,int _high): row(_row), col(_col),high(_high){};
    // Node(int _row, int _col, int _left, int _right, int _high)
    //     : row(_row), col(_col), left(_left), right(_right), high(_high){};
};



