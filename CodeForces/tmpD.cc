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
#include <map>
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

int n,k;
vi vp[100001];
vi vnp[100001];
int group[100001];
bool isPalin(string& S){
	FOR(i,(S.size()+1)/2) if(S[i]!=S[S.size()-i-1]) return false;
	return true;
}
int main() {
	memset(group,-1,sizeof(group));
	map<string,int> m;
	vector<pair<int,string>> vPalin,vNotPalin;
	inp2(n,k);
	FOR(i,n){
		string S;
		int score;
		cin >> S;
		inp1(score);
		if(isPalin(S)) vPalin.pb(mp(score,S));
		else vNotPalin.pb(mp(-score,S));
	}
	sort(vPalin.begin(),vPalin.end());
	sort(vNotPalin.begin(),vNotPalin.end());
	int cntPalin=0,cntNotPalin=0;
	int ans=0;
	FOR(i,vNotPalin.size()){
		string S = vNotPalin[i].second;
		if(m.find(S)==m.end()) m[S] = cntNotPalin++;
		int curNum = m[S];
		vnp[curNum].pb(-vNotPalin[i].first);
		string RS = S;
		reverse(RS.begin(),RS.end());
		if(m.find(RS)==m.end()) continue;
		else {
			int revNum = m[RS];
			if(group[curNum]==-1) group[revNum]=curNum,group[curNum]=revNum;
			int curSize = vnp[curNum].size();
			if(vnp[curNum].size() <= vnp[revNum].size() && vnp[curNum][curSize-1]+vnp[revNum][curSize-1]>0) ans+=vnp[curNum][curSize-1]+vnp[revNum][curSize-1];

		}		
	}
	FOR(i,vPalin.size()){
		string S = vPalin[i].second;
		if(m.find(S)==m.end()) m[S] = cntPalin++;
		int curNum = m[S];
		vp[curNum].pb(vPalin[i].first);
	}
	FOR(i,cntPalin){
		while(vp[i].size()>1 && vp[i][vp[i].size()-2]+vp[i][vp[i].size()-1]>0){
			ans+=vp[i][vp[i].size()-2]+vp[i][vp[i].size()-1];
			if(vp[i][vp[i].size()-2]>=0 && vp[i][vp[i].size()-1]>=0) {vp[i].pop_back();vp[i].pop_back();}
			else break;
		}
	}
	int midAns = ans;
	FOR(i,cntPalin){
		if(!vp[i].size()||vp[i].back()<=0) continue;
		if(vp[i].size()==1) ans=max(ans,midAns+vp[i][0]);
		else if(vp[i][vp[i].size()-2]+vp[i][vp[i].size()-1]>0) ans=max(ans,midAns-vp[i][vp[i].size()-2]);
		else ans=max(ans,midAns+vp[i].back());
	}
	printf("%d",ans);
	return 0;
}
