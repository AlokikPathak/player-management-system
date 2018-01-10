
#include<iostream>
#include<fstream>  #For File Handling  fstream, ifstream, ofstream
#include<string>   #For String Manipulation
#include<stdlib.h> #
#include<conio.h>  #clrscr() function which is used to clear the console
//#include<bits/stdc++.h> //this header includes all the library in the Program




/*
    * This Program consists of 9 Functions which performs different tasks as per MENU;
      Functions are as follows;
      1. input();   Takes the Input of Player Information from user
      2. output();  Shows the last input information of Player
      3. writeInFile(); Writes the Input information into the File "PlayersRecord.txt"
      4. searchInRecord();  Searches the information such as Game, PlayerName, PlayerId, DormNo., bedNo. etc. in the File "PlayersRecord.txt"
      5. deleteInRecord();  Deletes the Player's Record using either PlayerId or PlayerName
      6. countPlayersInGame(); Counts the Players Enrolled in different Games
      7. countPlayers();    Counts the No. of Players Records available in File(Database)
      8. showAllRecords();  Shows complete Player's Records
      9. clearCompleteDatabase(); Clears the complete Player's Record Database


    * In the File Parents Name is stored as pn+FirstName+_+LastName
      ex. Parents Name: Vinod Singh ; but in the File it is stored as pnVinod_Singh
    * Similarly Dorm No. is preceeded with "D"
      ex. Dorm No. 5, but in the File it is stored as D5
    * Similarly Bed No. is preceeded with "B"
      ex. Dorm No. 15, but in the File it is stored as B15
    * Similarly coach name is preceeded with "cn" ex. Coach Name is Sudhir Singh is cnSudhir_Singh

*/

using namespace std;

class file
{
    private:
        int playerid;
        string playerName;
        int age;
        char add[30];
        long long phno;   // we are not taking int because Mob No. is 10 digit which is outside the range of int
        string parentName;
        char game[30];
      //  char coachn[30];
        string coachName;
        int dorm;
        int bed;



    public:

        /*
            * This function takes input from user about Player Details
            * The input taken by this function is stored in the File using writeFile() function
        */
        void input(){

            cout<<"\nEnter player id no: ";
            cin>>playerid;
            cout<<"\nEnter player age: ";
            cin>>age;

            //Taking input of Player Name as First Name and Second Name
            string strFname="", strLname="";
            cout<<"\nEnter the First Name of Player: ";
            cin>>strFname;
            cout<<"\nEnter the Last Name of Player: ";
            cin>>strLname;
            playerName = strFname +"_"+ strLname;//Stores the Player as Fname_Lname ex. Aastha_Anand


            cout<<"\nEnter player address(City): ";
            cin>>add;
            cout<<"\nEnter player phone no.: ";
            cin>>phno;

            //Taking input of Player's Parent Name
            cout<<"\nEnter the First Name of Player's Parent: ";
            cin>>strFname;
            cout<<"\nEnter the Last Name of Player's Parent: ";
            cin>>strLname;
            parentName = strFname +"_"+ strLname;//Stores the Player as Fname_Lname ex. Aastha_Anand



            cout<<"\nEnter game name 'Basketball', 'TableTennis', 'Cricket', 'Volleyball', 'Hockey', 'Taekwondo', 'Badminton'\nGame Name: ";
            cin>>game;

            //Taking input of coach name as Fname and Lname
            cout<<"\nEnter the First Name of Coach: ";
            cin>>strFname;
            cout<<"\nEnter the Last Name of Coach: ";
            cin>>strLname;
            coachName = strFname +"_"+ strLname;//Stores the Player as Fname_Lname ex. Aastha_Anand


            //cout<<"\nEnter coach name alloted: ";
           // cin>>coachn;
            cout<<"\nEnter dorm no.: ";
            cin>>dorm;
            cout<<"\nEnter bed no.: ";
            cin>>bed;

        }//end of input()function

        void output(){
            cout<<"\nPlayer Details: \n";
            cout<<"playerid==>"<<playerid<<endl;
            cout<<"player name==>"<<playerName<<endl;
            cout<<"player add==>"<<add<<endl;
            cout<<"phone no==>"<<phno<<endl;
            cout<<"parent name==>"<<parentName<<endl;
            cout<<"game prefered==>"<<game<<endl;
            cout<<"coach alloted==>"<<coachName<<endl;
            cout<<"dorm no==>"<<dorm<<endl;
            cout<<"bed no==>"<<bed<<endl;

        }

       // char* retplayername(){
       //     return playername;
       // }

