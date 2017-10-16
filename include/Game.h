#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <Box2D/Box2D.h>



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

    sf::RenderWindow window;
     b2Vec2 _gravity;
     b2World *_World;

    sf::Texture object_tex;
    sf::Texture ground_tex;
    sf::Texture back_ground_tex;

     sf::Sprite GroundSprite;
     sf::Sprite BodySprite;
     sf::Sprite BackGroundSprite;


     sf::Sprite spites[255];


    void CreateGround(b2World& World, float X, float Y);
    void CreateBox(b2World& World, int MouseX, int MouseY);


};

#endif // GAME_H
