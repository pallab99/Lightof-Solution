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
int visit[22][22],dis[22][22],T,m,n;
int dirx[] = {-1,1,0,0};
int diry[] = {0,0,-1,1};
char str[22][22];
 
void bfs(int i,int j){
    for(int x=0; x < m; x++){
        for(int y = 0; y < n; y++) {
            dis[x][y]=INT_MAX;
            visit[x][y]=0;
        }
    }
    visit[i][j] = 1;
    dis[i][j] = 0;
 
    queue<pii>q;
    q.push(make_pair(i,j));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++){
            i = x + dirx[k];
            j = y + diry[k];
            if(i > -1 && i < m && j >-1 && j<n && str[i][j] !='#' && str[i][j]!= 'm' && visit[i][j] == 0){
                dis[i][j] = min(dis[x][y]+1,dis[i][j]);
                visit[i][j] = 1;
                q.push(make_pair(i,j));
            }
        }
    }
}
int main(){
    inout();
    int homX,homY;
    cin >> T;
    for(int t = 1; t<= T; t++){
        cin >> m >> n;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> str[i][j];
                if(str[i][j] == 'h'){
                    homX = i;homY = j;
                }
            }
        }
        int mxa,mxb,mxc;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                 if(str[i][j]=='a'){
                    bfs(i,j);
                    mxa = dis[homX][homY];
                 }
                 else if(str[i][j]=='b'){
                    bfs(i,j);
                    mxb = dis[homX][homY];
                 }
                 else if(str[i][j]=='c'){
                    bfs(i,j);
                    mxc = dis[homX][homY];
                 }
            }
        }
        cout << "Case " << t << ": " << max(max(mxa,mxb),mxc) << endl;
    }
    return 0;
}