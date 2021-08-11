#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "holder.h"
#include "ball.h"
#include "cannon.h"
#include "obstacle.h"
using namespace std;
using namespace sf;

void collideLogic(ObstacleBlock& obstacle, Ball& ball) {
    if (obstacle.GetRect().getGlobalBounds().contains(ball.GetRectangle().getPosition())) {  // Top left withing obstacle
        Vector2f bottomLeft = Vector2f(ball.GetRectangle().getPosition().x, ball.GetRectangle().getPosition().y + ball.radius * 2);
        if (obstacle.GetRect().getGlobalBounds().contains(bottomLeft)) {
            ball.Collide("right");
        }
        else {
            ball.Collide("down");
        }
    }
    else {
        Vector2f topRight = Vector2f(ball.GetRectangle().getPosition().x + ball.radius * 2, ball.GetRectangle().getPosition().y);
        if (obstacle.GetRect().getGlobalBounds().contains(topRight)) {
            ball.Collide("left");
        }
        else {
            ball.Collide("up");
        }
    }
}

int main() {
    RenderWindow window(VideoMode(600, 600), "Ball cannon", Style::Close);
    Clock clock;

    window.setFramerateLimit(60);

    Cannon cannon;
    Holder holder;
    vector<Ball> balls;
    vector<ObstacleBlock> obstacles;

    bool settingObstacle = false;
    bool shooting = false;

    while (window.isOpen()) {
        Event evnt;
        while (window.pollEvent(evnt)) {  // Event handling
            switch (evnt.type) {
            case Event::Closed:
                window.close();
                break;

            case Event::MouseButtonPressed:
                if (evnt.mouseButton.button == Mouse::Left) {
                    holder.StartAnimating();
                    shooting = true;
                }
                else if (evnt.mouseButton.button == Mouse::Right) {
                    ObstacleBlock obstacle(static_cast<sf::Vector2f>(Mouse::getPosition(window)));
                    obstacle.StartDrawing();
                    obstacles.push_back(obstacle);
                    settingObstacle = true;
                }
                break;

            case Event::MouseButtonReleased:
                if (shooting) {
                    cannon.shot(balls, holder.GetPower());
                    holder.StopAnimating();
                    shooting = false;
                }
                else if (settingObstacle) {
                    obstacles[obstacles.size() - 1].StopDrawing();
                    settingObstacle = false;
                }
                break;
            }
        }

        // Time and window management
        clock.restart().asSeconds();

        window.clear();

        // Cannon logic
        Time time = clock.getElapsedTime();
        cannon.PointTo(static_cast<sf::Vector2f>(Mouse::getPosition(window)));
        RectangleShape cannonRect = cannon.GetRectangle();
        window.draw(cannonRect);

        // Ball logic
        for (int i = 0; i < balls.size(); i++) {
            CircleShape ballRect = balls[i].GetRectangle();
            window.draw(ballRect);

            Vector2f gravity(0, 1800.0f);
            balls[i].ApplyForce(gravity);
            balls[i].Move();

            // Collision logic
            for (int j = 0; j < obstacles.size(); j++) {
                bool collides = balls[i].GetRectangle().getGlobalBounds().intersects(obstacles[j].GetRect().getGlobalBounds());
                if (collides) {
                    collideLogic(obstacles[j], balls[i]);
                }
            }
        }

        // Holder logic
        holder.Animate();
        RectangleShape holderRect = holder.GetRect();
        window.draw(holderRect);

        // Obstacle logic
        for (int i = 0; i < obstacles.size(); i++) {
            RectangleShape obstacleRect = obstacles[i].GetRect();
            double width = -(obstacles[i].GetPosition().x - (double)Mouse::getPosition(window).x);
            double height = (obstacles[i].GetPosition().y - (double)Mouse::getPosition(window).y);
            obstacles[i].Operate(width, height);
            window.draw(obstacleRect);
        }

        // Drawing
        window.display();
    }

    return 0;
}
