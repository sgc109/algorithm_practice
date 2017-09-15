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
#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
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
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;
const int MAX_N = 102;

int N,M;
int height[100003];
double S[1003];
double paraS[1003];
double minX[1003];
double maxX[1003];
double calcX(int x1, int y1, int x2, int y2, int h){
	return x1 - (double)(y1 - h) * (x1 - x2) / (y1 - y2);
}
int main() {
	scanf("%d%d",&N,&M);
	for(int i = 0 ; i < N; i++)
		scanf("%d",height+i);
	
	for(int i = 0 ; i < 1003; i++)
		S[i] = 0.0, paraS[i] = 0.0;

	for(int h = 0 ; h <= 1000; h++){
		double acc = 0.0;
		double prev = 0.0;
		for(int j = 0; j < N-1; j++){
			double crossX = calcX(j, height[j], j+1, height[j+1], h);
			if(height[j] == height[j+1] && height[j] == h) paraS[h] += 1.0;
			if(height[j] <= h && h < height[j+1]){
				prev = crossX;
			}
			else if(h < height[j] && height[j+1] <= h){
				acc += crossX - prev;
			}
		}
		if(h <= height[N-1]) {
			acc += N - 1 - prev;
		}
		S[h] = acc;
	}


	while(M--){
		char op;
		int x, h;
		scanf(" %c",&op);
		if(op=='Q'){
			scanf("%d",&h);
			if(!h){
				printf("0.00000000\n");
				continue;
			}
			double ans = h*(N-1);
			double minus = 0;
			for(int i = h; i >= 1; i--){
				// printf("S[i] : %lf, S[i-1] : %lf\n",S[i],S[i-1]);
					// printf("i:%d in!!!\n",i);
				minus += (S[i]+paraS[i]+S[i-1])/2;
			}
			// for(int i = 0; i < 4; i++){
			// 	printf("S[%d] : %lf ",i,S[i]);
			// }
			// printf("\n");
			printf("%.9lf\n",ans - minus);
		}
		else if(op=='U'){
			scanf("%d%d",&x,&h);
			int s = min({height[x], h, x==0?INF:height[x-1], x==N-1?INF:height[x+1]});
			int e = max({height[x], h, x==0?-1:height[x-1], x==N-1?-1:height[x+1]});
			for(int i = s; i <= e; i++){
				double l = x == 0 ? 0.0 : (height[x-1]==height[x]?x:max(calcX(x-1, height[x-1], x, height[x], i), calcX(x-1, height[x-1], x, h, i)));
				double r = x == N-1 ? N-1 : (height[x]==height[x+1]?x:min(calcX(x+1, height[x+1], x, height[x], i), calcX(x+1, height[x+1], x, h, i)));
				S[i] += height[x] <= h ? r - l : -(r - l);
			}
		}
	}
	return 0;
}
