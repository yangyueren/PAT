//
// Created by yryang on 2019/9/6.
//

#include "string"
#include "iostream"

using namespace std;

int main(){
    string s("assjdjdkl");
    string flag("sj");
    char a = 'd';
    size_t pos = s.find(a);
    s.erase(pos,1);
    cout << s << endl;
    cout << pos << endl;
    cout << s.length();

    int c[10];
    memset(c,10,1);
    int n;
    while(true) {
        cin >> n;
        if( n==0) {
            break;
        }
    }


    return 0;
}