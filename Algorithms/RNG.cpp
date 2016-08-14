struct RNG{
  int a, b;
    int seed;
    RNG(int _a, int _b) : a(_a), b(_b), seed(1983) {}
    int next() {
        int ret = seed;
        seed = ((seed*(long long)a)+b)%20090711;
        return ret;
    }
};