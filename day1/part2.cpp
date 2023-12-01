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

void solve() {
    ll res = 0;
    string s;
    while (getline(cin,s)) {
        int f=-1,l=-1;
        int fi = 0, li = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i]-'0'>=0&&s[i]-'0'<=9) {
                if (f==-1) {
                    f=(int)(s[i]-'0');
                    fi = i;
                }
                l=(int)(s[i]-'0');
                li = i;
            }
        }
        vector<string> v = {"zero","one","two","three","four","five","six","seven","eight","nine"};
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j <= s.size()-v[i].size(); j++) {
                int a = s.size(), b=v[i].size();
                if (a-b<0) {
                    break;
                }
                bool fl = true;
                for (int k = 0; k < v[i].size(); k++) {
                    if (v[i][k]!=s[j+k]) {
                        fl=false;
                        break;
                    }
                }
                if (fl) {
                    if (f==-1||fi>j) {
                        f=i;
                        fi=j;
                        if (l==-1) {
                            l = i;
                            li = j;
                        }
                    }
                    else {
                        int b = j;
                        if (li<b) {
                            l=i;
                            li=b;
                        }
                    }
                }
            }
        }
        res+=f*10+l;
        cout<<f*10+l<<endl;
        cout<<res<<endl;
    }
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll t;
    t=1;
    while (t--)
    {
        solve();
    }
    return 0;
}