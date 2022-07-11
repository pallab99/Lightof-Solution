///Have faith in god.
#include<bits/stdc++.h>
using namespace std;
using ll= long long;
using ull= unsigned long long;
using pll= pair<ll,ll>;
using pii= pair<int,int>;
//-----------Typedefine-------------//
#define        nn           "\n"
#define        sp           " "
#define        F            first
#define        S            second
#define        OO           (1<<30)
#define        pi           acos(-1.0)
#define        no           cout<<"NO"<<endl;
#define        yes          cout<<"YES"<<endl;
#define        all(x)       (x).begin(),(x).end()
#define        deb(a)       cout<<" # "<<#a<<" -> "<<a<<endl;
#define        test         int t;cin>>t;for(int tc=1;tc<=t;tc++)
#define        _00_         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//---------------Function---------------//
ll To_int(string str){stringstream ss(str); ll x = 0; ss >> x ; return x ;}
string To_string(ll x){stringstream ss; ss << x; string str = ss.str(); return str;}
template<typename T>T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b < 0)return gcd(a,-b);return (b == 0)?a:gcd(b,a%b);}
template<typename T>T lcm(T a,T b){if(a<0)return lcm(-a,b);if(b < 0)return lcm(a,-b);return a*(b/gcd(a,b));}
void inout()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
      //freopen("output.txt","w",stdout);
    #endif
}
struct MST
{
    int u,v,w;
    bool operator<(const MST&p) const
    {
        return w<p.w;
    }
};
int par[100];
int parr[100];
vector<MST>G;
void Make_Set(int n)
{
    for(int i=0; i<n+2; i++)
     par[i]=i;
}
int find(int r)
{
    return (par[r] == r) ? r : find(par[r]);
}
int n;
MST ms;
int Kruskal()
{
    int cnt=0,sum=0;
    for(auto i:G)
    {
        int u=find(i.u);
        int v=find(i.v);
        if(u!=v)
        {
            par[u]=v;
            cnt++;
            sum+=i.w;
            if(cnt==n)
            return sum;
        }
    }
}
int main()
{
	  _00_
	  inout();
      test
      {
         int a,b,c;
          G.clear();
          cin>>n;
          Make_Set(n);
          while(cin>>a>>b>>c)
          {
              if(a==0 && b==0 && c==0)
              break;
              ms.u=a;
              ms.v=b;
              ms.w=c;
              G.push_back(ms);
          }
           sort(all(G));
           int ans=Kruskal();
           reverse(all(G));
           Make_Set(n);
           ans+=Kruskal();
           printf("Case %d: ",tc);
           if(ans&1)
           printf("%d/2\n",ans);
           else 
           printf("%d\n",ans/2);
      }
	return 0;
}