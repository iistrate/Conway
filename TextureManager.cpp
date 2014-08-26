#include "TextureManager.h"

TextureManager::TextureManager() :m_pTexture(0), m_pTextSurface(0),m_ilevelHeight(1800), 
m_ilevelWidth(2400), m_iscreenHeight(900), m_iscreenWidth(1200){}
TextureManager::~TextureManager() {

}

void TextureManager::draw(SDL_Renderer* f_prenderer, std::vector < Image* > f_Images, SDL_RendererFlip f_flip) {
	//helper vars
	int cameraModifierX = (-1)* m_icamX;
	int cameraModifierY = (-1)* m_icamY;
	int origX = 0;
	int origY = 0;
	int currentFrame = 1;
	int totalFrames = 2;
	int width = 0;
	int height = 0;
	bool animated = false;
	bool flipped = false;

	const char* fname = "";
	//surface to texture loader
	for (std::vector < Image >::size_type i = 0; i != f_Images.size(); i++) {
		//image vars
		animated = f_Images[i]->isAnimated();
		flipped = f_Images[i]->isFlipped();
		width = f_Images[i]->getWidth();
		height = f_Images[i]->getHeight();
		currentFrame = f_Images[i]->getFrame();
		totalFrames = f_Images[i]->getTotalFrames();

		//see if image is flipped 
		if (flipped) {
			f_flip = SDL_FLIP_HORIZONTAL;
		}
		else {
			f_flip = SDL_FLIP_NONE;
		}

		//width and height of image
		m_srcRect.w = m_dstRect.w = width;
		m_srcRect.h = m_dstRect.h = height;

		m_srcRect.x = f_Images[i]->isAnimated() ? f_Images[i]->getSpriteX() + (currentFrame * width) : f_Images[i]->getSpriteX();
		m_srcRect.y = f_Images[i]->getSpriteY();


		origX = f_Images[i]->getX();
		origY = f_Images[i]->getY();
		//where to draw at
		m_dstRect.x = f_Images[i]->isStatic() ? origX : origX + cameraModifierX;
		m_dstRect.y = f_Images[i]->isStatic() ? origY : origY + cameraModifierY;

		//magic
		SDL_RenderCopyEx(f_prenderer, m_pTexture, &m_srcRect, &m_dstRect, NULL, NULL, f_flip);

		//see if it is animated
		if (animated) {
			//figure out next frame
			currentFrame = currentFrame + 1 == totalFrames ? 1 : currentFrame + 1;
			//set frame
			f_Images[i]->setCurrentFrame(currentFrame);
			f_Images[i]->animate(false);
		}
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