#pragma once
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm>

class VehicleInfo
{
public:
	VehicleInfo();
	~VehicleInfo();
	VehicleInfo CreateVehicleEntry(const std::string regNum = "", const size_t year = NULL, const int vID = NULL);
	size_t VehicleCount(const std::vector<VehicleInfo> vVehicleList);
	int FindVehicle(const std::vector<VehicleInfo> vVehicleList, const std::string regNum);
private:
	
	std::string m_registrationNumber;
	size_t m_vear;
	int m_vehicleID;
};
                 