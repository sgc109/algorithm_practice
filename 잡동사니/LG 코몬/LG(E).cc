#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <cmath>
// #include <unordered_set>
// #include <map>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
// #define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 1002;

int n;
vector<pair<pii,int> > cond[4];
vector<pair<pii,int> > cond2;
vector<pii> dots1[4];
vector<pii> dots2;
int outOn(int x, int y){

}
int main() {
	int T;
	inp1(T);
	while(T--){
		inp1(n);
		FOR(i,4) dots1[i] = vector<pii>(n);
		FOR(i,4) cond[i]=vector<pair<pii,int> >(n);
		FOR(i,n){
			int x,y;
			inp2(x,y);
			dots1[0][i].first=x;
			dots1[0][i].second=y;
			dots1[2][i].first=-x;
			dots1[2][i].second=-y;

		}
		FOR(i,n-1){
			if(dots1[i].first == dots1[i+1].first){
				if(dots1[i].second < dots1[i+1].second){
					cond[0][i] = mp(mp(dots1[i].first,0),-1);
				}else {
					cond[0][i] = mp(mp(dots1[i].first,0),1);
				}
			}
			else if(dots1[i].second == dots1[i+1].second){
				if(dots1[i].first < dots1[i+1].first){
					cond[0][i] = mp(mp(0,dots1[i].second),1);
				}
				else {
					cond[0][i] = mp(mp(0,dots1[i].second),-1);
				}
			}
		}
		dots2 = vector<pii>(n);
		cond2[i]=vector<pair<pii,int> >(n);
		FOR(i,n){
			int x,y;
			inp2(x,y);
			dots2[i].first=x;
			dots2[i].second=y;
		}
		FOR(i,n-1){
			if(dots1[i].first == dots1[i+1].first){
				if(dots1[i].second < dots1[i+1].second){

				}else {

				}
			}
			else if(dots1[i].second == dots1[i+1].second){
				if(dots1[i].first < dots1[i+1].first){

				}
				else {

				}
			}
		}






	}
	return 0;
}