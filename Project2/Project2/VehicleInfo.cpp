#include "VehicleInfo.h"

//Constructor
VehicleInfo::VehicleInfo(const std::string regNum, const size_t year, const int vID)
{
	m_registrationNumber = regNum;
	m_vear = year;
	m_vehicleID = vID;
}

//Deconstructor 
VehicleInfo::~VehicleInfo()
{
	m_registrationNumber.clear();
	m_vear = NULL;
	m_vehicleID = NULL;
}

size_t VehicleInfo::VehicleCount(const std::vector<VehicleInfo> vVehicleList)
{
	//Loop through vector of Vehicles, count only if registration number has data
	size_t count = std::count_if(vVehicleList.begin(), vVehicleList.end(), [](const VehicleInfo &temp)
		{return !temp.m_registrationNumber.empty();});

	return count;
}

int VehicleInfo::FindVehicle(const std::vector<VehicleInfo> vVehicleList, const std::string regNum)
{
	int vID = -1;

	//Loop through vehicles and compare the regNum argument with the data. If match is found, return related vID.
	for (const auto& temp : vVehicleList)
	{
		if (std::strcmp(temp.m_registrationNumber.c_str(), regNum.c_str()) == 0)
		{
			if (temp.m_vehicleID != NULL)
			{
				vID = temp.m_vehicleID;
			}
			break;
		}
	}

	return vID;
}