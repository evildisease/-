#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;

int n;

struct Node
{
    double x, y;
    Node() {}
    Node(double x, double y) : x(x), y(y) {}
    bool operator<(Node tmp)
    {
        return x < tmp.x;
    }
}v[maxn];

double getDis(Node a, Node b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double bruteForce()
{
    double res = inf * 1.0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            res = min(res, getDis(v[i], v[j]));
        }
    }
    return res;
}

Node Q[maxn];
double Divide(int l, int r)
{
    if (l == r)
        return inf * 1.0;
    int mid = (l + r) >> 1, tot = 0;
    double dis, midx = v[mid].x; 
    dis = min(Divide(l, mid), Divide(mid + 1, r));
    for (int i = l, j = mid + 1; (i <= mid || j <= r); i++)
    {
        while (j <= r && (v[i].y > v[j].y || i > mid))
            Q[tot++] = v[j], j++; 
        if (fabs(v[i].x - midx) < dis && i <= mid)
        { 
            for (int k = j - 1; k > mid && j - k < 3; k--)
                dis = min(dis, getDis(v[i], v[k]));
            for (int k = j; k <= r && k - j < 2; k++)
                dis = min(dis, getDis(v[i], v[k]));
        }
        if (i <= mid)
            Q[tot++] = v[i];
    }
    for (int i = l, j = 0; i <= r; i++, j++)
        v[i] = Q[j];
    return dis;
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        double x, y;
        cin >> x >> y;
        v[i] = Node(x, y);
    }
    sort(v + 1, v + n + 1);

    cout << "Brute force: " << bruteForce() << endl;
    cout << "Divide and conquer algorithm: " << Divide(1, n) << endl;
    
    return 0;
}
