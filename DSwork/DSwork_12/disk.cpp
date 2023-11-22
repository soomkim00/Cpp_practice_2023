#include<bits/stdc++.h>
using namespace std;

#define rep(i, N) for(int i=0;i<(int)(N);i++)

struct File {
    string name;
    int space;
};

struct FilePos {
    string name;
    vector<int> pos;
};

void WriteFile(list<File> &disk, list<FilePos> &pos_table, string name, string space);
void DeleteFile(list<File> &disk, list<FilePos> &pos_table, string name);
void ShowFile(list<File> &disk, list<FilePos> pos_table, string name);
void CompactDisk(list<File> &disk, list<FilePos> &pos_table);

int main() {
    int v;
    cin >> v;
    
    list<File> disk;
    list<FilePos> pos_table;
    
    File file;
    file.name = "free";
    file.space = v;
    disk.push_back(file);
    
    string command;
    while(true) {
        if (command == "end") break;
        cin >> command;
        stringstream ss(command);
        string word;
        vector<string> commands;
        while(getline(ss, word, ' ')) {
            commands.push_back(word);
        }
        
        if(commands[0] == "write") WriteFile(disk, pos_table, commands[1], commands[2]);
        else if(commands[0] == "delete") DeleteFile(disk, pos_table, commands[1]);
        else if(commands[0] == "show") ShowFile(disk, pos_table, commands[1]);
        else if(commands[0] == "compact") CompactDisk(disk, pos_table);
        else cout << "command Error!" << endl;
    }
    return 0;
}

void WriteFile(list<File> &disk, list<FilePos> &pos_table, string name, string space) {
    cout << "write" << endl;
    
}

void DeleteFile(list<File> &disk, list<FilePos> &pos_table, string name) {
    cout << "delete" << endl;
    
}

void ShowFile(list<File> &disk, list<FilePos> pos_table, string name) {
    cout << "show" << endl;

}

void CompactDisk(list<File> &disk, list<FilePos> &pos_table) {
    cout << "compact" << endl;

}
