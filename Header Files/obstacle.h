#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace std;
using namespace sf;

class ObstacleBlock {
private:
	Vector2f position;
	bool drawing;

public:
	double currentWidth;
	double currentHeight;

	Vector2f GetPosition();
	void Operate(double, double);
	void StartDrawing();
	void StopDrawing();
	RectangleShape GetRect();

	ObstacleBlock(Vector2f);
};
