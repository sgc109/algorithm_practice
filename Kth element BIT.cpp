const int MAXN;
int kth(int k){
   int idx = 0;
   for(int i=20; i>=0; i--){
       if(idx + (1<<i) < MAXN && tree[idx+(1<<i)] < k){
           idx += (1<<i);
           k -= tree[idx];
       }
   }
   return idx+1;
}