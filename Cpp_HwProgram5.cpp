#define CRT_SECURE_NO_WARNINGS
using namespace std;
#include<iostream>
#include<iomanip>
#include<string>

class Course
{
public:
	Course(const string studentName = " ", const string courseName = " ");
	virtual void scoreCalc() = 0;
	float finalPercentageCalc();
	char finalGradeCalc();
	friend ostream& operator<<(ostream& os, const Course& data);
protected:
	int labScore;
	int labTotal;
	float labPercentage;
	int classScore;
	int classTotal;
	float classPercentage;
private:
	string studentName;
	string courseName;
	float finalPercentage;
	char finalLetterGrade;
};

Course::Course(const string studentName, const string courseName)
{
	this->studentName = studentName;
	this->courseName = courseName;
}

ostream& operator<<(ostream& os, const Course& data)
{
	os << setprecision(2) << showpoint << fixed;
	os << setw(25) << left << "Student name: " << data.studentName << endl;
	os << setw(25) << left << "Course: " << data.courseName << endl;
	os << setw(25) << left << "Lab Percentage: " << data.labScore << "/" << data.labTotal << " = " << data.labPercentage << "%" << endl;
	os << setw(25) << left << "Classroom Percentage: " << data.classScore << "/" << data.classTotal << " = " << data.classPercentage << "%" << endl;
	os << setw(25) << left << "Final Percentage: " << data.finalPercentage << "%" << endl;
	os << setw(25) << left << "Final Grade: " << data.finalLetterGrade << endl;
	return os;
}

float Course::finalPercentageCalc()
{
	labPercentage = labScore / (float)labTotal * 100;
	classPercentage = classScore / (float)classTotal * 100;
	finalPercentage = (float)(labPercentage + classPercentage) / 2.0;
	return finalPercentage;
}

char Course::finalGradeCalc()
{
	if (finalPercentage >= 90)
	{
		finalLetterGrade = 'A';
		return 'A';
	}
	else if (finalPercentage >= 80)
	{
		finalLetterGrade = 'B';
		return 'B';
	}
	else if (finalPercentage >= 70)
	{
		finalLetterGrade = 'C';
		return 'C';
	}
	else if (finalPercentage >= 60)
	{
		finalLetterGrade = 'D';
		return 'D';
	}
	else
	{
		finalLetterGrade = 'F';
		return 'F';
	}
}

