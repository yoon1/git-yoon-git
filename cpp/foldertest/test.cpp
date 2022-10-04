#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Edge {
public:
    int node[2];
    int dist;
    Edge(int a, int b, int dist) {
        this->node[0] = a;
        this->node[1] = b;
        this->dist = dist;
    }
    bool operator < (const Edge &edge) const{
        return this->dist < edge.dist;
    }
};

int getParent(int set[], int x) {
    if (set[x] == x) return x;
    return set[x] = getParent(set, set[x]);
}

void unionParent(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);

    if (a < b) set[b] = a;
    else set[a] = b;
}

int find(int set[], int a, int b) {
    a = getParent(set, a);
    b = getParent(set, b);

    return a == b;
}

int main() {
    vector<Edge> v;
    int N, M;
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(Edge(a, b, c));
        v.push_back(Edge(b, a, c));
    }

    sort(v.begin(), v.end());

    int set[N];
    for (int i = 0; i < N; i++) {
        set[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!find(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
            sum += v[i].dist;
            unionParent(set, v[i].node[0] -1, v[i].node[1] - 1);
        }
    }

    printf("%d", sum);

    return 0;
}