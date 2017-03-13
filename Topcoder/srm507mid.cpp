/*
우선 1x1x1 큐브들과 LxLxL 큐브들의 부피의 총합을 구해보면
Ns+Nb*L^3 인데 이것을 T 라고 해보자. 그럼 적어도 우리가 이 큐브들을 포장하는 하나의 큐브의 부피 V는 T보다 크거나 같다.
그렇다면 T보다 크거나 같은 모든 V에 대해 검사해보자. 그런데 여기서 따져줘야 할 것이 세가지가 있다.
첫번째로 큐브의 모서리의 길이를 x,y,z 라고할때 x<=y<=z 관계를 유지해줘야 셌던것을 또 안센다. 회전하면 결국 같은게 나오기때문이다.
(그렇기 때문에 x^3 <= 2e9 일 것이다)
두번째로 지금 보는 V의 부피가 T보다 크다 할지라도 Nb개의 큐브가 모두 들어갈 수 없는 상황이 있다. 이것을 분리 해주기 위해서
LxLxL 큐브가 들어갈 수 있는 개수를 세어 줘야하는데 이것은 (x/L)*(y/L)*(z/L) 이다. 이것이 Nb보다 크거나 같은지를 봐주면된다.
세번째로 x와 y가 정해지면 x*y*z가 T보다 크거나 같아야하기때문에 최소 z가 정해질텐데
이 최소z부터 모든 가능한 z값을 다 봐주지 않아도 된다는 것이다. 딱 이거 하나만 봐주면된다. 그렇기 때문에 시간복잡도는
K = Ns+Nb*L^3 라고 정의하면, O(K^(1/3)lgK)
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
class CubePacking{
public:
	int getMinimumVolume(int Ns, int Nb, int L){
		ll ans = INFL;
		ll ns=Ns, nb=Nb, l=L;
		ll minV = ns+nb*l*l*l;
		for(ll i = 1; i*i*i <= 2e9; i++){
			for(ll j = i; i*j <= minV; j++){
				if(i*j>minV) break;
				ll k = minV/(i*j)+(minV%(i*j)!=0);
				if(j>k) break;z
				if((i/l)*(j/l)*(k/l)>=nb) ans = min(ans,i*j*k);
			}
		}
		return (int)ans;		
	}
};
