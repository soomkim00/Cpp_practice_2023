#include<bits/stdc++.h>
#define allout(MSG,X) cout <<"\n"<<MSG<<"=> ";for(auto w:X)cout<<w<<" "
using namespace std;

int main () {
    vector< vector<int>> X { {3,4,5},{2,3},{6},{10,11,12,13},{22,23}} ;
    int tmp ;
    for(auto it=X.begin()+1; it!= X.end(); it++) {
        tmp = (it)->front();
        (it)->erase( (it)->begin() );
        (it-1)->push_back( tmp ) ;
    }
    auto it = X.begin();
    tmp = (it)->front();
    (it)->erase( (it)->begin() );
    (X.end()-1)->push_back( tmp ) ;
    
    for(int i = 0; i < X.size(); i++) {
        for(int j = 0; j < X[i].size(); j++) {
            cout << X[i][j] << " ";
        }
        cout << endl;
    }
}

