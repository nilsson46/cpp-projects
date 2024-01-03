#include <iostream>

#include <vector>

/*namespace first{

    int x = 1;

}

namespace second{

    int x = 2;

} */

//typedef std::vector<std::pair<std::string, int>> parilist_t;

//typedef std::string text_t;

//typedef int number_t;

//USING is more popular then typedef

/*using text_t = std::string;

using number_t = int; */

// RECURSION

void walk(int steps);

//FUNCTION TEMPLATE THEN YOU CAN USE DIFFERENT DATATYPES!

template <typename T, typename U>

auto max(T x, U y){

    return (x > y) ? x : y;

}

int main(){




    /*const double PI = 3.14159;//Read only and cant be changed.

   

    double radius = 10;

    double circumference = 2 * PI * radius;




    std::cout << circumference << "cm"; */




    //int x = 0;

    // If you dont specify namespace its using its local.

    //Its possible to set a namespace as standard in the method.

    /*using namespace first;

    std::cout << x; */

    //parilist_t parilist;

   

    //TYPEDEF OR USING

    /*text_t firstname = "BRO";

    number_t age = 21;

    std::cout <<firstname<<' ';

    std::cout << age; */

   

    // TYPE CONVERSION

    /*double x = (int)3.14;

    std::cout << x;




    std::cout << (char) 100;




    int correct = 8;

    int questions = 10;




    double score = correct/(double)questions *100;

    std::cout << score << "%"; */

    /*int age;

    std::string name;




    std::cout <<"What is your age?: ";

    std::cin >> age;




    std::cout <<"What is your name?: ";

    std::getline(std::cin >> std::ws, name);

     

    std::cout << "Hello " << name << ' ';

    std::cout << "You are " << age << " years old"; */

    // GOOD LOOKING TERNARY OPERATOR (IF ELSE)

    /*int grade = 61;




    grade >= 60 ? std::cout <<"You pass" : std::cout <<"You failed"; */

    //It uses the local(inside method or function first) if you want to use a global use :: then call the method.




    // & address of

    // * dereference operator

   

    // POINTERS




    /*std::string name = "BRO";

    int age = 51;

    std::string freePizzas [5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};

   

    std::string *pName = & name;

    int *pAge = &age;

    std::string *pFreePizzas = freePizzas;

   

    //ADDRESS OF THE STRING

    std::cout << pName << ' ';

    std::cout << pAge << ' ';

   

    // VALUE OF THE STRING

    std::cout << *pName << ' ';

    std::cout << *pAge << ' ';

    std::cout << freePizzas; */




    // DYNAMIC MEMORY

    /*int *pNum = NULL;

    // DELETE WHEN YOU USING NEW!!!

    pNum = new int;




    *pNum = 21;




    std::cout << "address: " << pNum << ' ';

    std::cout << "value: " << *pNum << ' ';




    delete pNum; */

/*

    char *pGrades = NULL;

    int size;




    std::cout << "How many grades to enter in?: ";

    std::cin >> size;




    pGrades = new char[size];




    for(int i = 0; i < size; i++){

        std::cout << "Enter grade #" << i + 1 << ": ";

        std::cin >> pGrades[i];

    }




    for (int i = 0; i < size; i++){

        std::cout << pGrades [i] << " ";

    }

    delete[] pGrades; */

       

        // RECURSION

        //walk(100);




        //FUNCTION TEMPLATE




        std::cout << max(1, 2.1) << ' ';

    return 0;

}

// RECURSION

void walk (int steps){

    //ITTERATIVE APPROACH

    /*for(int i = 0; i < steps; i++){

        std::cout <<"You take a step! ";

    }*/

    //RECURSIVE EASIER TO UNDERSTAND BUT SAME AS ABOVE

    if(steps > 0){

        std::cout << "You take a step ";

        walk(steps -1);

    }

}


