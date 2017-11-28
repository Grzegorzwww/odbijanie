#ifndef GAME_H
#define GAME_H


#include <cstdint>
#include <cassert>
#include <iostream>
#include "sstream"

#include <defines.h>

#include "player.h"
#include "ball.h"
#include "ground.h"
#include "paletka.h"
#include "menu.h"




class MyContactListener : public b2ContactListener
{
  public:
  void BeginContact(b2Contact* contact) {

    //check if fixture A was a ball
    void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
    if ( bodyUserData )
      static_cast<Ball*>( bodyUserData )->startContact();

    //check if fixture B was a ball
    bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
    if ( bodyUserData )
      static_cast<Ground*>( bodyUserData )->startContact();

  }

  void EndContact(b2Contact* contact) {

    //check if fixture A was a ball
    void* bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
    if ( bodyUserData )
      static_cast<Ball*>( bodyUserData )->endContact();

    //check if fixture B was a ball
    bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
    if ( bodyUserData )
      static_cast<Ground*>( bodyUserData )->endContact();
  }

//  void PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
//  { /* handle pre-solve event */ }
//  void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
//  { /* handle post-solve event */ }
};





class Game {
public:

    Game();
    void run();
    virtual ~Game();

protected:

private:

    void processEvents();
    void update();
    void render();


    const int SCALE = 30;
    int spites_count;
    int pilki_counter;

    bool fail_detcted;


    sf::RenderWindow window;
     b2Vec2 _gravity;
     b2World *World;

    sf::Texture back_ground_tex;
    sf::Sprite _backGroundSprite;

    game_state_t game_sate;
    int player_1_counter;
    int player_2_counter;

    int prev_ball_altitude;


     MyContactListener myContactListenerInstance;


    Player *player_one;
    Player *player_two;


    //Ball *ball[250];
    Ball *ball;


    Ground *ground;
    Ground *left_wall;
    Ground *right_wall;


    std::vector<sf::Sprite > sprites_buffor;




    Menu *menu;

    void CreateGround(b2World& World, float X, float Y);
    void CreateBox(b2World& World, int MouseX, int MouseY);

    void create_ground(b2World& World, float X, float Y, float heigh, float width);
    void create_ball(b2World& World, int MouseX, int MouseY);



    void resumeGame();
    void newGame();
    void collisionDetection();
    void constrolLogic();

};

#endif // GAME_H
