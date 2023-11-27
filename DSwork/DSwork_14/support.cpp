#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i=0;i<(int)(N);i++)

struct Guest {
    int arrive_time;
    int id;
    int consult_time;
    bool operator<(const Guest& other) const {
        if (consult_time == other.consult_time) return arrive_time > other.arrive_time;
        else return consult_time < other.consult_time;
    }
};

void enter_room(priority_queue<Guest> &Room, vector<Guest> &waiting, int &time);
void consulting(priority_queue<Guest> &Room, int &time, int &cnt);

int main() {
    int N, time, cnt;
    priority_queue <Guest> Room;
    vector <Guest> waiting;
    cin >> N;

    rep(i, N) {
        int arrive_t, id, consult_t;
        Guest guest;
        cin >> arrive_t >> id >> consult_t;
        guest.arrive_time = arrive_t;
        guest.id = id;
        guest.consult_time = consult_t;
        waiting.push_back(guest);
    }

    time = 30;
    cnt = 0;

    while(cnt < N) {
        enter_room(Room, waiting, time);
        consulting(Room, time, cnt);
    }

    return 0;
}

void enter_room(priority_queue<Guest> &Room, vector<Guest> &waiting, int &time) {
    for (auto it = waiting.begin(); it != waiting.end();) {
        int arrive_time = it->arrive_time;
        if (arrive_time <= time) {
            Room.push(*it);
            it = waiting.erase(it);
        } else {
            it++;
        }
    }
}

void consulting(priority_queue<Guest> &Room, int &time, int &cnt) {
    if(Room.size() == 0) {
        time++;
        return;
    }
    Guest select = Room.top();
    Room.pop();
    if(select.consult_time <= 10) {
        cout << select.id << endl;
        cnt++;
        time += select.consult_time;
    } else {
        int consult_time = select.consult_time / 2;
        time += consult_time;
        select.arrive_time = time;
        select.consult_time -= consult_time;
        Room.push(select);
    }
}
