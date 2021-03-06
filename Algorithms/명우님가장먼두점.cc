#include <bits/stdc++.h>
using namespace std;
 
#define MAXN 200005
#define pb push_back
#define sz(v) ((int)(v).size())
typedef long long lld;
 
int N;
struct Z{
    int x, y;
} A[MAXN];
 
int ccw(int ax, int ay, int bx, int by, int cx, int cy)
{
    lld k = (lld)(bx-ax)*(cy-ay)-(lld)(cx-ax)*(by-ay);
    if (k > 0) return 1;
    if (k) return -1;
    return 0;
}
int ccw(const Z &a, const Z &b, const Z &c){ return ccw(a.x, a.y, b.x, b.y, c.x, c.y); }
 
lld dist(const Z &a, const Z &b)
{ return (lld)(b.x-a.x)*(b.x-a.x) + (lld)(b.y-a.y)*(b.y-a.y); }
 
int main()
{
    scanf("%d", &N);
    for (int i=1;i<=N;i++) scanf("%d%d", &A[i].x, &A[i].y);
 
    // Graham Scan
    for (int i=1;i<=N;i++) if (A[1].y > A[i].y || A[1].y == A[i].y && A[1].x > A[1].y) swap(A[1], A[i]);
    sort(A+2, A+N+1, [](const Z &a, const Z &b){
        int k = ccw(A[1], a, b);
        if (k) return k > 0;
        return (a.y-A[1].y)+abs(a.x-A[1].x) < (b.y-A[1].y)+abs(b.x-A[1].x);
    });
    vector <int> stk = {1}; stk.reserve(N);
    for (int i=2;i<=N;i++){
        while (sz(stk) > 1 && ccw(A[stk[sz(stk)-2]], A[stk.back()], A[i]) <= 0) stk.pop_back();
        stk.pb(i);
    }
 
    // Farthest two point
    int j = 1;
    lld ans = 0; Z p, q;
    for (int i=0;i<sz(stk);i++){
        int ni = (i+1) % sz(stk);
        for (;;){
            int nj = (j+1) % sz(stk);
            int v = ccw(0, 0, A[stk[ni]].x-A[stk[i]].x, A[stk[ni]].y-A[stk[i]].y, A[stk[nj]].x-A[stk[j]].x, A[stk[nj]].y-A[stk[j]].y);
            if (v > 0) j = nj;
            else break;
        }
        lld v = dist(A[stk[i]], A[stk[j]]);
        if (ans < v)
            ans = v, p = A[stk[i]], q = A[stk[j]];
    }
 
    printf("Farest two points are (%d, %d) <-> (%d, %d)\n", p.x, p.y, q.x, q.y);
}