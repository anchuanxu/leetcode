#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> res1 = {0};
    cout<<res1[0]<<endl;
    cout<<res1.size()<<endl;

    vector<int> res2 = {0,1};
    for(int i = 0; i < res2.size(); i++)
        cout<<res2[i]<<" ";
    cout<<endl;
    cout<<res2.size()<<endl;

    vector<int> res3;
    res3.push_back(0);
    for(int i = 0; i < res3.size(); i++)
        cout<<res3[i]<<" ";
    cout<<endl;
    cout<<res3.size()<<endl;
    res3.push_back(1);
    for(int i = 0; i < res3.size(); i++)
        cout<<res3[i]<<" ";
    cout<<endl;
    cout<<res3.size()<<endl;

    vector<char> res4;
    res4.push_back('a');
    for(int i = 0; i < res4.size(); i++)
        cout<<res4[i]<<" ";
    cout<<endl;
    cout<<res4.size()<<endl;
    res4.push_back('n');
    for(int i = 0; i < res4.size(); i++)
        cout<<res4[i]<<" ";
    cout<<endl;
    cout<<res4.size()<<endl;

    vector<string> res5;
    res5.push_back("chuan");
    for(int i = 0; i < res5.size(); i++)
        cout<<res5[i]<<" ";
    cout<<endl;
    cout<<res5.size()<<endl;
    res5.push_back("xu");
    for(int i = 0; i < res5.size(); i++)
        cout<<res5[i]<<" ";
    cout<<endl;
    cout<<res5.size()<<endl;

    return 0;
}