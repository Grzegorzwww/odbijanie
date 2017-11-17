#ifndef BALL_H
#define BALL_H

#include <iostream>
#include "defines.h"



class Ball
{
    public:
        Ball(b2World& World, std::string texture_file, int x, int y);
        virtual ~Ball();

        void setPosition(int x, int y);
        sf::Texture getTexture();
        void setDefPosiotion(int x, int y);

    protected:

    private:
        Ball();



        sf::Texture ball_tex;
        sf::Sprite BallSprite;

         b2BodyDef BodyDef;
         b2PolygonShape Shape;


          b2CircleShape shape;


         b2FixtureDef FixtureDef;
         b2Body* Body;

        //b2World *temp_world;

        float height, wight;


};

#endif // BALL_H
