/*
    MY YOUTUBE VIDEO ON THIS Qn : 
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/partition-array-for-maximum-sum/
*/

/********************************************************** C++ ******************************************************************/
//Approach-1 (Recursion + Memo)
//T.C : With Memoization - O(n*k) -> We visit only n states in dp array and everytime run a for loop of size k
//      Without Memoization - We have 2 options at each index - O(k * 2^n)
//S.C : O(n)
class Solution {
public:
    int n;
    int t[501];
    int solve(vector<int>& arr, int idx, int k) {
        if(idx >= n) {
            return 0;
        }
        
        if(t[idx] != -1) {
            return t[idx];
        }
        
        int result = 0;
        int curr_max = -1;
        for(int i = idx; i < n && i-idx+1 <= k; i++) {
            curr_max = max(curr_max, arr[i]);
            
            result = max(result, curr_max*(i-idx+1) + solve(arr, i+1, k));
        }
        
        return t[idx] = result;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n = arr.size();
        memset(t, -1, sizeof(t));
        return solve(arr, 0, k);
    }
};


//Approach-2 (Bottom Up)
//T.C : O(n*k)
//S.C : O(n)
class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] t = new int[n + 1];
        
        //t[i] = Maximum sum for the partition arr[0 to i]
        //we need to find max for whole array = t[n]
        for (int i = 0; i <= n; i++) {
            int currMax = -1;
            //Let's move back till k positions and find the best result
            for (int j = 1; j <= k && i - j >= 0; j++) {
                currMax = Math.max(currMax, arr[i - j]);
                t[i] = Math.max(t[i], t[i - j] + currMax * j);
            }
        }

        return t[n];
    }
}


/********************************************************** JAVA ******************************************************************/
//Approach-1 (Recursion + Memo)
//T.C : With Memoization - O(n*k) -> We visit only n states in dp array and everytime run a for loop of size k
//      Without Memoization - We have 2 options at each index - O(k * 2^n)
//S.C : O(n)
class Solution {
    private int n;
    private int[] t;

    public int maxSumAfterPartitioning(int[] arr, int k) {
        n = arr.length;
        t = new int[501];
        Arrays.fill(t, -1);
        return solve(arr, 0, k);
    }

    private int solve(int[] arr, int idx, int k) {
        if (idx >= n) {
            return 0;
        }

        if (t[idx] != -1) {
            return t[idx];
        }

        int result = 0;
        int currMax = -1;
        for (int i = idx; i < n && i - idx + 1 <= k; i++) {
            currMax = Math.max(currMax, arr[i]);

            result = Math.max(result, currMax * (i - idx + 1) + solve(arr, i + 1, k));
        }

        return t[idx] = result;
    }
}


//Approach-2 (Botom Up)
//T.C : O(n*k)
//S.C : O(n)
class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] t = new int[n + 1];
        
        //t[i] = Maximum sum for the partition arr[0 to i]
        //we need to find max for whole array = t[n]
        for (int i = 0; i <= n; i++) {
            int currMax = -1;
            //Let's move back till k positions and find the best result
            for (int j = 1; j <= k && i - j >= 0; j++) {
                currMax = Math.max(currMax, arr[i - j]);
                t[i] = Math.max(t[i], t[i - j] + currMax * j);
            }
        }

        return t[n];
    }
}
