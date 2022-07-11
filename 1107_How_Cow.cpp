///Have faith in god.
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long int;
#define     Fin        freopen("input.txt","r",stdin)
#define     Fout       freopen("output.txt","w",stdout)
#define     test       ll t;cin>>t;while(t--)	
#define     FasterIO   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{
	int T,ar[4];
    cin >> T;
    for(int i = 1; i <= T; i++)
    {
        cin >> ar[0] >> ar[1] >> ar[2] >> ar[3];
        int m,fa[2];
        cin >> m;
        cout << "Case " << i << ":" << endl;
        for(int j = 0; j < m; j++)
        {
            cin >> fa[0] >> fa[1];
            if(fa[0] >= ar[0]&& fa[1] >= ar[1] && fa[0] <= ar[2] && fa[1] <= ar[3])
            cout << "Yes" << endl;
            else 
            cout << "No" << endl;
        }
    }
	return 0;
}

