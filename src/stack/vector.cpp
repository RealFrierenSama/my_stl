#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void output1(vector<int>&vec)
{
    int n = vec.size();
    for(int i = 0;i < n;i++)
    {
        cout << vec[i] << " " ;
    }
    cout << endl;
}
void output2(vector<int>& vec)
{
    for(auto &i: vec)
    {
        cout << i << " ";//取到第一个就换行
    }
    cout << endl;
}
void add(vector<int>&vec,int num1,int num2)//加入num1个num2
//不加& add 中传递的是 vec 的副本,
//而不是原始 vec1。因此,add 修改的是副本,而不会影响 vec1。
{
    for(int i = 0;i < num1;i++)
    {
        vec.push_back(num2);
    }
}
int main()
{
    //可变长的数组
    //vector<类型>arr[长度,初始值]
    //连续顺序的存储结构,长度可变
    cout << "-----------喵" << endl;
    cout << "vec1(10,1): ";
    
    vector<int>vec1(10,1);//类型为int 10个int 1
    output2(vec1);
    cout << endl;
    //cout << "vec1[0]: " << vec1[0]  << endl;

    cout << "vec1 push two 3of2: ";
    add(vec1,2,3);
    output2(vec1);
    cout << endl;

    for(int i = 0;i < 10;i++)
    {
        vec1.push_back(10-i);
    }
    output2(vec1);
    //vec1排序
    sort(vec1.begin(),vec1.end());
    output2(vec1);
}