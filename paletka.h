#ifndef PALETKA_H
#define PALETKA_H

#include <iostream>
#include "defines.h"
#include "math.h"


class Paletka
{
public:


    Paletka(b2World& World, std::string texture_file, int x, int y,  float width, float height, bool rev = false);
    void setPosition(int x, int y);
   // virtual ~Paletka();



    void makeHitMove();
    void releaseHitMove();
    void makeBackhandMove();

    b2Body * getBody();

    sf::Sprite getSprite() {return _sprite;}


 protected:


private :
        Paletka();

        bool direction;
        sf::Texture _texture;
        sf::Sprite _sprite;

        b2BodyDef _bodyDef;
        b2PolygonShape _shape;
        b2FixtureDef _fixtureDef;
        b2Body* _body;


};


#endif // PALETKA_H
