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

#define MAXG 200000
#define MAXD 210
#define MAXS 11

using namespace std;

typedef long long int tint;
typedef pair<int,int> par;

tint comb[MAXD][MAXD];
double dp[MAXD][MAXD][8][8];

int PR[8][8];

double prob[8][8];
double pr_match[8][8];
double E_match[8][8];
double E[8][8];

void calc_comb()
{
	forn(n, 2 * MAXS)
	{
		comb[n][0] = 1;
		comb[n][n] = 1;
	}

	forsn(n,1,2 * MAXS)
	{
		forsn(k,1,n)
		{
			comb[n][k] = comb[n-1][k-1] + comb[n-1][k];
		}
	}
}

double calc_prob(int i, int j, int J, int D)
{
	double ans = 0.0;

	if(PR[i][j] == 100) return 1.0;
	if(PR[i][j] == 0) return 0.0;

	if(PR[i][j] < PR[j][i]) return (1.0 - calc_prob(j,i,J,D));

	// win with J

	forn(lose, J - D + 1)
	{
		//ans += dp[J + lose - 1][J + J - lose - 1] * P * pow(PR[i][j] / 50.0, J) * pow(PR[j][i] / 50.0, lose);
		ans += dp[J-1][lose][i][j] * (PR[i][j] / 100.0);
	}

	// win with more than J

	if(PR[i][j] == 50)
	{
		forsn(n,1,2*D)
		{
			int dif = -D + n;
			if(dif == 0) continue;

			// probability of winning if the difference is of dif games in favour of player i when the first has reached J games
		
			if(dif < 0)
			{
				double p = dp[J + dif][J - 1][i][j] * (PR[j][i] / 100.0);
				ans += p * n / (2 * D + 0.0);
			}
			else
			{
				double p = dp[J - 1][J - dif][i][j] * (PR[i][j] / 100.0);
				ans += p * n / (2 * D + 0.0);
			}
		}
	}
	else
	{
		double u = (100.0 - PR[i][j]) / PR[i][j];
		double U = 1.0 / (pow(u,2*D) - 1.0);

		forsn(n,1,2*D)
		{
			int dif = -D + n;
			if(dif == 0) continue;

			// probability of winning if the difference is of dif games in favour of player i when the first has reached J games
		
			if(dif < 0)
			{
				double p = dp[J + dif][J - 1][i][j] * (PR[j][i] / 100.0);
				ans += p * (pow(u,n) - 1.0) * U;
			}
			else
			{
				double p = dp[J - 1][J - dif][i][j] * (PR[i][j] / 100.0);
				ans += p * (pow(u,n) - 1.0) * U;
			}
		}
	}

	return (ans);
}

double calc_exp(int i, int j, int J, int D)
{
	double ans = 0.0;

	if(PR[i][j] == 100.0) return J;
	if(PR[i][j] == 0.0) return J;

	if(PR[i][j] < PR[j][i]) return (calc_exp(j,i,J,D));

	// expected number of games for match ending at J games

	forn(lose, J - D + 1)
	{
		ans += (J + lose) * (dp[J-1][lose][i][j] * (PR[i][j] / 100.0) + dp[lose][J-1][i][j] * (PR[j][i] / 100.0) );
		//ans += (J + lose) * comb[J-1+lose][lose] * ( pow(PR[i][j] / 100.0, J) * pow(PR[j][i] / 100.0, lose) );
	}

	// more than J games for the winner
	
	if(PR[i][j] == 50)
	{
		forsn(n,1,2*D)
		{
			int dif = -D + n;
			if(dif == 0) continue;
		
			if(dif < 0)
			{
				double p = dp[J + dif][J - 1][i][j] * (PR[j][i] / 100.0);
				double e = n * (2 * D - n);
				ans += p * (e + 2 * J + dif);
			}
			else
			{
				double p = dp[J - 1][J - dif][i][j] * (PR[i][j] / 100.0);
				double e = n * (2 * D - n);
				ans += p * (e + 2 * J - dif);
			}
		}
	}
	else
	{
		double u = (100.0 - PR[i][j]) / PR[i][j];
		double U = ( (pow(u, 2 * D) - 1.0) / (u - 1.0) );
		double X = ( 100.0 / (PR[i][j] * U) ) * (1.0 / (u - 1.0) ) * ( U - 2 * D );
	
		//cout << "u U X " << u << " " << U << " " << X << endl;

		forsn(n,1,2*D)
		{
			int dif = -D + n;
			if(dif == 0) continue;
		
			if(dif < 0)
			{
				double p = dp[J + dif][J - 1][i][j] * (PR[j][i] / 100.0);
				double e = X * ( (pow(u,n) - 1.0) / (u - 1.0) ) - ( (pow(u,n) - 1.0) / (u - 1.0) - n ) * (100.0 / PR[i][j] ) * ( 1.0 / (u - 1.0) ) ;
				ans += p * (e + 2 * J + dif);
				//cout << (pow(u,n) - 1.0) << " " << (u - 1.0) << " " << (pow(u,n) - 1.0) / (u - 1.0) << endl;
				//cout << dif << " " << dp[J + dif][J - 1][i][j] << " " << p << " " << e << " " << ans << endl;
			}
			else
			{
				double p = dp[J - 1][J - dif][i][j] * (PR[i][j] / 100.0);
				double e = X * ( (pow(u,n) - 1.0) / (u - 1.0) ) - ( (pow(u,n) - 1.0) / (u - 1.0) - n ) * (100.0 / PR[i][j] ) * ( 1.0 / (u - 1.0) ) ;
				ans += p * (e + 2 * J - dif);
				//cout << (pow(u,n) - 1.0) << " " << (u - 1.0) << " " << (pow(u,n) - 1.0) / (u - 1.0) << endl;
				//cout << dif << " " << dp[J - 1][J - dif][i][j] << " " << p << " " << e << " " << ans << endl;
			}
		}
	}

	return (ans);
}

