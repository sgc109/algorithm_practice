#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
int T, M, N;
struct point{
    int x, y;
    bool operator<(const point& rhs) const{
        if(x == rhs.x) return y < rhs.y;
        return x < rhs.x;
    }
};
point points[50003];
int h[50003];
vector<point> v;
point A, B;
int dist(point& a, point& b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int main(){
    fastio();
    cin >> T;
    while(T--){
        v.clear();
        cin >> M >> N;
        for(int i = 0 ; i < N; i++){
            int xx, yy;
            cin >> xx >> yy;
            points[i] = point{xx, yy};
        }
        A = points[0], B = points[1];
        for(int i = 0 ; i < N; i++) {
            auto p = points[i];
            points[i] = point{dist(A, p), dist(B, p)};
        }
        sort(points, points + N);
        int lastY = 0x3c3c3c3c;
        for(int i = 0 ; i < N; i++){
            auto p = points[i];
            if(lastY <= p.y) continue;
            lastY = p.y;
            v.pb(p);
        }
        ll ans = 0;
        for(int i = 0 ; i < sz(v) - 1; i++){
            auto cur = v[i];
            auto nxt = v[i + 1];
            for(int j = cur.x ; j < nxt.x; j++) h[j] = cur.y;
        }
        int D = dist(A, B);
        int Y = A.y;
        for(int i = 0 ; i < D; i++){
            int x0 = i;
            int y0 = D - i;
            if(h[x0] == y0) continue;
            if(min(Y, M - Y - 1) * 2 < h[x0] - y0) ans += (1 + (min(Y, M - Y - 1) * 2) / 2 * 2 + (h[x0] - y0 - (min(Y, M - Y - 1) * 2) - 1) / 2);
            else ans += (1 + (h[x0] - y0 - 1) / 2 * 2);
        }
        cout << ans << '\n';
    }
    return 0;
}


