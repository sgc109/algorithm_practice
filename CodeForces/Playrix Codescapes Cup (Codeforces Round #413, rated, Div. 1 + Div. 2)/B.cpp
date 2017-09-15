#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
int M;
int selected[200003];
int p[200003];
int c1[200003];
int c2[200003];
priority_queue<pair<int,int> > pq[3];
int main() {
	scanf("%d",&N);
	for(int i = 0 ; i < N; i++) scanf("%d",&p[i]);
	for(int i = 0 ; i < N; i++) scanf("%d",&c1[i]), c1[i]--;
	for(int i = 0 ; i < N; i++) scanf("%d",&c2[i]), c2[i]--;
	for(int i = 0 ; i < N; i++){
		pq[c1[i]].push({-p[i],i});
		pq[c2[i]].push({-p[i],i});
	}
	scanf("%d",&M);
	for(int i = 0 ; i < M; i++) {
		int c;
		scanf("%d",&c);
		c--;
		bool found = false;
		pair<int,int> t;
		while(!pq[c].empty()){
			t = pq[c].top();
			pq[c].pop();
			if(selected[t.second]==0) {
				found = true;
				break;
			}
		}
		if(!found) printf("-1 ");
		else {
			selected[t.second] = 1;
			printf("%d ",-t.first);
		}
	}

	return 0;
}
