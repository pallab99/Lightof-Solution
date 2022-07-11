#include<bits/stdc++.h>
using namespace std;
void file()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}
int n,k;
int main()
{
    file();
    int t,cas=1;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cout << "Case " << cas++ << ":\n";
        string s = "";
        for(int i=0;i<n;i++)
            s += ('A'+i);
        do
        {
            for(int i=0;i<n;i++)
                cout << s[i];
            cout << endl;
            k--;
        }
        while(next_permutation(s.begin(),s.end()) && k);
    }
}
