#include "ground.h"

Ground::Ground()
{
}

Ground::Ground(b2World& World, std::string texture_file, int x, int y, float width, float height)
{
  if (!_texture.loadFromFile(texture_file)) {
       std::cerr << "Can't load file "<<texture_file<<std::endl;
    }
    else {

    }
    _sprite.setTexture(_texture);

    _bodyDef.position = b2Vec2(x/SCALE, y/SCALE);
    _bodyDef.type = b2_staticBody;

    _body = World.CreateBody(&_bodyDef);
    _body->SetUserData((void *)&_sprite);

    _shape.SetAsBox((width/2)/SCALE, (height/2)/SCALE);

    _fixtureDef.density = 1.0f;
    _fixtureDef.restitution = 0.0f;

    _fixtureDef.shape = &_shape;
    _body->CreateFixture(&_fixtureDef);

    std::cerr << "kontruktor ground"<<std::endl;

}


void Ground::setPosition(int x, int y){
    _body->SetTransform(b2Vec2(0,0),_body->GetAngle());

}


Ground::~Ground()
{
    //dtor
}

void Ground::startContact(){
    //std::cout <<"ZIEMIA START\n";
    ColisionCollector *instanceCollerctorPtr =  ColisionCollector::GetColisionCollector();
    instanceCollerctorPtr->setGroundColision(true);
}

void Ground::endContact(){
   // std::cout <<"ZIEMIA STOP\n";
    ColisionCollector *instanceCollerctorPtr =  ColisionCollector::GetColisionCollector();
    instanceCollerctorPtr->setGroundColision(false);
}



