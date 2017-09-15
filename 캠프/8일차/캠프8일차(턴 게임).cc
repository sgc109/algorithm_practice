#include <cstdio>
using namespace std;
typedef long long ll;
int ans;
int main() {
	ll x,y,n;
	scanf("%lld%lld",&x,&y);
	for(n=0;;n++) if(n*(n+1)/2>=x+y) break;
	if(n*(n+1)/2!=x+y) return printf("-1"),0;
	for(ll i=n;i>=0&&x;i--) if(x>=i) x-=i,ans++;
	return printf("%d",ans),0;
}
