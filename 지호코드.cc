#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
   int inp[105][105] = { 0, };
   int ans[105][105] = { 0, };

   stack<pair<int, int>> s;

   int N; cin >> N;

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         cin >> inp[i][j];
         if (inp[i][j] == 1) s.push({ i,j });
      }
   }

   while (!s.empty()) {
         int here = s.top().first;
         int next = s.top().second;
         s.pop();
         if(ans[here][next]) continue;
         ans[here][next] = 1;

         if (here == next) continue;

         for (int i = 0; i < N; i++) {
            if (inp[next][i] == 1) {
               s.push({ here, i });
            }
         }

      }

   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
         cout << ans[i][j] << ' ';
      }
      cout << endl;
   }
}