// # include"common.h"




// void maxRectangle(const vector<vector<int> > &sourceArray,int rows,int cols);
// rectangle maxRec_Row(const NodeArray &array,int firstRow);
// rectangle maxRec_RowSet(const NodeArray &array,int firstRow,const rowSet &rowset);
// rectangle maxRec_RowSetHigh(const NodeArray &array,int firstRow,const rowSet &rowset,int high);
// maxLongLine findMaxLongLine(const NodeArray &array,int row,vector<int> cols);



# include"randomMatrix01.h"

int main(int argc, char const *argv[])
{
    cout<<"请输入01矩阵的行数:";
    int rows;
    cin>>rows;

    cout<<"请输入01矩阵的列数:";
    int cols;
    cin>>cols;

    cout<<"随机生成的01矩阵为:";

    randomMatrix01 sourceMatrix(rows,cols);
    sourceMatrix.show();


    return 0;
}

// void maxRectangle(const vector<vector<int> > &sourceArray,int rows,int cols)
// {
//     // 构造出Node型矩阵
//     NodeArray array(sourceArray,rows,cols);
//     // 最大矩阵
//     rectangle max;

//     // 按照矩阵的首行位置进行分类，先求出各分类中的最大矩形，再求出整体最大值
//     rectangle temp;
//     for (int i = 0; i < array.rows; i++)
//     {
//         temp=maxRec_Row(array,i);
//         if(temp.area()>max.area())
//         {
//             max=temp;
//         }
//     }

//     // 输出结算结果
//     cout<<"the max rectangle is:"
//         <<"("<<max.start.row<<max.start.col<<")"<<"-----------" <<"("<<max.start.row<<max.end.col<<")"
//         <<"("<<max.end.row<<max.start.col<<")"<<"-----------" <<"("<<max.end.row<<max.end.col<<")"
//         <<endl;
//     cout<<"the max area is :"<<max.area()<<endl;

    
// }

// rectangle maxRec_Row(const NodeArray &array,int firstRow)
// {
//     rectangle max;
//     for(auto x:array.rowInfs[firstRow])
//     {
//         rectangle temp;
//         temp=maxRec_RowSet(array,firstRow,x);
//         if(temp.area()>max.area())
//         {
//             max=temp;
//         }
//     }

//     return max;
// }


// rectangle maxRec_RowSet(const NodeArray &array,int firstRow,const rowSet &rowset)
// {
//     rectangle max;
//     for(int h=(rowset.maxHigh-1);h>=1;h--)
//     {
//         maxRec_RowSetHigh(array,firstRow,rowset,h);
//     }
// }

// rectangle maxRec_RowSetHigh(const NodeArray &array,int firstRow,const rowSet &rowset,int high)
// {   
//     vector<int> cols;
//     for(int col=rowset.left;col<=rowset.right;col++)
//     {
//         if(array.nodeArray[firstRow][col].high>=high)
//         {
//             cols.push_back(col);
//         }
//     }

//     maxLongLine mll=findMaxLongLine(array,firstRow-high,cols);

//     return rectangle(array.nodeArray[firstRow][mll.start.col],mll.end);

// }


// maxLongLine findMaxLongLine(const NodeArray &array,int row,vector<int> cols)
// {
//     maxLongLine max;
//     max.start=max.end=array.nodeArray[row][cols[0]];
//     maxLongLine temp;
//     temp.start=temp.end=array.nodeArray[row][cols[0]];
//     for(int col=cols[0];col<cols[cols.size()];col++)
//     {
//         // 更新temp
//         if(temp.start.left==array.nodeArray[row][col].left) 
//             temp.end=array.nodeArray[row][col];
//         else
//             temp.start=temp.end=array.nodeArray[row][col];
        
//         // 更新max
//         if(temp.length()>max.length())
//             max=temp;
//     }
// }