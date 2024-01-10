struct UserInfo {
    static int latestId; 
    int id;
    string username;
    string password;

    UserInfo() : id(++latestId) {}
};