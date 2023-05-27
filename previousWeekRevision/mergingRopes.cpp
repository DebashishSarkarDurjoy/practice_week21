#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int mergeRopes(vector<int> ropes) {
    priority_queue<int, vector<int>, greater<int>> min_heap(ropes.begin(), ropes.end());

    int cost = 0;
    while (min_heap.size() > 1) {
        int top_1 = min_heap.top();
        min_heap.pop();
        int top_2 = min_heap.top();
        min_heap.pop();

        cost += top_1 + top_2;
        min_heap.push(top_1 + top_2);
    }

    return cost;
}

int main(void) {
    vector<int> ropes = {4,3,2,6};
    int minCost = mergeRopes(ropes);

    cout << minCost << endl;

    return 0;
}