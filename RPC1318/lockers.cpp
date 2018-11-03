#include <bits/stdc++.h>
using namespace std;
#define forsn(i, s, n) for (tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define dforsn(i, s, n) for (tint i = (tint)(n); i >= (tint)(s); i--)
#define dforn(i, n) dforsn(i, 0, n)
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long tint;

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << v << endl;
#else
#define debug(v)
#endif

vector<pair<int, int>> sf;
bool comp(int lhs, int rhs) { return sf[lhs] < sf[rhs]; }

struct SuffixArray {
    // sa guarda los indices de los sufijos ordenados
    vector<int> sa;
    vector<int> r;
    void init(const string& a, int n) {  // O(nlg²n) !!!
        sf = vector<pair<int, int>>(n);
        sa = vector<int>(n);
        r = vector<int>(n);

        forn(i, n) r[i] = a[i];
        for (int m = 1; m < n; m <<= 1) {
            forn(i, n) sa[i] = i,
                       sf[i] = make_pair(r[i], i + m < n ? r[i + m] : -1);
            stable_sort(sa.begin(), sa.end(), comp);
            r[sa[0]] = 0;
            forsn(i, 1, n) r[sa[i]] =
                sf[sa[i]] != sf[sa[i - 1]] ? i : r[sa[i - 1]];
        }
    }
} sa;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    string so;
    tint no;
    tint n;
    string s;
    SuffixArray sa;

    cin >> n >> k >> so;
    no = so.size();
    s = so + so;
    n = s.size();

    debug(s);
    debug(n);

    sa.init(s, n);

    // do thing
    vector<bool> marked(no, false);
    set<int> ends;
    tint countMark = 0;
    tint res = -1;
    forn(i, n) {
        if (sa.sa[i] >= no)
            continue;

        tint pt = sa.sa[i];

        tint toMark = k;
        if(marked[pt]) {
            auto nxtIt = ends.upper_bound(pt+k);
            if(nxtIt != ends.begin()) {
                nxtIt--;
                tint nxt = *nxtIt;
                toMark = max((tint)0, k - (nxt - pt));
                pt = nxt % no;

                if(toMark > 0) {
                    ends.erase(nxtIt);
                }
            }
        }

        for(; toMark > 0; toMark--) {
            if (marked[pt]) {
                break;
            } else {
                marked[pt] = true;
                countMark++;
                pt = (pt + 1) % no;

                if(toMark == 1) {
                    if(not marked[pt]) {
                        ends.insert(pt);
                        ends.insert(pt+no);
                    }
                }
            }
        }

        if (countMark >= no) {
            res = sa.sa[i];
            break;
        }
    }

    forn(i, k) { cout << s[res + i]; }
    cout << endl;

    for(auto m : marked)
        cerr << m;
    cerr << endl;
    for (auto e : ends)
        cerr << e;
    cerr << endl;
    return 0;
}
