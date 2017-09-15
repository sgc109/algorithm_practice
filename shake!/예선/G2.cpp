#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct point{
	int x,y;
	bool operator==(const point& rhs) const {return x == rhs.x && y == rhs.y;}
};
int N,T;
vector<point> lovelyz;
vector<point> other;

int ccw(point& p1, point& p2, point& p3){
	int ret = (p2.x - p1.x) * (p3.y - p1.y) -  (p2.y - p1.y) * (p3.x - p1.x);
	return ret > 0 ? 1 : -1;
}

int maxCnt(point& p1, point& p2){
	int ret = 0;
	int upLove = 0;
	int upOther = 0;
	for(int i = 0 ; i < lovelyz.size(); i++){
		auto p = lovelyz[i];
		if(p == p1 || p == p2) continue;
		if(ccw(p1,p2,p) > 0) upLove++;
	}
	for(int i = 0 ; i < other.size(); i++){
		auto p = other[i];
		if(ccw(p1,p2,p) > 0) upOther++;
	}

	if(upOther == other.size()) return lovelyz.size() - upLove;
	else if(upOther == 0) return upLove + 2;
	return 0;
}
int main() {
	cin >> T;
	for(int t = 1; t <= T; t++){
		lovelyz.clear();
		other.clear();
		int ans = 0;

		cin >> N;
		for(int i = 0 ; i < N; i++){
			int x,y;
			string s;
			cin >> x >> y >> s;
			if(s == "LOVELYZ") lovelyz.push_back(point{x,y});
			else other.push_back(point{x,y});
		}
		for(int i = 0 ; i < lovelyz.size(); i++){
			for(int j = i+1; j < lovelyz.size(); j++){
				point p1 = lovelyz[i];
				point p2 = lovelyz[j];

				int f = maxCnt(p1, p2);
				ans = max(ans, f);
			}
		}
		cout << "Case #" << t << "\n" << ans << endl;
	}
	return 0;
}
	