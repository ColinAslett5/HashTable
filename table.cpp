//CPP file for hash table, Colin Aslett, C++ Period 07
#include <iostream>
#include "table.h"

using namespace std;

Table::Table(){//initialization of the HashTable
  size = 100;//setting size to 100, what was recommended in Canvas
  list = new Node*[100];//creating a list that is that long using Nodes
}
//deallocating the table and destroying it
Table::~Table(){
  for(int i = 0;i < size;i++){//going through the entire table
    Node* current = list[i];
    while(current){//going through each node and deleting them using ITERATION
      Node* temp = current;
      current = current->next;
      delete temp->data;
      delete temp;
    }
  }
  delete[] list;//destroying the list at the end cause we dont got to use it anymore
}
//adding student publically
void Table::add(char* fname, char* lname, int id, float gpa){
  Node** current = &list[hash(id)];
  int index = 0;
  while(*current != 0){//adding to the end of the chain
    current = &(*current)->next;
    index++;
  }
  if(index >= 3){//3 or more collisions while using chaining, in this case we are going to double the array size
    size *= 2;
    Node** temp = list;
    list = new Node*[size];
    for(int i = 0;i < size/2;i++){
      Node* current = temp[i];
      while(current){
	add(fname,lname,id,gpa);
	Node* old = current;
	current = current->next;
	delete old;
      }
    }
    delete[] temp;
    add(fname,lname,id,gpa);
  }
  else{
    *current = new Node(new Student(fname,lname,id,gpa));
  }
}
//inserting student data privatelly
void Table::insert(Student* current){
  add(current->fname,current->lname,current->id,current->gpa);
  delete current;
}
//deleting a student
bool Table::delt(int id){
  Node** current = &list[hash(id)];
  while(*current != 0){//going through all nodes
    if((*current)->data->id == id){//trying to find a match
      Node* currentx = *current;//temp variable
      *current = (*current)->next;
      delete currentx->data;
      delete currentx;
      return true;//deleted succesfully
    }
    else{
      current = &((*current)->next);
    }
  }
  return false;//couldnt find the student id number
}
//printing out student list
void Table::print(){
  for(int i = 0;i < size;i++){//going throuhg all students
    Node* current = list[i];
    while(current != 0){
      current->data->print();
      current = current->next;
    }
  }
}
//hashing bro
int Table::hash(int id){
  return id % size;//getting the remainder
}
//retrieving student
Student* Table::find(int id){
  Node* current = list[hash(id)];
  while(true){
    if(current == 0){
      return 0;
    }
    else if(current->data->id == id){
      return current->data;
    }
    else{
      current = current->next;
    }
  }
}
