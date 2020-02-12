#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	initTextures();	
	initZombie();
	initMario();
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	zombie_1.handleInput(dt);
	mario_1.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	zombie_1.update(dt);
	mario_1.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(zombie_1);
	window->draw(mario_1);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}

void Level::initTextures()
{
	zombTexture.loadFromFile("gfx/animZombie.png");
	marioTexture.loadFromFile("gfx/MarioSheetT.png");
}

void Level::initZombie()
{
	zombie_1.setInput(input);
	zombie_1.setWindow(window);
	zombie_1.setSize(sf::Vector2f(55, 100));
	zombie_1.setPosition(100, 100);
	zombie_1.setOrigin(sf::Vector2f(zombie_1.getSize().x / 2, zombie_1.getSize().y / 2));
	zombie_1.setTexture(&zombTexture);
}

void Level::initMario()
{
	mario_1.setInput(input);
	mario_1.setWindow(window);
	mario_1.setSize(sf::Vector2f(16, 21));				// Max size to accomodate ALL sprites.
	mario_1.setPosition(100, 100);
	mario_1.setOrigin(sf::Vector2f(mario_1.getSize().x / 2, mario_1.getSize().y / 2));
	mario_1.setTexture(&marioTexture);
}
