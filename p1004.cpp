//
// Created by yryang on 2019/9/6.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct node
{
    int height;
    vector<node *> child;
};
node *nodes[101];
int ans[101];
int main()
{
    int n, m;

    while(true) {
        cin >> n;
        if(n == 0){
            break;
        }
        cin >> m;
        int level = 0;
        for(int i = 0; i < m; i++) {
            int id, num;
            cin >> id >> num;
            if(nodes[id] == NULL) {
                nodes[id] = new node;
                nodes[id]->height = 0;
            }
            for(int j = 0; j < num; j++) {
                int cid;
                cin >> cid;
                nodes[cid] = new node;
                nodes[cid]->height = nodes[id] -> height + 1;
                level = nodes[cid]->height;
                nodes[id]->child.push_back(nodes[cid]);
            }
        }
        queue<node*> q;
        q.push(nodes[1]);
        while(!q.empty()) {
            auto it = q.front();
            // leave
            if(it->child.size() == 0) {ans[it->height]++;}
            else {
                for(auto n : it->child) {
                    q.push(n);
                }
            }
            q.pop();
        }
        cout << ans[0];
        for(int i = 1; i <= level; i++) {
            cout << " " << ans[i];
        }
    }

    return 0;
}