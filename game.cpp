#include "game.h"

Game::Game() : window(sf::VideoMode(800, 600), "SFML window")
{
    //cto

    window.setFramerateLimit(60);


    _gravity = b2Vec2(0.0f, 25.0f);
    World = new b2World(_gravity);
    pilki_counter = 0;
    spites_count = 0;



    menu = new Menu(window.getSize().x,window.getSize().y);

    if (!back_ground_tex.loadFromFile("background_2.jpg")) {

    }
    _backGroundSprite.setTexture(back_ground_tex);
    _backGroundSprite.setPosition(0, 0);


    ground = new Ground(*World, "ground.jpg",400 , 600, 800.0f,  10.0f);
    left_wall = new Ground(*World, "x",3,300, 6.0f,  600.0f);
    right_wall = new Ground(*World, "x",806,300, 6.0f,  600.0f);


    ball = nullptr;



    // CreateGround(*_World, 400.f, 500.f);
    //create_ground(*_World, 400.0f, 500.0f, 800.0f, 10.0f);

    player_one = new Player(*World, "player.png", 400, 200, PLAYER_WIDTH, PLAYER_HEIGHT, PAL_LEFT_HENDED);

    player_two = new Player(*World, "player.png", 200, 200, PLAYER_WIDTH, PLAYER_HEIGHT, PAL_RIGHT_HENDED);













}

Game::~Game()
{
    //dtor
}

void Game::run() {


    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }


}

void Game::processEvents() {
    int i= 0;

    sf::Event event;
    while (window.pollEvent(event))
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
            window.close();
            break;
            // key pressed
        case sf::Event::KeyPressed:
            switch(event.key.code)
            {
            case sf::Keyboard::Left : player_one->moveLeft();
                break;
            case sf::Keyboard::Right : player_one->moveRight();
                break;

            case sf::Keyboard::Up : if(!menu->getMenuState()){
                    player_one->makeJump();
                }
                else{
                    menu->MoveUp();
                }

                break;
            case sf::Keyboard::Down :
                  menu->MoveDown();
                break;
            case sf::Keyboard::K : player_one->switchPaddleState(FORHAND); player_one->makeHit();
                break;
            case sf::Keyboard::L : player_one->switchPaddleState(BACKHAND);  player_one->makeBackhand();
                break;
            case sf::Keyboard::A : player_two->moveLeft();
                break;
            case sf::Keyboard::D : player_two->moveRight();
                break;
            case sf::Keyboard::W : player_two->makeJump();
                break;
            case sf::Keyboard::S : std::cerr << "idle : palyer 2: down"<<std::endl;
                break;
            case sf::Keyboard::V : player_two->switchPaddleState(FORHAND); player_two->makeHit();
                break;
            case sf::Keyboard::B : player_two->switchPaddleState(BACKHAND); player_two->makeBackhand();
                break;
            case sf::Keyboard::Space :
                if(ball == nullptr){
                    ball = new Ball(*World, "ball_small.png", 400 , 200);
                }
                else {
                }
                break;
            case sf::Keyboard::Y :
                resumeGame();
                break;
            default:
                break;
            case sf::Keyboard::Escape :
                menu->showMenu();
                break;

            case sf::Keyboard::Return :
                if(menu->getMenuState()){
                    menu->hideMenu();
                }


               break;
            }
        }

    }
}

void Game::update() {

    sf::Sprite *class_temp_sprite = new sf::Sprite();
    for(b2Body *bodyIterator = World->GetBodyList(); bodyIterator  != 0; bodyIterator  = bodyIterator ->GetNext()) {

        class_temp_sprite = reinterpret_cast<sf::Sprite  *>( bodyIterator->GetUserData());
        class_temp_sprite->setPosition(SCALE * bodyIterator->GetPosition().x, SCALE * bodyIterator->GetPosition().y);
        class_temp_sprite->setRotation(bodyIterator->GetAngle() * 180/b2_pi);
        sprites_buffor.push_back(*class_temp_sprite);
    }
    World->Step(1/60.f, 8, 3);
}




void Game::render()
{
    window.clear();



    window.draw(_backGroundSprite);
    for (std::vector<sf::Sprite >::iterator it = sprites_buffor.begin(); it != sprites_buffor.end(); ++it){
        window.draw(*it);
    }

    menu->draw(window);
    sprites_buffor.clear();



    /* for(int i = 0; i < spites_count; i++ ){
                    window.draw(spites[i]);
                }*/


    spites_count = 0;

    window.display();
}






void Game::create_ground(b2World& World, float X, float Y, float heigh, float width)
{



    b2BodyDef bd;
    bd.position = b2Vec2(X/SCALE, Y/SCALE);

    b2Body* ground = World.CreateBody(&bd);

    b2PolygonShape shape;

    //shape.SetAsEdge(b2Vec2(-40.0f, 0.0f), b2Vec2(40.0f, 0.0f));
    shape.SetAsBox((heigh/2)/SCALE, (width/2)/SCALE); // Creates a box shape. Divide your desired width and height by 2.
    b2FixtureDef FixtureDef;

    ground->CreateFixture(&shape, 0.0f);


}



void Game::create_ball(b2World& World, int MouseX, int MouseY)
{
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(MouseX/SCALE, MouseY/SCALE);
    BodyDef.type = b2_dynamicBody;
    b2Body* Body = World.CreateBody(&BodyDef);

    b2PolygonShape Shape;
    Shape.SetAsBox((40.f/2)/SCALE, (40.f/2)/SCALE);

    b2FixtureDef FixtureDef;
    FixtureDef.density = 1.0f;
    FixtureDef.restitution = 0.0f;

    //FixtureDef= 1.0f;
    //FixtureDef.friction = 1.0f;
    FixtureDef.shape = &Shape;

    Body->CreateFixture(&FixtureDef);
}




void Game::CreateGround(b2World& World, float X, float Y)
{
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(X/30.f, Y/30.f);
    BodyDef.type = b2_staticBody;
    b2Body* Body = World.CreateBody(&BodyDef);


    b2PolygonShape Shape;
    Shape.SetAsBox((800.f/2)/SCALE, (16.f/2)/SCALE); // Creates a box shape. Divide your desired width and height by 2.
    b2FixtureDef FixtureDef;
    FixtureDef.density = 1.0f;

    //FixtureDef.density = 1.0f;  // Sets the density of the body
    FixtureDef.shape = &Shape; // Sets the shape
    Body->CreateFixture(&FixtureDef); // Apply the fixture definition


}

void Game::CreateBox(b2World& World, int MouseX, int MouseY)
{
    b2BodyDef BodyDef;
    BodyDef.position = b2Vec2(MouseX/SCALE, MouseY/SCALE);
    BodyDef.type = b2_dynamicBody;
    b2Body* Body = World.CreateBody(&BodyDef);

    b2PolygonShape Shape;
    Shape.SetAsBox((32.f/2)/SCALE, (32.f/2)/SCALE);

    b2FixtureDef FixtureDef;
    FixtureDef.density = 5.0f;
    FixtureDef.restitution = 0.4f;


    FixtureDef.shape = &Shape;

    Body->CreateFixture(&FixtureDef);
}

void Game::resumeGame(){
    if(ball  != nullptr){
        ball->setDefPosiotion(650,100);
        player_one->setPosition(650, 550);
         player_one->makeJump();
        player_two->setPosition(150, 550);
        player_two->makeJump();
    }
}



