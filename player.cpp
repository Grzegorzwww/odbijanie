#include "player.h"

Player::Player()
{
    //cto

}
Player::Player(b2World& World, std::string texture_file, int x, int y,  float width, float height)
{


  if (!_texture.loadFromFile(texture_file)) {
       std::cerr << "Can't load file:  "<<texture_file<<std::endl;

    }
    else {

        _sprite.setTexture(_texture);
        _sprite.setOrigin(50.0f, 50.0f);
    }



      window_w_max =0;
      window_h_max = 0;

    _bodyDef.position = b2Vec2(x/SCALE, y/SCALE);
    _bodyDef.type = b2_dynamicBody;
    //_bodyDef.type = b2_kinematicBody;


    _body = World.CreateBody(&_bodyDef);



    _body->SetUserData((void *)&_sprite);

    _shape.SetAsBox((width/2)/SCALE, (height/2)/SCALE);

    _fixtureDef.density = 80.0f;
    _fixtureDef.restitution = 0.0f;

    _fixtureDef.shape = &_shape;
    _body->CreateFixture(&_fixtureDef);
    _body->SetFixedRotation(true);

    std::cerr << "kontruktor ball"<<std::endl;



}

void Player::getWindowSize(int w, int h){

    window_h_max = h;
    window_w_max = w;

}

void Player::makeJump(){


   b2Vec2 pos = _body->GetPosition();



    //std::cerr <<" pos.y = "<<pos.y * SCALE<<std::endl;
    b2Vec2 vel = _body->GetLinearVelocity();
   if(pos.y * SCALE > JUMP_MAX_POSITION+JUMP_MAX_POSITION){
        vel.y = -10;//upwards - don't change x velocity
        _body->SetLinearVelocity( vel );
   }




    //std::cerr <<" vel.x = "<<vel.x <<std::endl;

    /*float impulse = _body->GetMass() * 2;
    _body->ApplyLinearImpulse( b2Vec2(0,-impulse), _body->GetWorldCenter() );*/

}


void Player::moveRight(){



    float impulse = _body->GetMass() / 2;
    _body->ApplyLinearImpulse( b2Vec2(impulse,0), _body->GetWorldCenter(), true );




}

void Player::moveLeft(){
  /*  b2Vec2 vel = _body->GetLinearVelocity();
        vel.x = -2;
    _body->SetLinearVelocity( vel );*/


    float impulse = _body->GetMass() / 2;
    _body->ApplyLinearImpulse( b2Vec2(-impulse,0), _body->GetWorldCenter(), true );



}



void Player::setPosition(int x, int y){

    _body->SetTransform(b2Vec2(0,0),_body->GetAngle());


}

Player::~Player()
{
    //dtor
}
