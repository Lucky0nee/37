#include <iostream>
#include <vector>
#include <time.h>
#include <random>

using namespace std;

vector<int> solution(vector<int>& A, int K, int n) {
	if (static_cast<double>(K) / n == 2) // Useless
		return A;

	for (int j = 0; j < K; j++) {
		vector<int> temp = A;

		for (int i = 1; i < n + 1; i++)
			A[i] = temp[i - 1];

		swap(A[n], A[0]);
	}
	return A;
}
int main() {
	//system("chcp 1251>nul");
	srand(time(NULL));
x:
	cout << "\nВведiть розмiр масива: "; int n; cin >> n;
	if (n < 0 || n > 100) { cout << "Введiть число ( Вiд 0 до 100 ): ";  goto x; } // цілі числа в межах [0..100]
	vector<int> tempVec(n);
y:
	cout << "\nВведiть K: "; int K; cin >> K;
	if (K < 0 || K > 100) { cout << "Введiть число ( Вiд 0 до 100 ): ";  goto y; } // цілі числа в межах [0..100]

	cout << "Масив: \t\t   ";
	for (int i = 0; i < n; i++)
		tempVec[i] = rand() % 2000 - 1000; //Кожен елемент вектора A є цілим числом в межах[-1000..1000]

	for (int i = 0; i < n; i++)
		cout << tempVec[i] << " ";

	vector<int> vec(n);
	vec = solution(tempVec, K, n);

	cout << "\nМасив пiсля зсуву: ";
	for (int i = 0; i < n; i++)
		cout << vec[i] << " ";

	return 0;
}

/*
Дано вектор A, що складається з N цілих чисел. Зсув означає, що кожен
елемент зміщується вправо на один індекс, а останній елемент
переміщується на перше місце.
Наприклад, зсув вектора A = 
[3, 8, 9, 0, 7, 6, 8, 9] на 1 дорівнює
[9, 3, 8, 9, 0, 7, 6, 8]
(елементи зміщуються вправо на один
індекс, а останній переміщується на перше місце).

Завдання: написати функцію:
vector<int> solution(vector<int> &A, int K);

що K разів зсуватиме вектор A (тобто кожен елемент A буде зміщений вправо
K разів) і повертатиме значення зсунутого вектора. 
Тобто функція має приймати як параметр адресу вектора і розмір зміщення, а повертати
оновлений вектор зі зсувом за допомогою return.

Вважаємо, що:
N і K — цілі числа в межах [0..100];
кожен елемент вектора A є цілим числом в межах [-1000..1000].
*/
