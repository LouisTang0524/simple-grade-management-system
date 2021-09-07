#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "Student.h"

class Class {
public:
	//构造函数
	Class();
	//析构函数
	~Class();
	//添加学生
	void addStudent(vector<Lesson>& lessons);
	//设置班级编号
	void setClassId(int id);
	//获取班级编号
	int getClassId();
	//获取班级人数
	int getClassSize();
	//显示班级信息和学生信息
	void showClass();
	//班级人数加一
	void increaseClassSize();
	//班级人数减一
	void decreaseClassSize();
	//计算本班中获得奖学金的人数
	void setScholarshipStudent();
	//获取本班中获得奖学金的人数
	int getScholarshipStudent();
	//计算班级得分
	void calculateClassScore();
	//获取班级得分
	double getClassScore();

	vector<Student> myStudent;  //该班级的学生组成的数组

private:
	int classSize;  //班级总人数
	int classId;  //班级编号
	int scholarshipStudent;  //获得奖学金的人数
	double classScore;  //班级得分

};