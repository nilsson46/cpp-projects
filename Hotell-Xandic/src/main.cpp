#include <iostream>
#include <fstream>
#include <vector>
#include <istream>
#include <sstream>

using 
    std::cout,
    std::cin,
    std::string,
    std::fstream,
    std::ios,
    std::vector,
    std::istringstream;

bool isRunning = true;
fstream file;
string fileName = "user.txt";

struct UserInfo{
    string username;
    string password; 
};

void displayMenu(){
    cout << "[1] Log in"<<'\n';
    cout << "[2] Register"<<'\n';
    cout << "[3] Exit"<<'\n';
}
string getUserInput(string prompt){
    string userInput;
    cout << prompt;
    cin >> userInput;
    return userInput;
}

void readFromFile(UserInfo userInfo){
    file.open(fileName, ios::in);
    string line, name, secret;
    bool isLoggedIn = false;
    for(int i = 1; getline(file, line); i++){
        istringstream iss(line);
        iss >> name >> secret;
        //cout << i << ". " << line << '\n';
        if(name == userInfo.username && secret == userInfo.password){
            isLoggedIn = true;
        }
    }
    if(isLoggedIn = true){
        cout << "Welcome " << userInfo.username << '\n';
    }
    file.close();
}
void writeToFile(vector<string> text){
    file.open(fileName, ios::out | ios::app);
    for (string text : text){
        file <<text << '\n';
    }
    file.close();
}
void login(){
    UserInfo userInfo;
    userInfo.username = getUserInput("Enter your username: ");
    userInfo.password = getUserInput("Enter your password: ");

    readFromFile(userInfo);
}

void registerNewUser(){
    UserInfo userInfo;
    userInfo.username = getUserInput("Enter your username: ");
    userInfo.password = getUserInput("Enter your password: ");
    cout << "Username: " << userInfo.username <<'\n';
    cout << "Password: " << userInfo.password <<'\n';
    //Enter username and password
    //check if user already exist
    //else create user
    writeToFile({userInfo.username, userInfo.password});

} 
void handleUserSelection(string userInput){
    UserInfo userInfo; 
    if(userInput == "1"){
        cout << "Login " << '\n';
        login();
    } else if(userInput == "2") {
        cout << "Register new user" << '\n';
        registerNewUser();
    } else if(userInput == "3") {
        cout << "Exiting..." << '\n';
        isRunning = false;
    } else {
        cout << "Invalid selection. Try again." << '\n';
    }
}


void gameloop(){
    while(isRunning){
        displayMenu();
        handleUserSelection(getUserInput("Enter your selection: "));
    }
}
int main (){
    gameloop();
    return 0;
}