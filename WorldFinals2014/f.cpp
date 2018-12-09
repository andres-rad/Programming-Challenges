// Messenger

#include <bits/stdc++.h>
using namespace std;
typedef long long tint;
#define forsn(i, s, n) for (tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i, n) forsn(i, 0, n)
#define fst first
#define snd second
#define pb push_back
#define ii pair<tint, tint>
#define dd pair<double, double>
#define segment pair<dd, dd>

#ifdef DEBUG
#define debug(v) cerr << #v << ": " << (v) << endl;
#define pdebug(v) cerr << #v << ": " << (v).fst << "," << (v).snd << endl;
#define dassert(x) assert(x)
#else
#define debug(v)
#define pdebug(v)
#define dassert(x)
#endif

const double EPS = 1e-4;
const double EPS2 = 1e-5;

vector<dd> a;
vector<dd> b;
tint n, m;
double distA;
double distB;

double dist2(dd u, dd v) {
    double dx = v.fst - u.fst;
    double dy = v.snd - u.snd;
    return dx * dx + dy * dy;
}

double dist(dd u, dd v) { return sqrt(dist2(u, v)); }

dd mover(dd from, dd to, double d, double distP = -1) {
    double dx = to.fst - from.fst;
    double dy = to.snd - from.snd;
    if (distP < 0) {
        distP = dist(from, to);
    }
    return {from.fst + dx * d / distP, from.snd + dy * d / distP};
}

double segmentDist(segment u, segment v) {
    // Asumo que tienen el mismo largo
    dassert(fabs(dist(u.fst, u.snd) - dist(v.fst, v.snd)) < EPS);

    double totDist = dist(u.fst, u.snd);

    double xLL = dist(u.fst, v.fst);
    double xRR = dist(u.snd, v.snd);

    while (totDist > EPS2) {
        double l = totDist / 3;
        double r = l * 2;

        dd uL = mover(u.fst, u.snd, l, totDist);
        dd uR = mover(u.fst, u.snd, r, totDist);
        dd vL = mover(v.fst, v.snd, l, totDist);
        dd vR = mover(v.fst, v.snd, r, totDist);

        double xL = dist(uL, vL);
        double xR = dist(uR, vR);

        if (xLL < xL or xLL < xR or (xRR > xL and xRR > xR and xLL < xRR)) {
            u.snd = uR;
            v.snd = vR;
            xRR = dist(u.snd, v.snd);
            totDist = totDist * 2 / 3;
        } else {
            u.fst = uL;
            v.fst = vL;
            xLL = dist(u.fst, v.fst);
            totDist = totDist * 2 / 3;
        }
    }
    return xLL;
}

bool hayMenor(double x) {
    //debug("Hay menor");
    //debug(x);

    size_t i = 1, j = 1;
    dd currA = a[0];
    dd currB = b[0];

    double distToI = dist(currA, a[i]);
    double distToJ = dist(currB, b[j]);

    // Adelantar
    double restX = x;
    while (j < b.size()) {
        if (restX >= distToJ) {
            restX -= distToJ;
            currB = b[j];
            j++;
            distToJ = dist(currB, b[j]);
        } else {
            currB = mover(currB, b[j], restX, distToJ);
            distToJ = dist(currB, b[j]);
            break;
        }
    }
    if (j == b.size()) {
        return restX < EPS and dist(a[0], b[j - 1]) - x < EPS;
    }

    debug(i);
    debug(j);
    debug(distToI);
    debug(distToJ);

    // buscar de a segmentos
    while (i < a.size() and j < b.size()) {
        segment u, v;
        if (fabs(distToI - distToJ) < EPS) {
            u.fst = currA;
            u.snd = a[i];
            v.fst = currB;
            v.snd = b[j];

            i++;
            j++;
            currA = a[i - 1];
            currB = b[j - 1];
            if (i < a.size() and j < b.size()) {
                distToI = dist(currA, a[i]);
                distToJ = dist(currB, b[j]);
            }
        } else if (distToI < distToJ) {
            u.fst = currA;
            u.snd = a[i];
            v.fst = currB;
            v.snd = mover(currB, b[j], distToI, distToJ);

            i++;
            currA = a[i - 1];
            currB = v.snd;
            if (i < a.size()) {
                distToI = dist(currA, a[i]);
                distToJ = dist(currB, b[j]);
            }
        } else {
            u.fst = currA;
            u.snd = mover(currA, a[i], distToJ, distToI);
            v.fst = currB;
            v.snd = b[j];

            j++;
            currA = u.snd;
            currB = b[j - 1];
            if (j < b.size()) {
                distToI = dist(currA, a[i]);
                distToJ = dist(currB, b[j]);
            }
        }

        pdebug(u.fst);
        pdebug(u.snd);
        pdebug(v.fst);
        pdebug(v.snd);
        debug(segmentDist(u, v));
        debug(segmentDist(u, v) - x);

        if (segmentDist(u, v) - x < EPS)
            return true;
    }

    return false;
}

void binaria() {
    double minX = 0;
    double maxX = distB;

    if (not hayMenor(maxX)) {
        cout << "impossible\n";
        return;
    }
    if (hayMenor(0)) {
        cout << 0.0 << "\n";
        return;
    }

    debug("--------------------- ");

    while (maxX - minX > EPS) {
        double mid = (maxX + minX) / 2;

        if (hayMenor(mid)) {
            maxX = mid;
        } else {
            minX = mid;
        }
    }
    cout << minX << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << setprecision(20) << fixed;

    while (cin >> n) {
        a.clear();
        a.resize(n);
        distA = 0;
        forn(i, n) {
            cin >> a[i].fst >> a[i].snd;
            if (i > 0)
                distA += dist(a[i], a[i - 1]);
        }

        cin >> m;
        b.clear();
        b.resize(m);
        distB = 0;
        forn(i, m) {
            cin >> b[i].fst >> b[i].snd;
            if (i > 0)
                distB += dist(b[i], b[i - 1]);
        }

        binaria();

        //cerr << "\n-------------------------------------------\n\n";
    }

    return 0;
}
