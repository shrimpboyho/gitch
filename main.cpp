#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctype.h>
#include <vector>
#include "dewey.h"

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

        command = "git ";
        for(i = 0; i < argc; i++){

            // Find the indexes of the custom args

            for(k = 0; k <= gitch_commands.size(); k++){

                if(k == gitch_commands.size()){
                    overflow = true;
                    break;
                }
                if(argv[i] == gitch_commands[k]){
                    break;
                }

            }

             if(overflow == false){
                command = command + git_commands[k] + " ";
             }
             if(overflow == true){
                command = command + (string)argv[i] + " ";
             }
        }

        cout << "Send this command to git: \n" << command << "\n\n";
        system(command.c_str());
    }


}

void loadCommands(){

    TextFileToArray parser("gitch.txt", ';');

    parser.vectorfiller(&user_settings);

    // Find a way to splt into 2 derivative vectors at the % delim


}



