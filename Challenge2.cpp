#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int stringToInt(std::string x);
int pow10(int x);
void sortAndFind(std::vector<int>);

int main() {
	std::string x,whole;
	char delimeter = ',';
	std::vector< std::vector<int>* > setOfSets;
	
	//put all numbers into the vectors 
	while (std::getline(std::cin, whole)){
		if (whole.empty()) { break; }
		
		std::vector<int> *set = new std::vector<int>;
		for (int i = 0; i < whole.size(); i++){
			bool wholeNumberFound = (whole[i] == delimeter || i == (whole.size() - 1));
			if (whole[i] != delimeter){
				x += whole[i];
			}
			if (wholeNumberFound){
				set->push_back(stringToInt(x));
				x = "";
			}
		}
		setOfSets.push_back(set);
		whole = "";
	}
	
	//for each set of numbers, find the missing one.
	for (auto iter = setOfSets.begin(); iter != setOfSets.end(); iter++){
		sortAndFind(**iter);
	}
	return 0;
}

int stringToInt(std::string x){
	//Converts the string to the integer
	long int z = 0;
	for (int i = 0; i < x.length(); i++){
		z += (static_cast<int>(static_cast<char>(x[x.length()-1-i])) - 48) * (pow10(i));
	}
	return z;
}

int pow10(int x){
	//Custom power function because the built-in one from math was acting up...
	if (x == 0){return 1;}
	return 10 * pow10(x - 1);
}

void sortAndFind(std::vector<int> set) {
	std::sort(set.begin(), set.end());
	for (int i = 0; i < set.size(); i++){
		if (set[i] + 2 == set[i+1]){
			std::cout << set[i] + 1 << std::endl;
		}
	}
}
