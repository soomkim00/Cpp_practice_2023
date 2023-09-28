#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i=0;i<(int)(N);i++)

struct term {
    int coef;
    int expo;
};

void input_data(vector<term> &terms);
vector<int> add_term(vector<term> &terms);
void print_result(vector<int> &result_term);

int main() {
    vector<term> terms;
    vector<int> result_term;
    
    input_data(terms);
    result_term = add_term(terms);
    print_result(result_term);
    
    return 0;
}

void input_data(vector<term> &terms) {
    int N;
    cin >> N;
    rep(i, N) {
        int t;
        cin >> t;
        rep(j, t) {
            int coef, expo;
            cin >> coef >> expo;
            terms.push_back({coef, expo});
        }
    }
}

vector<int> add_term(vector<term> &terms) {
    int max_expo = 0;
    rep(i,terms.size()) {
        if(terms[i].expo > max_expo) {
            max_expo = terms[i].expo;
        }
    }
    vector<int> result_term(max_expo + 1); // exp 0 : const
    rep(j,terms.size()) {
        result_term[terms[j].expo] += terms[j].coef;
    }
    return result_term;
}

void print_result(vector<int> &result_term) {
    int size_result = result_term.size();
    int cnt = 0;
    rep(i, size_result) {
        if (result_term[i] != 0) {
            cnt++;
        }
    }
    if(cnt == 0) {
        cout << "0 0" << endl;
    }
    else {
        cout << cnt << endl;
        for(int i = size_result - 1; i >= 0; i--) {
            if (result_term[i] == 0) {
                continue;
            }
            cout << result_term[i] << " " << i << endl;
        }
    }
}
