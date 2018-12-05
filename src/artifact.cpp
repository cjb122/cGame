/* Team Bandcamp
 * Class function: 
 * The class that handles artifact operations
*/
#include "include/artifact.h"
#include <iostream>

Artifact::Artifact(std::string name_, SDL_Texture* image_, int r_, int g_, int b_) {
	name = name_;
	image = image_;
	r = r_;
	g = g_;
	b = b_;
}

Artifact::Artifact(){}

std::string Artifact::getName(){
	return name;
}

SDL_Texture* Artifact::getImage(){
    return image;
}


int Artifact::getR(){
	return r;
}

int Artifact::getG(){
	return g;
}

int Artifact::getB(){
	return b;
}