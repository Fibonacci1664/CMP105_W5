#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Mario : public GameObject
{
public:
	Mario();
	~Mario();

	void update(float dt) override;
	void handleInput(float dt) override;


protected:
	Animation run;
	Animation swim;
	Animation duck;

private:
	const int runFrames = 4;
	const int swimFrames = 3;
	const int duckFrames = 2;

	const int FRAME_WIDTH = 15;
	const int FRAME_HEIGHT = 21;

	bool movingLeft;
	bool movingRight;

	void addFrames();
};

