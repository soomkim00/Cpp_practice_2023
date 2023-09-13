#include <iostream>

using namespace std;

#define rep(i, N) for(int i=0;i<(int)(N);i++)
#define rep2(i, N) for(int i=1;i<(int)(N);i=i+2)
#define pos_x(i) pos[i][0]
#define pos_y(i) pos[i][1]
#define q_pos_x(i) pos[i][0]
#define q_pos_y(i) pos[i][1]

void check(int q_pos_x, int q_pos_y);
void check1(int q_pos_y, int pos_y);
void check2(int q_pos_y, int pos_y, int pos_y_next);

int pos[21][2] = {0,};
int last_x = 0;

int main() {
    int q_pos[15][2];
    int sum = 0;
    rep(i, 20) {
        int temp = 0;
        cin >> temp;
        if(temp == 0) break;
        if(i % 2 == 0) {
            pos_x(i+1) = pos_x(i) + temp;
            pos_y(i+1) = pos_y(i);
        }
        else {
            pos_x(i+1) = pos_x(i);
            pos_y(i+1) = pos_y(i); - temp;
            sum += temp;
        }
        last_x = pos_x(i);
    }
    rep(i,20) {
        pos_y(i) += sum;
    }

    rep(i, 15) {
        cin >> q_pos_x(i) >> q_pos_y(i);
        if(cin.eof() == true) {
            break;
        }
        check(q_pos_x(i), q_pos_y(i));
    }
    return 0;
}

void check(int q_pos_x, int q_pos_y) {
    if (q_pos_x > last_x) {
        cout << "out" << endl;
        return;
    }
    rep2(j, 21) {
        if (q_pos_x < pos_x(j)) {
            check1(q_pos_y, pos_y(j));
            return;
        }
        else if (q_pos_x == pos_x(j)) {
            check2(q_pos_y, pos_y(j), pos_y(j+1));
            return;
        }
    }
}

void check1(int q_pos_y, int pos_y) {
    if(q_pos_y < pos_y) {
        cout << "in";
    }
    else if(q_pos_y > pos_y) {
        cout << "out";
    }
    else {
        cout << "on";
    }
    cout << endl;
}

void check2(int q_pos_y, int pos_y, int pos_y_next) {
    if(q_pos_y < pos_y_next) {
        cout << "in";
    }
    else if(q_pos_y > pos_y) {
        cout << "out";
    }
    cout << endl;
}
