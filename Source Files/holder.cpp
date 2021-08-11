#include "holder.h"

RectangleShape Holder::GetRect() {
	RectangleShape powerMeter(Vector2f(20.0f, currentLength));
	powerMeter.setOrigin(Vector2f(0.0f, currentLength));
	powerMeter.setPosition(position);
	powerMeter.setFillColor(Color::White);

	return powerMeter;
}

void Holder::Animate() {
	if (animate) {
		if (upState) currentLength += speed;
		else currentLength -= speed;

		if (currentLength > maxLength) upState = false;
		else if (currentLength < 5) upState = true;
	}
}

void Holder::StopAnimating() {
	currentLength = 0;
	animate = false;
}

void Holder::StartAnimating() {
	animate = true;
}

double Holder::GetPower() {
	return currentLength * 4.3;
}

Holder::Holder() {
	this->maxLength = 140;
	this->currentLength = 0;
	this->position = Vector2f(0, 350.0f);
	this->speed = 3;
	this->upState = true;
	this->animate = false;
}