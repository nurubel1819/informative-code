#include <bits/stdc++.h>
using namespace std;
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

int main()
{
    long long int n;
    cin>>n;
    vector<long long int> v;
    v = all_divisors(n);
    for (auto a : v)
        cout << a << " ";
    return 0;
}
