#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct point{
	int x,y;
};
int N,T;
vector<point> lovelyz;
vector<point> other;
int ans;
int maxCnt(int x1, int y1, int x2, int y2)	{
	int upLov = 0, downFuck = 0;
	if(x1 == x2){
		for(auto p : other) if(p.x < x1) downFuck++;
		for(auto p : lovelyz) if(x1 < p.x) upLov++;
	}
	else if(y1 == y2){
		for(auto p : other) if(p.y < y1) downFuck++;
		for(auto p : lovelyz) if(y1 < p.y) upLov++;
	}
	else {
		for(auto p : other) if((p.x-x1)*(y1-y2) > (p.y-y1)*(x1-x2)) downFuck++;
		for(auto p : lovelyz) if((p.x-x1)*(y1-y2) < (p.y-y1)*(x1-x2)) upLov++;
	}
	if(downFuck == other.size()){
		return upLov + 2;
	}
	else if(downFuck == 0){
		return lovelyz.size() - upLov;
	}
	return 0;
}
int main() {
	// freopen("output.txt","w",stdout);
	cin >> T;
	for(int t = 1; t <= T; t++){
		lovelyz.clear();
		other.clear();
		ans = 0;

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

				int f = maxCnt(p1.x, p1.y, p2.x, p2.y);
				ans = max(ans, f);
			}
		}
		cout << "Case #" << t << "\n" << ans << endl;
	}
	return 0;
}
