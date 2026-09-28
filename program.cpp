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

void getInput(char (&input)[81]){
  cout << "enter command: ";
  cin.get(input,81);
  cin.ignore(99999,'\n');
  strip(input);
}

int main(){
  char input[81];
  bool running = true;
  char print[6] = "PRINT";
  char add[4] = "ADD";
  char del[7] = "DELETE";
  char quit[5] = "QUIT";
  vector<char*> commands = {print,add,del,quit};
  int a = 0;
  
  while (running){
    getInput(input);
    //for (auto it = commands.begin(); it != commands.end(); it++){
    //}
    a++;
    if (a==5){
      running = false;
    }
  }
}
