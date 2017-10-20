#include "Player.h"

Player::Player()
{
    //cto

}
Player::Player(b2World *World, std::string texture_file, int x, int y): temp_world(World)
{


  if (!player_tex.loadFromFile(texture_file)) {
       std::cerr << "Can't load file "<<texture_file<<std::endl;
    }



    BodyDef.position = b2Vec2(x/SCALE, y/SCALE);
    BodyDef.type = b2_dynamicBody;

    Body = temp_world->CreateBody(&BodyDef);


    Shape.SetAsBox((20.f/2)/SCALE, (40.f/2)/SCALE);


    FixtureDef.density = 1.0f;
    FixtureDef.restitution = 0.0f;

    FixtureDef.shape = &Shape;
    Body->CreateFixture(&FixtureDef);



}



void Player::setPosition(int x, int y){

    Body->SetTransform(b2Vec2(0,0),Body->GetAngle());


}

Player::~Player()
{
    //dtor
}
