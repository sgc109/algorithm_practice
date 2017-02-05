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

const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 300002;

int n,k;
vector<pair<pair<int,int>, int > > v;
pii arr[MAX_N];
int main() {
	inp2(n,k);
	FOR(i,n){
		int a,b;
		inp2(a,b);
		arr[i]=mp(a,b);
		v.pb(mp(mp(a,0),i+1));
		v.pb(mp(mp(b,1),i+1));
	}
	sort(v.begin(),v.end());
	set<pair<pair<int, int>,int> > st;
	int ans=0;
	int ansI;
	bool start=false;
	auto it=st.begin();
	pair<pair<int, int>,int> memo;
	pair<pair<int, int>,int> gotoo;
	FOR(i,v.size()){
		// if(start) printf("kth:%d\n",(*it).first.first);
		int pos = v[i].first.first;
		int lr = v[i].first.second;
		int id = v[i].second;
		if(lr==0) {
			if(st.size()>=k) gotoo=*(--it);
			st.insert(v[i]);
			if(st.size()==k){
				it=--st.end();
				memo=(*it);
			}
			else if(st.size()>k){
				if(v[i]<memo) it=st.find(gotoo),memo=(*it);
				else it=st.find(memo);
			}
		}
		else if(lr==1){
			if(st.size()>=k){
				if(ans<pos-(*it).first.first+1){
					ans=pos-(*it).first.first+1;
					ansI=i;
				}
			}
			if(st.size()>k) gotoo=*(++it);
			st.erase(st.find(mp(mp(arr[id-1].first,0),id)));
			if(st.size()>=k){
				if(mp(mp(arr[id-1].first,0),id)<memo) it=st.find(gotoo), memo=(*it);
				else it=st.find(memo);
			}
		}
	}
	printf("%d\n",ans);
	if(!ans) {
		FOR(i,k) printf("%d ",i+1);
		return 0;
	}
	set<int> st2;
	FOR(i,ansI+1){
		int pos = v[i].first.first;
		int lr = v[i].first.second;
		int id = v[i].second;
		if(lr==0) st2.insert(id);
		else if(lr==1&&i!=ansI) st2.erase(st2.find(id));
	}
	vi ansV;
	int t=0;
	for(auto it=st2.begin();it!=st2.end()&&t<k;it++,t++) ansV.pb((*it));
		sort(ansV.begin(),ansV.end());
	FOR(i,ansV.size()) printf("%d ",ansV[i]);
	return 0;
}
