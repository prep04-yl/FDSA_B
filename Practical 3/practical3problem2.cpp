#include<iostream>
using namespace std;

void sort_codes(int (&arr)[], int n)
{
    int count[3]={0};

    for(int i=0; i<n; i++)
    {
        count[arr[i]]++;
    }

    int k=0;
    for(int i=0; i<3; i++)
    {
        while(count[i]--)
        {
            arr[k++]=i;
        }
    }
}

int main()
{
    int arr[]={1,2,1,0,2,0,2,0,1,1,2,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Original: ";
    for(int i=0; i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    sort_codes(arr, n);
    cout<<"Sorted list: ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
