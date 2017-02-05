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

struct Circle{
public:
	int x,y,r;
	Circle(int x,int y,int r):x(x),y(y),r(r){}
	bool operator<(const Circle& other){
		return r>other.r;
	}
};

vector<Circle> circles;
int sqr(int x){return x*x;}
bool enclose(int a, int b){
	auto A = circles[a];
	auto B = circles[b];
	int dist = sqr(A.x-B.x)+sqr(A.y-B.y);
	if(A.r >= B.r && dist <= sqr(A.r-B.r)) return true;
	return false;
}
struct Node{
public:
	int id;
	vector<Node *> childs;
	Node(int id):id(id){}
	void add(int target){
		FOR(i,childs.size()){
			if(enclose(childs[i]->id,target)) {
				childs[i]->add(target);
				return;
			}
		}
		childs.pb(new Node(target));
	}
};

int maxDist;
int longestDist(Node *cur){
	vi ans;
	FOR(i,cur->childs.size()){
		ans.pb(1+longestDist(cur->childs[i]));
	}
	sort(ans.begin(),ans.end());
	if(ans.size()==0) maxDist=max(maxDist,0);
	else if(ans.size()==1) maxDist=max(maxDist,ans[ans.size()-1]);
	else maxDist=max(maxDist,ans[ans.size()-2]+ans[ans.size()-1]);
	return ans.size()==0?0:ans[ans.size()-1];
}
int main() {
	int T;
	inp1(T);
	while(T--){
		maxDist=0;
		circles.clear();
		int n;
		inp1(n);
		FOR(i,n){
			int x,y,r;
			inp3(x,y,r);
			circles.pb(Circle(x,y,r));
		}
		sort(circles.begin(),circles.end());
		Node *root = new Node(0);
		FOR(i,n-1) root->add(i+1);
		
		longestDist(root);
		printf("%d\n",maxDist);
		delete root;
	}
	return 0;
}