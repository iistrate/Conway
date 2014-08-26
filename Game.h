#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "Globals.h"
#include "TextureManager.h"
#include "World.h"


class Game {
private:
	//sdl vars
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	//controls game loop
	bool m_brunning;

	//composition
	TextureManager Tmanager;
	World* Conways;

	//image sets
	std::vector < Image* > m_Images_WORLD;
	std::vector < Image* > m_Images_MOVING;

	//vars
	int m_ifpsCap;


public:
	Game();
	//cleans up SDL
	~Game();
	//initialize SDL, create window 
	void init(const char* title, int x, int y, int w, int h, int flags);
	//start game loop
	void run();
	//exits game loop;
	void quit();
	//fps
	void fpsCap();
};

#endif