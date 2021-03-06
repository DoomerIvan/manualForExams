#include "Menu.h"
#include "Color.h"
#include "Main.h"

using namespace std;
using namespace ECC;

string txtFilesFolder = "txtFiles/";
string fileExtension = ".txt";

int countOfTopic() {
	int count = 0;
	char fileStream;

	fstream allPuncts("qList.txt");
	while (allPuncts.get(fileStream)) {
		if (fileStream == '\n') {
			count++;
		}
	}
	allPuncts.close();

	return count + 1;
}

string chooseFile() {
    int j = 0;
	int Puncts = countOfTopic();
	
	string drawnPoint = "-> ";
	fstream allPuncts("qList.txt");
	string jLocation;

	string* punctsList = new string[Puncts];

	for (int i = 0; i < Puncts; i++) {
		getline(allPuncts, punctsList[i]);
	}
	

	for (int i = 0; i < Puncts; i++) {
		if (i == j) {
			ECC::setColor(Yellow, Black);
			cout << setw(5) << drawnPoint + punctsList[i] << endl;
			setColor(White, Black);
		}
		else {
			cout << setw(5) << punctsList[i] << endl;
		}
	}

	char selectingFile = 'a';

	while (selectingFile != 13) {
		selectingFile = _getch();
		system("cls");
		if (selectingFile == 's') {
			j++;
			if (j >= Puncts) {
				j = 0;
			}
		}
		if (selectingFile == 'w') {
			j--;
			if (j < 0) {
				j = Puncts;
			}
		}
		for (int i = 0; i < Puncts; i++) {
			if (i == j) {
				setColor(Yellow, Black);
				cout << drawnPoint + punctsList[i] << endl;
				setColor(White, Black);
			}
			else {
				cout << setw(5) << punctsList[i] << endl;
			}
		}
		jLocation = to_string(j+1);
	}
	allPuncts.close();
	delete [] punctsList;
	return jLocation;
}
void openChoosedFile() {
	string choose = chooseFile();

	string chooseFix = choose;

	choose = txtFilesFolder + choose + fileExtension; // (j+1)+.txt
	fstream task(choose);

	system("cls"); //clear window

	char fileStream;

	outputThemeName(chooseFix);

	while (task.get(fileStream)) {
		cout << fileStream;
	}

	task.close();

	char enterWaiting = 'a';

	while (enterWaiting != 13) {
		enterWaiting = _getch();
	}

	system("cls");
	main();
}
void txtFilesCreator() {
	string fileAddress;
	int fileCount = countOfTopic();
	for (int i = 0; i < fileCount; i++) {
		fileAddress = txtFilesFolder + to_string(i+1) + fileExtension;
		ofstream checkAvailability(fileAddress, ios_base::app);
		checkAvailability.close();
	}
}

void outputThemeName(string chooseTheme) {
	int themeNumber = atoi(chooseTheme.c_str());

	int Puncts = countOfTopic();

	fstream allPuncts("qList.txt");

	string* punctsList = new string[Puncts];

	for (int i = 0; i <= Puncts; i++) {
		getline(allPuncts, punctsList[i]);
		if (i == themeNumber) {
			setColor(Yellow, Black);
			cout << setw(5) << punctsList[i - 1] << endl;
			setColor(White, Black);
		}
	}

	delete[] punctsList;
	allPuncts.close();
}