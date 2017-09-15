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

template <class TYPE> class Heap{
public:
	vector<TYPE> v;
	TYPE top(){
		if(v.size()) return v[0];
		return NULL;
	}
	void pop(){
		if(v.size()==0) return;
		v[0] = v.back();
		v.pop_back();
		int cur=0;
		while(1){
			int left = 2*cur+1; int right = 2*cur+2;
			if(v.size()-1 < left) break;
			int next = left;
			if(v.size()+1 > left && v[left] < v[right]) next = right;
			if(!(v[cur] < v[next])) break;
			swap(v[cur],v[next]);
			cur = next;
		}
	}
	void insert(TYPE x){
		v.pb(x);
		int cur = v.size()-1;
		while(cur!=0 && v[(cur-1)>>1] < v[cur]) {
			swap(v[(cur-1)>>1],v[cur]);
			cur=(cur-1)>>1;
		}
	}
};
int main() {	
	return 0;
}