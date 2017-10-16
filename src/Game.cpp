#include "Game.h"

Game::Game() : window(sf::VideoMode(800, 600), "SFML window")
{
    //cto

      window.setFramerateLimit(60);


    _gravity = b2Vec2(0.f, 100.0f);
    _World = new b2World(_gravity, true);





    if (!object_tex.loadFromFile("ball_small.png")) {
        // error...
    }



    /*if (!ground_tex.loadFromFile("ground.jpg")) {
        // error...
    }*/


    if (!back_ground_tex.loadFromFile("background.jpg")) {
        // error...
    }


    CreateGround(*_World, 400.f, 500.f);






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

    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))

    {
        int MouseX = sf::Mouse::getPosition(window).x;
        int MouseY = sf::Mouse::getPosition(window).y;
        CreateBox(*_World, MouseX, MouseY);
    }


}

void Game::update() {

    BackGroundSprite.setTexture(back_ground_tex);
    BackGroundSprite.setPosition(0, 0);


    spites_count = 0;

    for(b2Body *bodyIterator = _World->GetBodyList(); bodyIterator  != 0; bodyIterator  = bodyIterator ->GetNext()) {
        if (bodyIterator ->GetType() == b2_dynamicBody) {

            BodySprite.setTexture(object_tex);
            BodySprite.setOrigin(16.f, 16.f);
            BodySprite.setPosition(SCALE * bodyIterator->GetPosition().x, SCALE * bodyIterator->GetPosition().y);
            BodySprite.setRotation(bodyIterator->GetAngle() * 180/b2_pi);
            spites[spites_count++] = BodySprite;


        } else {


            GroundSprite.setTexture(ground_tex);
            GroundSprite.setOrigin(400.f, 16.f);
            GroundSprite.setPosition(bodyIterator->GetPosition().x * SCALE, bodyIterator->GetPosition().y * SCALE);
            GroundSprite.setRotation(180/b2_pi * bodyIterator->GetAngle());
          //  window.draw(GroundSprite);
           spites[spites_count++] = BodySprite;

        }

    }
      _World->Step(1/60.f, 8, 3);
}




void Game::render()
{
    window.clear();
    //window.draw();



        window.draw(BackGroundSprite);
        for(int i = 0; i < spites_count; i++ ){
            window.draw(spites[i]);
        }
       // window.draw(BodySprite);
      // window.draw(GroundSprite);
        window.display();
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
    FixtureDef.density = 0.f;  // Sets the density of the body
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
    FixtureDef.density = 1.f;
    FixtureDef.friction = 0.7f;
    FixtureDef.shape = &Shape;
    FixtureDef.restitution = 0.4f;
    Body->CreateFixture(&FixtureDef);
}

