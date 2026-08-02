#include<iostream>
#include<string>
using namespace std;

int recursive_search(string licenses[], string tar, int n, int pos=0)
{
    if(pos>=n)
        return -1;
    if(licenses[pos]==tar)
    {
        return pos;
    }
    return recursive_search(licenses, tar, n, pos+1);

}

int main()
{
    int n;
    cout<<"Enter no. of vehicles: ";
    cin>>n;
    string license_plates[n];
    for(int i=0; i<n; i++)
    {
        cin>>license_plates[i];
    }
    string target;
    cout<<"Enter target license plate: ";
    cin>>target;
    int found=0;
    for(int i=0; i<n; i++)
    {
        if(license_plates[i]==target)
        {
            found=1;
            cout<<"The target is at position "<<i<<endl;
            break;
        }
    }
    if(!found)
        cout<<"Target not found.";

    int pos=recursive_search(license_plates, target, n);
    cout<<"Using recursion"<<endl;
    if(pos==-1)
        cout<<"Not found";
    else
        cout<<"Target at position: "<<pos;
    return 0;
}
