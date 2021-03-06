#include "utils.h"


void clearScreen(){
  for(int counter = 0; counter < ALTURA_ECRA; counter++)
    cout << endl;
}

void pressToContinue(){
    string lixo;
    cout << "Press ENTER to continue." << endl;
    getline(cin,lixo);
    clearScreen();
}


void DeleteWhitespace(string &s){
    //Function copied from first mini midterm
    while (s.find("  ") != string::npos)
        s.erase(s.find("  "), 1);
    if (s[0] == ' ')
        s.erase(0, 1);
    if (s[s.length() - 1] == ' ')
        s.erase(s.length() -1, 1);
}

unsigned short int readUnsignedShortInt(unsigned short int minValue, unsigned short int  maxValue){

  unsigned short int number;
  do{
      cin >> number;
      if(number < minValue || number > maxValue)
        cout << "ERROR: Out of range value, please insert a value between " << minValue << "-" << maxValue << ": ";
  }while(number < minValue || number > maxValue);

  return number;
}


int readInteger(int minValue, int maxValue){

  int number;
  do{
      cin >> number;
      if(number < minValue || number > maxValue)
        cout << "ERROR: Out of range value, please insert a value between " << minValue << "-" << maxValue << ":";
  }while(number < minValue || number > maxValue);

  return number;
}

string readYesNo() {

    string answer;
    bool goodChoice = false;

    do{
        getline(cin, answer);

        if(answer == "yes" || answer == "no")
            goodChoice = true;

        if(!goodChoice)
            cout << "ERROR: That was not a valid answer, please insert valid option (yes or no) :" << endl;

    } while(!goodChoice);

    return answer;
}

//Check if leap year
bool isLeapYear(int year) {
    bool leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    return leap;
}

//Returns the number of days on a given month
unsigned int numDays(unsigned int year,unsigned int month) {

    unsigned int days;

    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) days = 31;
    else if(month == 2) {
        if(isLeapYear(year)) days = 29;
        else days = 28;
    }
    else days = 30;

    return days;
}

bool isMember(const vector<int> &idVector, int id) {
    for(int index = 0; index < idVector.size(); index++){
        if(idVector.at(index) == id)
            return true;
    }
    return false;
}
