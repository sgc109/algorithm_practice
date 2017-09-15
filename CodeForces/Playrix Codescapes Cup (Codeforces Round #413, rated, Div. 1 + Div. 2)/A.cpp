#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int n,t,k,d;
int main() {
	scanf("%d%d%d%d",&n,&t,&k,&d);
	int ans1 = (n+k-1)/k*t;

	int i;
	int cnt = 0;
	bool used = false;
	for(i = 0; ; i++){
		if(i && i%t==0) cnt+=k;
		if(i>d && (i-d)%t==0) {
			used = true;
			cnt+=k;
		}
		if(cnt >= n) break;
	}
	if(ans1 <= i) printf("NO");
	else printf("YES");
	return 0;
}
