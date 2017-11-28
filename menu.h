#ifndef MENU_H
#define MENU_H

#include "iostream"
#include "ostream"
#include "sstream"

#include "SFML/Graphics.hpp"

static const int MAX_NUMBER_ITEMS = 3;
static const int MAX_NUMBER_ALL_ITEMS = 6;


class Menu
{
public:


    Menu(float width, float height);
    ~Menu();

    int GetPresesedItem() {return selectedItemIndex;}
    void draw(sf::RenderWindow &window);
    void showMenu();
    void hideMenu();

    void showResult();
    void hideResult();

    bool getMenuState() {return show_hide_flag;}
    void MoveUp();
    void MoveDown();
    void setResulMenu(std::string str, int num1, int num2);





private:

      Menu();
      int selectedItemIndex;
      sf::Font font;
      sf::Text menu[MAX_NUMBER_ALL_ITEMS];
      volatile bool show_hide_flag;
      volatile bool show_result_menu_flag;





};

#endif // MENU_H
