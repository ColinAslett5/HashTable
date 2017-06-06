//Random generation of Students for Hash Table, C++ Period 07, COlin Aslett
#include "random.h"
#include <fstream>
#include <ctime>
#include <cstdlib>
//initialization
Name::Name(const char* fnamex, const char* lnamex) : id(100001){
  srand(time(0));
  //opening the files to look at the names I put in there
  //it will choose one
  ifstream strFname;
  ifstream strLname;
  strFname.open(fnamex);
  strLname.open(lnamex);
  //first names
  if(strFname.is_open()){
    while(!strFname.eof()){
      char* name = new char[32];
      strFname.getline(name,32);
      fname.push_back(name);//pushing back to the fname vector in the header file
    }
  }
  //last names
  if(strLname.is_open()){
    while(!strLname.eof()){
      char* name = new char[32];
      strLname.getline(name,32);
      lname.push_back(name);//pushing back to the lname vector in the header file
    }
  }
}
//deallocation
Name::~Name(){
  for(int i = 0;i < fname.size();i++){//going through the fname vector and deleting everything
    delete fname[i];
  }
  for(int i = 0;i < lname.size();i++){//going through the lname vector and deleting everything
    delete lname[i];
  }
}
//randomly generating the fname,lname,id, and gpa
char* Name::Fname(){
  return fname[rand()%fname.size()];
}
char* Name::Lname(){
  return lname[rand()%lname.size()];
}
int Name::Id(){
  return id++;
}
float Name::GPA(){
  float num = (rand() % 100);
  num /= 100;
  while(num > 4){//goa cant be bigger than 4
    num--;
  }
  return num;
}
