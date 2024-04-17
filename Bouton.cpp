#include "Bouton.h"


Bouton::Bouton() {
	cheminImageBouton = "PAS DE CHEMIN";
	cheminSoundBouton = "PAS DE CHEMIN";
	NombreBouton++;
}

Bouton::Bouton(string titre) {
	BoutonTitre = titre;
	cheminImageBouton = "PAS DE CHEMIN";
	cheminSoundBouton = "PAS DE CHEMIN";
	NombreBouton++;

}

Bouton::~Bouton() {
	NombreBouton--;
}

int Bouton::NombreBouton = 0;

int Bouton::SetBouton(string titre, string chemin_image, float height, float width) {
	BoutonTitre = titre;
	if (!BoutonTexture.loadFromFile(chemin_image)) {
		cout << "Erreur de chargement l'image de chemin " << chemin_image << endl;
		return EXIT_FAILURE;
	}
	cheminImageBouton = chemin_image;
	BoutonSprite.setTexture(BoutonTexture);
	BoutonSprite.setScale(height, width);
	return EXIT_SUCCESS;

}

int Bouton::SetImageBouton(string chemin_image)
{
	if (!BoutonTexture.loadFromFile(chemin_image)) {
		cout << "Erreur de chargement l'image de chemin " << chemin_image << endl;
		return EXIT_FAILURE;
	}
	cheminImageBouton = chemin_image;
	BoutonSprite.setTexture(BoutonTexture);
	return EXIT_SUCCESS;
}

int Bouton::SetSoundBouton(string chemin_sound)
{
	if (!soundBuffer.loadFromFile(chemin_sound)) {
		cout<<"Erreur de chargement effect son de chemin "<<chemin_sound<<endl;
		return EXIT_FAILURE;
	}
	cheminSoundBouton = chemin_sound;
	BoutonSound.setBuffer(soundBuffer);
	return EXIT_SUCCESS;

}

void Bouton::SetTitreBouton(string titre)
{
	BoutonTitre = titre;
}

void Bouton::SetDimensionBouton(float height, float width)
{
	BoutonSprite.setScale(height, width);
}

string Bouton::GetImageBouton()
{
	cout << cheminImageBouton << endl;

	return cheminImageBouton;
}

string Bouton::GetSoundBouton()
{
	cout << cheminSoundBouton << endl;
	return cheminSoundBouton;
}

string Bouton::GetTitreImage()
{
	cout << BoutonTitre << endl;
	return BoutonTitre;
}

