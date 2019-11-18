//
// Created by yryang on 2019/9/6.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    string owner, eva;
    cin >> owner >> eva;
    int miss = 0;

    for(int i = 0; i < eva.size(); i++) {
        size_t pos = owner.find(eva[i]);
        if(pos != string::npos) {
            owner.erase(pos, 1);
        } else {
            miss++;
        }
    }
    if(miss == 0) {
        cout << "YES " << owner.size();
    } else {
        cout << "NO " << miss;
    }
    return 0;
}