int main()
{	
	int K,S,J,D,N;

	cout.precision(2);
	cout.setf(ios::showpoint | ios::fixed);
	calc_comb();
	
	while(cin >> K >> S >> J >> D and K > 0)
	{
		N = (1<<K);
		forn(i,N) forn(j,N) cin >> PR[i][j];

		memset(dp, 0, sizeof(dp[0][0][0][0]) * MAXD * MAXD * 8 * 8);
		
		forn(i,N)
		{
			forn(j,N)
			{
				if(i == j) continue;

				forn(win, J)
				{
					forn(lose, J)
					{
						if(win == 0 and lose == 0)
						{
							dp[win][lose][i][j] = 1.0;
							continue;
						}

						dp[win][lose][i][j] = (win ? dp[win-1][lose][i][j] * (PR[i][j] / 100.0) : 0) + (lose ? dp[win][lose-1][i][j] * (PR[j][i] / 100.0) : 0);
					}
				}
			}
		}
		
		forn(i,N)
		{
			forn(j,N)
			{
				if(i == j) continue;
				prob[i][j] = calc_prob(i, j, J, D);
				E[i][j] = calc_exp(i, j, J, D);
			}
		}

		forn(i,N)
		{
			forn(j,N)
			{
				if(i == j) continue;

				pr_match[i][j] = 0.0;
				forn(L,S)
				{
					pr_match[i][j] += (comb[S-1+L][L] * pow(prob[i][j],S) * pow(1.0 - prob[i][j],L));
				}
			}
		}

		forn(i,N)
		{
			forn(j,N)
			{
				if(i == j) continue;

				E_match[i][j] = 0.0;
				forn(L,S)
				{
					//cout << i << " " << j << " " << L << " " << (S + L) * (E[i][j] + E[j][i]) * (comb[S-1+L][L] * pow(prob[i][j], S) * pow(prob[j][i], L)) << endl;
					E_match[i][j] += (S + L) * (E[i][j] ) * comb[S-1+L][L] * (pow(prob[i][j], S) * pow(1.0 - prob[i][j], L) + pow(1.0 - prob[i][j], S) * pow(prob[i][j], L) );
				}
			}
		}
		/*
		cout << "Probability of winning a set" << endl;

		forn(i,N)
		{
			forn(j,N)
			{
				cout << prob[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl << "Expectation of quantity of games per set" << endl;

		forn(i,N)
		{
			forn(j,N)
			{
				cout << E[i][j] << " ";
				//cout << (E[i][j] + E[j][i]) << " ";
			}
			cout << endl;
		}

		cout << endl << "Probability of winning the whole match" << endl;

		forn(i,N)
		{
			forn(j,N)
			{
				cout << pr_match[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl << "Expected number of games played per match" << endl;
		
		forn(i,N)
		{
			forn(j,N)
			{
				cout << E_match[i][j] << " ";
			}
			cout << endl;
		}
		*/
		vector<int> arr(N);
		forn(i,N) arr[i] = i;

		double ans = 0.0;
		do
		{
			double cnd = 0.0;
			double al[8];

			forn(i, N) al[i] = 1.0;

			int LEG = 1;
			int M = N / 2;
			forn(R,K)
			{
				double aux_al[8];
				forn(i,N) aux_al[arr[i]] = 0;
				forn(m,M)
				{
					forsn(f, 2 * m * LEG, 2 * m * LEG + LEG )
					{
						forsn(s, (2 * m + 1) * LEG, (2 * m + 1) * LEG + LEG)
						{
							cnd += al[arr[f]] * al[arr[s]] * E_match[arr[f]][arr[s]];
							aux_al[arr[f]] += pr_match[arr[f]][arr[s]] * al[arr[f]] * al[arr[s]];
							aux_al[arr[s]] += pr_match[arr[s]][arr[f]] * al[arr[f]] * al[arr[s]];
						}
					}
				}
				LEG *= 2;
				M /= 2;

				forn(i,N) al[arr[i]] = aux_al[arr[i]];
			}
			ans = max(ans, cnd);

		} while(next_permutation(arr.begin(), arr.end()));


		cout << ans << endl;
	}

	return 0;
}