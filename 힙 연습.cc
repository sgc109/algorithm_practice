#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <random>
#include <ctime>
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
typedef vector<piii> viii;
const double EPSILON = 1e-9;
const double PI = acos(0.0)*2;
const int MOD = 1000000007;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

vi heap;
void insert(int add){
	heap.pb(add);
	int cur=sz(heap)-1;
	while(cur>0){
		int p=(cur-1)>>1;
		if(heap[p]>=heap[cur]) break;
		swap(heap[p],heap[cur]);
		cur=p;
	}
}
bool empty(){return heap.size()==0;}
int top(){return heap[0];}
void pop(){
	heap[0]=heap.back();
	heap.pop_back();
	int cur=0;
	while(1){
		int l=cur*2+1,r=cur*2+2;
		if(r<sz(heap)){
			if(heap[cur]>=max(heap[l],heap[r])) break;
			if(heap[l]>heap[r]){
				swap(heap[l],heap[cur]);
				cur=l;
			}
			else {
				swap(heap[r],heap[cur]);
				cur=r;
			}
		}
		else if(l<sz(heap)){
			if(heap[cur]>=heap[l]) break;
			swap(heap[cur],heap[l]);
			cur=l;
		}
		else break;
	}
}
int n,a;
int main() {
	for(inp1(n);n--;){
		inp1(a);
		if(a) insert(-a);
		else {
			if(empty()){
				printf("0\n");
				continue;
			}
			printf("%d\n",top());
			pop();
		}
	}
	return 0;
}
