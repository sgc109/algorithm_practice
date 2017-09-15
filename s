diff --git a/#319Div2B.cc b/#319Div2B.cc
new file mode 100644
index 0000000..dcf2781
--- /dev/null
+++ b/#319Div2B.cc
@@ -0,0 +1,46 @@
+#include <bits/stdc++.h>
+// #include <iostream>
+// #include <unordered_set>
+// #include <unordered_map>
+// #include <vector>
+// #include <cstdio>
+// #include <cstring>
+// #include <queue>
+// #include <set>
+// #include <map>
+// #include <cmath>
+// #include <algorithm>
+// #include <utility>
+// #include <string>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;	
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+
+int main() {
+	
+	return 0;
+}
diff --git a/#400A.cc b/#400A.cc
new file mode 100644
index 0000000..9f841b7
--- /dev/null
+++ b/#400A.cc
@@ -0,0 +1,65 @@
+// #include <bits/stdc++.h>
+// #include <iostream>
+#include <unordered_set>
+#include <unordered_map>
+#include <vector>
+#include <cstdio>
+#include <cstring>
+#include <queue>
+#include <set>
+#include <map>
+#include <cmath>
+#include <algorithm>
+#include <utility>
+#include <string>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;	
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+map<ll, ll> um;
+int N,K;
+int A[100003];
+ll pSum[100003];
+unordered_set<ll> us;
+vector<ll> cand;
+int main() {
+	inp2(N,K);
+	FOR(i,N) inp1(A[i]), pSum[i+1]=pSum[i]+A[i];
+	long long pusher=1;
+	for(; abs(pusher) <= 1e16; pusher*=K) {
+		if(us.count(pusher)) break;
+		us.insert(pusher);
+		cand.pb(pusher);
+	}
+	ll ans=0;
+	um[0]=1;
+	REP(i,1,N){
+		for(auto kk : cand) ans+=um[pSum[i]-kk];
+		um[pSum[i]]++;
+	}
+	printf("%lld",ans);
+	return 0;
+}
diff --git a/10423.cc b/10423.cc
new file mode 100644
index 0000000..45d438c
--- /dev/null
+++ b/10423.cc
@@ -0,0 +1,46 @@
+#include <cstdio>
+#include <vector>
+#include <algorithm>
+using namespace std;
+
+struct Edge{
+	int u,v,c;
+	bool operator<(const Edge& rhs){
+		return c<rhs.c;
+	}
+};
+int parent[1003];
+int N,M,K;
+int a,b,c,d,core;
+int find(int u){
+	if(parent[u]==u) return u;
+	return parent[u]=find(parent[u]);
+}
+void merge(int a, int b){
+	a = find(a), b = find(b);
+	if(a==b) return;
+	parent[b]=a;
+}
+vector<Edge> edges;
+int main() {
+	for(int i = 0 ; i < 1000; i++) parent[i]=i;
+	core=1001;
+	scanf("%d%d%d",&N,&M,&K);
+	for(int i = 0 ; i < K; i++){
+		scanf("%d",&a);
+		merge(core,a);
+	}
+	for(int i = 0 ; i < M; i++){
+		scanf("%d%d%d",&a,&b,&c);
+		edges.push_back(Edge{a,b,c});
+	}
+	sort(edges.begin(),edges.end());
+	int ans=0;
+	for(auto e : edges){
+		if(find(e.u)==find(e.v)) continue;
+		ans+=e.c;
+		merge(e.u,e.v);
+	}
+	printf("%d",ans);
+	return 0;
+}
diff --git a/1069.cc b/1069.cc
new file mode 100644
index 0000000..91adf75
--- /dev/null
+++ b/1069.cc
@@ -0,0 +1,56 @@
+#include <bits/stdc++.h>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+
+int X,Y,D,T;
+double sqr(double x){return x*x;}
+double ans1,ans2,ans3;
+double dist(double x, double y){
+	return sqrt(sqr(x)+sqr(y));
+}
+int main() {
+	while(scanf("%d%d%d%d",&X,&Y,&D,&T)!=-1){
+		double d = dist(X,Y);
+		ans1 = d;
+		double in,out;
+		int n;
+		if(d<D){
+			ans2=D-d+T;
+			ans3=2*T;
+		}
+		else {
+			for(n=0, out=0.0; out<d; out+=D, n++){}
+			in = out-D;
+			ans2 = min(d-in+(n-1)*T,out-d+n*T);
+			ans3 = n*T;
+		}
+		printf("%.13lf\n",min({ans1,ans2,ans3}));
+	}
+
+	return 0;
+}
diff --git a/A.cc b/A.cc
new file mode 100644
index 0000000..663c790
--- /dev/null
+++ b/A.cc
@@ -0,0 +1,58 @@
+// #include <bits/stdc++.h>
+// #include <iostream>
+#include <unordered_set>
+#include <unordered_map>
+#include <vector>
+#include <cstdio>
+#include <cstring>
+#include <queue>
+#include <set>
+#include <map>
+#include <cmath>
+#include <algorithm>
+#include <utility>
+#include <string>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+
+int fell[100003];
+int pos,N,a;
+int main() {
+	inp1(N);
+	pos=N;
+	FOR(i,N){
+		inp1(a);
+		fell[a]=1;
+		while(fell[pos]) {
+			printf("%d ",pos);
+			pos--;
+		}
+		printf("\n");
+	}
+	return 0;
+}
diff --git a/APAC_A.cc b/APAC_A.cc
new file mode 100644
index 0000000..590173e
--- /dev/null
+++ b/APAC_A.cc
@@ -0,0 +1,74 @@
+// #include <bits/stdc++.h>
+// #include <iostream>
+#include <unordered_set>
+#include <unordered_map>
+#include <vector>
+#include <cstdio>
+#include <cstring>
+#include <queue>
+#include <set>
+#include <map>
+#include <cmath>
+#include <algorithm>
+#include <utility>
+#include <string>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+
+int T,N;
+int check[30];
+int ansCnt;
+string ansName;
+char buf[100];
+vector<string> vs;
+int main() {
+	freopen("output.txt","w",stdout);
+	scanf("%d ",&T);
+	REP(t,1,T){
+		vs.clear();
+		ansCnt=0;
+		scanf("%d ",&N);
+		FOR(i,N){
+			gets(buf);
+			vs.push_back(string(buf));
+		}
+		sort(all(vs));
+		for(auto str : vs){
+			int cnt=0;
+			memset(check,0,sizeof(check));
+			for(char c : str){
+				if(check[c-'A']) continue;
+				check[c-'A']=1,cnt++;
+			}
+			if(ansCnt<cnt) ansCnt=cnt,ansName=str;
+		}
+		printf("Case #%d: ",t);
+		printf("%s\n",ansName.c_str());
+	}
+	return 0;
+}
diff --git a/APAC_B.cc b/APAC_B.cc
new file mode 100644
index 0000000..0d7bf78
--- /dev/null
+++ b/APAC_B.cc
@@ -0,0 +1,60 @@
+// #include <bits/stdc++.h>
+// #include <iostream>
+#include <unordered_set>
+#include <unordered_map>
+#include <vector>
+#include <cstdio>
+#include <cstring>
+#include <queue>
+#include <set>
+#include <map>
+#include <cmath>
+#include <algorithm>
+#include <utility>
+#include <string>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+
+double dp[2001][2001];
+int N,M,T;
+int main() {
+	freopen("output.txt","w",stdout);
+	inp1(T);
+	REP(t,1,T){
+		FOR(i,2001) FOR(j,2001) dp[i][j]=0;
+		dp[0][0]=1;
+		inp2(N,M);
+		REP(i,1,N){
+			FOR(j,i){
+				dp[i][j]=dp[i-1][j]*(1.0/(M-j+N-i+1))*(N-i+1)+(j>0?dp[i][j-1]:0)*(1.0/(M-j+N-i+1))*(M-j+1);
+			}
+		}
+		printf("Case #%d: %.8lf\n",t,dp[N][M]);
+	}
+	return 0;
+}
diff --git a/APAC_C.cc b/APAC_C.cc
new file mode 100644
index 0000000..b62b321
--- /dev/null
+++ b/APAC_C.cc
@@ -0,0 +1,69 @@
+// #include <bits/stdc++.h>
+// #include <iostream>
+#include <unordered_set>
+#include <unordered_map>
+#include <vector>
+#include <cstdio>
+#include <cstring>
+#include <queue>
+#include <set>
+#include <map>
+#include <cmath>
+#include <algorithm>
+#include <utility>
+#include <string>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+
+ll dp[100003];
+ll ans[100003];
+ll sqr(ll x){return x*x;}
+ll go(int n){
+	if(n<0) return 0;
+	if(n==0) return 1;
+	if(n%2) return 0;
+	ll& cache = dp[n];
+	if(cache!=-1) return cache;
+	return cache = sqr(go((n-2)/2))+sqr(go(n/2))+2*go((n-2)/2)*go((n-2)/2-2)+(n>2?1:0);
+}
+int T,L,R;
+int main() {
+	freopen("output.txt","w",stdout);
+	memset(dp,-1,sizeof(dp));
+	for(int i = 2; i <= 100000; i+=2){
+		if(dp[i]==-1) dp[i]=go(i);
+		ans[i]+=ans[i-2]+dp[i];
+	}
+	scanf("%d",&T);
+	for(int t=1; t<=T; t++){
+		scanf("%d%d",&L,&R);
+		int tmp = 2*min(L,R);
+		printf("Case #%d: %lld\n",t,ans[tmp]);
+	}
+	return 0;
+}
diff --git a/Algorithms/Convex hull optimization.cc b/Algorithms/Convex hull optimization.cc
new file mode 100644
index 0000000..91a6df4
--- /dev/null
+++ b/Algorithms/Convex hull optimization.cc	
@@ -0,0 +1,63 @@
+#include <bits/stdc++.h>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef vector<pair<int,int> > vii;
+typedef vector<vector<int> > vvi;
+typedef pair<int,int> pii;
+typedef pair<int,pair<int,int> > piii;
+const double EPSILON = 1e-9;
+const double PI = acos(0.0)*2;
+const int MOD = 1000000007;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+
+int N;
+ll dp[100003];
+ll A[100003],B[100003];
+pll stck[100003];
+int size=0;
+double cross(int a, int b){
+	return (double)(stck[b].second-stck[a].second)/(stck[a].first-stck[b].first);
+}
+void insert(ll a, ll b){
+	stck[size]={a,b};
+	while(size>1&&cross(size-2,size-1)>cross(size-1,size)){
+		stck[size-1]=stck[size];
+		size--;
+	}
+	size++;
+}
+ll query(ll x){
+	int i;
+	for(i=0;i<size-1;i++){
+		if(cross(i,i+1)>=x) break;
+	}
+	return stck[i].first*x+stck[i].second;
+}
+int main() {
+	ios_::sync_with_stdio(false);
+	cin >> N;
+	REP(i,1,N) cin >> A[i];
+	REP(i,1,N) cin >> B[i]
+	dp[1]=0;
+	insert(B[1],0);
+	REP(i,2,N){
+		dp[i]=query(A[i]);
+		insert(B[i],dp[i]);
+	}
+	cout << dp[N];
+	return 0;
+}
diff --git a/Algorithms/Divide and conquer optimization.cc b/Algorithms/Divide and conquer optimization.cc
new file mode 100644
index 0000000..4875ee1
--- /dev/null
+++ b/Algorithms/Divide and conquer optimization.cc	
@@ -0,0 +1,83 @@
+	#include <iostream>
+	#include <cstdio>
+	#include <vector>
+	#include <algorithm>
+	#include <queue>
+	#include <utility>
+	#include <stack>
+	#include <cstring>
+	#include <cstdlib>
+	#include <string>
+	#include <set>
+	#include <cmath>
+	#include <deque>
+	// #include <unordered_set>
+	// #include <map>
+	#define REP(i,a,b) for(int i = a; i <= b;++i)
+	#define FOR(i,n) REP(i,0,n-1)
+	#define mp make_pair
+	#define pb push_back
+	#define all(v) (v).begin(),(v).end()
+	#define inp1(a) scanf("%d",&a)
+	#define inp2(a,b) scanf("%d%d",&a,&b)
+	#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+	#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+
+using namespace std;
+
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef vector<vector<int> > vvi;
+typedef pair<int,int> pii;
+typedef pair<int,pair<int,int> > piii;
+typedef queue<int> QU;
+
+const double EPSILON = 1e-9;
+const double PI = acos(0.0)*2;
+const int MOD = 1000000007;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+
+int N,M;
+int A[8003];
+ll pSum[8003];
+ll D[803][8003];
+int K[803][8003];
+ll C(int l, int r){
+	return (pSum[r]-pSum[l-1])*(r-l+1);
+}
+void DC(int i, int l, int r, int p, int q){
+	if(l>r) return;
+	int mid=(l+r)>>1;
+	D[i][mid]=INFL;
+	for(int k=p;k<=q&&k<mid;k++){
+		if(D[i][mid]>D[i-1][k]+C(k+1,mid)) D[i][mid]=D[i-1][k]+C(k+1,mid),K[i][mid]=k;
+	}
+	DC(i,l,mid-1,p,K[i][mid]);
+	DC(i,mid+1,r,K[i][mid],q);
+}
+int main() {
+	memset(D,0x3c,sizeof(D));
+	inp2(N,M);
+	REP(i,1,N) inp1(A[i]),pSum[i]=pSum[i-1]+A[i];
+	if(N<=M) {
+		printf("%lld",pSum[N]);
+		return 0;
+	}
+	D[0][0]=0;
+	// REP(i,1,M){
+	// 	REP(j,1,N){
+	// 		if(i>j) continue;
+	// 		REP(k,i-1,j-1){
+	// 			if(D[i][j]>D[i-1][k]+C(k+1,j)) D[i][j]=D[i-1][k]+C(k+1,j),K[i][j]=k;
+	// 		}
+	// 	}
+	// }
+	REP(i,1,M) DC(i,1,N,0,N-1);
+	printf("%lld",D[M][N]);
+
+	return 0;
+}
diff --git a/Algorithms/Knuth optimization.cc b/Algorithms/Knuth optimization.cc
new file mode 100644
index 0000000..bdc3d7f
--- /dev/null
+++ b/Algorithms/Knuth optimization.cc	
@@ -0,0 +1,66 @@
+#include <iostream>
+#include <cstdio>
+#include <vector>
+#include <algorithm>
+#include <queue>
+#include <utility>
+#include <stack>
+#include <cstring>
+#include <cstdlib>
+#include <string>
+#include <set>
+#include <cmath>
+#include <deque>
+// #include <unordered_set>
+// #include <map>
+#define REP(i,a,b) for(int i = a; i <= b;++i)
+#define FOR(i,n) REP(i,0,n)
+#define mp make_pair
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+
+using namespace std;
+
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef vector<vector<int> > vvi;
+typedef pair<int,int> pii;
+typedef pair<int,pair<int,int> > piii;
+typedef queue<int> QU;
+
+const double EPSILON = 1e-9;
+const double PI = acos(0.0)*2;
+const int MOD = 1000000007;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+
+ll D[5003][5003];
+int pSum[5003],K[5003][5003];
+int f[5003];
+int n;
+int T;
+int main() {
+	for(inp1(T);T--;){
+		inp1(n);
+		REP(i,1,n) inp1(f[i]),pSum[i]=pSum[i-1]+f[i];
+		memset(D,0x3c,sizeof(D));
+		REP(i,1,n) D[i][i+1]=0,K[i][i+1]=i+1;
+		REP(size,2,n){
+			for(int i=1;i+size<=n+1;i++){
+				int j=i+size;
+				for(int k=K[i][j-1];k<=K[i+1][j];k++){
+					if(D[i][j]>D[i][k]+D[k][j]+pSum[j-1]-pSum[i-1]) D[i][j]=D[i][k]+D[k][j]+pSum[j-1]-pSum[i-1],K[i][j]=k;
+				}
+			}
+		}
+		printf("%lld\n",D[1][n+1]);
+	}
+	return 0;
+}
diff --git a/Algorithms/rotating calipers.cc b/Algorithms/rotating calipers.cc
deleted file mode 100644
index 71bf19c..0000000
--- a/Algorithms/rotating calipers.cc	
+++ /dev/null
@@ -1,86 +0,0 @@
-#include <bits/stdc++.h>
-#define REP(i,a,b) for(int i=a;i<=b;++i)
-#define FOR(i,n) for(int i=0;i<n;++i)
-#define pb push_back
-#define all(v) (v).begin(),(v).end()
-#define sz(v) ((int)(v).size())
-#define inp1(a) scanf("%d",&a)
-#define inp2(a,b) scanf("%d%d",&a,&b)
-#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
-#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
-using namespace std;
-typedef long long ll;
-typedef pair<ll,ll> pll;
-typedef vector<int> vi;
-typedef vector<ll> vl;
-typedef pair<int,int> pii;
-typedef vector<pii> vii;
-typedef vector<pll> vll;
-typedef vector<vector<int> > vvi;
-typedef pair<int,pair<int,int> > piii;
-typedef vector<piii> viii;
-const double EPSILON = 1e-9;
-const double PI = acos(0.0)*2;
-const int MOD = 1000000007;
-const int INF = 0x3c3c3c3c;
-const long long INFL = 0x3c3c3c3c3c3c3c3c;
-const int MAX_N = 102;
-
-struct vector2{
-	ll x,y;
-	vector2(ll x, ll y):x(x),y(y){}
-	vector2(){}
-	bool operator<(const vector2& rhs) const{
-		if(y==rhs.y) return x<rhs.x;
-		return y<rhs.y;
-	}
-	vector2 operator-(const vector2& rhs) const {return vector2(x-rhs.x,y-rhs.y);}
-	ll cross(const vector2& rhs){return x*rhs.y-y*rhs.x;}
-	ll size(){return x*x+y*y;}
-};
-vector2 base;
-ll ccw(vector2& a, vector2& b, vector2& c){
-	return (b-a).cross(c-a);
-}
-bool cmpAngle(vector2& lhs, vector2& rhs){
-	vector2 a = lhs-base;
-	vector2 b = rhs-base;
-	if(!ccw(base,lhs,rhs)) return a.size()<b.size();
-	return ccw(base,lhs,rhs)>0;
-}
-int N,T;
-ll a,b;
-vector<vector2> points;
-vector<vector2> poly;
-int main() {
-	for(inp1(T);T--;){
-		points.clear();
-		poly.clear();
-		inp1(N);
-		FOR(i,N){
-			scanf("%lld%lld",&a,&b);
-			points.pb(vector2{a,b});
-		}
-		sort(all(points));
-		base=points[0];
-		points.erase(points.begin());
-		sort(all(points),cmpAngle);
-		poly.pb(base);
-		for(int i=0;i<sz(points);i++){
-			while(poly.size()>=2&&ccw(poly[poly.size()-2],poly.back(),points[i])<=0) poly.pop_back();
-			poly.pb(points[i]);
-		}
-		vector2 ansA,ansB;
-		ll d=0;
-		FOR(i,sz(poly)){
-			REP(j,i+1,sz(poly)-1){
-				if((poly[i]-poly[j]).size()>d){
-					d=(poly[i]-poly[j]).size();
-					ansA=poly[i],ansB=poly[j];
-				}
-			}
-		}
-		printf("%lld %lld %lld %lld\n",ansA.x,ansA.y,ansB.x,ansB.y);
-	}
-	return 0;
-}
\ No newline at end of file
diff --git "a/Algorithms/segtree lazy(\354\247\247\354\235\200\354\275\224\353\223\234).cc" "b/Algorithms/segtree lazy(\354\247\247\354\235\200\354\275\224\353\223\234).cc"
index 9fc5d95..5d4bd9d 100644
--- "a/Algorithms/segtree lazy(\354\247\247\354\235\200\354\275\224\353\223\234).cc"	
+++ "b/Algorithms/segtree lazy(\354\247\247\354\235\200\354\275\224\353\223\234).cc"	
@@ -1,5 +1,5 @@
-
-
+#include <cstdio>
+using namespace std;
 
 void update(int nl, int nr, int l, int r, int n, ll v){
 	if(d[n]) t[n]+=(nr-nl+1)*d[n],(nl!=nr?d[2*n]+=d[n],d[2*n+1]+=d[n]:0),d[n]=0;
@@ -11,4 +11,10 @@ ll query(int nl, int nr, int l, int r, int n){
 	if(d[n]) t[n]+=(nr-nl+1)*d[n],(nl!=nr?d[2*n]+=d[n],d[2*n+1]+=d[n]:0),d[n]=0;
 	if(l<=nl&&nr<=r) return t[n];
 	if(r<nl||nr<l) return 0;
-	return query(nl,(nl+nr)/2,l,r,2*n)+query((nl+nr)/2+1,nr,l,r,2*n+1);
\ No newline at end of file
+	return query(nl,(nl+nr)/2,l,r,2*n)+query((nl+nr)/2+1,nr,l,r,2*n+1);
+}
+
+int main(){
+	
+	return 0;
+}
\ No newline at end of file
diff --git "a/Algorithms/\354\247\201\354\240\221\354\247\234\353\263\270 STL.cc" "b/Algorithms/\354\247\201\354\240\221\354\247\234\353\263\270 STL.cc"
new file mode 100644
index 0000000..00fa46e
--- /dev/null
+++ "b/Algorithms/\354\247\201\354\240\221\354\247\234\353\263\270 STL.cc"	
@@ -0,0 +1,132 @@
+#include <stdio.h>
+template <class T> void swap(T& a, T& b) { T tmp = a; a = b; b = tmp; }
+template <class T> class vector {
+	int cap;
+	int _size;
+	T *arr;
+public:
+	vector() :_size(0), cap(32), arr(new T[32]) {}
+	T& operator[](int idx) { return arr[idx]; }
+	bool empty() { return _size == 0; }
+	void reserve(int newCap) {
+		T *newArr = new T[newCap];
+		for (int i = 0; i < cap; i++) newArr[i] = arr[i];
+		delete[] arr;
+		arr = newArr;
+		cap = newCap;
+	}
+	void push_back(T v) {
+		if (_size == cap) reserve(cap << 1);
+		arr[_size++] = v;
+	}
+	T back() { return arr[_size - 1]; }
+	void pop_back() { --_size; }
+	int size() { return _size; }
+	T* begin() { return arr; }
+	T* end() { return arr + _size; }
+};
+template <class T> class priority_queue {
+	vector<T> tree;
+public:
+	T top() { return tree.size() ? tree[0] : T(); }
+	bool empty() { return tree.empty(); }
+	void push(T v) {
+		tree.push_back(v);
+		int cur = tree.size() - 1;
+		while (cur > 0) {
+			int next = (cur - 1) / 2;
+			if (!(tree[next] < tree[cur])) break;
+			swap(tree[next], tree[cur]);
+			cur = next;
+		}
+	}
+	void pop() {
+		if (empty()) return;
+		tree[0] = tree.back();
+		tree.pop_back();
+		int cur = 0;
+		while (1) {
+			int next1 = 2 * cur + 1;
+			int next2 = 2 * cur + 2;
+			int next;
+			if (next1 >= tree.size()) break;
+			if (next2 >= tree.size()) next = next1;
+			else next = !(tree[next1] < tree[next2]) ? next1 : next2;
+			if (!(tree[cur] < tree[next])) break;
+			swap<T>(tree[cur], tree[next]);
+			cur = next;
+		}
+	}
+};
+template <class T>
+void sort(T* s, T* e) {
+	priority_queue<T> pq;
+	for (T* pos = s; pos != e; pos++) {
+		pq.push(*pos);
+	}
+	for (T* pos = --e; pos >= s; pos--) {
+		*pos = pq.top();
+		pq.pop();
+	}
+}
+struct RNG {
+	long long seed;
+	RNG() :seed(12387621) {}
+	int next() {
+		int ret = (int)seed;
+		seed = (seed * 2123978 + 122178) % 1000000007;
+		return ret;
+	}
+};
+template <class T> class set {
+	struct Node {
+		Node *l, *r;
+		T key;
+		int prior;
+		Node() {}
+		Node(T ky, int pr) :l(0), r(0), key(ky), prior(pr) {}
+	};
+	typedef Node* pNode;
+	pNode root;
+	RNG rng;
+public:
+	set() : root(0),rng(RNG()) {}
+	void merge(pNode& par, pNode l, pNode r) {
+		if (l == 0 || r == 0) par = (l == 0 ? r : l);
+		else if (l->prior < r->prior) merge(r->l, l, r->l), par = r;
+		else merge(l->r, l->r, r), par = l;
+	}
+	void split(pNode cur, pNode breaker, pNode& l, pNode& r) {
+		if (cur == 0) l = r = 0;
+		else if (cur->key < breaker->key) split(cur->r, breaker, cur->r, r), l = cur;
+		else split(cur->l, breaker, l, cur->l), r = cur;
+	}
+	void insert(pNode& cur, pNode target) {
+		if (cur == 0) { cur = target; }
+		else if (cur->prior < target->prior) split(cur, target, target->l, target->r), cur = target;
+		else insert((cur->key < target->key ? cur->r : cur->l), target);
+	}
+	void erase(pNode &cur, pNode target) {
+		if (cur == 0) return;
+		else if (cur->key != target->key) erase((cur->key < target->key ? cur->r : cur->l), target);
+		else merge(cur, cur->l, cur->r);
+	}
+	void inorder(pNode cur) {
+		if (cur == 0) return;
+		inorder(cur->l);
+		printf("%d ", cur->key);
+		inorder(cur->r);
+	}
+	void insert(T v) { insert(root, new Node(v, rng.next())); }
+	void erase(T v) { erase(root, new Node(v,rng.next())); }
+	void printAll() { inorder(root); }
+};
+
+int main() {
+	set<int> st;
+	for (int i = 0; i < 10; i++) {
+		st.insert(i);
+	}
+	st.printAll();
+	return 0;
+}
\ No newline at end of file
diff --git a/B.cc b/B.cc
new file mode 100644
index 0000000..191eac4
--- /dev/null
+++ b/B.cc
@@ -0,0 +1,46 @@
+// #include <bits/stdc++.h>
+// #include <iostream>
+#include <unordered_set>
+#include <unordered_map>
+#include <vector>
+#include <cstdio>
+#include <cstring>
+#include <queue>
+#include <set>
+#include <map>
+#include <cmath>
+#include <algorithm>
+#include <utility>
+#include <string>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+
+int main() {
+	
+	return 0;
+}
diff --git a/C.cc b/C.cc
new file mode 100644
index 0000000..2313989
--- /dev/null
+++ b/C.cc
@@ -0,0 +1,124 @@
+// #include <bits/stdc++.h>
+// #include <iostream>
+#include <unordered_set>
+#include <unordered_map>
+#include <vector>
+#include <cstdio>
+#include <cstring>
+#include <queue>
+#include <set>
+#include <map>
+#include <cmath>
+#include <algorithm>
+#include <utility>
+#include <string>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 1000003;
+
+vi G[MAX_N];
+int t[MAX_N];
+int N,a,b;
+ll w[MAX_N];
+int ans1, ans2,root,rootbak;
+void dfs(int here){
+	for(int there : G[here]){
+		if(there==ans1) continue;
+		dfs(there);
+		w[here]+=w[there];
+	}
+}
+int dfs2(int here, int type){
+	if(type){
+		if(here!=root&&((w[root]-w[here])*2==w[here])){
+			ans1=here;
+			return 1;`
+		}
+	}
+	else {
+		if(here!=root&&(w[root]-w[here]==2*w[here])){
+			ans1=here;
+			return 1;
+		}
+	}
+	for(int there : G[here]){
+		int ret = dfs2(there,type);
+		if(ret) return ret;
+	}
+	return 0;
+}
+int dfs3(int here){
+	if(here!=root&&(w[root]-w[here]==w[here])) {
+		ans2=here;
+		return 1;
+	}
+	for(int there : G[here]){
+		if(there==ans1) continue;
+		if(dfs3(there)) return 1;
+	}
+	return 0;
+}
+void init(){
+	REP(i,1,N) w[i]=t[i];
+}
+
+int solve1(){
+	root=rootbak;
+	ans1=0,ans2=0;
+	init();
+	dfs(root);
+	int ret = dfs2(root,1);
+	if(!ret) return 0;
+	root=ans1;
+	init();
+	dfs(root);
+	return dfs3(root);
+}
+int solve2(){
+	root=rootbak;
+	ans1=0,ans2=0;
+	init();
+	dfs(root);
+	int ret = dfs2(root,0);
+	if(!ret) return 0;
+	init();
+	dfs(root);
+	return dfs3(root);
+}
+int main() {
+	inp1(N);
+	REP(i,1,N){
+		inp2(a,b);
+		if(a) G[a].pb(i);
+		else rootbak=i;
+		t[i]=b;
+	}
+	if(solve1()||solve2()) printf("%d %d",ans1,ans2);
+	else printf("-1");
+
+	return 0;
+}
diff --git a/C2.cc b/C2.cc
new file mode 100644
index 0000000..ea213b1
--- /dev/null
+++ b/C2.cc
@@ -0,0 +1,91 @@
+// #include <bits/stdc++.h>
+// #include <iostream>
+#include <unordered_set>
+#include <unordered_map>
+#include <vector>
+#include <cstdio>
+#include <cstring>
+#include <queue>
+#include <set>
+#include <map>
+#include <cmath>
+#include <algorithm>
+#include <utility>
+#include <string>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 1000002;
+
+int N,a,b,c,root;
+vi G[MAX_N];
+int w[MAX_N];
+vi third[MAX_N];
+void dfs(int here){
+	for(int there : G[here]){
+		dfs(there);
+		w[here]+=w[there];
+	}
+}
+int dfs2(int here){
+	for(int there : G[here]){
+		int ret = dfs2(there);
+		if(ret) third[here].pb(ret);
+	}
+	if(sz(third[here])>=2){
+		printf("%d %d",third[here][0],third[here][1]);
+		exit(0);
+	}
+	return (here!=root && w[root]==w[here]*3)?here:(sz(third[here])?third[here][0]:0);
+}
+
+void dfs3(int here){
+	if(here!=root && w[here]==w[root]*2/3 && sz(third[here])){
+		printf("%d %d",here,third[here][0]);
+		exit(0);
+	}
+	for(int there : G[here]){
+		dfs3(there);
+	}
+}
+int main() {
+	inp1(N);	
+	REP(i,1,N){
+		inp2(a,b);
+		if(a) G[a].pb(i);
+		else root=i;
+		w[i]=b;
+	}
+	dfs(root);
+	if(w[root]%3){
+		printf("-1");
+		return 0;
+	}
+	dfs2(root);
+	dfs3(root);
+	printf("-1");
+	return 0;
+}
diff --git a/SRM504,5(mid).cc b/SRM504,5(mid).cc
new file mode 100644
index 0000000..de3de13
--- /dev/null
+++ b/SRM504,5(mid).cc
@@ -0,0 +1,71 @@
+// #include <bits/stdc++.h>
+// #include <iostream>
+#include <unordered_set>
+#include <unordered_map>
+#include <vector>
+#include <cstdio>
+#include <cstring>
+#include <queue>
+#include <set>
+#include <map>
+#include <cmath>
+#include <algorithm>
+#include <utility>
+#include <string>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+
+pii dist[10];
+int solve(int N) {
+	FOR(i,10) dist[i]={-1,-1};
+	queue<pii> q;
+	q.push({0,0});
+	while(!q.empty()){
+		int hereNum = q.front().first;
+		int hereD = q.front().second;
+		q.pop();
+		string s="47";
+		for(auto c : s){
+			int nextNum = hereNum + c-'0';
+			int nextD = hereD+1;
+			if(dist[nextNum%10].second!=-1) continue;
+			dist[nextNum%10] = {nextNum, nextD};
+			q.push({nextNum,nextD});
+		}
+	}
+	if(dist[N%10].first > N) return -1;
+	else return dist[N%10].second;
+}
+
+
+class TheNumbersWithLuckyLastDigit{
+public:
+	int find(int n) {
+		return solve(n);
+	}
+}
\ No newline at end of file
diff --git a/frame.cpp b/frame.cpp
index d7683d8..fd1c438 100644
--- a/frame.cpp
+++ b/frame.cpp
@@ -1,17 +1,4 @@
-// #include <bits/stdc++.h>
-#include <unordered_set>
-// #include <unordered_map>
-// #include <iostream>
-#include <vector>
-#include <cstdio>
-#include <cstring>
-#include <queue>
-#include <set>
-#include <map>
-#include <cmath>
-#include <algorithm>
-#include <utility>
-#include <string>
+#include <bits/stdc++.h>
 #define REP(i,a,b) for(int i=a;i<=b;++i)
 #define FOR(i,n) for(int i=0;i<n;++i)
 #define pb push_back
@@ -25,7 +12,7 @@
 using namespace std;
 typedef long long ll;
 typedef pair<ll,ll> pll;
-typedef vector<int> vi;
+typedef vector<int> vi;	
 typedef vector<ll> vl;
 typedef pair<int,int> pii;
 typedef vector<pii> vii;
@@ -35,7 +22,7 @@ typedef pair<int,pair<int,int> > piii;
 typedef vector<piii> viii;
 const double EPSILON = 1e-9;
 const double PI = acos(-1);
-const int MOD = 1000000007;
+const int MOD = 1e9+7;
 const int INF = 0x3c3c3c3c;
 const long long INFL = 0x3c3c3c3c3c3c3c3c;
 const int MAX_N = 102;
diff --git a/hackerearth1.cc b/hackerearth1.cc
new file mode 100644
index 0000000..10b4e45
--- /dev/null
+++ b/hackerearth1.cc
@@ -0,0 +1,67 @@
+// #include <bits/stdc++.h>
+// #include <iostream>
+#include <vector>
+#include <cstdio>
+#include <cstring>
+#include <queue>
+#include <set>
+#include <map>
+#include <cmath>
+#include <algorithm>
+#include <utility>
+#include <string>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;	
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+
+int left[100003];
+int T,N;
+int A[100003];
+ll pSum[100003];
+int main() {
+	inp1(T);
+	while(T--){
+		memset(left,0,sizeof(left));
+		memset(pSum,0,sizeof(pSum));
+		inp1(N);
+		FOR(i,N) inp1(A[i]),pSum[i+1]=pSum[i]+A[i];
+		int l=0,r=INF;
+		REP(i,1,N){
+			int updL=-1;
+			int mod = pSum[i]%N;
+			if(mod) {
+				if(left[mod]) updL = left[mod];
+			}
+			else updL = left[mod];
+			if(updL != -1 && r-l > i-updL) l = updL, r = i;
+			left[mod]=i;
+		}
+		printf("%d %d\n",l+1,r);
+	}
+
+	return 0;
+}
diff --git a/heap_sort.cc b/heap_sort.cc
new file mode 100644
index 0000000..7bda7f1
--- /dev/null
+++ b/heap_sort.cc
@@ -0,0 +1,20 @@
+#include <stdio.h>
+#include <malloc.h>
+typedef long long ll;
+struct RNG{
+	ll seed;
+	RNG():seed(1){}
+	ll next(){
+		ll ret = seed;
+		seed = ((seed)*2012122327)%1000000007;
+		return ret;
+	}
+};
+template <class T> class vector{
+	
+};
+int main(){
+	RNG rng;
+
+	return 0;
+}
\ No newline at end of file
diff --git a/input.txt b/input.txt
index eeca4a1..a5facbd 100644
--- a/input.txt
+++ b/input.txt
@@ -1 +1,7 @@
-5 5
\ No newline at end of file
+10 6
+1 10
+1 10
+1 9
+1 9
+1 9
+1 9
\ No newline at end of file
diff --git a/output.txt b/output.txt
new file mode 100644
index 0000000..22782d1
--- /dev/null
+++ b/output.txt
@@ -0,0 +1,100 @@
+Case #1: 0.65144864
+Case #2: 0.14791851
+Case #3: 0.87390543
+Case #4: 0.52073288
+Case #5: 0.30508475
+Case #6: 0.68236583
+Case #7: 0.44630072
+Case #8: 0.61138015
+Case #9: 0.32961931
+Case #10: 0.41000000
+Case #11: 0.48457350
+Case #12: 0.18887685
+Case #13: 0.23429084
+Case #14: 0.83917775
+Case #15: 0.23231058
+Case #16: 0.23239218
+Case #17: 0.00025006
+Case #18: 0.81701738
+Case #19: 0.24707657
+Case #20: 0.18839361
+Case #21: 0.03211304
+Case #22: 0.52459815
+Case #23: 0.27338710
+Case #24: 0.16767865
+Case #25: 0.08123606
+Case #26: 0.05023133
+Case #27: 0.63192721
+Case #28: 0.52550768
+Case #29: 0.06743738
+Case #30: 0.25777414
+Case #31: 0.30627306
+Case #32: 0.96576032
+Case #33: 0.96551724
+Case #34: 0.60579244
+Case #35: 0.99900050
+Case #36: 0.20239774
+Case #37: 0.88052373
+Case #38: 0.96293312
+Case #39: 0.71491876
+Case #40: 0.26384365
+Case #41: 0.39885057
+Case #42: 0.47517084
+Case #43: 0.31041667
+Case #44: 0.00787402
+Case #45: 0.05778961
+Case #46: 0.99306358
+Case #47: 0.16232465
+Case #48: 0.60765550
+Case #49: 0.39869782
+Case #50: 0.96975806
+Case #51: 0.53795918
+Case #52: 0.57718121
+Case #53: 0.07060653
+Case #54: 0.30429594
+Case #55: 0.01261564
+Case #56: 0.30496454
+Case #57: 0.11860095
+Case #58: 0.07857912
+Case #59: 0.01716902
+Case #60: 0.01485320
+Case #61: 1.00000000
+Case #62: 0.01554908
+Case #63: 0.72876712
+Case #64: 0.17530864
+Case #65: 1.00000000
+Case #66: 0.05038372
+Case #67: 0.06359946
+Case #68: 0.37752161
+Case #69: 0.17851694
+Case #70: 0.79404818
+Case #71: 0.35640786
+Case #72: 0.01308258
+Case #73: 0.33333333
+Case #74: 0.37894737
+Case #75: 0.31595092
+Case #76: 0.97439181
+Case #77: 0.17653569
+Case #78: 0.02529511
+Case #79: 0.13656388
+Case #80: 0.32568579
+Case #81: 0.61936721
+Case #82: 0.14285714
+Case #83: 0.56358164
+Case #84: 0.18681319
+Case #85: 0.43002833
+Case #86: 0.02743561
+Case #87: 0.53207150
+Case #88: 0.93207547
+Case #89: 0.63776164
+Case #90: 0.30461271
+Case #91: 0.97553517
+Case #92: 0.48734873
+Case #93: 0.56743815
+Case #94: 0.35487594
+Case #95: 0.03225806
+Case #96: 0.40719910
+Case #97: 0.99330656
+Case #98: 0.03587052
+Case #99: 0.25799190
+Case #100: 0.20278224
diff --git a/quick_sort.cc b/quick_sort.cc
new file mode 100644
index 0000000..717455a
--- /dev/null
+++ b/quick_sort.cc
@@ -0,0 +1,62 @@
+#include <bits/stdc++.h>
+// #include <iostream>
+#include <unordered_set>
+#include <unordered_map>
+#include <vector>
+#include <cstdio>
+#include <cstring>
+#include <queue>
+#include <set>
+#include <map>
+#include <cmath>
+#include <algorithm>
+#include <utility>
+#include <string>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+
+struct RNG{
+	ll seed;
+	RNG():seed(1){}
+	ll next(){
+		ll ret = seed;
+		seed = (seed*2012122327)%100000;
+		return ret;
+	}
+};
+
+vector<int> before,after;
+int N;
+int main() {
+	RNG rng;
+	N=100;
+	for(int i = 0; i < N; i++) before.push_back(rng.next());
+	FOR(i,N) printf("%d\n",before[i]);
+
+	return 0;
+}
diff --git a/rail2.cpp b/rail2.cpp
index 4e69ee1..4a43ff6 100644
--- a/rail2.cpp
+++ b/rail2.cpp
@@ -8,7 +8,7 @@
 #include <queue>
 #include <set>
 #include <map>
-#include <cmath>
+// #include <cmath>
 #include <algorithm>
 #include <utility>
 #include <string>
@@ -33,54 +33,79 @@ typedef vector<pll> vll;
 typedef vector<vector<int> > vvi;
 typedef pair<int,pair<int,int> > piii;
 typedef vector<piii> viii;
-const double EPSILON = 1e-9;
-const double PI = acos(-1);
 const int MOD = 1000000007;
 const int INF = 0x3c3c3c3c;
 const long long INFL = 0x3c3c3c3c3c3c3c3c;
 const int MAX_N = 102;
 
-int N,M,a,b,E;
-ll dp[200003];
-int l[200003],r[200003],t[200003];
-unordered_set<int> us;
-
-void update(int l, int r, ll v){
-	for(l+=E,r+=E;l<=r;l>>=1,r>>=1){
-		if(l&1) (t[l++]+=v)%=MOD;
-		if(!(r&1)) (t[r--]+=v)%=MOD;
+struct Range{
+	int l,r;
+	bool operator<(Range& rhs){
+		if(l==rhs.l) return r<rhs.r;
+		return l<rhs.l;
 	}
-}
-ll query(int l, int r){
-	ll ret=0;
-	for(l+=E,r+=E;l<=r;l>>=1,r>>=1){
-		if(l&1) (ret+=t[l++])%=MOD;
-		if(!(r&1)) (ret+=t[r--])%=MOD;
+};
+int N,M,a,b,E;
+Range ranges[200003];
+ll dp[3610003];
+int lz[3610003];
+ll pow2(ll x, int n){
+	if(!n) return 1;
+	ll memo;
+	if(n%2) {
+		memo = pow2(x,(n-1)/2);
+		return x*memo%MOD*memo%MOD;
 	}
-	return ret;
+	memo = pow2(x,n/2);
+	return memo*memo%MOD;
 }
+unordered_set<int> us;
+ll query(int nl, int nr, int l, int r, int nd){
+	if(lz[nd]) (dp[nd]*=pow2(2,lz[nd]))%=MOD,(nl!=nr?lz[2*nd]+=lz[nd],lz[2*nd+1]+=lz[nd]:0),lz[nd]=0;
+	if(l<=nl&&nr<=r) return dp[nd];
+	if(r<nl||nr<l) return 0;
+	return (query(nl,(nl+nr)/2,l,r,2*nd)+query((nl+nr)/2+1,nr,l,r,2*nd+1))%MOD;
+} ll query(int l, int r){return query(0,E,l,r,1);}
+
+void update(int nl, int nr, int l, int r, int nd){
+	if(lz[nd]) (dp[nd]*=pow2(2,lz[nd]))%=MOD,(nl!=nr?lz[2*nd]+=lz[nd],lz[2*nd+1]+=lz[nd]:0),lz[nd]=0;
+	if(l<=nl&&nr<=r) {(dp[nd]*=2)%=MOD,(nl!=nr?lz[2*nd]++,lz[2*nd+1]++:0);return;}
+	if(r<nl||nr<l) return;
+	update(nl,(nl+nr)/2,l,r,2*nd),update((nl+nr)/2+1,nr,l,r,2*nd+1),dp[nd]=(dp[2*nd]+dp[2*nd+1])%MOD;
+} void update(int l, int r){update(0,E,l,r,1);}
+
+void pUpdate(int nl, int nr, int nd, int pos, ll val){
+	if(lz[nd]) (dp[nd]*=pow2(2,lz[nd]))%=MOD,(nl!=nr?lz[2*nd]+=lz[nd],lz[2*nd+1]+=lz[nd]:0),lz[nd]=0;
+	if(nl==nr&&nl==pos) {dp[nd]=val;return;}
+	if(nr<pos||pos<nl) return;
+	pUpdate(nl,(nl+nr)/2,2*nd,pos,val),pUpdate((nl+nr)/2+1,nr,2*nd+1,pos,val),dp[nd]=(dp[2*nd]+dp[2*nd+1])%MOD;
+} void pUpdate(int pos, ll val){pUpdate(0,E,1,pos,val);}
+
 int main() {
-	memset(dp,-1,sizeof(dp));
 	vi sorted;
 	inp2(N,M);
 	us.insert(1),sorted.pb(1);
 	us.insert(N),sorted.pb(N);
 	FOR(i,M){
 		inp2(a,b);
-		l[i]=a,l[i]=b;
+		ranges[i]=Range{a,b};
 		if(!us.count(a)) us.insert(a),sorted.pb(a);
 		if(!us.count(b)) us.insert(b),sorted.pb(b);
 	}
 	sort(all(sorted));
-	E=sz(sorted);
+	E=sz(sorted)-1;
 	FOR(i,M) {
-		l[i]=lower_bound(all(sorted),l[i])-sorted.begin();
-		r[i]=lower_bound(all(sorted),r[i])-sorted.begin();
+		ranges[i].l=lower_bound(all(sorted),ranges[i].l)-sorted.begin();
+		ranges[i].r=lower_bound(all(sorted),ranges[i].r)-sorted.begin();
 	}
-	// ì¢Œí‘œì••ì¶• ì™„ë£Œ
-	
-	REP(i,1,E){
+	sort(ranges,ranges+M);
+	// ì¢Œí‘œì••ì¶• + ì •ë ¬ê¹Œì§€ ì™„ë£Œ
 
+	pUpdate(0,1);
+	FOR(i,M){
+		pUpdate(ranges[i].r,(query(ranges[i].l,ranges[i].r)+query(ranges[i].r,ranges[i].r))%MOD);
+		update(ranges[i].r+1,E);
 	}
+	printf("%lld",query(E,E));
 	return 0;
 }
diff --git a/test.cc b/test.cc
index ccba6e3..0186c88 100644
--- a/test.cc
+++ b/test.cc
@@ -1,92 +1,39 @@
-#include<iostream>
-#include<cstdio>
-#include<cstring>
-#include<queue>
-#include<vector>
-#define R 1001
-#define MAX_R R*2
-#define INF 1987654321
+#include <bits/stdc++.h>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
 using namespace std;
-
-int cost[MAX_R][MAX_R], flow[MAX_R][MAX_R];
-int main(){
-	int i;
-	int v,e;
-
-	while(scanf("%d%d",&v,&e)!=EOF){
-
-		int source,sink;
-		vector<int> adj[MAX_R];
-		
-		memset(flow,0,sizeof(flow));
-		memset(cost,0,sizeof(cost));
-
-		source=1;
-		sink=v+v;
-		getchar();
-		for(i=0;i<e;i++){ // ì´ë¶€ë¶„.
-			int a,b,c;
-			scanf("%d%d%d",&a,&b,&c);
-			printf("%d -> %d\n",a,b+v);
-			adj[a].push_back(b+v);
-			adj[b+v].push_back(a);
-			cost[a][b+v]=c;
-			cost[b+v][a]=-c;
-			flow[a][b+v]++;
-		}
-
-		int roop=2;
-		int ans=0;
-		int ans2=0;
-		while(roop>0){
-			int dist[MAX_R],prev[MAX_R];
-			bool visit[MAX_R];
-
-			memset(prev,-1,sizeof(prev));
-			fill(dist,dist+MAX_R,INF);
-			memset(visit,false,sizeof(visit));
-
-			queue<int> q;
-			visit[source]=true;
-			q.push(source);
-			dist[source]=0;
-
-			while(!q.empty()){
-				int x;
-				x=q.front();
-				q.pop();
-				visit[x]=false;
-
-				for(i=0;i<adj[x].size();i++){
-					int next;
-					next=adj[x][i];
-
-					if(flow[x][next]==0) continue;
-				
-					if(dist[next]>dist[x]+cost[x][next]){
-						dist[next]=dist[x]+cost[x][next];
-						prev[next]=x;
-						if(visit[next]==false){
-							q.push(next);
-							visit[next]=true;
-						}
-					}
-				}
-			}
-
-			if(prev[sink]==-1) break;
-			ans++;
-			ans2+=dist[sink];
-			for(i=sink;i!=source;i=prev[i]){
-				flow[prev[i]][i]--;
-				flow[i][prev[i]]++;
-			}
-
-			printf("%d\n",ans2);
-			roop--;
-		}
-		
-	}
-
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;	
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 102;
+
+ll pow2(ll x, int n){
+	if(!n) return 1;
+	if(n%2) return x*pow2(x,(n-1)/2)%MOD*pow2(x,(n-1)/2)%MOD;
+	return pow2(x,n/2)*pow2(x,n/2)%MOD;
+}
+
+int main() {
+	printf("%lld",pow2(2,200000));
 	return 0;
-}
\ No newline at end of file
+}
diff --git a/test.cpp b/test.cpp
index c198f2c..10c6177 100644
--- a/test.cpp
+++ b/test.cpp
@@ -1,13 +1,13 @@
 // #include <bits/stdc++.h>
+// #include <iostream>
 #include <unordered_set>
 // #include <unordered_map>
-// #include <iostream>
 #include <vector>
 #include <cstdio>
 #include <cstring>
 #include <queue>
-#include <set>
-#include <map>
+// #include <set>
+// #include <map>
 #include <cmath>
 #include <algorithm>
 #include <utility>
@@ -35,40 +35,172 @@ typedef pair<int,pair<int,int> > piii;
 typedef vector<piii> viii;
 const double EPSILON = 1e-9;
 const double PI = acos(-1);
-const int MOD = 1000000007;
+const int MOD = 1e9+7;
 const int INF = 0x3c3c3c3c;
 const long long INFL = 0x3c3c3c3c3c3c3c3c;
 const int MAX_N = 102;
 
-ll dp[10][1<<10];
-int W,H;
-int bitOn(int state, int pos){
-	return state|(1<<pos-1);
+struct Point{int x,y;};
+vector<int> sortedX, sortedY;
+int newX[10], newY[10];
+Point straw[3], cherry[3], candle;
+unordered_set<int> usX, usY;
+int N,M,S,T;
+int dy[]={-1,1,0,0};
+int dx[]={0,0,1,-1};
+vector<int> G[3003];
+int iter[3003],parent[3003],flow[3000][3000],cap[3000][3000],level[3000];
+bool isCandle(int i, int j){return i==candle.x&&j==candle.y;}
+bool inRange(int i, int j){return 0<=i&&i<N&&0<=j&&j<M;}
+int IN(int x){return 2+x;}
+int OUT(int x){return 2+N*M+x;}
+void connect(int a, int b){
+	G[a].push_back(b);
+	G[b].push_back(a);
+	cap[a][b]=1;
 }
-int isOn(int state, int pos){
-	return state&(1<<pos-1);
+int trans(int i, int j){return i*M+j;}
+void makeGraph(){
+	FOR(i,N){
+		FOR(j,M){
+			if(isCandle(i,j)) continue;
+			FOR(k,4){
+				int ni = i+dy[k], nj = j+dx[k];
+				if(!inRange(ni,nj) || isCandle(ni,nj)) continue;
+				connect(OUT(trans(i,j)),IN(trans(ni,nj)));
+			}
+			connect(IN(trans(i,j)),OUT(trans(i,j)));
+		}
+	}
 }
-ll go(int, int);
-ll back(int h, int w, int prvState, int curState){
-	if(w==W) return go(h+1,curState);
-	ll ret=0;
-	ret+=back(h,w+1,prvState,curState);
-	if(isOn(prvState,w)){
-		(ret+=back(h,w+1,prvState,bitOn(curState,w)))%=MOD;
-		if(w+1<W && isOn(prvState,w+1)) (ret+=back(h,w+2,prvState,bitOn(bitOn(curState,w),w+1)))%=MOD;
-		if(w+2<W && isOn(prvState,w+2)) (ret+=back(h,w+3,prvState,bitOn(bitOn(bitOn(curState,w),w+1),w+2)))%=MOD;
+
+int dfs(int here){
+	if(here==T) return 1;
+	for(int& i = iter[here]; i < G[here].size(); ++i){
+		int there=G[here][i];
+		if(cap[here][there]-flow[here][there]>0 && level[here]+1 == level[there]){
+			parent[there]=here;
+			if(dfs(there)) return 1;
+		}
 	}
-	return ret;
+	return 0;
 }
-ll go(int h, int prvState){
-	if(h==H) return 1;
-	ll& cache = dp[h][prvState];
-	if(cache!=-1) return cache;
-	return cache = back(h,0,prvState,0);
+
+int dinic(){
+	int ret=0;
+	while(1) {
+		memset(level,-1,sizeof(level));
+		level[S]=0;
+		queue<int> q;
+		q.push(S);
+		while(!q.empty() && level[T] == -1) {
+			int here = q.front();
+			q.pop();
+			for(auto& there : G[here]){
+				if(cap[here][there]-flow[here][there]>0 && level[there] == -1){
+					level[there]=level[here]+1;
+					q.push(there);
+				}
+			}
+		}
+		if(level[T] == -1) break;
+		memset(iter,0,sizeof(iter));
+
+		while(1){
+			memset(parent,-1,sizeof(parent));
+			parent[S]=0;
+			if(!dfs(0)) break;
+			int minFlow=INF;
+			for(int p = 1; p!=parent[p]; p = parent[p]){
+				minFlow = min(minFlow, cap[parent[p]][p]-flow[parent[p]][p]);
+			}
+
+			for(int p = 1; p!=parent[p]; p = parent[p]){
+				flow[parent[p]][p] += minFlow;
+				flow[p][parent[p]] -= minFlow;
+			}
+			ret+=minFlow;
+		}
+	}
+	return ret;
 }
+
 int main() {
-	memset(dp,-1,sizeof(dp));
-	scanf("%d%d",&W,&H);
-	printf("%lld",go(0,(1<<W)-1));
+	scanf("%d%d",&N,&M);
+	
+	scanf("%d%d",&candle.x,&candle.y);
+	candle.x--,candle.y--;
+	if(!usX.count(candle.x)) sortedX.push_back(candle.x);
+	if(!usY.count(candle.y)) sortedY.push_back(candle.y);
+
+	for(int i = 0; i < 3; i++) {
+		scanf("%d%d",&straw[i].x,&straw[i].y);
+		straw[i].x--,straw[i].y--;
+		if(!usX.count(straw[i].x)) usX.insert(straw[i].x), sortedX.push_back(straw[i].x);
+		if(!usY.count(straw[i].y)) usY.insert(straw[i].y), sortedY.push_back(straw[i].y);
+	}
+	for(int i = 0; i < 3; i++) {
+		scanf("%d%d",&cherry[i].x,&cherry[i].y);
+		cherry[i].x--,cherry[i].y--;
+		if(!usX.count(cherry[i].x)) usX.insert(cherry[i].x), sortedX.push_back(cherry[i].x);
+		if(!usY.count(cherry[i].y)) usY.insert(cherry[i].y), sortedY.push_back(cherry[i].y);
+	}
+	sort(all(sortedX)), sort(all(sortedY));
+	
+	newX[0] = sortedX[0]>3 ? 3 : sortedX[0];
+	for(int i = 0; i < sz(sortedX)-1; i++){
+		int diff = sortedX[i+1]-sortedX[i];
+		if(diff > 4) diff=4;
+		newX[i+1]=newX[i]+diff;
+	}
+	
+	newY[0] = sortedY[0]>3 ? 3 : sortedY[0];
+	for(int i = 0; i < sz(sortedY)-1; i++){
+		int diff = sortedY[i+1]-sortedY[i];
+		if(diff > 4) diff=4;
+		newY[i+1]=newY[i]+diff;
+	}
+
+	int pos;
+	for(int i = 0; i < 3; i++){
+		pos = lower_bound(all(sortedX),straw[i].x) - sortedX.begin();
+		straw[i].x=newX[pos];
+		pos = lower_bound(all(sortedY),straw[i].y) - sortedY.begin();
+		straw[i].y=newY[pos];
+	}
+
+	for(int i = 0; i < 3; i++){
+		pos = lower_bound(all(sortedX),cherry[i].x) - sortedX.begin();
+		cherry[i].x=newX[pos];
+		pos = lower_bound(all(sortedY),cherry[i].y) - sortedY.begin();
+		cherry[i].y=newY[pos];
+	}
+
+	pos = lower_bound(all(sortedX),candle.x) - sortedX.begin();
+	candle.x=newX[pos];
+	pos = lower_bound(all(sortedY),candle.y) - sortedY.begin();
+	candle.y=newY[pos];
+	
+
+	int diff = N-sortedX.back();
+	N = newX[sz(sortedX)-1]+(diff>3?3:diff);
+	diff = M-sortedY.back();
+	M = newY[sz(sortedY)-1]+(diff>3?3:diff);
+
+	// printf("straw\n");
+	// FOR(i,3) printf("(%d, %d), ",straw[i].x,straw[i].y);
+	// printf("\n");
+	// printf("cherry\n");
+	// FOR(i,3) printf("(%d, %d), ",cherry[i].x,cherry[i].y);
+	// printf("\n");
+	// printf("N:%d, M:%d\n",N,M);
+	// printf("candle:(%d,%d)",candle.x,candle.y);
+	S=0,T=1;
+	makeGraph();
+	FOR(i,3){
+		connect(S,IN(trans(straw[i].x,straw[i].y)));
+		connect(OUT(trans(cherry[i].x,cherry[i].y)),T);
+	}
+	printf("%s", dinic()==3?"Yes":"No");
 	return 0;
 }
diff --git a/testCaseMaker.cc b/testCaseMaker.cc
index 9bd2bc7..c48c46d 100644
--- a/testCaseMaker.cc
+++ b/testCaseMaker.cc
@@ -38,17 +38,9 @@ const int MAX_N = 1000000;
 int T,N,M,K,R;
 int main() {
 	freopen("input.txt","w",stdout);
-	N=500,K=100;
-	cout << N << endl;
-	FOR(i,N/2) printf("%d ",i%2+1);
-	FOR(i,(N+1)/2) printf("0 ");
-	printf("\n");
-	FOR(i,N){
-		FOR(j,N){
-			if(i-j) printf("1000 ");
-			else printf("0 ");
-		}
-		printf("\n");
+	printf("999999\n");
+	FOR(i,999999){
+		printf("%d %d\n",i,-100);
 	}
 	
 	return 0;
diff --git "a/unordered_map \354\204\270\353\262\210\354\247\270 \355\225\264\354\211\254\355\225\250\354\210\230 \354\235\270\354\236\220.cc" "b/unordered_map \354\204\270\353\262\210\354\247\270 \355\225\264\354\211\254\355\225\250\354\210\230 \354\235\270\354\236\220.cc"
new file mode 100644
index 0000000..c7305d6
--- /dev/null
+++ "b/unordered_map \354\204\270\353\262\210\354\247\270 \355\225\264\354\211\254\355\225\250\354\210\230 \354\235\270\354\236\220.cc"	
@@ -0,0 +1,8 @@
+struct hashLL {
+    size_t operator()(LL x) const {
+        x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
+        x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
+        x = x ^ (x >> 31);
+        return x;
+    }
+};
\ No newline at end of file
diff --git "a/\354\206\214\354\210\230\355\214\220\353\263\204\352\270\260.cc" "b/\354\206\214\354\210\230\355\214\220\353\263\204\352\270\260.cc"
new file mode 100644
index 0000000..dac70e1
--- /dev/null
+++ "b/\354\206\214\354\210\230\355\214\220\353\263\204\352\270\260.cc"
@@ -0,0 +1,56 @@
+// #include <bits/stdc++.h>
+// #include <iostream>
+#include <unordered_set>
+#include <unordered_map>
+#include <vector>
+#include <cstdio>
+#include <cstring>
+#include <queue>
+#include <set>
+#include <map>
+#include <cmath>
+#include <algorithm>
+#include <utility>
+#include <string>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 1000002;
+
+int notPrime[MAX_N];
+int a;
+int main() {
+	for(int i = 2; i*i < MAX_N; i++){
+		if(notPrime[i]) continue;
+		for(int j = 2*i; j<MAX_N; j+=i){
+			notPrime[j]=1;
+		}
+	}
+	scanf("%d",&a);
+	if(notPrime[a]) printf("[-] %d is not prime!\n",a);
+	else printf("[+] %d is prime!\n",a);
+	return 0;
+}
diff --git "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/170201 \353\260\260\354\232\264\352\261\260.txt" "b/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/170201 \353\260\260\354\232\264\352\261\260.txt"
deleted file mode 100644
index 8d18c9b..0000000
--- "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/170201 \353\260\260\354\232\264\352\261\260.txt"	
+++ /dev/null
@@ -1,5 +0,0 @@
-4»ö Á¤¸® :
-"Æò¸é ±×·¡ÇÁ¿¡¼­ ÃÑ 4°¡ÁöÀÇ »öÀ¸·Î¸¸ ´Ù Ä¥ÇÒ¼öÀÖ´Ù." ¶ó´Â Á¤¸®
-
-±×·¸±â ¶§¹®¿¡ ¹°·Ð Æ®¸®µµ °¡´É. »ç½Ç Æ®¸®´Â 2°¡ÁöÀÇ »öÀ¸·Î ´Ù Ä¥ÇÒ ¼ö ÀÖ´Ù.
-ÇÏÁö¸¸ »ö ¸¶´Ù ºñ¿ëÀÌ ´Ù¸¦°æ¿ì °¡Àå ÀûÀº ºñ¿ëÀÇ 4°¡Áö »ö¸¸ °í·ÁÇØµµ ÃÖÀûÇØ°¡ ³ª¿Â´Ù.
\ No newline at end of file
diff --git "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/170215 \353\260\260\354\232\264\352\261\260.txt" "b/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/170215 \353\260\260\354\232\264\352\261\260.txt"
deleted file mode 100644
index 7cd0fdf..0000000
--- "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/170215 \353\260\260\354\232\264\352\261\260.txt"	
+++ /dev/null
@@ -1,10 +0,0 @@
-dp ¿¡¼­ Àç±ÍÇÔ¼ö³»¿¡¼­ ÇÏ³ªÀÇ ºÎºÐ¹®Á¦¸¦ Ç®¶§¿¡ ÇÊ¿äÇÑ ¼­ºêÈ£ÃâÀ» ÇÒ¶§
-¿©·¯ °¡Áö Á¶ÇÕ(combination) ÀÌ ³ª¿Ã°æ¿ì¿¡ ½Ã°£µµ ¿À·¡°É¸®°í ±¸Çöµµ º¹ÀâÇÏ±â¶§¹®¿¡
-°¢°¢ÀÇ Àç±ÍÇÔ¼ö¿¡¼­ ¹Ýº¹¹®À¸·Î ±×°ÍµéÀ» ´Ù µûÁ®ÁÖ±âº¸´Ù ÇÔ¼ö ÀÎÀÚ¸¦ ÇÏ³ª ´õ Ãß°¡ÇÏ¿©
-ÇÑ´Ü°è ÇÑ´Ü°è ÆÇ´ÜÇÏµµ·Ï ÇÏ¿© O(1)·Î ¹Ù²Ù¸é ±¸Çöµµ °£´ÜÇØÁö°í ½Ã°£µµ »¡¶óÁö´Â Å×Å©´ÐÀ» »ç¿ëÇÏ¸é ÁÁ´Ù
-
-
-BOJ 12995¹ø Æ®¸®³ª¶ó(https://www.acmicpc.net/problem/12995) ¹®Á¦°°Àº
-Æ®¸® dp ¿¡¼­ ¸î¹øÂ° ¿§Áö±îÁö ºÁÁá´ÂÁö¸¦ ÀÎÀÚ·Î Ãß°¡ÇÏ´Â °Íµµ ÀÌ Å×Å©´Ð¿¡ ÇØ´çÇÏ°í
-BOJ 14276¹ø µµ·Î°Ç¼³(https://www.acmicpc.net/problem/14276) ¹®Á¦µµ
-ÀÌ Å×Å©´ÐÀ» »ç¿ëÇÑ´Ù
\ No newline at end of file
diff --git "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/170217 \353\260\260\354\232\264\352\261\260.txt" "b/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/170217 \353\260\260\354\232\264\352\261\260.txt"
deleted file mode 100644
index bea9670..0000000
--- "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/170217 \353\260\260\354\232\264\352\261\260.txt"	
+++ /dev/null
@@ -1,21 +0,0 @@
-BOJÀÇ ºí·°½×±â(https://www.acmicpc.net/problem/14278) ¸¦ Ç®¸ç ¹è¿îÁ¡
-
-dp ¹®Á¦¸¦ Ç®¶§ ºÎºÐ¹®Á¦ÀÇ Á¤ÀÇ¿Í Á¡È­½ÄÀÌ ³ª¿Ô´Âµ¥ °¢°¢ÀÇ ºÎºÐ¹®Á¦¸¦ ±¸ÇÏ´Â ½ÄÀÇ ±¸ÇöÀÌ º¹ÀâÇÏ°Å³ª½Ã°£ÀÌ ¿À·¡°É¸®´Â(È¤Àº µÑ´ÙÀÇ)°æ¿ì°¡ ÀÖ´Ù.
-¿¹¸¦ µé¾î ¿©·¯°¡Áö Á¶ÇÕ(Combination) À» µûÁ®Áà¾ßÇÒ°æ¿ì°¡ ±×·¸´Ù. ÀÌ·²°æ¿ì °¡Àå °£ÆíÇÑ ¹æ¹ýÁß ÇÏ³ª°¡ Æ®¸®dp ¿¡¼­ ÇöÀç ³ëµåÀÇ À§Ä¡ »Ó¸¸¾Æ´Ï¶ó ¸î¹øÂ°
-ÀÚ½Ä±îÁö Ã³¸®ÇØ ÁÖ¾ú´ÂÁö¸¦ ÀúÀåÇÏ´Â º¯¼ö ÇÏ³ª¸¦ ºÎºÐ¹®Á¦¿¡(Àç±Í·Î ±¸ÇöÇÑ´Ù¸é Àç±Í ÇÔ¼öÀÇ ÀÎÀÚ¿¡) Ãß°¡ÇÏ¿© ÇÑ,µÎ Â÷¿øÀ» ´Ã¸®´Â°ÍÃ³·³ ºÎºÐ ¹®Á¦¸¦
-¼¼ºÐÈ­ÇÏ´Â ¹æ¹ýÀÌ´Ù. ÇÏÁö¸¸ ÀÌ·¸°Ô ÇÒ °æ¿ì ½Ã°£ º¹Àâµµ°¡ ±âÁØ ÀÌ»óÀ¸·Î Ä¿Áö°Å³ª dp ¹è¿­ÀÇ °ø°£º¹Àâµµ°¡ ±âÁØ ÀÌ»óÀ¸·Î Ä¿Áö´Â °æ¿ì°¡ ÀÖ´Â µí ÇÏ´Ù.
-ÀÌ·² °æ¿ì¿¡´Â ±×³É ºÎºÐ ¹®Á¦¸¦ ±×´ë·Î µÎ°í Á÷Á¢ ¿©·¯°¡Áö Á¶ÇÕµéÀ» °è»êÀ» ÇÒ ¼ö ¹Û¿¡ ¾ø´Ù. (¹°·Ð ÀÌ·¸°Ô ÇßÀ» ¶§¿¡´Â ½Ã°£º¹Àâµµ°¡ ±âÁØÀ» ³ÑÁö¾Ê´Â´Ù¸é)
-±×·¯³ª, ±× °è»ê ÇÏ´Â ºÎºÐÀ» ¶Ç ´Ù¸¥ Àç±Í ÇÔ¼ö¸¦ Á¤ÀÇÇÏ¿© ¿ÏÀüÅ½»ö(¹éÆ®·¡Å·)À¸·Î ±¸ÇöÇÏ¸é µÇ°í ±× Àç±Í ÇÔ¼ö ³»¿¡¼­ ³¡(±âÀú)¿¡ µµ´ÞÇß´Ù¸é
-±× Àç±Í ÇÔ¼ö¿¡¼­ dp ÇÔ¼ö¸¦ ¼­ºêÈ£ÃâÇÏ¿© ¹ÝÈ¯ÇÏ´Â ½ÄÀ¸·Î ±¸ÇöÇÏ¸é ±¸ÇöÀÌ ÈÎ¾À °£ÆíÇØÁø´Ù. ±×¸®°í ¸¸¾à ±× Àç±ÍÇÔ¼ö³»¿¡ Æ¯Á¤ Á¶°Ç¿¡ ÀÇÇØ
-°¡Áö¸¦ Ä¥ °ÍÀÌ ¸¹´Ù¸é ¹éÆ®·¡Å·À¸·Î ¼Óµµ°¡ ÈÎ¾À »¡¶óÁø´Ù.
-BOJ¿¡¼­ ºÎºÐ¹®Á¦¸¦ ¼¼ºÐÈ­ ÇÏ´Â ¹®Á¦·Î´Â 'µµ·Î °Ç¼³', 'Æ®¸® ³ª¶ó' °¡ ÀÖ°í, ¼¼ºÐÈ­ÇÏÁö ¾Ê°í ¶Ç ´Ù¸¥ Àç±Í ÇÔ¼ö¸¦ Á¤ÀÇÇÏ¿© ¹éÆ®·¡Å·À¸·Î Çª´Â ¹®Á¦´Â
-'ºí·° ½×±â' °¡ ÀÖ´Ù.
-
-±×¸®°í ºí·° ½×±â¿¡¼­ ÁÖ¾îÁø ³ôÀÌÀÇ ºí·Ïµé¸¸ÀÌ ¾Æ´Ï¶ó ÁÖ¾îÁø ³ôÀÌ ÀÌÇÏÀÇ °¡´ÉÇÑ ¸ðµç ´äÀ» ¿ä±¸ÇÏ´Âµ¥ ÀÌ°Ç µû·Î °¢°¢ÀÇ ³ôÀÌ¿¡ ´ëÇØ ´õÇØÁÙ ÇÊ¿ä°¡¾ø´Ù.
-Ã³À½¿¡ ÀÌ°ÍÀ» ¸ô¶ó¼­ ¸Å¿ì Çì¸Ì´Âµ¥, Á¶±Ý¸¸ ´õ »ý°¢ÇØº¸¸é 2Ãþ¿¡¼­ ºóÄ­À¸·Î 3ÃþÀ» ´õ ½×À¸¸é 5ÃþÀÌ±â ¶§¹®¿¡ °á±¹ 2Ãþµµ 5ÃþÀÎ°ÍÀÌ´Ù. Áï ½ÇÁ¦·Î´Â 
-2Ãþ±îÁö¸¸ ½×°í ÀÌÈÄ¿¡´Â ºóÄ­À¸·Î¸¸ ½×¾Æ¿Ã·Áµµ °á±¹ ±âÀú(²À´ë±â ³ôÀÌ)±îÁö ¿Ã¶ó°¡±â¶§¹®¿¡ 2Ãþµµ 5ÃþÀ¸·Î ÇÔ²² °è»êÇØÁÖ°Ô µÇ´Â°ÍÀÌ´Ù.
-°á±¹ ¾È½×´Â°Í, Áï ºó ºí·Ï È¤Àº Åõ¸í ºí·ÏÀ» ½×´Â °Íµµ ºí·ÏÀ» ½×´Â °ÍÀÌ±â ¶§¹®¿¡ µû·Î ÁÖ¾îÁø Ãþº¸´Ù ³·Àº ´äÀ» °è»êÇØ ÁÙ ÇÊ¿ä°¡¾ø´Â°ÍÀÌ´Ù.
-¿ÀÈ÷·Á ÀÌ ¹®Á¦¿¡¼­ ¸Ç ¸¶Áö¸· Ãþ±îÁö ½×ÀÎ ºí·ÏÀÇ °¡Áþ¼ö ¸¸À» ¹¯´Â´Ù¸é ±âÀú¿¡ µµ´ÞÇßÀ»¶§(h(ÇöÀç³ôÀÌ)==H(ÁÖ¾îÁø³ôÀÌ) ÀÏ¶§) prvState(¾Æ·¡Ãþ¿¡ ºí·Ï³õÀÎÇöÈ²)
-ÀÌ 0ÀÌ ¾Æ´ÑÁö¸¦ ÆÇ´ÜÇÏ¿© 0ÀÌ¾Æ´Ï¶ó¸é return 1; 0ÀÌ¶ó¸é return 0; À» ÇÏ¸é µÉ°ÍÀÌ´Ù. ¿Ö³ÄÇÏ¸é ¹Ù·Î ¾Æ·¡Ãþ¿¡ ºí·ÏÀÌ ÇÏ³ª¶óµµ ÀÖ´Ù´Â°ÍÀº ±× ¾Æ·¡Ãþµµ
-¿ÏÀüÈ÷ ºñ¾îÀÖÁö ¾Ê´Ù´Â ¶æÀÌ°í(±× ºí·ÏÀ» ¹ÞÃÄ¾ß ÇÏ´Ï±î) ±× ¾Æ·¡Ãþµµ ¸¶Âù°¡ÁöÀÌ°í... ÂßÂßÂßÂß ³»·Á°¡´Ùº¸¸é °á±¹ »çÀÌ¿¡ ºó ÁÙÀÌ ¾øÀÌ
-²À´ë±â±îÁö ¿Ã¶ó¿Ô´Ù´Â°Å´Ï±î ÁÖ¾îÁø ³ôÀÌÀÇ ºí·ÏÀÎ °æ¿ì¶ó´Â ¸»ÀÌ µÇ±â¶§¹®ÀÌ´Ù.
\ No newline at end of file
diff --git "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 10\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt" "b/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 10\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt"
deleted file mode 100644
index ac390b2..0000000
--- "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 10\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt"	
+++ /dev/null
@@ -1,23 +0,0 @@
-persistent segtree ´Â Æ®¸®¿¡¼­ ·çÆ®¿¡¼­ºÎÅÍ ´Ù¸¥ ¸ðµç ³ëµå±îÁöÀÇ °æ·Î»óÀÇ Á¤º¸¸¦ ÀúÀåÇØ¾ßÇÒ¶§
-¸ðµç ³ëµå¿¡ ´ëÇØ ÀúÀåÇÏ·Á¸é ½Ã°£,°ø°£ º¹Àâµµ°¡ n^2 ÀÌ´Ù. ±×·±µ¥ Àßº¸¸é
-ºÎ¸ð ³ëµå±îÁöÀÇ Á¤º¸¿¡¼­ ÇÑ³ëµå¸¸ Ãß°¡µÇ´Â°ÍÀÌ±â¶§¹®¿¡  
-
-LR max flow ´Â sink ¿¡¼­ source ·Î °¡´Â capacity ¹«ÇÑ´ëÀÇ °¡»óÀÇ °£¼±À» ÀÌ¾îÁà¼­ LR circulation À»
-¸¸Á·ÇÏ´ÂÁö º¸°í(¸¸Á·ÇÏÁö ¾Ê´Â´Ù¸é ºÒ°¡´ÉÇÑ°Å) ¸¸Á·ÇÑ´Ù¸é LR circulation ¿¡¼­ max Flow + ¸ðµç ÇÏÇÑ µéÀÇÇÕ
-ÀÌ ´äÀÌ´Ù.
-±×·±µ¥ LR circulation ¿¡¼­ max Flow ´Â ¾î¶»°Ô ±¸ÇÏ³Ä¸é ¸ðµç °£¼±µéÀÇ capacity¸¦ R-L ·Î ¹Ù²ãÁÖ°í
-°¡»óÀÇ source ¸¦ ¸¸µé¾î¼­ °£¼±µé¿¡ ´ëÇØ º¸³»´ÂÂÊÀÇ ³ëµå¿¡°Ô´Â °¡»óÀÇ source ¿¡¼­ L ¸¸Å­ º¸³»Áà¼­
-LÀÌ Èå¸£°Ô º¸ÀåÇØÁÖ°í ¹Þ´ÂÂÊÀÇ ³ëµå °¡»óÀÇ sink °¡ L¸¸Å­ È¸¼öÇØ°¡°Ô ÇØÁØµÚ ÀÌ ±×·¡ÇÁ¿¡¼­
-max flow ¸¦ ±¸ÇØ¼­ ±×°Ô ¸ðµç LÀÇ ÇÕ°ú °°À¸¸é LR circulation À» ¸¸Á·ÇÏ´Â°ÍÀÓ
-
-º¸Åë n^2 ¿¡ °è»êÇÏ´Â°ÍÀ» nlgn À¸·Î ¹Ù²ã¾ßÇÒ¶© ÁÖ·Î ºÐÇÒÁ¤º¹À¸·Î Ç°(°¡Àå °¡±î¿î µÎÁ¡, ¼ö¿­ µÚÁý±â?)
-ÈçÈ÷ ±×³É ¾î·Á¿î¹®Á¦µéµµ ºÐÇÒÁ¤º¹À¸·Î ¸¹ÀÌÇ®¼öÀÖÀ½
-±×·¡¼­ Æ®¸®¿¡¼­ Äõ¸®¸¦ ³¯¸±¶§ centroid ¸¦ Áß½ÉÀ¸·Î Àç±ÍÀûÀ¸·Î ºÐÇÒÁ¤º¹À¸·Î ³ª´©¸éµÊ
-°æ·ÎÀÇ ÇÕÀÌ KÀÎ °Å Ã£À»¶§ centroid ·ÎÇÔ
-(centroid ´Â Æ®¸®¿¡¼­ n^2À¸·Î °è»êÇØ¾ßÇÏ´Â°ÍÀ» nlgn À¸·Î ÇÒ¼öÀÖµµ·ÏÇØÁÜ)
-ºÐÇÒÁ¤º¹Àº ¹è¿­¿¡¼­ È¿°úÀûÀÎ¸¸Å­ Æ®¸®¿¡¼­µµ À¯¿ëÇÔ. Æ®¸®¿¡¼­´Â Àü¹ÝÀûÀ¸·Î ´Ù ¾î·Æ±â¶§¹®
-
-Æ®¸®¿¡¼­ path query ¸¦ ÇÒ¶© º¸Åë dfs ordering À¸·Î Æ®¸®¸¦ Æì°Å³ª HLD ¸¦ »ç¿ëÇÑ´Ù.
-centroid ·Î´Â Á» ºÒÆíÇÔ
-
-HLD ³ª persistent segtree ´Â ´Ù path ¿¡ ´ëÇÑ ¾Ë°í¸®ÁòÀÓ
\ No newline at end of file
diff --git "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 1\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt" "b/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 1\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt"
deleted file mode 100644
index 42c79db..0000000
--- "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 1\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt"	
+++ /dev/null
@@ -1,11 +0,0 @@
-Áß±Þ¹Ý¿ÀÀüD¹ø
-i¹ø µµ½Ã¿¡¼­ j¹ø µµ½Ã·Î ÃÑ a°³ÀÇ µµ½Ã¸¦ ¹æ¹®ÇÏ¿©(Ãâ¹ß,µµÂøÁöÆ÷ÇÔ) µµÂøÇÏ´Â ÃÖ´Ü°æ·Î(k´Â °æÀ¯µµ½Ã)
-dp[i][j][a] = dp[i][k][a-1] + dist[k][j]
-ÀÎµ¥ ¹®Á¦»ó¿¡¼­ Ãâ¹ß ÁöÁ¡ÀÌ Á¤ÇØÁ®ÀÖÁö¾Ê±â ¶§¹®¿¡
-dp ¹è¿­¿¡¼­ Ãâ¹ßÁö [i] ¸¦ ¶¿¼ö°¡ÀÖÀ½. Áï 2Â÷¿øÀ¸·Î ÇÏ¿© °ø°£º¹Àâµµ´Â N^2, ½Ã°£º¹Àâµµ´Â N^3°¡µÊ(ÇÑÂ÷¿ø¾¿ ÁÙ¾îµë)
-Áï dp[j][a] = dp[k][a-1] + dist[k][j]
-
-Áß±Þ¹Ý¿ÀÈÄB¹ø
-¸ðµç ¼ö¿¡¼­ 1À»»«µÚ °°ÀºÇà³¢¸®´Â ¸òÀÌ °°Àº¿­³¢¸®´Â ³ª¸ÓÁö°¡ °°¾Æ¾ßÇÔ
-Àý´ë·Î ¼¯¾úÀ»¶§ °°ÀºÇàÀÌ¾ú´ø ¼öµéÀÇ ÇàÀÌ ´Þ¶óÁú¼ö°¡¾øÀ½(ÅëÂ°·Î ¿Å±â±â¶§¹®¿¡) ,¿­µµ¸¶Âù°¡Áö
-
diff --git "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 2\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt" "b/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 2\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt"
deleted file mode 100644
index a12ab8f..0000000
--- "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 2\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt"	
+++ /dev/null
@@ -1,11 +0,0 @@
-BFS¿¡¼­ »óÅÂ·Î ³ª´©µí dp¿¡¼­µµ Á¡È­½ÄÀÌ »óÅÂ¸¦ ³ªÅ¸³¿
-°¢°¢ÀÇ »óÅÂ°¡ À¯ÀÏÇÏ°Ô ¸¸µé±âÀ§ÇØ Á¶°ÇÀ» ÇÏ³ªÀÇ Â÷¿øÀ¸·Î ³ÖÀ½
-(ÁÖ·Î ¿¬¼ÓµÇ¾î¼­ ³ª¿Ã¼ö¾ø°Å³ª ±×·± Á¶°ÇÀ» Á¡È­½ÄÀÇ ÇÏ³ªÀÇ Â÷¿øÀ¸·Î Ãß°¡)
-
-Ãâ±Ù±â·Ï¹®Á¦¿¡¼­ A´Â dp Á¡È­½Ä¿¡ Ãß°¡ÇÏÁö¾Ê°í A¸¦ ¾ø¾Ù¼ö°¡ÀÖÀ½
-B,CÀÇ °³¼ö¿Í ¸¶Áö¸·¿¡ BBÀÎÁö BCÀÎÁö CCÀÎÁö CBÀÎÁö¸¦ º¸´Â½ÄÀ¸·Î?
-
-¿¬ÈÞ
-°¢°¢ÀÇ ÇÏ³ªÀÇ µµ·Î¿¡ ´ëÇØ ¸ðµç °¡Á·ÀÌ »ç¿ëÇÒ È®·üÀ» ±¸ÇÑµÚ ¸ðµçµµ·Î¿¡ ´ëÇØ ÀÌ°É±¸ÇØ¼­ ´õÇÔ
-
-±â´ë°ªdp´Â °æ¿ìÀÇ¼öÀÇÇÕ/ÀüÃ¼ ÀÎµ¥ °æ¿ìÀÇ¼öÀÇÇÕÀ» DP·Î ±¸ÇÔ
\ No newline at end of file
diff --git "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 3\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt" "b/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 3\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt"
deleted file mode 100644
index 3c0df5d..0000000
--- "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 3\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt"	
+++ /dev/null
@@ -1,2 +0,0 @@
-¼Ò¼ö ÀÌ(»ï)ºÐÅ½»öÇÒ¶§ ¼Ò¼öÁ¡ ¾ó¸¶ ÀÌÇÏ·Î µ¹¸®Áö¸»°í ±×³É 10000¹øÁ¤µµ µ¹¸®ÀÚ
-100¹ø µ¹¸®¸é ¿ÀÂ÷°¡ ¼Ò¼öÁ¡ 1e-18 ±îÁö ³»·Á°£´Ù°í ÇÑ´Ù
diff --git "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 5\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt" "b/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 5\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt"
deleted file mode 100644
index 6f15b19..0000000
--- "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 5\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt"	
+++ /dev/null
@@ -1,2 +0,0 @@
-DAG À§»óÁ¤·Ä ²÷À»¶§ »çÀü¼ø,¼ýÀÚÀÛÀº¼ø µîÀ¸·Î ²÷¾î¾ßÇÏ¸é º¹Àâµµ°¡ ÇÑÂ÷¿ø Áõ°¡ÇÏ±â¶§¹®¿¡
-NÁ¦ÇÑÀÌ Å¬¶© priority queue ¸¦ ¾²¸é µÈ´Ù.
\ No newline at end of file
diff --git "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 9\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt" "b/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 9\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt"
deleted file mode 100644
index 0cde080..0000000
--- "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\204 9\354\235\274\354\247\270 \353\260\260\354\232\264\352\261\260.txt"	
+++ /dev/null
@@ -1,7 +0,0 @@
-long long À¸·Î ÇØ¾ßÇÒ °ÍÀ» double ·Î ÇÏ¸é ¿ÀÂ÷°¡ »ý±ä´Ù
-n^2 ²ÃÀÎ Á¤¼öÀÎÁö È®ÀÎÇÒ¶§ sqrt(n)*sqrt(n) == n ÀÎÁö º¸¸é ¿ÀÂ÷¶§¹®¿¡ Æ²¸°°æ¿ì°¡ÀÖÀ¸¹Ç·Î
-(sqrt(n)+1)*(sqrt(n)+1) ¿Í (sqrt(n)-1)*(sqrt(n)-1) µµ ºÁÁà¾ßÇÔ ÃÑ ¼¼°³ºÁÁà¾ßÇÔ
-
-ÇÇÅ¸°í¶ó½ºÀÇ ¼ö¿¡¼­ ºøº¯ÀÌ ¾Æ´Ñ µÎ º¯Àº ¹«Á¶°Ç ÇÏ³ª´Â Â¦¼ö, ÇÏ³ª´Â È¦¼ö¿©¾ßÇÔ
-
-Á¤¼ö »ïºÐÅ½»ö¿¡¼­ ³»ºÐÇÒ¶§ (lo*2+hi)/3 ¶û (lo+hi*2)/3 ·Î ÇØ¾ß ÇÔ
\ No newline at end of file
diff --git "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\2046\354\235\274\354\247\270 \355\225\264\354\273\244\354\273\265\354\227\220\354\204\234 \353\260\260\354\232\264\352\261\260.txt" "b/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\2046\354\235\274\354\247\270 \355\225\264\354\273\244\354\273\265\354\227\220\354\204\234 \353\260\260\354\232\264\352\261\260.txt"
deleted file mode 100644
index 4bc992e..0000000
--- "a/\354\225\214\352\263\240\353\246\254\354\246\230 \353\260\260\354\232\264\354\240\220\353\223\244/\354\272\240\355\224\2046\354\235\274\354\247\270 \355\225\264\354\273\244\354\273\265\354\227\220\354\204\234 \353\260\260\354\232\264\352\261\260.txt"	
+++ /dev/null
@@ -1,2 +0,0 @@
-·òÄ«ÀÇ Á¤¸®(Lucas Theorem)
-ÀÌÇ×°è¼ö ºü¸£°Ô±¸ÇÒ¶§ »ç¿ëÇÔ
\ No newline at end of file
diff --git "a/\354\247\200\355\230\270\354\275\224\353\223\234.cc" "b/\354\247\200\355\230\270\354\275\224\353\223\234.cc"
deleted file mode 100644
index 2f2256d..0000000
--- "a/\354\247\200\355\230\270\354\275\224\353\223\234.cc"
+++ /dev/null
@@ -1,46 +0,0 @@
-#include <iostream>
-#include <stack>
-#include <vector>
-#include <algorithm>
-
-using namespace std;
-
-int main() {
-   int inp[105][105] = { 0, };
-   int ans[105][105] = { 0, };
-
-   stack<pair<int, int>> s;
-
-   int N; cin >> N;
-
-   for (int i = 0; i < N; i++) {
-      for (int j = 0; j < N; j++) {
-         cin >> inp[i][j];
-         if (inp[i][j] == 1) s.push({ i,j });
-      }
-   }
-
-   while (!s.empty()) {
-         int here = s.top().first;
-         int next = s.top().second;
-         s.pop();
-         if(ans[here][next]) continue;
-         ans[here][next] = 1;
-
-         if (here == next) continue;
-
-         for (int i = 0; i < N; i++) {
-            if (inp[next][i] == 1) {
-               s.push({ here, i });
-            }
-         }
-
-      }
-
-   for (int i = 0; i < N; i++) {
-      for (int j = 0; j < N; j++) {
-         cout << ans[i][j] << ' ';
-      }
-      cout << endl;
-   }
-}
\ No newline at end of file
diff --git "a/\354\272\240\355\224\204/4\354\235\274\354\260\250/\354\272\240\355\224\2044\354\235\274\354\260\250(\355\224\214\353\240\210\354\235\264\353\246\254\354\212\244\355\212\270).cc" "b/\354\272\240\355\224\204/4\354\235\274\354\260\250/\354\272\240\355\224\2044\354\235\274\354\260\250(\355\224\214\353\240\210\354\235\264\353\246\254\354\212\244\355\212\270).cc"
new file mode 100644
index 0000000..7adb312
--- /dev/null
+++ "b/\354\272\240\355\224\204/4\354\235\274\354\260\250/\354\272\240\355\224\2044\354\235\274\354\260\250(\355\224\214\353\240\210\354\235\264\353\246\254\354\212\244\355\212\270).cc"
@@ -0,0 +1,16 @@
+#include <cstdio>
+const int MOD = 1e9+7;
+long long dp[101][101];
+int N,M,P;
+int main() {
+	scanf("%d%d%d",&N,&M,&P);
+	dp[0][0]=1;
+	for(int i = 1; i <= P; i++){
+		for(int j = 0; j <= N; j++){
+			if(j > 0) (dp[i][j] += dp[i-1][j-1] * (N-j+1)) %= MOD;
+			if(j > M) (dp[i][j] += dp[i-1][j] * (j-M)) %= MOD;
+		}
+	}
+	printf("%lld",dp[P][N]);
+	return 0;
+}
diff --git "a/\354\272\240\355\224\204/6\354\235\274\354\260\250/\354\272\240\355\224\2046\354\235\274\354\260\250(\353\221\220 \354\210\230\354\235\230 \352\263\261).cc" "b/\354\272\240\355\224\204/6\354\235\274\354\260\250/\354\272\240\355\224\2046\354\235\274\354\260\250(\353\221\220 \354\210\230\354\235\230 \352\263\261).cc"
new file mode 100644
index 0000000..469101e
--- /dev/null
+++ "b/\354\272\240\355\224\204/6\354\235\274\354\260\250/\354\272\240\355\224\2046\354\235\274\354\260\250(\353\221\220 \354\210\230\354\235\230 \352\263\261).cc"	
@@ -0,0 +1,16 @@
+#include <cstdio>
+#include <cmath>
+using namespace std;
+int A,B,C;
+int a,b,c;
+int main() {
+	int ans=INF;
+	scanf("%d%d%d",&a,&b,&c);
+	for(int i = 1; i <= 4000000; i++){
+		for(int j = 1; i*j<=a+b+2*c-3; j++){
+			ans=min(ans,abs(a-i)+abs(b-j)+abs(c-i*j));
+		}
+	}
+	printf("%d",ans);
+	return 0;
+}
diff --git "a/\354\272\240\355\224\2046\354\235\274\354\260\250(\353\270\224\353\237\255 \354\214\223\352\270\260).cc" "b/\354\272\240\355\224\204/6\354\235\274\354\260\250/\354\272\240\355\224\2046\354\235\274\354\260\250(\353\270\224\353\237\255 \354\214\223\352\270\260).cc"
similarity index 100%
rename from "\354\272\240\355\224\2046\354\235\274\354\260\250(\353\270\224\353\237\255 \354\214\223\352\270\260).cc"
rename to "\354\272\240\355\224\204/6\354\235\274\354\260\250/\354\272\240\355\224\2046\354\235\274\354\260\250(\353\270\224\353\237\255 \354\214\223\352\270\260).cc"
diff --git "a/\354\272\240\355\224\2046\354\235\274\354\260\250(\354\230\201\354\204\240\354\235\264\354\235\230 \354\203\235\354\235\274).cc" "b/\354\272\240\355\224\2046\354\235\274\354\260\250(\354\230\201\354\204\240\354\235\264\354\235\230 \354\203\235\354\235\274).cc"
new file mode 100644
index 0000000..dfe5990
--- /dev/null
+++ "b/\354\272\240\355\224\2046\354\235\274\354\260\250(\354\230\201\354\204\240\354\235\264\354\235\230 \354\203\235\354\235\274).cc"	
@@ -0,0 +1,203 @@
+// #include <bits/stdc++.h>
+// #include <iostream>
+#include <unordered_set>
+// #include <unordered_map>
+#include <vector>
+#include <cstdio>
+#include <cstring>
+#include <queue>
+// #include <set>
+// #include <map>
+#include <cmath>
+#include <algorithm>
+#include <utility>
+#include <string>
+#define REP(i,a,b) for(int i=a;i<=b;++i)
+#define FOR(i,n) for(int i=0;i<n;++i)
+#define pb push_back
+#define all(v) (v).begin(),(v).end()
+#define sz(v) ((int)(v).size())
+#define inp1(a) scanf("%d",&a)
+#define inp2(a,b) scanf("%d%d",&a,&b)
+#define inp3(a,b,c) scanf("%d%d%d",&a,&b,&c)
+#define inp4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
+#define inp5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
+using namespace std;
+typedef long long ll;
+typedef pair<ll,ll> pll;
+typedef vector<int> vi;
+typedef vector<ll> vl;
+typedef pair<int,int> pii;
+typedef vector<pii> vii;
+typedef vector<pll> vll;
+typedef vector<vector<int> > vvi;
+typedef pair<int,pair<int,int> > piii;
+typedef vector<piii> viii;
+const double EPSILON = 1e-9;
+const double PI = acos(-1);
+const int MOD = 1e9+7;
+const int INF = 0x3c3c3c3c;
+const long long INFL = 0x3c3c3c3c3c3c3c3c;
+const int MAX_N = 5200;
+
+struct Point{int x,y;};
+vector<int> sortedX, sortedY;
+int newX[10], newY[10];
+Point straw[3], cherry[3], candle;
+unordered_set<int> usX, usY;
+int N,M,S,T;
+int dy[]={-1,1,0,0};
+int dx[]={0,0,1,-1};
+vector<int> G[MAX_N];
+int iter[MAX_N],parent[MAX_N],flow[MAX_N][MAX_N],cap[MAX_N][MAX_N],level[MAX_N];
+bool isCandle(int i, int j){return i==candle.x&&j==candle.y;}
+bool inRange(int i, int j){return 0<=i&&i<N&&0<=j&&j<M;}
+int IN(int x){return 2+x;}
+int OUT(int x){return 2+N*M+x;}
+void connect(int a, int b){
+	G[a].push_back(b);
+	G[b].push_back(a);
+	cap[a][b]=1;
+}
+int trans(int i, int j){return i*M+j;}
+// bool isObj(int i, int j){
+// 	FOR(k,3) if(straw[k].x==i&&straw[k].y==j) return true;
+// 	FOR(k,3) if(cherry[k].x==i&&cherry[k].y==j) return true;
+// 	return candle.x==i&&candle.y==j;
+// }
+void makeGraph(){
+	FOR(i,N){
+		FOR(j,M){
+			FOR(k,4){
+				int ni = i+dy[k], nj = j+dx[k];
+				if(!inRange(ni,nj)) continue;
+
+				connect(OUT(trans(i,j)),IN(trans(ni,nj)));
+			}
+			if(!isCandle(i,j)) connect(IN(trans(i,j)),OUT(trans(i,j)));
+		}
+	}
+}
+
+int dfs(int here){
+	if(here==T) return 1;
+	for(int& i = iter[here]; i < G[here].size(); ++i){
+		int there=G[here][i];
+		if(cap[here][there]-flow[here][there]>0 && level[here]+1 == level[there]){
+			parent[there]=here;
+			if(dfs(there)) return 1;
+		}
+	}
+	return 0;
+}
+
+int dinic(){
+	int ret=0;
+	while(1) {
+		memset(level,-1,sizeof(level));
+		level[S]=0;
+		queue<int> q;
+		q.push(S);
+		while(!q.empty() && level[T] == -1) {
+			int here = q.front();
+			q.pop();
+			for(auto& there : G[here]){
+				if(cap[here][there]-flow[here][there]>0 && level[there] == -1){
+					level[there]=level[here]+1;
+					q.push(there);
+				}
+			}
+		}
+		if(level[T] == -1) break;
+		memset(iter,0,sizeof(iter));
+
+		while(1){
+			memset(parent,-1,sizeof(parent));
+			parent[S]=0;
+			if(!dfs(0)) break;
+			int minFlow=INF;
+			for(int p = 1; p!=parent[p]; p = parent[p]){
+				minFlow = min(minFlow, cap[parent[p]][p]-flow[parent[p]][p]);
+			}
+
+			for(int p = 1; p!=parent[p]; p = parent[p]){
+				flow[parent[p]][p] += minFlow;
+				flow[p][parent[p]] -= minFlow;
+			}
+			ret+=minFlow;
+		}
+	}
+	return ret;
+}
+
+int main() {
+	scanf("%d%d",&N,&M);
+	
+	scanf("%d%d",&candle.x,&candle.y);
+	candle.x--,candle.y--;
+	if(!usX.count(candle.x)) sortedX.push_back(candle.x);
+	if(!usY.count(candle.y)) sortedY.push_back(candle.y);
+
+	for(int i = 0; i < 3; i++) {
+		scanf("%d%d",&straw[i].x,&straw[i].y);
+		straw[i].x--,straw[i].y--;
+		if(!usX.count(straw[i].x)) usX.insert(straw[i].x), sortedX.push_back(straw[i].x);
+		if(!usY.count(straw[i].y)) usY.insert(straw[i].y), sortedY.push_back(straw[i].y);
+	}
+	for(int i = 0; i < 3; i++) {
+		scanf("%d%d",&cherry[i].x,&cherry[i].y);
+		cherry[i].x--,cherry[i].y--;
+		if(!usX.count(cherry[i].x)) usX.insert(cherry[i].x), sortedX.push_back(cherry[i].x);
+		if(!usY.count(cherry[i].y)) usY.insert(cherry[i].y), sortedY.push_back(cherry[i].y);
+	}
+	sort(all(sortedX)), sort(all(sortedY));
+	
+	newX[0] = sortedX[0]>3 ? 3 : sortedX[0];
+	for(int i = 0; i < sz(sortedX)-1; i++){
+		int diff = sortedX[i+1]-sortedX[i];
+		if(diff > 4) diff=4;
+		newX[i+1]=newX[i]+diff;
+	}
+	
+	newY[0] = sortedY[0]>3 ? 3 : sortedY[0];
+	for(int i = 0; i < sz(sortedY)-1; i++){
+		int diff = sortedY[i+1]-sortedY[i];
+		if(diff > 4) diff=4;
+		newY[i+1]=newY[i]+diff;
+	}
+
+	int pos;
+	for(int i = 0; i < 3; i++){
+		pos = lower_bound(all(sortedX),straw[i].x) - sortedX.begin();
+		straw[i].x=newX[pos];
+		pos = lower_bound(all(sortedY),straw[i].y) - sortedY.begin();
+		straw[i].y=newY[pos];
+	}
+
+	for(int i = 0; i < 3; i++){
+		pos = lower_bound(all(sortedX),cherry[i].x) - sortedX.begin();
+		cherry[i].x=newX[pos];
+		pos = lower_bound(all(sortedY),cherry[i].y) - sortedY.begin();
+		cherry[i].y=newY[pos];
+	}
+
+	pos = lower_bound(all(sortedX),candle.x) - sortedX.begin();
+	candle.x=newX[pos];
+	pos = lower_bound(all(sortedY),candle.y) - sortedY.begin();
+	candle.y=newY[pos];
+	
+
+	int diff = N-sortedX.back();
+	N = newX[sz(sortedX)-1]+(diff>3?3:diff);
+	diff = M-sortedY.back();
+	M = newY[sz(sortedY)-1]+(diff>3?3:diff);
+
+	S=0,T=1;
+	makeGraph();
+	FOR(i,3){
+		connect(S,IN(trans(straw[i].x,straw[i].y)));
+		connect(OUT(trans(cherry[i].x,cherry[i].y)),T);
+	}
+	printf("%s", dinic()==3?"Yes":"No");
+	return 0;
+}
warning: LF will be replaced by CRLF in input.txt.
The file will have its original line endings in your working directory.
