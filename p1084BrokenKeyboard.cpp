//
// Created by yryang on 2019/9/12.
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
using namespace std;

vector<char> keys;
vector<char> ruined;
int main(){
    char c;
    while ((c=getchar()) != '\n'){
        if(c>='a' && c<='z') c =  c+'A'-'a';
        keys.push_back(c);
    }
    while ((c=getchar()) != '\n'){
        if(c>='a' && c<='z') c =  c+'A'-'a';
        ruined.push_back(c);
    }
    for (int i = 0; i < keys.size(); ++i) {
        char a = keys[i];
        if(find(ruined.begin(), ruined.end(), a) == ruined.end()){
            printf("%c", a);
            ruined.push_back(a);
        }
    }
}