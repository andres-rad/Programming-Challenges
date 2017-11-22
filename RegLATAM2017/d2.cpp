#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define fst first
#define snd second
#define pb push_back
#define mp make_pair
typedef long long tint;
typedef pair<int, int> ii;

#ifdef DEBUG
#define debug(v) cerr<< #v << " = " << v << endl;
#else
#define debug(v)
#endif

int main(){
	tint l, c, n;
	cin >> l >> c >> n;
	map<int, int> inte; // desde este punto hasta el proximo, color es sign

	inte[0] = 0;
    inte[l] = -1;

	unordered_map<int, int> h;

    h[0] = l;

	forn(i, n){
		tint p, x, a, b;
		cin >> p >> x >> a >> b;
		p--;
		x--;

		tint s = h[p];
        debug(s);
		int m1a = (a + s*s) % l;
		int m2a = (a + (s + b)*(s+b)) % l;

		int m1 = min(m1a, m2a);
		int m2 = max(m1a, m2a) + 1;
        debug(m1);
        debug(m2);
        // [m1, m2)

        auto left = --inte.upper_bound(m1);
        auto right = --inte.upper_bound(m2);

        if (left->fst != m1)  left  = inte.insert(mp(m1, left->snd)).fst;
        if (right->fst != m2) right = inte.insert(mp(m2, right->snd)).fst;

        while (left != right){
            debug(left->fst);
            debug(left->snd);
            debug(right->fst);
            debug(right->snd);
            auto prox = left;
            prox++;
            h[left->snd] -= prox->fst - left->fst;
            h[x] += prox->fst - left->fst;
            inte.erase(left);
            left = prox;
        }
        debug(h[x]);
        inte[m1] = x;
    }

    int maxi = -1;

    for(auto d:h){
        maxi = max(maxi, d.snd);
    }

    cout << maxi << endl;

	return 0;
}
