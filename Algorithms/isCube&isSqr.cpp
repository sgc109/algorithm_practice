bool isCube(ll x){
	ll lo = 1, hi = 1e6 + 1;
	while(lo < hi){
		ll mid = (lo + hi) / 2;
		if(mid * mid * mid >= x) hi = mid;
		else lo = mid + 1;
	}
	return lo * lo * lo == x;
}

bool isSqr(ll x){
	ll lo = 1, hi = 1e6 + 1;
	while(lo < hi){
		ll mid = (lo + hi) / 2;
		if(mid * mid >= x) hi = mid;
		else lo = mid + 1;
	}
	return lo * lo == x;
}