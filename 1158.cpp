#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N,M;
int removed[5003];
int cnt;
int main() {
	vector<int> ans;
	scanf("%d%d",&N,&M);
	cnt = N;
	int pos = 0;
	while(cnt){
		int cnt2 = 0;
		for(;; pos=(pos+1)%N){
			if(removed[pos]) continue;
			cnt2++;
			if(cnt2 == M) {
				ans.push_back(pos);
				removed[pos] = 1;
				cnt--;
				break;
			}
		}
	}
	printf("<");
	for(int i = 0 ; i < ans.size(); i++){
		printf("%d", ans[i]+1);
		if(i < ans.size()-1) printf(", ");
		else printf(">");
	}
	return 0;
}
