#pragma once
#include <string>
#include <iostream>
using namespace std;

class Lesson {
public:
	//构造函数
	Lesson();
	//复制构造函数
	Lesson(const Lesson& l);
	//析构函数
	~Lesson();
	//设置权重
	void setWeight(double weight);
	//获取权重
	double getWeight();
	//设置课程名
	void setName(string name);
	//获取课程名
	string getName();
	//设置课程成绩
	void setGrade(int grade);
	//获取课程成绩
	int getGrade();
	//判断是否及格
	bool isPassed();
private:
	string l_Name;  //课程名
	double l_Weight;  //课程成绩权重
	int l_Grade;  //课程成绩
};