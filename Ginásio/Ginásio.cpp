#include "stdafx.h"
#include "Gym.h"
#include "PersonalTrainer.h"
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void mainMenu(Gym &gym);
Gym * readInformationFile(std::string fileName);
void writeInformationFile(std::string fileName, Gym & gym);

int main()
{
	Gym * FitnessMx= readInformationFile("File.txt");
	FitnessMx->login();
	mainMenu(*FitnessMx);
	writeInformationFile("File.txt", *FitnessMx);
	return 0;
}

