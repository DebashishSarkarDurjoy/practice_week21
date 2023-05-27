#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Cab {
public:
    int x, y;
    string id;

    Cab(int x, int y, string id) {
        this->x = x;
        this->y = y;
        this->id = id;
    }

    int dist() {
        return (this->x * this->x) + (this->y * this->y);
    }
};

class customCompare {
public:
    bool operator()(Cab* A, Cab* B) const {
        return A->dist() < B->dist();
    }
};

void nearestCabs(vector<Cab*> cabs, int k) {
    priority_queue<Cab*, vector<Cab*>, customCompare> max_heap(cabs.begin(), cabs.begin()+k);

    for (int i = k; i < cabs.size(); i++) {
        if (cabs[i]->dist() < max_heap.top()->dist()) {
            max_heap.pop();
            max_heap.push(cabs[i]);
        }
    }

    vector<Cab*> result;
    while (!max_heap.empty()) {
        result.push_back(max_heap.top());
        max_heap.pop();
    }

    reverse(result.begin(), result.end());

    cout << "Closest Cabs: " << endl;
    for (auto cab: result) {
        cout << cab->id << "   ";
    }
    cout << endl;
}

int main(void) {
    vector<Cab*> cabs;

    int N, k;
    cin >> N >> k;
    for (int i = 0; i < N; i++) {
        string id;
        int x, y;
        cin >> id >> x >> y;
        Cab *newCab = new Cab(x, y, id);
        cabs.push_back(newCab);
    }

    // for (auto cab: cabs) {
    //     cout << cab->id << " " << cab->x << " " << cab->y << endl;
    // }

    nearestCabs(cabs, k);

    return 0;
}