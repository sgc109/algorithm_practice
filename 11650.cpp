#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const ll infl = 0x3c3c3c3c3c3c3c3c;

struct Point{
    int x, y;
    bool operator<(const Point& rhs) const {
        if(x != rhs.x) return x < rhs.x;
        return y < rhs.y;
    }
};
Point ps[100003];
int N;
int main() {
	fastio();
    cin >> N;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        ps[i] = Point{x, y};
    }
    sort(ps, ps + N);
    for(int i = 0; i < N; i++) cout << ps[i].x << ' ' << ps[i].y << '\n';
}
