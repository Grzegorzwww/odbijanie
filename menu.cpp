#include "menu.h"

using namespace std;

Menu::Menu()
{


}

Menu::Menu(float width, float height) {

    if(!font.loadFromFile("fonts/KGSummerSunshineBlackout.ttf")) {
        cerr << "can not load font: SnakeStitch.ttf"<<endl;
    }




    menu[0].setFont(font);
    menu[0].setColor(sf::Color::Green);
    menu[0].setString("New Game");
    menu[0].setPosition(sf::Vector2f(width /3 , height / (MAX_NUMBER_ITEMS+ 1) * 1));

    menu[1].setFont(font);
    menu[1].setColor(sf::Color::Green);
    menu[1].setString("Continue");
    menu[1].setPosition(sf::Vector2f(width /3 , height / (MAX_NUMBER_ITEMS+ 1) * 2));

    menu[2].setFont(font);
    menu[2].setColor(sf::Color::Green);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width /3 , height / (MAX_NUMBER_ITEMS+ 1) * 3));

    selectedItemIndex = 0;
}



void Menu::draw(sf::RenderWindow &window) {
    if(show_hide_flag) {
        for(int i = 0; i < MAX_NUMBER_ITEMS ; i++) {
            window.draw(menu[i]);

        }

    }


}

void  Menu::showMenu() {
     show_hide_flag = true;

}
void  Menu::hideMenu() {
    show_hide_flag = false;
}

void Menu::MoveUp() {
    if(selectedItemIndex - 1 >= 0) {
        menu[selectedItemIndex].setColor(sf::Color::Green);
        selectedItemIndex--;
        menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}
void Menu::MoveDown() {
    if(selectedItemIndex + 1 < MAX_NUMBER_ITEMS ) {
        menu[selectedItemIndex].setColor(sf::Color::Green);
        selectedItemIndex++;
        menu[selectedItemIndex].setColor(sf::Color::Red);

    }
}

