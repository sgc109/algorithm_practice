/*
https://community.topcoder.com/stat?c=problem_statement&pm=11315

단순한 그리디+구현+자료구조 문제이다.
map 에 색을 key 값으로 개수를 세어준뒤 두개이상이 있는 색이있으면 무조건
마주보는 두 면에 쓰고 버리는게 이득이다.
그리고 서로 다른 색들은 아무렇게나 붙여도 된다.
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

class CubeStickers{
public:
	map<string,int> mp;
	string isPossible(vector <string> sticker){
		for(auto s : sticker) mp[s]++;
		int goal=3;
		int diff=0;
		for(auto it=mp.begin();it!=mp.end();it++){
			int cnt = (*it).second;
			if(cnt==1) diff++;
			else goal--;
		}
		if(goal-diff/2 <= 0) return "YES";
		return "NO";
	}
};