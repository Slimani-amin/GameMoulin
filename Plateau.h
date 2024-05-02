#pragma once

#include <iostream>
#include <vector>
#include <stdbool.h>

typedef struct {
	int i, j, k;
}Index;

typedef struct {
	Index pion1;
	Index pion2;
	Index pion3;
}MOULIN;


class Plateau
{
	char carre[3][3][3];
	std::vector<char> pionX;
	std::vector<char> pionY;
	std::vector<Index> pionX_Sur_Plateau;
	std::vector<Index> pionY_Sur_Plateau;
	std::vector<MOULIN> ListeMoulin;
	std::vector<MOULIN> ListeMoulinDejaTraite;

	Plateau* pere;

	
	std::vector<Plateau*> fils;

	static int NombrePlateau;

public:
	Plateau();
	Plateau(const Plateau&);
	~Plateau();
	void AddFils(Plateau* child);
	void GenererSucesseur(char type);
	void SetCase(char type, int i, int j, int k);
	bool EstExisteMoulin(char type);
	void CreeMoulin(Index A, Index B, Index C);
	char GetCase(int i, int j, int k);
	void AfficherPlateau();
	void ChangerListeMoulinDejaTraite(const Plateau*);
	void ChangerListeMoulin(const Plateau*);
	void AjouterMoulinAListeDejaTraiter(MOULIN);
	void AfficherSucceseur();

};

bool EstMoulinExiste(MOULIN M, std::vector<MOULIN> Liste);

bool DeuxIndexSontEgaux(Index A, Index B);

Index CreeIndex(int a, int b, int c);

