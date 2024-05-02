#include "Plateau.h"

Plateau::Plateau()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				carre[i][j][k] = ' ';
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		carre[i][1][1] = 'N';
	}
	for (int i = 0; i < 9; i++) {
		pionX.push_back('X');
		pionY.push_back('Y');
	}
	NombrePlateau++;
	pere = NULL;
}

Plateau::Plateau(const Plateau& plateau)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				carre[i][j][k] = plateau.carre[i][j][k];

			}
		}
	}
	for (int i = 0; i < 3; i++) {
		carre[i][1][1] = 'N';
	}
	pionX = plateau.pionX;
	pionY = plateau.pionY;
	pionX_Sur_Plateau = plateau.pionX_Sur_Plateau;
	pionY_Sur_Plateau = plateau.pionY_Sur_Plateau;
	NombrePlateau++;
	pere = NULL;
}

Plateau::~Plateau()
{
	pionX.clear();
	pionY.clear();
	pionX_Sur_Plateau.clear();
	pionY_Sur_Plateau.clear();
	NombrePlateau--;
}

int Plateau::NombrePlateau = 0;

void Plateau::AddFils(Plateau* child)
{
	fils.push_back(child);
}

void Plateau::GenererSucesseur(char type)
{
	char contre_type;
	if (type == 'X') {
		contre_type = 'Y';
	}
	else {
		contre_type = 'X';
	}
	if (!((pionX.empty() && pionX_Sur_Plateau.size() < 3) || (pionY.empty() && pionY_Sur_Plateau.size() < 3))) {
		if (!pionX.empty() || !pionY.empty()) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					for (int k = 0; k < 3; k++) {
						if (carre[i][j][k] == ' ') {
							Plateau* fil = new Plateau(*this);
							fil->SetCase(contre_type, i, j, k);
							fil->ChangerListeMoulin(pere);
							fil->ChangerListeMoulinDejaTraite(pere);
							if (!fil->EstExisteMoulin(contre_type)) {
								AddFils(fil);
							}
							else {
								for(std::vector<MOULIN>::iterator it=fil->ListeMoulin.begin(); it!=fil->ListeMoulin.end();it++){
									if (!EstMoulinExiste(*it, this->pere->ListeMoulinDejaTraite)) {
										for (int x=0; x < 3; x++) {
											for (int y = 0; y < 3; y++) {
												for (int z = 0; z < 3; z++) {
													if (carre[x][y][z] == type) {
														Plateau* fil1 = new Plateau(*fil);
														fil1->SetCase(' ', x, y, z);
														fil1->AjouterMoulinAListeDejaTraiter(*it);
														AddFils(fil1);
														
														
													}
												}
											}
										}
									}
								}
							}


						}
					}
				}
			}
		}
	}
}

void Plateau::SetCase(char type, int i, int j, int k)
{
	carre[i][j][k] = type;
}

bool Plateau::EstExisteMoulin(char type)
{
	bool existe = false;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {

				if (k != 1 && j != 1) {
					if (GetCase(i, j, k) == type) {
						if (j == 0) {
							if (GetCase(i, j + 1, k) == type && GetCase(i, j + 2, k) == type) {
								existe = true;
								Index A,  B,  C;
								A = CreeIndex(i, j, k);
								B = CreeIndex(i, j + 1, k);
								C = CreeIndex(i, j + 2, k);
								CreeMoulin(A, B, C);


							}

							if (k == 0 && GetCase(i, j, k + 1) == type && GetCase(i, j, k + 2) == type) {
								existe = true;
								Index A,  B,  C;
								A = CreeIndex(i, j, k);
								B = CreeIndex(i, j, k + 1);
								C = CreeIndex(i, j, k + 2);
								CreeMoulin(A, B, C);


							}


						}

						else if (j == 2) {
							if (k == 0 && GetCase(i, j, k + 1) == type && GetCase(i, j, k + 2) == type) {
								existe = true;
								Index A,  B,  C;
								A = CreeIndex(i, j, k);
								B = CreeIndex(i, j, k + 1);
								C = CreeIndex(i, j, k + 2);
								CreeMoulin(A, B, C);
							}
						}
					}
				}
				else {
					if (i == 0) {
						if (GetCase(i, j, k) == type) {
							if (GetCase(i + 1, j, k) == type && GetCase(i + 2, j, k) == type) {
								existe = true;
								Index A,  B,  C;
								A = CreeIndex(i, j, k);
								B = CreeIndex(i + 1, j, k);
								C = CreeIndex(i + 2, j, k);
								CreeMoulin(A, B, C);


							}
						}
					}

				}
			}




		}
	}
	return existe;
}

void Plateau::CreeMoulin(Index A, Index B, Index C)
{
	MOULIN M;
	M.pion1.i = A.i;
	M.pion1.j = A.j;
	M.pion1.k = A.k;

	M.pion2.i = B.i;
	M.pion2.j = B.j;
	M.pion2.k = B.k;

	M.pion3.i = C.i;
	M.pion3.j = C.j;
	M.pion3.k = C.k;
	ListeMoulin.push_back(M);
}

