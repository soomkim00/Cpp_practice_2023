#include <iostream>

using namespace std;
char Get_strip(int x_val);

int T[5] = {40, 50, 60, 85, 10000};
char g[5] = {'F', 'D', 'C', 'B', 'A'};

int score()
{
    int score;
    cin >> score;
    cout << Get_strip(score);
}

char Get_strip(int x_val) {
    for (int i = 0; i < 5; i++) {
        if (x_val <= T[i]) {
            return g[i];
        }
    }
}
