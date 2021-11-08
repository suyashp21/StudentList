/* Author: Suyash Pandit
Date: November 8, 2021
This program simulates a list of students */


#include <vector>
#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>

using namespace std;

struct Student {
  // student attributes
  char first[20];
  char last[20];
  int id;
  float gpa;
};

void add (vector<Student*> &in);
void remove(vector<Student*> &in);

int main() {
  char action[20];
  
  vector <Student*> students;
  cout << "\nWhat would you like to do? (ADD, PRINT, DELETE, QUIT)" << endl;
  
  while (true) {
    // repeat until user ends loop
    cin >> action;
    if (strcmp(action, "ADD") == 0) {
      cout << "\n";
      add(students);
      // cout << students.size() << endl;
    }
    else if (strcmp(action, "PRINT") == 0) {
      cout << "\n";
      if (students.size() == 0) {
	cout << "There are currently no students on your list." << endl;
      }
      // print students on list
      for (int i=0; i<students.size(); i++) {
	cout << students[i]->first << " " << students[i]->last;
	cout << ", " << students[i]->id << ", " << fixed << setprecision(2) << students[i]->gpa << endl;
      }
    }
    else if (strcmp(action, "DELETE") == 0) {
      if (students.size() == 0) {
	cout << "You cannot delete any students as there are currently none on your list!" << endl;
      }
      else {
	remove(students);
      }
    }
    else if (strcmp(action, "QUIT") == 0) {
      // end the loop
      break;
    }
    else {
      // not any of the commands
      cout << "Unrecognized command." << endl;
      continue;
    }
    cout << "\nWhat would you like to do?" << endl;
  }
  // add(students);
  return 0;
}

void add (vector <Student*> &in) {
  // initialize a new student and add to vector
  Student* s = new Student();
  cout << "New student first name: "; cin >> s->first;
  cout << "Last name: "; cin >> s->last;
  cout << "Student ID: "; cin >> s->id;
  cout << "GPA: "; cin >> s->gpa;
  in.push_back(s);
}

void remove (vector <Student*> &in) {
  // removes student by id number.
  // got help from Kushal Rao.
  
  int remove = -1;
  bool found = false;
  cout << "\nEnter ID number of student to remove. ";
  cin >> remove;
  for (int i=0; i < in.size(); i++) {
    // search for matching ID
    if(in[i]->id == remove) {
      in.erase(in.begin()+i);
      break;
      found = true;
    }
  }
  if (found == false) {
    // ID number does not match any student
    cout << "Not a valid ID number. No students deleted." << endl;
  }
}