        string retplayername(){
            return playerName;
        }


        int retplayerid(){
            return playerid;
        }

        int retage(){
            return age;
        }

        char* radd(){
            return add;
        }

        long long  rphno(){ //int cannot store the mobile since it is out of Range
            return phno;
        }

       // char* rparentn(){
       //     return parentn;
       // }

       string rparentn(){
            return parentName;
       }


        char* rgame(){
            return game;
        }


       // char* rcoachn(){
        //    return coachn;
        //}

        string rcoachn(){
            return coachName;
        }


        int rdorm(){
            return dorm;
        }

        int rbed(){
            return bed;
        }

};// End of Class file


/*
    * This function is used to write the details in the file
    * It takes details of class instance and append that into the file
    *
*/
void writeInFile(file fobj){

    char arr[]= "     ";
    ofstream fout;
    fout.open("PlayersRecord.txt", ios::out | ios::app);

    fout<<"id";
    fout<<fobj.retplayerid();fout<<arr;
    fout<<fobj.retplayername();fout<<arr;
    fout<<fobj.retage();fout<<arr;
    fout<<fobj.radd();fout<<arr;
    fout<<fobj.rphno();fout<<arr;

    fout<<"pn";
    fout<<fobj.rparentn();fout<<arr;
    fout<<fobj.rgame();fout<<arr;

    fout<<"cn";
    fout<<fobj.rcoachn();fout<<arr;

    fout<<'D';   //D will starting char of Dorm no. in file for unique identification
                    //All Dorm No. will start with D
    fout<<fobj.rdorm();fout<<arr;

    fout<<'B';  //B will be the Starting char of every BedNo.  to uniquely identify this
    fout<<fobj.rbed();fout<<arr;
    fout<<'\n';


    fout.close();

}


/*
    * This functions shows all the Players record which we have stored in file
*/
void showAllRecords(){

    ifstream readFile;
    readFile.open("PlayersRecord.txt");
    char charsInLine[1024];
    int count=0;
    cout<<"Players records :\n\n";
    while(!readFile.eof()){
        readFile.getline(charsInLine,1024);
        cout<<charsInLine<<endl;
    }
    readFile.close();

}



/*
    * deleteInRecords is function which deletes the Record of Player from Playersrecord.txt file
    * it can delete the Record of Player using Player Id and Player Name both
    * if the choice is 1: it asks for Player's Id
    * else the choice is not 1 here it is 2 as passed by main as 2(deleInRecords(2)): it asks for Player's Name
    * It searches the Player's id and if found it deletes that record

*/
void deleteInRecords(int choice){

    string deleteString;
    string strFname="", strLname="";
    if(choice == 1){   //1: Deletion using PlayerId
        cout<<"Enter the Player's Id whose record needs to be deleted\n";
        cin>>deleteString;
        deleteString = "id"+deleteString;
        cout<<"deleteString: "<<deleteString<<endl;
    }
    else{               //2: Deletion using Player Name
        cout<<"Enter the First Name of Player: ";
        cin>>strFname;
        cout<<"\nEnter the Last Name of Player: ";
        cin>>strLname;
        deleteString = strFname+"_"+strLname;  //ex. Aastha_Anand  here Fname= Aastha Lname= Anand
        cout<<"deleteString: "<<deleteString<<endl;
    }


    ifstream readFile;
    ofstream writeFile("sample.txt");

    char charsInLine[1024];

    readFile.open("PlayersRecord.txt");
   // writeFile.open("sample2.txt", ios::out | ios::app);
    int count=0;
    bool found = false; //checks wheather Player Record is there or not
    //running the loop till end of file
    while(!readFile.eof()){

        readFile.getline(charsInLine,1024);
        string strLine(charsInLine);  //converting to STL string
        cout<<count<<": "<<charsInLine<<endl;

        size_t found = strLine.find(deleteString);

        if(found != string::npos){

            found = true; //stores the found value as true since there is a record with that Id or Name
            break;
        }

        //writes the Line in the write File which doesn't the string
        else{
            writeFile<<charsInLine;//writes the read line of 1024 char which doesn't have that string into the write file
            writeFile<<"\n";
          //  cout<<"Written: "<<charsInLine<<endl;
        }
        count++;

    }//end of While loop

    readFile.close();  //closing the PlayersRecord,txt file
    writeFile.close(); //closing sample.txt file

    remove("PlayersRecord.txt");     //deleting Playersrecord.txt file since unmatched(contents which doesn't need to be deleted) content is copied to sample.txt file
    rename("sample.txt", "PlayersRecord.txt");  //Rename sample.txt as PlayersRecord.txt since Sample.txt contains the contents which were not needed to be deleted

   //if no records found with entered Id or Name
    if(found == false){
       cout<<"No records available...!\n";
    }
}



