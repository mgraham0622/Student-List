#include<iostream>
#include<cstring>
#include<cctype>
#include<vector>

using namespace std;

void strip(char (&input)[81]){
  char temp[81] = "";
  int length;
  char ch1;

  length = strlen(input);

  for(int i = 0; i<length; i++){
    ch1 = input[i];
    if(isalnum(ch1)){
      ch1 = toupper(ch1);
      strncat(temp,&ch1,1);
    }
  }
  strcpy(input,temp);
}

void getTextInput(char (&input)[81], char prompt[81]){
  cout << prompt;
  cin.get(input,81);
  cin.ignore(99999,'\n');
  strip(input);
}

void getFloatInput(float &input, char prompt[81]){
  bool noinput = true;
  char error[22] = "Enter a Valid Number!";
  while (noinput){
    cout << prompt;cin >> input;
    cin.ignore(99999,'\n');
    if (cin.fail()){
      cout << endl << error << endl << prompt;
      cin.clear();
    } else {
      noinput = false;
    }
  }
}

void getIntInput(int &input, char prompt[81]){
  bool noinput = true;
  char error[22] = "Enter a Valid Number!";
  while (noinput){
    cout << prompt;
    cin >> input;
    if (cin.fail()){
      cout << endl << error << endl << prompt;
      cin.clear();
    } else {
      noinput = false;
    }
  }
}

struct student {
  float gpa;
  int id;
  char first[81];
  char last[81];
  void getValues(){
    char idPrompt[81] = "ID: ";
    char gpaPrompt[81] = "GPA: ";
    char fNamePrompt[81] = "First Name: ";
    char lNamePrompt[81] = "Last Name: ";
    getIntInput(id, idPrompt);
    getFloatInput(gpa, gpaPrompt);
    getTextInput(first, fNamePrompt);
    getTextInput(last, lNamePrompt);
  }
};

void printStudents(vector<student*> studentList){
  char spacer[3] = ", ";
  for (auto it = studentList.begin(); it != studentList.end(); it++){
    cout << (**it).first << spacer;
    cout << (**it).last << spacer;
    cout << (**it).id << spacer;
    cout << (**it).gpa << endl;
  }
}

void delStudent(vector<student*> studentList, int id){
  for (auto it = studentList.begin(); it != studentList.end(); it++){
    if ((**it).id == id){
      cout << "hi";
      delete *it;

    }
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
  
  vector<student*> studentList = {};
  
  
  while (running){
    getTextInput(input1,commandPrompt);
    if (strncmp(input1,print,strlen(print)) == 0){
      printStudents(studentList);
    } else if (strncmp(input1,add,strlen(add)) == 0){
      studentList.push_back(new student);
      (*studentList.back()).getValues();
    } else if (strncmp(input1,del,strlen(del)) == 0){
      getIntInput(intInput, idLabel);
      delStudent(studentList,intInput);
    } else if (strncmp(input1,quit,strlen(quit)) == 0){
      running = false;
    }

  }
}
