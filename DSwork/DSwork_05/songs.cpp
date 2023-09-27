#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i=0;i<(int)(N);i++)

struct song {
    string name = "";
    string type = "";
    int bangsong = 0;
    double filesize = 0;
    int download = 0;
};

bool comp(song a, song b) {
    if (a.bangsong == b.bangsong) {
        if (a.download == b.download) {
            return a.filesize < b.filesize;
        }
        return a.download > b.download;
    }
    return a.bangsong > b.bangsong;
}

void input_data(vector<song> &songs, int &k);
void sort_data(vector<song> &songs);
void check_type(vector<song> &songs);

int main() {
    vector<song> songs;
    int k;
    input_data(songs, k);
    sort_data(songs);
    cout << songs[k].name;
    return 0;
}

void input_data(vector<song> &songs, int &k) {
    int N;
    string name, type;
    int bangsong, download;
    double filesize;
    cin >> N >> k;
    rep(i, N) {
        cin >> name >> type >> bangsong >> filesize >> download;
        songs.push_back({name, type, bangsong, filesize, download});
    }
};

void sort_data(vector<song> &songs) {
    auto sortSongDefalut = songs;
    sort(sortSongDefalut.begin(), sortSongDefalut.end(), comp);
    check_type(songs);
}

void check_type(vector<song> &songs) {
    rep(i, songs.size()-1) {
        if(songs[i].type == songs[i+1].type) {
            for(int j = i+1; j++; j < songs.size()) {
                if(songs[i+1].name != songs[j].name) {
                    swap(songs[i+1], songs[j]);
                }
                else {
                    break;
                }
            }
        }
    }
}
