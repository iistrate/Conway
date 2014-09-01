#include "TextureManager.h"

TextureManager::TextureManager() :m_pTexture(0), m_ilevelHeight(1800), 
m_ilevelWidth(2400), m_iscreenHeight(900), m_iscreenWidth(1200){}
TextureManager::~TextureManager() {

}

void TextureManager::draw(SDL_Renderer* f_prenderer, std::list < Image* > f_Images, SDL_RendererFlip f_flip) {
	//helper vars
	int cameraModifierX = (-1)* m_icamX;
	int cameraModifierY = (-1)* m_icamY;
	int origX = 0;
	int origY = 0;
	int width = 0;
	int height = 0;
	const char* fname = "";

	for (std::list < Image* >::iterator it = f_Images.begin(); it != f_Images.end(); ++it) {
		fname = (*it)->getFileName();
		m_pTexture = IMG_LoadTexture(f_prenderer, fname);
		//image vars
		width = (*it)->getWidth();
		height = (*it)->getHeight();

		//width and height of image
		m_srcRect.w = m_dstRect.w = width;
		m_srcRect.h = m_dstRect.h = height;

		m_srcRect.x = 0;
		m_srcRect.y = 0;


		origX = (*it)->getX();
		origY = (*it)->getY();
		//where to draw at
		m_dstRect.x = (*it)->isStatic() ? origX : origX + cameraModifierX;
		m_dstRect.y = (*it)->isStatic() ? origY : origY + cameraModifierY;

		//magic
		SDL_RenderCopyEx(f_prenderer, m_pTexture, &m_srcRect, &m_dstRect, NULL, NULL, f_flip);

	}
	SDL_DestroyTexture(m_pTexture);
	m_pTexture = NULL;
}

//set camera x position
void TextureManager::setCamX(int i) {
	m_icamX = i;
}
//set camera y position
void TextureManager::setCamY(int i) {
	m_icamY = i;
}