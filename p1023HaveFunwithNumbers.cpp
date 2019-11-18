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
using namespace std;


//  (c = getchar()) != '\n'
//  carry不进位，要置0

int num[25];
int main(){

    vector<int> s;
    char c;

    while ((c=getchar()) !='\n'){
//        cout << c;
        s.push_back(c-'0');
    }

    for (int j = 0; j < s.size(); ++j) {
        num[s[j]]++;
    }
    int carry=0;
    int b;
    for (int k = s.size()-1; k >= 0 ; --k) {
        b = s[k]*2+carry;
        carry=0;
        if(b>=10) carry = b/10;
        s[k] = b%10;

    }
    if (carry>0) s.insert(s.begin(), carry);

    bool flag = true;
    for (int i = 0; i < s.size(); ++i) {
        num[s[i]]--;
    }
    for (int l = 0; l < 25; ++l) {
        if(num[l] != 0) flag = false;
    }
    if(flag) printf("Yes\n");
    else printf("No\n");
    for (int m = 0; m < s.size(); ++m) {
        printf("%d", s[m]);
    }
}