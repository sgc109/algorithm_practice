struct Number{
    vector<int> v;
    Number(vector<int> init){
        v = init;
    }
    Number(int size){
        v = vector<int>(size, 0);
    }
    Number operator+(Number& rhs) {
        vector<int> retV;
        int szA = sz(v), szB = sz(rhs.v);
        for(int i = 0; i < max(szA, szB); i++){
            int l = (i < szA ? v[i] : 0);
            int r = (i < szB ? rhs.v[i] : 0);
            retV.pb(l + r);
        }
        retV.pb(0);
        for(int i = 0; i < sz(retV) - 1; i++) {
            retV[i + 1] += retV[i] / 10, retV[i] %= 10;
        }
        if(retV.back() == 0) retV.pop_back();
        Number ret(retV);
        return ret;
    }
    void print(){
        for(int i = sz(v) - 1; i >= 0; i--) cout << v[i];
    }
};
