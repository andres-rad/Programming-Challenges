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

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

#define EPS 1e-8

int a;
struct info
{
    double sentido; //N = 1, S = -1
    double inicio;
    double radio;
};

map<double, info> mm[2];

double f(double x){
    auto norte = mm[0].lower_bound(x)->snd;
    auto sur = mm[1].lower_bound(x)->snd;
    //debug(x);
    //debug(norte.inicio);
    //debug(norte.radio);
    //debug(sur.inicio);
    //debug(sur.radio);

    double altnorte = 0;
    if (x - norte.inicio > norte.radio){
        altnorte += sqrt(norte.radio*norte.radio - (x - norte.inicio - norte.radio)*(x - norte.inicio - norte.radio));
        //cerr<<"yuhu"<<endl;
    }else{
        altnorte += sqrt(norte.radio*norte.radio - (norte.radio - x + norte.inicio)*(norte.radio - x + norte.inicio));
    }

    double altsur = 0;
    if (x - sur.inicio > sur.radio){
        altsur += sqrt(sur.radio*sur.radio - (x - sur.inicio - sur.radio)*(x - sur.inicio - sur.radio));
    }else{
        altsur += sqrt(sur.radio*sur.radio - (sur.radio - x + sur.inicio)*(sur.radio - x + sur.inicio));
    }

    //debug(altnorte*norte.sentido);
    //debug(altsur*sur.sentido);

    return (a + altnorte*norte.sentido) - altsur*sur.sentido;
}


int main() {

    while(cin >> a) {
        if(a == -1) break;
        mm[0].clear();
        mm[1].clear();

        set<int> interesantes;
        forn(i, 2){
            int c;
            char sentch;
            cin>>c>>sentch;
            int sent = (sentch == 'N' ? 1 : -1);
            int inicio = 0;

            forn(j, c){
                int r;
                cin>>r;

                interesantes.insert(inicio);
                interesantes.insert(inicio + r);

                mm[i][inicio + 2*r] = {sent, inicio, r};
                debug(inicio);
                debug(r);



                inicio += r*2;
                sent = (sent == 1 ? -1 : 1);
            }
        }

        double mini = 1e9;

        debug(f(4));
        debug(f(5));
        debug(f(6));
        //return 0 ;
        for (auto it = interesantes.begin(); it!=interesantes.end()--; it++){
            auto it2 = it;
            double lo = *it;
            double hi = *(++it2);
            debug(lo);
            debug(hi);
            mini = min(mini, f(hi));
            mini = min(mini, f(lo));

            //it--;

            while (hi - lo > EPS){
                double di = f(lo + (hi - lo)/3) - f(lo);
                double dm = f(lo + 2*(hi - lo)/3) - f(lo + (hi-lo)/3);
                double dd = f(hi) - f(lo + 2*(hi - lo)/3);

                debug(lo);
                debug(hi);

                debug(di);
                debug(dm);
                debug(dd);

                if (di < 0 && dd > 0){
                    if (dm < 0){
                        lo = lo + (hi - lo)/3;
                    }else{
                        hi = lo + 2*(hi - lo)/3;
                    }
                }else if (di < 0 && dd < 0){
                    lo = lo + (hi - lo)/3;

                }else if (di > 0 && dd > 0){
                    hi = lo +  2*(hi - lo)/3;

                }else{
                    mini = min(mini, f(hi));
                    mini = min(mini, f(lo));
                    //cerr<<"caso raro"<<endl;
                    break;
                }


            }

            debug(f(hi));
            debug(mini);
            mini = min(mini, f(hi));

        }

        cout<<setprecision(2)<<fixed<<mini<<endl;



    }

    return 0;
}
