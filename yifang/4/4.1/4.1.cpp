#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Node;
class NodeArray;
class rowSet;
class maxLongLine;
class rectangle



maxLongLine findMaxLongLine(const NodeArray &array,int row,vector<int> cols);
rectangle maxRectangle(const vector<vector<int> > &sourceArray,int rows,int cols);
rectangle maxRec_Row(const NodeArray &array,int firstRow);
rectangle maxRec_RowSet(const NodeArray &array,int firstRow,const rowSet &rowset);
rectangle maxRec_RowSetHigh(const NodeArray &array,int firstRow,const rowSet &rowset,int high);


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
    // Node() : row(0), col(0), left(0), right(0), high(0){};
    // Node(int _row, int _col): row(_row), col(_col){};
    Node(int _row, int _col,int _high): row(_row), col(_col),high(_high){};
    // Node(int _row, int _col, int _left, int _right, int _high)
    //     : row(_row), col(_col), left(_left), right(_right), high(_high){};
};





class rowSet
{
public:
    const NodeArray &array;
    int row;
    int left;
    int right;
    int maxHigh;
public:
    void computeMaxHigh()
    {
        int max=0;
        for(int col=left;col<=right;col++)
        {
            if(max < (array.nodeArray[row][col].high) )
                max=array.nodeArray[row][col].high;
        }
    };
    rowSet(const NodeArray &_array,int _row,int _left,int _right):array(_array),row(_row),left(_left),right(_right)
    {
        computeMaxHigh();
    };
};


class NodeArray
{
public:
    vector<vector<int> > source;
    vector<vector<Node> > nodeArray;
    vector<vector<rowSet> > rowInfs;
    int rows;
    int cols;
public:
    void creatNodeArray()
    {
        // 生成NodeArray(同时计算每个节点的高度)
        for(int row=0;row<rows;row++)
        {
            vector<Node> temp;
            for(int col=0;col<cols;cols++)
            {
                int high=0;
                for(int h=row;h<row;h++)
                {
                    if(source[h][col]==1)high++;
                    else break;
                }
                temp.push_back(Node(row,col,high));
            }
            nodeArray.push_back(temp);
        }


        // 计算每个点的左右极限
        for(int row=0;row<rows;row++)
        {
            bool currNodeBool=false;
            bool lastNodeBool=false;
            int set_left=-1;
            int set_right=-1;
            for(int col=0;col<cols;cols++)
            {
                // 确定当前节点的0，1值
                currNodeBool=(bool)nodeArray[row][col].high;

                // 先检测一遍集合的起始和终止要不要修改，要修改就及时修改，后面要用到。
                // 设置集合的起点(出现01)
                if(lastNodeBool==false&&currNodeBool==true)
                    set_left=col;
                // 设置某个集合的终点(出现10，或者一直是1走到头了)
                if(lastNodeBool==true&&currNodeBool==false )
                    set_right=col-1;
                else if(lastNodeBool==true&&currNodeBool==true&&col==(cols-1) )
                    set_right=lastNodeBool;


                nodeArray[row][col].left=set_left;
                nodeArray[row][col].right=set_right;
                lastNodeBool=currNodeBool;
            }
        }

    }
    void creatRowInfs()
    {
        for(int row=0;row<rows;row++)
        {
            int set_left=-1;
            int set_right=-1;
            vector<rowSet> temp;
            for(int col=0;col<cols;cols++)
            {
                if((bool)nodeArray[row][col].high==true)
                {
                    if(set_left<nodeArray[row][col].left)
                        set_left=nodeArray[row][col].left;
                        set_right=nodeArray[row][col].right;
                        temp.push_back(rowSet(row,set_left,set_right));
                }
            }
        }
    }



    NodeArray(const vector<vector<int> > &_src,int _rows,int _cols):source(_src),rows(_rows),cols(_cols)
    {
       creatNodeArray();
       creatRowInfs();
    }

};

class maxLongLine
{
public:
    Node start;
    Node end;
};

// 矩形
class rectangle
{
  public:
    Node start; // 矩形起始点(最左，最上)
    Node end;   // 矩形终止点(最下，最右)
    int _area;
  public:
    rectangle() : start(), end(){};
    rectangle(Node const &Start, Node const &End) : start(Start), end(End){};
    int area() // 计算矩形面积
    {
        return _area=abs((start.row - end.row) * (start.col - end.col));
    }
};












int main(int argc, char const *argv[])
{

    return 0;
}

rectangle maxRectangle(const vector<vector<int> > &sourceArray,int rows,int cols)
{
    
    NodeArray array(sourceArray,rows,cols);
    rectangle max;
    for (int i = 0; i < array.rows; i++)
    {
        rectangle temp;
        temp=maxRec_Row(array,i);
        if(temp.area()>max.area())
        {
            max=temp;
        }
    }

    return max;
}

rectangle maxRec_Row(const NodeArray &array,int firstRow)
{
    rectangle max;
    for(auto x:array.rowInfs[firstRow])
    {
        rectangle temp;
        temp=maxRec_RowSet(array,firstRow,x);
        if(temp.area()>max.area())
        {
            max=temp;
        }
    }

    return max;
}


rectangle maxRec_RowSet(const NodeArray &array,int firstRow,const rowSet &rowset)
{
    rectangle max;
    for(int h=(rowset.maxHigh-1);h>=1;h--)
    {
        maxRec_RowSetHigh(array,firstRow,rowset,h);
    }
}

rectangle maxRec_RowSetHigh(const NodeArray &array,int firstRow,const rowSet &rowset,int high)
{   
    vector<int> cols;
    for(int col=rowset.start;col<=rowset.end;col++)
    {
        if(array.nodeArray[firstRow][col].high>=high)
        {
            cols.push_back(col);
        }
    }

    maxLongLine mll=findMaxLongLine(array,firstRow-high,cols);

    return rectangle(array.nodeArray[firstRow][mll.start.col],mll.end);

}


maxLongLine findMaxLongLine(const NodeArray &array,int row,vector<int> cols)
{

}