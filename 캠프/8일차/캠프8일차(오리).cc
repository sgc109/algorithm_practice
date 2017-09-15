#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int,int> > vii;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int cnt[5];
string S;
void NO() {
	printf("-1");
	exit(0);
}
int main() {
	cin >> S;
	int ans=0;
	FOR(i,sz(S)){
		if(S[i]=='q') cnt[0]++;
		if(S[i]=='u') cnt[1]++,cnt[0]--;
		if(S[i]=='a') cnt[2]++,cnt[1]--;
		if(S[i]=='c') cnt[3]++,cnt[2]--;
		if(S[i]=='k') cnt[3]--;
		ans=max(ans,cnt[0]+cnt[1]+cnt[2]+cnt[3]);
		if(cnt[0]<0||cnt[1]<0||cnt[2]<0||cnt[3]<0||cnt[4]<0) NO();
		ans=max(ans,cnt[S[i]-'a']);
	}
	cout << ans;
	return 0;
}
