struct Node {
    int remain[5] = {0};
    int prod = 1;
};

class SegmentTree {
public:
    explicit SegmentTree(const vector<int>& nums, int k) : n(nums.size()), k(k), tree(4 * n) {
        build(nums, 0, 0, n - 1);
    }

    void update(int i, int val) {
        update(0, 0, n - 1, i, val);
    }

    Node query(int i, int j) const {
        return query(0, 0, n - 1, i, j);
    }

private:
    const int n;
    const int k;
    vector<Node> tree;

    void build(const vector<int>& nums, int cur, int left, int right) {
        if (left == right) {
            tree[cur].remain[nums[left] % k] = 1;
            tree[cur].prod = nums[left] % k;
            return;
        }
        int mid = left + (right - left) / 2;
        build(nums, 2 * cur + 1, left, mid);
        build(nums, 2 * cur + 2, mid + 1, right);
        tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
    }

    void update(int cur, int left, int right, int i, int val) {
        if (left == right) {
            tree[cur] = Node();
            tree[cur].remain[val % k] = 1;
            tree[cur].prod = val % k;
            return;
        }
        int mid = left + (right - left) / 2;
        if (i <= mid) {
            update(2 * cur + 1, left, mid, i, val);
        } else {
            update(2 * cur + 2, mid + 1, right, i, val);
        }
        tree[cur] = merge(tree[2 * cur + 1], tree[2 * cur + 2]);
    }

    Node query(int cur, int lo, int hi, int i, int j) const {
        if (i <= lo && hi <= j) {
            return tree[cur];
        }
        int mid = lo + (hi - lo) / 2;
        if (j <= mid) {
            return query(2 * cur + 1, lo, mid, i, j);
        }
        if (i > mid) {
            return query(2 * cur + 2, mid + 1, hi, i, j);
        }
        return merge(query(2 * cur + 1, lo, mid, i, mid), query(2 * cur + 2, mid + 1, hi, mid + 1, j));
    }

    Node merge(const Node& left, const Node& right) const {
        Node node;
        node.prod = (left.prod * right.prod) % k;
        for (int i = 0; i < k; ++i) {
            node.remain[i] = left.remain[i];
        }
        for (int i = 0; i < k; ++i) {
            if (left.remain[i] > 0) {
                int new_rem = (i * right.prod) % k;
                node.remain[new_rem] += left.remain[i];
            }
        }
     
        for (int i = 0; i < k; ++i) {
            if (right.remain[i] > 0) {
                int combined_rem = (left.prod * i) % k;
               
            }
        }
        
        
        Node res;
        res.prod = (left.prod * right.prod) % k;
        for (int i = 0; i < k; ++i) {
            res.remain[i] = left.remain[i];
        }
        for (int i = 0; i < k; ++i) {
            if (right.remain[i] > 0) {
                int rem = (left.prod * i) % k;
                res.remain[rem] += right.remain[i];
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        SegmentTree st(nums, k);
        vector<int> ans;
        for (const auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            st.update(idx, val);
            Node res = st.query(start, n - 1);
            ans.push_back(res.remain[x]);
        }
        return ans;
    }
};