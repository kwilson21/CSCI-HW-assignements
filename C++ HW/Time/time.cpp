// asgn BY Kazon Wilson,  CSCI 2170-5
// PROGRAM ID:  time.cpp / Time converter
// AUTHOR:  Kazon Wilson
// INSTALLATION:  MTSU
// REMARKS:   Reads in the time from a data file and converts the time
// in 24-hour notation as two integers - one for
// hours and one for minutes - and converts it to 12-hour notation.

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

string convertTime(string temphour,string tempminute, char& meridian);
void displayTime(string& currentTime);

int main(){
    // Declare variables
    ifstream myIn;
    string currentTime;
    string templine;
    string temphour;
    string tempminute;
    char meridian;
    
    // Open and verify the file
    myIn.open("times.dat");
    assert(myIn); 

    // Read in each time in 24-hour format, determine if the meridian is AM or PM
    // convert the time as needed, then display the new time.
    while(getline(myIn,templine)){      // Read in each line as a string. ie. "10:45"
        /* Iterate through each element of the string,
           split the hour and time and store them into seperate variables.*/
        for(int i = 0; i<templine.length(); i++){   
            if(templine[i] == ':'){
                tempminute+= templine[i+1];
                tempminute+= templine[i+2];
                break;
            }   
            else{
                temphour += templine[i];
            }
        }
        /* Convert the hour from string to int, if it is greater than 12,
           set the meridian to 'A', otherwise set it to 'P'. */
        if (stoi(temphour) > 12){
            meridian = 'A';
        }
        else{
            meridian = 'P';
        }
        // Convert and display the new time.
        currentTime = convertTime(temphour, tempminute, meridian);
        displayTime(currentTime);
        // Clear the temporary strings.
        temphour = "";
        tempminute = "";
    }
    myIn.close();
}

string convertTime(string temphour,string tempminute,char& meridian){
    string temptime;
    int hour;

    /* Convert the hour from string to integer, then check the meridian.
       If the meridian is 'A', convert the hour and add 'PM' to the time. 
       If the hour is 0, correct it to show midnight and add 'AM' to the time.
       Otherwise, leave the hour as is and add 'AM' to the time. */
    hour = stoi(temphour);
    if (meridian == 'A'){
        hour = hour - 12;
        temptime+=to_string(hour);
        temptime+=":";
        temptime+=tempminute;
        temptime+=" PM";
    }
    else if(hour == 0 || hour == 24){
        temptime+="12";
        temptime+=":";
        temptime+=tempminute;
        temptime+=" AM";
    }
    else{
        temptime+=temphour;
        temptime+=":";
        temptime+=tempminute;
        temptime+=" AM";
    }
    return temptime;
}

void displayTime(string& currentTime){
    cout << currentTime << endl;
}