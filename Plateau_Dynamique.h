#pragma once
#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;



typedef struct {
	int i, j, k;
}Index;



typedef struct {
	Index pion1;
	Index pion2;
	Index pion3;
}MOULIN;











typedef struct {
	Noeud* tete;
	int taille;
}Pile;








class Plateau_Dynamique
{
	char carre[3][3][3];
	std::vector<char> pionX;
	std::vector<char> pionY;
	std::vector<char> pionX_Sur_Plateau;
	std::vector<char> pionY_Sur_Plateau;
	std::vector<MOULIN> ListeMoulin;
	std::vector<MOULIN> MoulinDejaTraite;
	std::vector<Index> CaseSuprimer;
	Pile *listeSuccesseur;
	


	static int NombrePlateau;


public:
	Plateau_Dynamique();
	Plateau_Dynamique(const Plateau_Dynamique&);
	~Plateau_Dynamique();
	void GenererSuccesseur(const char Type);
	bool CaseDejaTraiter(char type, int i, int j, int k);
	char GetCase(int i, int j, int k);
	void SetCase(char type, int i, int j, int k);
	void Pop_Back_Pion(char type);
	int GetNombrePionXSurPlateau(char type);
	bool EstFinJeu();
	int GetNombreDeMoulin();
	bool EstExisteMoulin(char type);
	void CreeMoulin(Index* A , Index* B, Index* C);
	bool EstCaseSupprimer(int i, int j, int k);
	void InsrerCaseSupprimer(int i, int j, int k);





};

typedef struct {
	Noeud* tete;
	int taille;
}Pile;

typedef struct etat {
	Plateau_Dynamique moulin;
	int h;
}etat;

typedef struct Noeud {
	etat Etat;
	struct Noeud* suivant;
}Noeud;

Index* CreeIndex(int a, int b, int c);
bool EstMoulinSontEgaux(MOULIN A, MOULIN B);

etat Depiler(Pile* P);

Noeud* CreeNoeud(etat E);

Pile* CreePile();




void Empiler(Pile* P, etat E);








