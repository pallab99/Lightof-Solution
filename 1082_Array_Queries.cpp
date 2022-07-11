#include<bits/stdc++.h>
using namespace std;
int tree[400000];
int num[100050];
void build (int at, int L, int R) 
{ 
    if (L == R) {
        tree[at] = num[L];
        return;
    }
    int mid = (L+R) /2;
    build (2*at, L, mid);
    build (2*at+1, mid+1, R);
    tree[at] = min(tree[2*at], tree[2*at+1]);
}
int query (int at, int L, int R, int l, int r) { 
    if (L > r || R < l) return 1e9;
    if (L >= l && R <= r) return tree[at];
    int mid = (L+R) /2;
    int x = query (2*at, L, mid, l, r);
    int y = query (2*at+1, mid+1, R, l, r);
    return min(x, y);
}
int main ()
{
    int n, q, L, R, tc, k = 0;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &q);
        for (int i = 1; i <= n; i++) scanf (" %d", &num[i]);
        build (1, 1, n);
        printf ("Case %d:\n", ++k);
        while (q--) {
            scanf (" %d %d", &L, &R);
            printf ("%d\n", query (1, 1, n, L, R));
        }
    }
    return 0;
}