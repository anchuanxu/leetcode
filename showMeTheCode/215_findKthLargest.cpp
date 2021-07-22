#include <iostream>
#include <vector>

using namespace std;
//利用快速排序思想

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k > nums.size())
            return 0;
        k = nums.size() - k;

        quicksort(nums,0,nums.size()-1);
        return nums[k];

    }

public:
    void quicksort(vector<int>& arr,int l, int r){
        if(l >= r)
            return ;
        int mid;
        mid = partition(arr ,l ,r);
        quicksort(arr,l,mid-1);
        quicksort(arr,mid+1,r);
    }

public:
    //关键的划分函数，保证左边都比key小，右边都比key大
    int partition(vector<int>& arr, int l ,int r){
        int  v = arr[l];//基准设为第一个元素

        //arr[l+1...j] < v arr[j+1 ... r] > v
        int j = l;
        for(int i = l + 1; i <= r; i++){ //此处一定要理解，为什么是从l + 1开始，因为我们要要维护arr[l+1...j] < v这个循环不变量。
            if(arr[i] < v){
                swap(arr[++j],arr[i]);
            }
        }
        swap(arr[l],arr[j]);
        return  j;
    }

};

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    vector<int> vec(arr,arr+ sizeof(arr)/ sizeof(int));
    cout<<Solution().findKthLargest(vec,n-1)<<endl;
    return 0;
}