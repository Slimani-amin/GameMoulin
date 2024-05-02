//#include "Plateau_Dynamique.h"
//using namespace std;
//
//Plateau_Dynamique::Plateau_Dynamique() {
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			for (int k = 0; k < 3; k++) {
//				carre[i][j][k] = ' ';
//			}
//		}
//	}
//	for (int i = 0; i < 3; i++) {
//		carre[i][1][1] = 'N';
//	}
//	for (int i = 0; i < 9; i++) {
//		pionX.push_back('X');
//		pionY.push_back('Y');
//	}
//
//	
//	listeSuccesseur = CreePile();
//
//}
//
//Plateau_Dynamique::Plateau_Dynamique(const Plateau_Dynamique& plateau) {
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			for (int k = 0; k < 3; k++) {
//				carre[i][j][k] = plateau.carre[i][j][k];
//
//			}
//		}
//	}
//	for (int i = 0; i < 3; i++) {
//		carre[i][1][1] = 'N';
//	}
//	pionX = plateau.pionX;
//	pionY = plateau.pionY;
//	pionX_Sur_Plateau = plateau.pionX_Sur_Plateau;
//	pionY_Sur_Plateau = plateau.pionY_Sur_Plateau;
//
//}
//
//Plateau_Dynamique::~Plateau_Dynamique() {
//	delete[] carre;
//	pionX.clear();
//	pionY.clear();
//	pionX_Sur_Plateau.clear();
//	pionY_Sur_Plateau.clear();
//}
//
//void Plateau_Dynamique::GenererSuccesseur(const char type)
//{
//
//	if (EstFinJeu() == false) {
//		if ((type == 'X' && !pionX.empty()) || (type == 'Y' && !pionY.empty())) {
//			for (int i = 0; i < 3; i++) {
//				for (int j = 0; j < 3; j++) {
//					for (int k = 0; k < 3; k++) {
//						if (EstExisteMoulin(type)) {
//							for (vector<MOULIN>::iterator it1 = ListeMoulin.begin(); it1 != ListeMoulin.end(); it1++) {
//								bool DEJA;
//								for (vector<MOULIN>::iterator it2 = MoulinDejaTraite.begin(); it2 != MoulinDejaTraite.end(); it2++) {
//									DEJA = EstMoulinSontEgaux(*it1, *it2);
//									if (DEJA) {
//										break;
//									}
//
//								}
//								if (DEJA == false) {
//									char contre_type;
//									if (type == 'X') {
//										contre_type = 'Y';
//									}
//									else if (type == 'Y') {
//										contre_type = 'X';
//									}
//									for (int x = 0; x < 3; x++) {
//										for (int y = 0; y < 3; y++) {
//											for (int z = 0; z < 3; z++) {
//												if (carre[x][y][z] == contre_type) {
//													Plateau_Dynamique fils(*this);
//													fils.SetCase(type, i, j, k);
//													fils.Pop_Back_Pion(type);
//													etat Etatfils;
//													Etatfils.moulin = fils;
//													Empiler(listeSuccesseur, Etatfils);
//												}
//											}
//										}
//									}
//								}
//
//							}
//						}
//						if (carre[i][j][k] == ' ') {
//							if (CaseDejaTraiter(type, i, j, k) == false) {
//								Plateau_Dynamique fils(*this);
//								fils.SetCase(type, i, j, k);
//								fils.Pop_Back_Pion(type);
//								etat Etatfils;
//								Etatfils.moulin = fils;
//								Empiler(listeSuccesseur, Etatfils);
//							}
//						}
//					}
//				}
//			}
//		}
//		else if ((type == 'X' && pionX.empty()) || (type == 'Y') && pionY.empty()) {
//
//		}
//	}
//	
//}
//
//bool Plateau_Dynamique::CaseDejaTraiter(char type, int i, int j, int k)
//{
//	Noeud* courant;
//	courant = listeSuccesseur->tete;
//	while (courant != NULL) {
//		if (courant->Etat.moulin.GetCase(i, j, k) == type) {
//			return true;
//		}
//		courant = courant->suivant;
//	}
//	return false;
//}
//
//char Plateau_Dynamique::GetCase(int i, int j, int k)
//{
//	return carre[i][j][k];
//	
//}
//
//void Plateau_Dynamique::SetCase(char type, int i, int j, int k)
//{
//	carre[i][j][k] = type;
//}
//
//void Plateau_Dynamique::Pop_Back_Pion(char type)
//{
//	if (type == 'X') {
//		pionX.pop_back();
//	}
//	if (type == 'Y') {
//		pionY.pop_back();
//	}
//}
//
//int Plateau_Dynamique::GetNombrePionXSurPlateau(char type)
//{
//	int cmpt=0;
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			for (int k = 0; k < 3; k++) {
//				if (carre[i][j][k] == type) {
//					cmpt++;
//				}
//			}
//		}
//	}
//	return cmpt;
//}
//
//bool Plateau_Dynamique::EstFinJeu()
//{
//	if ((pionX.empty() && pionX_Sur_Plateau.size() < 3) || (pionY.empty() && pionY_Sur_Plateau.size() < 3)) {
//		return true;
//	}
//	return false;
//}
//
//int Plateau_Dynamique::GetNombreDeMoulin()
//{
//	return ListeMoulin.size();
//}
//
//bool Plateau_Dynamique::EstExisteMoulin(char type)
//{
//	bool existe = false;
//
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			for (int k = 0; k < 3; k++) {
//				
//					if (k != 1 && j != 1) {
//						if (GetCase(i, j, k) == type) {
//							if (j == 0 ) {
//								if (GetCase(i, j + 1, k) == type && GetCase(i, j + 2, k) == type) {
//									existe = true;
//									Index *A, *B, *C;
//									A = CreeIndex(i, j, k);
//									B = CreeIndex(i, j + 1, k);
//									C = CreeIndex(i, j + 2, k);
//									CreeMoulin(A, B, C);
//									
//
//								}
//
//								if (k==0 && GetCase(i, j, k+1) == type && GetCase(i, j, k+2) == type) {
//									existe = true;
//									Index* A, * B, * C;
//									A = CreeIndex(i, j, k);
//									B = CreeIndex(i, j , k+1);
//									C = CreeIndex(i, j , k+2);
//									CreeMoulin(A, B, C);
//
//
//								}
//
//
//							}
//
//							else if (j == 2) {
//								if (k == 0 && GetCase(i, j, k + 1) == type && GetCase(i, j, k + 2)==type) {
//									existe = true;
//									Index* A, * B, * C;
//									A = CreeIndex(i, j, k);
//									B = CreeIndex(i, j, k + 1);
//									C = CreeIndex(i, j, k + 2);
//									CreeMoulin(A, B, C);
//								}
//							}
//						}
//					}
//					else {
//						if (i == 0) {
//							if (GetCase(i, j, k) == type) {
//								if (GetCase(i+1, j , k) == type && GetCase(i+2, j , k) == type) {
//									existe = true;
//									Index* A, * B, * C;
//									A = CreeIndex(i, j, k);
//									B = CreeIndex(i+1, j, k);
//									C = CreeIndex(i+2, j, k);
//									CreeMoulin(A, B, C);
//
//
//								}
//							}
//						}
//
//					}
//			}
//
//			
//			
//		
//		}
//	}
//	return existe;
//}
//
//void Plateau_Dynamique::CreeMoulin(Index* A, Index* B, Index* C)
//{
//	MOULIN M;
//	M.pion1.i = A->i;
//	M.pion1.j = A->j;
//	M.pion1.k = A->k;
//	
//	M.pion2.i = B->i;
//	M.pion2.j = B->j;
//	M.pion2.k = B->k;
//
//	M.pion3.i = C->i;
//	M.pion3.j = C->j;
//	M.pion3.k = C->k;
//	ListeMoulin.push_back(M);
//}
//
//bool Plateau_Dynamique::EstCaseSupprimer(int i, int j, int k)
//{
//	for (vector<Index>::iterator it = CaseSuprimer.begin(); it != CaseSuprimer.end(); it++) {
//		if (it->i == i && it->j == j && it->k == k) {
//			return true;
//		}
//	}
//	return false;
//}
//
//void Plateau_Dynamique::InsrerCaseSupprimer(int i, int j, int k)
//{
//	Index index;
//	index.i = i;
//	index.j = j;
//	index.k = k;
//	CaseSuprimer.push_back(index);
//}
//
//Index *CreeIndex(int a, int b, int c)
//{
//	Index *A;
//	A = (Index*)malloc(sizeof(Index));
//	if (A == NULL) {
//		cout << "IMPOSIBLE DE CRIER INDEX" << endl;
//		exit(0);
//	}
//	A->i = a;
//	A->j = b;
//	A->k = c;
//
//	return A;
//}
//
//bool EstMoulinSontEgaux(MOULIN A, MOULIN B)
//{
//	if (A.pion1.i != B.pion1.i || A.pion1.j != B.pion1.j || A.pion1.k != B.pion1.k) {
//		return false;
//	}
//	if (A.pion2.i != B.pion2.i || A.pion2.j != B.pion2.j || A.pion2.k != B.pion2.k) {
//		return false;
//	}
//	if (A.pion3.i != B.pion3.i || A.pion3.j != B.pion3.j || A.pion3.k != B.pion3.k) {
//		return false;
//	}
//
//	return true;
//}
//
//Noeud* CreeNoeud(etat E)
//{
//
//	Noeud* noeud;
//	noeud = (Noeud*)malloc(sizeof(Noeud));
//	if (noeud == NULL) {
//		cout << "IMPOSIBLE DE CRIER UN NOEUD" << endl;
//		exit(0);
//	}
//	noeud->Etat = E;
//	noeud->suivant = NULL;
//	return noeud;
//}
//
//Pile* CreePile()
//{
//	Pile* pile;
//	pile = (Pile*)malloc(sizeof(Pile));
//	if (pile == NULL) {
//		cout << "IMPOSIBLE DE CRIER UN PILE" << endl;
//		exit(0);
//	}
//	pile->tete = NULL;
//	pile->taille = 0;
//	return pile;
//}
//
//
//void Empiler(Pile* P, etat E)
//{
//	Noeud* noeud;
//	noeud = CreeNoeud(E);
//	noeud->suivant = P->tete;
//	P->tete = noeud;
//	P->taille++;
//}
//
//etat Depiler(Pile* P)
//{
//	etat E;
//	Noeud* courant;
//	if (P->tete == NULL) {
//		cout << "IMPOSIBLE DE DEPILER" << endl;
//	}
//	else {
//		courant = P->tete;
//		E = courant->Etat;
//		P->tete = P->tete->suivant;
//		P->taille--;
//		delete[] courant;
//		return E;
//	}
//	return etat();
//}
