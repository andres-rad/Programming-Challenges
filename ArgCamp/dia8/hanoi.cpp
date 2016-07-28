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
#include <sstream>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef long long int tint;

int n;
int cadena[250];
	

bool anala(int pos, int res){
	if (pos<0) return true;
	
	else if (cadena[pos]==res) return false;
	else{
		if (res==2){
			return anala(pos-1, 1);
		}else if (res==1){
			return anala(pos-1, 2);
		}
	}
}

bool anal(int pos, int a, int d, int r){
	if (pos<0) return true;
	
	else if (cadena[pos]==residual) return false;
	
	else return anal(pos-1, a,r,d);
	
}

int posiciones[250];

void proc(int a, int b, int c, int n){
	if (n==0) return;
	forn (i,5){
		cout<<(char)(posiciones[i]+'A') ;
	}
	cout<<endl;
	
	proc(a,c,b,n-1);
	posiciones[5-n]=b;
	//cout<<"DISk "<<n<<" from "<<a<<" to "<<b<<endl;
	forn (i,5){
		cout<<(char)(posiciones[i]+'A') ;
	}
	cout<<endl;
	proc(c,b,a,n-1);
}
		

bool analb(int pos, int res){
	if (pos<0) return true;
	
	else if (cadena[pos]==res) return false;
	else{
		if (res==2){
			return anala(pos-1, 0);
		}else if (res==0){
			return anala(pos-1, 2);
		}
	}
	
}

/* 
 * A=0
 * B=1
 * C=2
*/

int main(){
	

	
	
	
	cin>>n;
	
	forn (i,n){
		char temp;
		cin>>temp;
		
		cadena[i]=temp-'A';
	}
	bool flag;
	if (cadena[n-1]==0){
		flag=anala(n-1, 2);
	}else if (cadena[n-1]==1){
		flag=analb(n-1, 2);
	}else{
		flag=false;
	}
	
	cout<<(flag?"YES":"NO")<<endl;
	
	
	
	
	
	
	return 0;
}
