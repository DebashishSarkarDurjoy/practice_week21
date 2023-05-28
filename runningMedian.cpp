#include <iostream>
#include <queue>
#include <vector>

using namespace std;



int main(void) {
    priority_queue<int> left_heap;
    priority_queue<int, vector<int>, greater<int>> right_heap;
    vector<float> med;

    vector<int> test_numbers = {2,1,5,7,2,0,5};

    int d = test_numbers[0];
    left_heap.push(d);

    med.push_back(d);
    float median = d;

    d = test_numbers[1];
    int i = 2;
    while (d != -1) {
        if (left_heap.size() > right_heap.size()) {
            if (d < median) {
                right_heap.push(left_heap.top());
                left_heap.pop();
                left_heap.push(d);
            }
            else {
                left_heap.push(d);
            }
            med.push_back((left_heap.top() + right_heap.top()) / 2.0);
            median = med[med.size()-1];
        }
        else if (left_heap.size() < right_heap.size()) {
            if (d > median) {
                left_heap.push(right_heap.top());
                right_heap.pop();
                right_heap.push(d);
            }
            else {
                right_heap.push(d);
            }
            med.push_back((left_heap.top() + right_heap.top()) / 2.0);
            median = med[med.size() -1];
        }
        else {
            if (d < median) {
                left_heap.push(d);
                med.push_back(left_heap.top());
                median = med[med.size()-1];
            }
            else {
                right_heap.push(d);
                med.push_back(right_heap.top());
                median = med[med.size()-1];
            }

        }

        
        if (i < test_numbers.size() ) {
            d = test_numbers[i++];
        }
        else d = -1;
    }

    


    for (float m: med) cout << m << " ";
    cout << endl;
    return 0;
}