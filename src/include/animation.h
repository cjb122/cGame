#ifndef BANDCAMP_ANIMATION_H_
#define BANDCAMP_ANIMATION_H_

#include <SDL.h>
#include <vector>

class Animation
{
private:
	std::vector< SDL_Rect > frames;
	int curFrame;
	Uint32 frameTicks;
	bool playing;
	bool loop;
public:
	Animation(std::vector<SDL_Rect> _frames);
	Animation(std::vector<SDL_Rect> _frames, bool _loop);
	Animation();
	~Animation();
	void update(Uint32 ticks);
	void play();
	void stop();
	void reset();
	SDL_Rect* getFrame();
	void setFrame(int _frame);
};

#endif  //  BANDCAMP_ANIMATION_H_