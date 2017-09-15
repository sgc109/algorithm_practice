#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3c3c3c3c;
const long long INFL = 0x3c3c3c3c3c3c3c3c;

struct node{
	int volt, id;
	bool operator<(const node& rhs) const{
		if(volt != rhs.volt) return volt < rhs.volt;
		return id < rhs.id;
	}
};
node socks[200003];
node coms[200003];
int N, M, a;
int C, U;
int A[200003], B[200003];
int checkS[200003], checkC[200003];
int main() {
	fastio();
	cin >> N >> M;
	for(int i = 0 ; i < N; i++) {
		cin >> a;
		coms[i] = node{a, i};
	}
	for(int i = 0 ; i < M; i++) {
		cin >> a;
		socks[i] = node{a, i};
	}

	sort(coms, coms + N);
	sort(socks, socks + M);
	for(int i = 0 ; i < 40; i++){
		int posS = 0, posC = 0;
		while(posC < N && posS < M){
			auto c = coms[posC];
			auto s = socks[posS];
			if(checkC[posC] || s.volt > c.volt) posC++;
			else if(checkS[posS] || s.volt < c.volt) posS++;
			else{
				C++;
				U += i;
				A[s.id] = i;
				B[c.id] = s.id + 1;
				checkS[posS] = checkC[posC] = 1;
				posC++;
				posS++;
			}
		}
		for(int j = 0 ; j < M; j++) socks[j] = node{(socks[j].volt + 1) / 2, socks[j].id};
	}

	cout << C << " " << U << "\n";
	for(int i = 0 ; i < M; i++) cout << A[i] << " ";
	cout << "\n";
	for(int i = 0 ; i < N; i++) cout << B[i] << " ";
	return 0;
}