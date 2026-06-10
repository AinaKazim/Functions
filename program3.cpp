#include<iostream>
#include<string>
using namespace std;

string customerName;
int customerID, customerType, paymentMethod;

string items[8] = {
    "Rice 1 KG",
    "Sugar 1 KG",
    "Cooking Oil 1 Litre",
    "Milk Pack",
    "Tea Pack",
    "Flour 5 KG",
    "Eggs Dozen",
    "Detergent"
};

float prices[8] = {350,180,580,220,450,950,320,600};
int quantity[8] = {0};

void registerCustomer()
{
    cout<<"Enter Customer Name: ";
    cin.ignore();
    getline(cin, customerName);

    cout<<"Enter Customer ID: ";
    cin>>customerID;

    cout<<"1. Regular Customer\n2. Member Customer\n";
    cout<<"Enter Customer Type: ";
    cin>>customerType;

    cout<<"1. Cash\n2. Card\n";
    cout<<"Enter Payment Method: ";
    cin>>paymentMethod;
}

void displayItems()
{
    cout<<"\n===== GROCERY ITEMS =====\n";

    for(int i=0;i<8;i++)
    {
        cout<<i+1<<". "<<items[i]
            <<" - Rs. "<<prices[i]<<endl;
    }
}

void addItemsToCart()
{
    int choice, qty;
    char more;

    do
    {
        displayItems();

        cout<<"\nEnter Item Number: ";
        cin>>choice;

        cout<<"Enter Quantity: ";
        cin>>qty;

        quantity[choice-1] += qty;

        cout<<"Add More Items? (Y/N): ";
        cin>>more;

    }while(more=='Y' || more=='y');
}

float calculateGrossBill()
{
    float grossBill=0;

    for(int i=0;i<8;i++)
    {
        grossBill += quantity[i] * prices[i];
    }

    return grossBill;
}

void displayCustomerDetails()
{
    cout<<"\nCustomer Name: "<<customerName;
    cout<<"\nCustomer ID: "<<customerID;

    if(customerType==1)
        cout<<"\nCustomer Type: Regular";
    else
        cout<<"\nCustomer Type: Member";

    if(paymentMethod==1)
        cout<<"\nPayment Method: Cash";
    else
        cout<<"\nPayment Method: Card";

    cout<<endl;
}

void displayFinalBill()
{
    float grossBill = calculateGrossBill();

    float salesTax = 0;

    for(int i=0;i<8;i++)
    {
        if(i<=6)
            salesTax += quantity[i] * prices[i] * 0.05;
        else
            salesTax += quantity[i] * prices[i] * 0.10;
    }

    float memberDiscount = 0;

    if(customerType==2)
        memberDiscount = grossBill * 0.07;

    float billDiscount = 0;

    if(grossBill>=5000 && grossBill<=10000)
        billDiscount = grossBill * 0.05;
    else if(grossBill>10000)
        billDiscount = grossBill * 0.10;

    float total =
        grossBill +
        salesTax -
        memberDiscount -
        billDiscount;

    float cardCharges = 0;

    if(paymentMethod==2)
    {
        cardCharges = total * 0.02;
        total += cardCharges;
    }

    int generatedPoints = total / 100;
    int existingPoints;

    cout<<"\nGenerated Loyalty Points: "
        <<generatedPoints;

    cout<<"\nEnter Existing Loyalty Points (0 if new user): ";
    cin>>existingPoints;

    int totalPoints =
        generatedPoints +
        existingPoints;

    cout<<"Loyalty Points After Purchase: "
        <<totalPoints;

    int choice;

    cout<<"\n\n1. Redeem Loyalty Points";
    cout<<"\n2. Continue";
    cout<<"\nEnter Choice: ";
    cin>>choice;

    if(choice==1)
        total -= totalPoints;

    cout<<"\n\n========== GROCERY MART BILL ==========\n";

    cout<<"Customer Name: "<<customerName<<endl;

    if(customerType==1)
        cout<<"Customer Type: Regular"<<endl;
    else
        cout<<"Customer Type: Member"<<endl;

    if(paymentMethod==1)
        cout<<"Payment Method: Cash"<<endl;
    else
        cout<<"Payment Method: Card"<<endl;

    cout<<"\nGross Bill: Rs. "<<grossBill;
    cout<<"\nSales Tax: Rs. "<<salesTax;
    cout<<"\nMembership Discount: Rs. "<<memberDiscount;
    cout<<"\nBill Discount: Rs. "<<billDiscount;
    cout<<"\nCard Charges: Rs. "<<cardCharges;

    cout<<"\n---------------------------------------";
    cout<<"\nTotal Payable Amount: Rs. "<<total;

    cout<<"\nThank You For Shopping :)";
    cout<<"\n=======================================\n";
}

int main()
{
    int choice;

    registerCustomer();

    do
    {
        cout<<"\n\n===== MAIN MENU =====";
        cout<<"\n1. View Grocery Items";
        cout<<"\n2. Add Items To Cart";
        cout<<"\n3. Calculate Bill";
        cout<<"\n4. View Customer Details";
        cout<<"\n5. Exit";
        cout<<"\nEnter Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                displayItems();
                break;

            case 2:
                addItemsToCart();
                break;

            case 3:
                displayFinalBill();
                break;

            case 4:
                displayCustomerDetails();
                break;

            case 5:
                cout<<"\nThank You!";
                break;

            default:
                cout<<"\nInvalid Choice!";
        }
    }while(choice!=5);
    return 0;
}
