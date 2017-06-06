//Main file for Hash Table, COlin Aslett, C++ Period 07
#include <iostream>
#include <vector>
#include <cctype>
#include <cstring>
#include "table.h"

using namespace std;

int main(){
  char input[32];
  Table table;
  //RN rn("firstnames.txt","lastnames.txt");//generating random student info
  cout << "Welcome To Hash Table!" << endl;
  while(true){
    cout << "Enter a number, 1 = add student/s, 2 = delete student, 3 = print out list of students, 4 = quit" << endl;
    cin >> input;
    //adding students
    if(input[0] == '1'){
      char fname[32];
      cout << "Enter first name of student: " << endl;
      cin.ignore();
      cin.getline(fname,32);
      char lname[32];
      cout << "Enter last name of student " << endl;
      cin.getline(lname,32);
      int id;
      cout << "Enter ID of student: " << endl;
      cin >> id;
      float gpa;
      cout << "Enter GPA of Student: " << endl;
      cin >> gpa;
      table.add(fname,lname,id,gpa);//adding the student through functions explained in table.h and table.cpp
      cout << "Success!" << endl;
    }
    //deleting a student if it exists
    else if(input[0] == '2'){
      //get the id of the student
      cout << "Enter ID of student you want deleted: " << endl;
      int id;
      cin >> id;
      //checking to see if the student exists before we delete it
      if(table.delt(id)){
	cout << "Successful!" << endl;
      }
      else{
	cout << "Failure, Could Not Find Student" << endl;
      }
    }
    //printing out the student list
    else if(input[0] == '3'){
      table.print();//calls the table function to print out the table
    }
    //quitting the program
    else if(input[0] == '4'){
      return 0;
    }
  }
}
