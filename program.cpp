/*
This is a program that keeps track of students' names, IDs, and GPAs.
there are 4 commands, add (adds a new student), print (prints stored students),
delete (removes a student from the database), and quit (ends the program).

Created by: Matthew Graham

Last worked on: 10/8/26
*/

// imports the headers used
#include<iostream>
#include<cstring>
#include<cctype>
#include<vector>
#include<algorithm>
#include<iomanip>

// sets namespace
using namespace std;

// function to remove whitespace/punctuation from a carray and make it uppercase
void strip(char (&input)[81]){
  // establishes variables used
  char temp[81] = "";
  int length;
  char ch1;

  // gets length of the input carray
  length = strlen(input);

  // goes through and capitalizes alphanumeric characters and adds them to output 
  for(int i = 0; i<length; i++){
    ch1 = input[i];
    if(isalnum(ch1)){
      ch1 = toupper(ch1);
      strncat(temp,&ch1,1);
    }
  }
  // sets input to the output
  strcpy(input,temp);
}

// gets text input using a passed in prompt and assigns it to the char passed in
void getTextInput(char (&input)[81], char prompt[81]){
  cout << prompt;
  cin.getline(input,81);
  strip(input);
}

// gets float input using a passed in prompt and assigns it to a float passed in
void getFloatInput(float &input, char prompt[81]){
  bool noinput = true;
  char error[22] = "Enter a Valid Number!";
  // checks that input is valid and dosent leave anything in the buffer
  while (noinput){
    cout << prompt;
    cin >> input;
    if (cin.fail() or cin.peek() != '\n'){
      cout << error << endl;
      cin.clear();
    } else {
      noinput = false;
    }
    // removes trailing newline from input buffer
    cin.ignore(99999,'\n');
  }
}

// gets int input using a passed in prompt and assigns it to an int passed in
void getIntInput(int &input, char prompt[81]){
  bool noinput = true;
  char error[22] = "Enter a Valid Number!";
  // checks that input is valid and dosent leave anything in the buffer
  while (noinput){
    cout << prompt;
    cin >> input;
    if (cin.fail() or cin.peek() != '\n'){
      cout << error << endl;
      cin.clear();
    } else {
      noinput = false;
    }
    // removes trailing newline from input buffer
    cin.ignore(99999,'\n');
  }
}

// defines the struct object that stores student variables
struct student {
  float gpa;
  int id;
  char first[81];
  char last[81];
  // function to get the values for the struct and assign them to variables in the struct
  void getValues(vector<student*> studentList){
    // prompts and variables used
    char sameId[44] = "ID cannot be the same as another student's";
    char idPrompt[81] = "ID: ";
    char gpaPrompt[81] = "GPA: ";
    char fNamePrompt[81] = "First Name: ";
    char lNamePrompt[81] = "Last Name: ";
    bool noId = true;
    int tempId;
    // checks that the id is not a duplicate
    while (noId){
      getIntInput(tempId, idPrompt);
      noId = false;
      // goes through passed in vector and sees if id matches
      for (auto it = studentList.begin(); it != studentList.end(); it++){
	if ((**it).id == tempId){
	    noId = true;
	    cout << sameId << endl;
	  }
      }
    }
    // gets rest of values and assigns non-duplicate id
    id = tempId;
    getFloatInput(gpa, gpaPrompt);
    getTextInput(first, fNamePrompt);
    getTextInput(last, lNamePrompt);
  }
};

// prints students
void printStudents(vector<student*> studentList){
  // text chunks to print out with values
  char spacer[3] = ", ";
  char noPrintMessage[17] = "Nothing to Print";

  // goes through and prints out the values for each student on their own line
  for (auto it = studentList.begin(); it != studentList.end(); it++){
    cout << (**it).first << spacer;
    cout << (**it).last << spacer;
    cout << (**it).id << spacer;
    // sets gpa to 2 decimal places and prints it out at the end of the line, then makes a new line
    cout << fixed << setprecision(2) << (**it).gpa << endl;
  }
  // tells user if vector is empty
  if (studentList.size() == 0){
    cout << noPrintMessage << endl;
  }
}

// deletes student based on id passed in
void delStudent(vector<student*> &studentList, int num){
  // sets up variables used
  student* toDelete = nullptr;
  bool deleted = false;
  char deleteMessage[9] = "Deleted!";
  char noDeleteMessage[18] = "Nothing to Delete";

  // checks struct for struct with matching id and saves its pointer
  for (auto it = studentList.begin(); it != studentList.end(); it++){
    if ((**it).id == num){
      toDelete = *it;
      deleted = true;
    }  
  }
  if (deleted){
    // deletes pointer from struct that has the matching id
    studentList.erase(remove_if(studentList.begin(),studentList.end(), [num](student* x){return (*x).id == num;}));
    // deletes data
    delete toDelete;
    cout << deleteMessage << endl;
  } else {
    cout << noDeleteMessage << endl;
  }
}

int main(){
  char input1[81];
  char input2[81];
  float floatInput;
  int intInput;
  char commandPrompt[16] = "enter command: ";
  char idLabel[81] = "ID: ";
  bool running = true;
  char print[6] = "PRINT";
  char add[4] = "ADD";
  char del[7] = "DELETE";
  char quit[5] = "QUIT";

  int counter = 0;
  
  vector<student*> studentList = {};
  
  while (running){
    getTextInput(input1,commandPrompt);
    if (strncmp(input1,print,strlen(print)) == 0){
      printStudents(studentList);
    } else if (strncmp(input1,add,strlen(add)) == 0){
      studentList.push_back(new student);
      (*studentList.back()).getValues(studentList);
    } else if (strncmp(input1,del,strlen(del)) == 0){
      getIntInput(intInput, idLabel);
      delStudent(studentList,intInput);
    } else if (strncmp(input1,quit,strlen(quit)) == 0){
      running = false;
    }
  }
}
