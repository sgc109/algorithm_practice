#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N,M;
int G[203][203];
vector<int> comp1;
vector<int> comp2;
int cnt1[120000], cnt2[8000000];
long long total;
int trans1(pair<int,int>& p){
	return p.first*201+p.second;
}
int trans2(pair<pair<int,int>,pair<int,int> > p){
	return trans1(p.first)*201*201+trans1(p.second);
}
void compMake(int a, int b, int c){
	pair<int,int> p[3];
	p[0] = {a,b};
	p[1] = {a,c};
	p[2] = {b,c};
	comp1.push_back(trans1(p[0]));
	comp1.push_back(trans1(p[1]));
	comp1.push_back(trans1(p[2]));
	comp2.push_back(trans2({p[0],p[1]}));
	comp2.push_back(trans2({p[0],p[2]}));
	comp2.push_back(trans2({p[1],p[2]}));
}
int find(int v, int num){
	if(num==1) return lower_bound(comp1.begin(),comp1.end(),v) - comp1.begin();
	return lower_bound(comp2.begin(),comp2.end(),v) - comp2.begin();
}
void add(int a, int b, int c){
	pair<int,int> p[3];
	p[0] = {a,b};
	p[1] = {a,c};
	p[2] = {b,c};
	cnt1[find(trans1(p[0]),1)]++;
	cnt1[find(trans1(p[1]),1)]++;
	cnt1[find(trans1(p[2]),1)]++;
	cnt2[find(trans2({p[0],p[1]}),2)]++;
	cnt2[find(trans2({p[0],p[2]}),2)]++;
	cnt2[find(trans2({p[1],p[2]}),2)]++;
}
long long calc(int a, int b, int c){
	pair<int,int> p[3];
	p[0] = {a,b};
	p[1] = {a,c};
	p[2] = {b,c};
	long long ret = 0;
	ret+=cnt1[find(trans1(p[0]),1)];
	ret+=cnt1[find(trans1(p[1]),1)];
	ret+=cnt1[find(trans1(p[2]),1)];
	ret-=cnt2[find(trans2({p[0],p[1]}),2)];
	ret-=cnt2[find(trans2({p[0],p[2]}),2)];
	ret-=cnt2[find(trans2({p[1],p[2]}),2)];
	return ret+1;
}

int main() {
	scanf("%d%d",&N,&M);
	for(int i = 0 ; i < M; i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a][b] = G[b][a] = 1;
	}

	for(int i = 1; i <= N; i++){
		for(int j = i+1; j <= N; j++){
			for(int k = j+1; k <= N; k++){
				if(!G[i][j] || !G[j][k] || !G[k][i]) continue;
				compMake(i,j,k);
			}
		}
	}
	sort(comp1.begin(),comp1.end());
	sort(comp2.begin(),comp2.end());
	comp1.erase(unique(comp1.begin(),comp1.end()),comp1.end());
	comp2.erase(unique(comp2.begin(),comp2.end()),comp2.end());

	for(int i = 1; i <= N; i++){
		for(int j = i+1; j <= N; j++){
			for(int k = j+1; k <= N; k++){
				if(!G[i][j] || !G[j][k] || !G[k][i]) continue;
				add(i,j,k);
				total++;
			}
		}
	}

	long long ans = 0;
	for(int i = 1; i <= N; i++){
		for(int j = i+1; j <= N; j++){
			for(int k = j+1; k <= N; k++){
				if(!G[i][j] || !G[j][k] || !G[k][i]) continue;
				ans += total - calc(i,j,k);
			}
		}
	}

	printf("%lld",ans/2);

	return 0;
}
