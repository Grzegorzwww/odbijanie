#ifndef GROUND_H
#define GROUND_H

#include <iostream>
#include <defines.h>


class Ground
{
    public:

      Ground(b2World& World, std::string texture_file, int x, int y, float width, float height );
      void setPosition(int x, int y);
      virtual ~Ground();


      void startContact();
      void endContact();


         sf::Sprite getSprite() {return _sprite;}

    protected:




    private:
        Ground();

         sf::Texture _texture;
         sf::Sprite _sprite;

         b2BodyDef _bodyDef;
         b2PolygonShape _shape;
         b2FixtureDef _fixtureDef;
         b2Body* _body;
};

#endif // GROUND_H
