
#if !defined(RECTANGLE_h_)
#define RECTANGLE_h_


# include"Common.h"

class rectangle
{
  public:
    Node start; // 矩形起始点(最左，最上)
    Node end;   // 矩形终止点(最下，最右)
    int _area;
  public:
    rectangle() : start(), end()
    {
      area();
    };
    rectangle(Node const &Start, Node const &End) : start(Start), end(End)
    {
      area();
    };
    int area()// 计算矩形面积
    {
        if(start.row==-1||start.col==-1||end.row==-1||end.col==-1)
          _area=0;
        else
          _area=abs( (end.row - start.row+1) * (end.col - start.col+1) );
        return _area;
    }
    void show() const
    {
      cout << "(" << start.row << start.col << ")"
           << "-"
           << "(" << start.row << end.col << ")"
           << "(" << end.row << start.col << ")"
           << "-"
           << "(" << end.row << end.col << ")"
           << _area;
    }
};



#endif // RECTANGLE_h_
