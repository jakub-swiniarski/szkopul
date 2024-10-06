// https://szkopul.edu.pl/problemset/problem/obTB-Nlc2kXuC_TX18Kiae9V/site/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

vector<int> find_distances(const Graph& graph, int i_src) {
    vector<int> distances(graph.size(), -1);
    vector<bool> visited(graph.size(), false);
    queue<int> visit_queue;

    distances[i_src] = 0;
    visited[i_src] = true;
    visit_queue.push(i_src);

    while (!visit_queue.empty()) {
        int i_cur = visit_queue.front();
        visit_queue.pop();

        for (auto i : graph[i_cur]) {
            if (visited[i])
                continue;
            distances[i] = distances[i_cur] + 1;
            visited[i] = true;
            visit_queue.push(i); 
        }
    }

    return distances;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n_nodes, n_edges;
    cin >> n_nodes >> n_edges;

    Graph graph(n_nodes + 1);
    for (int i = 0; i < n_edges; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int result = 0;
    for (auto i : find_distances(graph, 0))
        result += 2 * i;

    cout << result << '\n';

    return 0;
}
