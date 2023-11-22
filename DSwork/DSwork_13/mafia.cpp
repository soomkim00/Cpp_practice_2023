#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i=0;i<(int)(N);i++)

void insert_tree(vector<vector<string>> &mafia_tree, string parent, string child);
void rank_tree(vector<vector<string>> &mafia_tree);
void show_tree(vector<vector<string>> &mafia_tree);

int main() {
    int N;
    vector<vector<string>> mafia_tree;

    cin >> N;
    rep(i, N-1) {
        string parent, child;
        cin >> child >> parent;
        insert_tree(mafia_tree, parent, child);
    }

    rank_tree(mafia_tree);

    show_tree(mafia_tree);

    return 0;
}

void insert_tree(vector<vector<string>> &mafia_tree, string parent, string child) {
    vector<string> relation;
    int flag1 = 0;
    int flag2 = 0;
    
    if(mafia_tree.size() == 0) {
        relation.push_back(parent);
        relation.push_back(child);
        mafia_tree.push_back(relation);
        relation.clear();
        relation.push_back(child);
        mafia_tree.push_back(relation);
        return;
    }
    
    rep(i, mafia_tree.size()) {
        if(mafia_tree[i].front() == parent) {
            mafia_tree[i].push_back(child);
            flag2 = 1;
        }
        else if(mafia_tree[i].front() == child) flag1 = 1;
    }
    
    if(flag == 0) {
        relation.push_back(child);
        mafia_tree.push_back(relation);
    }
}

void rank_tree(vector<vector<string>> &mafia_tree) {
    cout << "rank" << endl;
}

void show_tree(vector<vector<string>> &mafia_tree) {
    rep(i, mafia_tree.size()) {
        rep(j, mafia_tree[i].size()) {
            cout << mafia_tree[i][j] << " ";
        }
        cout << endl;
    }
}
