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
    std::vector<VehicleInfo> vVehicleList;
    std::vector<std::string> testRegList;

    //Populate Vector with vehicle data
    vVehicleList.push_back(VehicleInfo("AB01 CDE", 2001, 12345));
    vVehicleList.push_back(VehicleInfo("EG02 HJK", 2002, 67890));
    vVehicleList.push_back(VehicleInfo("L33T H4XOR", 2022));
    vVehicleList.push_back(VehicleInfo());
    
    //Check if software is run with test command
    if (argc > COMMAND_INDEX && std::strcmp(argv[COMMAND_INDEX], "TestRegSearch") == 0)
    {
        TEST_MODE_REG_SEARCH = true;
    }

    //Populate a vector used to test the functionality of the reg search feature
    if (TEST_MODE_REG_SEARCH)
    {
        testRegList.push_back("AB01 CDE");
        testRegList.push_back("EG02 HJK");
        testRegList.push_back("L33T H4XOR");
        testRegList.push_back("");
    }

    //Check if software is run with Registration Number count command
    if ((argc > COMMAND_INDEX && std::strcmp(argv[COMMAND_INDEX],"RegCount") == 0))
    {
        size_t count = VehicleInfo::VehicleCount(vVehicleList);
        std::cout << "Total Registration Numbers = " << count << std::endl;
    }
    else if (TEST_MODE_REG_SEARCH || (argc > SEARCH_VAR_INDEX && std::strcmp(argv[COMMAND_INDEX], "FindID") == 0)) //Check if software is run with Registration Search command
    {
        //Check if there is a valid argument 
        if (argv[SEARCH_VAR_INDEX] == NULL && !TEST_MODE_REG_SEARCH)
        {
            std::cout << "NO REG ENTERED, PLEASE ENTER REGISTRATION NUMBER AFTER COMMAND Eg. 'AB01 CDE' " << std::endl;
        }
        else
        {
            std::string reg;
            size_t searchIndex = 0;

            //While for looping through strings passed for testing. One iteration for normal function
            while (!TEST_MODE_REG_SEARCH && searchIndex != 1 || TEST_MODE_REG_SEARCH && searchIndex != testRegList.size())
            {
                if (TEST_MODE_REG_SEARCH)
                {
                    reg = testRegList[searchIndex];
                    
                }
                else
                {
                    reg = argv[SEARCH_VAR_INDEX];
                }

                int vID = VehicleInfo::FindVehicle(vVehicleList, reg);

                if (vID == -1)
                {
                    std::cout << "VEHICLE REG NOT FOUND OR NO VALID VEHICLE ID" << std::endl;
                }
                else
                {
                    std::cout << "VehicleID Found = " << vID << std::endl;
                }
                searchIndex++;
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