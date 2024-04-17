#ifndef PLAYER_H
#define PLAYER_H

#include "Obstacle.h"
class Obstacle;


   
 

    class Player {
    private:
      

    public:
        int x, y;
        int size;
        int speed = 5;
        int verticalSpeed = 0;
        const int gravity = 1;
        bool onObstacle = false;

        Player(int startX, int startY, int playerSize)
            : x(startX), y(startY), size(playerSize) {}

        void draw() {
            // Голова (круг)
            circle(x, y - size / 8, size / 6);

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

        void move(int deltaX) {
            x += deltaX;
        }

      
        void update(const Obstacle& obstacle, int groundY) {
            int playerBottomY = y + size;
            int playerFootX1 = x - size / 4;
            int playerFootX2 = x + size / 4;
            int playerFootY = y + size;
            int playerBorderX1 = x - size / 2;
            int playerBorderX2 = x + size / 2;
            int playerBorderY1 = y;
            int playerBorderY2 = y + size;

            bool isOnFoot = (playerFootX2 >= obstacle.getX1() && playerFootX1 <= obstacle.getX2() &&
                playerFootY >= obstacle.getTopY() && playerFootY <= obstacle.getBottomY());

            bool isOnBorder = (playerBorderX2 >= obstacle.getX1() && playerBorderX1 <= obstacle.getX2() &&
                playerBorderY1 <= obstacle.getBottomY() && playerBorderY2 >= obstacle.getTopY());

            if (isOnFoot || isOnBorder) {
                y = obstacle.getTopY() - size;
                onObstacle = true;
            }
            else {
                onObstacle = false;
                verticalSpeed += gravity;
            }

           
            y += verticalSpeed;

          
            if (y + size > groundY) {
                y = groundY - size;
                verticalSpeed = 0;
                onObstacle = false;
            }
        }

        void jump() {
            if (onObstacle) {
                verticalSpeed = -15; 
                onObstacle = false;  
            }
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