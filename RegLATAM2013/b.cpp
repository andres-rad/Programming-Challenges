#include <bits/stdc++.h>
#define forsn(i,s,n) for(int i = s; i<n; i++)
#define forn(i,n) forsn(i,0,n)
#define dforn(i,n) for(int i = (n-1); i>=0; i--)
#define pb push_back
#define fst first
#define mp make_pair
#define snd second

using namespace std;

typedef pair<int,int> Elem; 
typedef bool Alt;

const Elem neutro=mp(-1,100000000); const Alt neutro2=false;

Elem operacion(Elem a, Elem b){
	return mp(max(a.fst,b.fst), min(a.snd,b.snd));


}

#define MAXN 100000

		string match;
		string orig;

struct RMQ{
	int sz;
	Elem t[4*MAXN];
	Alt dirty[4*MAXN];
	Elem &operator[](int p){return t[sz+p];}
	void init(int n){
		sz=1<<(32-__builtin_clz(n));
		//cerr<<sz<<endl;
		forn(i, 2*sz) t[i]=neutro;
		forn(i, 2*sz) dirty[i]=neutro2;

	}

	void push(int n, int a, int b){
		if (dirty[n]!=neutro2){
			//t[n]+=dirty[n]*(b-a);
			if (t[n].fst!=-1 && dirty[n]){
				t[n]=mp(match.size()-t[n].snd, match.size()-t[n].fst);
			}			


			if (n<sz){
				dirty[2*n]=dirty[n];
				dirty[2*n+1]=dirty[n];
			}
			dirty[n]=neutro2;
		}
	}

	Elem get(int i, int j, int n, int a, int b){
		if (j<=a || i>=b) return neutro;
		push(n,a,b);
		if (i<=a && b<=j) return t[n];
		int c=(a+b)/2;
		//cerr<<"abro"<<endl;
		return operacion(get(i,j,2*n,a,c), get(i,j,2*n+1,c,b));
	}
	

	Elem get(int i, int j){return get(i,j,1,0,sz);}

	void alterar(Alt val, int i, int j , int n,int a, int b){
		push(n,a,b);
		if (j<=a || i>=b) return ;
		if (i<=a && b<=j){
			dirty[n]=!dirty[n];
			push(n,a,b);
			return;
		}
		int c=(a+b)/2;
		alterar(val,i,j,2*n,a,c), alterar(val,i,j,2*n+1,c,b);
		t[n]=operacion(t[2*n], t[2*n+1]);
		
	}

	void alterar(Alt val, int i,int j){
		dforn(h,match.size()-1){
			if(t[j-h].fst!=-1 && h>0){
				string temp=orig.substr(j-h, match.size());
				int dif=0;
				forn (k, match.size()){
					bool alt=k<h;
					int n=(j-h+k+sz)/2;
					while(n>0){
						alt=alt ^ dirty[n];
						n/=2;

					}

					if( (alt && match[k]==temp[k]) || (!alt && match[k]!=temp[k])){
						dif++;
					}
				}

				t[j-h+sz]=mp(max(dif,t[j-h+sz].fst), min(dif, t[j-h+sz].snd));
				int n=(j-h+sz)/2;
				while (n>0){
					t[n]=operacion(t[2*n], t[2*n+1]);
					n=n/2;
				}
			}
		}

		alterar(val,i,j-match.size()+1,1,0,sz);
	}

	void updall(){
		dforn(i,sz){

			t[i]=operacion(t[2*i], t[2*i+1]);
			//cerr<<"veo el "<<2*i<<" y "<<2*i+1<<endl; 
			//cerr<<t[i]<<" es el max entre "<<t[2*i]<<" y "<<t[2*i+1]<<endl;
		}
	}
};

int main() {
	long n;

	while (cin >> n){

		cin>>match>>orig;

		RMQ seg;
		seg.init(orig.size());

		forn(j,orig.size()){
			string temp=orig.substr(j, match.size());
			int tot=0;
			int dif=0;
			forn (i, match.size()){
				if (tolower(match[i])==tolower(temp[i])) tot++;
				if( match[i]!=temp[i]){
					dif++;
				}
			}

			if (tot==match.size()) seg[j]=mp(dif,dif);
			

			//cerr<<"dif "<<j<<' '<<seg[j]<<endl;
		}

		//forn(i, seg.sz){
		//	cerr<<"db "<<seg[i]<<endl;
		//}

		seg.updall();

		forn(i,n){

			forn(j, orig.size()){
				//cerr<<j<<" "<<seg[j]<<endl;
			}
			int a, b;
			cin>>a>>b;
			cout<<seg.get(a-1,b-match.size()).fst<<endl;
			seg.alterar(0,a-1,b);

			forn(i,seg.sz){
			//	cerr<<i<<" "<<seg.t[i]<<endl;
			}
		}




	}

	return 0;
}