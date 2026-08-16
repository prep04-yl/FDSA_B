#include<iostream>
using namespace std;

void sort_codes(int (&arr)[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i]>arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

int main()
{
    int arr[]={1,2,1,0,2,0,2,0,1,1,2,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort_codes(arr, n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
