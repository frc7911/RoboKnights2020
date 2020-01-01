#include "utilities/RoboKnights.h"


//Class Instanciation
RoboKnights::RoboKnights(){}

//Reads the file into an array for processing
void RoboKnights::ReadFile()
{
    ifstream fp;
    string line, value, name;
    fp.open("/home/lvuser/RoboKnights.cfg",ios_base::in);
    if(fp.is_open())
    {
        //While lines can still be gotten...
        while( getline(fp, line) )
        {
            for(int i = 0; i < line.length(); i++)
            {
                if(line[i] == '=')
                {
                    name = line.substr(0, i);
                    value = line.substr(i + 1, line.length());
                }
            }
            names->append(name);
            values->append(value);
        }
        fp.close();
    }else
    {
        std::cout << "Error While Opening File! \n";
    }
}

//Returns the value for a specific config line
string RoboKnights::GetValue(string sName)
{
    string sValue = "";
    for(int i = 0; i < names->size(); i++)
    {
        std::cout << "Test: " + names[i];
        if(names[i] == sName)
        {
            sValue = values[i];
            break;
        }
    }
    //Locate sName in Name array
    //Get the values stored at the same location in the Name array
    return sValue;
}

//Sets the values for a specific config line
void RoboKnights::SetValue(string sName, int iValue){}
