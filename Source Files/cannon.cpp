#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "cannon.h"
using namespace std;
using namespace sf;

constexpr double pi = 3.14159265358979323846;

void Cannon::PointTo(Vector2f position) {
    double deltaX = (double)position.x - (double)origin.x;
    double deltaY = (double)origin.y - (double)position.y;
    this->angle = atan(deltaY / deltaX) * 180 / pi;
}

void Cannon::SetOrigin(Vector2f position) {
    this->origin = position;
}

RectangleShape Cannon::GetRectangle() {
    RectangleShape cannonRect(Vector2f(length, width));
    cannonRect.setOrigin(0, width / 2);
    cannonRect.rotate(-angle);
    cannonRect.setFillColor(Color::White);
    cannonRect.setPosition(0.0f, 600.0f);

    return cannonRect;
}

void Cannon::shot(vector<Ball>& balls, double magnitude) {
    Vector2f position(origin.x + length * cos(angle * 3.14159 / 180), origin.y - length * sin(angle * 3.14159 / 180));

    Vector2f direction(length * cos(angle * 3.14159 / 180), -length * sin(angle * 3.14159 / 180));
    float norm = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    direction.x /= norm;
    direction.y /= norm;

    Vector2f initialVelocity(direction.x * magnitude, direction.y * magnitude);
    Ball ball(position, initialVelocity, 10.0f);
    balls.push_back(ball);
}

Cannon::Cannon(double angle, double length, double width) {
    this->angle = angle;
    this->length = length;
    this->width = width;
    this->origin = Vector2f(0.0f, 600.0f);
}

Cannon::Cannon() {
    this->angle = 40.0f;
    this->length = 60.0f;
    this->width = 15.0f;
    this->origin = Vector2f(0.0f, 600.0f);
}
