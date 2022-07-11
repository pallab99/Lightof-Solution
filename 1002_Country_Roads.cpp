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
        //freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
}
struct node
{
    int u;
    int cost;
    node(int _u, int _cost)
    {
        u = _u;
        cost = _cost;
    }
    bool operator<(const node &p) const { return cost > p.cost; } //Operator overloading
};
vector<int>G[510],weight[510];
int dist[510];
void Dijkstra(int src)
{
    priority_queue<node>q;
    q.push(node(src,0));
    dist[src]=0;
    while(!q.empty())
    {
        node top=q.top();
        q.pop();
        int uu=top.u;
        if(dist[uu]<top.cost)
        continue;
        for(int i=0;i<G[uu].size();i++)
        {
            int v=G[uu][i];
            int w=weight[uu][i];
            if(dist[v]>max(w,dist[uu]))
            {
                dist[v]=max(w,dist[uu]);
                q.push(node(v,dist[v]));
            }
        }
    }
}
int main()
{
	  //_00_
	  //inout();
     test
     {
      for(int i=0;i<510;i++)
      {
          G[i].clear();
          weight[i].clear();
          dist[i]=inf;
      }
      int n,m;
      cin>>n>>m;
      for(int i=0;i<m;i++)
      {
          int u,v,w;
          cin>>u>>v>>w;
          G[u].push_back(v);
          G[v].push_back(u);
          weight[u].push_back(w);
          weight[v].push_back(w);
      }
      int src;
      cin>>src;
      Dijkstra(src);
      printf("Case %d:\n",tc);
        for(int i=0;i<n;i++)
        {
            if(dist[i]==inf)
                printf("Impossible\n");
            else
                printf("%d\n",dist[i]);
        }
     }
	return 0;
}