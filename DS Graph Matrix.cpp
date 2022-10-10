#include <iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
pair<int, int> findLable(const vector<string>& pointName, const
string& lable1,const string& lable2)
{
 int point1 = -1, point2 = -1;
 for(int i = 0; i < pointName.size(); i++)
 {
 if(pointName[i].compare(lable1) == 0)
 point1 = i;
 if(pointName[i].compare(lable2) == 0)
 point2 = i;
 }
 return make_pair(point1, point2);
}
void printEdge(int** matrix, int size, vector<string> pointName)
{
 for(int i = 0; i < size; i++)
 {
 for(int j = 0; j < size; j++)
 {
 if(matrix[i][j] == 1)
 cout<<pointName[i] << "->"<<pointName[j]<<"\n";
 }
 }
}
int main() {
 int x;
 cout << "how many points ?:\n";
 cin >> x;
 int** matrix = new int*[x];
 //create matrix
 for(int i = 0; i< x; i++)
 {
 matrix[i] = new int[x];
 }
 for(int i = 0; i < x; i++)
 {
 for(int j = 0; j< x; j++)
 {
 matrix[i][j] = 0;
 }
 }

 //lable points name
 string ss;
 vector<string> pointName;
 for(int i = 0; i < x; i++)
 {
 cout<<"please lable point " << i+1 << " :\n";
 cin>>ss;
 pointName.push_back(ss);
 }
 cout<<"defind edges by listing a pair of vertices, i.e. A B,
or -1 to stop:\n";
 string input;
 cin.get();
 getline(cin, input);
 while(input != "-1")
 {
 stringstream tmp(input);
 string lable1, lable2;
 tmp >> lable1 >> lable2;
 pair<int, int> ret = findLable(pointName, lable1,
lable2);
 if(ret.first == -1 || ret.second == -1)
 {
 cout<<"invalid edges input.\n";
 exit(-1);
 }
 matrix[ret.first][ret.second] = 1;
 cout<<"defind edges by listing a pair of vertices, i.e.
A B, or -1 to stop:\n";
 getline(cin, input);
 }
 cout<<"your edges are:\n";
 printEdge(matrix, x, pointName);
 return 0;
}
/*
how many points ?:
5
please lable point 1 :
A
please lable point 2 :
B
please lable point 3 :
C
please lable point 4 :
D
please lable point 5 :
E
defind edges by listing a pair of vertices, i.e. A B, or -1 to
stop:
A C
defind edges by listing a pair of vertices, i.e. A B, or -1 to
stop:
D A
defind edges by listing a pair of vertices, i.e. A B, or -1 to
stop:
A B
defind edges by listing a pair of vertices, i.e. A B, or -1 to
stop:
A D
defind edges by listing a pair of vertices, i.e. A B, or -1 to
stop:
E B
defind edges by listing a pair of vertices, i.e. A B, or -1 to
stop:
-1
your edges are:
A->B
A->C
A->D
D->A
E->B
Program ended with exit code: 0
*/
