/*
 Files:
	eea.cpp
 
 Title:
	ExtendedEuclideanAlgorithmC++
 
 Language:
	C++
 
 Author:
	Louis Jannett
 
 Version:
	2.1
 
 Date:
	Jan 2017
 
 Important:
	compile with C++11, e.g. $ g++ -std=c++11 -o eea eea.cpp
 
 Note/Installation: 
	You can copy the executable binary to your shell's search path. Execute following command in your Terminal:
	$ mkdir ~/bin
	$ g++ -std=c++11 -o eea <PATH TO YOUR EEA.CPP>
	$ echo "export PATH=$PATH:/Users/<YOUR USERNAME>/bin" >> .bash_profile
	Your bin directory can now include all executable files, which can be executed directly via the terminal.
 
 Description:
	This little programm executes the Extended Euclidean Algorithm. This algorithm computes the great common divisor and especially the multiplicative inverse. With the multiplicative inverse, one can find an element x such that y * x^-1 == 1 mod n. Of course, all calculations are done modulo n. The input values of this algorithm are the modulus n and the element y in the group of n. X is now called the "multiplicative inverse of y mod n". This arithmetic is very important for cryptographic implementations. Important: If the great common divisor of the element and the modulo is not 1, then the element has no multiplicative inverse!  
 
 eMail: 
	louisjannett@icloud.com
	PGP public key is located on my website.
 
 Website:
	www.louisjannett.de

*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>

bool validInput();

/**
 check if strings are valid long long integers

 @param input string, which is going to be checked
 @return returns true if string is valid, false if string is invalid
 */
bool validInput(char *input){
	for (int i = 0; i < strlen(input); i++){
			if (!isdigit(input[i])){
			std::cout << "ERROR: Please choose a valid positive integer." << std::endl;
			return false;
		}
	}
	if (strlen(input) > 19){
		std::cout << "ERROR: Please choose a smaller number." << std::endl;
		return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	
	/**
	 Display the help page

	 @param argv just one argument "help"
	 @param "help" if parameter is help
	 @return exits the programm
	 */
	if (argc == 2 && strcmp(argv[1],"help") == 0){
		std::cout << "eea.cpp" << std::endl << "©2017, Louis Jannett" << std::endl << "Executes the Extended Euclidean Algorithm and computes the great common divisor and the multiplicative inverse with modular arithmetic" << std::endl << "Use this format: \"eea NUMBER1 NUMBER2\"" << std::endl << "Use \"eea help\" to get more informations." << std::endl;
		return 0;
	}
	
	if (argc != 3){
		std::cout << "Syntax Error: Use <./eea NUMBER1 NUMBER2>" << std::endl;
		return 0;
	}
	
	//init
	
	std::vector<long long int> r;
	std::vector<long long int> s;
	std::vector<long long int> t;
	std::vector<long long int> q;
	
	int size = 2;
	int i = 1;
	
	r.resize(size);
	s.resize(size);
	t.resize(size);
	q.resize(size);
	
	s[0] = 1;
	t[0] = 0;
	s[1] = 0;
	t[1] = 1;
	
	//check if input is valid
	if (!validInput(argv[1])){
		return 0;
	}
	if (!validInput(argv[2])){
		return 0;
	}
	
	//input from the arguments
	r[0] = atoll(argv[1]);
	r[1] = atoll(argv[2]);
	
	//change order of input numbers, higher number comes first
	if (r[0] < r[1]) {
		long swp;
		swp = r[0];
		r[0] = r[1];	
		r[1] = swp;
	}

	//execute the extended euclidean algorithm
	do {
		i = i+1;
		
		//resize the vector and add one element per vector
		size++;
		r.resize(size);
		s.resize(size);
		t.resize(size);
		q.resize(size);
		
		r[i] = r[i-2] % r[i-1];
		q[i-1] = (r[i-2]-r[i]) / r[i-1];
		s[i] = s[i-2] - (q[i-1] * s[i-1]);
		t[i] = t[i-2] - (q[i-1] * t[i-1]);
	} while (r[i] != 0);
	
	//check if inverse is < 0 and if so, calculate mod n to display positive inverse
	if(s[i-1] < 0){
		s[i-1] = s[i-1] + r[0];
	}
	if(t[i-1] < 0){
		t[i-1] = t[i-1] + r[0];
	}

	//output of the result
	std::cout << "Input = " << r[0] << ", " << r[1] << std::endl;
	std::cout << "gcd   = " << r[i-1] << std::endl;
	std::cout << "s     = " << s[i-1] << std::endl;
	std::cout << "t     = " << t[i-1] << std::endl;

	return 0;
}
