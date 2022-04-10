
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

int32_t main()
{
    int t;
    cin >> t;
    int x;
    while (t--)
    {
       int n;
       cin>>n;
       vector<int> v1;
       vector<int> v2;
       for(int i = 0;i<n;i++)
       {
           int x; 
           cin>>x;
           v1.push_back(x);
       }
       for(int i = 0;i<n;i++)
       {
           int x; 
           cin>>x;
           v2.push_back(x);
       }
       int sum = 0;
       int p,q,r;
       for(int i = 0;i<n-1;i++)
       {
           p = abs(v1[i] - v1[i+1]) + abs(v2[i] - v2[i+1]) ;
           q = abs(v1[i] - v2[i+1]) + abs(v2[i] - v1[i+1]) ;
           sum = sum + min(p ,q);
       }
       cout<< sum<<"\n";
       
    }
}