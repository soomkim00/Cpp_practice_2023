#include <iostream>

using namespace std;

int stair() {
    int left_top, right_bottom;
    int length_hor[10], length_vir[10];
    int seg[20];
    for(int i = 0; i < 20; i++) {
        cin >> seg[i];
    }
    for(int i = 0; i < 20; i++) {
        cout << seg[i] << " ";
    }

    return 0;
}
