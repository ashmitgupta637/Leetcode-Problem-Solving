class Solution {
public:
    struct Node {
        long long score = -1;
        vector<int> idxs;
    };

    int n;
    vector<int> nextIdx;
    vector<vector<Node>> dp;

    int findNext(vector<vector<int>>& intervals, int r) {
        int lo = 0;
        int hi = n - 1;
        int result = n;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (intervals[mid][0] > r) {
                result = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return result;
    }

    Node solve(vector<vector<int>>& intervals, int i, int k) {

        
        if (k == 0 || i >= n) {
            Node base;
            base.score = 0;
            return base;
        }

        if (dp[i][k].score != -1) {
            return dp[i][k];
        }

   
        Node skip = solve(intervals, i + 1, k);

      
        int wt = intervals[i][2];
        int idx = intervals[i][3];

        int j = nextIdx[i];

        Node temp = solve(intervals, j, k - 1);

        Node take;

        take.score = temp.score + wt;
        take.idxs = temp.idxs;

        take.idxs.push_back(idx);

        sort(take.idxs.begin(), take.idxs.end());

        Node result;

        if (skip.score > take.score) {
            result = skip;
        }
        else if (skip.score < take.score) {
            result = take;
        }
        else {
            
            result = (skip.idxs < take.idxs) ? skip : take;
        }

        return dp[i][k] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        nextIdx.resize(n);

        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            nextIdx[i] = findNext(intervals, end);
        }

        int k = 4;

        
        dp.assign(n, vector<Node>(k + 1));

        return solve(intervals, 0, k).idxs;
    }
};