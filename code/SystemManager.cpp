#include "SystemManager.h"
#include "Class.h"
#define TOTAL_SCHOLARSHIP 10

SystemManager::SystemManager() {

}

SystemManager::~SystemManager() {

}

//显示菜单
void SystemManager::showMenu() {
	cout << "-------班级成绩管理---------" << endl;
	cout << "============================" << endl;
	cout << "-------1.添加新班级---------" << endl;
	cout << "-------2.添加新学生---------" << endl;
	cout << "-------3.显示所有信息-------" << endl;
	cout << "-------4.查找班级-----------" << endl;
	cout << "-------5.查找学生-----------" << endl;
	cout << "-------6.删除班级-----------" << endl;
	cout << "-------7.删除学生-----------" << endl;
	cout << "-------8.修改学生信息-------" << endl;
	cout << "-------9.清空系统-----------" << endl;
	cout << "-------10.评选奖学金--------" << endl;
	cout << "-------0.退出系统-----------" << endl;
	cout << "============================" << endl;
}

//退出系统
void SystemManager::exitSystem() {
	cout << "欢迎下次使用。" << endl;
	system("pause");
	exit(0);
}

//初始化课程，包括录入课程名，成绩权重
void SystemManager::initLessons(vector<Lesson>& lessons) {
	//int total;
	//cout << "请输入本学期课程总数：";
	//cin >> total;
	//vector<Lesson> lessons(total);
	for (size_t i = 0; i < lessons.size(); i++) {
		cout << "请输入第" << i + 1 << "门课程名：";
		string name;
		cin >> name;
		lessons[i].setName(name);
		cout << "请输入第" << i + 1 << "门课程的成绩权重（小于1的小数）：";
		double weight;
		cin >> weight;
		lessons[i].setWeight(weight);
		lessons[i].setGrade(0);
	}
}

//添加班级
void SystemManager::addClass(vector<Lesson>& lessons) {
	Class newClass;
	cout << "请输入班级编号：" << endl;
	int id;
	cin >> id;

	newClass.setClassId(id);
	myClass.push_back(newClass);
	myClass.back().addStudent(lessons);

	system("pause");
	system("cls");
}

//显示所有班级
void SystemManager::showAll() {
	if (myClass.size() == 0) {
		cout << "系统中无任何信息" << endl;
	}
	else {
		for (size_t i = 0; i < myClass.size(); i++) {
			myClass[i].showClass();
		}
	}

	system("pause");
	system("cls");
}

//添加新学生，先输入班级查找
//如果找到则添加学生
//如果没找到则不添加，并打印提示信息
void SystemManager::addStudent(vector<Lesson>& lessons) {
	cout << "请输入班级编号：" << endl;
	int id;
	cin >> id;

	bool flag = false;
	size_t i;
	for (i = 0; i < myClass.size(); i++) {
		if (id == myClass[i].getClassId()) {
			myClass[i].addStudent(lessons);
			flag = true;
			break;
		}
	}
	if (!flag) {
		cout << "查无此班，请先添加班级" << endl;
	}

	system("pause");
	system("cls");
}

