/*
https://community.topcoder.com/stat?c=problem_statement&pm=11063

우선 Linearity of expectation 을 알아야 한다.
그니까 건설한 도로들의 길이의 총 합의 기대값은
각각의 도로의 길이의 기대값들의 총 합과 같다라는 것이다.
Editorial 에 있는 식을 인용하자면

Expected Length of all roads build after picking all villages =
Expected Length (Sum of lengths of the roads built when village i is picked, for all i) =
Sum of the expected lengths of road built when village i is picked, for all i
이다.

그리고 추가적으로 새로 두가지 사실을 깨달았다.

첫번째는
배열이 있고 그 배열을 특정한 조건대로 나열되는 확률 구할 때
그 조건을 만족시키는데에 필요한 배열의 원소들 이외의 원소들은 식에 계산하지 않아도 된다.
(경우의 수 팩토리얼로 셀때 아예 안 넣으면 됨 그냥 없다고 생각하면 이해쉬움. 있으나 마나 어차피 조건만족엔 무관하므로)

두번째는
특정 값이 같은게 여러개 있고 그 것들이 동일한 확률로 선택된다고 할 때
굳이 따로 모두 나눠서 계산할 것없이 매우 작은 수 만큼 증가를 시켰다고 간주해서 다 다르다고 생각하고
실제로 다 다를 때 계산하는 방식대로 식만들어서 계산해도 된다. 그럼 훨씬 간단해짐.
(단, 매우 작은 수 만큼 증가 시켜도 답이 달라지지 않아야 한다.
(다 더해봤자 최종 답도 매우작은수만큼 차이가나므로 달라지지않는다고 보는것이다))
*/

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

class KingdomXCitiesandVillages{
public:
	double myPow(int x){return (double)x*x;}
	double myDist(int x1, int y1, int x2, int y2){return sqrt(myPow(x1-x2)+myPow(y1-y2));}
	int N,M;
	double determineLength(vector <int> cityX, vector <int> cityY, vector <int> villageX, vector <int> villageY){
		N = cityX.size();
		M = villageX.size();

		double ans=0;

		FOR(i,M){
			vector<pair<double,int> > v;
			FOR(j,M){
				if(i==j) continue;
				v.pb({myDist(villageX[i],villageY[i],villageX[j],villageY[j]),0});
			}
			FOR(j,N) v.pb({myDist(villageX[i],villageY[i],cityX[j],cityY[j]),1});
			sort(all(v));
			double exp=0;
			FOR(j,sz(v)){
				if(v[j].second==1){
					exp+=v[j].first/(j+1);
					break;
				}
				else exp+=v[j].first/((j+1)*(j+2));
			}
			ans+=exp;
		}
		return ans;
	}
};

int main() {
	KingdomXCitiesandVillages obj;
	cout << obj.determineLength(
{1,2,3},
{4,4,4},
{4,5,6},
{4,4,4}

		);
	return 0;
}
