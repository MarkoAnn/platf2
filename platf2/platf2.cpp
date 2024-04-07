#include <iostream>
#include <vector>

#include "graphics.h"
#include "Player.h"
#include "Obstacle.h"
#pragma comment(lib,"graphics.lib")
const int WINDOW_WIDTH = 500;
const int WINDOW_HEIGHT = 500;


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

    while (!isColliding(player, obstacle)) {
        cleardevice(); // Очищаем экран

        player.fall(obstacle.getTopY()); // Падаем, если не находимся над препятствием
        player.draw(); // Рисуем игрока
        obstacle.draw(); // Рисуем препятствие

        delay(100); // Задержка для плавности анимации
    }

    delay(5000); // Ждем 5 секунд перед закрытием окна
    closegraph();

    return 0;
}