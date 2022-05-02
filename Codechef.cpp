#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define loop(i,n) for(int i=0;i<n;i++)

long long lcm(int a,int b)
{
    int g = gcd(a,b);
    return (a*b)/g;
}

int32_t main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
	    int n,r; cin>>n>>r;
	    int arr_r[n];
	    int arr_c[n];
	    loop(i,n) cin>>arr_r[i];
	    loop(i,n) cin>>arr_c[i];
	    // int min_diff =abs( arr_r[0] - arr_c[0]);
        map<int,int> m;
	    for(int i = 0 ;i<n;i++)
	    {
            m.insert(pair<int,int>(abs( arr_r[i] - arr_c[i]),arr_r[i]));
	    }
        int cnt = 0;
	    for(auto x :m)
        {
            while(r >= x.second){
                r = r - x.first;
                cnt++;
            }
        }
        cout<<cnt<<"\n";
	}
	return 0;
}
