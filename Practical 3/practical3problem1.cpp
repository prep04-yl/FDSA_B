#include <iostream>
#include <utility>
using namespace std;

void bubble_sort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
void selection_sort(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_value=arr[i];
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<min_value)
            {
                min_value=arr[j];
            }
        }
        if(min_value!=arr[i])
            swap(arr[i], min_value);
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
void insertion_sort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int element=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>element)
        {
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=element;
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {2,3,8,4,6,1,9,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Method 1 (Using bubble sort): ";
    bubble_sort(arr, n);
    cout<<endl;
    cout<<"Method 1 (Using selection sort): ";
    selection_sort(arr, n);
    cout<<endl;
    cout<<"Method 1 (Using insertion sort): ";
    insertion_sort(arr, n);

    return 0;
}
