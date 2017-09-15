#include <iostream>
using namespace std;
#define MAX 35000000
// #define MAX 50
const long long mod = 1000000007LL;
int a[MAX+1];
long long calc(long long a, long long b, long long c) {
    long long ans = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            ans = (ans * a) % c;
        }
        a = (a*a) % c;
        b = b/2;
    }
    return ans;
}
int main(){
    long long n;
    cin >> n;
    a[1] = 1;
    a[2] = a[3] = 2;
    int now = 4;
    for (int i=3;; i++){
        for (int j=0; j<a[i]; j++) {
            a[now++] = i;
            if (now >= MAX) {
                break;
            }
        }
        if (now >= MAX) {
            break;
        }
    }
    if (n < MAX) {
        long long ans = 1;
        for (int i=2; i<=n; i++) {
            ans = (ans * a[i]) % mod;
        }
        cout << ans << '\n';
    } else {
        long long ans = 1;
        long long sum = 0;
        long long mul = 1;
        while (true) {
            if (sum == n) break;
            if (sum + a[ans] > n) {
                mul *= calc(ans, n-sum, mod);
                mul %= mod;
            } else {
                mul *= calc(ans, a[ans], mod);
                mul %= mod;
            }
            sum += a[ans];
            if (sum > n) {
                break;
            }
            ans++;
        }
        cout << mul << '\n';
    }
    return 0;
}