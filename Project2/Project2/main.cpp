#include <iostream>
#include <vector>
#include "VehicleInfo.h"

bool TEST_MODE_REG_SEARCH = false;

enum argIndexes
{
    START = 0,
    COMMAND_INDEX,
    SEARCH_VAR_INDEX,
};


int main(int argc, char* argv[])
{
    VehicleInfo VehicleObj;

    std::vector<VehicleInfo> vVehicleList;
    std::vector<std::string> testRegList;

    vVehicleList.push_back(VehicleObj.CreateVehicleEntry("AB01 CDE", 2001, 12345));
    vVehicleList.push_back(VehicleObj.CreateVehicleEntry("EG02 HJK", 2002, 67890));
    vVehicleList.push_back(VehicleObj.CreateVehicleEntry("L33T H4XOR", 2022));
    vVehicleList.push_back(VehicleObj.CreateVehicleEntry());
    
    if (argc > COMMAND_INDEX && std::strcmp(argv[COMMAND_INDEX], "TestRegSearch") == 0)
    {
        TEST_MODE_REG_SEARCH = true;
    }

    if (TEST_MODE_REG_SEARCH)
    {
        testRegList.push_back("AB01 CDE");
        testRegList.push_back("EG02 HJK");
        testRegList.push_back("L33T H4XOR");
        testRegList.push_back("");
    }

    if ((argc > COMMAND_INDEX && std::strcmp(argv[COMMAND_INDEX],"RegCount") == 0))
    {
        size_t count = VehicleObj.VehicleCount(vVehicleList);
        std::cout << "Total Registration Numbers = " << count << std::endl;
    }
    else if (TEST_MODE_REG_SEARCH || (argc > SEARCH_VAR_INDEX && std::strcmp(argv[COMMAND_INDEX], "FindID") == 0))
    {
        if (argv[SEARCH_VAR_INDEX] == NULL && !TEST_MODE_REG_SEARCH)
        {
            std::cout << "NO REG ENTERED, PLEASE ENTER REGISTRATION NUMBER AFTER COMMAND Eg. 'AB01 CDE' " << std::endl;
        }
        else
        {
            std::string reg;
            size_t searchIndex = 0;

            if (TEST_MODE_REG_SEARCH)
            {
                searchIndex = testRegList.size()-1;
            }

            while (searchIndex != -1)
            {
                if (TEST_MODE_REG_SEARCH)
                {
                    reg = testRegList[searchIndex];
                    
                }
                else
                {
                    reg = argv[SEARCH_VAR_INDEX];
                }

                int vID = VehicleObj.FindVehicle(vVehicleList, reg);

                if (vID == -1)
                {
                    std::cout << "VEHICLE REG NOT FOUND OR NO VALID VEHICLE ID" << std::endl;
                }
                else
                {
                    std::cout << "VehicleID Found = " << vID << std::endl;
                }
                searchIndex--;
            }
        }
    }
    else
    {
        std::cout << "INVALID COMMAND" << std::endl;
        std::cout << "VALID COMMANDS:" << std::endl;
        std::cout << "FindID 'REG'" << std::endl;
        std::cout << "RegCount" << std::endl;
    }

    vVehicleList.clear();
    return 0;
}