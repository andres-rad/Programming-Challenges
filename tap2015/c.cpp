#include "math.h"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "iostream"

#define tint long long
#define utint unsigned long long
#define forsn(i,s,n) for(tint i = s; i < n; i++)
#define forn(i,n) forsn(i,0,n)

using namespace std;

int main() {
	tint n,s,j,d;

	ios::sync_with_stdio(false);

	while(cin >> n) {
		//scanf("%zu %zu %zu %zu\n", &n, &s, &j, &d);
		cin >> s >> j >> d;

		tint sa=0, sb=0, ga = 0, gb=0;

		forn(i,n) {
			char res;
			//scanf("%c", &res);
			cin >> res;

			if(res == 'A') {
				ga++;
			} else {
				gb++;
			}

			if(ga >= j and ga-gb >= d) {
				sa++;
				ga=gb=0;
			} else if(gb >= j and gb-ga >= d) {
				sb++;
				ga=gb=0;
			}

		}

		cout << sa << " " << sb << endl;

	}

	return 0;
}
