#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define db double
#define MOD 1000000007
#define PB push_back
#define F first
#define S second
#define uset unordered_set
#define umap unordered_map
#define pq priority_queue
#define MP make_pair
#define vt vector
#define ins insert
#define __int128 int128
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)x.size()
#define REP(i, a) for (int i = 0; i < a; i++)
#define pii pair<int, int>;
#define setprf(x) setprecision(x) << fixed
#define setpr(x) setprecision(x)
#define pll pair<ll, ll>;

using namespace std;

typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef long double ld;
typedef complex<ld> cd;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll res = 0;
    string s;
    int cnt = 0;
    while (getline(cin,s)) {
        cnt++;
        int d = 1;
        if (cnt>=10) d++;
        if (cnt>=100) d++;
        int r = 0, b = 0, g= 0;
        int temp = 0;
        string col = "";
        bool f = false;
        for (int i = 7+d; i < s.size(); i++) {
            if (s[i]>=48&&s[i]<=57) {
                temp*=10;
                temp+=(int)(s[i]-'0');
            }
            else if (s[i]!=' '&&s[i]!=','&&s[i]!=';') {
                col+=s[i];
            }
            else if (s[i]==',') {
                if (col=="blue") b+=temp;
                else if (col=="red") r+=temp;
                else g+=temp;
                col="";
                temp=0;
            }
            if (s[i]==';'||i==s.size()-1) {
                if (col=="blue") b+=temp;
                else if (col=="red") r+=temp;
                else g+=temp;
                col="";
                temp=0;
                if (r>12||g>13||b>14) {
                    f=true; break;
                }
                r=0,g=0,b=0;
            }
        }
        if (!f) res+=cnt;
        cout<<res<<endl;
    }
    cout << res << endl;
    return 0;
}