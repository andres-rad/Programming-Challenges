#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define fst first
#define snd second
#define pb push_back
#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

int main() {
    tint n, k;
    cin >> n >> k;

    tint cnt = 0;
    vector<char> ans;
    while (n>0){
        if (cnt <= k){
            n--;
            k-=cnt;
            cnt++;
            ans.pb('(');
        }else{
            cnt--;
            ans.pb(')');
        }
    }

    cnt--;
    while(cnt>=0){
        ans.pb(')');
        cnt--;
    }


    if (k>0){
        cout<<"Impossible"<<endl;
        return 0;
    }
    for (auto a:ans){
        cout<<a;
    }
    cout<<endl;

    return 0;
}
