#include<bits/stdc++.h>
using namespace std;

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
/*
int main()
{
    int n;
    cin >> n;
	//it for segment tree
    for(int i=1;i<=n;i++) arr[i]=i;
    init(1, 1, n);
    cout << query(1, 1, n, 1, 3) << endl;
    update(1, 1, n, 2, 0);
    cout << query(1, 1, n, 1, 3) << endl;
    update(1, 1, n, 2, 7);
    cout << query(1, 1, n, 2, 3) << endl;
    return 0;
}
*/
void solve()
{
	int n,a,b,c,d,m,x,y,z,i,j;
}

int main()
{
	int t;
	t=0;
	cin>>t;
	while(t--) solve();

}
