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
typedef vector<ll> vl;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 2502;

class FlippingBitsDiv2{
public:
	int dp1[MAX_N][2];
	int dp2[MAX_N][2];
	string str;
	int getmin(vector<string> vs, int M){
		FOR(i,vs.size()){
			str+=vs[i];
		}
		dp1[0][0] = str[0]!='0';
		dp1[0][1] = str[0]!='1';
		REP(i,1,str.size()){
			if(str[i]=='0'){
				dp1[i][0] = dp1[i-1][0];
				if(i%M==0) dp1[i][0] = min(dp1[i][0],dp1[i-1][1]+1);
				dp1[i][1] = dp1[i-1][1]+1;
				if(i%M==0) dp1[i][1] = min(dp1[i][1],dp1[i-1][0]+2);
			}
			else if(str[i]=='1'){
				dp1[i][0] = dp1[i-1][0]+1;
				if(i%M==0) dp1[i][0] = min(dp1[i][0],dp1[i-1][1]+2);
				dp1[i][1] = dp1[i-1][1];
				if(i%M==0) dp1[i][1] = min(dp1[i][1],dp1[i-1][0]+1);
			}
		}
		dp1[str.size()-1][1] = min(dp1[str.size()-1][1],dp1[str.size()-1][0]+1);
		reverse(str.begin(),str.end());
		dp2[0][0] = str[0]!='0';
		dp2[0][1] = str[0]!='1';
		REP(i,1,str.size()){
			if(str[i]=='0'){
				dp2[i][0] = dp2[i-1][0];
				if(i%M==0) dp2[i][0] = min(dp2[i][0],dp2[i-1][1]+1);
				dp2[i][1] = dp2[i-1][1]+1;
				if(i%M==0) dp2[i][1] = min(dp2[i][1],dp2[i-1][0]+2);
			}
			else if(str[i]=='1'){
				dp2[i][0] = dp2[i-1][0]+1;
				if(i%M==0) dp2[i][0] = min(dp2[i][0],dp2[i-1][1]+2);
				dp2[i][1] = dp2[i-1][1];
				if(i%M==0) dp2[i][1] = min(dp2[i][1],dp2[i-1][0]+1);
			}
		}
		dp2[str.size()-1][1] = min(dp2[str.size()-1][1],dp2[str.size()-1][0]+1);
		int ans = min(dp1[str.size()-1][1],dp2[str.size()-1][1]);
		FOR(i,str.size()-1){
			ans = min(ans, dp1[i][1]+dp2[str.size()-2-i][1]);	
		}
		return ans;
	}
};

int main() {
	FlippingBitsDiv2 obj;
	printf("%d",obj.getmin({"00100"},5));
	return 0;
}