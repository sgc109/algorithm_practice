#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct point{int x, y;};
pair<int,int> t[2000003];
ll tp[2000003];
point in[300003];
int N, K, size;

void update(int x, int v){
	while(x <= size) tp[x] += v, x += x & -x;
}

ll queryBIT(int x, ll ret = 0){
	while(x > 0) ret += tp[x], x -= x & -x;
	return ret;
}
void init(){
	for(int i = size - 1; i > 0; i--) {
		auto p1 = t[i * 2], p2 = t[i * 2 + 1];
		t[i] = min(p1, p2);
	}
}
pair<int,int> query(int l, int r){
	pair<int,int> ret = {inf, inf};
	for(l += size, r += size; l < r; l /= 2, r /= 2){
		if(l & 1) ret = min(ret, t[l++]);
		if(r & 1) ret = min(ret, t[--r]);
	}
	return ret;
}
ll go(int s, int e, int h){
	if(s == e) return 0;
	auto mid = query(s, e);
	int id = mid.second;
	int nh = mid.first;
	if(id == inf) return 0;
	ll ret = 0;
	int cnt = queryBIT(e) - queryBIT(s);
	if(cnt == 0) ret += (ll)(nh - h) * (e - s);
	ret += go(s, in[id].x, nh) + go(in[id + 1].x, e, nh);
	return ret;
}
double go2(int s, int e, int h){
	int cnt = queryBIT(e) - queryBIT(s);
	if(cnt == 0) return 0;
	auto mid = query(s, e);
	int id = mid.second;
	int nh = mid.first;
	double ret = 0;
	ret += ((double)(nh - h) * (e - s)) / cnt;
	ret += max(go2(s, in[id].x, nh), go2(in[id + 1].x, e, nh));
	return ret;
}
int main() {
	size = 524288;
	for(int i = 0 ; i < 2000000; i++) t[i] = {inf, inf};
	scanf("%d", &N);
	for(int i = 0 ; i < N; i++){
		scanf("%d %d", &in[i].x, &in[i].y);
		if(i % 2 && i != N - 1) {
			t[size + in[i].x] = {in[i].y, i};
		}
	}
	scanf("%d", &K);
	for(int i = 0 ; i < K; i++){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		update(x1 + 1, 1);
	}

	init();
	printf("%.2lf\n", go2(0, in[N - 1].x, 0));
	printf("%lld", go(0, in[N - 1].x, 0));

	return 0;
}