#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,M,K;
pair<int,int> p[100003];
int main() {
	scanf("%d%d%d",&N,&M,&K);
	for(int i = 0 ; i < M; i++){
		int a,b;
		scanf("%d%d",&a,&b);
		p[i] = {a,b};
	}
	int cur = K-1;
	for(int i = 0 ; i < M; i++){
		int rev = p[i].first;
		int l = p[i].second;
		if(rev){
			if(l >= N-cur) cur = 2*N-l-cur-1;
		}	
		else {
			if(l >= cur+1) cur = l-1-cur;
		}
	}
	printf("%d",cur+1);
	return 0;
}
