#include "Student.h"

//���캯��
Student::Student() {
	s_Name = "";
	s_AverageGrade = 0.0;
	s_hasScholarship = false;
	s_isPassed = true;
}

//��������
Student::~Student() {

}

//��������
void Student::setName(string name) {
	s_Name = name;
}

//��ȡ����
string Student::getName() {
	return s_Name;
}

//��ȡѧ����ƽ���ɼ�
double Student::getAverageGrade() {
	return s_AverageGrade;
}

//¼��ѧ�����ſεĳɼ�
void Student::setGrade(vector<Lesson>& lessons) {
	myLesson = lessons;
	for (size_t i = 0; i < myLesson.size(); i++) {
		cout << "�������" << i + 1 << "�ſ�" << myLesson[i].getName() << "�ĳɼ���";
		int grade;
		cin >> grade;
		myLesson[i].setGrade(grade);
	}

	//�����Ȩƽ���ɼ�
	for (size_t i = 0; i < myLesson.size(); i++) {
		s_AverageGrade += myLesson[i].getGrade() * myLesson[i].getWeight();
	}

	//�ж��Ƿ�ȫ������
	s_isPassed = true;
	for (size_t i = 0; i < myLesson.size(); i++) {
		if (myLesson[i].getGrade() < 60) {
			s_isPassed = false;
			break;
		}
	}
	cout << "��ѧ���ɼ�¼��ɹ���" << endl;

}

//��ʾѧ����Ϣ
void Student::showStudent() {
	cout << "\t������" << getName() << "\tƽ���ɼ���" << getAverageGrade() << endl;
	for (size_t i = 0; i < myLesson.size(); i++) {
		cout << "\t" << myLesson[i].getName() << ":" << myLesson[i].getGrade();
	}
	cout << endl;
}

//�޸�ѧ����Ϣ
//�������������Ƴɼ��������¼����Ȩƽ���ɼ�
void Student::changeStudent() {
	cout << "������������";
	string newName;
	cin >> newName;
	setName(newName);

	for (size_t i = 0; i < myLesson.size(); i++) {
		cout << "�������" << i + 1 << "�ſ�" << myLesson[i].getName() << "�ĳɼ���";
		int grade;
		cin >> grade;
		myLesson[i].setGrade(grade);
	}
	cout << "��ѧ���ɼ�¼��ɹ���" << endl;

	//���¼����Ȩƽ���ɼ�
	s_AverageGrade = 0.0;//�Ƚ�ƽ���ɼ�����
	for (size_t i = 0; i < myLesson.size(); i++) {
		s_AverageGrade += myLesson[i].getGrade() * myLesson[i].getWeight();
	}

	//�ж��Ƿ�ȫ������
	s_isPassed = true;
	for (size_t i = 0; i < myLesson.size(); i++) {
		if (myLesson[i].getGrade() < 60) {
			s_isPassed = false;
			break;
		}
	}

	cout << "�޸ĳɹ�" << endl;
}

//����ѧ���Ƿ��ý�ѧ��
void Student::setHasScholarship(bool hasScholarship) {
	s_hasScholarship = hasScholarship;
}

//��ȡѧ���Ƿ��ý�ѧ��
bool Student::getHasScholarship() {
	return s_hasScholarship;
}

//��ȡѧ���Ƿ�ȫ���γ̶�����
bool Student::getIsPassed() {
	return s_isPassed;
}