/**
 * @file terrain.cpp
 * @author Yanisse FERHAOUI
 * @brief 
 * @version 0.1
 * @date 2022-11-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "terrain.h"

const char terrain[21][59] ={
"##########################################################",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"#                                                        #",
"##########################################################"
};


Terrain::Terrain(){

    dimy = 20;
    dimx = 58;

    for(unsigned int x = 0; x < dimx; ++x){
        for(unsigned int y = 0; y < dimy; ++y){
            switch(terrain[dimy-1-y][x]){
                case '#': ter[x][y] = WALL; break;
                case ' ': ter[x][y] = SPACE; break;
                case 'F': ter[x][y] = FRUIT; break;
                case 'o': ter[x][y] = SNAKE; break;
            }
        }
    }

}

unsigned int Terrain::getDimX() const { return dimx;}
unsigned int Terrain::getDimY() const { return dimy;}

Terrain::TypeCase Terrain::getXY(const unsigned int & x, const unsigned int &y) const{
    
    assert(x <= dimx);
    assert(y <= dimy);
    
    return ter[x][y];
}

char Terrain::getXYAsChar(const unsigned int &x, const unsigned int &y)const {
    assert(x <= dimx);
    assert(y <= dimy);
    
    return (char)(ter[x][y]);
}

bool Terrain::estPositionValide(const unsigned int x, const unsigned int y) const{
    return ((x >= 0) && (y >= 0) && (x < dimx) && (y < dimy) && (ter[x][y] != '#'));
}