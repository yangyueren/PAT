//
// Created by yryang on 2019/9/15.
//

#include "iostream"
#include "string.h"
#include "string"
#include "stdlib.h"
#include "stdio.h"
#include "map"
#include "vector"
#include "set"
#include "math.h"
#include "queue"
#include "algorithm"
#include "unordered_map"
using namespace std;

map<string, int> mp;
string maxstr="";
int maxcnt=-1;
void storeword(string word){
    if(word == "") return;
    string a="";
    for (int i = 0; i < word.size(); ++i) {
        if(isalpha(word[i]) || isdigit(word[i])){
            if(word[i] >= 'A' && word[i] <= 'Z') word[i] = word[i] -'A' + 'a';
            a += word[i];
        }
    }
    if(a.size() > 0){
        mp[a]++;
        if(mp[a] > maxcnt){
            maxstr = a;
            maxcnt = mp[a];
        } else if(mp[a] == maxcnt){
            if(a < maxstr){
                maxstr = a;
            }
        } else{

        }
    }
}

int main(){

    string s;
    getline(cin, s);
    int pos = 0;
    while (pos < s.size()){
        string word = "";
        while((isdigit(s[pos]) || isalpha(s[pos])) && pos != s.size()){
            word += s[pos];
            pos++;
        }
        storeword(word);
        pos++;
    }
    cout << maxstr << " "<< maxcnt <<endl;
    return 0;
}