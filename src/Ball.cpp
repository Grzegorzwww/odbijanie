#include "Ball.h"

Ball::Ball()
{
    //ctor
}

Ball::Ball(b2World& World, std::string texture_file, int x, int y)
{


  if (!ball_tex.loadFromFile(texture_file)) {
       std::cerr << "Can't load file "<<texture_file<<std::endl;
    }



    BodyDef.position = b2Vec2(x/SCALE, y/SCALE);
    BodyDef.type = b2_dynamicBody;





    Body = World.CreateBody(&BodyDef);

    Body->SetUserData(this);


    Shape.SetAsBox((30.f/2)/SCALE, (30.f/2)/SCALE);


    FixtureDef.density = 1.0f;
    FixtureDef.restitution = 0.0f;

    FixtureDef.shape = &Shape;
    Body->CreateFixture(&FixtureDef);



}

void Ball::setPosition(int x, int y){

    Body->SetTransform(b2Vec2(0,0),Body->GetAngle());


}


sf::Texture Ball::getTexture(){
    return ball_tex;
}


Ball::~Ball()
{
    //dtor
}
