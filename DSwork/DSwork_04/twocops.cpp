#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i=0;i<(int)(N);i++)
#define allout(MSG,X)   cout<<"\n"<<MSG<<" ";for(auto w:X)cout<<w<<", "

vector<int> point_x;
vector<int> point_y;
int pos_1x;
int pos_1y;
int pos_2x;
int pos_2y;

void input_data(int &t);
void comp(int &t);
void init();

int main() {

    int t;
    input_data(t);
    comp(t);
    cout << pos_1x << " " << pos_1y << endl;
    cout << pos_2x << " " << pos_2y << endl;
    
    return 0;
}

void input_data(int &t) {
    int N;
    cin >> N;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        point_x.push_back(x);
        point_y.push_back(y);
    }
    cin >> t;
}

void comp(int &t) {
    init();
    rep()
}

void init() {
    int pos2 = floor(point_x.size()/2);
    pos_1x = point_x[0];
    pos_1y = point_y[0];
    pos_2x = point_x[pos2];
    pos_2y = point_y[pos2];
}
