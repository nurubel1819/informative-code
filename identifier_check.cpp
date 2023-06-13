#include<bits/stdc++.h>
using namespace std;

bool isIdentifier(string s)
{
    int n=s.size();
    if((s[0]>='a' and s[0]<='z') or (s[0]>='A' and s[0]<='Z') or (s[0]=='_'))
    {
        for(int i=1;i<n;)
        {
            if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z') or (s[0]=='_') or (s[i]>=0 and s[i]<=9)) i++;
            else return false;
        }
    }
    else return false;
    return true;
}

int main()
{
    string s;
    getline(cin,s);
    bool flag = isIdentifier(s);
    if(flag==true) cout<< "Yes" <<endl;
    else cout<< "No" <<endl;
    return 0;
}
