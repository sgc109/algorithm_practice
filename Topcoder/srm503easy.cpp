/*
탄것과 덜익은것을 하나의 벡터에 담아서 X값으로 정렬했을때
맨왼쪽이 탄것이거나 맨오른쪽이 덜익은것이면 무조건 불가능하고
만약 아니라면, 한가지 사실을 파악해야한다. 양끝의 두개를 제외했을때
모든 탄 빵은 맨왼쪽에있던 덜익은 빵과 매치시킬수있고 
모든 덜익은 빵은 맨 오른쪽에 있던 탄 빵과 매치 시킬수가있으므로 답은 2보다 커질수가없다. 그런데 딱 한 경우에 답이 1이 된다.
바로 모든 덜익은빵이 모든 탄빵보다 왼쪽에 있을 때 이다.

쉽게 이해하기위해 나는 꺾쇠 괄호를 사용하여 그림을 그렸다. 수직선상에
덜익은빵은 <, 탄빵은 > 로 표현했고 맨왼쪽의 <는 위로 올리고 맨오른쪽의 >는 아래로 내려보자.
그리고 나서 이 두개를 제외한 나머지 빵들에 대해 모든 >는 위로올리고 모든 <는 아래로 내려보자. 그럼 빵이 매치되는 모습이 보일것이다.
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

class ToastXToast{
public:
	int bake(vector <int> undertoasted, vector <int> overtoasted){
		int N = sz(undertoasted);
		int M = sz(overtoasted);
		vii v;
		FOR(i,N) v.pb({undertoasted[i],0});
		FOR(i,M) v.pb({overtoasted[i],1});
		sort(all(undertoasted));
		sort(all(overtoasted));
		sort(all(v));
		if(v[0].second==1||v.back().second==0) return -1;
		if(undertoasted.back()<overtoasted[0]) return 1;
		return 2;
	}
};