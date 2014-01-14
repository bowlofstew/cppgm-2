
#include <iostream>
#include <string>
#include <limits>
#include <list>
#include <typeinfo>

using namespace std;

template<typename T>
class MyAllocator {
  public : 
    typedef T value_type;
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

  public : 
    template<typename U>
    struct rebind {
        typedef MyAllocator<U> other;
    };

  public : 
    explicit MyAllocator() { cout << "allocator constructor" << endl; }
    ~MyAllocator() { cout << "allocator destructor" << endl; }
    explicit MyAllocator(MyAllocator const&) {}
    template<typename U>
    explicit MyAllocator(MyAllocator<U> const&) {}

    //    address
    pointer address(reference r) { 
        cout << "get address of " << (void*)&r << endl;
        return &r; 
    }

    const_pointer address(const_reference r) { 
        cout << "get address of " << (void*)&r << endl;
        return &r; 
    }

    //    memory allocation
    pointer allocate(size_type cnt, typename std::allocator<void>::const_pointer = 0) 
    { 
        pointer p = reinterpret_cast<pointer>(::operator new(cnt * sizeof (T))); 
        cout << "allocate : " << typeid(T).name() << " " << cnt * sizeof(T) << " at " << (void*) p << endl; 
        return p; 
    }

    void deallocate(pointer p, size_type) 
    {
        cout << "deallocate " << (void*) p << endl; 
        ::operator delete(p); 
    }

    //    size
    size_type max_size() const { 
        return std::numeric_limits<size_type>::max() / sizeof(T);
    }

    //    construction/destruction
    void construct(pointer p, const T& t) { 
        cout << "construct " << typeid(T).name() << " at " <<  p << endl;
        new(p) T(t); 
    }

    void destroy(pointer p) { 
        cout << "destroy " << typeid(T).name() << " at " <<  p << endl;
        p->~T(); 
    }

    bool operator==(MyAllocator const&) { return true; }
    bool operator!=(MyAllocator const& a) { return !operator==(a); }
};    


class MyObject {
  public:
    MyObject() : value(0)
    {
        cout << "MyObject default constructor, value "<< value << " at " << (void*) this << endl;
    }

    MyObject(int x) : value(x)
    {
        cout << "MyObject value constructor, value "<< value << " at " << (void*) this << endl;
    }

    MyObject( const MyObject& a)
    {
        this->value = a.value;
        cout << "MyObject copy constructor, value "<< value << " at " << (void*) this << endl;
    }

    ~MyObject() {
        cout << "MyObject destructor, value "<< value << " at " << (void*) this << endl;
    }

    int value;
};


int main(void) 
{
    cout << "1" << endl;
    list<MyObject, MyAllocator<MyObject> > mylist;
    cout << "2" << endl;

    MyObject obj(2);
    cout << "3" << endl;
    mylist.push_back( obj );
    cout << "4" << endl;


    return 0;
}
