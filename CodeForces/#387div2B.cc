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
#define all(v) (v).begin(),(v).end()
#define inp1(a) scanf("%d",&a)
#define inp2(a,b) scanf("%d%d",&a,&b)
#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)

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
const int MAX_N = 102;

int main() {
	int n;
	inp1(n);
	string S;
	cin >> S;
	int cnt[4]={0,};
	int cntQ = 0;
	FOR(i,S.size()){
		if(S[i]=='A') cnt[0]++;
		else if(S[i]=='C') cnt[1]++;
		else if(S[i]=='G') cnt[2]++;
		else if(S[i]=='T') cnt[3]++;
		else if(S[i]=='?') cntQ++;
	}
	int maxCnt=0;
	FOR(i,4){
		maxCnt = max(maxCnt,cnt[i]);
	}
	int cntLess=0;
	FOR(i,4){
		cntLess+=maxCnt-cnt[i];
	}
	if(cntLess > cntQ || (((cntQ-cntLess)%4) != 0)) {
		printf("===");
		return 0;
	}

	vector<char> ans;
	FOR(j,maxCnt-cnt[0]) ans.pb('A');
	FOR(j,maxCnt-cnt[1]) ans.pb('C');
	FOR(j,maxCnt-cnt[2]) ans.pb('G');
	FOR(j,maxCnt-cnt[3]) ans.pb('T');
	FOR(i,(cntQ-cntLess)/4) {
		ans.pb('A');
		ans.pb('C');
		ans.pb('G');
		ans.pb('T');
	}

	FOR(i,S.size()){
		if(S[i]!='?') printf("%c",S[i]);
		else {
			printf("%c",ans.back());
			ans.pop_back();
		}
	}





	return 0;
}