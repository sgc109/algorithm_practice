#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <map>
#include <set>

#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;	
typedef vector<ll> vl;

const ll INFL = 0x3c3c3c3c3c3c3c3c;
map<ll,ll> v[40][2];
ll score[2][40];
int N;

pair<ll, ll> merge(pair<ll, ll> A, pair<ll, ll> B){
	return make_pair(abs(A.first+B.first), (A.second<<(N/2))|(B.second));
}
int main() {
	inp1(N);
	FOR(i,2) FOR(j,N) scanf("%lld",&score[i][j]);
	FOR(j,N) score[1][j] *= -1;
	int l = N/2;
	int r = (N+1)/2;

	FOR(k,2){
		int lr = k?r:l;
		FOR(i,1<<lr) {
			ll diff = 0;
			int cntOn = 0;
			FOR(j,lr){
				int isOn = i&(1<<(lr-j-1))?1:0;
				diff += score[isOn][j+(k?l:0)];
				if(isOn) cntOn++;
			}
			if(v[cntOn][k].find(diff) != v[cntOn][k].end()) continue;
			v[cntOn][k][diff] = i;
		}	
	}

	pair<ll,ll> ans = {INFL,INFL};
	REP(i,0,N/2){
		for(auto it = v[i][0].begin(); it != v[i][0].end(); it++){
			auto target = -(*it).first;

			if(sz(v[N/2-i][1])==0) continue;

			auto it2 = v[N/2-i][1].lower_bound(target);
			if(it2 != v[N/2-i][1].end()) {
				ans = min(ans, merge({(*it).first, (*it).second}, {(*it2).first, (*it2).second}));
			}
			if(it2 != (v[N/2-i][1]).begin()){
				--it2;
				ans = min(ans, merge({(*it).first, (*it).second}, {(*it2).first, (*it2).second}));
			}
		}
	}

	auto bit = ans.second;
	FOR(i,N) printf("%c ","12"[bit&(1ll<<N-1-i)?1:0]);
	return 0;
}
