#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second
#define debug(v) cerr << #v << " = " << (v) << endl;
#define pb push_back

struct trie{
	int yes;
	map<char, trie> next;
};

trie patricia;
double ans;

void insert(string a, trie & pat){
	if (a.empty()){
		pat.yes = 1;
	}else{
		insert(a.substr(1, string::npos), pat.next[a[0]]);
	}

}

int dfs(trie & pat, int cnt){
	if (pat.yes){
		ans+=cnt;
	}

	int add = (pat.yes || pat.next.size()>1 ? 1 : 0);
	for (auto p:pat.next){
		dfs(p.snd, cnt+add);
	}
}

int main() {
	int n;

	while (cin>>n){
		forn(i,n){
			string temp;
			cin>>temp;
			insert(temp, patricia);
		}
		
		dfs(patricia, (patricia.next.size() > 1 ? 0 : 1));

		cout<<setprecision(2)<<fixed<<ans/((double) n)<<endl;	




		//cin>>n;
		ans = 0;
		patricia.yes = 0;
		patricia.next.clear();
	}


	return 0;
}