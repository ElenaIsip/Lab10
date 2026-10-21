# Домашняя работа
# Индивидуальный вариант 22
# Описание программы
Задание 3  (индивидуальное). Составьте программу, которая для заданной пользователем фигуры, например прямоугольника (треугольника или другой фигуры см. инидивидуальное задание работы 9) предлагает меню выбора одной из операций:
1) рассчитать площадь;
2) вывести определение фигуры;
3) нарисовать фигуру.
Для каждой из операций и фигур реализуйте одну собственную функцию вычисления площади с необходимым числом параметров, например :

float area_round( float a); // для круга

float area_rectangle( float a, float b); // для прямоугольника

float area_triangle( float a, float b, float c); // для треугольника

 и рисования  фигуры символом '*' (размеры сторон фигуры пользователь задает в main):

void draw_rectangle( int a, int b);

или рисования  фигуры (вид символа пользователь задает в main):

void draw_round( char a);

Для вывода параметров фигуры:

int get_radius(); // возвращает радиус круга

Для сравнения двух фигур по площади

int compare_round (int a, int b)// возвращает разницу между двумя кругами с радиусами a и b

# Алгоритм и блок-схема
Программа рисует контур дельтоида в консоли по сетке символов. Ввод: R (целое, R>0), a (0<a<R), символ для рисования — с проверкой через scanf и очисткой буфера getchar() перед вводом символа. Двойной цикл по y и x от -R-2 до R+2; для каждой точки считается real_y = y/2.2 (компенсация вытянутости символов). Точка на окружности, если |sqrt(x²+real_y²) - R| < 0.5. Контур дельтоида: вершины (R,0), (-R,0), (tx,±ty), где tx=R-a, ty=sqrt(R²-a²); для x в [tx,R] проверяется отклонение от прямой line_y=k(x-R), для x в [-R,tx] — от line_y=k2(x+R), допуск 0.6. Вывод: контур — заданный символ, окружность — точка, иначе пробел; после каждой строки '\n'.

# Блок-схема

<img width="522" height="345" alt="{DE2660DA-1010-480B-9066-D6749061EB9D}" src="https://github.com/user-attachments/assets/e39cb3e3-1610-4dc2-ad36-4afeafbad14f" />



# Реализация программы

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
   
# Информация о разработчике
Попова Елена, БТИИ 262
