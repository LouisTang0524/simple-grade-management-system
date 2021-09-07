#include "Student.h"

//构造函数
Student::Student() {
	s_Name = "";
	s_AverageGrade = 0.0;
	s_hasScholarship = false;
	s_isPassed = true;
}

//析构函数
Student::~Student() {

}

//设置姓名
void Student::setName(string name) {
	s_Name = name;
}

//获取姓名
string Student::getName() {
	return s_Name;
}

//获取学生的平均成绩
double Student::getAverageGrade() {
	return s_AverageGrade;
}

//录入学生各门课的成绩
void Student::setGrade(vector<Lesson>& lessons) {
	myLesson = lessons;
	for (size_t i = 0; i < myLesson.size(); i++) {
		cout << "请输入第" << i + 1 << "门课" << myLesson[i].getName() << "的成绩：";
		int grade;
		cin >> grade;
		myLesson[i].setGrade(grade);
	}

	//计算加权平均成绩
	for (size_t i = 0; i < myLesson.size(); i++) {
		s_AverageGrade += myLesson[i].getGrade() * myLesson[i].getWeight();
	}

	//判断是否全部及格
	s_isPassed = true;
	for (size_t i = 0; i < myLesson.size(); i++) {
		if (myLesson[i].getGrade() < 60) {
			s_isPassed = false;
			break;
		}
	}
	cout << "该学生成绩录入成功。" << endl;

}

//显示学生信息
void Student::showStudent() {
	cout << "\t姓名：" << getName() << "\t平均成绩：" << getAverageGrade() << endl;
	for (size_t i = 0; i < myLesson.size(); i++) {
		cout << "\t" << myLesson[i].getName() << ":" << myLesson[i].getGrade();
	}
	cout << endl;
}

//修改学生信息
//包括姓名，各科成绩，并重新计算加权平均成绩
void Student::changeStudent() {
	cout << "请输入姓名：";
	string newName;
	cin >> newName;
	setName(newName);

	for (size_t i = 0; i < myLesson.size(); i++) {
		cout << "请输入第" << i + 1 << "门课" << myLesson[i].getName() << "的成绩：";
		int grade;
		cin >> grade;
		myLesson[i].setGrade(grade);
	}
	cout << "该学生成绩录入成功。" << endl;

	//重新计算加权平均成绩
	s_AverageGrade = 0.0;//先将平均成绩清零
	for (size_t i = 0; i < myLesson.size(); i++) {
		s_AverageGrade += myLesson[i].getGrade() * myLesson[i].getWeight();
	}

	//判断是否全部及格
	s_isPassed = true;
	for (size_t i = 0; i < myLesson.size(); i++) {
		if (myLesson[i].getGrade() < 60) {
			s_isPassed = false;
			break;
		}
	}

	cout << "修改成功" << endl;
}

//设置学生是否获得奖学金
void Student::setHasScholarship(bool hasScholarship) {
	s_hasScholarship = hasScholarship;
}

//获取学生是否获得奖学金
bool Student::getHasScholarship() {
	return s_hasScholarship;
}

//获取学生是否全部课程都及格
bool Student::getIsPassed() {
	return s_isPassed;
}