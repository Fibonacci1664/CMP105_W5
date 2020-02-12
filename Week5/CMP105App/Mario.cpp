#include "Mario.h"
#include <iostream>


Mario::Mario()
{
	movingLeft = false;
	movingRight = false;
	setVelocity(sf::Vector2f(150, 150));
	addFrames();
}

Mario::~Mario()
{
	std::cout << "Mario object destroyed!\n";
}

void Mario::update(float dt)
{
	if (!run.getPlaying())
	{
		run.reset();
	}
	else
	{
		setTextureRect(run.getCurrentFrame());
	}

	if (!swim.getPlaying())
	{
		swim.reset();
	}
	else
	{
		setTextureRect(swim.getCurrentFrame());
	}

	if (!duck.getPlaying())
	{
		duck.reset();
	}
	else
	{
		setTextureRect(duck.getCurrentFrame());
	}
}

void Mario::handleInput(float dt)
{
	run.setPlaying(false);
	swim.setPlaying(false);
	duck.setPlaying(false);

	// Move right.
	if (input->isKeyDown(sf::Keyboard::L))
	{
		movingRight = true;
		movingLeft = false;
		run.setPlaying(true);
		run.setFlipped(false);
		run.animate(dt);
		setTextureRect(run.getCurrentFrame());

		setPosition(sf::Vector2f(getPosition().x + getVelocity().x * dt, getPosition().y));
	}

	// Move left.
	if (input->isKeyDown(sf::Keyboard::J))
	{
		movingLeft = true;
		movingRight = false;
		run.setPlaying(true);
		run.setFlipped(true);
		run.animate(dt);
		setTextureRect(run.getCurrentFrame());

		setPosition(sf::Vector2f(getPosition().x - getVelocity().x * dt, getPosition().y));
	}

	// Swim right.
	if (input->isKeyDown(sf::Keyboard::P) && (input->isKeyDown(sf::Keyboard::L)))
	{
		run.setPlaying(false);
		swim.setPlaying(true);
		swim.setFlipped(false);
		swim.animate(dt);
		setTextureRect(swim.getCurrentFrame());

		setPosition(sf::Vector2f(getPosition().x + (getVelocity().x / 3) * dt, getPosition().y));
	}

	// Swim left.
	if (input->isKeyDown(sf::Keyboard::P) && (input->isKeyDown(sf::Keyboard::J)))
	{
		run.setPlaying(false);
		swim.setPlaying(true);
		swim.setFlipped(true);
		swim.animate(dt);
		setTextureRect(swim.getCurrentFrame());

		setPosition(sf::Vector2f(getPosition().x - (getVelocity().x / 3) * dt, getPosition().y));
	}

	// Duck.
	if (input->isKeyDown(sf::Keyboard::K))
	{
		run.setPlaying(false);
		duck.setPlaying(true);
		
		if (movingRight)
		{
			duck.setFlipped(false);
		}
		else if (movingLeft)
		{
			duck.setFlipped(true);
		}

		//duck.animate(dt);
		setTextureRect(duck.getCurrentFrame());

		setPosition(sf::Vector2f(getPosition().x, getPosition().y));
	}
}

void Mario::addFrames()
{
	for (int i = 0; i < (runFrames * FRAME_WIDTH); i += FRAME_WIDTH)
	{
		run.addFrame(sf::IntRect(i, 0, FRAME_WIDTH, FRAME_HEIGHT));
	}

	for (int i = 0; i < (swimFrames * FRAME_WIDTH); i += FRAME_WIDTH)
	{
		swim.addFrame(sf::IntRect(i, FRAME_HEIGHT, FRAME_WIDTH, FRAME_HEIGHT));
	}

	for (int i = 0; i < (duckFrames * FRAME_WIDTH); i += FRAME_WIDTH)
	{
		duck.addFrame(sf::IntRect(i, (FRAME_HEIGHT * 2), FRAME_WIDTH, FRAME_HEIGHT));
	}

	run.setFrameSpeed(1.0f / 10.f);
	swim.setFrameSpeed(1.5f / 10.f);
	duck.setFrameSpeed(1.0f / 10.f);
}