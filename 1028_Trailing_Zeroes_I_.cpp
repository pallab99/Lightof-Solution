///Have faith in god.
#include<bits/stdc++.h>
using namespace std;
using ll= long long;
using ull= unsigned long long;
using pll= pair<ll,ll>;
using pii= pair<int,int>;
const int sz= 200000;

#define        nn           "\n"
#define        sp           " "
#define        F            first
#define        S            second
#define        OO           (1<<30)
#define        mod          1000000007
#define        pi           acos(-1.0)
#define        PB           emplace_back
#define        no           cout<<"NO"<<endl;
#define        yes          cout<<"YES"<<endl;
#define        all(x)       (x).begin(),(x).end()
#define        test         int t;cin>>t;while(t--)
#define        deb(a)       cout<<" # "<<#a<<" -> "<<a<<endl;
#define        _00_         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

class Function
{
  public:
ll To_int(string str){stringstream ss(str); ll x = 0; ss >> x ; return x ;}
string To_string(ll x){stringstream ss; ss << x; string str = ss.str(); return str;}
bool vowel_up(char c){return c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'O' || c == 'Y';}
bool vowel_low(char c){return c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o' || c == 'y';}
template<typename T>T lcm(T a,T b){if(a<0)return lcm(-a,b);if(b < 0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<typename T>T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b < 0)return gcd(a,-b);return (b == 0)?a:gcd(b,a%b);}
};

vector<ll>prime;
bitset<1000005>isprime;
void sieve()
{
    ll n=1000005;
    isprime.set();
    isprime[0]=0;
    isprime[1]=0;
    for(int i=2; i*i<=n; i++)
    {
        if(isprime[i])
            for(int j=2; i*j<=n; j++)
                isprime[i*j]=0;
    }
    for(int i=2; i<=n; i++)
    {
        if(isprime[i])
            prime.push_back(i);
    }
}
ll div_count(ll n)
{
    ll r=1,s,cnt;
    for(ll i=0;prime[i]<=sqrt(n) && i<prime.size();i++)
    {
        cnt=0;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
            cnt++;
            n/=prime[i];
            if(n==1 || n==0)
            break;
            }

           s=cnt+1;
           r*=s;
        }
    }
    if(n!=1)
    r*=2;
    return r;

}
int main()
{
	  //_00_
	  //inout();
      sieve();
      int tc=1;
     test
     {
         ll n;
         scanf("%lld",&n);
         ll ans=div_count(n)-1;
        printf("Case %d: %lld\n",tc++,ans);
     }
	return 0;
}