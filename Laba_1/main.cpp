#include <vector>
#include "Fun.h"

int main() {
	int task;
	do {
		cout << "Menu\n1. Task 1\n2. Task 2\n3. Task 3\n4. Task 4\n5. Task 5\n0. Exit\nEnter Task: ";
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
		case 0: { cout << "Exit completed successfully" << endl; }
			  break;
		default: { cout << "Uncorrect input" << endl; }
			   break;
		}
	} while (task != 0);
	
	return 0;
}