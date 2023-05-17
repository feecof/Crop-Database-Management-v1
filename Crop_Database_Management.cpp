#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int userInputChoice;
    cout << "1.) To input additional data into the Database." << endl;
    cout << "2.) To search for an already existing item." << endl;
    cout << "Choose a suitable operation to proceed: ";
    cin >> userInputChoice;
    cin.ignore();

    if (userInputChoice == 1)
    {
        fstream fout;
        fout.open("example.csv", ios::out | ios::app);

        string serialNumber, cropID, cropName, season, region;
        cout << "Enter Serial Number: ";
        getline(cin, serialNumber);
        cout << "Enter crop ID: ";
        getline(cin, cropID);
        cout << "Enter crop name: ";
        getline(cin, cropName);
        cout << "Enter season/Month: ";
        getline(cin, season);
        cout << "Enter region: ";
        getline(cin, region);

        string farmID, farmerName, pincode, gender, totalAreaOfFarm, varietyOfCropsCultivated,
            geographicalCoordinates, fertilizerDetails, yield,
            sellingPrice;

        cout << "Enter farm ID: ";
        getline(cin, farmID);
        cout << "Enter farmer name: ";
        getline(cin, farmerName);
        cout << "Enter pincode: ";
        getline(cin, pincode);
        cout << "Enter gender: ";
        getline(cin, gender);
        cout << "Enter total area of farm: ";
        getline(cin, totalAreaOfFarm);
        cout << "Enter variety of crops: ";
        getline(cin, varietyOfCropsCultivated);
        cout << "Enter fertilizer details: ";
        getline(cin, fertilizerDetails);
        cout << "Enter yield: ";
        getline(cin, yield);
        cout << "Enter selling price: ";
        getline(cin, sellingPrice);

        string productID, packSerialNo, batchNo, netWeight, grossWeight;
        cout << "Enter product ID:";
        getline(cin, productID);
        cout << "Enter pack serial no:";
        getline(cin, packSerialNo);
        cout << "Enter batch no:";
        getline(cin, batchNo);
        cout << "Enter net weight:";
        getline(cin, netWeight);
        cout << "Enter gross weight:";
        getline(cin, grossWeight);

        fout
            << serialNumber << ","
            << cropID << ","
            << cropName << ","
            << season << ","
            << region << ","
            << farmID << ","
            << farmerName << ","
            << pincode << ","
            << gender << ","
            << totalAreaOfFarm << ","
            << varietyOfCropsCultivated << ","
            << fertilizerDetails << ","
            << yield << ","
            << sellingPrice << ","
            << productID << ","
            << packSerialNo << ","
            << batchNo << ","
            << netWeight << ","
            << grossWeight << endl;

        fout.close();
    }

    else if (userInputChoice == 2)
    {
        // Get user input for crop ID
        string cropID;
        cout << "Enter the crop ID: ";
        getline(cin, cropID);

        // Open the CSV file
        ifstream infile("example.csv");

        // Check if the file was opened successfully
        if (!infile.is_open())
        {
            cerr << "Error: Failed to open file" << endl;
            return 1;
        }

        // Read the file into a vector of vectors
        vector<vector<string>> data;
        string line;
        while (getline(infile, line))
        {
            vector<string> row_data;
            stringstream ss(line);
            string token;
            while (getline(ss, token, ','))
            {
                row_data.push_back(token);
            }
            data.push_back(row_data);
        }

        // Search for the crop ID in the file
        bool found = false;
        for (size_t i = 0; i < data.size(); i++)
        {
            if (data[i][1] == cropID)
            {
                found = true;

                const int width = 25;
                cout << "\n";
                cout << left << setw(width) << "Crop Name: " << data[i][2] << endl;
                cout << left << setw(width) << "Season/Month: " << data[i][3] << endl;
                cout << left << setw(width) << "Region: " << data[i][4] << endl;
                cout << left << setw(width) << "Farm ID: " << data[i][5] << endl;
                cout << left << setw(width) << "Farmer Name: " << data[i][6] << endl;
                cout << left << setw(width) << "Pincode: " << data[i][7] << endl;
                cout << left << setw(width) << "Gender: " << data[i][8] << endl;
                cout << left << setw(width) << "Total Area of Farm: " << data[i][9] << endl;
                cout << left << setw(width) << "Variety of Crops: " << data[i][10] << endl;
                cout << left << setw(width) << "Fertilizer Details: " << data[i][11] << endl;
                cout << left << setw(width) << "Yield: " << data[i][12] << endl;
                cout << left << setw(width) << "Selling Price: " << data[i][13] << endl;
                cout << left << setw(width) << "Product ID: " << data[i][14] << endl;
                cout << left << setw(width) << "Pack Serial No: " << data[i][15] << endl;
                cout << left << setw(width) << "Batch No: " << data[i][16] << endl;
                cout << left << setw(width) << "Net Weight: " << data[i][17] << endl;
                cout << left << setw(width) << "Gross Weight: " << data[i][18] << endl;
                cout << "\n";
                break;
            }
        }

        if (!found)
        {
            cout << "Error: Crop ID not found in the database" << endl;
            return 1;
        }
    }

    else
    {
        cout << "Error: Invalid input, Please choose between 1 & 2." << endl;
        return 1;
    }

    return 0;
}