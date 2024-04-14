
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
using namespace sf;
using namespace std;


class Menu
{


public:
	Menu();
	Menu(VideoMode mode, string title);
	~Menu();

	int SetSoundBouton(string chemin_effect_sound);
	int AjouterBouton(String titre, string chemin_image, float posX, float posY, float height, float width);
	int SetBackground(string chemin_background);
	int SetMusic(String chemin_music);
	int SetIcon(String chemin_icon);
	void start();

	static int NombreMenu;

private:
	RenderWindow window;
	Sprite backgroundSprite;
	Texture backgroundTexture;
	map<string, Sprite> bouton;
	Sound sound;
	SoundBuffer soundBuffer;
	Texture* BoutonTexture;//MAX DES BOUTONS DANS UN WINDOW EST 10
	int NombreBouton;
	Music music;
	Image icon;












};







