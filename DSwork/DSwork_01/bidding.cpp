#include <iostream>

using namespace std;

int main()
{
    int n_person, tmp_bid=0;
    string tmp_name = "NONE";
    cin >> n_person;
    int bid[n_person];
    string name[n_person];
    for (int i = 0; i < n_person; i++) {
        cin >> name[i] >> bid[i];
    }
    int chk_same_bid = 0;
    for (int i = 0; i < n_person - 1; i++) {
        for (int j = i + 1; j < n_person; j++) {
            if (bid[i] == bid[j]) {
                chk_same_bid = 1;
                bid[j] = 0;
            }
        }
        if (chk_same_bid == 1) {
            bid[i] = 0;
        }
        chk_same_bid = 0;
    }
    for (int i = 0; i < n_person; i++) {
        if (bid[i] != 0) {
            if (bid[i] > tmp_bid) {
                tmp_bid = bid[i];
                tmp_name = name[i];
            }
        }
    }
    cout << tmp_name;
}
