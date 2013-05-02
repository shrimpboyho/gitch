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
void printCommands();


/*GLOBAL VARIABLES*/

vector<string> user_settings;
vector<string> git_commands;
vector<string> gitch_commands;

int main ( int argc, char *argv[] )
{


    /* CHECK IF NO ARGUMENTS ARE PASSED */

    if ( argc < 2 ) /* argc should be 2 for correct execution */
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
                cout << "Not a valid answer. Y or N only\n\n";
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
    string command = "git ";
    bool overflow = false;

    if((string)argv[1] == "replace"){

    }else if((string)argv[1] == "list"){

        // Print the commands

        printCommands();

    }else{

        /* RUN THE CUSTOM GITCH COMMAND */

                int i;

                for(i = 1; i < argc; i++){

                    for(k = 0;k<gitch_commands.size();k++){

                        if((string)argv[i] == gitch_commands[k]){
                            command = command + git_commands[k] + " ";
                        }
                    }

                }



                cout << "\nSending this command to git: "<< command << endl;

                system(command.c_str());




    }


}

void loadCommands(){

    int i; // loop counter
    string tempstrgitch; // a temporary string
    string tempstrgit; // a temporary string

    TextFileToArray parser("gitch.txt", ';');

    parser.vectorfiller(&user_settings);

    // Create an empty 0th index

    gitch_commands.push_back("");
    git_commands.push_back("");

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

    }



}

void printCommands(){

    /*Check to see if the text file is not empty*/

    int length;
    ifstream filestr;

    filestr.open("gitch.txt", ios::binary); // open your file

    filestr.seekg(0, ios::end); // put the "cursor" at the end of the file

    length = filestr.tellg(); // find the position of the cursor

    filestr.close(); // close your file

    if ( length == 0 )
    {
        printf("\nYou haven't loaded gitch with any commands. Use the replace command to do so.\n");
    }
    else
    {
        int i; // loop counter

        cout << "\nCOMMANDS:\n";

        for(i = 0; i < gitch_commands.size(); i++){
            cout << "\n" << gitch_commands[i] << " = " << git_commands[i];
    }

    }


}



