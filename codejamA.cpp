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
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;	
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,pair<int,int> > piii;
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int T,K;
char buf[10000];
int len;
string S;
int main() {
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(int t = 1; t <= T; t++){
		scanf("%s",buf);
		scanf("%d",&K);

		S = string(buf);
		len = S.size();
		int cnt = 0;
		for(int i = 0 ; i <= len - K; i++){
			if(S[i] == '+') continue;
			for(int j = i; j < i+K; j++){
				if(S[j] == '+') S[j] = '-';
				else if(S[j] == '-') S[j] = '+';
			}
			cnt++;
		}


		for(int i = 0; i < len; i++){
			if(S[i] == '-') cnt = -1;	
		}
		printf("Case #%d: ",t);
		if(cnt == -1) printf("IMPOSSIBLE\n");
		else printf("%d\n",cnt);
	}

	return 0;
}
