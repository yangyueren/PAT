//
// Created by yryang on 2019/9/14.
//
//sscanf(str, "%lf", &tmp);
//ssprintf(str, "%.2lf", tmp);

//  因为ad长度肯定小于b，所以只需要判断a与b的共同部分即可
//  for (int j = 0; j < strlen(a); ++j) {
//     if(a[j] != b[j]) flag=0;
//  }


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

int N;
int k;
double num[105];
int cnt=0;
int main(){
    scanf("%d",&N);
    char a[50], b[50];
    for (int i = 0; i < N; ++i) {
        scanf("%s", a);
        double tmp;
        int flag=1;
        sscanf(a, "%lf", &tmp);
        sprintf(b, "%.2lf", tmp);
        for (int j = 0; j < strlen(a); ++j) {
            if(a[j] != b[j]) flag=0;
        }
        if(flag && tmp<=1000 && tmp>=-1000){
            num[cnt++] = tmp;
        } else{
            printf("ERROR: %s is not a legal number\n", a);
        }
    }
    if(cnt==0){
        printf("The average of 0 numbers is Undefined\n");
    } else if(cnt == 1){
        printf("The average of 1 number is %.2lf\n", num[0]);
    }
    else{
        double ave=0;
        for (int i = 0; i < cnt; ++i) {
            ave+= num[i];
        }
        ave = ave / cnt;
        printf("The average of %d numbers is %.2lf\n", cnt, ave);
    }
}

//
//int N;
//int k;
//double num[105];
//int cnt=0;
//
//int isnum(string s){
//    int dot=0;
//    int flag=1;
//    if(s[0] == '-') s.erase(0,1);
//    //开头是数字
//    if(s[0] <'0' || s[0] > '9') return 0;
//
//    int len = s.size();
//    if(s[len-1] == '.') return 0;
//
//    for (int j = 0; j < s.size(); ++j) {
//        if(s[j] <'0' || s[j] >'9'){
//            if(s[j] == '.' && dot==0){
//                dot=1;
//            } else{
//                return 0;
//            }
//        }
//    }
//    return 1;
//
//}
//int twodecimal(string d){
//    size_t t = d.find('.');
//    if(d.size() - t > 3) return 0;
//    else return 1;
//}
//int main(){
//    cin >> N;
//    string s;
//    for (int i = 0; i < N; ++i) {
//        cin >> s;
//        if(isnum(s)){
//            double dd = stod(s);
//            if(dd>=-1000 && dd<=1000 && twodecimal(s))
//                num[cnt++] = stod(s);
//            else printf("ERROR: %s is not a legal number\n", s.c_str());
//        } else{
//            printf("ERROR: %s is not a legal number\n", s.c_str());
//        }
//    }
//    if(cnt==0){
//        printf("The average of 0 numbers is Undefined\n");
//    } else if(cnt == 1){
//        printf("The average of 1 number is %.2lf\n", num[0]);
//    }
//    else{
//        double ave=0;
//        for (int i = 0; i < cnt; ++i) {
//            ave+= num[i];
//        }
//        ave = ave / cnt;
//        printf("The average of %d numbers is %.2lf\n", cnt, ave);
//    }
//    return 0;
//}