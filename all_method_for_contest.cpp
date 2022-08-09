#include <bits/stdc++.h>
using namespace std;
/*
int arr[100001];
int tree[100001 * 4];
//segment tree simply build(node=1,b=array's first index , e =array's last index)
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = tree[Left] + tree[Right];//sumation of range
    //tree[node] = max(tree[Left],tree[Right]);//big element of range
}
//segment tree for output (node = 1 , b = array's first index , e = array's last index , i = range'f first index, j = range last index)
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0; //বাইরে চলে গিয়েছে
    if (b >= i && e <= j)
        return tree[node]; //রিলেভেন্ট সেগমেন্ট
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return p1 + p2; //বাম এবং ডান পাশের যোগফল , sum of range
    //return max(p1,p2);// big number in range
}
//segment tree for update (node = 1 , b = array's first index , e = array's last index , i = range'f first index, j = range last index)
void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b)
        return; //বাইরে চলে গিয়েছে
    if (b >= i && e <= i) { //রিলেভেন্ট সেগমেন্ট
        tree[node] = newvalue;
        return;
    }
    int Left = node * 2; //আরো ভাঙতে হবে
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);
    tree[node] = tree[Left] + tree[Right];// sum of element of range
    //tree[node] = max(tree[Left],tree[Right]);//big element of range
}
*/
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

int main()
{
    /*long long int n;
    cin>>n;
    vector<long long int> v;
    v = all_divisors(n);
    for (auto a : v)
        cout << a << " ";
        
    int w,x,y,z;
    cin>>w>>x>>y>>z;
    pair<int,int> time;
    time = time_duration(w,x,y,z,24);
    cout<<time.first<< " "<<time.second<<endl;   
    */
   int a=8,b=12;
   cout<<gcd(a,b)<<endl;
   cout<<lcm(a,b)<<endl;
    return 0;
}
