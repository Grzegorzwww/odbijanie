#ifndef MENU_H
#define MENU_H

#include "iostream"
#include "ostream"
#include "sstream"

#include "SFML/Graphics.hpp"

static const int MAX_NUMBER_ITEMS = 4;
static const int MAX_NUMBER_ALL_ITEMS = 7;


static const int NEW_GAME =0;
static const int CONTINUE = 1;
static const int RESULT_MENU = 2;
static const int EXIT = 3;
static const int RESULT_TEXT = 4;

static const int SCORE_TEXT_PL1 = 5;
static const int SCORE_TEXT_PL2 = 6;



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
