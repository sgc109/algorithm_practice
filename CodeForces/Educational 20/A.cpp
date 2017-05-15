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

int A[103][103];
int n,k;
void YES(){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n; j++){
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	exit(0);
}
void NO(){
	printf("-1");
	exit(0);
}
int main() {
	memset(A,0,sizeof(A));
	inp2(n,k);
	if(n*n < k) NO(); 
	for(int i = 0; i < n ; i++){
		for(int j = i; j < n ; j++){
			if(k==0) YES();
			if(k==1 && i!=j){
				A[i+1][i+1] = 1;
				YES();
			}
			if(i==j) {
				A[i][j] = 1;
				k--;
			}
			else {
				A[i][j] = A[j][i] = 1;
				k-=2;
			}
		}
	}
	YES();
	return 0;
}
