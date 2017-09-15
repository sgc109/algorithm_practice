const int MAX_N = 100000;
int t[2 * MAX_N];

void init(){
	FOR(i,N) t[N+i]=distFrom[i].second;
	for(int i=N-1;i>=1;i--) t[i]=max(t[i<<1],t[i<<1|1]);
}
ll query(int l, int r) {
	ll ret = 0;
	for (l += N, r += N; l <= r; l >>= 1, r >>= 1) {
		if (l&1) ret = max(ret,t[l++]);
		if (!(r&1)) ret = max(ret,t[r--]);
	}
	return ret;
}
void update(int pos, ll val){
	for(t[pos+=N]=val;pos>1;pos>>=1){
		t[pos>>1]=t[pos]+t[pos^1];
	}
}