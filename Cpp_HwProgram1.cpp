#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
using namespace std;

struct stu 
{
	char LetterGrade;
	char name[20];
	int HwGrade1;//range from 0 - 25
	int HwGrade2;
	int HwGrade3;
	int ExamGrade1;//range from 0 - 100
	int ExamGrade2;
	int ttlHw;
	int ttlExam;
	float ClassPercent;
};

int CheckHwValid()
{
	int grade;
	cin >> grade;
	while (grade > 25 || grade < 0)
	{
		cout << "Invalid input! The homework grade range from 0 - 25." << endl << "Please re-enter the grade:>";
		cin >> grade;
	}
	return grade;
}

int CheckExamValid()
{
	int grade;
	cin >> grade;
	while (grade > 100 || grade < 0)
	{
		cout << "Invalid input! The Exam grade range from 0 - 100." << endl << "Please re-enter the grade:>";
		cin >> grade;
	}
	return grade;
}

void InitStu (struct stu* s,const int num)
{
	int i;
	for(i = 0;i<num;i++)
	{
		cout << "Please enter the name:>";
		cin.getline(s->name, sizeof(s->name));
		cout << "Please enter the first Homework Grade:>";
		s->HwGrade1 = CheckHwValid();
		cout << "Please enter the second Homework Grade:>";
		s->HwGrade2 = CheckHwValid();
		cout << "Please enter the third Homework Grade:>";
		s->HwGrade3 = CheckHwValid();
		cout << "Please enter the first Exam Grade:>";
		s->ExamGrade1 = CheckExamValid(); 
		cout << "Please enter the second Exam Grade:>";
		s->ExamGrade2 = CheckExamValid();
		cin.ignore(20, '\n');
		s++;
	}
}

void CalcStu(struct stu* s, const int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		s->ttlHw = s->HwGrade1 + s->HwGrade2 + s->HwGrade3;
		s->ttlExam = s->ExamGrade1 + s->ExamGrade2;
		s->ClassPercent = (s->ttlHw / 1.875) + (s->ttlExam / 3.333);
		s++;
	}
}

void LetterGradeStu(struct stu* s, const int num) 
{
	int i;
	for (i = 0; i < num; i++)
	{
		if (s->ClassPercent >= 90)
			s->LetterGrade = 'A';
		else if (s->ClassPercent >= 80)
			s->LetterGrade = 'B';
		else if (s->ClassPercent >= 70)
			s->LetterGrade = 'C';
		else if (s->ClassPercent >= 60)
			s->LetterGrade = 'D';
		else
			s->LetterGrade = 'F';
		s++;
	}
}

void PrintLine()
{
	cout << "|";
	int j;
	for (j = 0; j < 19; j++)
		cout << "-";
	cout << "|";
	for (j = 0; j < 4; j++)
		cout << "-";
	cout << "|";
	for (j = 0; j < 6; j++)
		cout << "-";
	cout << "|";
	for (j = 0; j < 12; j++)
		cout << "-";
	cout << "|";
	for (j = 0; j < 7; j++)
		cout << "-";
	cout <<"|"<< endl;
}

void ShowStu(const struct stu* s, const int num)
{
	int i;
	//print title
	cout <<endl<<endl<<
		setw(20) << left << "| NAME" <<"|"
		<< setw(4) << " HW " <<"|"
		<< setw(6) << " EXAM " <<"|"
		<< setw(12) << " PERCENTAGE " <<"|" 
		<< setw(7) << " GRADE " <<"|"<< endl;
	PrintLine();
	//print each student's data
	for (i = 0; i < num; i++)
	{
		cout << setprecision(2) << showpoint << fixed;
		cout <<"| "<< setw(18) <<left<< s->name << "| "
			<< setw(3) <<right<< s->ttlHw << "| "
			<< setw(5) << s->ttlExam << "| "
			<< setw(11) << s->ClassPercent << "| "
			<< setw(6) << s->LetterGrade << "|" << endl;
		PrintLine();
		s++;
	}
}
void CalcAveExam(const struct stu* s, const int num)
{
	int i;
	float ttlexam1 = 0;
	float ttlexam2 = 0;
	for (i = 0; i < num; i++)
	{
		ttlexam1 += s->ExamGrade1;
		ttlexam2 += s->ExamGrade2;
		s++;
	}
	ttlexam1 /= num;
	ttlexam2 /= num;
	cout << "The average exam 1 score is: " << ttlexam1 << endl;
	cout << "The average exam 2 score is: " << ttlexam2 << endl;
}

void CalcLetterGrade(const struct stu* s,const int num)
{
	int i;
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;
	int F = 0;
	for (i = 0; i < num; i++)
	{
		if (s->LetterGrade == 'A')
			A++;
		else if (s->LetterGrade == 'B')
			B++;
		else if (s->LetterGrade == 'C')
			C++;
		else if (s->LetterGrade == 'D')
			D++;
		else
			F++;
		s++;
	}
	cout << endl;
	cout << A << " A's are given." << endl;
	cout << B << " B's are given." << endl;
	cout << C << " C's are given." << endl;
	cout << D << " D's are given." << endl;
	cout << F << " F's are given." << endl;
}

int main()
{
	const int size = 5;
	struct stu* s = (struct stu*)malloc(size*sizeof(struct stu));
	InitStu(s,size);//enter student's data
	CalcStu(s, size);//calculate ttl hw, ttl exam, class percentage
	LetterGradeStu(s, size);//calculate letter grade
	ShowStu(s,size);//print out a chart for each student's data
	CalcAveExam(s,size);
	CalcLetterGrade(s,size);
	return 0;
}
