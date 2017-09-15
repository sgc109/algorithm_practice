#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stack>
#include <string.h>
#include <stdlib.h>
#define REP(i,a,b) for(int i = a; i < b;++i) 
#define FOR(i,n) REP(i,0,n)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> llll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;
	
const int INF = 0x3a3a3a3a;
const int MAX_V = 1000000;

int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		int a,b,c,d,e,f,g,h;
		scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
		a+=e;
		b+=f;
		c+=g;
		d+=h;
		a = (a<1)?1:a;
		b = (b<1)?1:b;
		c = (c<0)?0:c;
		printf("%d\n",a+5*b+2*c+2*d);
	}		
	return 0;
}