// https://szkopul.edu.pl/problemset/problem/l8gBuYPAbv4Qbf2vDV8bTT3i/site/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    vector<int> adj_nodes;
    bool visited;
};

constexpr int max_n = 1e5 + 9;
Node tree[max_n];
int farthest_node, max_depth;

void find_farthest(int v, int depth = 0) {
    tree[v].visited = true;

    if (depth > max_depth) {
        farthest_node = v;
        max_depth = depth;
    }
    
    for (int i : tree[v].adj_nodes) {
        if (!tree[i].visited)
            find_farthest(i, depth + 1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].adj_nodes.push_back(b);
        tree[b].adj_nodes.push_back(a);
    } 

    find_farthest(1);

    for (int i = 0; i <= n; i++)
        tree[i].visited = false;

    max_depth = 0;
    find_farthest(farthest_node);

    cout << max_depth + 1 << '\n';

    return 0;
}
