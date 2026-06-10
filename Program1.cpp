#include <iostream>
#include <string>
using namespace std;

string customerName;
int customerID;
string customerType;
int meterChoice;

void registerCustomer();
void displayMenu();
double calculateConsumptionCharges(int units);
double calculateGST(double amount);
double calculateIncomeTax(double amount);
double calculateElectricityDuty(double consumption);
double calculateFixedCharges(int units);
double calculateNewConnectionCharges();
void displayFinalBill();
void displayCustomerDetails();

int main()
{
    registerCustomer();

    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayFinalBill();
                break;

            case 2:
                cout << "\nNew Connection Charges: Rs. "
                     << calculateNewConnectionCharges() << endl;
                break;

            case 3:
                displayCustomerDetails();
                break;

            case 4:
                cout << "\nThank you for using LESCO System.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}

void registerCustomer()
{
    cout << "========== LESCO CUSTOMER REGISTRATION ==========\n";

    cout << "Enter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);

    cout << "Enter Customer ID: ";
    cin >> customerID;

    cout << "Enter Customer Type (Household/Commercial): ";
    cin >> customerType;

    cout << "Meters Already Installed\n";
    cout << "1. First Meter\n";
    cout << "2. Second Meter\n";
    cout << "Enter Choice: ";
    cin >> meterChoice;
}

void displayMenu()
{
    cout << "\n========== MAIN MENU ==========\n";
    cout << "1. Calculate Monthly Electricity Bill\n";
    cout << "2. Apply for New Electricity Connection\n";
    cout << "3. View Customer Details\n";
    cout << "4. Exit Program\n";
    cout << "Enter Choice: ";
}

double calculateConsumptionCharges(int units)
{
    double rates[8] = { 12.21, 14.53, 31.51, 38.41, 41.62, 43.04, 44.18, 49.10};

    double charges = 0;

    if(units <= 100)
        charges = units * rates[0];

    else if(units <= 200)
        charges = units * rates[1];

    else if(units <= 300)
        charges = units * rates[2];

    else if(units <= 400)
        charges = units * rates[3];

    else if(units <= 500)
        charges = units * rates[4];

    else if(units <= 600)
        charges = units * rates[5];

    else if(units <= 700)
        charges = units * rates[6];

    else
        charges = units * rates[7];

    return charges;
}

double calculateGST(double amount)
{
    return amount * 0.18;
}

double calculateIncomeTax(double amount)
{
    if(customerType == "Household" || customerType == "household")
        return amount * 0.10;
    else
        return amount * 0.15;
}

double calculateElectricityDuty(double consumption)
{
    return consumption * 0.015;
}

double calculateFixedCharges(int units)
{
    if(units >= 301 && units <= 400)
        return 200;

    else if(units >= 401 && units <= 500)
        return 400;

    else if(units >= 501 && units <= 600)
        return 600;

    else if(units >= 601 && units <= 700)
        return 800;

    else if(units > 700)
        return 1000;

    return 0;
}

double calculateNewConnectionCharges()
{
    double meterCost;
    double cableCost;
    double securityCost;
    double additionalCharges;

    cout << "\nEnter Meter Cost: ";
    cin >> meterCost;

    cout << "Enter Meter Cable Cost: ";
    cin >> cableCost;

    cout << "Enter Security Cost: ";
    cin >> securityCost;

    if(customerType == "Household" || customerType == "household")
    {
        if(meterChoice == 1)
            additionalCharges = 2500;
        else
            additionalCharges = 5000;
    }
    else
    {
        if(meterChoice == 1)
            additionalCharges = 35000;
        else
            additionalCharges = 70000;
    }

    char properConnection;

    cout << "Apply for Proper Connection? (Y/N): ";
    cin >> properConnection;

    double total = meterCost + cableCost + securityCost + additionalCharges;

    if(properConnection == 'Y' || properConnection == 'y')
        total += 250000;

    return total;
}
void displayFinalBill()
{
    int units;

    cout << "\nEnter Units Consumed: ";
    cin >> units;

    double consumption = calculateConsumptionCharges(units);

    double duty = calculateElectricityDuty(consumption);

    double fixedCharges = calculateFixedCharges(units);

    double meterRent = 250;
    double tvFee = 35;

    double subTotal = consumption + duty + fixedCharges + meterRent + tvFee;

    double gst = calculateGST(subTotal);

    double incomeTax = calculateIncomeTax(subTotal);

    double finalBill = subTotal + gst + incomeTax;

    cout << "\n========== ELECTRICITY BILL ==========\n";
    cout << "Consumption Charges : Rs. " << consumption << endl;
    cout << "Electricity Duty    : Rs. " << duty << endl;
    cout << "Fixed Charges       : Rs. " << fixedCharges << endl;
    cout << "Meter Rent          : Rs. " << meterRent << endl;
    cout << "TV Fee              : Rs. " << tvFee << endl;
    cout << "GST (18%)           : Rs. " << gst << endl;
    cout << "Income Tax          : Rs. " << incomeTax << endl;
    cout << "--------------------------------------\n";
    cout << "Total Bill          : Rs. " << finalBill << endl;
}
void displayCustomerDetails()
{
    cout << "\n========== CUSTOMER DETAILS ==========\n";

    cout << "Customer Name : " << customerName << endl;
    cout << "Customer ID   : " << customerID << endl;
    cout << "Customer Type : " << customerType << endl;

    if(meterChoice == 1)
        cout << "Meter Status  : First Meter\n";
    else
        cout << "Meter Status  : Second Meter\n";
}
