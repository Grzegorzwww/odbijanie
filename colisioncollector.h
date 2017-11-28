#ifndef COLISIONCOLLECTOR_H
#define COLISIONCOLLECTOR_H

#include <iostream>

class ColisionCollector
{
public:

    static ColisionCollector * GetColisionCollector();


    void setGroundColision(bool state);
    void setBallColision(bool state);
    void control();


protected:
    ColisionCollector() {}
private:
    bool kolizja_pilka;
    bool kolizja_ziemia;

};

#endif // COLISIONCOLLECTOR_H