class Biology : public Course
{
public:
	Biology(const string student = " ", const string course = "Biology", int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
	void scoreCalc();
private:
	int lab1, lab2, lab3;//three labs x 100 points each
	int problem1, problem2, problem3;//three problems x 50 points each
	int exam1, exam2;// two exams x 100 points each
};

Biology::Biology(const string student, const string course, int l1, int l2, int l3, int p1, int p2, int p3, int e1, int e2)
	:Course(student, course)
{
	lab1 = l1;
	lab2 = l2;
	lab3 = l3;
	problem1 = p1;
	problem2 = p2;
	problem3 = p3;
	exam1 = e1;
	exam2 = e2;
	scoreCalc();
}

void Biology::scoreCalc()
{
	labScore = lab1 + lab2 + lab3;
	labTotal = 300;
	classScore = problem1 + problem2 + problem3 + exam1 + exam2;
	classTotal = 350;
	Course::finalPercentageCalc();
	Course::finalGradeCalc();
}


class Math : public Course
{
public:
	Math(const string = " ", const string = "Math",
		int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
	void scoreCalc();
private:
	int lab1, lab2;//two labs x 100 points each, lowest dropped.
	int quiz1, quiz2, quiz3;//three quizs x 50 points each, lowest dropped
	int exam1, exam2, exam3, exam4;// four exams x 100 points each, lowest dropped
};

Math::Math(const string s, const string c,
	int l1, int l2, int q1, int q2, int q3, int e1, int e2, int e3, int e4)
	:Course(s, c)
{
	lab1 = l1;
	lab2 = l2;
	quiz1 = q1;
	quiz2 = q2;
	quiz3 = q3;
	exam1 = e1;
	exam2 = e2;
	exam3 = e3;
	exam4 = e4;
	scoreCalc();
}

int calcLowest(const int e1, const int e2)
{
	if (e1 < e2)
		return e1;
	else
		return e2;
}

int calcLowest(const int e1, const  int e2, const  int e3)
{
	int lowest = e1;
	if (e2 < lowest)
		lowest = e2;
	if (e3 < lowest)
		lowest = e3;
	return lowest;
}

int calcLowest(const int e1, const  int e2, const  int e3, const  int e4)
{
	int lowest = e1;
	if (e2 < lowest)
		lowest = e2;
	if (e3 < lowest)
		lowest = e3;
	if (e4 < lowest)
		lowest = e4;
	return lowest;
}

void Math::scoreCalc()
{
	labScore = lab1 + lab2 - calcLowest(lab1, lab2);
	labTotal = 100;
	int lowestQz = calcLowest(quiz1, quiz2, quiz3);
	int lowestExam = calcLowest(exam1, exam2, exam3, exam4);
	classScore = quiz1 + quiz2 + quiz3 + exam1 + exam2 + exam3 + exam4 - lowestExam - lowestQz;
	classTotal = 400;
	Course::finalPercentageCalc();
	Course::finalGradeCalc();
}

class ComputerScience :public Course
{
public:
	void scoreCalc();
	ComputerScience(const string student = " ", const string course = "Computer Science",
	int p1 = 0, int p2 = 0, int p3 = 0, int p4 = 0, int e1 = 0, int e2 = 0, int f = 0);
private:
	int program1, program2, program3, program4;//4 programs each 20 points
	int exam1, exam2;//two exam each 100 pints. if final is higher than lowest exam, then lowest = final
	int final;//if final exam <50, fail
};


ComputerScience::ComputerScience(const string student, const string course,
	int p1, int p2, int p3, int p4, int e1, int e2, int f):Course(student, course)
{
	program1 = p1;
	program2 = p2;
	program3 = p3;
	program4 = p4;
	exam1 = e1;
	exam2 = e2;
	final = f;
	scoreCalc();
}

void ComputerScience::scoreCalc()
{
	labScore = program1 + program2 + program3 + program4;
	labTotal = 80;
	int lowestExam = calcLowest(exam1, exam2);
	if (final > lowestExam)
	{
		classScore = exam1 + exam2 - lowestExam + final + final;
	}
	if (final <= 50)//if final exam <50, automatically fail
	{
		exam1 = exam2 = final = 0;
	}
	classTotal = 300;
	Course::finalPercentageCalc();
	Course::finalGradeCalc();
}

class English :public Course
{
//a English course
//Lab percentage is based on four essays worth up to 100 points each, the lowest essay dropped.
//class percentage is based on four quizzes worth 20 points each, and two exams worth 100 points each
//the lowest quiz score will dropped
public:
	void scoreCalc();
	English(const string student = " ", const string course = "English", int e1 = 0, int e2 = 0, int e3 = 0, int e4 = 0,
		int q1 = 0, int q2 = 0, int q3 = 0, int q4 = 0, int em1 = 0, int em2 = 0);
private:
	int essay1, essay2, essay3, essay4;
	int quiz1, quiz2, quiz3, quiz4;
	int exam1, exam2;
};

English::English(const string student, const string course, int e1, int e2, int e3, int e4,
	int q1, int q2, int q3, int q4, int em1, int em2)
{
	essay1 = e1;
	essay2 = e2;
	essay3 = e3;
	essay4 = e4;
	quiz1 = q1;
	quiz2 = q2;
	quiz3 = q3;
	quiz4 = q4;
	exam1 = em1;
	exam2 = em2;
	scoreCalc();
}

void English::scoreCalc()
{
	int lowestEssay = calcLowest(essay1, essay2, essay3, essay4);
	labScore = essay1 + essay2 + essay3 + essay4 - lowestEssay;
	labTotal = 300;
	int lowestQuiz = calcLowest(quiz1, quiz2, quiz3, quiz4);
	classScore = quiz1 + quiz2 + quiz3 + quiz4 + exam1 + exam2 - lowestQuiz;
	classTotal = 260;
	Course::finalPercentageCalc();
	Course::finalGradeCalc();
}

int main()
{
	Course* ptr = new Biology("Joy", "Biology", 50, 90, 95, 35, 40, 39, 89, 79);
	cout << *ptr << endl << endl;
	ptr = new Math("Janna", "Math", 100, 80, 40, 30, 45, 99, 89, 66, 98);
	cout << *ptr << endl << endl;
	ptr = new ComputerScience("Andew", "Computer Science", 20, 10, 18, 15, 100, 60, 80);
	cout << *ptr << endl << endl;
	ptr = new English("Anna", "English", 40, 60, 70, 50, 5, 10, 16, 8, 66, 49);
	cout << *ptr << endl << endl;
	delete ptr;
	ptr = NULL;
	return 0;

}
