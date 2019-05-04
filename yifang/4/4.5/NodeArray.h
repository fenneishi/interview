


#if !defined(NODEARRAR_h_)
#define NODEARRAR_h_

#include "Common.h"
using namespace std;

class NodeArray;
class RowSet
{
public:
    const NodeArray &array;
    int row;
    int left;
    int right;
    int maxHigh;
public:
    void computeMaxHigh();
    RowSet(const NodeArray &_array,int _row,int _left,int _right);
    void show() const
    {
        cout<<" ["<<row<<","<<left<<","<<right<<","<<maxHigh<<","<<"] ";
    }
};

class NodeArray
{
public:
    vector< vector<int> > source;
    vector< vector<Node> > nodeArray;
    vector< vector<RowSet> > rowInfs;
    int rows;
    int cols;
public:
    void creatNodeArray()
    {
        // 生成NodeArray(同时计算每个节点的高度)
        for(int row=0;row<rows;row++)
        {
            vector<Node> temp;
            for(int col=0;col<cols;col++)
            {
                int high=0;
                for(int h=row;h<rows;h++)
                {
                    if(source[h][col]==1)
                        high++;
                    else 
                    break;
                }
                temp.push_back(Node(row,col,high));
            }
            nodeArray.push_back(temp);
        }

        // 计算每个点的左右极限
        for(int row=0;row<rows;row++)
        {
            bool currNodeBool;
            bool lastNodeBool;

            // 从左向右确定各个node的left
            currNodeBool=false;
            lastNodeBool=false;
            int set_left=-1;
            for(int col=0;col<cols;col++)
            {
                // 更新当前节点01值。
                currNodeBool=(bool)(nodeArray[row][col].high);

                // 先检测一遍集合的起始和终止要不要修改，要修改就及时修改，后面要用到。
                // 出现01更新当前集合的left。
                if(lastNodeBool==false&&currNodeBool==true)
                    set_left=col;


                // 设置当前节点集合归属的left
                nodeArray[row][col].left=set_left;
                lastNodeBool=currNodeBool;
            }

            // 从右向左确定各个node的right
            currNodeBool=false;
            lastNodeBool=false;
            int set_right=-1;
            for(int col=(cols-1);col>=0;col--)
            {
                // 更新当前节点01值。
                currNodeBool=(bool)(nodeArray[row][col].high);

                // 先检测一遍集合的起始和终止要不要修改，要修改就及时修改，后面要用到。
                // 出现01更新当前集合的left。
                if(lastNodeBool==false&&currNodeBool==true)
                    set_left=col;


                nodeArray[row][col].right=set_left;
                lastNodeBool=currNodeBool;
            }

            // 所有0节点的left=right=-1
            for(int col=0;col<cols;col++)
            {
                if((bool)(nodeArray[row][col].high)==false)
                    nodeArray[row][col].left=nodeArray[row][col].right=-1;
            }
        }

    }

    void creatRowInfs()
    {
        for(int row=0;row<rows;row++)
        {
            int set_left=-1;
            int set_right=-1;
            vector<RowSet> temp;
            for(int col=0;col<cols;col++)
            {
                if((bool)nodeArray[row][col].high==true)
                {
                    if(set_left<nodeArray[row][col].left)
                    {
                        set_left=nodeArray[row][col].left;
                        set_right=nodeArray[row][col].right;
                        temp.push_back( RowSet(*this,row,set_left,set_right) );
                    }
                        
                }
            }
            rowInfs.push_back(temp);
        }

        

    }
    NodeArray(const vector<vector<int> > &_src,int _rows,int _cols):source(_src),rows(_rows),cols(_cols)
    {
       creatNodeArray();
       creatRowInfs();
    }

    void showNodeArray()
    {
        cout<<"nodeArray:"<<endl;
        for(int row=0;row<rows;row++)
        {
            for(int col=0;col<cols;col++)
            {
                nodeArray[row][col].show();
            }
            cout<<endl;
        }
    }
    void showRowInfs()
    {
        cout<<"Infs:"<<endl;
        for(int row=0;row<rows;row++)
        {
            for(auto x:rowInfs[row])
            {
                x.show();
            }
            cout<<endl;
        }
    }

};



void RowSet::computeMaxHigh()
{
    maxHigh=0;
    for(int col=left;col<=right;col++)
    {
        if(maxHigh< (array.nodeArray[row][col].high) )
            maxHigh=array.nodeArray[row][col].high;
    }
}
RowSet::RowSet(const NodeArray &_array,int _row,int _left,int _right):array(_array),row(_row),left(_left),right(_right)
{
    computeMaxHigh();
}






#endif // NODEARRAR_h_













