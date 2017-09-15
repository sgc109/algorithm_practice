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

class TheJackpotDivOne{
public:
	vector<long long> find(vector<long long> money, long long jackpot){
		long long n = money.size();
		sort(all(money));
		while(money[0]!=money.back() && jackpot){
			long long avg = 0, modSum = 0;
			for(auto it : money) {
				avg += it/n;
				modSum += it%n;
			}
			avg += modSum/n;
			long long give = min(jackpot,avg-money[0]+1);
			money[0]+=give;
			sort(all(money));
			jackpot-=give;
		}
		for(auto& it : money) it+=jackpot/n;
		jackpot-=(jackpot/n*n);
		for(int i = n-1, j = jackpot; i >= 0 && j; i--,j--) money[i]++;
		return money;
	}
};
int main() {
	TheJackpotDivOne obj;
	vector<long long> ret = obj.find(

{3, 3, 3, 3},
4
		);
	for(auto it : ret) printf("%d ",it);
	return 0;
}
