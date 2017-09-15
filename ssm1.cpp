#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int inf = 0x3c3c3c3c;
const long long infl = 0x3c3c3c3c3c3c3c3c;

class Rumor {
public:
	int N;
	int got[17][2];
	int gave[17][2];
	int tgot[17][2];
	int tgave[17][2];
	int getMinimum(string knowledge, vector<string> graph) {
		N = (int)knowledge.size();
		int ans = inf;
		for (int mask = 0; mask < (1 << N); mask++) {
			memset(got, 0, sizeof(got));
			memset(gave, 0, sizeof(gave));
			for (int i = 0; i < N; i++) if (knowledge[i] == 'Y') got[i][0] = got[i][1] = 1;
			int i;
			for (i = 0; i < N + 2; i++) {
				int ok = 1;
				for (int j = 0; j < N; j++) if (!got[j][0] || !got[j][1]) ok = 0;
				if (ok) break;
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < 2; k++) {
						tgave[j][k] = gave[j][k];
						tgot[j][k] = got[j][k];
					}
				}

				for (int j = 0; j < N; j++) {
					int o = (mask & (1 << j)) != 0;
					int cur = 0;
					if (gave[j][o]) cur = !o;
					else cur = o;
					if (!got[j][cur] || gave[j][cur]) continue;
					for (int k = 0; k < N; k++) {
						if (graph[j][k] == 'N') continue;
						tgot[k][cur] = 1;
					}
					tgave[j][cur] = 1;
				}

				for (int j = 0; j < N; j++) {
					for (int k = 0; k < 2; k++) {
						gave[j][k] = tgave[j][k];
						got[j][k] = tgot[j][k];
					}
				}
			}
			int ok = 1;
			for (int j = 0; j < N; j++) if (!got[j][0] || !got[j][1]) ok = 0;
			if (!ok) continue;
			ans = min(ans, i);
		}
		if (ans == inf) ans = -1;
		return ans;
	}
};

int main() {
	Rumor obj;
	cout << obj.getMinimum(
		"NNNNNNNYYY",
	{"NYNNYNNYNN"
		, "NNYNYNNNNY"
		, "YYNNNYNNNN"
		, "YNNNYNYNNN"
		, "NNYNNYNNYN"
		, "NNNNYNNNYY"
		, "NYNYNYNNNN"
		, "NNNNNNYNYY"
		, "NNNYNNNYNY"
		, "NYYNNNNYNN"}
	
	);
	return 0;
}