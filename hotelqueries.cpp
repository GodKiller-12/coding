#include <bits/stdc++.h>
using namespace std;
#define int long long

class segtree
{
private:
    vector<int> tree;
    vector<int> arr;
    int n;
    void build(int ind, int left, int right)
    {
        if (left == right)
        {
            tree[ind] = arr[left];
            return;
        }
        int mid = (left + right) / 2;
        build(2 * ind + 1, left, mid);
        build(2 * ind + 2, mid + 1, right);

        tree[ind] = max(tree[2 * ind + 1], tree[2 * ind + 2]);
    }

    int query(int ind, int l, int r, int ql, int qr)
    {
        //    no overlap
        if (ql > r || l > qr)
            return INT_MAX;
        //   complete overlap

        if (ql <= l && qr >= r)
            return tree[ind];

        int mid = (l + r) / 2;

        int ans = min(query(2 * ind + 1, l, mid, ql, qr), query(2 * ind + 2, mid + 1, r, ql, qr));

        return ans;
    }

    int query2(int l, int r, int val)
    {
        //    no overlap
        if (l == r)
        {
            update(0, 0, n - 1, l, arr[l] - val);
            return l;
        }
        int mid = (l + r) / 2;
        int lq = query(0, 0, n - 1, l, mid);
        if (val <= lq)
        {
            return query2(l, mid, val);
        }
        else
        {
            return query2(mid + 1, r, val);
        }
    }

    void update(int ind, int l, int r, int pos, int val)
    {
        if (l == r)
        {
            arr[pos] = val;
            tree[ind] = val;
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

        tree[ind] = max(tree[2 * ind + 1], tree[2 * ind + 2]);
    }

public:
    segtree(vector<int> &a)
    {
        n = a.size();
        arr = a;
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    int getmax(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }

    void upd(int pos, int val)
    {
        return update(0, 0, n - 1, pos, val);
    }
    int rekxybackinghinderson(int val)
    {
        return query2(0, n - 1, val);
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

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        int d = st.getmax(0, n - 1);
        if (x > d)
        {
            cout << 0 << " ";
            continue;
        }
        cout << st.rekxybackinghinderson(x) + 1 << " ";
    }
}
