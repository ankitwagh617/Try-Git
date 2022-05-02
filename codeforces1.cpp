#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define loop(i, n) for (int i = 0; i < n; i++)


int32_t main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string s;
        cin >> s;
        int n = s.length();
        set<char> c;
        bool ok = true;
        int k;
        for(k=0;k<n;k++)
        {
            if(c.find(s[k])==c.end())
                c.insert(s[k]);
            else
                break;
        }
        for(int i=k;i<n;i++)
        {
            if(s[i]!=s[i-k])
                ok = false;
        }
        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}