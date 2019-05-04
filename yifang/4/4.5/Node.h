

#include "Common.h"



using namespace std;
// 每个数字即为一个Node
class Node
{
public:
    int row;    // 行号，第一行为0
    int col;    // 列好，第一行为1
    int left;   // 左连续极点的列号
    int right;  // 右连续极点的列号码
    int high;   // Node的高度

public:
    Node() : row(-1), col(-1), left(-1), right(-1), high(-1){};
    // Node(int _row, int _col): row(_row), col(_col){};
    Node(int _row, int _col,int _high): row(_row), col(_col),high(_high){};
    // Node(int _row, int _col, int _left, int _right, int _high)
    //     : row(_row), col(_col), left(_left), right(_right), high(_high){};
    void show()
    {
        cout<<" ("<<row<<","<<col<<","<<left<<","<<right<<","<<high<<") ";
    }
};




