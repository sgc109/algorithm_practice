#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int p,x,y;
vector<int> giveT(int s){
	vector<int> ret;
	int i = (s / 50) % 475;
	for(int j = 0 ; j < 25; j++){
		i = (i*96+42)%475;
		ret.push_back(26+i);
	}
	return ret;
}
int main() {
	int ans = INF;
	scanf("%d%d%d",&p,&x,&y);
	for(int i = 0; x - i >= y; i += 50){
		int s = x - i;
		vector<int> ret = giveT(s);
		for(int j = 0 ; j < ret.size(); j++) {
			if(ret[j] == p) {
				ans = min(ans, 0);
			}
		}
	}
	for(int i = 0 ; i <= 1000000; i += 50) {
		int s = x + i;
		vector<int> ret = giveT(s);
		for(int j = 0 ; j < ret.size(); j++) if(ret[j] == p) ans = min(ans, (i+50)/100);
	}

	printf("%d",ans);
	return 0;
}
