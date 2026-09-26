#include<iostream>
using namespace std;
#define n 10


void place(int* stack, int &top)
{
    if(top==n-1)
        cout<<"Stack overflow"<<endl;
    else
    {
        top=top+1;
        stack[top]=1;
        cout<<top<<endl;
    }
}
void take(int* stack, int &top)
{
    if(top==-1)
        cout<<"Stack underflow"<<endl;
    else
    {
        top=top-1;
        cout<<top<<endl;
    }
}

int main()
{
    int top=-1;
    int stack[n];
    place(stack,top);
    place(stack,top);
    place(stack,top);
    place(stack,top);
    take(stack,top);
    place(stack,top);
    place(stack,top);
    place(stack,top);
    take(stack,top);
    place(stack,top);
    place(stack,top);
    place(stack,top);
    place(stack,top);
    place(stack,top);
    place(stack,top);
    place(stack,top);
    return 0;
}
