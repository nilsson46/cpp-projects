/*
Uppvärmning
I följande program, tänk på vad som skiljer en integer från en float point!

Skriv ett c++ program som skapar följande utskrifter
7 / 4 using integer division equals <result>
7 / 4 using floating-point division equals <result>
7 modulo 4 equals <result>

Skriv ett program som hämtar in en celsius grad (med cin från användaren) och gör om den till fahrenheit
Formeln för transformeringen är fahrenheit = ( 9 / 5 ) * celsius + 32

Skriv ett program där användaren får välja mellan att beräkna omkretsen och arean av en cirkel, eller av en rektangel.

Skapa ett program som skapar en diamant av asterisk, givet en viss höjd och bredd som användaren anger. (Ange endast höjd om uppgiften upplevs svår)
Exempel A:
	höjd: 3
	bredd: 5
	  *
	****
	  *
Exempel B:
	höjd: 5
	bredd: 3
	  *
	 * *
	* * *
	 * *
	  *
*/

#include <iostream>
int main (){
	/*//1 
	int x = 7;
	int y = 4;

	int result = x/y;
	std::cout << result; */
	//2
	/*
	float x = 7;
	float y = 4;

	float result = x/y;
	std::cout << result;
	*/

	//3
	/*int x = 7;
	int y = 4;

	int result = x%y;
	std::cout << result; */
	/*Formeln för transformeringen 
	är fahrenheit = ( 9 / 5 ) * celsius + 32 */
	double celsius, fahrenheit;

	std::cout << "Ange temperatur i Celsius: ";
	std:: cin >> celsius;

	fahrenheit = (9.0 / 5.0) * celsius + 32.0;

	std::cout << celsius << " grader Celsius motsvarar " << fahrenheit << " grader Fahrenheit.";


	return 0;
}