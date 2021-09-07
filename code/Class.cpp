#include "Class.h"

//���캯��
Class::Class() {
	classSize = 0;
	classId = 0;
	classScore = 0.0;
	scholarshipStudent = 0;
}

//��������
Class::~Class() {

}

//���ð༶���
void Class::setClassId(int id) {
	classId = id;
}

//��ȡ�༶���
int Class::getClassId() {
	return classId;
}

//��ȡ�༶����
int Class::getClassSize() {
	return classSize;
}

//�༶������һ
void Class::increaseClassSize() {
	classSize++;
}

//�༶������һ
void Class::decreaseClassSize() {
	classSize--;
}

//���ѧ��
void Class::addStudent(vector<Lesson>& lessons) {
	cout << "���ι����ѧ��������";
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		Student newStudent;
		cout << "�������" << i + 1 << "��ѧ����������";
		string name;
		cin >> name;
		newStudent.setName(name);  //����ѧ������
		newStudent.setGrade(lessons);  //����ѧ�����Ƴɼ�
		myStudent.push_back(newStudent);  //�ڱ���ѧ������ĩβ��Ӹ�ѧ��
		increaseClassSize();  //�༶��������һ
	}
	
}

//��ʾ�༶��Ϣ��ѧ����Ϣ
void Class::showClass() {
	cout << "�༶��ţ�" << classId << endl;
	for (size_t i = 0; i < myStudent.size(); i++) {
		myStudent[i].showStudent();
	}
}

//���㱾���л�ý�ѧ�������
void Class::setScholarshipStudent() {
	scholarshipStudent = 0;
	for (size_t i = 0; i < myStudent.size(); i++) {
		if (myStudent[i].getHasScholarship()) {
			scholarshipStudent++;
		}
	}
}

//��ȡ�����л�ý�ѧ�������
int Class::getScholarshipStudent() {
	return scholarshipStudent;
}



//����༶�÷�
//�༶�÷�=
//����ý�ѧ�������*20+�����пγ̶���������-��ý�ѧ���������*80��
///�༶������
void Class::calculateClassScore() {
	//�������пγ̶����������
	int passStudent = 0;
	for (size_t i = 0; i < myStudent.size(); i++) {
		if (myStudent[i].getIsPassed()) {
			passStudent++;
		}
	}

	//����༶�÷�
	classScore = ((double)getScholarshipStudent() * 20 + ((double)passStudent - (double)getScholarshipStudent()) * 80) / getClassSize();
}

//��ȡ�༶�÷�
double Class::getClassScore() {
	return classScore;
}