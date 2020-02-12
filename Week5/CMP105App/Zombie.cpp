#include<iostream>>
#include "Zombie.h"


Zombie::Zombie()
{
	setVelocity(sf::Vector2f(150, 150));
	addFrames();
}

Zombie::~Zombie()
{
	std::cout << "Zombie object destroyed!\n";
}

void Zombie::update(float dt)
{
	if (!walk.getPlaying())
	{
		walk.reset();
	}

	setTextureRect(walk.getCurrentFrame());
}

void Zombie::handleInput(float dt)
{
	walk.setPlaying(false);

	// Move right.
	if (input->isKeyDown(sf::Keyboard::D))
	{
		walk.setPlaying(true);
		walk.setFlipped(false);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());

		setPosition(sf::Vector2f(getPosition().x + getVelocity().x * dt, getPosition().y));


	}

	// Move left.
	if (input->isKeyDown(sf::Keyboard::A))
	{
		walk.setPlaying(true);
		walk.setFlipped(true);
		walk.animate(dt);
		setTextureRect(walk.getCurrentFrame());

		setPosition(sf::Vector2f(getPosition().x - getVelocity().x * dt, getPosition().y));
	}
}

void Zombie::addFrames()
{
	for (int i = 0; i < (walkFrames * FRAME_WIDTH); i += FRAME_WIDTH)
	{
		walk.addFrame(sf::IntRect(i, 0, FRAME_WIDTH, FRAME_HEIGHT));
	}

	/*walk.addFrame(sf::IntRect(0, 0, FRAME_WIDTH, FRAME_HEIGHT));
	walk.addFrame(sf::IntRect(55, 0, FRAME_WIDTH, FRAME_HEIGHT));
	walk.addFrame(sf::IntRect(110, 0, FRAME_WIDTH, FRAME_HEIGHT));
	walk.addFrame(sf::IntRect(165, 0, FRAME_WIDTH, FRAME_HEIGHT));
	walk.addFrame(sf::IntRect(220, 0, FRAME_WIDTH, FRAME_HEIGHT));
	walk.addFrame(sf::IntRect(275, 0, FRAME_WIDTH, FRAME_HEIGHT));
	walk.addFrame(sf::IntRect(330, 0, FRAME_WIDTH, FRAME_HEIGHT));
	walk.addFrame(sf::IntRect(385, 0, FRAME_WIDTH, FRAME_HEIGHT));*/
	walk.setFrameSpeed(1.0f / 10.f);
}