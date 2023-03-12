/**
 * @file mainTxt.cpp
 * @author Yanisse FERHAOUI
 * @brief 
 * @version 0.1
 * @date 2022-11-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "winTxt.h"
#include "txtJeu.h"

int main(int argc, char ** argv){

    termClear();
	Jeu jeu;
	txtBoucle(jeu);
    termClear();

    return 0;
}