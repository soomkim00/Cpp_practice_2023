#include<bits/stdc++.h>
#define allout(MSG,X) cout <<"\n"<<MSG<<"=> ";for(auto w:X)cout<<w<<" "
using namespace std;
typedef vector<vector<int>> dvec ;

int main () {
    vector <int> Z {1,2,3} ;
    int S = 0, T = 0 ; //Z.capacity() = 3 ;
    for(int i=1; i<=30; i++) {
        Z.push_back(i) ;
        T += Z.size( );
        S += Z.capacity( );
    }
    cout << "T= " << T << "\n , S= " << S ;
}
