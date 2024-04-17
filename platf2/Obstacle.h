#ifndef OBSTACLE_H
#define OBSTACLE_H

class Obstacle {
private:
    int startX, startY; // координаты начала препятствия
    int endX, endY; // координаты конца препятствия

public:
    Obstacle(int x1, int y1, int x2, int y2) : startX(x1), startY(y1), endX(x2), endY(y2) {}

    void draw() {
        line(startX, startY, endX, endY); // рисуем линию препятствия
    }
    int getTopY() const {

        return startY < endY ? startY : endY;
    }

    int getBottomY() const {
        return startY > endY ? startY : endY;
    }
    int getX1() const {
        return startX;
    }

    int getX2() const {
        return endX;
    }
};

#endif // OBSTACLE_H