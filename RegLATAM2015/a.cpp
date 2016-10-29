#include <bits/stdc++.h>
using namespace std;

#define forsn(i,s,n) for(long i=s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define pb push_back

long check(long n, const vector<long> &dig) {
	for(long i=n; i >= 0; i--) {
		if(dig[i] < 2) 
			return i;
	}
	return -1;
}

int main() {
	long n;

	while(cin >> n) {
		vector<long> num;
		long n2 = n;

		while(n2 > 0) {
			num.pb(n2%10);
			n2 /= 10;
		}
		reverse(num.begin(), num.end());

		vector<long> dig(10,0);

		long ma = -1;
		long man = -1;
		vector<long> mav;

		bool fail = false;
		forn(i,num.size()) {
			if(dig[num[i]] >= 2) {
				long l = check(num[i]-1, dig);
				if(l >= 0) {
					ma = i;
					man = l;
					mav = dig;
					mav[l]++;
				}

				fail = true;
				break;
			}

			dig[num[i]]++;

			long ll = check(num[i]-1, dig);
			if(ll >= 0) {
				ma = i;
				man = ll;
				mav = dig;
				mav[num[i]]--;
				mav[ll]++;
			}
		}

		if(fail == true) {
			if(ma >= 0) {
				long last = 9;
				num[ma] = man;
				forsn(i, ma + 1, num.size()) {
					while(last > 0 and mav[last] >= 2) {
						last--;
					}
					num[i] = last;
					mav[last]++;
				}
			} else {
				num.pop_back();
				forn(i, num.size()) {
					num[i] = 9 - (i/2);
				}
			}
		}

		bool first = true;
		for(long c : num) {
			if(first and c == 0) continue;
			first = false;
			printf("%d", c);
		}
		printf("\n");


		//long gtg = true;
		//while(i < num.size()) {
		//	cout << "i num[i] " << i << " " << num[i] << endl;
		//	if(dig[num[i]] < 2) {
		//		dig[num[i]]++;
		//		i++;
		//	} else {
		//		bool found = false;
		//		for(long l=i-1; l >= 0; l++) {
		//			if(dig[l] < 2) {
		//				num[i] = l;
		//				dig[l]++;
		//				i++;
		//				found =true;
		//				break;
		//			}
		//		}
		//		if(!found) {
		//			if(i>0) {
		//				dig[num[i]]--;
		//				i--;
		//				num[i]--;
		//			}
		//			else {
		//				gtg = false;
		//				break;
		//			}
		//		}
		//	}
		//}
		//if(gtg) {
		//	for(long c : num) {
		//		printf("%d", c);
		//	}
		//	printf("\n");
		//} else {
		//	// un digito menos
		//	forn(i,num.size()-1) {
		//		printf("%d", 9 - (i/2));
		//	}
		//	printf("\n");
		//}
	}

	return 0;
}