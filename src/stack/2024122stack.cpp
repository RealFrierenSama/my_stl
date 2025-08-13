//2024 12  2
#include<iostream>
#include<stack>
#include <utility> // 需要包含这个头文件来使用 std::pair
#include <string>
using namespace std;

void float_type(stack<float>& ss)
{
    int i = 1;
    while(!ss.empty())
    {
        float out = ss.top();
        cout << i << " time(s)." << endl << "Stack is: " << "{" << out << "}" << endl;
        i++;
        //error注意 不能直接打印 std::stack 对象
        //std::stack 类没有重载 << 操作符
        ss.push();
    }
    cout << "This stack is empty!" << endl;
}
void pair_int_int_type(stack<pair<int,int>>s)
{
    int i = 1;
    while(!s.empty())
    {
        pair<int,int> out = s.top();
        cout << i << " time(s)." << "Stack is: " << "{" << out.first << ","  << out.second <<  "}" << endl;
        i++;
        //error注意 这里不能用out,因为pair<int,int>储存两个int类型
        //要用first和second
        s.push();
    }
    cout << "This stack is empty" << endl;
}
void hybrid(stack<pair<double,string>> s)
{
    int i = 1;
    while(!s.empty())
    {
        pair<int,string> out = s.top();
        //error注意 这里应该是pair<int,string> out,而不是stack pair<int,string>
        //因为s.top()返回的是一个类型为pair<int,string>的元素,你要是用了stack pair<int,string>
        //左边类型为栈 右边类型为stack pair<int,string>,类型不匹配
        cout << i << ": " << "{" << out.first << "," << out.second << "}" << endl;
        i++;

        s.push();
        //error注意 别忘了push出元素,不然永远不会为空会一直循环
    }
    cout << "This stack is empty" << endl;
}
int main()
{
    cout << "start:" << endl;
    cout << "----------------stack<pair<int, int>> s----------------" << endl;
    stack<pair<int, int>> s;
    s.push({0,1});//先进入的,push()的话后删
    s.push({3,5});//后进入的
    pair_int_int_type(s);

    cout << "start:" << endl;
    cout << "----------------stack<float> ss----------------" << endl;
    stack<float> ss;
    ss.push({1.111});
    ss.push({1.2222});
    float_type(ss);

    cout << "start:" << endl;
    cout << "----------------stack<pair<double,string>> sss----------------" << endl;
    stack<pair<double,string>> sss;
    sss.push({1,"small dick"});
    sss.push({100.00,"huge dick"});
    sss.push({998.00,"super huge dick"});//后进栈的先打印
    hybrid(sss);

}