char Plateau::GetCase(int i, int j, int k)
{
	return carre[i][j][k];
}

void Plateau::AfficherPlateau()
{
	std::cout << carre[0][0][0] << "(00)----------------------" << carre[0][0][1] << "(01)----------------------" << carre[0][0][2] << "(02)\n";
	std::cout << "|                           |                           |\n";
	std::cout << "|       " << carre[1][0][0] << "(08)--------------" << carre[1][0][1] << "(09)--------------" << carre[1][0][2] << "(10)     |\n";
	std::cout << "|       |                   |                    |      |\n";
	std::cout << "|       |                   |                    |      |\n";
	std::cout << "|       |        " << carre[2][0][0] << "(16)-----" << carre[2][0][1] << "(17)-----" << carre[2][0][2] << "(18)       |      |\n";
	std::cout << "|       |         |                   |          |      |\n";
	std::cout << "|       |         |                   |          |      |\n";
	std::cout << carre[0][1][0] << "(03)---" << carre[1][1][0] << "(11)----" << carre[2][1][0] << "(19)               " << carre[2][1][2] << "(20)----" << carre[1][1][2] << "(12)---" << carre[0][1][2] << "(04)\n";
	std::cout << "|       |         |                   |          |      |\n";
	std::cout << "|       |         |                   |          |      |\n";
	std::cout << "|       |        " << carre[2][2][0] << "(21)-----" << carre[2][2][1] << "(22)-----" << carre[2][2][2] << "(23)       |      |\n";
	std::cout << "|       |                   |                    |      |\n";
	std::cout << "|       |                   |                    |      |\n";
	std::cout << "|       " << carre[1][2][0] << "(13)--------------" << carre[1][2][1] << "(14)--------------" << carre[1][2][2] << "(15)     |\n";
	std::cout << "|                           |                           |\n";
	std::cout << "|                           |                           |\n";
	std::cout << carre[0][2][0] << "(05)----------------------" << carre[0][2][1] << "(06)----------------------" << carre[0][2][2] << "(07)\n";
}

void Plateau::ChangerListeMoulinDejaTraite(const Plateau* P)
{
	if (P != NULL) {
		ListeMoulinDejaTraite = P->ListeMoulinDejaTraite;
	}
}

void Plateau::ChangerListeMoulin(const Plateau *P)
{
	if (P != NULL) {
		ListeMoulin = P->ListeMoulin;
	}
}

void Plateau::AjouterMoulinAListeDejaTraiter(MOULIN M)
{
	ListeMoulinDejaTraite.push_back(M);
}

void Plateau::AfficherSucceseur()
{
	for (std::vector<Plateau*>::iterator it = fils.begin(); it != fils.end(); it++) {
		(*it)->AfficherPlateau();
		std::cout << "\n\n\n\n";
	}
}

bool EstMoulinExiste(MOULIN M, std::vector<MOULIN> Liste)
{
	bool existe;
	existe = false;
	for (std::vector<MOULIN>::iterator it = Liste.begin(); it != Liste.end(); it++) {
		if (DeuxIndexSontEgaux(M.pion1, it->pion1) && DeuxIndexSontEgaux(M.pion2, it->pion2) && DeuxIndexSontEgaux(M.pion3, it->pion3)) {
			existe = true;
			break;
		}
		if (DeuxIndexSontEgaux(M.pion1, it->pion2) && DeuxIndexSontEgaux(M.pion2, it->pion1) && DeuxIndexSontEgaux(M.pion3, it->pion3)) {
			existe = true;
			break;

		}
		if (DeuxIndexSontEgaux(M.pion1, it->pion2) && DeuxIndexSontEgaux(M.pion2, it->pion3) && DeuxIndexSontEgaux(M.pion3, it->pion1)) {
			existe = true;
			break;

		}
		if (DeuxIndexSontEgaux(M.pion1, it->pion1) && DeuxIndexSontEgaux(M.pion2, it->pion3) && DeuxIndexSontEgaux(M.pion3, it->pion2)) {
			existe = true;
			break;

		}
		if (DeuxIndexSontEgaux(M.pion1, it->pion3) && DeuxIndexSontEgaux(M.pion2, it->pion1) && DeuxIndexSontEgaux(M.pion3, it->pion2)) {
			existe = true;
			break;

		}
		if (DeuxIndexSontEgaux(M.pion1, it->pion3) && DeuxIndexSontEgaux(M.pion2, it->pion1) && DeuxIndexSontEgaux(M.pion3, it->pion1)) {
			existe = true;
			break;

		}
		
	}
	return existe;
}

bool DeuxIndexSontEgaux(Index A, Index B)
{
	bool resultat = true;
	if (A.i != B.i || A.j != B.j || A.k != B.k) {
		resultat = false;
	}
	return resultat;
}

Index CreeIndex(int a, int b, int c) {
	Index A;
	A.i = a;
	A.j = b;
	A.k = c;

	return A;
}

