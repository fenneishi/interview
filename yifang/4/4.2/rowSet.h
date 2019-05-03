
#if !defined(ROWSET_H_)
#define ROWSET_H_

#include "common.h"

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



#endif // ROWSET_H_





