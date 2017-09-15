#include <bits/stdc++.h>
using namespace std;
int main() {
	set<int> st({1,1,1,1,2,2,2,3,3,4,4,5,6,7,7,7,7,8,8,9,9,9});
	vector<int> v;
	v.assign(st.begin(), st.end());
	for(int i = 0 ; i < v.size(); i++) printf("%d ",v[i]);

	return 0;
}
