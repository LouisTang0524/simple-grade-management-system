#pragma once
#include <iostream>
#include <vector>
using namespace std;
#include "Class.h"

class SystemManager {
public:
	//构造函数
	SystemManager();
	//析构函数
	~SystemManager();
	//显示菜单
	void showMenu();
	//退出系统
	void exitSystem();
	//初始化课程，包括录入课程名，成绩权重
	void initLessons(vector<Lesson>& lessons);
	//添加新班级，创建新班级后添加学生
	void addClass(vector<Lesson>& lessons);
	//显示所有班级
	void showAll();
	//添加新学生
	void addStudent(vector<Lesson>& lessons);
	//按班级编号查找班级
	void searchClass();
	//按姓名查找学生
	void searchStudent();
	//删除班级
	void deleteClass();
	//删除学生
	void deleteStudent();
	//修改学生信息
	void changeStudent();
	//清空（删除）所有班级信息
	void clearAll();
	//排名并评选奖学金
	void rankForScholarship();
	//按成绩排序
	void sorting(Student** studentArray, int totalSize);
	//评定优秀班级
	void chooseBestClass();

	vector<Class> myClass;  //系统中的班级

private:
};