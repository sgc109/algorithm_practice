string plas(string A, string B){
	string ret;
	int lenA = sz(A), lenB = sz(B);
	if(lenA > lenB) swap(A, B), swap(lenA, lenB);
	reverse(all(A));
	reverse(all(B));
	int carry = 0;
	for(int i = 0 ; i < lenA; i++){
		int sum = A[i] -'0' + B[i] - '0' + carry;
		if(sum >= 10) carry = 1, sum -= 10;
		else carry = 0;
		ret += sum + '0';
	}

	for(int i = lenA; i < lenB; i++){
		int sum = B[i] - '0' + carry;
		if(sum >= 10) carry = 1, sum -= 10;
		else carry = 0;
		ret += sum + '0';
	}
	if(carry) ret += '1';
	reverse(all(ret));
	return ret;
}