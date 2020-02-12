#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Zombie : public GameObject
{
public:
	Zombie();
	~Zombie();

	void update(float dt) override;
	void handleInput(float dt) override;

protected:
	Animation walk;

private:
	const int walkFrames = 8;
	const int FRAME_WIDTH = 55;
	const int FRAME_HEIGHT = 108;

	void addFrames();

};
