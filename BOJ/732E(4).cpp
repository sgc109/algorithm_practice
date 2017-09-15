#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

struct node{
	int volt, id;
	bool operator<(const node& rhs) const{
		if(volt != rhs.volt) return volt < rhs.volt;
		return id < rhs.id;
	}
};
node socks[200003];
node coms[200003];
int N, M, a;
int C, U;
int A[200003], B[200003];
map<int, int> id;
vector<int> ids[200003];
int cnt;
int main() {
	scanf("%d%d",&N,&M);
	for(int i = 0 ; i < N; i++) {
		scanf("%d",&a);
		coms[i] = node{a, i + 1};
		if(!id[a]) id[a] = ++cnt;
		ids[id[a]].push_back(i + 1);
	}
	for(int i = 0 ; i < M; i++) {
		scanf("%d",&a);
		socks[i] = node{a, i + 1};
	}
	sort(coms, coms + N);
	sort(socks, socks + M);
	for(int i = 0 ; i < M; i++){
		for(int j = 0, x = socks[i].volt; ; j++, x = (x + 1) / 2){
			int d = id[x];
			if(d && sz(ids[d])) {
				int b = ids[d].back();
				C++;
				U += j;
				A[socks[i].id - 1] = j;
				B[b - 1] = socks[i].id;
				ids[d].pop_back();
				break;
			}
			if(x == 1) break;
		}
	}
	printf("%d %d\n", C, U);
	for(int i = 0 ; i < M; i++) printf("%d ", A[i]);
	printf("\n");
	for(int i = 0 ; i < N; i++) printf("%d ", B[i]);
	return 0;
}