#include <bits/stdc++.h>
using namespace std;
#define int long long

class segtree
{
private:
    vector<pair<int, int>> tree;
    vector<int> arr;
    int n;
    void build(int ind, int left, int right)
    {
        if (left == right)
        {
            tree[ind].first = arr[left];
            tree[ind].second = 1;
            return;
        }
        int mid = (left + right) / 2;
        build(2 * ind + 1, left, mid);
        build(2 * ind + 2, mid + 1, right);
        int mini = min(tree[2 * ind + 1].first, tree[2 * ind + 2].first);
        tree[ind].first = mini;
        if (tree[2 * ind + 1].first == mini)
            tree[ind].second += tree[2 * ind + 1].second;
        if (tree[2 * ind + 2].first == mini)
            tree[ind].second += tree[2 * ind + 2].second;
    }

    pair<int, int> query(int ind, int l, int r, int ql, int qr)
    {
        //    no overlap
        if (ql > r || l > qr)
            return {INT_MAX, 0};
        //   complete overlap

        if (ql <= l && qr >= r)
            return {tree[ind].first, tree[ind].second};
        int mid = (l + r) / 2;
        pair<int, int> ans;
        pair<int, int> lq = query(2 * ind + 1, l, mid, ql, qr);
        pair<int, int> rq = query(2 * ind + 2, mid + 1, r, ql, qr);
        ans.first = min(lq.first, rq.first);
        if (lq.first == ans.first)
            ans.second += lq.second;
        if (rq.first == ans.first)
            ans.second += rq.second;
        return ans;
    }

    void update(int ind, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            arr[pos] = val;
            tree[ind].first = val;
            tree[ind].second = 1;
            return;
        }

        int mid = (l + r) / 2;
        if (pos <= mid)
        {
            update(2 * ind + 1, l, mid, pos, val);
        }
        else
        {
            update(2 * ind + 2, mid + 1, r, pos, val);
        }

        int mini = min(tree[2 * ind + 1].first, tree[2 * ind + 2].first);
        tree[ind].first = mini;
        tree[ind].second = 0;
        if (tree[2 * ind + 1].first == mini)
            tree[ind].second += tree[2 * ind + 1].second;
        if (tree[2 * ind + 2].first == mini)
            tree[ind].second += tree[2 * ind + 2].second;
    }

public:
    segtree(vector<int> &a)
    {
        n = a.size();
        arr = a;
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    pair<int, int> getmin(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }

    void upd(int pos, int val)
    {
        return update(0, 0, n - 1, pos, val);
    }
};

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    segtree st(a);

    while (m--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int pos, val;
            cin >> pos >> val;
            st.upd(pos, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            r--;
            pair<int, int> ans = st.getmin(l, r);
            cout << ans.first << " " << ans.second << endl;
        }
    }
}
