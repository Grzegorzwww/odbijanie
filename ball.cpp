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

    shape.m_radius = 0.5f;
    BallSprite.setTexture(ball_tex);
    BallSprite.setOrigin(40.0f/2, 40.0f/2);

    Body = World.CreateBody(&BodyDef);
    Body->SetUserData((void *)&BallSprite);

   // Shape.SetAsBox((30.f/2)/SCALE, (30.f/2)/SCALE);
    FixtureDef.density = 1.0f;
    FixtureDef.restitution = 0.5f;
    FixtureDef.friction = 0.5;
    Body->SetFixedRotation(false);

    //FixtureDef.shape = &Shape;
    FixtureDef.shape = & shape;
    Body->CreateFixture(&FixtureDef);

    std::cerr << "kontruktor ball"<<std::endl;


}

void Ball::setPosition(int x, int y){
     Body->SetTransform(b2Vec2(0,0),Body->GetAngle());
     float impulse = Body->GetMass() / 2;
     Body->ApplyLinearImpulse( b2Vec2(impulse * 2.0, 0), Body->GetWorldCenter(), true );
}

void Ball::setDefPosiotion(int x, int y){
    Body->SetTransform(b2Vec2(x/SCALE,y/SCALE),Body->GetAngle());
    float impulse = Body->GetMass() / 2;
    Body->ApplyLinearImpulse( b2Vec2(impulse * 2.0, 0), Body->GetWorldCenter(), true );
}

sf::Texture Ball::getTexture(){
    return ball_tex;
}

Ball::~Ball()
{
}

void Ball::startContact() {
   // std::cout <<"PIŁKA START\n";
    ColisionCollector *instanceCollerctorPtr =  ColisionCollector::GetColisionCollector();
    instanceCollerctorPtr->setBallColision(true);
}

void Ball::endContact(){
  // std::cout <<"PIŁKA STOP\n";
    ColisionCollector *instanceCollerctorPtr =  ColisionCollector::GetColisionCollector();
    instanceCollerctorPtr->setBallColision(false);
}



