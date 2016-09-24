#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

#define forn(i,n) for (int i=0;i<n;i++)
#define pb push_back
#define fs first
#define sd second


int main () {
  
  int n;
  cin>>n;

	int bempr, rempr, bempb, rempb;
	bempr=rempr=bempb=rempb=0;
	char bnext='b', rnext='r';
	
	forn (i,n){
		char cur;
		cin>>cur;
		
		if (bnext!=cur){
			if (cur=='b'){
				bempb++;
			}else{
				rempb++;
			}
		}else{
			if (cur=='b'){
				bempr++;
			}else{
				rempr++;
			}
		}
		
		if (bnext=='b'){
			bnext='r'; rnext='b';
		}else {
			bnext='b'; rnext='r';
		}
	}
	
	cout<<min(max(bempb, rempb), max(bempr,rempr))<<endl;
	
  return 0;
}
