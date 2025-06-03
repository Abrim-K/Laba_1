#include "Fun.h"
#include "Binar.h"

int main() {
	int task;
	system("chcp 1251");
	do {
		cout << "Menu\n1. Task 1\n2. Task 2\n3. Task 3\n4. Task 4\n5. Task 5\n6. Task 6\n7. Task 7\n8. Task 8\n9. Task 9\n10. Task 10\n0. Exit\nEnter Task: ";
		cin >> task;
		switch (task)
		{
		case 1:
		{
			double sum = 0;
			string input;
			int pos = 0, neg = 0;
			ifstream in("a.txt");
			if (in.is_open()) {
				while (getline(in, input, ' ')) {
					if (stod(input) > 0) {
						pos++;
					}
					else if (stod(input) < 0) {
						neg++;
					}
				}
			}
			in.close();
			cout << "positive: " << pos << endl;
			cout << "negative: " << neg << endl;
		}
		break;
		case 2:
		{
			double sum = 0;
			string input;
			ifstream in1("a1.txt");
			if (in1.is_open()) {
				while (getline(in1, input, ' ')) {
					if (stod(input) > 0) {
						sum += stod(input);
					}
				}
			}
			in1.close();
			ifstream in2("a2.txt");
			if (in2.is_open()) {
				while (getline(in2, input, ' ')) {
					if (stod(input) > 0) {
						sum += stod(input);
					}
				}
			}
			in2.close();
			cout << "summa: " << sum << endl;
		}
		break;
		case 3:
		{
			string input;
			ifstream inold_3("old_3.txt");
			ofstream innew_3("new_3.txt");
			if (inold_3.is_open()) {
				while (getline(inold_3, input)) {
					for (char& c : input) {
						c = toup(c);
					}
					innew_3 << input << endl;
				}
			}
			inold_3.close();
			innew_3.close();
		}
		break;
		case 4:
		{
			string input;
			ifstream inold_4("old_4.txt");
			ofstream innew_4_1("new_4-1.txt");
			ofstream innew_4_2("new_4-2.txt");
			if (inold_4.is_open()) {
				while (getline(inold_4, input, ' ')) {
					innew_4_1 << stod(input) << endl;
					getline(inold_4, input, ' ');
					innew_4_2 << stod(input) << endl;
				}
			}
			inold_4.close();
			innew_4_1.close();
			innew_4_2.close();
		}
		break;
		case 5:
		{
			vector <people> pip;
			people younger;
			ifstream inold_5("old_5.txt");
			if (inold_5.is_open()) {
				people person;
				inold_5 >> younger;
				pip.push_back(younger);
				while (inold_5 >> person) {
					if (younger.age() < person.age()) {
						younger = person;
					}
					pip.push_back(person);
				}
			}
			inold_5.close();
			ofstream innew_5("new_5.txt");
			if (innew_5.is_open()) {
				innew_5 << younger;
			}
			innew_5.close();
			cout << younger;
		}
		break;
		case 6:
		{
			string input;
			double itog = 1;
			ifstream inold_6("old_6.txt");
			ofstream outnew_6("new_6.txt");
			if (inold_6.is_open() and outnew_6.is_open()) {
				while (getline(inold_6, input, ' ')) {
					cout << input << endl;
					outnew_6 << stod(input) << endl;
					itog *= stod(input);
				}
			}
			inold_6.close();
			outnew_6.close();
			cout << "itog: " << itog << endl;
		}
		break;
		case 7:
		{
			int k, l, m, n;

			// Ввод параметров
			cout << "Введите количество матриц в первом файле (k): ";
			cin >> k;
			cout << "Введите количество матриц во втором файле (l): ";
			cin >> l;
			cout << "Введите размерность матриц (m n): ";
			cin >> m >> n;

			// Ввод матриц для первого файла
			vector<vector<vector<int>>> matrices1(k);
			cout << "\nВведите матрицы для первого файла:\n";
			for (int i = 0; i < k; ++i) {
				cout << "Матрица " << i + 1 << ":\n";
				inputMatrix(matrices1[i], m, n);
			}

			// Ввод матриц для второго файла
			vector<vector<vector<int>>> matrices2(l);
			cout << "\nВведите матрицы для второго файла:\n";
			for (int i = 0; i < l; ++i) {
				cout << "Матрица " << i + 1 << ":\n";
				inputMatrix(matrices2[i], m, n);
			}

			// Запись в файлы
			writeMatricesToFile("old_7.txt", matrices1);
			writeMatricesToFile("new_7.txt", matrices2);

			// Чтение файлов
			readMatricesFromFile("old_7.txt", matrices1);
			readMatricesFromFile("new_7.txt", matrices2);

			// Перенос матриц с a00 == 0 из первого файла во второй
			for (size_t i = 0; i < matrices1.size(); ) {
				if (matrices1[i][0][0] == 0) {
					matrices2.push_back(matrices1[i]);
					matrices1.erase(matrices1.begin() + i);
				}
				else {
					++i;
				}
			}

			// Перезапись файлов
			writeMatricesToFile("old_7.txt", matrices1);
			writeMatricesToFile("new_7.txt", matrices2);

			// Вывод содержимого файлов
			cout << "\nСодержимое первого файла:\n";
			printMatrices(matrices1);

			cout << "\nСодержимое второго файла:\n";
			printMatrices(matrices2);
		}
		break;
		case 8:
		{
			setlocale(LC_ALL, "RU");
			const char* filename = "new_8.dat";
			vector<Student> students;
			int count;

			cout << "Введите количество студентов: ";
			cin >> count;

			for (int i = 0; i < count; i++) {
				Student s;
				inputStudent(s);
				students.push_back(s);
			}

			// Сохраняем в бинарный файл
			saveToBinaryFile(filename, students);

			// Выводим студентов с положительными оценками
			printGoodStudents(filename);
		}
		break;
		case 9:
		{
			const string filename = "old_9.dat";
			vector<int> numbers;
			int count, num;

			// Ввод чисел
			cout << "Введите количество чисел: ";
			cin >> count;

			cout << "Введите " << count << " целых чисел (через Enter):\n";
			for (int i = 0; i < count; ++i) {
				cin >> num;
				numbers.push_back(num);
			}

			// Запись в бинарный файл
			ofstream out(filename, ios::binary);
			if (!out) {
				cerr << "Ошибка создания файла!" << endl;
				return 1;
			}

			for (int n : numbers) {
				out.write(reinterpret_cast<const char*>(&n), sizeof(n));
			}
			out.close();

			// Вывод исходных чисел
			printNumbers(filename, "Исходные числа в файле");

			// Удвоение чисел в файле
			fstream file(filename, ios::binary | ios::in | ios::out);
			if (!file) {
				cerr << "Ошибка открытия файла для изменения!" << endl;
				return 1;
			}

			int current;
			streampos pos;
			while (file.read(reinterpret_cast<char*>(&current), sizeof(current))) {
				pos = file.tellg(); // Запоминаем текущую позицию
				current *= 2;
				file.seekp(pos - static_cast<streamoff>(sizeof(current))); // Возвращаемся назад
				file.write(reinterpret_cast<const char*>(&current), sizeof(current));
				file.seekg(pos); // Перемещаем указатель чтения вперед
			}
			file.close();

			// Вывод измененных чисел
			printNumbers(filename, "Числа после удвоения");
		}
		break;
		case 10:
		{
			const char* filename = "old_10.dat";
			vector<Student> students;
			int count;
			cout << "Введите количество студентов: ";
			cin >> count;
			for (int i = 0; i < count; ++i) {
				Student s;
				inputStudent(s);
				students.push_back(s);
			}
			saveToBinaryFile(filename, students);
			cout << "\nДанные до изменения:\n";
			printAllStudents(filename);
			increaseScholarship(filename);
			cout << "\nДанные после изменения (стипендия увеличена на 30% для студентов без двоек):\n";
			printAllStudents(filename);
		}
		break;
		case 0: { cout << "Exit completed successfully" << endl; }
			  break;
		default: { cout << "Uncorrect input" << endl; }
			   break;
		}
	} while (task != 0);
	return 0;
}