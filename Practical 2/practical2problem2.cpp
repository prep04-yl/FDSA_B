#include<iostream>
using namespace std;

int bookcode_binarysearch(int book_codes[], int target, int st, int end)
{
    int mid=st+(end-st)/2;
    if(book_codes[mid]==target)
        return mid+1;
    if(book_codes[mid]>target)
        end=mid-1;
    else
        st=mid+1;
    return bookcode_binarysearch(book_codes, target, st, end);
}

int main()
{
    int n;
    cout<<"Enter no. of book codes: ";
    cin>>n;
    int book_codes[n];
    cout<<"Book codes (in sorted manner):";
    for(int i=0; i<n; i++)
    {
        cin>>book_codes[i];
    }
    int target;
    cout<<"Enter target code: ";
    cin>>target;
    int st=0, end=n-1, found=0;
    cout<<"Using recursive function: "<<bookcode_binarysearch(book_codes, target, st, end)<<endl;
    while(st<=end)
    {
        int mid=st+(end-st)/2;
        if(book_codes[mid]==target)
        {
            cout<<"Position: "<<mid+1;
            found=1;
            break;
        }
        if(book_codes[mid]>target)
            end=mid-1;
        else
            st=mid+1;
    }
    if(!found)
        cout<<"Target not found"<<endl;
    return 0;
}
