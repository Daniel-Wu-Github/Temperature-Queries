# include "TemperatureData.h"
using std::string;

TemperatureData::TemperatureData() /* TODO */ : id(""), year(0), month(0), temperature(-99.99){
	// TODO: implement this function
}

TemperatureData::TemperatureData(string id, int year, int month, double temperature) /* TODO */ : id(id), year(year), month(month), temperature(temperature){
	// TODO: implement this function
}

TemperatureData::~TemperatureData() {}

bool TemperatureData::operator<(const TemperatureData& b) {
    // TODO: implement this function
    if(this->id != b.id){
        return this->id < b.id;
    }
    else if(this->year != b.year){
        return this->year < b.year;
    }
    else if(this->month != b.month){
        return this->month < b.month;
    }
    else{
        return this->temperature < b.temperature;
    }
}

