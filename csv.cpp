// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
class DateAndValueCSVData{

public:
	DateAndValueCSVData(std::istream& str){
		std::string v;
		std::string sdate ;
		std::string line;
		std::getline(str, line);
		char delim = ',';
		row_count = 0;
		while (str){
			std::getline(str, line);
		    std::stringstream s(line);
			std::getline(s, sdate, delim);
			std::getline(s, v, delim);
			value.push_back(std::stod(v));
			date.push_back(sdate);
			row_count++;
		}
	}
	double ValueAt(int index){
		return value[index];
	}
	std::string DateAt(int index){
		return date[index];
	}
	//return the Values` vector as array
	double* GetValueArray(){
		return &value[0];
	}
	int count(){
		return row_count;
	}
private:
	std::vector<std::string> date;
	std::vector<double> value;
	int row_count;
};

int _tmain(int argc, _TCHAR* argv[])
{
	int i = 0;
	std::ifstream str;
	//full path to the file
	str.open("c:\csvtest.csv",std::ios::in);
	DateAndValueCSVData csv(str);
	std::cout << csv.DateAt(0)<<std::endl;
	std::cout << csv.GetValueArray()[2];
	std::cin >> i;
	return 0;
}

