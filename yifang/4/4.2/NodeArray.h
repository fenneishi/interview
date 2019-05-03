


#if !defined(NODEARRAR_h_)
#define NODEARRAR_h_

#include "common.h"

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
                        temp.push_back( rowSet(*this,row,set_left,set_right) );
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






#endif // NODEARRAR_h_













