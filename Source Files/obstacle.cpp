#include "obstacle.h"

Vector2f ObstacleBlock::GetPosition() {
	return position;
}

void ObstacleBlock::Operate(double width, double height) {
	if (drawing) {
		currentWidth = width;
		currentHeight = height;
	}
}

void ObstacleBlock::StartDrawing() {
	drawing = true;
}

void ObstacleBlock::StopDrawing() {
	drawing = false;
}

RectangleShape ObstacleBlock::GetRect() {
	RectangleShape obstacleRect(Vector2f(currentWidth, currentHeight));
	obstacleRect.setOrigin(Vector2f(0, currentHeight));
	obstacleRect.setPosition(position);
	obstacleRect.setFillColor(Color::White);

	return obstacleRect;
}

ObstacleBlock::ObstacleBlock(Vector2f placement) {
	this->position = placement;
	this->currentWidth = 0;
	this->currentHeight = 0;
	this->drawing = true;
}
