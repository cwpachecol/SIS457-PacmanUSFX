#include "PacmanGalactico.h"
//
//PacmanGalactico::PacmanGalactico(Tile* _tile, Texture* _texturaPacman, int _posicionX, int _posicionY, int _velocidadPatron) 
//	:GameObject(_texturaPacman, _posicionX, _posicionY)
//{
//
//
//}

#include <stdio.h>

PacmanGalactico::PacmanGalactico(Tile* _tile, Texture* _texturaPacmanGalactico, int _posicionX, int _posicionY, int _velocidadPatron) :
	Pacman(_tile, _texturaPacmanGalactico, _posicionX, _posicionY, _velocidadPatron)
{
	texturaAnimacion = new TextureAnimation();
	texturaAnimacion->setTexture(_texturaPacmanGalactico);
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 0, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("izquierda", new SDL_Rect({ 25, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 0, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("derecha", new SDL_Rect({ 25, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 50, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("arriba", new SDL_Rect({ 75, 25, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 50, 0, 25, 25 }));
	texturaAnimacion->addCuadroAnimacion("abajo", new SDL_Rect({ 75, 0, 25, 25 }));


	tileActual = _tile;
	tileSiguiente = nullptr;

	if (tileActual != nullptr) {
		tileActual->setPacman(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}
	else {
		posicionX = 0;
		posicionY = 0;
	}


	//Colisionador ancho y alto 
	//collider->w = Width;
	//collider->h = Height;

	////colisionador posicionX
	//collider->x = posicionX;

	////colisionador posicionY
	//collider->y = posicionY;

	direccionActual = MOVE_RIGHT;
	direccionSiguiente = MOVE_RIGHT;


	// Inicializa propiedade de de pacman
	velocidadX = 0;
	velocidadY = 0;
	velocidadPatron = _velocidadPatron;
	posicionXEnTextura = 0;
	posicionYEnTextura = 0;
	vida = 10;
}

void PacmanGalactico::RestarVida() {
	if (vida > 0) {
		vida--;
	}
}



//DESTRUCTOR y deja un espacio libre 
PacmanGalactico::~PacmanGalactico()
{
	//Free();
}

void PacmanGalactico::setTile(Tile* _tileNuevo) {

	if (tileActual != nullptr) {
		tileActual->setPacman(nullptr);
	}

	tileActual = _tileNuevo;

	if (tileActual != nullptr) {
		tileActual->setPacman(this);

		posicionX = tileActual->getPosicionX() * Tile::anchoTile;
		posicionY = tileActual->getPosicionY() * Tile::altoTile;
	}

}