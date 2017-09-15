#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,C,D;
int tc[400003], td[400003];
int size;
void update(int pos, int v, int *t){
	if(t[pos+=size] >= v) return;
	t[pos] = v;
	for(;pos>1;pos/=2) t[pos/2] = max(t[pos],t[pos^1]);
}
int query(int l, int r, int *t){
	int ret = 0;
	for(l+=size,r+=size; l<=r; l/=2,r/=2){
		if(l&1) ret = max(ret, t[l++]);
		if(~r&1) ret = max(ret, t[r--]);
	}
	return ret;
}

int main() {
	size = 100001;
	scanf("%d%d%d",&N,&C,&D);
	int ans = 0, maxC = 0, maxD = 0;
	for(int i = 0 ; i < N ; i++){
		int b,p;
		char type;
		scanf("%d %d %c\n",&b,&p,&type);
		if(type == 'C') {
			if(p <= C) maxC = max(maxC, b);
			if(p < C){
				int Max = query(1,C - p, tc);
				if(Max) ans = max(ans, Max + b);
			}
			update(p, b, tc);
		}
		else {
			if(p <= D) maxD = max(maxD, b);
			if(p < D) {
				int Max = query(1,D - p, td);
				if(Max) ans = max(ans, Max + b); 
			}
			update(p, b, td);
		}
	}
	if(maxC && maxD) ans = max(ans, maxC + maxD);

	printf("%d",ans);
	return 0;
}
