#include <bits/stdc++.h>
using namespace std;
#define tint long long
#define forsn(i,s,n) for(tint i = (tint)(s); i < (tint)(n); i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for(tint i = (tint)(n)-1; i >= (tint)(s); i--)
#define dforn(i,n) dforsn(i,0,n)
#define fst first
#define snd second

int main() {
	tint n,m;

	while(cin >> n) {
		cin >> m;

		tint cnt = 0;
		forsn(i,n,m+1) {
			vector<bool> nums(10, false);
			tint num = i;
			while(num > 0) {
				if(nums[num % 10]) {
					cnt++;
					break;
				}
				nums[num % 10] = true;
				num /= 10;
			}
		}
		cout << (m-n+1-cnt) << endl;
	}

	return 0;
}