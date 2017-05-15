#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int cnt[10000];
int main() {
	int N;		
	int changed = 0;
	scanf("%d",&N);
	vector<int> v;
	for(int i = 0 ; i < N; i++){
		int a,b;
		scanf("%d%d",&a,&b);
		v.push_back(a);
		cnt[a]++;
		if(a!=b) changed = 1;
	}
	if(changed){
		printf("rated");
		return 0;
	}
	int sz = v.size()-1;
	bool found = false;
	for(int i = 0 ; i < sz; i++){
		if(v[i] < v[i+1]) found = true;
	}
	if(found) printf("unrated");
	else printf("maybe");
	return 0;
}
