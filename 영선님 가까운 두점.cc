#include<stdio.h>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<math.h>
using std::vector;
struct point{
    long long x;
    long long y;
};
bool X(const point& a, const point& b){
    return a.x < b.x;
}

bool Y(const point& a, const point& b){
    return a.y < b.y;
}
long long dist(const point& a, const point& b){
    return (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
}
long long divide(const vector<point>& p){
    if (p.size() <= 2){
        if (p.size() == 2){
            return dist(p[0], p[1]);
        }
        return LLONG_MAX / 2;
    }

    vector<point> left(p.begin(), p.begin() + p.size() / 2);
    vector<point> right(p.begin() + p.size() / 2, p.end());

    long long ret = std::min(divide(left), divide(right));
    long long temp = sqrt(ret);

    long long x = (p.begin() + p.size() / 2)->x;
    vector<point> q;
    for (const point& po:p){
        if (po.x >= x - temp && po.x <= x + temp){
            q.push_back(po);
        }
    }
    std::sort(q.begin(), q.end(),Y);
    for (int i = 0; i < q.size(); i++){
        for (int j = i + 1; j < q.size(); j++){
            ret = std::min(ret, dist(q[i], q[j]));
            if (dist(q[i], q[j]) <= ret){
                break;
            }
        }
    }
    
    return ret;

}

int main(){
    vector<point> p;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        long long x, y;
        scanf("%lld%lld", &x, &y);
        p.push_back({ x, y });
    }
    std::sort(p.begin(), p.end(),X);
    printf("%lld", divide(p));
}