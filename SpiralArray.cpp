/*
 * Задача "Массив по спирали"
 * --------------------------
 * Заполнение двумерного квадратного массива
 * значениями из одномерного массива, по спирали
 */

#include <iostream>
using std::cout;
using std::endl;

const short N = 5;		// Глобальная константа - размер массива

// Вывод на экран 1-мерного массива
void show_1d_array(int m[])
{
	cout << "1-d array:" << endl;
	for (int i = 0; i < N*N; i++)
		cout << m[i] << ", ";
	cout << endl;
}

// Вывод на экран 2-мерного массива
void show_2d_array(int m[N][N])
{
	int i, j;
	cout << "2-d array:" << endl;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			cout << m[i][j] << '\t';
		cout << endl;
	}
	cout << endl;
}

// Заполнение 1-мерного массива арифм. прогрессией
// Функция принимает адрес массива, начальный
// член прогрессии и шаг прогрессии
void fill_1d_array(int m[], int start, int step)
{
	int val = start;
	for (int i = 0; i < N*N; i++) {
		m[i] = val;
		val += step;
	}
}

// Функция установки направления
// движения по спирали
void set_direction(short dir, short m[])
{
	switch (dir)
	{
	case 1:
		m[0] = 0;  m[1] = 1;
		break;
	case 2:
		m[0] = 1;  m[1] = 0;
		break;
	case 3:
		m[0] = 0;  m[1] = -1;
		break;
	case 4:
		m[0] = -1; m[1] = 0;
		break;
	}
}


// Заполнение 2-мерного массива по спирали
// значениями членов 1-мерного массива
void fill_2d_array(int m1d[], int m2d[N][N])
{
	int i;
	int r = 0, c = 0;					// Текущее положение строки и колонки в 2d массиве
	short direction = 1;				// Направление заполнения 2d массива (1: вправо, 2: вниз, 3: влево, 4: вверх)
	short step[2] = { 0, 1 };			// step[0] - шаг смещения строки; step[1] - шаг смещения колонки
	// Общий цикл - проходит по всему 1-мерному массиву
	for (i = 0; i < N * N; i++) {
		// устанавливаем значение очередной ячейки
		m2d[r][c] = m1d[i];
		// если упёрлись в край или уже заполненную ячейку, то меняем направление
		if ( (m2d[r + step[0]][c + step[1]] != 0) || (r + step[0] == N) || (c + step[1] == N) || (c + step[1] < 0) ) {
			direction = (direction == 4) ? 1 : direction + 1;
			set_direction(direction, step);
		}
		// продвигаемся по спирали, добавляя шаг к строке и колонке
		r += step[0];
		c += step[1];
	}
}


// Старт
int main()
{
	int mas1d[N*N];
	int mas2d[N][N] = {};
	// Заполнение массивов
	fill_1d_array(mas1d, 1, 1);
	fill_2d_array(mas1d, mas2d);
	// Вывод результатов
	show_1d_array(mas1d);
	cout << endl;
	show_2d_array(mas2d);
}
