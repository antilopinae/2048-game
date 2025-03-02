#include "box.hpp"

Box::Box(int x_, int y_, int boardScale_, int boxSize_, int number_)
{
    boardScale = boardScale_;
    xGrid = x_;
    yGrid = y_;
    xGridNext = x_;
    yGridNext = y_;
    x = boardScale * x_;
    y = boardScale * y_;
    xNext = boardScale * x_;
    yNext = boardScale * y_;
    isMoving = false;
    deleteAfterMerge = false;
    height = boxSize_;
    width = boxSize_;
    number = number_;
    numberNext = number_;
    isValid = true;
}

void Box::setLocation(int newX, int newY)
{
    xGridNext = newX;
    yGridNext = newY;
    xNext = boardScale * newX;
    yNext = boardScale * newY;
}

void Box::merge()
{
    numberNext = number * 2;
    number = numberNext;
}

void Box::update()
{
    if (xGridNext != xGrid)
    {
        isMoving = true;

        if (xGrid < xGridNext)
        {
            x += 32.0;

            if (x >= xNext)
            {
                isMoving = false;
                x = xNext;
                xGrid = xGridNext;

                if (numberNext != number) {
                    number = numberNext;
                }
            }
        }
        else if (xGrid > xGridNext)
        {
            x -= 32.0;

            if (x <= xNext) {
                isMoving = false;
                x = xNext;
                xGrid = xGridNext;

                if (numberNext != number) {
                    number = numberNext;
                }
            }
        }
    }

    if (yGridNext != yGrid) {
        isMoving = true;

        if (yGrid < yGridNext) {
            y += 32.0;

            if (y >= yNext) {
                isMoving = false;
                y = yNext;
                yGrid = yGridNext;

                if (numberNext != number) {
                    number = numberNext;
                }
            }
        }
        else if (yGrid > yGridNext)
        {
            y -= 32.0;

            if (y <= yNext) {
                isMoving = false;
                y = yNext;
                yGrid = yGridNext;

                if (numberNext != number) {
                    number = numberNext;
                }
            }
        }
    }
}