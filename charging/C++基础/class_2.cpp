#include <iostream>

using namespace std;

class Vector
{
    public:

    Vector(int _size, int* _p) : _size(_size), _p(nullptr)
    {
        cout << "构造函数" << endl;
    }

    Vector(Vector& v) : _size(v._size), _p(nullptr)
    {
        cout << "拷贝构造函数" << endl;
    }

    Vector(Vector&& v) : _size(v._size), _p(nullptr)
    {
        cout << "移动构造函数" << endl;
    }

    private:
        int _size;
        int* _p;
};