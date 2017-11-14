#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define first fst
#define second snd
#define push_back pb
#define make_pair mp
typedef long long tint;

#ifdef DEBUG
#define debug(v) cerr<< #v << " = " << v << endl;
#else 
#define debug(v) 
#endif

bool vo(char c) {
	return c == 'a' or c == 'e' or 
		   c == 'i' or c == 'o' or c == 'u';
}

  
int main(){
	string s;
	cin >> s;
	
	int n = s.length();
	
	int i = 0, j=n-1;
	
	int cV = 0;
	int cNV = 0;
	
	if(not vo(s[0])) {
		bool hasVo = false;
		for(char c : s) hasVo = hasVo or vo(c);
		cout << (hasVo ? 0 : 1) << endl;
		return 0;
	}
	
	bool fw = false;
	while(i < j) {
		if(fw) {
			if(vo(s[i])) {
				cV++;
				fw = false;
				cNV = 0;
				//debug(j);
				j--;
			} else {
				cNV++;
				//debug(cNV);
				//debug(i);
				i++;
			}
		} else {
			if(vo(s[j])) {
				cV++;
				fw = true;
				cNV = 0;
				//debug(i);
				i++;
			} else {
				cNV++;
				//debug(j);
				//debug(cNV);
				j--;
			}
		}
	}
	
	debug(i);
	debug(j);
	cout << cNV + 1 << endl;
	
	return 0;
}
