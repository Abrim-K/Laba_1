#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

char toup(char c);


void inputMatrix(vector<vector<int>>& matrix, int m, int n);


void writeMatricesToFile(const string& filename, const vector<vector<vector<int>>>& matrices);


void readMatricesFromFile(const string& filename, vector<vector<vector<int>>>& matrices);


void printMatrices(const vector<vector<vector<int>>>& matrices);


struct birthday {
	string year;
	string month;
	string day;
	string age() {
		return year + month + day;
	}
};


struct adress {
	string index;
	string country;
	string oblast;
	string raion;
	string city;
	string streat;
	string home;
	string kvartira;
};


class people : public birthday, public adress
{
public:
	string second_name;
	string first_name;
	string third_name;
	string pol;
	string national;
	string tall;
	string weight;
	string number;
};


ostream& operator << (ostream& out, const people& people) {
	return out << people.second_name << "\n" << people.first_name << "\n" << people.third_name
		<< "\n" << people.pol << "\n" << people.national << "\n" << people.tall << "\n" << people.weight << "\n" << people.year << "\n" << people.month
		<< "\n" << people.day << "\n" << people.number << "\n" << people.index << "\n" << people.country << "\n" << people.oblast << "\n" << people.raion << "\n" << people.city
		<< "\n" << people.streat << "\n" << people.home << "\n" << people.kvartira << endl;
}


istream& operator >> (istream& in, people& people) {
	string second_name, first_name, third_name, pol, national, tall, weight, year, month, day, number, index, country, oblast, raion, city, streat,
		home, kvartira;
	in >> second_name >> first_name >> third_name >> pol >> national >> tall >> weight >> year >> month >> day >> number >> index >> country >> oblast >>
		raion >> city >> streat >> home >> kvartira;
	people.second_name = second_name;
	people.first_name = first_name;
	people.third_name = third_name;
	people.pol = pol;
	people.national = national;
	people.tall = tall;
	people.weight = weight;
	people.year = year;
	people.month = month;
	people.day = day;
	people.number = number;
	people.index = index;
	people.country = country;
	people.oblast = oblast;
	people.raion = raion;
	people.city = city;
	people.streat = streat;
	people.home = home;
	people.kvartira = kvartira;
	return in;
}

