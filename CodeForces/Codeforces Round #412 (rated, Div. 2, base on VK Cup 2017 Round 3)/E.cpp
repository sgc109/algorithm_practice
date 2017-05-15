#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N;
ll A[100003];
int rs[53];
int chunk[53];
int pow2[53];

int main() {
	scanf("%d",&N);
	for(int i = 0 ; i < N; i++){
		scanf("%lld",&A[i]);
		ll a = A[i];
		int cnt = -1;
		for(ll b = a; b ; b/=2) cnt++;
		if(a == (a&-a)) pow2[cnt]++;
		else rs[cnt]++;
	}

	vector<int> ans;

	int cnt = 0;
	while(pow2[0]){
		cnt++;
		int pos = 0;
		while(pow2[pos]) pow2[pos++]--;
		chunk[pos-1]++;

		int now = 0;
		int ok = 1;
		for(int i = 50; i >= 0 ; i--){
			now += chunk[i];
			now -= pow2[i+1] + rs[i];
			
			if(now < 0){
				ok = 0;
				break;
			}
		}
		if(now - pow2[0] < 0) continue;
		if(ok) ans.push_back(cnt);
	}
	if(ans.size()==0) return !printf("-1");
	for(int i = 0 ; i < ans.size(); i++) printf("%d ",ans[i]);
	return 0;
}
