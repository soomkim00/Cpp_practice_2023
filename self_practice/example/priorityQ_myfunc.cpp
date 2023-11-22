#include <iostream>
#include <queue>
using namespace std;

struct compare {  // private compare function
    bool operator()(const int& l, const int& r) {
        if(l/100 != r/100) return l/100 < r/100;
        else if(l/100 == 2) return l < r;
        else return l > r;
    }
};

int main() {
    vector<int> guest {234, 147, 163, 282, 214, 160, 0, 134, 146, 0, 0, 0, 158, 132, 0, 213 ,277, 0, 0, 0, 183 ,105, 0};
    priority_queue<int, deque<int>, compare> pq;
    for(int w:guest) {
        if (w == 0) {
            cout << pq.top() << endl;
            pq.pop();
        }
        else pq.push(w);
    }

    return 0;
}
