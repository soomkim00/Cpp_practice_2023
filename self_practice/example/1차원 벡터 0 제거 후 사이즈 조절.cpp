#include<bits/stdc++.h>
#define allout(MSG,X) cout <<"\n"<<MSG<<"=> ";for(auto w:X)cout<<w<<" "
using namespace std;
typedef vector<vector<int>> dvec ;

int main () {
    std::vector<int> myVector = {4, 0, 0, 3, 6, 0, 7, 0, 0, 9, 0, 1};

    // �� 0�� ��� ����
    myVector.erase(std::remove(myVector.begin(), myVector.end(), 0), myVector.end());

    // ũ�⸦ ������
    myVector.shrink_to_fit()
    }
}
