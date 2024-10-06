// https://szkopul.edu.pl/problemset/problem/fIwYfy0zzmVZJJXTShFq2ICC/site/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
using Bitmap = vector<vector<bool>>;
using Answer = vector<vector<int>>;

vector<pair<int, int>> moves = {
    { 1, 0 },
    { -1, 0 },
    { 0, 1 },
    { 0, -1 }
};

Answer find_distances(const Bitmap& bitmap) {
    int width = bitmap[0].size();
    int height = bitmap.size();

    Answer distances(height, vector<int>(width, -1));
    queue<pair<int, int>> visit_queue;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (bitmap[y][x] == 1) {
                visit_queue.push({ x, y });
                distances[y][x] = 0;
            }
        }
    }

    while (!visit_queue.empty()) {
        auto [x, y] = visit_queue.front();

        for (const auto& i : moves) {
            int new_x = x + i.first;
            int new_y = y + i.second;

            if (new_x < 0 || new_x >= width
             || new_y < 0 || new_y >= height)
                continue;
            
            if (distances[new_y][new_x] != -1)
                continue;

            distances[new_y][new_x] = distances[y][x] + 1;
            visit_queue.push({ new_x, new_y });
        }

        visit_queue.pop();
    }

    return distances;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int width, height;
    cin >> height >> width;

    Bitmap bitmap(height, vector<bool>(width));
    for (int y = 0; y < height; y++) {
        string line;
        cin >> line;
        for (int x = 0; x < width; x++)
            bitmap[y][x] = (line[x] == '1');
    }

    Answer answer = find_distances(bitmap);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++)
            cout << answer[y][x] << ' ';
        cout << '\n';
    }

    return 0;
}
