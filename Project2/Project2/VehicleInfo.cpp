#include "VehicleInfo.h"

VehicleInfo::VehicleInfo(const std::string regNum, const size_t year, const int vID)
{
	m_registrationNumber = regNum;
	m_vear = year;
	m_vehicleID = vID;
}

VehicleInfo::~VehicleInfo()
{
	m_registrationNumber.clear();
	m_vear = NULL;
	m_vehicleID = NULL;
}

size_t VehicleInfo::VehicleCount(const std::vector<VehicleInfo> vVehicleList)
{
	size_t count = std::count_if(vVehicleList.begin(), vVehicleList.end(), [](const VehicleInfo &temp)
		{return !temp.m_registrationNumber.empty();});

	return count;
}

int VehicleInfo::FindVehicle(const std::vector<VehicleInfo> vVehicleList, const std::string regNum)
{
	int vID = -1;

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