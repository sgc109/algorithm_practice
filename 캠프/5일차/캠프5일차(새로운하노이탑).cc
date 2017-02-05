#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,n) for(int i=0;i<n;++i)
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
typedef vector<pair<int,int> > vii;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef queue<int> QU;

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

map<string,int> mp;
int main() {
	string S;
	FOR(i,3) {
		int a;
		string s;
		inp1(a);
		if(a) {
			cin >> s;
			S+=s;
		}
		if(i!=2) S+="/";
	}
	
	queue<string> q;
	q.push(S);
	mp[S]=0;
	int cnt=1;
	while(!q.empty()){
		string here=q.front();
		q.pop();
		int hereDist=mp[here];
		int pos1=-1,pos2=-1;
		FOR(i,here.size()){
			if(here[i]=='/'){
				if(pos1==-1) pos1=i;
				else pos2=i;
			}
		}
		string SS[3];
		SS[0]=here.substr(0,pos1);
		SS[1]=here.substr(pos1+1,pos2-pos1-1);
		SS[2]=here.substr(pos2+1,here.size()-pos2-1);
		bool found=true;
		FOR(i,SS[0].size()) if(SS[0][i]!='A') found=false;
		FOR(i,SS[1].size()) if(SS[1][i]!='B') found=false;
		FOR(i,SS[2].size()) if(SS[2][i]!='C') found=false;
		if(found){
			printf("%d",hereDist);
			return 0;
		}
		FOR(i,6){
			string NS[3];
			NS[0]=SS[0],NS[1]=SS[1],NS[2]=SS[2];
			int a=i%3,b=(i%3+1)%3;
			if(i/3) swap(a,b);
			if(NS[a].size()) NS[b]+=NS[a].back(),NS[a].pop_back();
			string newS = NS[0]+'/'+NS[1]+'/'+NS[2];
			if(mp.find(newS)==mp.end()) {
				mp[newS]=hereDist+1;
				q.push(newS);
				cnt++;
			}
		}
	}


	return 0;
}
