#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] != 0) return false;

        int r = 0, c = 0;

        vector<int> dx = {2, 2, -1, -2, -2, -1, 1, 1};
        vector<int> dy = {1, -1, 2, 1, -1, -2, -2, 2};

        for (int move = 1; move < n * n; move++) {
            bool found = false;

            for (int k = 0; k < 8; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                    grid[nr][nc] == move) {
                    r = nr;
                    c = nc;
                    found = true;
                    break;
                }
            }

            if (!found) return false;
        }

        return true;
    }
};

int main(){
  return 0;
}
