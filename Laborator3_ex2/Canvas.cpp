#include "Canvas.h"
#include <iostream>
#include <cmath>

using namespace std;

// Constructor: Initialize matrix
Canvas::Canvas(int width, int height) : width(width), height(height) {
    matrix = new char* [height];
    for (int i = 0; i < height; i++) {
        matrix[i] = new char[width];
        for (int j = 0; j < width; j++) {
            matrix[i][j] = ' '; // Initialize with spaces
        }
    }
}

// Destructor: Free allocated memory
Canvas::~Canvas() {
    for (int i = 0; i < height; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

// Set a single point on the canvas
void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        matrix[y][x] = ch;
    }
}

// Bresenham's Line Algorithm
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
    int err = dx + dy, e2;

    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    for (int i = y - ray; i <= y + ray; i++) {
        for (int j = x - ray; j <= x + ray; j++) {
            int equation = (i - y) * (i - y) + (j - x) * (j - x);
            if (equation >= ray * (ray - 1) && equation <= ray * (ray + 1)) {
                SetPoint(j, i, ch); // (j, i) because x is horizontal, y is vertical
            }
        }
    }
}
 
void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = y - ray; i <= y + ray; i++) {
        for (int j = x - ray; j <= x + ray; j++) {
            if ((i - y) * (i - y) + (j - x) * (j - x) <= ray * ray) {
                SetPoint(j, i, ch);
            }
        }
    }
}
// Draw a rectangle outline
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int x = left; x <= right; x++) {
        SetPoint(x, top, ch);
        SetPoint(x, bottom, ch);
    }
    for (int y = top; y <= bottom; y++) {
        SetPoint(left, y, ch);
        SetPoint(right, y, ch);
    }
}

// Fill a rectangle
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int y = top; y <= bottom; y++) {
        for (int x = left; x <= right; x++) {
            SetPoint(x, y, ch);
        }
    }
}

// Clear the canvas by filling it with spaces
void Canvas::Clear() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = ' ';
        }
    }
}

// Print the canvas to the console
void Canvas::Print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}
