#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

bool isYoon(int year){
	return year % 400 == 0 || (year % 4 == 0 && year % 100);
}
int main() {
	int y;
	cin >> y;
	cout << isYoon(y);
	return 0;
}