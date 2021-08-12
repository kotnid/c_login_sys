// include package
#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

// login 
bool login(){
    string username , password ,un , pw;

    cout << "Pls enter your username: " ; cin >> username;
    cout << "PLs enter your password: " ; cin >> password;

    ifstream read("data\\" + username + ".txt");
    getline(read , un);
    getline(read , pw);

    if (un == username && pw == password){
        return true;
    }else{
        return false;
    }


}

// main script 
int main(){
    int choice;

    cout << "1 :Register accout" << endl ; 
    cout << "2 :Login" << endl ;
    cout << "Pls enter your choice: "; cin >> choice;

    if (choice == 1){
        string username , password ; 
        cout << "Pls register the username: " ; cin >> username;
        cout << "Pls register the password: " ; cin >> password; 

        ofstream file;
        file.open("data\\" + username + ".txt");
        file << username << endl << password;
        file.close();

        main();
    }else if(choice == 2){
        bool status = login();

        if (status == true){
            cout << "login success";
            return 0;
        }else{
            cout << "login fail";
            return 1;
        }
        main();
        

    }else{
        cout << "Illegal input !";
        main();
    }
}