#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace std;
using namespace sf;

class Ball {
private:
	double mass;
	Vector2f position;
	Color color;
	Vector2f velocity;
	Vector2f acceleration;

public:
	double radius;
	void ApplyForce(Vector2f force);
	void Move();
	void Collide(string);

	CircleShape GetRectangle();

	Ball(Vector2f position, Vector2f velocity, double mass);
};
