#include "Menu.hpp"

Menu::Menu() : window(VideoMode(800, 600), "Default Title") {
    BoutonTexture = new Texture[10];
    NombreBouton = 0;
     
    NombreMenu++;
}

Menu::Menu(VideoMode mode, string title) : window(mode, title) {
    BoutonTexture = new Texture[10];
    NombreBouton = 0;
    NombreMenu++;
}

Menu::~Menu() {
    delete[] BoutonTexture;
    NombreMenu--;
}

int Menu::NombreMenu = 0;



int Menu::SetSoundBouton(string chemin_effect_sound) {
    if (!soundBuffer.loadFromFile(chemin_effect_sound)) {
        std::cerr << "Failed to load sound file!" << std::endl;
        return 1;
    }
    cerr << "load sound file success!!" << endl;
    sound.setBuffer(soundBuffer);
    return 0;
}

int Menu::AjouterBouton(String titre, string chemin_image, float posX, float posY, float height, float width)
{
    // Charger l'image du bouton
    if (!BoutonTexture[NombreBouton].loadFromFile(chemin_image)) {
        std::cerr << "Erreur : Impossible de charger l'image pour le bouton ." << std::endl;
        return EXIT_FAILURE;
    }
    // Créer un sprite pour le bouton 
    cerr << "chargement de l'image suceess!!" << endl;
    Sprite Button(BoutonTexture[NombreBouton]);
    Button.setScale(height, width);
    Button.setPosition(posX, posY);

    bouton[titre] = Button;
    NombreBouton++;
    return EXIT_SUCCESS;
}

int Menu::SetBackground(string chemin_background) {
    // Charger l'image pour l'arrière-plan
    if (!backgroundTexture.loadFromFile(chemin_background)) {
        std::cerr << "Erreur : Impossible de charger l'image pour l'arrière-plan." << std::endl;
        return EXIT_FAILURE;
    }
    cerr << "chargement de l'image success!!" << endl;
    backgroundSprite.setTexture(backgroundTexture);
    return EXIT_SUCCESS;
}

int Menu::SetMusic(String chemin_music)
{
    if (!music.openFromFile(chemin_music)) {
        // Gérer l'erreur si le chargement du fichier audio échoue
        cout << "Erreur de lecture la music" << endl;
        return 1;
    }
    cout << "lecture de music success!!" << endl;
    return 0;
}

int Menu::SetIcon(String chemin_icon)
{
    if (!icon.loadFromFile(chemin_icon)) {
        cout << "Imposible de charger l'image Icon" << endl;
        return EXIT_FAILURE;
    }
    cout << "chargement image success" << endl;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    return EXIT_SUCCESS;
}




void Menu::start() {

    backgroundSprite.setScale(
        static_cast<float>(window.getSize().x) / backgroundSprite.getLocalBounds().width,
        static_cast<float>(window.getSize().y) / backgroundSprite.getLocalBounds().height
    );

    music.play();
    while (window.isOpen()) {
        
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            // Vérification si le bouton Play est cliqué
            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                Vector2i mousePosition = Mouse::getPosition(window);
                for (map<string, Sprite>::iterator it = bouton.begin(); it != bouton.end(); ++it) {
                    if ((it->second).getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
                        cout << "Le bouton " << it->first << " a ete clique !" << endl;
                        sound.play();

                        if (it->first == "Play") {

                            SetBackground("image/background/background2.jpg");

                        }
                        if (it->first == "Exit") {
                            window.close();
                        }
                    }
                }
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        for (map<string, Sprite>::iterator it = bouton.begin(); it != bouton.end(); ++it) {
            window.draw(it->second);
        }
        window.display();
    }
    music.stop();
}