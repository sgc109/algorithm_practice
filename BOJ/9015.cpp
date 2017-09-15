#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct point{
	int x, y;
	int cross(point rhs){
		return x * rhs.y - y * rhs.x;
	}
	point operator-(const point& rhs) const{
		return point{x - rhs.x, y - rhs.y};
	}
	point operator+(const point& rhs) const{
		return point{x + rhs.x, y + rhs.y};
	}
	int dot(point& rhs){
		return x * rhs.x + y * rhs.y;
	}
	int size(){
		return x * x + y * y;
	}
};
bool cmp1(point& a, point& b){
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}
point cen;
int ccw(point& a, point& b, point& c){
	return (a - c).cross(b - c);
}
bool cmp2(point& a, point& b){
	int ret = ccw(a, b, cen);
	if(!ret) return (a - cen).size() < (b - cen).size();
	return ret > 0;
}
point ps[3003];
set<pair<int,int> > st;
int N, T;
int main() {
	fastio();
	cin >> T;
	while(T--){
		st.clear();
		cin >> N;
		int ans = 0;
		for(int i = 0 ; i < N; i++) {
			int x, y;
			cin >> x >> y;
			ps[i] = point{x, y};
			st.insert({x, y});
		}
		sort(ps, ps + N, cmp1);
		for(int i = 0 ; i < N - 1; i++){
			cen = ps[i];
			sort(ps + i + 1, ps + N, cmp2);
			int l = i + 1, r = i + 1;
			while(r < N){
				point vl = ps[l] - ps[i];
				point vr = ps[r] - ps[i];
				point vm = ps[r] + vl;
				int dt = (vl).dot(vr);
				if(l == r) r++;
				else if(dt == 0){
					if(vl.size() == vr.size() && st.count({vm.x, vm.y})) ans = max(ans, vl.size());
					l++;
				}
				else if(dt > 0) r++;
				else if(dt == 1) l++;
				else l++;
			}
		}
		cout << ans << '\n';
	}	

	return 0;
}