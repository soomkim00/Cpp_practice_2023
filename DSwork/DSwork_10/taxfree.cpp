#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i=0;i<(int)(N);i++)

void find_sets(int K, vector<int> price);
bool is_sets(vector<int> price, vector<int> purchase_set, vector<int> &tmp_set, int k);
void is_best(vector<int> &best_set, vector<int> tmp_set);

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> price;
    rep(i, N) {
        int pi;
        cin >> pi;
        price.push_back(pi);
    }
    find_sets(K, price);
    return 0;
}

void find_sets(int K, vector<int> price) {
    vector<int> best_set;
    stack<string> tmp;
    tmp.push("");
    while (!tmp.empty()) {
        string purchase = tmp.top();
        tmp.pop();
        if (purchase.length() == price.size()) {
            vector<int> purchase_set;
            vector<int> tmp_set;
            rep(i, purchase.length()) {
                purchase_set.push_back(purchase[i] - 48);
            }
            if (is_sets(price, purchase_set, tmp_set, K)) {
                is_best(best_set, tmp_set);
            }
        } else {
            tmp.push(purchase + "0");
            tmp.push(purchase + "1");
        }
    }
    if (best_set.size() == 0) {
        cout << 0 << endl;
        return;
    } else {
        reverse(best_set.begin(), best_set.end());
        for(auto i : best_set) {
            cout << i << endl;
        }
    }
}

bool is_sets(vector<int> price, vector<int> purchase_set, vector<int> &tmp_set, int k) {
    int sum = 0;
    rep(i, price.size()) {
        if (purchase_set[i] == 1) {
            sum += price[i];
            tmp_set.push_back(price[i]);
        }
    }
    sort(tmp_set.rbegin(), tmp_set.rend());
    if (sum == k) return true;
    else return false;
}

void is_best(vector<int> &best_set, vector<int> tmp_set) {
    if (best_set.size() == 0) best_set = tmp_set;
    else {
        for (int i=0; i < min(tmp_set.size(), best_set.size()); i++) {
            if (best_set[i] > tmp_set[i]) return;
            else if (best_set[i] < tmp_set[i]) {
                best_set.clear();
                best_set = tmp_set;
            }
        }
    }
}
