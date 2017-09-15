#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

struct matrix{
	int mat[16][16];
	matrix(){
		memset(mat,0,sizeof(mat));
	}
	matrix(int h){
		memset(mat,0,sizeof(mat));
		if(h == 1){
			mat[0][0] = 1;
		}	
		else if(h == 2){
			mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = 1;
		}
		else{
			mat[0][0] = mat[0][1] = mat[h-1][h-2] = mat[h-1][h-1] = 1;
			for(int i = 1 ; i < h-1; i++){
				for(int j = i-1; j <= i+1; j++){
					mat[i][j] = 1;
				}
			}
		}
	}
	matrix operator*(const matrix& rhs) const{
		matrix ret;
		for(int i = 0 ; i < 16; i++) {
			for(int j = 0 ; j < 16; j++){
				for(int k = 0 ; k < 16; k++){
					ret.mat[i][j] = (ret.mat[i][j] + (ll)mat[i][k] * rhs.mat[k][j] ) % mod;
				}
			}
		}
		return ret;
	}
};
matrix I;
matrix matpow(matrix mat, ll k){
	if(!k) return I;
	if(k%2) return mat*matpow(mat, k-1);
	return matpow(mat*mat, k/2);
}
int n;
ll k;
int main() {
	cin >> n >> k;
	for(int i = 0 ; i < 16; i++) I.mat[i][i] = 1;
	matrix res = I;
	for(int i = 0 ; i < n ; i++){
		ll a,b;
		int c;
		cin >> a >> b >> c;
		if(b > k) b = k;
		matrix mat(c+1);
		res = matpow(mat, b-a) * res;
	}

	cout << res.mat[0][0];
	return 0;
}