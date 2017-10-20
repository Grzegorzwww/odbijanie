#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <Box2D/Box2D.h>
#include <iostream>


static const int SCALE = 30;
class Player
{
    public:

        Player(b2World *World, std::string texture_file, int x, int y);
        virtual ~Player();



        void setPosition(int x, int y);
        sf::Sprite getSprite();
    protected:




    private:
        Player();

        sf::Texture player_tex;
        sf::Sprite PlayerSprite;

         b2BodyDef BodyDef;
         b2PolygonShape Shape;
         b2FixtureDef FixtureDef;
         b2Body* Body;




        b2World *temp_world;


        float height, wight;

        void create_player();



};

#endif // PLAYER_H
