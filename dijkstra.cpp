// https://szkopul.edu.pl/problemset/problem/fNxt_q3slvbbHw9rl8IeFyIj/site/

#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using LL = long long;
using Edge = pair<LL, LL>;
using Graph = vector<vector<Edge>>;

inline constexpr LL distance_max = numeric_limits<LL>::max();

pair<LL, vector<LL>> dijkstra(const Graph& graph, LL i_src, LL i_end) {
    vector<LL> distances(graph.size(), distance_max);
    vector<LL> previous(graph.size(), -1);
    vector<bool> visited(graph.size(), false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> visit_queue;

    distances[i_src] = 0;
    visit_queue.push({ 0, i_src });

    while (!visit_queue.empty()) {
        int i_cur = visit_queue.top().second;
        visit_queue.pop();

        if (visited[i_cur])
            continue;

        visited[i_cur] = true;

        for (const auto& i : graph[i_cur]) {
            auto [weight_adj, i_adj] = i;
            if (distances[i_adj] <= distances[i_cur] + weight_adj
             || visited[i_adj])
                continue;
            distances[i_adj] = distances[i_cur] + weight_adj;
            previous[i_adj] = i_cur;
            visit_queue.push({ distances[i_adj], i_adj });
        }
    }

    vector<LL> visit_path;
    for (LL i = i_end; i != -1; i = previous[i])
        visit_path.push_back(i);
    reverse(visit_path.begin(), visit_path.end());

    if (visit_path[0] != i_src)
        return { -1, {} };

    return { visit_path.size() - 1, visit_path };
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LL n_nodes, n_edges;
    cin >> n_nodes >> n_edges;
    Graph graph(n_nodes + 1);

    for (LL i = 0; i < n_edges; i++) {
        LL a, b, w;
        cin >> a >> b >> w;

        graph[a].push_back({ w, b });
        graph[b].push_back({ w, a });
    }

    auto [n_moves, visit_path] = dijkstra(graph, 1, graph.size() - 1);
    if (n_moves == -1)
        cout << "NIE\n";
    else {
        cout << n_moves << '\n';
        for (auto i : visit_path)
            cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
