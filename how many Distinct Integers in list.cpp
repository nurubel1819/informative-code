#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,valu,c=1;
    cin>>n;
    list<int> l;
    for(int i=0;i<n;i++) {
        cin>>valu;
        l.push_back(valu);
    }
    l.sort();
    int firsr = l.front();
    while (l.empty()==0)
     {
        if(firsr != l.front()) {
            firsr = l.front();
            c++;
            l.pop_front();
            
        }
        else {
            l.pop_front();
        }
    }
    cout<<c<<endl;
    return 0;
}
