#include <iostream>
#include <vector>
using namespace std;

#define rep(i, N) for(int i=0;i<(int)(N);i++)
#define NUM 5

vector<int> Point_x;
vector<int> Point_y;
int Result_x[NUM];
int Result_y[NUM];
int Time[NUM];
int robot_tmp_x;
int robot_tmp_y;
int index_tmp;

void input_data();
void comp();
void go(int direction);
void init();
int check_dir();
void check_start();
void print_result();

int main() {
    input_data();
    comp();
    print_result();
    return 0;
}

void input_data() {
    int N;
    cin >> N;
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        Point_x.push_back(x);
        Point_y.push_back(y);
    }
    Point_x.push_back(Point_x[0]);
    Point_y.push_back(Point_y[0]);
    rep(i, NUM) {
        cin >> Time[i];
    }
}

void comp(){
    rep(i, NUM) {
        init();
        rep(j, Time[i]) {
            int direction = check_dir();
            go(direction);
            check_start();
        }
        Result_x[i] = robot_tmp_x;
        Result_y[i] = robot_tmp_y;
    }
}

void go(int direction) {
    switch(direction) {
    case 1:
        robot_tmp_y++;
        if(robot_tmp_y == Point_y[index_tmp+1]) {
            index_tmp++;
        }
        break;
    case 2:
        robot_tmp_y--;
        if(robot_tmp_y == Point_y[index_tmp+1]) {
            index_tmp++;
        }
        break;
    case 3:
        robot_tmp_x++;
        if(robot_tmp_x == Point_x[index_tmp+1]) {
            index_tmp++;
        }
        break;
    case 4:
        robot_tmp_x--;
        if(robot_tmp_x == Point_x[index_tmp+1]) {
            index_tmp++;
        }
        break;
    }
}

void init() {
    robot_tmp_x = Point_x[0];
    robot_tmp_y = Point_y[0];
    index_tmp = 0;
};

int check_dir() {
    if(Point_x[index_tmp] == Point_x[index_tmp + 1]) {
        if(Point_y[index_tmp] < Point_y[index_tmp + 1]) {
            return 1; // up
        }
        else {
            return 2; // down
        }
    }
    else {
        if(Point_x[index_tmp] < Point_x[index_tmp + 1]) {
            return 3; // right
        }
        else {
            return 4; //left
        }
    }
}

void check_start() {
    if (robot_tmp_x == Point_x[0] && robot_tmp_y == Point_y[0]) {
        index_tmp = 0;
    }
}

void print_result() {
    rep(i, NUM) {
        cout << Result_x[i] << " " << Result_y[i] << endl;
    }
}
