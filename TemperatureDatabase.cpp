# include "TemperatureDatabase.h"
# include <fstream>
# include <iostream>
# include <string>
# include <sstream>

using std::cout, std::endl, std::string, std::ofstream;

TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// TODO: implement this function
	std::ifstream currentFile(filename);
	if (!currentFile.is_open()) {
    cout << "Error: Unable to open " << filename << endl;
    return;
	}
	string id;
	int year;
	int month;
	double temperature;
	string dataEntry;

	while (std::getline(currentFile, dataEntry)) {
		std::istringstream iss(dataEntry);
		if (!(iss >> id >> year >> month >> temperature)) {
			cout << "Error: Other invalid input" << endl;
			continue;
		}

		bool isValidId = true;
		for(int i = 0; i < id.length(); i++){
			if(id[i] < '0' || id[i] > '9'){
				isValidId = false;
				break;
			}
		}

		if (!isValidId) {
			cout << "Error: Invalid id " << id << endl;
		}
		if (year < 1800 || year > 2024) {
			cout << "Error: Invalid year " << year << endl;
		}
		if (month < 1 || month > 12) {
			cout << "Error: Invalid month " << month << endl;
		}
		if (temperature < -50 || temperature > 50 || temperature == -99.99) {
			cout << "Error: Invalid temperature " << temperature << endl;
		}

		if (isValidId && year >= 1800 && year <= 2024 && month >= 1 && month <= 12 && temperature >= -50 && temperature <= 50 && temperature != -99.99) {
			records.insert(id, year, month, temperature);
		}
	}
	currentFile.close();
}

void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}

	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
}
