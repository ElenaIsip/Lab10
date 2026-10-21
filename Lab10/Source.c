#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "Russian");

    double F1(double x);
    double F2(double x);

        double x;
        int choice;

        printf("Введите значение x: "); 
        scanf("%lf", &x);

        printf("\n--- МЕНЮ ---\n");
        printf("1. Вычислить F1(x)\n");
        printf("2. Вычислить F2(x)\n");
        printf("3. Вычислить произведение F1(x) * F2(x)\n");
        printf("4. Вычислить разность квадратов F1(x)^2 - F2(x)^2\n");
        printf("5. Вычислить удвоенную сумму 2 * (F1(x) + F2(x))\n");
        printf("6. Вывести значения обеих функций\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        double val1 = F1(x);
        double val2 = F2(x);

        switch (choice) {
        case 1:
            printf("F1(x) = %lf\n", val1);
            break;
        case 2:
            printf("F2(x) = %lf\n", val2);
            break;
        case 3:
            printf("Произведение: %lf\n", val1 * val2);
            break;
        case 4:
            printf("Разность квадратов: %lf\n", pow(val1, 2) - pow(val2, 2));
            break;
        case 5:
            printf("Удвоенная сумма: %lf\n", 2 * (val1 + val2));
            break;
        case 6:
            printf("F1(x) = %lf, F2(x) = %lf\n", val1, val2);
            break;
        default:
            printf("Неверный пункт меню.\n");
        }

        return 0;
    }

    double F1(double x) {
        double y;
        if (x <= 3) {
            y = pow(x, 2) - 3 * x + 9;
        }
        else {
            y = 1.0 / (pow(x, 3) + 3);
        }
        return y;
    }

    double F2(double x) {
        double y;
        y = x * exp(sin(pow(x, 2)));
        return y;
    }
