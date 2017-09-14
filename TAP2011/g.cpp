#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i=(tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i=(tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define pb push_back
#define ii pair<tint, tint>
#define dd pair<double, double>

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

struct control {
    double max;
    double min;
    tint x;
}

vector<control> cs;

double vFinal(double v0, double dx, double a) {
    return sqrt(max(0, v0*v0 + 2 * a * t));
}

int main() {
    int n;

    while(cin >> n) {
        if(n == -1) break;

        tint l, a ,d;
        cin >> l >> a >> d;

        cs = vector<control>(n+2);
        cs[0] = {0,0,0};
        cs[n+1] = {0,0,l};

        forn(i,n) {
            cin >> cs[i+i].x >> cs[i+i].min >> cs[i+i].max;
        }

        vector<dd> minmaxFw(n+2);
        vector<dd> minmaxBw(n+2);

        forsn(i,1,n+2) {
            minmaxFw[i].min = max(0, max(cs[i].min,
                vFinal(cs[i-1].min, cs[i].x - cs[i-1].x, -d)));
            minmaxFw[i].max = max(cs[i].max,
                vFinal(cs[i-1].max, cs[i].x - cs[i-1].x, a));
        }
        dforn(i,n+1) {
            minmaxBw[i].min = max(0, max(cs[i].min,
                vFinal(cs[i+1].min, cs[i+1].x - cs[i].x, -a)));
            minmaxBw[i].max = max(cs[i].max,
                vFinal(cs[i+1].max, cs[i+1].x - cs[i].x, d));
        }

        bool error = false;
        vector<dd> minmax(n+2);
        forn(i,n) {
            minmax[i].min = max(minmaxFw[i].min, minmaxBw[i].min);
            minmax[i].max = max(minmaxFw[i].max, minmaxBw[i].max);

            if(minmax[i].min > minmax[i].max) {
                error = true;
                break;
            }
        }

        double res = 0;
        forn(i,n) {
            // sumar el tiempo de los segmentos
        }

        if(not error)
            cout << setprecision(2) << fixed << res << endl;
        else
            cout << "*" << endl;
    }

    return 0;
}
