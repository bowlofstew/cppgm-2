
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;


class Point {
  public:
    Point(int px, int py) : x(px), y(py) {} 
    Point() : x(0), y(0) {}

    operator string() {
        stringstream ss;
        ss << "(" << x << "," << y << ")";
        return ss.str();
    }

    friend ostream& operator<<( ostream& os, const Point& p)
    {
        os << "(" << p.x << "," << p.y << ")"; 
        return os;
    }
     
  public:
    int x;
    int y;
};



class PointPool {
  public:
    static const int POOLSIZE = 200;

    struct PointItem {
        union {
            Point val;
            PointItem* next;
        };
    };

    PointPool()
    {
        _list = (PointItem*) ::operator new (sizeof(PointItem) * POOLSIZE);
        _freeLst = _list;

        for (int i=0; i<POOLSIZE-1; i++) 
        {
            _list[i].next = &_list[i+1];
        }
        _list[POOLSIZE-1].next = NULL;

    } 

    ~PointPool() 
    {
        delete _list;
    }

    Point* allocate() 
    {
        if (_freeLst == 0) {
            throw string("PointPool is full!");
        }

        Point* p = (Point*)_freeLst;  
        _freeLst = _freeLst->next;
        p->x = 0;
        p->y = 0;
        return p;
    }

    void deallocate(Point* p) 
    {
        PointItem* item = (PointItem*) p;
        item->next = _freeLst;
        _freeLst = item;
    }

  private:
    PointItem* _list;
    PointItem* _freeLst;
};


void test_allocate() 
{
    PointPool pool;
    Point* p = pool.allocate();
    assert( string("(0,0)") == string(*p) );
}

void test_allocate_bound() 
{
    PointPool pool;
    int i = 0;
    string m;

    try 
    {
        for (i=0; i<1000; i++) 
        {
            pool.allocate();
        }
    } 
    catch(string& msg) 
    {
        m = msg;
    }
    assert( m == "PointPool is full!");
    assert( i == 200);
}

void test_deallocate() 
{
    PointPool pool;
    Point* p = pool.allocate();
    pool.deallocate( p );
    Point* q = pool.allocate();
    assert( p == q);
}


int main(void) 
{
    test_allocate();
    test_deallocate();
    test_allocate_bound();

    return 0;
}



