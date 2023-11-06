#include<bits/stdc++.h>
#define allout(MSG,X) cout <<"\n"<<MSG<<"=> ";for(auto w:X)cout<<w<<" "
using namespace std;

stack<int> Reverse_Stack(stack<int> X);

int main () {
    stack <int> S, T;
    for(auto w : {3, 2, 8, 7, 9, 10, 5})
        S.push(w) ;
    T = Reverse_Stack(S);
    while (!T.empty()) {
        std::cout << T.top() << ' ';
        T.pop();
    }
    return 0;
}

stack<int> Reverse_Stack(stack<int> X) {
    stack<int> tmp;
    while(!X.empty()) {
        tmp.push(X.top());
        X.pop();
    }
    return tmp;
}
