#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <math.h>

float area_deltoid(float R, float a);
void print_definition();
void draw_deltoid(float R, float a);

int main() {
    setlocale(LC_ALL, "Russian");
    float R, a;
    int choice;

    printf("Введите радиус описанной окружности R: ");
    scanf("%f", &R);
    printf("Введите длину боковой стороны a: ");
    scanf("%f", &a);

    float b = sqrt((2 * R) * (2 * R) - a * a);

    if (b <= 0) {
        printf("Ошибка: сторона a не может быть больше или равна диаметру (2R).\n");
        return 1;
    }

    printf("\n--- МЕНЮ ДЕЛЬТОИДА ---\n");
    printf("1. Рассчитать площадь\n");
    printf("2. Вывести определение фигуры\n");
    printf("3. Нарисовать фигуру (контур)\n");
    printf("Выберите действие: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        printf("\nПлощадь дельтоида: %.2f\n", area_deltoid(R, a));
        break;
    case 2:
        print_definition();
        break;
    case 3:
        draw_deltoid(R, a);
        break;
    default:
        printf("Неверный пункт меню.\n");
    }

    return 0;
}

float area_deltoid(float R, float a) {
    float b = sqrt((2 * R) * (2 * R) - a * a);
    return a * b;
}

void print_definition() {
    printf("\nДельтоид — это четырехугольник, обладающий двумя парами сторон одинаковой длины.\n");
    printf("В данном случае он вписан в окружность радиуса R и состоит из двух прямоугольных треугольников.\n");
}

void draw_deltoid(float R, float a) {
    int scale = 3;
    int w = (int)(2 * R * scale);
    int h = (int)((2 * R) * scale * 0.7);
    int cx = w / 2;
    int cy = h / 2;
    int rad_x = (int)(R * scale);
    int rad_y = (int)(R * scale * 0.7);

    printf("\n");
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int dx = abs(x - cx);
            int dy = abs(y - cy);

            int in_ellipse = (dx * dx * rad_y * rad_y + dy * dy * rad_x * rad_x) <= (rad_x * rad_x * rad_y * rad_y);
            int in_rhombus = (dx * rad_y + dy * rad_x) <= (rad_x * rad_y);

            if (in_ellipse && !in_rhombus) {
                printf("*");
            }
            else if (!in_ellipse && in_rhombus) {
                printf("*");
            }
            else if (in_ellipse && in_rhombus) {
                if (dx == 0 || dy == 0 || (dx * rad_y == dy * rad_x)) {
                    printf("*");
                }
                else {
                    printf(" ");
                }
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}