#define _USE_MATH_DEFINES
#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
    setlocale(LC_ALL, "Russian");

    double sin_n(double x, int N);
    double sin_eps(double x, double eps);

        double x;
        int N;
        double eps;

        printf("Введите значение x (в радианах): ");
        scanf("%lf", &x);
        printf("Введите количество членов ряда (N): ");
        scanf("%d", &N);
        printf("Введите точность (eps): ");
        scanf("%lf", &eps);

        double sin_std = sin(x);
        printf("\n1. Стандартная функция sin(x): %lf\n", sin_std);

        double res_n = sin_n(x, N);
        printf("2. Функция sin_n(x, N):        %lf\n", res_n);
        printf("   Отклонение от стандарта:    %lf\n", fabs(sin_std - res_n));

        double res_eps = sin_eps(x, eps);
        printf("3. Функция sin_eps(x, eps):    %lf\n", res_eps);
        printf("   Отклонение от стандарта:    %lf\n", fabs(sin_std - res_eps));

        return 0;
    }

    double sin_n(double x, int N) {
        double sum = 0.0;
        double term = x;
        int sign = 1;

        for (int k = 1; k <= N; k++) {
            sum += sign * term;
            sign = -sign;
            term = term * x * x / ((2.0 * k) * (2.0 * k + 1.0));
        }
        return sum;
    }

    double sin_eps(double x, double eps) {
        double sum = 0.0;
        double term = x;
        int k = 1;
        int sign = 1;

        while (fabs(term) >= eps) {
            sum += sign * term;
            sign = -sign;
            term = term * x * x / ((2.0 * k) * (2.0 * k + 1.0));
            k++;
        }
        return sum;
}