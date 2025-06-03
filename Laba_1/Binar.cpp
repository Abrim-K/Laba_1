#include "Binar.h"


void inputStudent(Student& s) {
    cout << "\nВведите данные о студенте:\n";

    cout << "Фамилия и инициалы: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(s.name, 50);

    cout << "Номер группы: ";
    cin.getline(s.group, 20);

    cout << "Оценки по 3 предметам (через пробел): ";
    for (int i = 0; i < 3; ++i) {
        cin >> s.marks[i];
    }

    cout << "Размер стипендии: ";
    cin >> s.scholarship;
}

void saveToBinaryFile(const char* filename, const vector<Student>& students) {
    ofstream out(filename, ios::binary);
    if (!out) {
        cerr << "Ошибка создания файла!" << endl;
        return;
    }

    for (const auto& s : students) {
        out.write(reinterpret_cast<const char*>(&s), sizeof(Student));
    }
    out.close();
}

void printGoodStudents(const char* filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    cout << "\nСтуденты с положительными оценками по всем предметам:\n";
    cout << "----------------------------------------------------\n";

    Student s;
    while (in.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        bool allPositive = true;
        for (int mark : s.marks) {
            if (mark < 60) {
                allPositive = false;
                break;
            }
        }

        if (allPositive) {
            cout << "ФИО: " << s.name << endl;
            cout << "Группа: " << s.group << endl;
            cout << "Оценки: " << s.marks[0] << ", " << s.marks[1] << ", " << s.marks[2] << endl;
            cout << "Стипендия: " << s.scholarship << " руб." << endl;
            cout << "----------------------------------------------------\n";
        }
    }
    in.close();
}


void printNumbers(const string& filename, const string& message) {
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return;
    }

    cout << message << ": ";
    int num;
    while (in.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        cout << num << " ";
    }
    cout << endl;
    in.close();
}


void printAllStudents(const char* filename) {
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    cout << "\nВсе студенты:\n";
    cout << "----------------------------------------------------\n";

    Student s;
    while (in.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        cout << "ФИО: " << s.name << endl;
        cout << "Группа: " << s.group << endl;
        cout << "Оценки: " << s.marks[0] << ", " << s.marks[1] << ", " << s.marks[2] << endl;
        cout << "Стипендия: " << s.scholarship << " руб." << endl;
        cout << "----------------------------------------------------\n";
    }
    in.close();
}


void increaseScholarship(const char* filename) {
    // Читаем всех студентов из файла
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "Ошибка открытия файла для чтения!" << endl;
        return;
    }

    vector<Student> students;
    Student s;
    while (in.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        students.push_back(s);
    }
    in.close();

    // Проверяем оценки и увеличиваем стипендию
    for (auto& student : students) {
        bool hasBadMarks = false;
        for (int mark : student.marks) {
            if (mark < 40) { // Если есть оценка ниже 40 (двойка)
                hasBadMarks = true;
                break;
            }
        }

        if (!hasBadMarks) {
            student.scholarship *= 1.3; // Увеличиваем стипендию на 30%
        }
    }

    // Перезаписываем файл с обновленными данными
    ofstream out(filename, ios::binary);
    if (!out) {
        cerr << "Ошибка открытия файла для записи!" << endl;
        return;
    }

    for (const auto& student : students) {
        out.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }
    out.close();
}