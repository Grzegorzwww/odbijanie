#include "menu.h"

using namespace std;

Menu::Menu()
{


}

Menu::Menu(float width, float height) {

    if(!font.loadFromFile("fonts/KGSummerSunshineBlackout.ttf")) {
        cerr << "can not load font: SnakeStitch.ttf"<<endl;
    }
    show_hide_flag = false;
    show_result_menu_flag = false;

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

    menu[3].setFont(font);
    menu[3].setColor(sf::Color::Green);
    menu[3].setString(" - ");
    menu[3].setPosition(sf::Vector2f(width /3 , height / 3 ));


    menu[4].setFont(font);
    menu[4].setColor(sf::Color::Green);
    menu[4].setString(" - ");
    menu[4].setPosition(sf::Vector2f(width - 40 , 20));
    menu[5].setFont(font);
    menu[5].setColor(sf::Color::Green);
    menu[5].setString(" - ");
    menu[5].setPosition(sf::Vector2f( 20, 20));



    selectedItemIndex = 0;
}



void Menu::draw(sf::RenderWindow &window) {
    if(show_hide_flag) {
        for(int i = 0; i < MAX_NUMBER_ITEMS ; i++) {
            window.draw(menu[i]);
        }
    }
    if(show_result_menu_flag == true && show_hide_flag != true){
        //std::cout <<" wyswietlam wyniki: \n";
        window.draw(menu[3]);
        window.draw(menu[4]);
        window.draw(menu[5]);
    }

}
void  Menu::setResulMenu(std::string str, int num1, int num2) {
    menu[3].setString(str+"\n Nacisnij 'n'"  );
    ostringstream ss_num1;
    ss_num1 << num1;
    menu[4].setString(ss_num1.str());
    ostringstream ss_num2;
    ss_num2 << num2;
    menu[5].setString(ss_num2.str());
}


void  Menu::showMenu() {
     show_hide_flag = true;

}
void  Menu::hideMenu() {
    show_hide_flag = false;
}
void Menu::showResult() {
    show_result_menu_flag = true;
}
void Menu::hideResult() {
        show_result_menu_flag = false;
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

