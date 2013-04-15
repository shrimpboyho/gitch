#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctype.h>
#include <vector>
#include "dewey.h"
#include <sstream>


using namespace std;

//PROTOTYPES:

void checky();
void beginInit();
void runtimeExec(int argc, char* argv[]);
void loadCommands();

/*GLOBAL VARIABLES*/

vector<string> user_settings;
vector<string> git_commands;
vector<string> gitch_commands;

int main ( int argc, char *argv[] )
{


    /* CHECK IF NO ARGUMENTS ARE PASSED */

    if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s <command>\n\nRefer to online documentation for more information.\n", argv[0] );
    }else{
        /* BUT IF THEY ARE */

        if((string)argv[1] == "init"){
            checky();
        }else{

            loadCommands();
            runtimeExec(argc,argv);

        }

    }



}


void checky(){

    char option;

    // Check to see if the file exists

        fstream file;
        file.open("gitch.txt", ios_base::out | ios_base::in);
        if (file.is_open() == true){
            cout << "You already have gitch initialized here. Do you want to overwrite it? (y/n)";
            cin >> option;
            if(tolower(option)=='n'){
                cout << "Phew.";
            }
            if(tolower(option)=='y'){
                beginInit();
            }

            if((tolower(option)!='y')&&(tolower(option)!='n')){
                cout << "Not a valid answer. Y or N only";
                checky();
            }


        }

        // If a file doesn't exist

        if (file.is_open() == false){
            beginInit();
        }


}

void beginInit(){

        ofstream myfile("gitch.txt");

        // then hide it
        system("attrib +h gitch.txt");


        // and close the file when done
        myfile.close();

        cout << "\nInitialized gitch in this location.\n";

}

void runtimeExec(int argc, char* argv[]){

    // Looping variables

    int i, k;
    string command;
    bool overflow = false;

    if((string)argv[1] == "replace"){

    }else if((string)argv[1] == "list"){

    }else{

        command = "git " + git_commands[0];


        cout << "Send this command to git: \n" << command << "\n\n";
        system(command.c_str());
    }


}

void loadCommands(){

    int i; // loop counter
    string tempstrgitch; // a temporary string
    string tempstrgit; // a temporary string

    TextFileToArray parser("gitch.txt", ';');

    parser.vectorfiller(&user_settings);

    // Split string using pystring library.

    for(i = 0; i < user_settings.size() - 1 ; i++){

         // Create an input stream

         std::istringstream ss;
         ss.str(user_settings[i]);

         // Getline with delims

         std::getline(ss, tempstrgitch, '%');
         std::getline(ss, tempstrgit, '%');

         gitch_commands.push_back(tempstrgitch);
         git_commands.push_back(tempstrgit);

         cout << "GITCH COMMANDS: " << gitch_commands[i] << endl;
         cout << "GIT COMMANDS: " << git_commands[i] << endl;

    }



}



