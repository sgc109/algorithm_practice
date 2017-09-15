#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N, K;
int L[10003];
int makable(int len){
	int ret = 0;
	for(int i = 0 ; i < N; i++){
		ret += (L[i] / len);
	}
	return ret;
}
int main() {
	scanf("%d %d", &N, &K);
	for(int i = 0 ; i < N; i++) {
		string s;
		cin >> s;
		int num = 0;
		for(int i = 0 ; i < sz(s); i++) {
			if(s[i] == '.') continue;
			num = num * 10 + s[i] - '0';
		}
		L[i] = num;
	}
	int lo = 1, hi = 1e7 + 1;
	while(lo < hi){
		int mid = (lo + hi) / 2;
		if(makable(mid) >= K) lo = mid + 1;
		else hi = mid;
	}

	double ans = (lo - 1) / 100.0;
	printf("%.2lf", ans);
	return 0;
}