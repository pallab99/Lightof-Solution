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
#define        pi           acos(-1.0)
#define        inf          1<<30 //2^30
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
      //freopen("output.txt","w",stdout);
    #endif
}
map<string,int>mp;
vector<int>G[10020];
int indegree[10020];
bool cycle(int n)
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    int cnt=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cnt++;
        for(auto i:G[u])
        {
            indegree[i]--;
            if(indegree[i]==0)
            q.push(i);
        }
    }
    if(cnt!=n)
    return false;

    return true;
}
int main()
{
	  _00_
	  //inout();
      test
      {
          memset(indegree,0,sizeof indegree);
          for(int i=0;i<10020;i++)
          G[i].clear();
          mp.clear();
          int n,y=1;
          cin>>n;
          string s,s1;
          for(int i=0;i<n;i++)
          {
              cin>>s>>s1;
              if(!mp[s])
              {
              mp[s]=y; 
              y++;

              }
              if(!mp[s1])
              {
              mp[s1]=y;
              y++;
              }
              G[mp[s]].push_back(mp[s1]);
              indegree[mp[s1]]++;
          }
          //cout<<y<<endl;
          if(cycle(y-1))
          printf("Case %d: Yes\n",tc);
          else 
           printf("Case %d: No\n",tc);
      }
	return 0;
}