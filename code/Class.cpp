#include "Class.h"

//构造函数
Class::Class() {
	classSize = 0;
	classId = 0;
	classScore = 0.0;
	scholarshipStudent = 0;
}

//析构函数
Class::~Class() {

}

//设置班级编号
void Class::setClassId(int id) {
	classId = id;
}

//获取班级编号
int Class::getClassId() {
	return classId;
}

//获取班级人数
int Class::getClassSize() {
	return classSize;
}

//班级人数加一
void Class::increaseClassSize() {
	classSize++;
}

//班级人数减一
void Class::decreaseClassSize() {
	classSize--;
}

//添加学生
void Class::addStudent(vector<Lesson>& lessons) {
	cout << "本次共添加学生人数：";
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		Student newStudent;
		cout << "请输入第" << i + 1 << "名学生的姓名：";
		string name;
		cin >> name;
		newStudent.setName(name);  //输入学生姓名
		newStudent.setGrade(lessons);  //输入学生各科成绩
		myStudent.push_back(newStudent);  //在本班学生数组末尾添加该学生
		increaseClassSize();  //班级总人数加一
	}
	
}

//显示班级信息和学生信息
void Class::showClass() {
	cout << "班级编号：" << classId << endl;
	for (size_t i = 0; i < myStudent.size(); i++) {
		myStudent[i].showStudent();
	}
}

//计算本班中获得奖学金的人数
void Class::setScholarshipStudent() {
	scholarshipStudent = 0;
	for (size_t i = 0; i < myStudent.size(); i++) {
		if (myStudent[i].getHasScholarship()) {
			scholarshipStudent++;
		}
	}
}

//获取本班中获得奖学金的人数
int Class::getScholarshipStudent() {
	return scholarshipStudent;
}



//计算班级得分
//班级得分=
//（获得奖学金的人数*20+（所有课程都及格人数-获得奖学金的人数）*80）
///班级总人数
void Class::calculateClassScore() {
	//计算所有课程都及格的人数
	int passStudent = 0;
	for (size_t i = 0; i < myStudent.size(); i++) {
		if (myStudent[i].getIsPassed()) {
			passStudent++;
		}
	}

	//计算班级得分
	classScore = ((double)getScholarshipStudent() * 20 + ((double)passStudent - (double)getScholarshipStudent()) * 80) / getClassSize();
}

//获取班级得分
double Class::getClassScore() {
	return classScore;
}