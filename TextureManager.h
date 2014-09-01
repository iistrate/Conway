#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <list>
#include <iostream>


#include "Image.h"

class TextureManager {
private:
	SDL_Rect m_dstRect;
	SDL_Rect m_srcRect;
	SDL_Texture* m_pTexture;

	Uint32 FPS;

	//camera position
	int m_icamX;
	int m_icamY;
	int m_icamSpeed;

	//level dimension
	int m_ilevelWidth;
	int m_ilevelHeight;

	//screen dimension
	int m_iscreenWidth;
	int m_iscreenHeight;

public:
	TextureManager();
	~TextureManager();


	void draw(SDL_Renderer* f_prenderer, std::list < Image* > f_Images, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void setCamX(int);
	void setCamY(int);
};
#endif // end TextureManager.h