
#if !defined(MAXLONGLINE_H_)
#define MAXLONGLINE_H_

#include "common.h"

class maxLongLine
{
public:
    Node start;
    Node end;
    int length()
    {
        return end.col-start.col;
    }

};

#endif // MAXLONGLINE_H_

















