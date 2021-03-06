#include "Common.h"

void maxRec_Global(const vector<vector<int> > &sourceArray, int rows, int cols);
rectangle maxRec_Row(const NodeArray &nodeArray, int firstRow);
rectangle maxRec_RowSet(const NodeArray &nodeArray, int firstRow, const RowSet &rowSet);
rectangle maxRec_RowSetHigh(const NodeArray &nodeArray, int firstRow, const RowSet &rowSet, int high);
MaxLongLine findMaxLongLine(const NodeArray &nodeArray, int row, vector<int> cols);


int main(int argc, char const *argv[])
{
    cout << "请输入01矩阵的行数:";
    int rows;
    cin >> rows;

    cout << "请输入01矩阵的列数:";
    int cols;
    cin >> cols;

    cout<<"------------------------------------------------------"<<endl;
    cout << "sourceArray:" << endl;
    RandomMatrix01 sourceMatrix(rows, cols);
    sourceMatrix.show();

    maxRec_Global(sourceMatrix.martrix,rows,cols);

    return 0;
}





void maxRec_Global(const vector<vector<int> > &sourceArray, int rows, int cols)
{

    // cout<<"maxRec_Global_start-------------------"<<endl;
    // 构造出Node型矩阵
    NodeArray nodeArray(sourceArray, rows, cols);
    nodeArray.showNodeArray();
    nodeArray.showRowInfs();
    //定义最大矩阵
    rectangle max;

    // 按照矩阵的首行位置进行分类，先求出各分类中的最大矩形，再求出整体最大值
    rectangle temp;
    for (int firstRow = 0; firstRow < nodeArray.rows; firstRow++)
    {
        temp = maxRec_Row(nodeArray, firstRow);
        cout<<"第"<<firstRow<<"行最大面积为"<<temp.area()<<endl;
        if (temp.area() > max.area())
        {
            max = temp;
        }
    }

    // 输出结算结果
    cout<<"------------------------------------------------------"<<endl;    
    cout<<"最大面积为: "<<max._area<<endl;
    cout<<"第一个取最大面积的矩形为: "<<endl;
    max.show();
    cout<<endl;
}








rectangle maxRec_Row(const NodeArray &nodeArray, int firstRow)
{
    // 将矩阵首行按照“连续1集合进行分类”，先求出每个分类的最大值，再求出整体最大值，
    rectangle max;
    rectangle temp;

    if (nodeArray.rowInfs[firstRow].size() > 0)
    {
        int i = 1;
        for (auto _rowSet : nodeArray.rowInfs[firstRow])
        {
            // 求各分类最大矩阵
            temp = maxRec_RowSet(nodeArray, firstRow, _rowSet);

            // 更新max
            if (temp.area() > max.area())
            {
                max = temp;
            }
            i++;
        };
    }

    return max;
}




rectangle maxRec_RowSet(const NodeArray &array, int firstRow, const RowSet &rowSet)
{

    rectangle max;
    rectangle temp;
    
    for (int high = rowSet.maxHigh; high >= 1; high--)// 因为有可能有多行同时达到最大高度，所以起始高度不能为“(rowSet.maxHigh - 1)”;
    {  
        temp=maxRec_RowSetHigh(array, firstRow, rowSet, high);
        if(temp.area()>max.area())
            max=temp;
    };

    return max;
}







rectangle maxRec_RowSetHigh(const NodeArray &array, int firstRow, const RowSet &rowSet, int high)
{
    // 在rowSet从左向右依次筛选，找出高度值达到要求高度的点,并将这些点的列序号保存到cols中。
    vector<int> cols;
    for (int col = rowSet.left; col <= rowSet.right; col++)
    {
        if (array.nodeArray[firstRow][col].high >= high)
        {
            cols.push_back(col);
        }
    }
    
    // 找出同一行(行号为“firstRow+(high-1)”)多个节点(列号存放在cols中)最长连续1集合。
    MaxLongLine maxlongline = findMaxLongLine(array, firstRow+(high-1), cols);
    

    // 根据这个集合的起点和终点便可以知道所求最大矩形
    // 最大矩形start点:行号=firstRow，列号=集合起点的列号
    // 最大矩形end点=集合end点
    return rectangle(array.nodeArray[firstRow][maxlongline.start.col], maxlongline.end);
}







MaxLongLine findMaxLongLine(const NodeArray &array, int row, vector<int> cols)
{


    MaxLongLine max;
    max.start = max.end = array.nodeArray[row][cols[0]];
    MaxLongLine temp;
    temp.start = temp.end = array.nodeArray[row][cols[0]];
    for (auto col:cols)
    {
        // 更新temp
        if (temp.start.left == array.nodeArray[row][col].left)
            temp.end = array.nodeArray[row][col];
        else
            temp.start = temp.end = array.nodeArray[row][col];

        // 更新max
        if (temp.length() > max.length())
            max = temp;
    }
    
return max;
}