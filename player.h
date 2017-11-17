#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include "defines.h"




class Player
{
    public:

        Player(b2World& World, std::string texture_file, int x, int y,  float width, float height);
        virtual ~Player();



        void setPosition(int x, int y);
        void makeJump();
        void moveRight();
        void moveLeft();



        void getWindowSize(int w, int h);
        sf::Sprite getSprite();


    protected:




    private:
        Player();

        int window_w_max;
        int window_h_max;

         sf::Texture _texture;
         sf::Sprite _sprite;

         b2BodyDef _bodyDef;
         b2PolygonShape _shape;
         b2FixtureDef _fixtureDef;
         b2Body* _body;


};



#endif // PLAYER_H
