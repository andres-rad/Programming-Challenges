#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define forsn(i,s,n) for(int i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(int i=n; i-->s;)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define pb push_back

int main() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    int res = 0;
    forn(i,s.size()) {
        if(s[i] == 'A') res++;
        else res--;
    }

    if(res == 0) {
        cout << "Friendship" << endl;
    } else if (res > 0) {
        cout << "Anton" << endl;
    }
    else {
        cout << "Danik" << endl;
    }

    return 0;
}
