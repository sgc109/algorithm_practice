#include <bits/stdc++.h>
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define fastio() ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
typedef complex<double> base;
const ll INFL = 0x3c3c3c3c3c3c3c3c;
const double PI = 2.0 * acos(0.0);

void fft(vector <base> &a, bool invert)
{
    int n = sz(a);
    for (int i=1,j=0;i<n;i++){
        int bit = n >> 1;
        for (;j>=bit;bit>>=1) j -= bit;
        j += bit;
        if (i < j) swap(a[i],a[j]);
    }
    for (int len=2;len<=n;len<<=1){
        double ang = 2*PI/len*(invert?-1:1);
        base wlen(cos(ang),sin(ang));
        for (int i=0;i<n;i+=len){
            base w(1);
            for (int j=0;j<len/2;j++){
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if (invert){
        for (int i=0;i<n;i++) a[i] /= n;
    }
}
 
vector<int> operator*(const vector<int> &a,const vector<int> &b)
{
	vector<int> res;
    vector <base> fa(all(a)), fb(all(b));
    int n = 1;
    while (n < max(sz(a),sz(b))) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa,false); fft(fb,false);
    for (int i=0;i<n;i++) fa[i] *= fb[i];
    fft(fa,true);
    res.resize(n);
    for (int i=0;i<n;i++) res[i] = int(fa[i].real()+(fa[i].real()>0?0.5:-0.5));
    return res;
}

int poww(int x){return x * x;}
int H, W, h, w;
int P[503][503], p[503][503];
ll dp[503][503];
vector<int> A, B, C, D;
int main() {
	fastio();
	cin >> H >> W;
	A.resize(2 * H * W);
	for(int i = 0 ; i < H; i++) {
		for(int j = 0 ; j < W; j++){
			cin >> P[i][j];
			A[i * W + j] = P[i][j];
		}
	}

	cin >> h >> w;
	B.resize(2 * H * W);
	for(int i = 0 ; i < h; i++){
		for(int j = 0 ; j < w; j++){
			cin >> p[i][j];
			B[i * W + j] = p[i][j];
		}
		for(int j = w; j < W; j++) B[i * W + j] = 0;
	}

	for(int i = h ; i < H; i++){
		for(int j = 0 ; j < W; j++){
			B[i * W + j] = 0;
		}
	}
	for(int i = H * W ; i < 2 * H * W; i++) B[i] = B[i - H * W];
	reverse(all(B));

	C = A * B;
	
	D = vector<int>(C.begin() + H * W - 1, C.begin() + H * W - 1 + (W + w - 1) * (H - h + 1));
	C.clear();
	int pos = 0;
	while(pos < sz(D)){
		for(int i = 0 ; i < W - w + 1; i++, pos++) C.emplace_back(D[pos]);
		for(int i = 0 ; i < w - 1; i++, pos++);
	}

	for(int i = 1 ; i <= H; i++){
		for(int j = 1 ; j <= W; j++){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + poww(P[i - 1][j - 1]);
		}
	}

	ll ans = INFL;
	int ansI = 0, ansJ = 0;
	pos = 0;
	for(int i = h; i <= H; i++){
		for(int j = w; j <= W; j++){
			ll val = -2 * C[pos] + dp[i][j] - dp[i - h][j] - dp[i][j - w] + dp[i - h][j - w];
			if(ans > val) {
				ans = val;
				ansI = i - h;
				ansJ = j - w;
			}
			pos++;
		}
	}

	ll add = 0;
	for(int i = 0 ; i < h; i++){
		for(int j = 0 ; j < w; j++){
			add += poww(p[i][j]);
		}
	}

	cout << ans + add << "\n";
	cout << ansI + 1 << " " << ansJ + 1 << "\n";

	return 0;
}