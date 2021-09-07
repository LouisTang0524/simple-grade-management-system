#include "Lesson.h"

Lesson::Lesson() {
	l_Name = "";
	l_Grade = 0;
	l_Weight = 0.0;
}

Lesson::Lesson(const Lesson& l) {
	l_Name = l.l_Name;
	l_Weight = l.l_Weight;
	l_Grade = l.l_Grade;
}

Lesson::~Lesson() {

}

void Lesson::setName(string name) {
	l_Name = name;
}

string Lesson::getName() {
	return l_Name;
}

void Lesson::setWeight(double weight) {
	l_Weight = weight;
}

double Lesson::getWeight() {
	return l_Weight;
}

void Lesson::setGrade(int grade) {
	l_Grade = grade;
}

int Lesson::getGrade() {
	return l_Grade;
}

bool Lesson::isPassed() {
	if (l_Grade >= 60) {
		return true;
	}
	return false;
}