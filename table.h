//Header file for the hash table functions, Colin Aslett, C++ Period 07
#include <cstring>
#include <iostream>
#include <iomanip>//for setting precision
using namespace std;

//Struct containing student data
struct Student{
  //basic info for each student
  char* fname;
  char* lname;
  int id;
  float gpa;
  //deleting the student
  ~Student(){
    delete[] fname;
    delete[] lname;
  }
  //printing out student info
  void print(){
    cout << fname << " , " << lname << " , " << id << " , ";
    cout << setprecision(2) << fixed << gpa << endl;//seperate to make sure that only 2 digits of the gpa are printed out
  }
  //constructing the data for each student
  Student(const char* Fname, const char* Lname, int Id, float Gpa){
    fname = strcpy(new char[strlen(Fname) + 1], Fname);
    lname = strcpy(new char[strlen(Lname) + 1], Lname);
    id = Id;
    gpa = Gpa;
  }
};
struct Node{//linked list used for chaining
  Node* next;//next node on the chain
  Student* data;//each node holds a specific students data for that location
Node(Student* data) : data(data), next(0){}
  //deconstructor
  ~Node(){

  }
};

//The main class for the project
class Table{
 public:
  Table();//creation
  ~Table();//deletion
  Student* find(int id);//finding the student
  void add(char* fname, char* lname, int id, float gpa);//getting info then insert will be used privately to add data to table
  bool delt(int id);//returns true if it deleted it, false if it couldnt find the student
  void print();//prints out the student list
 private:
  int size;//size of the table
  void insert(Student*);//inserting the student data
  int hash(int num);//hashing based on ID
  Node** list;
};

  
