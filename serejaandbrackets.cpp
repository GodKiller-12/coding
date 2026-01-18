#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second

class segtree
{
private:
    vector<pair<pair<int, int>, int>> tree;
    string s;
    int n;
    void build(int ind, int left, int right)
    {
        if (left == right)
        {
            tree[ind].s = 0;
            if (s[left] == '(')
                tree[ind].f.f++;
            else
                tree[ind].f.s++;
            return;
        }
        int mid = (left + right) / 2;
        build(2 * ind + 1, left, mid);
        build(2 * ind + 2, mid + 1, right);

        tree[ind].s = tree[2 * ind + 1].s + tree[2 * ind + 2].s + min(tree[2 * ind + 1].f.f, tree[2 * ind + 2].f.s);
        tree[ind].f.f = tree[2 * ind + 1].f.f - min(tree[2 * ind + 1].f.f, tree[2 * ind + 2].f.s) + tree[2 * ind + 2].f.f;
        tree[ind].f.s = tree[2 * ind + 2].f.s - min(tree[2 * ind + 1].f.f, tree[2 * ind + 2].f.s) + tree[2 * ind + 1].f.s;
    }

    pair<pair<int, int>, int> query(int ind, int l, int r, int ql, int qr)
    {
        //    no overlap
        if (ql > r || l > qr)
            return {{0, 0}, 0};
        //   complete overlap
        if (ql <= l && qr >= r)
            return tree[ind];
        int mid = (l + r) / 2;
        pair<pair<int, int>, int> ans;
        pair<pair<int, int>, int> lq = query(2 * ind + 1, l, mid, ql, qr);
        pair<pair<int, int>, int> rq = query(2 * ind + 2, mid + 1, r, ql, qr);
        ans.s = lq.s + rq.s + min(lq.f.f, rq.f.s);
        ans.f.f = lq.f.f - min(lq.f.f, rq.f.s) + rq.f.f;
        ans.f.s = rq.f.s - min(lq.f.f, rq.f.s) + lq.f.s;
        return ans;
    }

public:
    segtree(string &str)
    {
        n = str.size();
        s = str;
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    pair<pair<int, int>, int> getmin(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }
};

signed main()
{
    string s;
    cin >> s;
    int m;
    cin >> m;

    segtree st(s);

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        pair<pair<int, int>, int> ans = st.getmin(l, r);
        cout << ans.s * 2 << endl;
    }
}
