
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // creating adjacency list for the connections and the relation 
        vector<vector<pair<int,int>>> adjlist(n);

        for(auto & f : flights){
            int x = f[0];
            int y = f[1];
            int val = f[2];
            adjlist[x].push_back({y,val});
        }



        //now making a distance vector for min cost to reach a city
        vector<int> cost(n,INT_MAX); // initially set to infinity or INT_MAX with n number of cities
        cost[src] = 0;


        //uisng queue for each city 
        // as queue : {stops,{node , current_cost}}

    queue<pair<int,pair<int,int>>> q;
    q.push({0,{src,0}}); // initail input




    //applying the BFS
    while(!q.empty()){
        auto temp = q.front();
        q.pop();


        //main logic
        int stp = temp.first;
        int nd = temp.second.first;
        int cc = temp.second.second;


        // if cost becomes higher than original cost then skip that cost
        if(stp > k){
            continue;
        }

        for(auto &v : adjlist[nd]){
            int next = v.first;
            int price = v.second;

            if(cc+price < cost[next]){
                cost[next] = cc + price;
                q.push({stp+1,{next,cost[next]}});
            }
        }
    }

    // final ans 

    if(cost[dst] == INT_MAX){
        return -1;
    }
    return cost[dst];

    }
};


int main(){
    Solution sol;
    // Unique graph with 4 cities (0..3)
    // Edges: 0->1 (50), 0->2 (300), 1->2 (50), 2->3 (100), 1->3 (200), 0->3 (1000)
    vector<vector<int>> flights = {
        {0,1,50},
        {0,2,300},
        {1,2,50},
        {2,3,100},
        {1,3,200},
        {0,3,1000}
    };
    int n = 4, src = 0, dst = 3, k = 2;
    cout << sol.findCheapestPrice(n, flights, src, dst, k) << endl;
    return 0;
}