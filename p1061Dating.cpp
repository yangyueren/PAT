//
// Created by yryang on 2019/9/13.
//

//这里的day[1] 可以是digit 也可以是'A'-'N'之间的字母，要考虑清楚

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

char s1[65];
char s2[65];
char s3[65];
char s4[65];
char week[7][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
string reday="";
int hour;
int minute=-1;
int main(){
    scanf("%s%s%s%s",s1,s2,s3,s4);
    char day[2];

    int index=0;
    while (index<strlen(s1) && index < strlen(s2)){
        if(s1[index] == s2[index] && s1[index] >='A' && s1[index] <='G'){
            day[0] = s1[index];
            break;
        }
        index++;
    }
    index++;
    while (index<strlen(s1) && index < strlen(s2)){
        if(s1[index] == s2[index] && ((s1[index] >='A' && s1[index] <='N') || (isdigit(s1[index])))){
            day[1] = s1[index];
            break;
        }
        index++;
    }

    reday = week[day[0]-'A'];
    if(day[1]>='0'&&day[1]<='9') hour = day[1]-'0';
    else hour = day[1]-'A'+10;


    int len3 = strlen(s3);
    for (int j = 0; j < len3 && j<strlen(s4); ++j) {
        if(s3[j]==s4[j] && isalpha(s3[j])) {
            minute = j;
            break;
        }
    }


    printf("%s %02d:%02d", reday.c_str(), hour, minute);


}