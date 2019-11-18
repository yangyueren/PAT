//
// Created by yryang on 2019/9/16.
//

#include "iostream"
#include "string"
#include "set"
#include "map"
#include "vector"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "algorithm"
using namespace std;

vector<string> person;
int M, N, S;
set<string> winners;
int main(){
    cin >> M >> N >> S;
    for (int i = 0; i < M; ++i) {
        string s="";
        cin >> s;
        person.push_back(s);
    }
    int win=S;
    while(win <= M){
        string now = person[win-1];
        if(winners.find(now) != winners.end()){
            win++;
        } else{
            cout << now << endl;
            winners.insert(now);
            win += N;
        }
    }
    if(winners.size() == 0){
        cout << "Keep going...\n";
    }
    return 0;
}