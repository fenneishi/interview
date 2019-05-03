
#if !defined(RECTANGLE_h_)
#define RECTANGLE_h_


# include"common.h"

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



#endif // RECTANGLE_h_
