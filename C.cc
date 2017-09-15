#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,K;
map<vector<int>,int> mp;
int main() {
	scanf("%d%d",&N,&K);
	int mod = 1;
	if(N==1) mod = 1;
	else if(N==2 || N%2) mod = 2;
	else mod = 4;

	K%=mod;

	vector<int> cur;
	for(int i = 1; i <= N; i++) cur.push_back(i);
	while(K--){
		vector<int> next1;
		for(int i = 0; i < N; i+=2) next1.push_back(cur[i]);
		for(int i = 1; i < N; i+=2) next1.push_back(cur[i]);
		vector<int> next2;
		for(int i = 0 ; i < N; i++){
			if(i%2) next2.push_back(next1[N-1-i/2]);
			else next2.push_back(next1[i/2]);
		}
		reverse(next2.begin(),next2.end());
		cur = next2;
	}
	for(int i = 0 ; i < cur.size(); i++) printf("%d ",cur[i]);


	return 0;
}
