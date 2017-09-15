#include <cstdio>
using namespace std;

void update(int nl, int nr, int l, int r, int n, ll v){
	if(d[n]) t[n]+=(nr-nl+1)*d[n],(nl!=nr?d[2*n]+=d[n],d[2*n+1]+=d[n]:0),d[n]=0;
	if(l<=nl&&nr<=r) {t[n]+=(nr-nl+1)*v,(nl!=nr?d[2*n]+=v,d[2*n+1]+=v:0); return;}
	if(r<nl||nr<l) return;
	update(nl,(nl+nr)/2,l,r,2*n,v),update((nl+nr)/2+1,nr,l,r,2*n+1,v),t[n]=t[2*n]+t[2*n+1];
}
ll query(int nl, int nr, int l, int r, int n){
	if(d[n]) t[n]+=(nr-nl+1)*d[n],(nl!=nr?d[2*n]+=d[n],d[2*n+1]+=d[n]:0),d[n]=0;
	if(l<=nl&&nr<=r) return t[n];
	if(r<nl||nr<l) return 0;
	return query(nl,(nl+nr)/2,l,r,2*n)+query((nl+nr)/2+1,nr,l,r,2*n+1);
}

int main(){
	
	return 0;
}