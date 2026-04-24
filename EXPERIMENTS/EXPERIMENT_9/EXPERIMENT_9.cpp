// Here is the complete C++ algorithm for the Minimum Sum Partition problem, placed within the `Solution` class structure you provided.

// This solution uses Dynamic Programming (specifically, the 0/1 Knapsack concept) to find the subset whose sum is closest to half of the total array sum.

class Solution {
  public:
    int minDifference(vector<int>& arr) {
        // 1. Calculate the total sum of the array
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        // 2. The ideal target for one subset is half the total sum
        int target = totalSum / 2;

        // 3. dp[j] will be true if a subset with sum j is possible.
        // We only need to check up to the target sum.
        vector<bool> dp(target + 1, false);
        
        // A sum of 0 is always possible (empty subset)
        dp[0] = true;

        // 4. Populate the DP table
        for (int num : arr) {
            // Traverse backwards from target down to num.
            // Going backwards ensures we only use each element once per subset.
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        // 5. Find the largest possible subset sum (maxSubsetSum) that is <= target
        int maxSubsetSum = 0;
        for (int j = target; j >= 0; --j) {
            if (dp[j]) {
                maxSubsetSum = j;
                break;
            }
        }

        // 6. Calculate the result
        // If subset 1 has sum maxSubsetSum, subset 2 has sum (totalSum - maxSubsetSum).
        // The difference is: (totalSum - maxSubsetSum) - maxSubsetSum 
        // = totalSum - 2 * maxSubsetSum
        return totalSum - 2 * maxSubsetSum;
    }
};