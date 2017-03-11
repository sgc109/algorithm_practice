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

class ToastXToast{
public:
	int bake(vector <int> undertoasted, vector <int> overtoasted){
		int N = sz(undertoasted);
		int M = sz(overtoasted);
		vii v;
		FOR(i,N) v.pb({undertoasted[i],0});
		FOR(i,M) v.pb({overtoasted[i],1});
		sort(all(v));
		int mode = 0;
		int ans=0;
		v.pb({10000000,0});
		FOR(i,sz(v)){
			if(mode==1){
				if(v[i].second==0) ans++,mode^=1;
			}
			else {
				if(v[i].second==1) mode^=1;
			}
		}
		if(mode==1) return -1;
		return ans;
	}
};
int main() {
	ToastXToast obj;
	cout << obj.bake(

{1,3,5},
{2,4,6}

		);
	return 0;
}
