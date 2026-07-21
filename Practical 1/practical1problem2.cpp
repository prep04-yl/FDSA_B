#include<iostream>
using namespace std;

int main()
{
    int book_ids[100]={1, 2, 2, 3, 1, 4, 4, 5};
    int arr[100]={0}, size=(sizeof(book_ids)/sizeof(book_ids[0]));
    for(int val: book_ids)
    {
        arr[val]+=1;
    }
    cout<<"Book id borrowed more than once: ";
    for(int i=1; i<100; i++)
    {
        if(arr[i]>1)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
