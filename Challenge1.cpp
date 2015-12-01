#include <iostream>

int main() {
	for (int i = 1; i <= 100; i++){
		if (i % 3 == 0){
			std::cout << "Fire";
		}
		if (i % 7 == 0 && i % 3 == 0){
			std::cout << " and ";
		}
		if (i % 7 == 0){
			std::cout << "Ice";
		}
		if (!((i % 3 == 0) || (i % 7 == 0))){
			std::cout << i;
		}
		std::cout << std::endl;
	}
}
