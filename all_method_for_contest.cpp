#include <bits/stdc++.h>
using namespace std;
#define ll long long int
/*
ll arr[99999999];
ll tree[100001 * 4];
//segment tree simply build(node=1,b=array's first index , e =array's last index)
void init(ll node, ll b, ll e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    ll Left = node * 2;
    ll Right = node * 2 + 1;
    ll mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];//sumation of range
    //tree[node] = max(tree[Left],tree[Right]);//big element of range
}
//segment tree for output (node = 1 , b = array's first index , e = array's last index , i = range'f first index, j = range last index)
ll query(ll node, ll b, ll e, ll i, ll j)
{
    if (i > e || j < b)
        return 0; //বাইরে চলে গিয়েছে
    if (b >= i && e <= j)
        return tree[node]; //রিলেভেন্ট সেগমেন্ট
    ll Left = node * 2; //আরো ভাঙতে হবে
    ll Right = node * 2 + 1;
    ll mid = (b + e) / 2;
    ll p1 = query(Left, b, mid, i, j);
    ll p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2; //বাম এবং ডান পাশের যোগফল , sum of range
    //return max(p1,p2);// big number in range
}
//segment tree for update (node = 1 , b = array's first index , e = array's last index , i = range'f first index, j = range last index)
void update(ll node, ll b, ll e, ll i, ll newvalue)
{
    if (i > e || i < b)
        return; //বাইরে চলে গিয়েছে
    if (b >= i && e <= i) { //রিলেভেন্ট সেগমেন্ট
        tree[node] = newvalue;
        return;
    }
    ll Left = node * 2; //আরো ভাঙতে হবে
    ll Right = node * 2 + 1;
    ll mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];// sum of element of range
    //tree[node] = max(tree[Left],tree[Right]);//big element of range
}
*/
//------------------------------------------------------------------------

long long gcd(long long int a, long long int b)//gosagu
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(int a, int b)//loasgu
{
    return (a / gcd(a, b)) * b;
}

//this methoe return all devisors for n
vector<long long int> all_divisors(long long int n)
{
    long long int i;
    vector<long long int> v;
    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
            v.push_back(i);
    }
    if (i - (n / i) == 1)
    {
        i--;
    }
    for (; i >= 1; i--)
    {
        if (n % i == 0)
            v.push_back(n / i);
    }
    return v;
}
//Time duration two time (w,x=start hour and menit and y,z = end hour and menit)
pair<int ,int> time_duration(int w,int x, int y, int z, int format)
{
    if(format==24)
    {
        if(y>=w)
        {
            if(z>=x) return (make_pair((y-w),(z-x)));
            else
            {
                if(w==y) return make_pair(23,(60-(x-z)));
                else return make_pair((y-w-1),(60-(x-z)));
            }
        }
        else
        {
            if(z>=x) return make_pair((24-(w-y)),(z-x));
            else return make_pair((24-(w-y+1)),(60-(x-z)));
        }
    }
    else if(format==12)
    {
        if(y>=w)
        {
            if(z>=x) return (make_pair((y-w),(z-x)));
            else
            {
                if(w==y) return make_pair(11,(60-(x-z)));
                else return make_pair((y-w-1),(60-(x-z)));
            }
        }
        else
        {
            if(z>=x) return make_pair((12-(w-y)),(z-x));
            else return make_pair((12-(w-y+1)),(60-(x-z)));
        }
    }
}
// frequency count ,, return a map
map<int,int> frequency_count(vector<int> v)
{
    map<int,int> mp;
    for(int i=0;i<v.size();i++)
    {
        if(mp.find(v[i])==mp.end()) mp[v[i]]=1;
        else mp[v[i]]++; 
    }
    //for(auto& at : mp) cout<< at.first << " " <<at.second <<endl; //print friquenci formate
    return mp;
}

int main()
{
    
    return 0;
}
