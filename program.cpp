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
    if (cin.fail){
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
  while (noinput){cout << prompt;cin >> input;
    cin.ignore(99999,'\n');
    if (cin.fail){
      cout << endl << error << endl << prompt;
      cin.clear();
    } else {
      noinput = false;
    }
  }
}


void printStudents(vector<student*> studentList){
  char spacer[3] = ", ";
  for (iterator it = studentList.start(); it != studentList.end(); it++){
    cout << *studentList[it].first << spacer;
    cout << *studentList[it].last << spacer;
    cout << *studentList[it].id << spacer;
    cout << *studentList[it].gpa << endl;
  }
}

void delStudent(vector<student*> studentList, int id){
  for (iterator it = studentList.start(); it != studentList.end(); it++){
    if (*studentList[it].id == id){
      delete *studentlist[it];
    }
  }
}

int main(){
  char input1[81];
  char input2[81];
  float floatInput;
  int intInput;
  char commandPrompt[16] = "enter command: ";
  char gpaLabel[81] = "GPA: ";
  char idLabel[81] = "ID: ";
  char fNameLabel[81] = "First Name: ";
  char lNameLabel[81] = "Last Name: ";
  bool running = true;
  char print[6] = "PRINT";
  char add[4] = "ADD";
  char del[7] = "DELETE";
  char quit[5] = "QUIT";

  struct student {
    float gpa;
    int id;
    char first,last;
  };
  
  vector<student*> studentList = {};
  
  
  while (running){
    getTextInput(input,commandPrompt);
    if (strncmp(input,print,strlen(print)) == 0){
      printStudents(studentList)
    } else if (strncmp(input,add,strlen(add)) == 0){
      getTextInput(input1, fNameLabel);
      getTextInput(input2, lNameLabel);
      getIntInput(intInput, idLabel);
      getFloatInput(floatInput, gpaLabel);
      vector.push_back(new student{floatInput,intInput,{input1,input2}});
    } else if (strncmp(input,del,strlen(del)) == 0){
      getIntInput(intInput, idLabel);
      delStudent(studentList,intInput);
    } else if (strncmp(input,quit,strlen(quit)) == 0){
      running = false;
    }

  }
}
