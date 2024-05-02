#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Bouton.h"
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
using namespace sf;
using namespace std;


class Interface
{
	Interface();
	Interface(VideoMode mode, string title);
	~Interface();

	int AjouterBouton(String titre, string chemin_image, float posX, float posY, float height, float width);
	int SetBackground(string chemin_background); 
	int SetMusic(String chemin_music);
	int SetIcon(String chemin_icon);




private:
	RenderWindow window;
	Sprite backgroundSprite;
	Texture backgroundTexture;
	Bouton bouton[10];
	Texture* BoutonTexture;
	int NombreBouton;
	Music music;
	Image icon;





};

