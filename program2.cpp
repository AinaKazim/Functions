#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string customerName;
string contactNumber;
string orderType;
int persons;

string foodItems[8] = {
    "Chicken Burger",
    "Zinger Burger",
    "Pizza Small",
    "Pizza Large",
    "Chicken Biryani",
    "BBQ Platter",
    "Fries",
    "Cold Drink"
};

float prices[8] = {450, 550, 900, 1800, 350, 1200, 250, 120};
int quantity[8] = {0};

void registerCustomer();
void displayMenu();
void placeOrder();
float calculateFoodBill();
float calculateServiceCharges(float);
float calculateGST(float);
float calculateDiscount(float);
void displayFinalBill();
void displayCustomerDetails();

void registerCustomer()
{
    cout << "\n========== CUSTOMER REGISTRATION ==========\n";

    cin.ignore();

    cout << "Enter Customer Name: ";
    getline(cin, customerName);

    cout << "Enter Contact Number: ";
    cin >> contactNumber;

    cout << "Enter Order Type (Dine-in/Takeaway): ";
    cin >> orderType;

    cout << "Enter Number of Persons: ";
    cin >> persons;
}

void displayMenu()
{
    cout << "\n========== FOOD MENU ==========\n";

    for(int i = 0; i < 8; i++)
    {
        cout << i + 1 << ". "
             << setw(20) << left << foodItems[i]
             << " Rs. " << prices[i] << endl;
    }
}

void placeOrder()
{
    int choice, qty;
    char more;

    do
    {
        displayMenu();

        cout << "\nEnter Item Number: ";
        cin >> choice;

        if(choice >= 1 && choice <= 8)
        {
            cout << "Enter Quantity: ";
            cin >> qty;

            quantity[choice - 1] += qty;

            cout << "Item Added Successfully!\n";
        }
        else
        {
            cout << "Invalid Item Number!\n";
        }

        cout << "Add More Items? (Y/N): ";
        cin >> more;

    } while(more == 'Y' || more == 'y');
}

float calculateFoodBill()
{
    float foodBill = 0;

    for(int i = 0; i < 8; i++)
    {
        foodBill += quantity[i] * prices[i];
    }

    return foodBill;
}

float calculateServiceCharges(float foodBill)
{
    if(orderType == "Dine-in" || orderType == "dine-in")
        return foodBill * 0.10;

    return foodBill * 0.05;
}

float calculateGST(float foodBill)
{
    return foodBill * 0.16;
}

float calculateDiscount(float foodBill)
{
    if(foodBill >= 3000 && foodBill <= 5000)
        return foodBill * 0.05;

    else if(foodBill > 5000 && foodBill <= 10000)
        return foodBill * 0.10;

    else if(foodBill > 10000)
        return foodBill * 0.15;

    return 0;
}

void displayFinalBill()
{
    float foodBill = calculateFoodBill();
    float serviceCharges = calculateServiceCharges(foodBill);
    float gst = calculateGST(foodBill);
    float discount = calculateDiscount(foodBill);

    float total = foodBill + serviceCharges + gst - discount;

    cout << "\n\n========== RESTAURANT BILL ==========\n";

    cout << "Customer Name: " << customerName << endl;
    cout << "Contact Number: " << contactNumber << endl;
    cout << "Order Type: " << orderType << endl;
    cout << "Number of Persons: " << persons << endl;

    cout << "\nFood Bill: Rs. " << foodBill << endl;
    cout << "Service Charges: Rs. " << serviceCharges << endl;
    cout << "GST (16%): Rs. " << gst << endl;
    cout << "Discount: Rs. " << discount << endl;

    cout << "------------------------------------\n";
    cout << "Total Payable Amount: Rs. " << total << endl;

    if(total > 5000)
    {
        cout << "\n*** FREE DELIVERY AVAILABLE ***\n";
    }

    cout << "\nEnjoy Your Meal :)\n";
    cout << "====================================\n";
}

void displayCustomerDetails()
{
    cout << "\n========== CUSTOMER DETAILS ==========\n";

    cout << "Customer Name: " << customerName << endl;
    cout << "Contact Number: " << contactNumber << endl;
    cout << "Order Type: " << orderType << endl;
    cout << "Number of Persons: " << persons << endl;
}

int main()
{
    int choice;

    registerCustomer();

    do
    {
        cout << "\n\n========== MAIN MENU ==========\n";
        cout << "1. View Food Menu\n";
        cout << "2. Place Order\n";
        cout << "3. Calculate Bill\n";
        cout << "4. View Customer Details\n";
        cout << "5. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayMenu();
                break;

            case 2:
                placeOrder();
                break;

            case 3:
                displayFinalBill();
                break;

            case 4:
                displayCustomerDetails();
                break;

            case 5:
                cout << "\nThank You For Visiting Our Restaurant!\n";
                break;

            default:
                cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while(choice != 5);

    return 0;
}
