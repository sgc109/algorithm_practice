#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define FOR(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
using namespace std;

const int INF = 0x3a3a3a3a;
const int MAX_V = 50;

struct Polygon{
	int size;
	vector<int> x;
	vector<int> y;
	Polygon(vector<int> &x, vector<int> &y) : x(x), y(y){
		size = x.size();
	}
};

double incline(int x1, int y1, int x2, int y2) {
	if(x2 == x1) return INF;
	return (double)(y2 - y1)/(x2 - x1);
}

double distDotLine(int dotX, int dotY, int x1, int y1, int x2, int y2) {
	int a = (y2-y1);
	int b = (x2-x1);
	return (double)abs(a*dotX+b*dotY+y1*b-x1*a)/sqrt(a*a+b*b);
}

double distDotDot(int x1, int y1, int x2, int y2) {
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

double distLineLine(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	int c1 = y1*(x2-x1) - x1*(y2-y1);
	int c2 = y3*(x4-x3) - x3*(y4-y3);
	return (double)abs(c1-c2)/sqrt((y2-y1)*(y2-y1)+(x2-x1)*(x2-x1));
}

double distPolyPoly(Polygon *polyA, Polygon *polyB) {
	double ret = 0x3a3a3a3a;
	//점~점
	printf("점 ~ 점\n");
	FOR(i,polyA->size) {
		FOR(j,polyB->size) {
			printf("ret : %lf\n",ret);
			ret = min(ret, distDotDot(polyA->x[i],polyA->y[i], polyB->x[j], polyB->y[j]));
		}
	}
	
	//점~선
	printf("점 ~ 선\n");
	FOR(i,polyA->size) {
		FOR(j,polyB->size) {
			printf("ret : %lf\n",ret);
			ret = min(ret, distDotLine(polyA->x[i], polyA->y[i], polyB->x[j], polyB->y[j], polyB->x[(j+1)%polyB->size], polyB->y[(j+1)%polyB->size]));
		}
	}

	//선~점
	printf("선 ~ 점\n");
	FOR(i,polyA->size) {
		FOR(j,polyB->size) {
			printf("ret : %lf\n",ret);
			ret = min(ret, distDotLine(polyB->x[j], polyB->y[j], polyA->x[i], polyA->y[i], polyA->x[(i+1)%polyA->size], polyA->y[(i+1)%polyA->size]));
		}
	}

	//선~선
	printf("선 ~ 선\n");
	FOR(i,polyA->size) {
		FOR(j,polyB->size) {
			printf("ret : %lf\n",ret);
			int inclineA = incline(polyA->x[i], polyA->y[i], polyA->x[(i+1)%polyA->size], polyA->y[(i+1)%polyA->size]);
			int inclineB = incline(polyB->x[j], polyB->y[j], polyB->x[(j+1)%polyB->size], polyB->y[(j+1)%polyB->size]);
			if(inclineA == inclineB) ret = min(ret, distLineLine(polyA->x[i], polyA->y[i], polyA->x[(i+1)%polyA->size], polyA->y[(i+1)%polyA->size], polyB->x[j], polyB->y[j], polyB->x[(j+1)%polyB->size], polyB->y[(j+1)%polyB->size]));
		}
	}	

	return ret;
}

double adj[MAX_V][MAX_V];
int n,start,dest;
double dist[MAX_V];
priority_queue<pair<double, int> > pq;

void dijkstra() {
	dist[start] = 0;
	pq.push(mp(0,0));
	while(!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		if(cost > dist[here]) continue;

		FOR(there,n) {
			if(here == there) continue;
			if(dist[there] > cost + adj[here][there]) {
				dist[there] = cost + adj[here][there];
				pq.push(mp(-dist[there],there));
			}
		}
	}
}

int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		FOR(i,MAX_V) {
			dist[i] = INF;
			FOR(j,MAX_V) {
				if(i == j) adj[i][j] = 0;
				else adj[i][j] = INF;
			}
		}
		vector<Polygon *> polygons;
		scanf("%d%d%d",&n,&start,&dest);
		--start;--dest;
		FOR(i,n) {
			int m;
			scanf("%d",&m);
			vector<int> x(m);
			vector<int> y(m);
			FOR(j,m) {
				int a,b;
				scanf("%d%d",&a,&b);
				x[j] = a;
				y[j] = b;
			}
			polygons.pb(new Polygon(x,y));
		}
		FOR(i,n) {
			FOR(j,n) {
				if(i>=j) continue;
				adj[i][j] = adj[j][i] = distPolyPoly(polygons[i],polygons[j]);
				// printf("adj[%d][%d] : %lf\n",i,j,adj[i][j]);
			}
		}
		dijkstra();
		// FOR(i,n) {
		// 	printf("%lf ",dist[i]);
		// }
		// printf("\n");
		// printf("%lf\n",dist[dest]);
	}
	return 0;
}