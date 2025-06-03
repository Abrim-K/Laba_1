#include "Binar.h"


void inputStudent(Student& s) {
    cout << "\n������� ������ � ��������:\n";

    cout << "������� � ��������: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(s.name, 50);

    cout << "����� ������: ";
    cin.getline(s.group, 20);

    cout << "������ �� 3 ��������� (����� ������): ";
    for (int i = 0; i < 3; ++i) {
        cin >> s.marks[i];
    }

    cout << "������ ���������: ";
    cin >> s.scholarship;
}

void saveToBinaryFile(const char* filename, const vector<Student>& students) {
    ofstream out(filename, ios::binary);
    if (!out) {
        cerr << "������ �������� �����!" << endl;
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
        cerr << "������ �������� �����!" << endl;
        return;
    }

    cout << "\n�������� � �������������� �������� �� ���� ���������:\n";
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
            cout << "���: " << s.name << endl;
            cout << "������: " << s.group << endl;
            cout << "������: " << s.marks[0] << ", " << s.marks[1] << ", " << s.marks[2] << endl;
            cout << "���������: " << s.scholarship << " ���." << endl;
            cout << "----------------------------------------------------\n";
        }
    }
    in.close();
}


void printNumbers(const string& filename, const string& message) {
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "������ �������� ����� ��� ������!" << endl;
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
        cerr << "������ �������� �����!" << endl;
        return;
    }

    cout << "\n��� ��������:\n";
    cout << "----------------------------------------------------\n";

    Student s;
    while (in.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        cout << "���: " << s.name << endl;
        cout << "������: " << s.group << endl;
        cout << "������: " << s.marks[0] << ", " << s.marks[1] << ", " << s.marks[2] << endl;
        cout << "���������: " << s.scholarship << " ���." << endl;
        cout << "----------------------------------------------------\n";
    }
    in.close();
}


void increaseScholarship(const char* filename) {
    // ������ ���� ��������� �� �����
    ifstream in(filename, ios::binary);
    if (!in) {
        cerr << "������ �������� ����� ��� ������!" << endl;
        return;
    }

    vector<Student> students;
    Student s;
    while (in.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        students.push_back(s);
    }
    in.close();

    // ��������� ������ � ����������� ���������
    for (auto& student : students) {
        bool hasBadMarks = false;
        for (int mark : student.marks) {
            if (mark < 40) { // ���� ���� ������ ���� 40 (������)
                hasBadMarks = true;
                break;
            }
        }

        if (!hasBadMarks) {
            student.scholarship *= 1.3; // ����������� ��������� �� 30%
        }
    }

    // �������������� ���� � ������������ �������
    ofstream out(filename, ios::binary);
    if (!out) {
        cerr << "������ �������� ����� ��� ������!" << endl;
        return;
    }

    for (const auto& student : students) {
        out.write(reinterpret_cast<const char*>(&student), sizeof(Student));
    }
    out.close();
}