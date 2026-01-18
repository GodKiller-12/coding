#include <bits/stdc++.h>
using namespace std;
#define int long long

class segtree
{
private:
    vector<vector<int>> tree;
    string s;
    int n;
    void build(int ind, int left, int right)
    {
        if (left == right)
        {
            tree[ind][s[left] - 'a'] = 1;
            return;
        }
        int mid = (left + right) / 2;
        build(2 * ind + 1, left, mid);
        build(2 * ind + 2, mid + 1, right);

        for (int i = 0; i < 26; i++)
        {
            tree[ind][i] = tree[2 * ind + 1][i] | tree[2 * ind + 2][i];
        }
    }

    vector<int> query(int ind, int l, int r, int ql, int qr)
    {
        //    no overlap
        if (ql > r || l > qr)
        {
            vector<int> p(26, 0);
            return p;
        }
        //   complete overlap

        if (ql <= l && qr >= r)
            return tree[ind];

        int mid = (l + r) / 2;

        vector<int> lq = query(2 * ind + 1, l, mid, ql, qr);
        vector<int> rq = query(2 * ind + 2, mid + 1, r, ql, qr);

        vector<int> ans(26, 0);
        for (int i = 0; i < 26; i++)
            ans[i] = lq[i] | rq[i];
        return ans;
    }

    void update(int ind, int l, int r, int pos, char val)
    {
        if (l == r)
        {
            tree[ind][s[pos] - 'a'] = 0;
            s[pos] = val;
            tree[ind][s[pos] - 'a'] = 1;
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
        for (int i = 0; i < 26; i++)
        {
            tree[ind][i] = tree[2 * ind + 1][i] | tree[2 * ind + 2][i];
        }
    }

public:
    segtree(string &str)
    {
        n = str.size();
        s = str;
        tree.resize(4 * n, vector<int>(26, 0));
        build(0, 0, n - 1);
    }

    vector<int> getsum(int l, int r)
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
    string s;
    cin >> s;
    int m;
    cin >> m;
    segtree st(s);
    while (m--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int pos;
            char val;
            cin >> pos >> val;
            pos--;
            st.upd(pos, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            vector<int> p = st.getsum(l, r);
            int count = 0;
            for (int i = 0; i < 26; i++)
            {
                count += p[i];
            }
            cout << count << endl;
        }
    }
}
