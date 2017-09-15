#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct query{
	int op;
	ll param[2];
};
query q[100003];
int N,M;
ll snow[100003];
ll backup[100003];
set<ll> st;
vector<ll> comp;
ll t[800003];
int size;
int calcIdx(ll v){
	return lower_bound(comp.begin(), comp.end(), v) - comp.begin();
}
void init(){
	for(int i = 0 ; i < N; i++) t[size+calcIdx(snow[i])]++;
	for(int i = size-1; i > 0; i--) t[i] = t[2*i] + t[2*i+1];
}
void update(int pos, int v){
	for(t[pos+=size] += v; pos > 1; pos/=2) t[pos/2] = t[pos] + t[pos^1];
}
int query(int l, int r){
	int ret = 0;
	for(l+=size, r+=size; l<=r; l/=2,r/=2){
		if(l&1) ret+=t[l++];
		if(~r&1) ret+=t[r--];
	}
	return ret;
}
int kth(ll k){
	int cur = 1;
	while(cur < size){
		if(t[2*cur] < k) k-=t[2*cur],cur=2*cur+1;
		else cur*=2;
	}
	return cur-size;
}
int main() {
	size = 270000;
	scanf("%d%d",&N,&M);
	for(int i = 0 ; i < N; i++) scanf("%lld",snow+i), st.insert(snow[i]), backup[i] = snow[i];
	for(int i = 0 ; i < M; i++) {
		scanf("%d",&q[i].op);
		if(q[i].op == 4) scanf("%lld", &q[i].param[0]);
		else {
			scanf("%lld%lld",&q[i].param[0],&q[i].param[1]);
			if(q[i].op == 1 || q[i].op == 2){
				q[i].param[0]--;
				if(q[i].op == 2) q[i].param[1] = -q[i].param[1];
				snow[q[i].param[0]] += q[i].param[1];
				st.insert(snow[q[i].param[0]]);
			}
		}
	}
	for(int i = 0 ; i < N; i++) snow[i] = backup[i];
	comp.assign(st.begin(),st.end());
	init();

	for(int i = 0 ; i < M; i++){
		int op = q[i].op;
		if(op == 1 || op == 2) {
			ll pos = q[i].param[0];
			update(calcIdx(snow[pos]), -1);
			snow[pos]+=q[i].param[1];
			update(calcIdx(snow[pos]), 1);
		}
		else if(op == 3){
			ll L = q[i].param[0], R = q[i].param[1];
			int l = calcIdx(L);
			int r = calcIdx(R+1)-1;
			printf("%d\n",query(l,r));
		}
		else if(op == 4){
			printf("%lld\n",comp[kth(N+1-q[i].param[0])]);
		}
	}
	return 0;
}
