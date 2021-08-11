#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace std;
using namespace sf;

class Holder {
private:
	double maxLength;
	double currentLength;
	double speed;
	bool upState;
	bool animate;
	Vector2f position;

public:
	void StartAnimating();
	RectangleShape GetRect();
	void Animate();
	void StopAnimating();
	double GetPower();

	Holder();
};

