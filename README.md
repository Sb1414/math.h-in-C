# math

> Реализация собственной версии математической библиотеки math.h.

## Оглавление

1. [Реализация функций "math.h"](#функции-библиотеки-mathh)  
2. [Условия функций библиотеки math.h](#условия-функций-библиотеки-mathh)

## Функции библиотеки "math.h":

| No. | Function | Description |
| --- | -------- | ----------- |
| 1 | `int abs(int x)` | вычисляет абсолютное значение целого числа |
| 2 | `long double acos(double x)` | вычисляет арккосинус |
| 3 | `long double asin(double x)` | вычисляет арксинус |
| 4 | `long double atan(double x)` | вычисляет арктангенс |
| 5 | `long double ceil(double x)` | возвращает ближайшее целое число, не меньшее заданного значения |
| 6 | `long double cos(double x)` | вычисляет косинус |
| 7 | `long double exp(double x)` | возвращает значение e, возведенное в заданную степень |
| 8 | `long double fabs(double x)` | вычисляет абсолютное значение числа с плавающей точкой |
| 9 | `long double floor(double x)` | возвращает ближайшее целое число, не превышающее заданное значение |
| 10 | `long double fmod(double x, double y)` | остаток операции деления с плавающей точкой |
| 11 | `long double log(double x)` | вычисляет натуральный логарифм |
| 12 | `long double pow(double base, double exp)` | возводит число в заданную степень |
| 13 | `long double sin(double x)` | вычисляет синус |
| 14 | `long double sqrt(double x)` | вычисляет квадратный корень |
| 15 | `long double tan(double x)` | вычисляет тангенс |  

## Условия функций библиотеки math.h

- Библиотека разработана на языке Си стандарта C11 с использованием компиятора gcc 
- Код библиотеки находится в папке src
- Библиотека разработана в соответствии с принципами структурного программирования, исключено дублирование кода
- Подготовлено полное покрытие unit-тестами функций библиотеки c помощью библиотеки Check
- Unit-тесты проверяют результаты выполненной работы путём сравнения ее с реализацией стандартной библиотеки math.h
- Unit-тесты покрывают не менее 80% каждой функции
- В цели gcov_report формируется отчёт gcov в виде html страницы.
- Предусмотрен Makefile для сборки библиотеки и тестов
- Соблюдена логика работы стандартной библиотеки
- Общая проверяемая точность - 16 значащих цифр
- Проверяемая точность дробной части - максимум 6 знаков после запятой.

