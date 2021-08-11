#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#pragma once
#include <cmath>
#include "ball.h"
using namespace std;
using namespace sf;

class Cannon {
private:
    double angle;
    double length;
    double width;
    Vector2f origin;

public:
    Vector2f GetTip() { return Vector2f(origin.x + cos(angle) * length, origin.y - sin(angle) * length); }
    double GetAngle() { return angle; }
    double GetLength() { return length; }
    Vector2f GetOrigin() { return origin; }

    void PointTo(Vector2f position);
    void SetOrigin(Vector2f position);

    void shot(vector<Ball>& balls, double magnitude);

    RectangleShape GetRectangle();

    Cannon(double angle, double length, double width);
    Cannon();
};
