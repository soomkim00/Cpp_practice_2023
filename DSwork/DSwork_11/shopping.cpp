#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i=0;i<(int)(N);i++)

struct Customer {
    int id=0;
    int ware;
};

void payment(queue<Customer> &line, int K, int N);

int main() {
    int N, K;
    cin >> N >> K;
    queue<Customer> line;
    rep(i, N) {
        int id, ware;
        Customer customer;
        cin >> id >> ware;
        customer.id = id;
        customer.ware = ware;
        line.push(customer);
    }
    payment(line, K, N);
}

void payment(queue<Customer> &line, int K, int N) {
    vector<Customer> counter;
    vector<int> result;
    int cnt = 0;
    rep(i, K) {
        if(line.empty()) break;
        counter.push_back(line.front());
        line.pop();
    }
    while(true) {
        rep(i, K) {
            if(counter[i].id != 0) {
                counter[i].ware--;
                if(counter[i].ware == 0) {
                    result.push_back(counter[i].id);
                    counter[i].id = 0;
                    cnt++;
                }
            }
            if(counter[i].id == 0 && !line.empty()) {
                counter[i].id = line.front().id;
                counter[i].ware = line.front().ware;
                line.pop();
            }
        }
        reverse(result.begin(), result.end());
        for(auto w:result) cout << w << endl;
        result.clear();
        if(cnt == N) break;
    }
}
