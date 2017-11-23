        #include "player.h"

    Player::Player()
    {
        //cto

    }
    Player::Player(b2World& World, std::string texture_file, int x, int y,  float width, float height, bool rev_pal) : play_direction(rev_pal), temp_world_ptr(&World)
    {

        m_joint = nullptr;
        if (!_texture.loadFromFile(texture_file)) {
            std::cerr << "Can't load file:  "<<texture_file<<std::endl;
        }
        else {
            _sprite.setTexture(_texture);
            _sprite.setOrigin(width/2, height/2);

        }
        if(!play_direction){
            padle = new Paletka(World, "paletka.png", x, y, 24, 56, PAL_LEFT_HENDED);
        }else{
            padle = new Paletka(World, "paletka_rev.png", x, y, 24, 56, PAL_RIGHT_HENDED);
        }


        paddle_state = false;
        window_w_max =0;
        window_h_max = 0;

        _bodyDef.position = b2Vec2(x/SCALE, y/SCALE);
        _bodyDef.type = b2_dynamicBody;


        _body = World.CreateBody(&_bodyDef);
        _body->SetUserData((void *)&_sprite);
        _shape.SetAsBox((width/2)/SCALE, (height/2)/SCALE);

        _fixtureDef.density = 400.0f;
        _fixtureDef.restitution = 0.2f;

        _fixtureDef.shape = &_shape;
        _body->CreateFixture(&_fixtureDef);
        _body->SetFixedRotation(true);

         rjd.Initialize(_body, padle->getBody(),b2Vec2(0, 0));

         std::cout << " 1 "<<std::endl;
         switchPaddleState(FORHAND);
         std::cout << " 2 "<<std::endl;



    }


    void Player::getWindowSize(int w, int h){

        window_h_max = h;
        window_w_max = w;
    }


    void Player::makeHit(){
        padle->makeHitMove();
    }
    void Player::releaseHit(){
        padle->releaseHitMove();
    }


    void Player::switchPaddleState(bool state){

        if(state == FORHAND){
            if(m_joint != nullptr){
              temp_world_ptr->DestroyJoint( m_joint );
            }
            if(!play_direction){
                rjd.localAnchorA.Set(10/SCALE,-40/SCALE);
                rjd.localAnchorB.Set(0, 50/SCALE);
                rjd.lowerAngle = -0.5f * b2_pi;
                rjd.upperAngle = 0.1f * b2_pi;
                rjd.maxMotorTorque = 1000.0f;
                rjd.motorSpeed = 6.0f * b2_pi;
            }else{
                rjd.localAnchorA.Set(60/SCALE,-40/SCALE);
                rjd.localAnchorB.Set(0, 50/SCALE);
                rjd.lowerAngle = -0.1f * b2_pi;
                rjd.upperAngle = 0.5f * b2_pi;
                rjd.maxMotorTorque = 1000.0f;
                rjd.motorSpeed = 2.0f * b2_pi * (-1);
            }
            rjd.enableMotor = true;
            rjd.enableLimit = true;
            rjd.collideConnected = false;
            m_joint = (b2RevoluteJoint *)temp_world_ptr->CreateJoint(&rjd);

        }else if(state == BACKHAND){
            if(m_joint != nullptr){
              temp_world_ptr->DestroyJoint( m_joint );
            }

            if(!play_direction){
                rjd.enableMotor = true;
                rjd.enableLimit = true;
                rjd.collideConnected = false;
                rjd.maxMotorTorque = 1000;
                rjd.motorSpeed = 4.0f * b2_pi *-1;
                rjd.lowerAngle = -0.65f * b2_pi;
                rjd.upperAngle = -0.1f * b2_pi;
                rjd.localAnchorA.Set(-10/SCALE, 10/SCALE);
                rjd.localAnchorB.Set(0, 50/SCALE);
                m_joint = (b2RevoluteJoint *)temp_world_ptr->CreateJoint(&rjd);

            }else{
                rjd.enableMotor = true;
                rjd.enableLimit = true;
                rjd.collideConnected = false;
                rjd.maxMotorTorque = 1000;
                rjd.motorSpeed = 4.0f * b2_pi;
                rjd.lowerAngle = 0.1f * b2_pi;
                rjd.upperAngle = 0.65f * b2_pi;
                rjd.localAnchorA.Set(60/SCALE, 10/SCALE);
                rjd.localAnchorB.Set(0, 50/SCALE);
                m_joint = (b2RevoluteJoint *)temp_world_ptr->CreateJoint(&rjd);
            }
        }


    }

    void Player::makeBackhand(){
        padle->makeBackhandMove();

    }


    void Player::makeJump(){

        b2Vec2 pos = _body->GetPosition();
        b2Vec2 vel = _body->GetLinearVelocity();
        if(pos.y * SCALE > JUMP_MAX_POSITION+JUMP_MAX_POSITION){
            vel.y = -10;//upwards - don't change x velocity
            _body->SetLinearVelocity( vel );
        }
    }

    void Player::moveRight(){
        float impulse = _body->GetMass() / 2;
        _body->ApplyLinearImpulse( b2Vec2(impulse * 2.0, 0), _body->GetWorldCenter(), true );
    }

    void Player::moveLeft(){

        float impulse = _body->GetMass() / 2;
        _body->ApplyLinearImpulse( b2Vec2(-impulse * 2.0, 0), _body->GetWorldCenter(), true );
    }


    void Player::setPosition(int x, int y){

        _body->SetTransform(b2Vec2(x/SCALE,y/SCALE),_body->GetAngle());
    }

    Player::~Player()
    {
        //dtor
    }
