#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cerrno>
#include <vector>

void reverse (char* bs, const char* as) {
	unsigned int ai = strlen(as) - 1;
	unsigned int bi = 0;
	
	for(unsigned int i = 0; i < strlen(as); i++){
		bs[bi++] = as[ai--];
		bs[bi] = 0;
	}
}

bool isPalindrome (const char* str) {
	unsigned int i = strlen(str) - 1;
	if(i == 0)	return true;
	unsigned int j = 0;
	while (i >= j) {
		if(str[i--] != str[j++])	return false;
	}
	return true;
}

void processLine (std::string& line) {
	int iterations	= 0;
	
	unsigned int ai;
	char as[11];
	strcpy(as,line.c_str());
	if(!sscanf(as,"%d",&ai))	return;

	unsigned int bi;
	char bs[11];
	
	for(iterations = 1; iterations <= 100; iterations++){
		reverse(bs,as);
		sscanf(bs,"%d",&bi);
		ai	+= bi;
		
		sprintf(as,"%d",ai);
		if(isPalindrome(as)){
			std::cout << iterations << " " << as << "\n";
			return;
		}
	}
	
	return;
}


int main(int argc, char **argv)
{
	std::ifstream file;
	std::string line;
	file.open (argv[1]);

	if(file.good()){
		while(std::getline(file,line)){
			processLine(line);
		}
	}else{
		std::cout << strerror(errno) << "\n";
		std::cout << "Could not open " << argv[1] << "\n";
	}

	return 0;
}
