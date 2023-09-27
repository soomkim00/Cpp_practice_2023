#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct person{  
	string name;  
	int height;  
}Person;

struct {  
	bool operator()(Person a, Person b) {  
		return a.height < b.height;  
	}  
} heightComp2;

int main(void) {  
	vector student;

	student.push_back({"Ã¶¼ö", 175});
	student.push_back({"¿µÈñ", 162});
	student.push_back({"¿µÃ¶", 188});
	student.push_back({"¹Î¼ö", 168});

	sort(student.begin(),student.end(), heightComp2);

	for(auto i : student) {
	    cout<<i.name<<" ";
	}
}