/*
    * It counts the Total number Players available in our Record File ("PlayersRecord.txt")
    * It uses the string "id" to uniquely identify a record(line) since there is id for every Player
    * So, No. of Player available in Record is equal to no.of times "id" is found in Record File("PlayersRecord.txt")
*/
void countPlayers(){
    ifstream readFile;
    char charsInLine[1024];
    int countPlayer=0;

    readFile.open("PlayersRecord.txt");  //open the File
    while(!readFile.eof()){

        readFile.getline(charsInLine,1024);//scans a single line of File and stores in the charsInLine array
        string strLine(charsInLine); //converting char array(charsInLine) --> string("strLine")

        //finds the string here "id" in strLine which contains a single line of file
        size_t found = strLine.find("id"); //we are looking for id since each row contains id
                                            //so number of rows will be equal to no.of time id is found..!!

        /*
            * If it finds that id in the line(strLine) it increments the countGame
        */
        if(found!= string::npos){
            countPlayer++;
            cout<<charsInLine<<endl;  //printing the Record for the game
        }
        else{
            break;  //if id is not there in Line records are empty
        }
    }//end of while(searching the record)

    cout<<"Number of Players available in our Records: "<<countPlayer<<endl;
    readFile.close(); //closes the file

}//end of countPlayers function




/*
    * Counts Total number of Players in all Games here "Basketball","TableTennis","Cricket","Volleyball","Hockey", "Taekwondo", "Badminton";
*/
void countPlayersInGame(){

    ifstream readFile;
    readFile.open("PlayersRecord.txt");
    char charsInLine[1024];
    int count=0;  //string strLine; // 1024 since a line contains 1024 chars

   //Contains the list of games available for enrollment
    string games[7]={"Basketball","TableTennis","Cricket","Volleyball","Hockey", "Taekwondo", "Badminton"};
    string gameName="";


    for(int i=0; i<7 ; i++){    //remove this loop

        gameName = games[i]; //selects the specific game from array
       // cout<<"GameName: "<<gameName<<endl;
        int countGame = 0;

        ifstream readFile;
        readFile.open("PlayersRecord.txt");

        while(!readFile.eof()){

            readFile.getline(charsInLine, 1024);
            string strLine(charsInLine);  //Casting a char array to string


            size_t found = strLine.find(gameName); //stores the info whether a particular string(Game) form in the line of not
            if(found!= string::npos){
                countGame++;
                //cout<<charsInLine<<endl;  //printing the Record for the game

            }//end of if

        }//end of while

        readFile.close();

        cout<<"No. of Players enrolled in "<<gameName<<": "<<countGame<<endl;
        countGame = 0; //initializing again as 0 to count for next game
   }//end of For Loop


}//end of Function



/*
    *This function finds the Player record by using the PlayerId, PlayerName,Parents Name, Game, Dorm No. Bed No.
    *It takes the Player Name as from user & Returns the Details of the player
    *It searches the Entered Player name in File "PlayersRecord.txt" and returns the record if it is there
    *If the Player is not found in the file it Returns "Player not found...!!"
*/

