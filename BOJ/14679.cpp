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

int N;
ll A, D, H;
int MA, MD, MH;
int Ap, Aa, Dp, Da, Hp, Ha;
int powA[103], powD[7], powH[1003];
int poww(int x, int y, int m){
	if(!y) return 1;
	if(y & 1) return x * poww(x, y - 1, m) % m;
	return poww(x * x % m, y / 2, m) % m;
}
int modd(int x, int m){
	while(x >= m) x -= m;
	return x;
}
int main() {
	fastio();
	cin >> N;
	cin >> A >> D >> H;
	cin >> MA >> MD >> MH;	
	cin >> Ap >> Aa >> Dp >> Da >> Hp >> Ha;
	for(int i = 1; i <= 100; i++) powA[i] = poww(i, Ap, 100);
	for(int i = 1; i <= 3; i++) powD[i] = poww(i, Dp, 3);
	for(int i = 1; i <= 1000; i++) powH[i] = poww(i, Hp, 1000);
	for(int i = 0 ; i < N; i++){
		ll Atck = max(A - MD, 1ll);
		ll MAtck = max(MA - D, 1ll);
		ll need = (MH + Atck - 1) / Atck;
		ll Mneed = (H + MAtck - 1) / MAtck;
		if(need > Mneed) return !printf("-1");
		A += MA, D += MD, H += MH;
		MA = modd(powA[MA] + Aa, 100) + 1;
		MD = modd(powD[MD] + Da, 3) + 1;
		MH = modd(powH[MH] + Ha, 1000) + 1;
	}
	cout << A % mod << ' ' << D % mod << ' ' << H % mod;
	return 0;
}