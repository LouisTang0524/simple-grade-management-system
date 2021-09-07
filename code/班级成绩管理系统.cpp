#include <iostream>
using namespace std;
#include "SystemManager.h"

int main() {
	SystemManager manager;
	int choice = -1;

	//初始化课程，包括录入课程名，成绩权重
	int total;
	cout << "请输入本学期课程总数：";
	cin >> total;
	vector<Lesson> lessons(total);  //创建一个数组用来存放用户输入的课程信息
	manager.initLessons(lessons);
	system("cls");

	//根据用户输入的选项序号执行相应操作
	while (true)
	{
		manager.showMenu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1://添加新班级
			manager.addClass(lessons);
			break;
		case 2://添加新学生
			manager.addStudent(lessons);
			break;
		case 3://显示所有信息
			manager.showAll();
			break;
		case 4://查找班级
			manager.searchClass();
			break;
		case 5://查找学生
			manager.searchStudent();
			break;
		case 6://删除班级
			manager.deleteClass();
			break;
		case 7://删除学生
			manager.deleteStudent();
			break;
		case 8://修改学生信息
			manager.changeStudent();
			break;
		case 9://清空系统
			manager.clearAll();
			break;
		case 10://排名并评选奖学金，优秀班级评定
			manager.rankForScholarship();
			{
				cout << "是否进行优秀班级评定？1：是。2：否。";
				int choice1 = 2;
				cin >> choice1;
				if (choice1 == 1) {
					manager.chooseBestClass();//评定优秀班级
				}
				else {
					system("cls");
				}
			}
			break;
		case 0:  //退出系统
			manager.exitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}