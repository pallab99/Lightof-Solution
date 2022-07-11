///Have faith in god.
#include<bits/stdc++.h>
using namespace std;
using ll= long long;
using ull= unsigned long long;
using pll= pair<ll,ll>;
using pii= pair<int,int>;
//=============Typedefines=============//
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
//=============Functions===============//
ll To_int(string str){stringstream ss(str); ll x = 0; ss >> x ; return x ;}
string To_string(ll x){stringstream ss; ss << x; string str = ss.str(); return str;}
template<typename T>T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b < 0)return gcd(a,-b);return (b == 0)?a:gcd(b,a%b);}
template<typename T>T lcm(T a,T b){if(a<0)return lcm(-a,b);if(b < 0)return lcm(a,-b);return a*(b/gcd(a,b));}
void inout()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
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
map<string,int>mp;
MST ms;
int par[120];
vector<MST>G;
void Make_Set(int n)
{
    for(int i=1; i<=n+2; i++)
     par[i]=i;
}
int find(int r)
{
    return (par[r] == r) ? r : find(par[r]);
}
int sum;
bool Kruskal(int index)
{
    int tc=1;
    Make_Set(index);
    sort(all(G));
    int cnt=0;
    sum=0;
    for(auto i:G)
    {
        int u=find(i.u);
        int v=find(i.v);
        if(u!=v)
        {
            par[u]=v;
            cnt++;
            sum+=i.w;
           // deb(sum);
            if(cnt==index-1)
            break;
        }
    }
    //deb(cnt);
    //deb(index);
    if(cnt!=index-2)
    return false;
    else 
    return true;
}
int main()
{
	  _00_
	  inout();
      int T=0;
      test
      {
          mp.clear();
          G.clear();
          int n;
          cin>>n;
          
          string s1,s2;
          int cost,index=1;
          for(int i=0;i<n;i++)
          {
              cin>>s1>>s2>>cost;
              if(mp.find(s1)==mp.end())
              {
                  mp[s1]=index++;
                  //index++;
              }
              if(mp.find(s2)==mp.end())
              {
                  mp[s2]=index++;
                  //index++;
              }
             ms.u=mp[s1];
             ms.v=mp[s2];
             ms.w=cost;
             G.push_back(ms);
          }
          //for(auto i:G)
          //{
              //cout<<i.u<<sp<<i.v<<sp<<i.w<<endl;;
          //}
         
           if(Kruskal(index))
           cout<<"Case "<<tc<<": "<<sum<<endl;
          // printf("Case %d: %d\n",++T,sum);
           else 
           cout<<"Case "<<tc<<": Impossible"<<endl;
           //printf("Case %d: Impossible\n",++T);
      }
	return 0;
}