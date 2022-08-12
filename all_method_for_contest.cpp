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
    //tree[node] = min(tree[Left],tree[Right]);//small element of range
}
//segment tree for output (node = 1 , b = array's first index , e = array's last index , i = range'f first index, j = range last index)
ll query(ll node, ll b, ll e, ll i, ll j)
{
    if (i > e || j < b)
        {
            return 0; //বাইরে চলে গিয়েছে,sum ar jonno
            //return INT_MAX;//minimum number 
            //return INT_MIN;//maximum number ar jonno
        }
    if (b >= i && e <= j)
        return tree[node]; //রিলেভেন্ট সেগমেন্ট
    ll Left = node * 2; //আরো ভাঙতে হবে
    ll Right = node * 2 + 1;
    ll mid = (b + e) / 2;
    ll p1 = query(Left, b, mid, i, j);
    ll p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2; //বাম এবং ডান পাশের যোগফল , sum of range
    //return max(p1,p2);// big number in range
    //return min(p1,p2);// small number in range
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
    //tree[node] = min(tree[Left],tree[Right]);//small element of range
}
*/
//------------------------------------------------------------------------

//return a vector there have all prime factro
vector<int> all_prime_factor(int n)
{
	vector<int> v;
	int spf[n+1]={0};
	for(int i=2;i<=n;i++) spf[i]=i;
	for(int i=2;i<=n;i++)
	{
		if(spf[i]==i)
		{
			for(int j=i*i;j<=n;j=j+i) if(spf[j]==j) spf[j]=i;
		}
	}
	while(n!=1)
	{
		v.push_back(spf[n]);
		n=n/spf[n];
	}
	return v;
}
//return a vector all prime number 2->n 
vector<int> all_prime(int n)
{
	int arr[n+1]={0};
	for(int i=2;i<=n;i++)
	{
		if(arr[i]==0)
		{
			for(int j=i*i;j<=n;j=j+i)
			{
				arr[j]=1;
			}
		}
	}
	vector<int> v;
	for(int i=2;i<=n;i++) if(arr[i]==0) v.push_back(i);
	return v;
}
//return a boolean value for prime or not
bool is_prime(long long int n)
{
	for(int i=2;i<=sqrt(n);i++) 
	{
		if(n%i==0) return false;
	}
	return true;
}

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

void solve()
{
    ll n,m,a,b,c,d,w,x,y,z,i,j;
    
}

int main()
{
    int t;
    t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
