#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <set>
#include <cassert>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;



int main(){
	//criba();
	
	/*for (char c = 'A'; c-0<='A'+60; c=(char)c+1){
		cout<<c<<c-0<<endl;
	}*/
	int g,n;
	cin>>g>>n;
	
	cout<<g<<" "<<n<<endl;
	char c ='A';
	forn(i,g){
		cout<<c;
		c=c+1;
		if (c=='Z') c='a';
		if (c=='z') c='A';
		//c=(char)(((int)c)%'z')+'A';
	}
	cout<<endl;
	forn(i,n){
		cout<<c;
		c=(char)c+1;
		if (c=='Z') c='a';
		if (c=='z') c='A';
		//c=(char)((((int)c)%'z')+'A');
	}
	
	
	
	
	return 0;
}
