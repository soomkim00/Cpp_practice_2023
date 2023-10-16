#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i=0;i<(int)(N);i++)

int Check_end = 0;

void input_data(int N, vector<stack<int>> &yard);
void sort_yard(vector<stack<int>> &yard);
int find_pos(vector<stack<int>> &yard);
void set_pos(int pos, vector<stack<int>> &yard);

int main() {
    int N;
    cin >> N;

    vector<stack<int>> yard;
    input_data(N, yard);
    sort_yard(yard);
    rep(i, N) {
        cout << 
    }
    return 0;
}



void input_data(int N, vector<stack<int>> &yard) {
    rep(i, N) {
        int num;
        cin >> num;
        stack<int> storage;
        if (num != 0) {
            rep(j, num) {
                int si;
                cin >> si;
                storage.push(si);
            }
        }
        yard.push_back(storage);
    }
}

void sort_yard(vector<stack<int>> &yard) {
    while(Check_end == 0) {
        int pos = find_pos(yard);
        set_pos(pos, yard);
    }
}

int find_pos(vector<stack<int>> &yard) {
    int high = 0;
    int pos = 0;
    rep(i, yard.size()) {
        if (yard[i].size() > high) {
            high = yard[i].size();
            pos = i;
        }
        if (yard[i].size() == high) {
            if (yard[i].top() > yard[pos].top()) {
                pos = i;
            }
        }
    }
    return pos;
}

void set_pos(int pos, vector<stack<int>> &yard) {
    int tmp = yard[pos].top();
    yard[pos].pop();
    int low_pos;
    int low_tmp = yard[pos].size();
    rep(i, yard.size()) {
        if (yard[i].size() == 0) {
            yard[i].push(tmp);
            return;
        }
        if (yard[i].size() < low_tmp) {
            low_tmp = yard[i].size();
            low_pos = i;
        }
    }
    if ((yard[i].size() - low_tmp) == 1) {
        Check_end = 1;
    } else {
        yard[low_pos].push(tmp);
    }
}
