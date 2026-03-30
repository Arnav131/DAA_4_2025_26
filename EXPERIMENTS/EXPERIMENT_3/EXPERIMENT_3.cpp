// HAMILTONIAN PATH //

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector <bool> visited;
    vector <int> path;
    int n;
    bool solve(int u, int count, vector<vector<int>> adjList)
    {
        if(count==n-1)
        return true;
        for(auto v: adjList[u])
        {
            if(!visited[v])
            {
                visited[v]=true;
                path.push_back(v);
              if(  solve(v, count+1, adjList)) return true;
                visited[v]=false;
                path.pop_back();
            }
        }
        return false;
    }
    bool check(int n, int m, vector<vector<int>> edges) {
        this->n=n;
        vector<vector<int>> adjList(n);
        for(auto i: edges)
        {
            adjList[i[0]-1].push_back(i[1]-1);
            adjList[i[1]-1].push_back(i[0]-1);
        }
        visited=vector<bool>(n, false);
        for(int i=0; i<n; i++)
        {
            visited=vector<bool>(n, false);
            visited[i]=true;
            path.push_back(i);
            if(solve(i, 0, adjList))
            return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    int n = 5;  // Number of vertices
    int m = 7;  // Number of edges
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 1},
        {1, 3},
        {2, 4}
    };
    if (sol.check(n, m, edges))
        cout << "Hamiltonian Path exists" << endl;
    else
        cout << "Hamiltonian Path does not exist" << endl;
    return 0;
}