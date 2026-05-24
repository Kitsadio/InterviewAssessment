#pragma once
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

class VehicleInfo
{
public:
	VehicleInfo(const std::string regNum = "", const size_t year = NULL, const int vID = NULL);
	~VehicleInfo();
	static size_t VehicleCount(const std::vector<VehicleInfo> vVehicleList);
	static int FindVehicle(const std::vector<VehicleInfo> vVehicleList, const std::string regNum);
private:
	
	std::string m_registrationNumber;
	size_t m_vear;
	int m_vehicleID;
};
                 