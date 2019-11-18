//
// Created by yryang on 2019/8/25.
//

#include "stdio.h"
#include "iostream"
#include "string"
#include "map"
#include "vector"
#include "limits.h"

using namespace std;

#define bankOpen 8*60*60
#define bankClose 17*60*60

int n, k;
int people = 0;
int windowSumTime[105];
map<int, int> m;
vector<int> waitTime;

int chooseMinWindow(){
    int minIndex = 0;
    int min = INT_MAX;//定义在limits.h
    for (int i = 0; i < k; ++i) {
        if(windowSumTime[i] < min){
            minIndex = i;
            min = windowSumTime[i];
        }
    }
    return minIndex;
}
void process(map<int, int>::iterator & it){
    if(it->first >= bankClose){
        return;
    }
    int minWindow = chooseMinWindow();
    int diff = windowSumTime[minWindow] - it->first;
    if(diff > 0){
        //如果前面有人在办理，
        waitTime.push_back(diff);
        //windowSumTime只需要加上该人的办理时间
        windowSumTime[minWindow] += it->second*60;
        people++;
    } else{
        //因为有空闲，所以需要加上-diff + 办理时间
        windowSumTime[minWindow] += 0-diff + it->second*60;
        waitTime.push_back(0);
        people++;
    }
}

int main(){
    cin >> n >> k;
    getchar();
    for (int i = 0; i < n; ++i) {
        int hour, min, second;
        int process;
        cin >> hour;
        getchar();
        cin >> min;
        getchar();
        cin >> second;
        getchar();
        cin >> process;
        process = process <= 60 ? process : 60;

        int arriveTime = hour*60*60 + min*60 + second;
        m.insert(make_pair(arriveTime, process));
    }
    for (int j = 0; j < k; ++j) {
        windowSumTime[j] = bankOpen;
    }
    map<int, int>::iterator it = m.begin();
    while (it != m.end()){
        process(it);
        it++;
    }
    int sumWait = 0;
    for (int l = 0; l < people; ++l) {
        sumWait += waitTime[l];
    }
    float mean = sumWait*1.0/people;
    mean /= 60.0;
    printf("%.1f", mean);

    return 0;
}