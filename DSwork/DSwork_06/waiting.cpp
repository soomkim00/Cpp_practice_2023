#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i=0;i<(int)(N);i++)
#define Sort_chair(i) sort(chair[i].begin(), chair[i].end())
int K;

void come(int num, vector<vector<int>> &chair);
void out(int num, vector<vector<int>> &chair);
void split(int i, vector<vector<int>> &chair);
void show_result(vector<vector<int>> &chair);

int main() {
    vector<vector<int>> chair;
    int N;
    cin >> N >> K;
    rep(i, N) {
        char para;
        int num;
        cin >> para >> num;
        if (para == '+') {
            come(num, chair);
        } else {
            out(num, chair);
        }
    }
    show_result(chair);

    return 0;
}

void come(int num, vector<vector<int>> &chair) {
    if (chair.empty()) {
        vector<int> new_chair = {num};
        chair.push_back(new_chair);
    } else {
        if (chair.size() == 1) {
            chair[0].push_back(num);
            Sort_chair(0);
            split(0, chair);
        } else {
            for (int i = 1; i < chair.size(); i++) {
                if (num < chair[i].front()) {
                    chair[i-1].push_back(num);
                    Sort_chair(i-1);
                    split(i-1, chair);
                    return;
                }
            }
            chair.back().push_back(num);
            Sort_chair(chair.size());
            split(chair.size(), chair);
        }
    }
}

void out(int num, vector<vector<int>> &chair) {

}

void split(int i, vector<vector<int>> &chair) {
    if (chair[i].size() == 2*K) {
        vector<int> temp_chair;
        rep(j, K) {
            temp_chair.push_back(chair[i].back());
            chair[i].pop_back();
        }
        sort(temp_chair.begin(), temp_chair.end());
        if (i == (chair.size() - 1)) {
            chair.push_back(temp_chair);
        }
        else {
            chair.insert(chair.begin() + (i+1), 1, temp_chair);
        }
    }
}

void show_result(vector<vector<int>> &chair) {
    for(int i = 0; i < chair.size(); i++) {
        cout << chair[i].front() << endl;
    }
}
