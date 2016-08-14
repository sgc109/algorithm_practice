const int MAX_N = 100000;
int t[2 * MAX_N];

void build()
{
	for(int pos=N-1; pos > 0; pos--)
		t[pos] = t[pos<<1] + t[pos<<1|1];
}

void modify(int pos, int val)
{
	for(t[pos += N] = val; pos > 1; pos >>= 1)
		t[pos >> 1] = t[pos] + t[pos^1];
}

int query(int l, int r)
{
	int ans = 0;
	for(l += N, r += N; l < r; l >>= 1, r >>= 1)
	{
		if(l & 1)
			ans += t[l++];
		if(r & 1)
			ans += t[--r];
	}
	return ans;
}
