#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Node {
public:
    int x, y;
    int distance;

    Node (int x, int y, int distance) {
        this->x = x;
        this->y = y;
        this->distance = distance;
    }
};

class customCompare {
public:
    bool operator()(Node* A, Node* B) const {
        return A->distance <= B->distance;
    }
};

void showGrid(vector<vector<int>> &grid) {
    for (auto row: grid) {
        for (auto data: row) {
            cout << data << " ";
        }
        cout << endl;
    }
}

void shortestGridPath(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> shortestPath(m, vector<int> (n, INT_MAX));

    set<Node*, customCompare> s;
    s.insert(new Node(0, 0, grid[0][0]));

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!s.empty()) {
        auto it = s.begin();
        s.erase(it);

        int current_x = (*it)->x;
        int current_y = (*it)->y;
        int current_distance = (*it)->distance;

        for (int k = 0; k < 4; k++) {
            int new_x = current_x + dx[k];
            int new_y = current_y + dy[k];

            if ( (new_x >= 0 && new_x < m) && (new_y >= 0 && new_y < n) && (current_distance + grid[new_x][new_y] < shortestPath[new_x][new_y]) ) {
                Node* temp = new Node(new_x, new_y, shortestPath[new_x][new_y]);
                if (s.find(temp) != s.end()) s.erase(s.find(temp));

                s.insert(new Node(new_x, new_y, current_distance + grid[new_x][new_y]));
                shortestPath[new_x][new_y] = current_distance + grid[new_x][new_y];
            }
        }
    }

    for (auto row: shortestPath) {
        for (auto data: row) cout << data << " ";
        cout << endl;
    }

    return;
}

int main(void) {
    vector<vector<int>> grid = {
        {31, 100, 64, 12, 18},
        {10, 13, 47, 157, 6},
        {100, 113, 174, 11, 33},
        {88, 124, 41, 20, 140},
        {99, 32, 111, 41, 20}
    };

    shortestGridPath(grid);

    // showGrid(grid);



    return 0;
}