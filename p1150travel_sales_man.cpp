    //
    // Created by yryang on 2019/9/7.
    //
    #include "iostream"
    #include "map"
    #include "string"
    #include "vector"
    #include "algorithm"
    #include "limits.h"
    using namespace std;

    int adj[205][205];
    bool NA, NS, Simple;
    int min_index = -1;
    int min_dis = INT_MAX;
    int N;

    int main(){
        int M;
        int be, end, dis;
        cin >> N >> M;
        int now_index = 0;
        int length;
        for (int i = 0; i < M; ++i) {
            cin >> be >> end >> dis;
            adj[be][end] = dis;
            adj[end][be] = dis;
        }
        int total_path = 0;
        cin >> total_path;
        for (int j = 0; j < total_path; ++j) {
            NA = false;
            NS = true;
            Simple = true;
            now_index += 1;
            length = 0;

            map<int, int> mp;
            int T;
            cin >> T;
            int path[T];
            for (int i = 0; i < T; ++i) {
                cin >> path[i];
                if(i>0){
                    if(adj[path[i-1]][path[i]] == 0){
                        NA = true;
                    }
                    length += adj[path[i-1]][path[i]];
                    mp[path[i]]++;
                }
            }

            NS = (NA==false && mp.size()==N && path[0] == path[T-1]);
            for(map<int,int>::iterator itr=mp.begin(); itr!=mp.end(); itr++){
    //            cout << itr->first << " " << itr->second <<"   ";
                if(itr->second != 1){
                    Simple = false;
                }
            }
            if(NA==false && NS==true && length < min_dis){
                min_dis = length;
                min_index = now_index;
            }
            if(NA) printf("Path %d: NA (Not a TS cycle)\n", now_index);
            else if(NS){
                if(Simple) printf("Path %d: %d (TS simple cycle)\n", now_index, length);
                else printf("Path %d: %d (TS cycle)\n", now_index, length);
            } else {
                printf("Path %d: %d (Not a TS cycle)\n", now_index, length);
            }



        }
        printf("Shortest Dist(%d) = %d\n", min_index, min_dis);

    }