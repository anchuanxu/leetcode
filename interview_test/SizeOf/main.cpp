#include <iostream>
using namespace std;


int main() {

    cout<< sizeof(int)<<endl;
    cout<< sizeof(char)<<endl;
    cout<< sizeof(short)<<endl;
    cout<< sizeof(long)<<endl;
    cout<< sizeof(long long)<<endl;
    cout<< sizeof(double)<<endl;

    int a = 10;
    int b = 20;
    double z = 1.1;
    double  w = 2.2;

    cout<<(a > b ? a : b)<<endl;

    cout<<((z > w ? z : w))<<endl;
    return 0;
}