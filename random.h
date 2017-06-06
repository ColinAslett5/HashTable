//Random student generator for HashTable, Colin Aslett, C++ Period 07
#include <vector>

using namespace std;

class Name{
 public:
  //initialization and deallocation
  Name(const char* fname,const char* lname);//file names
  ~Name();
  //by retrieving I mean randomly creating 
  char* Fname();//retrieving the first name
  char* Lname();//retrieving the last name
  int Id();//retrieving the ID
  float GPA();//retrieving
 private:
  vector<char*> fname;
  vector<char*> lname;
  int id;
};
