#Extended Euclidean Algorithm

---

##Files
eea.cpp

##Title
ExtendedEuclideanAlgorithmC++

##Language
C++
 
##Author
Louis Jannett

##Version
2.1
 
##Date
Jan 2017
 
##Important
compile with C++11, e.g. $ g++ -std=c++11 -o eea eea.cpp
 
##Note/Installation 
You can copy the executable binary to your shell's search path. Execute following command in your Terminal:
	$ mkdir ~/bin
	$ g++ -std=c++11 -o eea <PATH TO YOUR EEA.CPP>
	$ echo "export PATH=$PATH:/Users/<YOUR USERNAME>/bin" >> .bash_profile
Your bin directory can now include all executable files, which can be executed directly via the terminal.

##Description
This little programm executes the Extended Euclidean Algorithm. This algorithm computes the great common divisor and especially the multiplicative inverse. With the multiplicative inverse, one can find an element x such that y * x^-1 == 1 mod n. Of course, all calculations are done modulo n. The input values of this algorithm are the modulus n and the element y in the group of n. X is now called the "multiplicative inverse of y mod n". This arithmetic is very important for cryptographic implementations. Important: If the great common divisor of the element and the modulo is not 1, then the element has no multiplicative inverse!  

--- 

##eMail
louisjannett@icloud.com
PGP public key is located on my website.
 
##Website
www.louisjannett.de
