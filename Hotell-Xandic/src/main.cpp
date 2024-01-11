#include <iostream>
#include <fstream>
#include <vector>
#include <istream>
#include <sstream>
#include <algorithm>
#include "Log.h"
using 
    std::cout,
    std::cin,
    std::string,
    std::fstream,
    std::ofstream,
    std::ios,
    std::vector,
    std::istringstream,
    std::to_string;

bool isRunning = true;
bool isLoggedIn = false;

fstream userFile;
string userFileName = "user.txt";

fstream bookingFile; 
string bookingFileName = "booking.txt";

struct UserInfo {
    string username;
    string password;
    static int latestId; 
    int userId;
    UserInfo() : userId(++latestId) {}
};
int UserInfo::latestId;

struct Booking {
    static int latestBookingId;
    int bookingId;
    string username;
    string room; 
    string date;
    Booking() : bookingId(++latestBookingId) {}
};
int Booking::latestBookingId;

vector<string> readFromFile(fstream& file, const string& fileName) {
    vector<string> lines;
    file.open(fileName, ios::in);

    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

vector<UserInfo> getUsers() {
    vector<UserInfo> users;
    for (const string& text : readFromFile(userFile, userFileName)) {
        UserInfo user;
        istringstream iss(text);
        iss >> user.username >> user.password;
        users.push_back(user);
    }
    return users;
}

void updateLatestId() {
    vector<UserInfo> users = getUsers();
    if (!users.empty()) {
        UserInfo::latestId = users.back().userId;
    }
    else {
        UserInfo::latestId = 0;
    }
}

void updateLatestBookingId() {
    vector<Booking> bookings = getBookings();
    if (!bookings.empty()) {
        Booking::latestBookingId = bookings.back().bookingId;
    }
    else {
        Booking::latestBookingId = 0;
    }
}

void displayMenu(const vector<string>& menuOptions) {
    for (int i = 0; i < menuOptions.size(); i++) {
        cout << "[" << (i + 1) << "] " << menuOptions[i] << '\n';
    }
}

string getUserInput(const string& prompt) {
    string userInput;
    cout << prompt;
    cin >> userInput;
    return userInput;
}

void writeToFile(const string& fileName, const vector<string>& input) {
    ofstream file(fileName, ios::out | ios::app);
    if (!file.is_open()) {
        cout << "Unable to open file: " << fileName << '\n';
        return;
    }

    for (const string& text : input) {
        cout << "Writing to file: " << text << '\n';
        file << text << '\n';
    }

    file.close();
    if (file.fail()) {
        cout << "Error closing file: " << fileName << '\n';
    }
}

bool validateUser(const UserInfo& input) {
    for (const UserInfo& user : getUsers()) {
        if (user.username == input.username && user.password == input.password) {
            return true;
        }
    }
    return false;
}

void login() {
    UserInfo userInfo;
    userInfo.username = getUserInput("Enter your username: ");
    userInfo.password = getUserInput("Enter your password: ");

    if (validateUser(userInfo)) {
        cout << "Welcome " << userInfo.username << '\n';
        isLoggedIn = true;
    } else {
        cout << "Login failed" << '\n';
    }
}

void registerNewUser() {
    UserInfo userInfo;
    userInfo.username = getUserInput("Enter your username: ");
    userInfo.password = getUserInput("Enter your password: ");

    if (validateUser(userInfo)) {
        cout << "User already exists. Registration failed." << '\n';
    } else { 
        updateLatestId();
        
        userInfo.userId = ++UserInfo::latestId;
        
        cout << "Registration successful. Welcome, " << userInfo.username << " with ID " << UserInfo::latestId << '\n';

        writeToFile(userFileName, {userInfo.username + " " + userInfo.password + " " + to_string(userInfo.userId)});
    }
}

void createBooking(const UserInfo& user){
    Booking booking; 
    booking.username = user.username;
    booking.date = getUserInput("Enter the date you want to book: ");
    
    updateLatestId(); // Corrected function name
    
    booking.bookingId = ++Booking::latestBookingId;

    writeToFile(bookingFileName, {to_string(booking.bookingId) + " " + booking.date + " " + booking.username});
}

vector<Booking> getBookings() {
    vector<Booking> bookings;
    for (string text : readFromFile(bookingFile, bookingFileName)) {
        Booking booking;
        istringstream iss(text);
        iss >> booking.bookingId >> booking.date >> booking.username;
        bookings.push_back(booking);
    }
    return bookings;
}

void displayBookings(const vector<Booking>& bookingList) {
    for (const Booking& booking : bookingList) {
        cout << "Booking ID: " << booking.bookingId << ", Date: " << booking.date << ", Username: " << booking.username << '\n';
    }
}

void bookingMenuSelection(const string& userInput) {
    if (userInput == "1") {
        cout << "Add booking" << '\n';
        createBooking(getUsers().front());
    } else if (userInput == "2") {
        cout << "Reservations" << '\n';
        vector<Booking> bookings = getBookings();
        displayBookings(bookings);
    } else if (userInput == "3") {
        cout << "Remove reservation" << '\n';
    } else if (userInput == "4") {
        cout << "Change reservation" << '\n';
    } else if (userInput == "5") {
        isLoggedIn = false;
    } else {
        cout << "Invalid selection. Try again." << '\n';
    }
}

void bookingLoop() {
    while (isLoggedIn) {
        displayMenu({"Add booking", "Check your Reservations", "Remove reservation", "Update reservation", "Logout"});
        bookingMenuSelection(getUserInput("Enter your selection: "));
    }
}

void handleUserSelection(const string& userInput) {
    if (userInput == "1") {
        cout << "Login " << '\n';
        login();
        if (isLoggedIn) {
            bookingLoop();
        }
    } else if (userInput == "2") {
        cout << "Register new user" << '\n';
        registerNewUser();
    } else if (userInput == "3") {
        cout << "Exiting..." << '\n';
        isRunning = false;
    } else {
        cout << "Invalid selection. Try again." << '\n';
    }
}

void loginLoop() {
    while (isRunning) {
        displayMenu({"Login", "Register", "Exit"});
        handleUserSelection(getUserInput("Enter your selection: "));
    }
}

int main() {
    loginLoop();
    return 0;
}
