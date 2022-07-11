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
struct node
{
    int at;
    int cost;
    node(int _at, int _cost)
    {
        at = _at;
        cost = _cost;
    }
    bool operator<(const node &p) const { return cost > p.cost; } //Operator overloading
};
struct Edge
{
    int v,w;
};
vector<Edge>G[1200];
int dist[1200];
void dijkstra(int src)
{
    dist[src]=0;
    priority_queue<node>pq;
    pq.push(node(src,0));
    while(!pq.empty())
    {
        node u=pq.top();
        pq.pop();
        if(u.cost!=dist[u.at])
        continue;
        for(Edge e:G[u.at])
        {
            if(dist[e.v]>u.cost+e.w)
            {
                dist[e.v]=u.cost+e.w;
                pq.push(node(e.v,dist[e.v]));
            }
        }
    }
    return;
}
int main()
{
	  //_00_
	  inout();
    test
   {
       for(int i=0;i<1200;i++)
       {
           G[i].clear();
           dist[i]=inf;
       }
       int n,m;
       cin>>n>>m;
       for(int i=0;i<m;i++)
       {
          int u,v,w;
          cin>>u>>v>>w;
          Edge temp;
          temp.v=v;
          temp.w=w;
          G[u].push_back(temp);
          temp.v=u;
          G[v].push_back(temp);
       }
       dijkstra(1);
       printf("Case %d: ",tc);
       if(dist[n]!=inf)
       cout<<dist[n]<<endl;
       else 
       cout<<"Impossible"<<endl;
   }
	return 0;
}