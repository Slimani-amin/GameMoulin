#include "Menu.hpp"

int main() {

	VideoMode mode(800, 600);
	Menu MenuGame(mode, "MOULIN");
	MenuGame.SetSoundBouton("sound/effect/cliq.wav");
	MenuGame.AjouterBouton("Play", "image/icon/bouton-start.png",315,100,0.3f,0.3f);
	MenuGame.AjouterBouton("Exit", "image/icon/sortir.png", 315, 300, 0.3f, 0.3f);
	MenuGame.AjouterBouton("Parametre", "image/icon/parametres.png", 20, 10, 0.1f, 0.1f);
	MenuGame.SetBackground("image/background/background1.jpg");
	MenuGame.SetIcon("image/icon/icons8-xbox-controller-48.png");
	MenuGame.SetMusic("sound/music_background/music1.mp3");
	MenuGame.start();




	
}
