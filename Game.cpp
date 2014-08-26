#include "Game.h"

void Game::run() {
	//init sdl
	init("Practicum", 0, 0, GLOBALS::SCREEN_WIDTH, GLOBALS::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	//create world
	Conways = new World();

	while (m_brunning) {
		void;
	}
}
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
		}
		else {
			std::cout << "Window failed to load" << std::endl;
		}
	}
	else {
		std::cout << "SDL failed to initialize" << std::endl;
	}

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

}
Game::Game(): m_brunning(false), m_ifpsCap(50) {

}
Game::~Game() {

}