/**
 * @file snake.cpp
 * @author Yanisse FERHAOUI
 * @brief 
 * @version 0.1
 * @date 2022-11-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "snake.h"
#include <cassert>

Snake::Snake(){
    tete.x = tete.ox = 10;
    tete.y = tete.oy = 10;
    corps.push_back(tete);
    taille = 1;
}

int Snake::getTaille() const{ return taille; }

int Snake::getXTete() const{return tete.x;}

int Snake::getYTete() const{return tete.y;}

int Snake::getXCorps(unsigned int i) const{
    assert(i < taille);
    return corps[i].x;
}

int Snake::getYCorps(unsigned int i) const{
    assert(i < taille);
    return corps[i].y;
}

void Snake::haut(Terrain & ter){
    if(ter.estPositionValide(tete.x, tete.y+1)){
        tete.oy = tete.y;
        tete.ox = tete.x;
        tete.y++;
    }
}

void Snake::bas(Terrain & ter){
    if(ter.estPositionValide(tete.x, tete.y-1)){
        tete.oy = tete.y;
        tete.ox = tete.x;
        tete.y--;
    }
}

void Snake::gauche(Terrain & ter){
    if(ter.estPositionValide(tete.x-1, tete.y)){
        tete.ox = tete.x;
        tete.oy = tete.y;
        tete.x--;
    }
}

void Snake::droite(Terrain & ter){
    if(ter.estPositionValide(tete.x+1, tete.y)){
        tete.ox = tete.x;
        tete.oy = tete.y;
        tete.x++;
    }
}

void Snake::update_corps(){
    unsigned int i;
    
    corps[0].oy = corps[0].y;
    corps[0].y = tete.oy;
    corps[0].ox = corps[0].x;
    corps[0].x = tete.ox;
    for(i = 1; i < taille; i++){
        corps[i].oy = corps[i].y;
        corps[i].y = corps[i-1].oy;
        corps[i].ox = corps[i].x;
        corps[i].x = corps[i-1].ox;
    }
    
}

void Snake::mange(Fruit &Fr, Terrain &ter){
    if(tete.x == Fr.getX() && tete.y == Fr.getY()){
        Fr.changePos(ter);
        grandir();
    }
}

void Snake::grandir(){
    corps.push_back(corps[taille-1]);
    taille++;
}