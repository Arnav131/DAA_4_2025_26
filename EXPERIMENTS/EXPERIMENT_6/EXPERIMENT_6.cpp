// Longest Increasing Subsequence //

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }

        int n = nums.size();
        vector<int>dp(n,1);

        for(int i = 1 ; i <n ; i++){
            for(int j = 0 ;j<i ; j++ ){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int length = sol.lengthOfLIS(nums);
    cout << "Length of Longest Increasing Subsequence: " << length << endl;
    return 0;
}