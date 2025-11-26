#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

int main() {
    string a = "-11";

    if(a.size() > 1) std::cout <<"true"<< std::endl;
     bool get = isdigit(a[0]);
     cout <<stoi(a)<< endl;
    return 0;
}