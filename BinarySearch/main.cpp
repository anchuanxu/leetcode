#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

template <typename T>
int binarySearch(T arr[],int n,int target){

    int l = 0,r = n-1;//设置边界[l...r] 在这个区间内寻找target
    while(l <= r){
        int mid = l+(r-l)/2; //防止整型溢出
        if(arr[mid] ==  target)
            return mid;
        if(arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;

}

int main() {
    int n,t;
    cin>>n>>t;
    int a[n];
    for(int i = 0;i < n; i++){
        cin>>a[i];
    }
    cout<<"target在数组中的位置是: "<<binarySearch(a,n,t)+1<<endl;
    return 0;
}