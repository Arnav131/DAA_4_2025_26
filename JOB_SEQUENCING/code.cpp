#include<bits/stdc++.h>
using namespace std;


class Solution {
    int find(int x, vector<int>& parent){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }

public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

        int n = deadline.size();
        vector<pair<int,int>> jobs;

        for(int i=0;i<n;i++){
            jobs.push_back({profit[i], deadline[i]});
        }

        sort(jobs.begin(), jobs.end(), greater<>());

        int maxD = *max_element(deadline.begin(), deadline.end());

        vector<int> parent(maxD+1);
        for(int i=0;i<=maxD;i++) parent[i] = i;

        int cnt = 0, prof = 0;

        for(auto &job : jobs){
            int p = job.first;
            int d = job.second;

            int freeSlot = find(d, parent);
            if(freeSlot > 0){
                cnt++;
                prof += p;
                parent[freeSlot] = find(freeSlot-1, parent);
            }
        }

        return {cnt, prof};
    }
};


int main(){
    return 0;
}

