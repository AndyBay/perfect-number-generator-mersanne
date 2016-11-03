#include <iostream>
#include <cmath>

bool samePrimeFactor(unsigned long long m, unsigned long long c);

int main() {
	unsigned long long 	i = 1, 
						mersenne,
						candidate;
						
	std::cout << "\nFinds candidates using <<mersenne>> and checks if they"
			  << " are valid.\nProceeds to print out the <<perfect numbers>>"
			  << " until the amount of \ndigits overreaches its variable.\n";
						
	do {
		i++;
		mersenne = (pow(2, i) - 1);
		candidate = (pow(2, i-1)) * mersenne;
		
		if (samePrimeFactor(mersenne, candidate)){
			std::cout << "\nPerfect number: " << candidate;
			if (mersenne < 999) std::cout << '\t';
			if (mersenne < 999999) std::cout << '\t';
			std::cout << "\twith mersenne: " << mersenne;
		}
		
	} while (candidate != 0);
	
	return 0;
}

bool samePrimeFactor(unsigned long long m, unsigned long long c) {
	
	unsigned long long i = 2;

	while (i*i <= c) {
		if (c % i == 0) 
			c /= i;
		else
			i++;
	}
	if (c == m)
		return 1;
	
	return 0;
}
