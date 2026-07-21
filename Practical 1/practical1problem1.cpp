#include<iostream>
using namespace std;

int main()
{
    int items;
    cout<<"Enter number of items: ";
    cin>>items;
    int arr[items];
    for(int i=0; i<items; i++)
    {
        cin>>arr[i];
    }
    int n;
    cout<<"Enter number of hours: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        int first=arr[0];
        for(int j=1; j<items; j++)
            arr[j-1]=arr[j];
        arr[items-1]=first;
    }
    for(int i=0; i<items; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
