#include "Game.h"


void Game::init(const char* title, int x, int y, int w, int h, int flags) {
	//starts game loop
	m_brunning = true;

	//initialize sdl
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");
		SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
		m_pWindow = SDL_CreateWindow(title, x, y, w, h, flags);

		if (m_pWindow) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);
			SDL_SetRenderDrawColor(m_pRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
		}
		else {
			std::cout << "Window failed to load" << std::endl;
		}
	}
	else {
		std::cout << "SDL failed to initialize" << std::endl;
	}
}

void Game::run() {
	int tick = 0;
	//init sdl
	init("Conway", 32, 32, GLOBALS::SCREEN_WIDTH, GLOBALS::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	//create world
	Conways = new World();

	SDL_Event e;
	do {
		tick++;
		std::cout << tick << std::endl;
		Conways->getImages(m_Images);
		Conways->update();
	
		//clear window
		SDL_RenderClear(m_pRenderer);

		//error checking
		std::cout << SDL_GetError();
		std::cout << IMG_GetError();

		//set color bg to white
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

		//draw images
		Tmanager.draw(m_pRenderer, m_Images);

		SDL_RenderPresent(m_pRenderer);
		//
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_ESCAPE: quit();
				}
			}
		}
		//

		//cap fps
		fpsCap();
	} while (m_brunning);
}
void Game::fpsCap() {
	//time in seconds
	int fps = SDL_GetTicks() / 1000;
	if (fps < 1000 / m_ifpsCap) {
		//fps per seconds - time difference from when the loop started till the end in seconds
		SDL_Delay((1000 / m_ifpsCap) - (fps / 1000));
	}
}
void Game::quit() {
	m_brunning = false;
	IMG_Quit();
	SDL_Quit();
}
Game::Game(): m_brunning(false), m_ifpsCap(50) {

}
Game::~Game() {

}