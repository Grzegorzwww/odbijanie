#include "game.h"

Game::Game() : window(sf::VideoMode(800, 600), "SFML window")
{
    //cto

      window.setFramerateLimit(60);


    _gravity = b2Vec2(0.0f, 25.0f);
    World = new b2World(_gravity);
    pilki_counter = 0;
    spites_count = 0;




    if (!back_ground_tex.loadFromFile("background.jpg")) {

    }
    _backGroundSprite.setTexture(back_ground_tex);
    _backGroundSprite.setPosition(0, 0);


    ground = new Ground(*World, "ground.jpg",400 , 500, 800.0f,  10.0f);
    left_wall = new Ground(*World, "x",3,300, 6.0f,  600.0f);
    right_wall = new Ground(*World, "x",806,300, 6.0f,  600.0f);


     ball = nullptr;



   // CreateGround(*_World, 400.f, 500.f);
    //create_ground(*_World, 400.0f, 500.0f, 800.0f, 10.0f);

    player_one = new Player(*World, "player.png", 400, 200, PLAYER_WIDTH, PLAYER_HEIGHT);


    player_two = new Player(*World, "player.png", 200, 200, PLAYER_WIDTH, PLAYER_HEIGHT);







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
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        int mouseX = sf::Mouse::getPosition(window).x;
        int mouseY = sf::Mouse::getPosition(window).y;
        //create_ball(*_World, MouseX, MouseY);
        //if(pilki_counter == 0){
          /*  ball[pilki_counter] = new Ball(*World, "ball_small.png", mouseX , mouseY);
            std::cerr << "stworzono obiekt typu Ball nr: " << pilki_counter  <<std::endl;
        pilki_counter++;*/




    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        std::cerr << "Left";
        player_one->moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {

        std::cerr << "Right";
        player_one->moveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {

        std::cerr << "Up";
        player_one->makeJump();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {

        std::cerr << "Down";
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        std::cerr << "Left";
        player_two->moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {

        std::cerr << "Right";
        player_two->moveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

        std::cerr << "Up";
        player_two->makeJump();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {

        std::cerr << "Down";
    }


      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

        if(ball == nullptr){
              ball = new Ball(*World, "ball_small.png", 400 , 200);
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {

        if(ball != nullptr){
              ball->setDefPosiotion(400,100);

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



       /* sf::Texture *tex = NULL;)
        if (bodyIterator->GetType() == b2_dynamicBody ) {
            BodySprite.setTexture(object_tex);
            BodySprite.setOrigin(20.f, 20.f);
            BodySprite.setPosition(SCALE * bodyIterator->GetPosition().x, SCALE * bodyIterator->GetPosition().y);
            BodySprite.setRotation(bodyIterator->GetAngle() * 180/b2_pi);
            spites[spites_count++] = BodySprite;
        } else {
           // GroundSprite.setTexture(ground_tex);
            GroundSprite.setColor(sf::Color::Magenta);
            GroundSprite.setOrigin(400.f, 16.0f);
            GroundSprite.setPosition(bodyIterator->GetPosition().x * SCALE, bodyIterator->GetPosition().y * SCALE);
            GroundSprite.setRotation(180/b2_pi * bodyIterator->GetAngle());
          //  window.draw(GroundSprite);
           spites[spites_count++] = GroundSprite;
        }*/
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

    //FixtureDef= 1.0f;
    //FixtureDef.friction = 1.0f;
    FixtureDef.shape = &Shape;

    Body->CreateFixture(&FixtureDef);
}

