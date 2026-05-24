#include "VehicleInfo.h"

VehicleInfo::VehicleInfo()
{
	m_registrationNumber = "";
	m_vear = 0;
	m_vehicleID = 0;
}

VehicleInfo::~VehicleInfo()
{
	m_registrationNumber.clear();
	m_vear = NULL;
	m_vehicleID = NULL;
}

VehicleInfo VehicleInfo::CreateVehicleEntry(const std::string regNum, const size_t year, const int vID)
{
	VehicleInfo newCar;

	newCar.m_registrationNumber = regNum;
	newCar.m_vear = year;
	newCar.m_vehicleID = vID;

	return newCar;
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