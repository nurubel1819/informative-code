#include<bits/stdc++.h>
using namespace std;

bool is_email_valid(string s)
{
    int n = s.size();
    if(s[0]>='a' and s[0]<='z')
    {
        int ad=-1;
        int dot=-1;
        for(int i=1;i<n;i++)
        {
            
            if(s[i]=='@') ad=i;
            else if(s[i]=='.') dot=i;
            else if(s[n-1]=='.') return false;
        }
        if(ad==-1 or dot==-1) return false;
        else if(dot<ad) return false;
    }
    else return false;
    return true;
}

int main()
{
    string s;
    cout<< "Enter email address :";
    cin>>s;
    if(is_email_valid(s)) cout<< "Yes" <<endl;
    else cout<< "No"<<endl;
    return 0;
}

