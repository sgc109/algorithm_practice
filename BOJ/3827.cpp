#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(false),cin.tie(NULL)
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

int N, M, A, B, C, T;
struct Matrix{
	int size;
	vector<vector<int> > cell;
	Matrix(){}
	Matrix(int siz) : size(siz){
		cell = vector<vector<int> >(siz, vector<int>(siz, 0));
	}
	Matrix operator*(const Matrix& rhs) const{
		int n = rhs.size;
		Matrix ret(n);
		for(int i = 0 ; i < n; i++){
			for(int j = 0 ; j < n; j++){
				for(int k = 0 ; k < n; k++){
					ret.cell[i][j] += cell[i][k] * rhs.cell[k][j];
				}
				ret.cell[i][j] %= M;
			}
		}
		return ret;
	}
};
int S[53];
Matrix I;
Matrix matpow(Matrix mat, int pow){
	if(!pow) return I;
	if(pow & 1) return mat * matpow(mat, pow - 1);
	return matpow(mat * mat, pow / 2);
}
int main() {
	fastio();
	while(1){
		cin >> N >> M >> A >> B >> C >> T;
		if(!N && !M && !A && !B && !C && !T) break;
		for(int i = 0 ; i < N; i++) cin >> S[i];
		I = Matrix(N);
		for(int i = 0 ; i < N; i++) I.cell[i][i] = 1;
		Matrix mat(N);
		for(int i = 0 ; i < N; i++){
			if(0 <= i - 1) mat.cell[i][i - 1] = A;
			mat.cell[i][i] = B;
			if(i + 1 < N) mat.cell[i][i + 1] = C;
		}
		mat = matpow(mat, T);
		for(int i = 0 ; i < N; i++){
			int sum = 0;
			for(int j = 0 ; j < N; j++){
				sum += mat.cell[i][j] * S[j];
			}
			cout << sum % M << ' ';
		}
		cout << '\n';
	}
	return 0;
}