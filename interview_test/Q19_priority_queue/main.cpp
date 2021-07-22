#include <iostream>
#include <queue>
#include <ctime>
#include <vector>

using namespace std;


int main() {

    srand(time(NULL)); //随机种子
    //优先队列默认情况下，是最大堆

    priority_queue<int> pq;
    for(int i = 0; i < 10; i++){
        int num = rand()%100; //从0-99取一个随机数
        pq.push(num);
        cout<<"insert "<<num<< " in priotity queue. "<<endl;
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    cout<<endl<<endl;

    //实现最小堆
    priority_queue<int,vector<int>,greater<int>> pq2;
    for(int i = 0; i < 10; i++){
        int num = rand()%100; //从0-99取一个随机数
        pq2.push(num);
        cout<<"insert "<<num<< " in priotity queue. "<<endl;
    }
    while(!pq2.empty()){
        cout<<pq2.top()<<" ";
        pq2.pop();
    }

    cout<<endl<<endl;


    return 0;
}