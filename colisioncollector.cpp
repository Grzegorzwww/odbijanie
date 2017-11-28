#include "colisioncollector.h"



ColisionCollector * ColisionCollector::GetColisionCollector() {

    static  ColisionCollector objColisionCollector;
    return &objColisionCollector;
}

void ColisionCollector::setGroundColision(bool state){
//    kolizja_ziemia = state;
//    control();
    //std::cout <<"setGroundColision \n";
}

void ColisionCollector::setBallColision(bool state){
//    kolizja_pilka = state;
//    control();
    //std::cout <<"setBallColision \n";
}

void ColisionCollector::control(){
//    if(kolizja_pilka == true && kolizja_ziemia  == true){
//        std::cout <<"detekcja kolizji \n";
//    }



}

