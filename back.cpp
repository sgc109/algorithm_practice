#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

int N;
int A[103];
int main() {
	cin >> N;
	for(int i = 0 ; i < N; i++) cin >> A[i];

	int found = -1;
	int l = INF, r = -1;
	for(int i = 1 ; i < N; i++){
		if(A[i] == A[i-1]) {
			if(found == -1){
				l = i-1;
				r = i;
				found = A[i];
			}
			else {
				if(found != A[i] || r != i-1) return !printf("NO");
				r = i;
			}
		}
	}

	if(found == -1) return !printf("NO");

	int prev = found;
	for(int i = l-1; i >=0; i--){
		if(prev <= A[i]) return !printf("NO");
		prev = A[i];
	}

	prev = found;
	for(int i = r+1; i < N; i++){
		if(prev <= A[i]) return !printf("NO");
		prev = A[i];
	}

	printf("YES");

	return 0;
}