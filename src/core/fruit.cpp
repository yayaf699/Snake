/**
 * @file fruit.cpp
 * @author Yanisse FERHAOUI
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "fruit.h"

Fruit::Fruit(){
    x = 30;
    y = 10;
}

unsigned int Fruit::getX() const{
    return x;
}

unsigned int Fruit::getY() const{
    return y;
}

void Fruit::changePos(Terrain &ter){
    do{
        x = (rand()%(ter.getDimX()-1)-1+1)+1;
        y = (rand()%(ter.getDimY()-1)-1+1)+1;
    }while (ter.getXYAsChar(x, y) != ' ');
    
}