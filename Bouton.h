#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;
class Bouton
{

	Bouton();
	Bouton(string titre);
	~Bouton();

	static int NombreBouton;

	int SetBouton(string titre, string chemin_image, float height, float width);
	int SetImageBouton(string chemin_image);
	int SetSoundBouton(string chemin_sound);
	void SetPositionBouton(float PosX, float PosY);
	void SetTitreBouton(string titre);
	void SetDimensionBouton(float height, float width);
	string GetImageBouton();
	string GetSoundBouton();
	string GetTitreImage();




private:
	string BoutonTitre;
	Texture BoutonTexture;
	Sprite BoutonSprite;
	Sound BoutonSound;
	SoundBuffer soundBuffer;
	string cheminImageBouton;
	string cheminSoundBouton;

};

