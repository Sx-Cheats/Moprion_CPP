#include <iostream>
#include<vector>
#include<time.h>
#include<stdlib.h>
using namespace std;

typedef vector<vector<int>> MATRICE_3x3;
typedef vector<vector<string>> MATRICE_STRING;

struct Player {
	MATRICE_3x3 MATRICE = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };
	string SIGNE;
	string PLAYER_NAME;
	int WON=0;

};
int CALC_ROW(MATRICE_3x3 R)
{
	for (int x = 0; x < R.size(); ++x)
		if ((R[x][0]+R[x][1]+ R[x][2])==3)
			return 1;
	return 0;
	
}
int CALC_COLUMNS(MATRICE_3x3 C)
{
	for (int x=0;x < C[0].size();++x)
		if ((C[0][x]+ C[1][x]+ C[2][x])==3)
			 return 1;
	return 0;
}
int CALC_DIAGONAL(MATRICE_3x3 D)
{
	if ((D[0][0] + D[1][1] + D[2][2] == 3) || (D[0][2] + D[1][1] + D[2][0]) == 3)
		return 1;
	return 0;
}
int CALC_MATRICE(MATRICE_3x3 CP)
{
	if (CALC_ROW(CP) || CALC_COLUMNS(CP) || CALC_DIAGONAL(CP))
		return 1;

	return 0;
}
void TABLE_FOMRAT(MATRICE_STRING M)
{
	for (auto x = 0; x < M.size(); ++x)
	{
		for (auto xx = 0; xx < M[x].size(); ++xx)
		{
			
		if (!(xx % 3))
		{
			cout << string(5, '\n');
		};
		cout << string(7, ' ') << M[x][xx];
	    }
	};
	cout <<"\n\n\n";
};
void SET_POS(Player& CP,MATRICE_3x3 CP_2, MATRICE_STRING &GLOBAL_T)
{
	int POS[2];
	while (((POS[0] < 0 || POS[0] > 3) && (POS[1] < 0 || POS[1] > 3)) || CP_2[POS[0]][POS[1]] ==1)
	{
		cout << "POSITION Y ? : ";
		scanf("%d", &POS[0]);
		cout << "POSITION X ? : ";
		scanf("%d", &POS[1]);
	}
	GLOBAL_T[POS[0]][POS[1]] = CP.SIGNE;
	CP.MATRICE[POS[0]][POS[1]] = 1;
	TABLE_FOMRAT(GLOBAL_T);
	CP.WON = CALC_MATRICE(CP.MATRICE);

}
int SUM(MATRICE_STRING ARRAY)
{
	int G=0;
	for (auto x : ARRAY)
	{
		for (auto xx : x)
		{
			if (xx != "0")
				G++;
		}
	}
	return G==9;
}
int main()
{
	srand(time(NULL));
	bool TURN = rand ()%2;
	MATRICE_STRING GLOBAL_MATRICE = { {"0","0","0"}, {"0","0","0"},{"0","0","0"} };
	Player Player1;
	Player1.SIGNE = 'X';
	Player1.PLAYER_NAME = "BOB";
	
	Player Player2;
	Player2.SIGNE = 'O';
	Player2.PLAYER_NAME = "JEAN";
	TABLE_FOMRAT(GLOBAL_MATRICE);
	 do 
	{
		if (TURN == 1)
		{
			cout << Player2.PLAYER_NAME << " TURN\n\n";
			SET_POS(Player2,Player1.MATRICE, GLOBAL_MATRICE);
		}
		else
		{
			cout << Player1.PLAYER_NAME << " TURN\n\n";
			SET_POS(Player1, Player2.MATRICE, GLOBAL_MATRICE);
		};
		TURN = !TURN;
	 } while (!Player1.WON && !Player2.WON && !SUM(GLOBAL_MATRICE));
	cout << (Player1.WON ? Player1.PLAYER_NAME : Player1.WON ? Player2.PLAYER_NAME:"EQUALITY") << " WON\n";
	system("pause");
	return EXIT_SUCCESS; //0
}
