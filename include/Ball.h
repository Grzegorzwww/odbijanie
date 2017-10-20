#ifndef BALL_H
#define BALL_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <Box2D/Box2D.h>
#include <iostream>



class Ball
{
    public:
        Ball(b2World& World, std::string texture_file, int x, int y);
        virtual ~Ball();

        void setPosition(int x, int y);
        sf::Texture getTexture();

    protected:

    private:
        Ball();

        int SCALE;

        sf::Texture ball_tex;
        sf::Sprite BallSprite;

         b2BodyDef BodyDef;
         b2PolygonShape Shape;
         b2FixtureDef FixtureDef;
         b2Body* Body;

        //b2World *temp_world;

        float height, wight;


};

#endif // BALL_H
