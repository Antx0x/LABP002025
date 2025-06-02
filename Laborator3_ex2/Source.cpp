#include "Canvas.h"
#include <iostream>

int main() {
    // Create a canvas of size 40x20
    Canvas canvas(40, 20);

    // Draw and fill shapes
    //canvas.DrawCircle(10, 10, 5, 'O');
    canvas.FillCircle(30, 10, 5, 'o');
    //canvas.DrawRect(5, 5, 15, 15, '#');
    //canvas.FillRect(20, 5, 30, 15, '@');
    //canvas.DrawLine(0, 0, 39, 19, '*');

    // Display the canvas
    canvas.Print();

    return 0;
}
