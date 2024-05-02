//#include "Interface.h"
//
//
//
//Interface::Interface(){
//
//}
//
//
//
//
//
//
//
//
//int Interface::AjouterBouton(String titre, string chemin_image, float posX, float posY, float height, float width)
//{
//  
//    cerr << "chargement de l'image suceess!!" << endl;
//    bouton[NombreBouton].SetBouton(titre, chemin_image, height, width);
//    bouton[NombreBouton].SetPositionBouton(posX, posY);
//
//    NombreBouton++;
//    return EXIT_SUCCESS;
//}
//
//int Interface::SetBackground(string chemin_background)
//{
//    // Charger l'image pour l'arrière-plan
//    if (!backgroundTexture.loadFromFile(chemin_background)) {
//        std::cerr << "Erreur : Impossible de charger l'image pour l'arrière-plan." << std::endl;
//        return EXIT_FAILURE;
//    }
//    cerr << "chargement de l'image success!!" << endl;
//    backgroundSprite.setTexture(backgroundTexture);
//    return EXIT_SUCCESS;
//}
//
//int Interface::SetMusic(String chemin_music)
//{
//    if (!music.openFromFile(chemin_music)) {
//        // Gérer l'erreur si le chargement du fichier audio échoue
//        cout << "Erreur de lecture la music" << endl;
//        return 1;
//    }
//    cout << "lecture de music success!!" << endl;
//    return 0;
//}
//
//int Interface::SetIcon(String chemin_icon)
//{
//    if (!icon.loadFromFile(chemin_icon)) {
//        cout << "Imposible de charger l'image Icon" << endl;
//        return EXIT_FAILURE;
//    }
//    cout << "chargement image success" << endl;
//    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
//    return EXIT_SUCCESS;
//}
