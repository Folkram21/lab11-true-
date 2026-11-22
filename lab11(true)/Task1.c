#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

#define N 10

int main() {
    setlocale(LC_CTYPE, "RUS");

    float A[N];    
    float original_A[N];
    float temp;
    float sum = 0;

    // заполнение массива с консоли
    printf("Введите %d вещественных чисел:\n", N);
    for (int i = 0; i < N; i++) {
        printf("a[%d] = ", i + 1);
        scanf("%f", &temp);
        A[i] = temp;
        original_A[i] = temp;
    }

    // уменьшить в 10 раз значение каждого элемента массива
    for (int i = 0; i < N; i++) {
        A[i] = A[i] / 10.0f;
    }

    // вывод результатов в виде таблицы
    printf("\n--------------------------------------------------\n");
    printf("| %-7s | %-17s | %-15s |\n", "Индекс", "Исходное значение", "Новое значение");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < N; i++) {
        printf("| %-7d | %-17.2f | %-15.4f |\n", i + 1, original_A[i], A[i]);
        sum += A[i];
    }
    printf("--------------------------------------------------\n");

    // вычисление среднего арифметического
    float average = sum / N;
    printf("\nСреднее арифметическое элементов: %.4f\n", average);

    return 0;
}
