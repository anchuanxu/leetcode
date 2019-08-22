#include <iostream>
#include <map>
#include <vector>
using namespace std;

//map是有默认值的，而且执行find操作之后会自动加入该元素；

int main() {
    map<int,int> myMap;

    if(myMap.find(42) == myMap.end())
        cout<<"can not find element 42"<<endl;
    else
        cout<<"Element 42 is in the map"<<endl;

    cout<<myMap[42]<<endl;
    if(myMap.find(42) == myMap.end())
        cout<<"can not find element 42"<<endl;
    else
        cout<<"Element 42 is in the map"<<endl;

    myMap[42] ++;
    cout<<myMap[42]<<endl;

    myMap[42] --;
    cout<<myMap[42]<<endl;

    myMap.erase(42);
    if(myMap.find(42) == myMap.end())
        cout<<"can not find element 42"<<endl;
    else
        cout<<"Element 42 is in the map"<<endl;
    return 0;
}