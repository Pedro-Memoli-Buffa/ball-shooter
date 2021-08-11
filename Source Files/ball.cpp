#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "ball.h"
using namespace std;
using namespace sf;

void Ball::ApplyForce(Vector2f force) {
	this->velocity = Vector2f(velocity.x + force.x / (60 * mass), velocity.y + force.y / (60 * mass));
}

void Ball::Move() {  // Moves according to velocity and applies acceleration
	this->position = Vector2f(position.x + velocity.x / 60, position.y + velocity.y / 60);
}

void Ball::Collide(string direction) {
	if (direction == "left") {
		this->position = Vector2f(position.x - 10, position.y);
		this->velocity = Vector2f(-velocity.x, velocity.y);
	}
	else if (direction == "right") {
		this->position = Vector2f(position.x + 10, position.y);
		this->velocity = Vector2f(-velocity.x, velocity.y);
	}
	else if (direction == "up") {
		this->position = Vector2f(position.x, position.y - 10);
		this->velocity = Vector2f(velocity.x, -velocity.y);
	}
	else if (direction == "down") {
		this->position = Vector2f(position.x, position.y + 10);
		this->velocity = Vector2f(velocity.x, -velocity.y);
	}
}

CircleShape Ball::GetRectangle() {
	CircleShape ballRect(radius);
	ballRect.setFillColor(Color::White);
	ballRect.setPosition(position);
	return ballRect;
}

Ball::Ball(Vector2f position, Vector2f velocity, double mass) {
	this->mass = mass;
	this->radius = 6;
	this->color = Color::White;
	this->velocity = velocity;
	this->acceleration = Vector2f(0.0f, 0.0f);
	this->position = position;
}