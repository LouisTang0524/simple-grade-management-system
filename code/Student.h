#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Lesson.h"

class Student {
public:
	//构造函数
	Student();
	//析构函数
	~Student();
	//设置姓名
	void setName(string name);
	//获取姓名
	string getName();
	//获取学生的平均成绩
	double getAverageGrade();
	//设置学生各门课的成绩
	void setGrade(vector<Lesson>& lessons);
	//显示学生信息
	void showStudent();
	//修改学生信息
	void changeStudent();
	//设置学生是否获得奖学金
	void setHasScholarship(bool hasScholarship);
	//获取学生是否获得奖学金
	bool getHasScholarship();
	//获取学生是否全部课程都及格
	bool getIsPassed();

	vector<Lesson> myLesson;  //学生的课程组成的数组

private:
	string s_Name;  //学生姓名
	double s_AverageGrade;  //加权求学生的平均成绩
	bool s_hasScholarship;  //是否获得奖学金
	bool s_isPassed;  //是否全部课程都及格

};