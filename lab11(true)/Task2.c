#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

#define N 100

// функция вычисления
double my_function(double x) {
    return x * x - pow(cos(x + 1), 2);
}

int main() {
    setlocale(LC_CTYPE, "RUS");

    double arr[N];
    double start = 0.1;
    double end = 2.2;

    // шаг
    double h = (end - start) / (N - 1);

    double sum_pos = 0.0;
    double sum_neg = 0.0;
    int count_pos = 0;
    int count_neg = 0;
    double average_pos = 0.0;

    for (int i = 0; i < N; i++) {
        double x = start + i * h;
        arr[i] = my_function(x);

        if (arr[i] > 0) {
            sum_pos += arr[i];
            count_pos++;
        }
        else if (arr[i] < 0) {
            sum_neg += arr[i];
            count_neg++;
        }
    }

    // вычисление среднего значения положительных элементов
    if (count_pos > 0) {
        average_pos = sum_pos / count_pos;
    }

    // вывод результатов в виде строки
    printf("--- РЕЗУЛЬТАТЫ АНАЛИЗА МАССИВА ---\n");
    printf("Имя массива: arr\n");
    printf("Накопленное значение положительных: %.4f\n", sum_pos);
    printf("Накопленное значение отрицательных: %.4f\n", sum_neg);
    printf("Число положительных элементов: %d\n", count_pos);
    printf("Число отрицательных элементов: %d\n", count_neg);
    printf("Среднее значение положительных: %.4f\n", average_pos);

    return 0;
}
