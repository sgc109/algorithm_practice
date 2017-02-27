#include <stdio.h>
#include <malloc.h>
typedef long long ll;
struct RNG{
	ll seed;
	RNG():seed(1){}
	ll next(){
		ll ret = seed;
		seed = ((seed)*2012122327)%1000000007;
		return ret;
	}
};
template <class T> class vector{
	
};
int main(){
	RNG rng;

	return 0;
}