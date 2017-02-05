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

int n,k;
set<int> poses[MAX_N];
int arr[MAX_N];
int occu[MAX_N];
int usingCnt;
int del(){
	int lastNum;
	int lastPos=-1;
	FOR(i,n) {
		if(!occu[i]) continue;
		if(poses[i].empty()) return i;
		if(*(poses[i].begin())>lastPos){
			lastPos = *(poses[i].begin());
			lastNum=i;
		}
	}
	return lastNum;
}
int main() {
	int ans=0;
	inp2(k,n);
	FOR(i,n){
		inp1(arr[i]);
		arr[i]--;
		poses[arr[i]].insert(i);
	}
	FOR(i,n){
		if(occu[arr[i]]) {
			poses[arr[i]].erase(poses[arr[i]].begin());
			continue;
		}
		if(usingCnt<k) {
			usingCnt++;
		}
		else {
			ans++;
			int num = del();
			occu[num]=0;
		}
		occu[arr[i]]=1;
		poses[arr[i]].erase(poses[arr[i]].begin());
	}
	printf("%d",ans);
	return 0;
}
