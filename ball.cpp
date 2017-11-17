#include "ball.h"

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


    shape.m_radius = 0.7f;




    Body = World.CreateBody(&BodyDef);

    BallSprite.setTexture(ball_tex);
    BallSprite.setOrigin(20.0f, 20.0f);

    Body->SetUserData((void *)&BallSprite);

   // Shape.SetAsBox((30.f/2)/SCALE, (30.f/2)/SCALE);

    FixtureDef.density = 15.0f;
    FixtureDef.restitution = 0.5f;
    FixtureDef.friction = 0.0;


    //FixtureDef.shape = &Shape;
    FixtureDef.shape = & shape;
    Body->CreateFixture(&FixtureDef);

    std::cerr << "kontruktor ball"<<std::endl;


}

void Ball::setPosition(int x, int y){

    Body->SetTransform(b2Vec2(0,0),Body->GetAngle());


}

void Ball::setDefPosiotion(int x, int y){
    Body->SetTransform(b2Vec2(x/SCALE,y/SCALE),Body->GetAngle());
}

sf::Texture Ball::getTexture(){
    return ball_tex;
}




Ball::~Ball()
{

}
