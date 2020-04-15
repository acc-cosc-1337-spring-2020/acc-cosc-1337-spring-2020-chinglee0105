#include "temperature.h"
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

#ifndef TEMPERATURE_DATA_H
#define TEMPERATURE_DATA_H

//temperature_data.h
class TemperatureData {

public:
	void save_temps(vector<Temperature>& ts);
	vector<Temperature> get_temps() const;

private:
	const string file_name{ "temperature.dat" };
};

#endif