#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>
#include <iomanip>
using namespace std;


struct Student {
	char name[50];       
	char group[20];      
	int marks[3];        
	double scholarship;  
};


void inputStudent(Student& s);


void saveToBinaryFile(const char* filename,const vector <Student>& students);


void printGoodStudents(const char* filename);


void printNumbers(const string& filename, const string& message);


void printAllStudents(const char* filename);


void increaseScholarship(const char* filename);