#include <bits/stdc++.h>
using namespace std;
#define MAX                 110000
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())
#define error(args...)      { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }


typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {                                                  // Debugger error(a, b, ....)
	cerr << *it << " = " << a << "\n";
	err(++it, args...);
}

int len, k;
string str;

ll hauwa[60][60];

ll recur(int pos, int open) {
    if(pos == len) {
        if(open == 0)
            cout << str << endl;
        return (open == 0);
    }

    //cout << "AT " << pos << " " << open << endl;
    //if(hauwa[pos][open] != -1)
    //    return hauwa[pos][open];

    ll ret = 0;
    if(open > 0) {
        str.pb(')');
        ret += recur(pos+1, open-1);
        str.pop_back();
    }

    str.pb('(');
    ret += recur(pos+1, open+1);
    str.pop_back();

    return hauwa[pos][open] = ret;
}

int main() {
    int t;
    cin >> t;

    for(int Case = 1; Case <= t; ++Case) {
        memset(hauwa, -1, sizeof hauwa);
        cin >> len >> k;
        for(int i = 0; i  < k; ++i) str.pb('(');

        ll ans = recur(k, k);

        cout << "Case " << Case << ": " << ans << endl;
    }

    return 0;
}
