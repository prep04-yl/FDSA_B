#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int count=0, maxlength=0;
    string word="", maxword;
    for(int i=0; i<s.length(); i++)
    {
        if((s[i]<65 || s[i]>90) && (s[i]<97 || s[i]>122))
        {
            if(count>maxlength)
            {
                maxlength=count;
                maxword=word;
            }
            count=0;
            word="";
            continue;
        }
        word+=s[i];
        count++;
    }
    if(count>maxlength)
    {
        maxlength = count;
        maxword = word;
    }
    cout<<"Longest word: "<<maxword<<endl;
    cout<<"Maximum word length: "<<maxlength<<endl;
    return 0;
}
