#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

map<pair<pair<int,int>,int>,int> dp1, dp2;
int N;
int C,D;
int b1[100003], p1[100003];
int b2[100003], p2[100003];
int cnt1, cnt2;

int go1(int pos, int rest, int cnt){
	if(cnt==0) return 0;
	if(pos == cnt1) return -inf;

	auto it = dp1.find({{pos,rest},cnt});
	if(it!=dp1.end()) return (*it).second;
	
	int ret = 0;
	ret = max(ret, go1(pos+1,rest,cnt));
	if(rest >= p1[pos]) ret = max(ret, go1(pos+1,rest-p1[pos],cnt-1)+b1[pos]);

	return dp1[{{pos,rest},cnt}] = ret;
}

int go2(int pos, int rest, int cnt){
	if(cnt==0) return 0;
	if(pos == cnt2) return -inf;

	auto it = dp2.find({{pos,rest},cnt});
	if(it!=dp2.end()) return (*it).second;
	int ret = 0;
	ret = max(ret, go2(pos+1,rest,cnt));
	if(rest >= p2[pos]) ret = max(ret, go2(pos+1,rest-p2[pos],cnt-1)+b2[pos]);

	return dp2[{{pos,rest},cnt}] = ret;
}

int main() {
	scanf("%d%d%d",&N,&C,&D);
	for(int i = 0 ; i < N ;i++){
		int b,p;
		char type;
		scanf("%d %d %c\n",&b,&p,&type);
		if(type=='C'){
			b1[cnt1] = b;
			p1[cnt1++] = p;
		}
		else {
			b2[cnt2] = b;
			p2[cnt2++] = p;	
		}
	}
	int ans = 0;
	int bestC = 0;
	int bestD = 0;
	for(int i = 0 ; i < cnt1; i++) {
		if(p1[i] <= C) bestC = max(bestC, b1[i]);
	}
	for(int i = 0 ; i < cnt2; i++) {
		if(p2[i] <= D) bestD = max(bestD, b2[i]);
	}
	if(bestC && bestD) ans = max(ans, bestC + bestD);

	ans = max(ans, go1(0,C,2));
	ans = max(ans, go2(0,D,2));

	printf("%d",ans);

	return 0;
}