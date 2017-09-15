#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int T,N,M;
int A[1000003];
int divv[1000003];
vector<int> go(int pos, int cnt, int res, vector<pair<int,int> >& v, int size){
	if(pos == size) return vector<int>({res});
	vector<int> ret;
	vector<int> A = go(pos + 1, 0, res, v, size);
	vector<int> B;
	if((int)v[pos].second > cnt) B = go(pos, cnt + 1, res * v[pos].first, v, size);
	for(int i = 0 ; i < (int)A.size(); i++) ret.push_back(A[i]);
	for(int i = 0 ; i < (int)B.size(); i++) ret.push_back(B[i]);
	return ret;

}
int main() {
	divv[1] = 0;
	for(int i = 2; i * i <= 1000000; i++){
		if(divv[i]) continue;
		divv[i] = i;
		for(int j = 2*i; j <= 1000000; j += i) if(!divv[j]) divv[j] = i;
	}

	for(int i = 2; i <= 1000000; i++) if(divv[i] == 0) divv[i] = i;
	
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		printf("Case #%d\n", t);
		scanf("%d %d\n",&N, &M);
		for(register int i = 0 ; i < N; i++) scanf("%d", A + i);

		ll cnt = 0;
		for(register int i = 0 ; i < M; i++){
			int b, l, r;
			scanf("%d %d %d\n", &b, &l, &r);
			l--,r--;
			map<int, int> mp;
			int cur = b;
			while(cur > 1) {
				mp[divv[cur]]++;
				cur = cur / divv[cur];
			}
			vector<pair<int,int> > divs;
			for(auto it : mp) divs.push_back({it.first, it.second});
			vector<int> dvs;
			if((int)divs.size()) dvs = go(0, 0, 1, divs, (int)divs.size());
			for(register int j = 0 ; j < (int)dvs.size(); j++){
				int ok = 0;
				for(register int k = l; k <= r; k++){
					if(A[k] % dvs[j] == 0) {
						ok = 1;
						break;
					}
				}
				if(!ok) cnt++;
			}
		}
		printf("%lld\n", cnt);
	}
	return 0;
}