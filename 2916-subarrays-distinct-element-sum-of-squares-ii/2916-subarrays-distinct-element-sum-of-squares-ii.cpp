
class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sumSq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, long long val) {
        long long len = r - l + 1;

        tree[node].sumSq =
            (tree[node].sumSq
             + 2 * val * tree[node].sum
             + len * val * val) % MOD;

        tree[node].sum =
            (tree[node].sum + len * val) % MOD;

        tree[node].lazy =
            (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        long long val = tree[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long val) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, val);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        tree[node].sum =
            (tree[node * 2].sum +
             tree[node * 2 + 1].sum) % MOD;

        tree[node].sumSq =
            (tree[node * 2].sumSq +
             tree[node * 2 + 1].sumSq) % MOD;
    }

    long long query(int node, int l, int r,
                    int ql, int qr) {
        if (ql > r || qr < l)
            return 0;

        if (ql <= l && r <= qr)
            return tree[node].sumSq;

        push(node, l, r);

        int mid = l + (r - l) / 2;

        return (query(node * 2, l, mid, ql, qr)
              + query(node * 2 + 1, mid + 1, r, ql, qr))
              % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());

        unordered_map<int, int> last;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int left = 0;

            if (last.count(nums[i])) {
                left = last[nums[i]] + 1;
            }

            update(1, 0, n - 1, left, i, 1);

            last[nums[i]] = i;

            ans = (ans + query(1, 0, n - 1, 0, i)) % MOD;
        }

        return ans;
    }
};
