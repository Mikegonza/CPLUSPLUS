//Miguel Gonzalez
//Demo of an array of structs
#include"HeaderCA2.h"
#include<iostream>
using namespace std;
int main()
{
    //declare array of structs
    StudentInfo classroom[30];
    //loop through and read some data
    cout<<"enter number of students: ";
    int numStudents;
    cin>>numStudents;
    for(int i=0; i<numStudents; i++){
        cout<<"enter student name: ";
        cin>>classroom[i].studentName;
        cout<<"enter student id: ";
        cin>>classroom[i].studentID;
        cout<<"enter course grade: ";
        cin>>classroom[i].courseGrade;
    }
    //loop through classroom and display student data
    for(int j=0; j<numStudents; j++){
        cout<<"enter student name: ";
        cin>>classroom[j].studentName;
        cout<<"enter student id: ";
        cin>>classroom[j].studentID;
        cout<<"enter course grade: ";
        cin>>classroom[j].courseGrade;
    }

}