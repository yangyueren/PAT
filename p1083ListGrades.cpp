//
// Created by yryang on 2019/9/13.
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


//把不符合条件的grade设置为-1，然后sort，cmp中要>号，不能>=
//if(begin>=0){
//    //begin是下标，就要和下标做比较
//    for (int j = 0; j < cnt; ++j) {
//        int dd = j+begin;
//        printf("%s %s\n", vc[dd].name, vc[dd].id);
//    }
//}


struct node{
    char name[15];
    char id[15];
    int grade;
};

vector<node> vc;
int N;
int lo, hi;

int cmp(node a, node b){
    return a.grade > b.grade;
}
int main(){
    scanf("%d",&N);
    for (int i = 0; i < N; ++i) {
        node t;
        scanf("%s", t.name);
        scanf("%s", t.id);
        scanf("%d", &t.grade);
        vc.push_back(t);
    }
    scanf("%d %d",&lo,&hi);

    sort(vc.begin(), vc.end(), cmp);

    int cnt=0;
    int begin=-1;
    int tag=0;
    for (auto it = vc.begin(); it!= vc.end() ; it++) {
        if(it->grade>=lo && it->grade <=hi){
            if(cnt==0) begin=tag;
            cnt++;
//            printf("%s %s\n", it->name, it->id);
        }
        tag++;
    }

    if(cnt==0) printf("NONE");
    if(begin>=0){
        //begin是下标，就要和下标做比较
        for (int j = 0; j < cnt; ++j) {
            int dd = j+begin;
            printf("%s %s\n", vc[dd].name, vc[dd].id);
        }
    }
}

//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct stu {
//    char name[12];
//    char id[12];
//    int grade;
//};
//int cmp1(stu a, stu b) {
//    return a.grade > b.grade;
//}
//int main() {
//    int n, low, high, cnt = 0;
//    scanf("%d", &n);
//    vector<stu> v(n);
//    for(int i = 0; i < n; i++) {
//        scanf("%s %s %d", v[i].name, v[i].id, &v[i].grade);
//    }
//    scanf("%d %d", &low, &high);
//    for(int i = 0; i < n; i++) {
//        if(v[i].grade < low || v[i].grade > high) {
//            v[i].grade = -1;
//        } else {
//            cnt++;
//        }
//    }
//    sort(v.begin(), v.end(), cmp1);
//    for(int i = 0; i < cnt; i++) {
//        printf("%s %s\n", v[i].name, v[i].id);
//    }
//    if(cnt == 0)
//        printf("NONE");
//    return 0;
//}