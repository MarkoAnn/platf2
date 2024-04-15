#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "graphics.h"
#include "Obstacle.h"


#pragma comment(lib,"graphics.lib")

class Player {
private:
    int x, y; // координаты игрока
    int size; // размер игрока
    int speed = 5;
   
public:
    Player(int startX, int startY, int playerSize) : x(startX), y(startY), size(playerSize) {}
    void draw() {
        // Голова (круг)
        circle(x, y - size /8, size / 6);

        // Тело (прямоугольник)
        rectangle(x - size / 10, y, x + size / 10, y + size / 3);

        // Левая рука (линия)
        line(x - size / 10, y + size / 6, x - size / 5, y + size / 4);

        // Правая рука (линия)
        line(x + size / 10, y + size / 6, x + size / 5, y + size / 4);

        // Левая нога (линия)
        line(x - size / 20, y + size / 3, x - size / 10, y + size / 2);

        // Правая нога (линия)
        line(x + size / 20, y + size / 3, x + size / 10, y + size / 2);
    }
    void fall(int groundY) {
        if (y + size < groundY) {
            y += speed; // Продолжаем падение, если игрок находится выше земли
        }
    }

    void checkCollisionWithObstacle(int obstacleTopY, int obstacleLeftX, int obstacleRightX) {
        if (y + size >= obstacleTopY && y < obstacleTopY && x > obstacleLeftX && x < obstacleRightX) {
            y = obstacleTopY - size; // Устанавливаем позицию игрока на вершине препятствия
        }
    }

  
    void moveLeft() {
        x -= speed;
    }

    void moveRight() {
        x += speed;
    }


    int getY() const {
        return y;
    }
    int getX() const {
        return x;
    }
    int getSize() const {
        return size;
    }

};

#endif // PLAYER_H
