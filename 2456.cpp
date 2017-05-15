#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

struct student{
	int id;
	int score[3];
	student(){
		memset(score,0,sizeof(score));
	}
	int sum()const{
		int ret = 0;
		for(int i = 0 ; i < 3; i++) ret += score[i]*(i+1);
		return ret;
	}
	bool operator<(const student &rhs) const{
		int sum1=sum();
		int sum2=rhs.sum();
		if(sum1 != sum2) return sum1 < sum2;
		for(int i = 2; i >= 0 ; i--) if(score[i] != rhs.score[i]) return score[i] < rhs.score[i];
		return 1;
	}
	bool operator==(const student &rhs) const{
		int ret = 1;
		for(int i = 0 ; i < 3; i++) if(score[i] != rhs.score[i]) ret = 0;
		return ret;
	}
};

student st[3];
int main() {
	for(int i = 0 ; i < 3; i++) st[i].id = i;
	int N;
	scanf("%d",&N);
	for(int i = 0 ; i < N; i++){
		int a;
		for(int j = 0 ; j < 3; j++) scanf("%d",&a), st[j].score[a-1]++;
	}
	sort(st, st+3);
	if(st[2] == st[1]) printf("0 %d",st[2].sum());
	else {
		printf("%d %d",st[2].id+1, st[2].sum());
	}
	return 0;
}
