#include <iostream>
using namespace std;
#define size 3
int rear = 0;
int front = 0;
int arr[size];
void queen_in(int val)
{
    if(rear == size)
    {
        cout << "full";
    }
    else
    {
        arr[rear] = val;
        rear++;
    }
}
void queen_out(int val)
{
    if(rear == size)
    {
        cout << "empty";
    }
    else
    {
        arr[front];
        front++;
    }
}
