#include <iostream>
#include <vector>

#include "graphics.h"
#include "Player.h"
#include "Obstacle.h"
#pragma comment(lib,"graphics.lib")
const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;
char lastKey;
bool collision;
bool isColliding(const Player& player, const Obstacle& obstacle) {
    // Проверяем, находятся ли ноги игрока между верхней и нижней границами препятствия
    int playerBottomY = player.getY() + player.getSize() / 2;
    return playerBottomY >= obstacle.getTopY() &&
        playerBottomY <= obstacle.getBottomY() &&
        player.getX() >= obstacle.getX1() &&
        player.getX() <= obstacle.getX2();
}


int main() {
    initwindow(WINDOW_WIDTH, WINDOW_HEIGHT);



    Player player(200, 100, 50);
    Obstacle obstacle(100, 200, 300, 200);

    while (true) {
        cleardevice(); // Очищаем экран

        // Обработка клавиш
        if (kbhit()) {
            lastKey = getch();
        }

        if (lastKey == 'a' || lastKey == 'A') {
            player.moveLeft();
        }
        if (lastKey == 'd' || lastKey == 'D') {
            player.moveRight();
        }

        player.checkCollisionWithObstacle(obstacle.getTopY(), obstacle.getX1(), obstacle.getX2());
        player.fall(WINDOW_HEIGHT); // Падение, если не находимся над землей
        player.draw(); // Рисуем игрока
        obstacle.draw(); // Рисуем препятствие

        delay(100); // Задержка для плавности анимации
    }

   

    return 0;
}
