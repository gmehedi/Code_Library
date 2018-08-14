#include<iostream>
#include<cstdio>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>
#include<deque>
#include<iterator>
#include<assert.h>
#include<bitset>
#include<climits>
#include<ctime>
#include<complex>
#include<bits/stdc++.h>
using namespace std;
//define for shortcut
#define mem(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define sz(A) A.size()
#define clr(a) memset(a,0,sizeof(a))
#define pb push_back
#define pi acos(-1.0)
#define mp(a,b) make_pair(a,b)
#define pii pair<ll,ll>
#define vpii vector< pair<ll,ll> >
#define pcc pair<char,char>
#define pic pair<ll,char>
#define pci pair<char,ll>
#define pis pair<ll,string>
#define psi pair<string,ll>
#define vs vector<string>
#define vi vector<ll>
#define vc vector<char>
#define sts set<string>
#define sti set<ll>
#define stc set<char>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define ull unsigned long long
#define ll long long
#define for1(i,a,b) for(ll i=a;i<=b;i++)
#define rfor1(i,a,b) for(ll i=a;i>=b;i--)
#define rfor0(i,a,b) for(ll i=a-1;i>b;i--)
#define for0(i,a) for(ll i=0;i<a;i++)
//read input
#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sfll(a) scanf("%lld",&a)
#define sfll2(a,b) scanf("%lld%lld",&a,&b)
#define sfll3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define ss(a) scanf("%s",&a)
#define sc(a) scanf("%c",&a)
#define sd(a) scanf("%lf",&a)
#define pf(a) prllf("%d",a)
#define pfll(a) printf("%lld",a)
#define pfd(a) prllf("%.17f",a)
#define pc(a) prllf("%c",a)
#define ps(a) prllf("%s",a)
#define cs prllf("Case %d: ",kk++)
#define cn prllf("Case %d:\n",kk++)
///#define c# prllf("Case #%d: ",kk++)
#define nl printf("\n")
#define done cout<<"done"<<endl;
#define eps 1e-9
#define mod 1000000007
#define inf ll_MAX
#define MX 100010
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define fast ios_base::sync_with_stdio(false);
template<typename T>inline string tostring(T a)
{
    ostringstream os("");
    os << a;
    return os.str();
}
template<typename T>inline ll tolong(T a)
{
    ll res;
    istringstream os(a);
    os>>res;
    return res;
}
template<typename T>inline vi parse(T str)
{
    vi res;
    ll s;
    istringstream os(str);
    while(os>>s)res.pb(s);
    return res;
}
template< class T > inline T _sqrt(T x)
{
    return (T) sqrt( (double) x);
}
template< class T > inline T _bigmod(T n,T m)
{
    T ans=1,mult=n%mod;
    while(m)
    {
        if(m & 1) ans=(ans*mult)%mod;
        m>>=1;
        mult=(mult*mult)%mod;
    }
    ans%=mod;
    return ans;
}
template< class T > inline T _modinv(T x)
{
    return _bigmod(x,(T) mod-2)%mod;
}
inline ll len(string a)
{
    return a.length();
}
inline ll len(char a[])
{
    return strlen(a);
}
template<class T> inline T _gcd(T a, T b)
{
    return (b==0) ? a : _gcd(b, a % b);
}
template< class T > inline T _lcm(T x,T y)
{
    return x*y/_gcd(x,y);
}
//ll dx[]={1,0,-1,0};ll dy[]={0,1,0,-1}; //4 Direction
//ll dx[]={1,1,0,-1,-1,-1,0,1};ll dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//ll dx[]={2,1,-1,-2,-2,-1,1,2};ll dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//ll dx[6]={2,1,-1,-2,-1,1};ll dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
//bool compare(const pair<float,string>&i, const pair<float,string>&j)
//{
//    return i.first > j.first;
//}
//ll in_c() { ll c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
//ll EQ(double d) {
//    if ( fabs(d) < EPS ) return 0;
//    return d > EPS ? 1 : -1 ;
//}
map<string,ll>mp;
string s[100001];
ll arr[100009];
ll brr[100009];
int main()
{
//    clock_t begin = clock();
//    //your code goes here
        ll n,m,k;
        sfll3(n,k,m);
       for(ll i=0; i<n; i++)
       {
           cin>>s[i];
       }
       for(ll i=0; i<n; i++)
       {
           ll x;
           sfll(x);
           arr[i+1]=x;
           mp[s[i]]=x;
       }
       for(ll i=0; i<k; i++)
       {
           ll l;
           sfll(l);
           ll mn=1e9+1;
           for(ll j=0; j<l; j++)
           {
               ll p;
               sf(p);
               brr[j]=p;
               mn=min(arr[p],mn);
           }
           for(ll j=0; j<l; j++)
           {
               mp[s[brr[j]-1]]=mn;
           }
       }
       ll ans=0;
       for(ll i=0; i<m; i++)
       {
           string s;
           cin>>s;
           ans+=(ll)mp[s];
       }
       pfll(ans);
       nl;
//    //end here
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;
//    return 0;
}


