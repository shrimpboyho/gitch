#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <ctype.h>

using namespace std;

//PROTOTYPES:

void checky();
void beginInit();

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


