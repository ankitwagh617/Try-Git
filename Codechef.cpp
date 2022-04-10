#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    // your code goes here
	// cout<<"abcdefu"<<endl;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int tc;
	cin>>tc;
	while(tc--)
	{
	    int n,m;
	    cin>>n>>m;
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int arr[n][m];
		arr[x1-1][y1-1] = 1 ;
		arr[x2-1][y2-1] = 2 ; 	
	    
	}
	return 0;
}
