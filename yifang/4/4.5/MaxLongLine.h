
#if !defined(MAXLONGLINE_H_)
#define MAXLONGLINE_H_

#include "Common.h"

class MaxLongLine
{
public:
    Node start;
    Node end;
    int length()
    {
        return end.col-start.col+1;
    }

};

#endif // MAXLONGLINE_H_

















