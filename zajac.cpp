// https://szkopul.edu.pl/problemset/problem/wQAk4d4zyJLueWkOPiNq_yD7/site/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

inline constexpr int limit = 1e3 + 9;

int n, m;
string tab[limit];

vector<pair<int, int>> moves = {
    { 1, 2 },
    { 1, -2 },
    { -1, 2 },
    { -1, -2 },
    { 2, 1 },
    { 2, -1 },
    { -2, 1 },
    { -2, -1 }
};

struct Point {
    int x, y, depth;
    Point(int x, int y, int d) : x(x), y(y), depth(d) {}
};

int find_home(Point start) {
    queue<Point> visit_queue;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    visit_queue.push(start);
    visited[start.y][start.x] = true;
    while (!visit_queue.empty()) {
        int x = visit_queue.front().x;
        int y = visit_queue.front().y;

        for (const auto& i : moves) {
            int new_x = x + i.first;
            int new_y = y + i.second;
            
            if (new_x < 0 || new_x >= m
             || new_y < 0 || new_y >= n)
                continue;
            
            if (tab[new_y][new_x] == 'n')
                return visit_queue.front().depth + 1;

            if (tab[new_y][new_x] != 'x'
             && !visited[new_y][new_x]) {
                visit_queue.push(Point(new_x, new_y, visit_queue.front().depth + 1));
                visited[new_y][new_x] = true;
            }
        }

        visit_queue.pop();
    }

    return -1;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> tab[i];

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (tab[y][x] == 'z') {
                int wynik = find_home(Point(x, y, 0));
                if (wynik == -1)
                    cout << "NIE\n";
                else
                    cout << wynik << '\n';
                return 0;
            }
        }
    }

    return 0;
}
