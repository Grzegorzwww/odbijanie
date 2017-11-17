#ifndef PALETKA_H
#define PALETKA_H

#include <iostream>
#include "defines.h"


class Paletka
{
public:


    Paletka(b2World& World, std::string texture_file, int x, int y,  float width, float height);
    void setPosition(int x, int y);
   // virtual ~Paletka();


    sf::Sprite getSprite();
    void makeHitMove();

    b2Body * getBody();


 protected:


private :
        Paletka();

        sf::Texture _texture;
        sf::Sprite _sprite;

        b2BodyDef _bodyDef;
        b2PolygonShape _shape;
        b2FixtureDef _fixtureDef;
        b2Body* _body;


};


#endif // PALETKA_H