void searchInRecords(int choice){
   // char game[12];  //string game
    string searchString="";
    string strFname="", strLname="";

    switch(choice){

        case 1: //string strFname="", strLname="";
                cout<<"Enter the First Name of Player: ";
                cin>>strFname;
                cout<<"Enter the Last Name of Player: ";
                cin>>strLname;
                searchString = strFname+"_"+strLname;  //ex. Aastha_Anand  here Fname= Aastha Lname= Anand
                cout<<"Search String: "<<searchString<<endl;
                break;

        case 2: cout<<"Enter the Player Id: ";
                cin>>searchString;
                searchString = "id"+searchString;
                cout<<"Search String: "<<searchString<<endl;
                break;

        case 3: cout<<"Enter the Dorm No.: ";
                cin>>searchString;
                searchString = "D"+searchString;
                cout<<"Search String: "<<searchString<<endl;
                break;

        case 4: cout<<"Enter the Bed No.: ";
                cin>>searchString;
                searchString = "B"+searchString;
                cout<<"Search String: "<<searchString<<endl;
                break;

        case 5:// cout<<"\nEnter the ParentsName. : ";
                cout<<"\nEnter the First Name of Player's Parent: ";
                cin>>strFname;
                cout<<"\nEnter the Last Name of Player's Parent: ";
                cin>>strLname;
                searchString = "pn"+strFname+"_"+strLname;  //ex. Aastha_Anand  here Fname= Aastha Lname= Anand
                cout<<"Search String: "<<searchString<<endl;
                break;

        case 6: cout<<"Enter Player's Games Basketball, TableTennis, Cricket, Volleyball, Hockey, Taekwondo , Badminton : ";
                cin>>searchString;
                break;

        case 7: cout<<"Wrong Input..! Enter your choice again...\n";
                break;

    }//end of switch


    ifstream readFile;
    readFile.open("PlayersRecord.txt");
    char charsInLine[1024]; int count=0;  //string strLine; // 1024 since a line contains 1024 chars
    searchString = searchString+" ";

    while(!readFile.eof()){
        //cout<<"Im inside while\n";
        readFile.getline(charsInLine, 1024);
     //   cout<<"Records row: "<<charsInLine<<endl;

        string strLine(charsInLine);  //Casting a char array to string

        size_t found = strLine.find(searchString); //stores the info whether a particular string(Game) form in the line of not

        if(found!= string::npos){
            count++;
            cout<<"Records "<<count<<" : "<<charsInLine<<endl;  //printing the Record for the game
        }
    }

    readFile.close();
    if( count == 0 )
        cout<<"NO records found...!\n";
    else{
        cout<<"No. of Records found for "<<searchString<<": "<<count<<endl;
    }
}



/*
    * This function is used to completely delete the Player Database
    * It asks for re-confirmation from user
    * If the user press "Y" it completely clears the Player's record
*/

void clearCompleteDatabase(){
    int x;
    cout<<"Do you want to delete the complete database of Players...?\n Press 1 to confirm: ";
    cin>>x;

    if(x==1){
        remove("PlayersRecord.txt"); //Delete the file(Database) PlayersRecord.txt
        ofstream writeFile("PlayersRecord.txt");  //Creates a new empty file named as "PlayersRecord.txt"
        writeFile.close(); //closes the file "PlayersRecord.txt"
    }
}





int main(){

    file fileobj;   //Instance(object) of file class

    while(1){
        int choice;
        cout<<"\n\n############### MENU ###############";
        cout<<"\n1: Add a new Player Record";
        cout<<"\n2: Show all Players Record";
        cout<<"\n3: Delete Player by its Player Id from Record";
        cout<<"\n4: Delete Player by its Player Name from Record";
        cout<<"\n5: Search Player using Player Name";
        cout<<"\n6: Search Player using Player Id";
        cout<<"\n7: Search Player using Dorm No.";
        cout<<"\n8: Search Player using Bed No.";
        cout<<"\n9: Search Players using Parents Name";
        cout<<"\n10: Search Players in a specific Game";
        cout<<"\n11: Count the No. of Player in all Games";
        cout<<"\n12: Count the Total no. of Player's Record";
        cout<<"\n13: Clear the complete database of Player's Record";
        cout<<"\n14: Exit from Program";

        cout<<"\n\nEnter your choice...!\n";
        cin>>choice;
        system("cls");//clearing the console

        switch(choice){

            case 1: fileobj.input();  //Takes input for the instance
                    writeInFile(fileobj); //1: Writes the Input Record in File
                    break;
            case 2: showAllRecords();
                    break;
            case 3: deleteInRecords(1);//3: Delete Player by its Player Id from Record
                    break;
            case 4: deleteInRecords(2);//4: Delete Player by its Player Name from Record
                    break;
            case 5: searchInRecords(1);//5: Search Player using "Player Name"
                    break;
            case 6: searchInRecords(2);//6: Search Player using "Player Id"
                    break;
            case 7: searchInRecords(3);//7: Search Player using "Dorm No."
                    break;
            case 8: searchInRecords(4);//8: Search Player using "Bed No."
                    break;
            case 9: searchInRecords(5);//9: Search for Player's details of particular "Parents Name"
                    break;
            case 10: searchInRecords(6);//10: Search Player's details of particular "Game"
                    break;
            case 11: countPlayersInGame();//11: Count Players in all Games;
                    break;
            case 12: countPlayers();//12: Count Players in individual game
                    break;
            case 13: clearCompleteDatabase();
                    break;
            case 14: cout<<"Exiting from program...\n";
                     exit(0);  //closes the program
            default: cout<<"Wrong Choice..! enter your choice again...\n";
                     break;

        }//end of switch;
   }//end of while

}//end of main
