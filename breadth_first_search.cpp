// https://szkopul.edu.pl/problemset/problem/jz2F2uHp8uk_drXEPQExeDl5/site/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

vector<int> find_distances(const Graph& graph, int i_src) {
    vector<int> distances(graph.size(), -1);
    queue<int> visit_queue;

    distances[i_src] = 0;
    visit_queue.push(i_src);

    while (!visit_queue.empty()) {
        int i_cur = visit_queue.front();
        visit_queue.pop();

        for (int i : graph[i_cur]) {
            if (distances[i] != -1)
                continue;
            distances[i] = distances[i_cur] + 1;
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

    auto answer = find_distances(graph, 1);
    for (int i = 1; i < answer.size(); i++)
        cout << answer[i] << ' ';
    cout << '\n';

    return 0;
}
