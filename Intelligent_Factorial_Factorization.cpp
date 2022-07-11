/*
                            ॐ नमो नारायणाय
 
                            ॐ नमः शिवाय
 
                            ॐ हरे कृष्ण
*/

#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
using vll = vector<ll>;
using vii = vector<int>;
using pll = pair<ll, ll>;
using ll  = long long int;
using pii = pair<int, int>;
using ull = unsigned long long int;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
//=============Typedefines=============//
#define        nn           "\n"
#define        F            first
#define        S            second
#define        pi           acos(-1.0)
#define        MOD          1000000007
#define        inf          1<<30 //2^30
#define        no           cout<<"NO"<<nn;
#define        yes          cout<<"YES"<<nn;
#define        FN(i,n)      for(int i=0;i<n;i++)
#define        FO(i,m,n)    for(int i=n;i>=m;i--)
#define        all(x)       (x).begin(),(x).end()
#define        test         int t, tc; cin>>t; for( tc = 1;tc <= t ; tc++)
#define        _00_         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//=============Functions===============//
ll To_int(string str) {stringstream ss(str); ll x = 0; ss >> x ; return x ;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
template<typename T>T lcm(T a, T b) {if (a < 0)return lcm(-a, b); if (b < 0)return lcm(a, -b); return a * (b / gcd(a, b));}
ll moduloMultiplication(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
template<typename T>T gcd(T a, T b) {if (a < 0)return gcd(-a, b); if (b < 0)return gcd(a, -b); return (b == 0) ? a : gcd(b, a % b);}
ll powermod(ll x, ll y, ll p){ll res=1;x=x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
// ====================DEBUG SECTION===================//                     
#define debug(a)cerr << "Line " << __LINE__ << " ## " << #a << " -->> ";_print(a);cerr << endl;
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(ld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T>
void _print(vector<T> vec)
{
  cerr << "["
       << " ";
  for (T i : vec)
  {
    cout << i << " ";
  }
  cerr << "]" << endl;
}
template <class T, class V>
void _print(map<T, V> v)
{
  cerr << "["
       << " ";
  for (auto i : v)
  {
    cout << i << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(pair<T, V> p)
{
  cerr << "{";
  _print(p.ff);
  cerr << ",";
  _print(p.ss);
  cerr << "}";
}
template <class T>
void _print(set<T> s)
{
  cerr << "["
       << " ";
  for (T i : s)
  {
    cout << i << " ";
  }
  cerr << "]" << endl;
}
const int d4i[4]={-1, 0, 1, 0}, d4j[4]={0, 1, 0, -1};
const int d8i[8]={-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8]={0, 1, 1, 1, 0, -1, -1, -1};
void input()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
vector<ll>prime;
bitset<150>status;
void sieve()
{
    ll n=150;
    status.set();
    status[0]=0;
    status[1]=0;
    for(ll i=2; i*i<=n; i++)
    {
        if(status[i])
            for(ll j=2; i*j<=n; j++)
                status[i*j]=0;
    }
    for(ll i=2; i<=n; i++)
    {
        if(status[i])
            prime.push_back(i);
    }
    // for(auto i:prime)
    // cout<<i<<" ";
}
int main()
{
    _00_
    // input();
    int tc;
    cin >> tc;
    sieve();
    for (int tt = 1; tt <= tc; tt++)
    {
        ll n;
        cin >> n;
        cout << "Case " << tt << ": " << n << " = ";
        vector<pll> p;
        ll cnt = 0;
        for (ll i = 0; prime[i] <= n; i++)
        {
            ll f = n;
            // debug(f);
            cnt = 0;
            while (f >= prime[i])
            {
                // debug(prime[i]);
                f = f / prime[i];
                // debug(f);
                cnt += f;
                // debug(cnt);
            }
            p.push_back(make_pair(prime[i], cnt));
        }

        cout << p[0].first << " (" << p[0].second << ")";
        for (int it = 1; it < p.size(); it++)
        {
            cout << " * " << p[it].first << " (" << p[it].second << ")";
        }
        cout << endl;
    }
    return 0;
}