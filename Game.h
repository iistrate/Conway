#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h>

#include "Globals.h"
#include "World.h"

class Game {
private:
	//sdl vars
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	//controls game loop
	bool m_brunning;
public:
	Game();
	void start();
	void initSDL();
};

#endif