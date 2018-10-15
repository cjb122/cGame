#ifndef BANDCAMP_TESTROOM_H_
#define BANDCAMP_TESTROOM_H_

#include <SDL.h>
#include <vector>

#include "screen.h"
#include "object.h"
#include "pickup.h"

class TestRoom : public Screen 
{ 
	private:
		bool start;
		std::vector<Object*> objectList;
		int* roomReference;
		SDL_Renderer* rendererReference;
		bool escape; //Have we pushed the escape key?
	
	public: 
		TestRoom(int* roomReference);
		void init(SDL_Renderer* renderer);
		void input(const Uint8* keystate);
		void update();
		SDL_Renderer* draw(SDL_Renderer* renderer);
		void checkPickups();
};

#endif  //  BANDCAMP_TESTROOM_H_