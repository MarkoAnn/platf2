#include <iostream>
#include <vector>

#include "graphics.h"
#include "Player.h"
#include "Obstacle.h"
#include "graphics.h"

const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
char lastKey;

bool isColliding(const Player& player, const Obstacle& obstacle) {
    int playerBottomY = player.getY() + player.getSize();
    int playerTopY = player.getY();
    int playerRightX = player.getX() + player.getSize() / 2;
    int playerLeftX = player.getX() - player.getSize() / 2;

    int obstacleTopY = obstacle.getTopY();
    int obstacleBottomY = obstacle.getBottomY();
    int obstacleLeftX = obstacle.getX1();
    int obstacleRightX = obstacle.getX2();

    return playerBottomY >= obstacleTopY &&
        playerTopY <= obstacleBottomY &&
        playerRightX >= obstacleLeftX &&
        playerLeftX <= obstacleRightX;
}

int main() {
    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT);

    Obstacle obstacle(100, 200, 300, 200);
    Player player(200, 100, 50);

    while (true) {
        cleardevice(); // Очищаем экран

        if (kbhit()) {
            lastKey = getch();
            if (lastKey == 'a' || lastKey == 'A') {
                player.move(-player.speed);
            }
            else if (lastKey == 'd' || lastKey == 'D') {
                player.move(player.speed);
            }
            else if (lastKey == 'w' || lastKey == 'W') {
                player.jump();  // Пробел для прыжка
            }
        }
        // Обновляем состояние игрока и проверяем столкновение
        player.update(obstacle, WINDOW_HEIGHT);

        player.draw(); // Рисуем игрока
        obstacle.draw(); // Рисуем препятствие

        delay(100); // Задержка для плавности анимации
    }

    return 0;
}