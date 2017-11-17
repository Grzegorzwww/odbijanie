#ifndef GAME_H
#define GAME_H


#include <cstdint>
#include <cassert>
#include <iostream>

#include <defines.h>

#include "player.h"
#include "ball.h"
#include "ground.h"




class Game {
public:

    Game();
    void run();
    virtual ~Game();

protected:

private:

    void processEvents();
    void update();
    void render();


    const int SCALE = 30;
    int spites_count;
    int pilki_counter;

    sf::RenderWindow window;
     b2Vec2 _gravity;
     b2World *World;



    sf::Texture back_ground_tex;
    sf::Sprite _backGroundSprite;


    Player *player_one;
    Player *player_two;


    //Ball *ball[250];
    Ball *ball;


    Ground *ground;
    Ground *left_wall;
     Ground *right_wall;






    std::vector<sf::Sprite > sprites_buffor;
    // sf::Sprite spites[255];


    void CreateGround(b2World& World, float X, float Y);
    void CreateBox(b2World& World, int MouseX, int MouseY);


    void create_ground(b2World& World, float X, float Y, float heigh, float width);
    void create_ball(b2World& World, int MouseX, int MouseY);


};

#endif // GAME_H
