#include <stdio.h>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
#define MaxN 1000
#define MaxR 100
#define MaxT 500
int N, R, D;
struct point {
    int x, y, index;
    bool friend operator < (point a, point b) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    }
} Frog[MaxN];
int tmp[2 * MaxN];
int interval[2 * MaxN], size;
int Tree[MaxT + 1], T;
vector <int> connected[MaxN];
int queue[MaxN], visit[MaxN], head, tail;
int find_index(int a)
{
    int left = 0, right = size - 1;
    int middle;
    while (left <= right) {
        middle = (left + right) / 2;
        if (interval[middle] == a) break;
        if (interval[middle]<a) left = middle + 1;
        else right = middle - 1;
    }
    return middle;
}
int find_rightmost(int a)
{
    int max = -1;
    while (a>0) {
        if (max<Tree[a]) max = Tree[a];
        a /= 2;
    }
    return max;
}
void insert_edge(int a, int b)
{
    connected[a].push_back(b);
    connected[b].push_back(a);
}
void renew_tree(int left, int right, int value)
{
    while (left <= right) {
        Tree[left] = Tree[right] = value;
        left = (left + 1) / 2;
        right = (right - 1) / 2;
    }
}
void find_connection(void)
{
    int i;
    int a, b;
    for (i = 0; i<N; i++) {
        tmp[i] = Frog[i].y;
        tmp[i + N] = Frog[i].y + R;
    }
    sort(tmp, tmp + 2 * N);
    size = 1;
    interval[0] = tmp[0];
    
    for (i = 1; i<2 * N; i++) if (tmp[i] != tmp[i - 1])
        interval[size++] = tmp[i];
    
    for (T = 1; T<size; T *= 2);
    T = T * 2 - 1;
    
    for (i = 1; i <= T; i++)
        Tree[i] = -1;
    
    sort(Frog, Frog + N);
    
    for (i = 0; i<N; i++) {
        a = find_rightmost(T / 2 + find_index(Frog[i].y) + 1);
        b = find_rightmost(T / 2 + find_index(Frog[i].y + R) + 1);
        
        if (a != -1 && Frog[a].x + R + D >= Frog[i].x)
            insert_edge(Frog[a].index, Frog[i].index);
        
        if (b != -1 && Frog[b].x + R + D >= Frog[i].x)
            insert_edge(Frog[b].index, Frog[i].index);
        
        renew_tree(T / 2 + find_index(Frog[i].y) + 1, T / 2 + find_index(Frog[i].y + R) + 1, i);
    }
}
bool comp(point a, point b)
{
    return a.index < b.index;
}
int main()
{
    int i;
    int now, next;
    vector <int> ::iterator it;
    
    scanf("%d%d", &N, &R);
    for (i = 0; i<N; i++) {
        scanf("%d%d", &Frog[i].x, &Frog[i].y);
        Frog[i].index = i;
    }
    scanf("%d", &D);
    for (i = 0; i<N; i++)
        connected[i].clear();
    find_connection();
    for (i = 0; i<N; i++)
        Frog[i].x ^= Frog[i].y ^= Frog[i].x ^= Frog[i].y;
    
    find_connection();
    sort(Frog, Frog + N, comp);
    
    for (i = 0; i<N; i++)
        if (Frog[i].x == 0 && Frog[i].y == 0) break;
    
    queue[0] = i;
    visit[i] = true;
    tail = 1;
    
    while (head<tail) {
        now = queue[head++];
        for (it = connected[now].begin(); it != connected[now].end(); it++) {
            next = *it;
            if (visit[next]) continue;
            visit[next] = true;
            queue[tail++] = next;
        }
    }
    int ans = 0;
    for (i = 0; i<N; i++) {
        if (visit[i] && ans<Frog[i].x + Frog[i].y + 2 * R) {
            ans = Frog[i].x + Frog[i].y + 2 * R;
        }
    }
    printf("%d", ans);
    return 0;
}