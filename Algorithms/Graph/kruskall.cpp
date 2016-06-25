#include <iostream>
#include <queue>
#include <vector>
#include "ufds.cpp"

using namespace std;
using ii = pair<int, int>;
using edge = pair<int, ii>; // stores weight ( negative ), and vertices a -> b

priority_queue<edge> pq;

int kruskall(int V)
{
    UFDS ufds(V);
    int D = 0;
    
    while (not pq.empty())
    {
        auto e = pq.top();
        pq.pop();
        
        int w = -e.first;
        int u = e.second.first;
        int v = e.second.second;

        if (not ufds.same_set(u, v))
        {
            ufds.union_set(u, v);
            D += w;
        }
    }

    return D;
}

int main()
{
    
    int n,m,x,y,z;

    scanf("%d %d", &n, &m); // number of vertices and edges

    for ( int i = 0; i < m; i++ ){

        scanf("%d %d %d", &x, &y, &z); // z is the weight, x -> y
        pq.push(edge(-z, ii(x, y)));
    }

    printf("%d\n", kruskall(n));

    return 0;
}