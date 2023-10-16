#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i=0;i<(int)(N);i++)

struct Exe {
    stack<string> state;
    string fname;
};

void input_data(int N, vector<Exe> &seq);
void find_k(int k, vector<Exe> seq);

int main() {
    int N, k1, k2;
    cin >> N >> k1 >> k2;
    vector<Exe> seq;
    input_data(N, seq);
    find_k(k1, seq);
    find_k(k2, seq);
    return 0;
}

void input_data(int N, vector<Exe> &seq) {
    rep(i, N) {
        string fname;
        cin >> fname;
        vector<string> tmp;
        string state;
        while(state != "$") {
            cin >> state;
            tmp.push_back(state);
        }
        seq[i].fname = fname;
        rep(j, tmp.size()) {
            seq[i].state.push(tmp.back());
            tmp.pop_back();
        }
    }
}

void find_k(int k, vector<Exe> seq) {
    string tmp_state;
    string tmp_fname;
    tmp_fname = seq[0].fname;
    int tmp_pos = 0;
    rep(i, k) {
        string state = seq[tmp_pos].state.top();
        seq[tmp_pos].state.pop();
        if (isupper(state[0])) {
            
        }
    }
}
