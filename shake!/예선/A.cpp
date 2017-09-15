#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int T,N;
struct student{
	int id;
	int a,b,c;
	bool operator<(const student& rhs)const {
		if(a != rhs.a) return a > rhs.a;
		if(b != rhs.b) return b < rhs.b;
		return c < rhs.c;
	}
};

student students[10003];
int main() {
	freopen("output.txt","w",stdout);
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> N;
		for(int i = 0 ; i< N; i++){
			int a,b,c;
			cin >> a >> b >> c;
			students[i] = student{i,a,b,c};
		}
		sort(students, students+N);
		printf("Case #%d\n%d\n",t,students[0].id+1);
	}
	return 0;
}