//按班级编号查找班级
//如果找到则打印该班级中所有信息
//如果找不到则打印提示信息
void SystemManager::searchClass() {
	if (myClass.size() == 0) {
		cout << "系统中无任何信息" << endl;
	}
	else {
		cout << "请输入班级编号：" << endl;
		int id;
		cin >> id;

		bool flag = false;
		size_t i;
		for (i = 0; i < myClass.size(); i++) {
			if (id == myClass[i].getClassId()) {
				myClass[i].showClass();
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << "查无此班" << endl;
		}

	}

	system("pause");
	system("cls");
}

//按姓名查找学生
//如果找到则打印该学生的信息
//如果找不到则打印提示信息
void SystemManager::searchStudent() {
	if (myClass.size() == 0) {
		cout << "系统中无任何信息" << endl;
	}
	else {
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;

		bool flag = false;
		size_t i, j;
		for (i = 0; i < myClass.size(); i++) {
			for (j = 0; j < myClass[i].myStudent.size(); j++) {
				if (name == myClass[i].myStudent[j].getName()) {
					myClass[i].myStudent[j].showStudent();
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (!flag) {
			cout << "查无此人" << endl;
		}

	}

	system("pause");
	system("cls");
}

//删除班级，先按照班级编号查找班级
//如果找到则输出提示信息向用户再次确认，确认后执行删除，否则不执行
//如果找不到则输出提示信息
void SystemManager::deleteClass() {
	if (myClass.size() == 0) {
		cout << "系统中无任何信息" << endl;
	}
	else {
		cout << "请输入班级编号：" << endl;
		int id;
		cin >> id;

		bool flag = false;
		size_t i;
		int choice = 2;
		for (i = 0; i < myClass.size(); i++) {
			if (id == myClass[i].getClassId()) {
				myClass[i].showClass();
				flag = true;
				cout << "确定删除吗？1：是。2：否。";
				cin >> choice;
				if (choice == 1) {
					myClass.erase(myClass.begin() + i);
					cout << "删除成功" << endl;
					break;
				}
			}
		}
		if (!flag) {
			cout << "查无此班" << endl;
		}

	}

	system("pause");
	system("cls");
}

//删除学生，先按照学生姓名查找
//如果找到则输出提示信息向用户再次确认，确认后执行删除，否则不执行
//如果找不到则输出提示信息
void SystemManager::deleteStudent() {
	if (myClass.size() == 0) {
		cout << "系统中无任何信息" << endl;
	}
	else {
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;

		bool flag = false;
		size_t i, j;
		int choice = 2;
		for (i = 0; i < myClass.size(); i++) {
			for (j = 0; j < myClass[i].myStudent.size(); j++) {
				if (name == myClass[i].myStudent[j].getName()) {
					myClass[i].myStudent[j].showStudent();
					flag = true;
					cout << "确定删除吗？1：是。2：否。";
					cin >> choice;
					if (choice == 1) {
						myClass[i].myStudent.erase(myClass[i].myStudent.begin() + j);
						myClass[i].decreaseClassSize();
						cout << "删除成功" << endl;
					}
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (!flag) {
			cout << "查无此人" << endl;
		}

	}

	system("pause");
	system("cls");
}

//修改学生信息，先按照姓名查找
//如果找到则执行修改操作
//如果找不到则打印提示信息
void SystemManager::changeStudent() {
	if (myClass.size() == 0) {
		cout << "系统中无任何信息" << endl;
	}
	else {
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		bool flag = false;
		size_t i, j;
		for (i = 0; i < myClass.size(); i++) {
			for (j = 0; j < myClass[i].myStudent.size(); j++) {
				if (name == myClass[i].myStudent[j].getName()) {
					myClass[i].myStudent[j].showStudent();
					myClass[i].myStudent[j].changeStudent();
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
		}
		if (!flag) {
			cout << "查无此人" << endl;
		}

	}

	system("pause");
	system("cls");

}

//清空（删除）所有班级信息
//执行操作前输出提示信息向用户确认是否执行清空操作
//若是则执行操作，若否则不执行
void SystemManager::clearAll() {
	if (myClass.size() == 0) {
		cout << "系统中无任何信息" << endl;
	}
	else {
		cout << "是否确定清空？1：是。2：否。";
		int choice = 2;
		cin >> choice;
		if (choice == 1) {
			myClass.clear();
			cout << "清空成功" << endl;
		}
	}

	system("pause");
	system("cls");
}

//评选奖学金
//将所有学生降序排列，前十名获得奖学金
void SystemManager::rankForScholarship() {
	if (myClass.size() == 0) {
		cout << "系统中无任何信息" << endl;
		system("pause");
		system("cls");
		return;
	}
	int totalSize = 0;
	for (size_t i = 0; i < myClass.size(); i++) {
		totalSize += myClass[i].getClassSize();
	}  //计算系统中学生总数

	//动态申请内存创建一个数组，传入系统中所有学生信息
	Student** studentArray = new Student*[totalSize];
	int already = 0;
	for (size_t i = 0; i < myClass.size(); i++) {
		for (size_t j = 0; j < myClass[i].myStudent.size(); j++) {
			studentArray[already] = &(myClass[i].myStudent[j]);
			studentArray[already]->setHasScholarship(false);
			already++;
		}
	}

	//按照加权平均成绩降序排列
	sorting(studentArray, totalSize);

	//前十名获得奖学金，如果总人数不超过十个，则全部获得奖学金
	//如果总人数超过十个，则前十名获得奖学金
	//同时输出获奖者信息
	cout << "获得奖学金的名单：" << endl;
	if (totalSize <= TOTAL_SCHOLARSHIP) {
		for (int i = 0; i < totalSize; i++) {
			studentArray[i]->setHasScholarship(true);
			studentArray[i]->showStudent();
		}
	}
	else {
		for (int i = 0; i < TOTAL_SCHOLARSHIP; i++) {
			studentArray[i]->setHasScholarship(true);
			studentArray[i]->showStudent();
		}
	}

	//释放动态申请的内存
	delete[] studentArray;

}

//按成绩排序
void SystemManager::sorting(Student** studentArray, int totalSize) {
	int i, j;
	for (i = 0; i < totalSize - 1; i++) {
		for (j = 0; j < totalSize - 1; j++) {
			if (studentArray[j]->getAverageGrade() < studentArray[j + 1]->getAverageGrade()) {
				swap(studentArray[j], studentArray[j + 1]);
			}
		}
	}
}

//评定优秀班级
void SystemManager::chooseBestClass() {
	//计算所有班级的班级得分
	for (size_t i = 0; i < myClass.size(); i++) {
		myClass[i].calculateClassScore();
	}

	//选出优秀班级
	Class* bestClassPtr = &myClass[0];
	for (size_t i = 0; i < myClass.size(); i++) {
		if (myClass[i].getClassScore() > bestClassPtr->getClassScore()) {
			bestClassPtr = &myClass[i];
		}
	}

	//打印优秀班级
	bestClassPtr->showClass();
	cout << "班级得分：\t" << bestClassPtr->getClassScore() << endl;

	system("pause");
	system("cls");
}