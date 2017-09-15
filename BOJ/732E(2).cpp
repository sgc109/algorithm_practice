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

struct sock{
	int volt, used, id;
	bool operator<(const sock& rhs) const{
		if(volt != rhs.volt) return volt < rhs.volt;
		if(used != rhs.used) return used > rhs.used;
		return id < rhs.id;
	}
};
struct com{
	int volt, id;
	bool operator<(const com& rhs) const{
		if(volt != rhs.volt) return volt > rhs.volt;
		return id < rhs.id;
	}
};
com coms[200003];
priority_queue<sock> pqS;
int N, M, a;
int C, U;
int A[200003], B[200003];
int main() {
	fastio();
	cin >> N >> M;
	for(int i = 0 ; i < N; i++) {
		cin >> a;
		coms[i] = com{a, i};
	}
	for(int i = 0 ; i < M; i++) {
		cin >> a;
		pqS.push(sock{a, 0, i});
	}

	sort(coms, coms + N);
	int posC = 0;
	while(posC < N && !pqS.empty()){
		auto endC = coms[posC];
		auto endS = pqS.top();
		if(endS.volt < endC.volt) posC++;
		else if(endS.volt == endC.volt){
			C++;
			U += endS.used;
			A[endS.id] = endS.used;
			B[endC.id] = endS.id + 1;
			posC++;
			pqS.pop();
		}
		else {
			pqS.pop();
			pqS.push(sock{(endS.volt + 1) / 2, endS.used + 1, endS.id});
		}
	}

	cout << C << " " << U << "\n";
	for(int i = 0 ; i < M; i++) cout << A[i] << " ";
	cout << "\n";
	for(int i = 0 ; i < N; i++) cout << B[i] << " ";
	return 0;
}