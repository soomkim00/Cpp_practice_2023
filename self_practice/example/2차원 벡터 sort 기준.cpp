#include<bits/stdc++.h>
#define allout(MSG,X) cout <<"\n"<<MSG<<"=> ";for(auto w:X)cout<<w<<" "
using namespace std;
typedef vector<vector<int>> dvec ;

int main () {
    dvec v1 = { {12},{33, 33},{66}, {0,1 },{1} } ;
    dvec v2 = { {12, 22},{33, 32},{67}, {0,1,2},{2} } ;
    dvec v3 = { {11, 22},{ },{3} } ;
    dvec v4 = { {12, 22},{33}, {67},{4} } ;
    dvec v5 = { { },{32},{5} } ;
    dvec v6 = { {12, 22},{ { } }, {66},{6} } ;
    dvec v7 = { {12, 22},{ }, {65},{7} } ;
    vector<dvec> Allvec = { v1, v2, v3, v4, v5, v6, v7 };
    sort( Allvec.begin(), Allvec.end() ) ;
    for( auto w : Allvec ) {
        allout("> ", w.back()) ;
    }
}
