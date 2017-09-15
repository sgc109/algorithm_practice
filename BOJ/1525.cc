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
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int dy[]={-1,0,0,1};
int dx[]={0,1,-1,0};
map<long long, int> mp;
queue<long long> q;
int arr[3][3];
int ans,u;
bool inRange(int i, int j){
	return 0 <= i && i < 3 && 0 <= j && j < 3;
}
int main() {
	long long start=0;
	for(int i = 0; i < 9; i++){
		scanf("%d",&u);
		start=start*10+u;
	}
	q.push(start);
	mp[start]=1;
	bool found=false;
	while(!q.empty()){
		long long cur = q.front();
		int zeroI=0,zeroJ=0;
		q.pop();
		bool imposs=false;
		long long u=cur;
		for(int i = 0; i < 9; i++,u/=10){
			if(u%10==0) zeroI=(8-i)/3,zeroJ=(8-i)%3;
			if(i && u%10 != 9-i) imposs=true;
		}
		if(!imposs) {
			found=true;
			ans=mp[cur]-1;
			break;
		}
		for(int i = 0; i < 4; i++){
			int newI=zeroI+dy[i],newJ=zeroJ+dx[i];
			if(!inRange(newI,newJ)) continue;
			long long next = cur;
			for(int i = 0; i < 9; i++,next/=10) arr[(8-i)/3][(8-i)%3] = next%10;
			swap(arr[zeroI][zeroJ],arr[newI][newJ]);
			next=0;
			for(int i = 0; i < 9; i++) next=next*10+arr[i/3][i%3];
			if(!mp[next]) {
				q.push(next);
				mp[next]=mp[cur]+1;
			}
		}
	}
	if(!found) ans=-1;
	printf("%d",ans);
	return 0;
}
