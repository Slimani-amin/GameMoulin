#include "Menu.hpp"

Menu::Menu(){
  
     
    NombreMenu++;
}


Menu::~Menu() {
 
    NombreMenu--;
}

int Menu::NombreMenu = 0;





