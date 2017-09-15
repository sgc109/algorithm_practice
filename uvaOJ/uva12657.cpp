#include <bits/stdc++.h>

using namespace std;

int n,m;
struct List{
	int prev, next;
};
List lists[100003];
int head, tail;
int rev;
void move(int A, int B){
	if(A==B) return;
	lists[lists[A].next].prev = lists[A].prev;
	lists[lists[A].prev].next = lists[A].next;

	lists[A].prev = lists[B].prev;
	lists[A].next = B;

	lists[lists[B].prev].next = A;
	lists[B].prev = A;
}
void change(int A, int B){
	if(lists[A].next == B || lists[B].next == A){
		if(lists[B].next == A) swap(A, B);
		int prevB = lists[A].prev;

		lists[lists[A].prev].next = B;
		lists[lists[B].next].prev = A;
		lists[A].prev = B;
		lists[A].next = lists[B].next;
		lists[B].prev = prevB;
		lists[B].next = A;
		return;
	}
	int backup = lists[A].next;
	move(A, B);
	move(B, backup);
}

void print(){
	int pos = (rev ? tail : head);
	while(1){
		if(rev && pos == head) break;
		if(!rev && pos == tail) break;
		if(pos != head && pos != tail) printf("%d ",pos+1);
		if(rev) pos = lists[pos].prev;
		else pos = lists[pos].next;
	}
	printf("\n");
}
int main(){
	for(int t = 1; scanf("%d %d\n",&n, &m) != EOF; t++){
		head = n, tail = n+1;
		for(int i = 0 ; i < n ; i++){
			lists[i].prev = i-1;
			lists[i].next = i+1;
		}
		lists[0].prev = head;
		lists[n-1].next = tail;
		lists[head].next = 0;
		lists[tail].prev = n - 1;
		rev = 0;

		for(int i = 0 ; i < m ; i++){
			int op, a ,b;
			scanf("%d",&op);
			if(op == 4) rev ^= 1;
			else {
				scanf("%d%d",&a, &b);
				a--, b--;
				if(op == 1) move(a, rev ? lists[b].next : b );
				else if(op == 2) move(a, rev ? b : lists[b].next);
				else if(op == 3) change(a, b);
			}
		}
		long long ans = 0;
		int pos = (rev ? tail : head);
		int cnt = 0;
		while(1){
			if(rev && pos == head) break;
			if(!rev && pos == tail) break;

			if(pos != head && pos != tail && cnt % 2) ans += pos + 1;
			if(rev) pos = lists[pos].prev;
			else pos = lists[pos].next;
			cnt++;
		}
		printf("Case %d: %lld\n", t, ans);
	}
	return 0;
}