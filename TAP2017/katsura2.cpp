#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define sq(x) ((x) * (x))
#define all(v) ((v).begin, (v).end)
#define x real()
#define y imag()
#define pb push_back
#define f first
#define s second
#define mp make_pair
typedef long long  tint;

#ifdef DEBUG
#define debug(v) cerr << #v << " = " << (v) << endl;
#else
#define debug(v)
#endif

using namespace std;
typedef pair<int,int> par;

//vector<par> a;

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	vector<int> impares;
	int n; int m;
	cin >> n;
	vector<int> puedo (32, 0);
	vector<int> copia(32,0);
	puedo[0] = 1;
	forn(i,n)
	{
		cin >> m;

		if (m&1){
			int cant = 1;
			int aux = m / 2;
			while(aux & 1)
			{
				cant++;
				aux = aux>>1;
			}
			//par p;
			//p.f = cant;
			/*
			cant = 0;
			if (aux == 0){
				cant = 20;
			}
			*/
			/*
			while(aux > 0 and (not (aux&1))){
				cant++;
				aux /= 2;
			}
			*/
			//p.s = cant;
			impares.pb(cant);
			//debug(p.f);
			//debug(p.s);
			//// ordenados por cuanto me cuesta parificar y despues por si me agrega una div gratis
		}else{
			int temp = m;
			forn(j, 32){
				copia[j] = puedo[j];
			}
			//copia = puedo;
			int cnt = 0;
			while (temp > 0){
				//debug(temp);
				//debug(not (temp&1));
				//debug(cnt);
				if (not (temp&1)){
					for (int i = cnt; i < 32; i ++){
						//debug(i);
						if (copia[i-cnt])
							puedo[i] = 1;
					}
				}
				temp = temp>>1;
				cnt++;
			}
			for (int i = cnt; i<32; i++){
				// si lo lleve a 0 en menos de 32, agrego todo lo demas
				puedo[i] = 1;
			}
		}

	}

	/*forn(i, puedo.size()){
		debug(i);
		debug(puedo[i]);
	}*/
	sort(impares.begin(), impares.end());

	vector<tint> add(impares.size() + 3);
	//int first00 = -1;
	add.pb(0);
	//int cnt = 1;
	tint temp;
	forn(cnt, impares.size()){
		temp = impares[cnt];
		add[cnt + 1] = add[cnt] + temp;

		/*debug(add[add.size() - 1]);
		if (first00 == -1 and p.second > 1){
			first00 = p.first;
		}*/
	}
	//debug(first00);

	int lo = 0; int hi = 2*n;

	int ODD = (int)impares.size();

	if(ODD == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	// con hi se puede, con lo no
	// quien hace esto asi? jajja
	//debug(ODD);
	while(hi - lo > 1)
	{
		int m = (hi + lo) / 2;
		bool can = false;

		//quiero ver si lo puedo hacer con m

		// si puedo dividir a por lo menos ODD - m, listo
		// pero necesito una division si m == ODD 00, o entre 1 y las que me sobren

		//debug(hi);
		//debug(lo);
		//debug(m);
		if (m > ODD){
			// si tengo 1 ODD, divido a este m-1 veces y multiplico a otro y bla
			// si tengo 2 ODD, multiplico a uno m-1>=2 veces, despues divido a ese y mult al OTRO
			// si tengo 3 o mas ODD hago como arriba
			can = true;
		}else if (m == ODD){
			// si tengo 1 ODD, si puedo dividir a otro, lo divido y mult a este, o tambien divido a este y mult a un par
			// si tengo 2 o mas ODD, siempre puedo us
			if (add[1] <= m){
				can = true;
			}
			for (int i = 1; i<=m and (not can); i++){
				if (i >= 32 or puedo[i]){
					can = true;
					//break;
				}
			}

		}else{
			// m < ODD
			// tonce m div a los impares, si me da justito, tipo, agarro a ODD-m chabones, gane
			// si no llego a agarrar ODD-m tipos, perdi
			// si me sobran div...
			// si necesito menos de m divisiones para ODD-m chabones, donde mando las otras??
			// digamos que me sobran s div, notemos que s < m, entonces, seguro se las puedo encajar a algunos de los que multiplico?
			//																								yo diria que si, kent
			if (add[ODD-m] <= m){
				can = true;
			}
		}
		//debug(can);
		if(can) hi = m;
		else lo = m;


	}

	cout << hi << endl;

	return 0;
}
