#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    void insertSort(vector<int>& a, int n)
    {
        if (n < 2)
        {
            return;
        }

        for (int j = 1; j < n; j++)
        {
            int key = a[j];
            int i = j - 1;
            while (i >= 0 && a[i] > key)
            {
                a[i + 1] = a[i];
                i--;
            }
            a[i + 1] = key; 
        }
    }
};

int main()
{
    vector<int> arr = {4, 7, 6, 5, 2, 3};
    for (int i = 0; i < 6; i++)
    {
        cout << arr.at(i) << ", ";
    }
    cout << endl;
    Solution solution;
    solution.insertSort(arr, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << arr.at(i) << ", ";
    }
    return 0;
}