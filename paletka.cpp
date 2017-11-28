#include "paletka.h"

Paletka::Paletka(b2World& World, std::string texture_file, int x, int y,  float width, float height, bool rev ) : direction(rev)
{

    if (!_texture.loadFromFile(texture_file)) {
        std::cerr << "Can't load file:  "<<texture_file;
    }
    else {
        _sprite.setTexture(_texture);
        _sprite.setOrigin(width/2, height/2);
    }

    _bodyDef.position = b2Vec2(x/SCALE, y/SCALE);
    _bodyDef.type = b2_dynamicBody;

    _body = World.CreateBody(&_bodyDef);
    _body->SetUserData((void *)&_sprite);

    _shape.SetAsBox((width/2)/SCALE, (height/2)/SCALE);

    _fixtureDef.density = 20.0f;
    _fixtureDef.restitution = 0.0f;

    _fixtureDef.shape = &_shape;
    _body->CreateFixture(&_fixtureDef);
    _body->SetFixedRotation(false);

    //_body->set
    //std::cerr << "kontruktor paddle\n";


}

Paletka::Paletka()
{

}




void Paletka::makeBackhandMove(){
    float bodyAngle = _body->GetAngle();
    float nextAngle = bodyAngle + _body->GetAngularVelocity() / 60.0;
     float totalRotation = 4;
     while ( totalRotation < -180 * DEGTORAD ) totalRotation += 360 * DEGTORAD;
     while ( totalRotation >  180 * DEGTORAD ) totalRotation -= 360 * DEGTORAD;
     float desiredAngularVelocity = totalRotation; //*60;
     float impulse = _body->GetInertia() * desiredAngularVelocity;// disregard time factor
     if(!direction){
        _body->ApplyAngularImpulse( impulse * -10, true );
     }else{
        _body->ApplyAngularImpulse( impulse * 10, true );
     }
}


void Paletka::makeHitMove(){

    float bodyAngle = _body->GetAngle();
    float nextAngle = bodyAngle + _body->GetAngularVelocity() / 60.0;
     float totalRotation = 4;
     while ( totalRotation < -180 * DEGTORAD ) totalRotation += 360 * DEGTORAD;
     while ( totalRotation >  180 * DEGTORAD ) totalRotation -= 360 * DEGTORAD;
     float desiredAngularVelocity = totalRotation; //*60;
     float impulse = _body->GetInertia() * desiredAngularVelocity;// disregard time factor
     if(!direction){
        _body->ApplyAngularImpulse( impulse * 10, true );
     }else{
        _body->ApplyAngularImpulse( impulse * -10, true );
     }
}


void Paletka::releaseHitMove(){

//    // _body->SetTransform( _body->GetPosition(), -60 * DEGTORAD);
//    float bodyAngle = _body->GetAngle();
//    float nextAngle = bodyAngle + _body->GetAngularVelocity() / 60.0;
//     float totalRotation = 4;
//     while ( totalRotation < -180 * DEGTORAD ) totalRotation += 360 * DEGTORAD;
//     while ( totalRotation >  180 * DEGTORAD ) totalRotation -= 360 * DEGTORAD;
//     float desiredAngularVelocity = totalRotation; //*60;
//     float impulse = _body->GetInertia() * desiredAngularVelocity;// disregard time factor
//     if(!direction){
//        _body->ApplyAngularImpulse( impulse * 15, true );
//     }else {
//        _body->ApplyAngularImpulse( impulse * -15, true );
//     }

}

b2Body * Paletka::getBody(){
    return _body;

}

void Paletka::setPosition(int x, int y){
    _body->SetTransform(b2Vec2(x/SCALE,y/SCALE),_body->GetAngle());

}
