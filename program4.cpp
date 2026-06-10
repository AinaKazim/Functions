#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string products[8] = {
    "T-Shirt", "Jeans", "Shoes", "Watch", "Handbag", "Headphones", "Mobile Cover", "Perfume"};

double prices[8] = {
    1200, 3500, 5000, 2500, 4200, 3000, 700, 2800};

int quantity[8] = {0};

string userName, email, city;
int customerType;

void registerUser();
void displayProducts();
void addToCart();
double calculateProductTotal();
double calculateGST(double total);
double calculateDeliveryCharges();
double calculateCustomerDiscount(double total);
double calculateOrderDiscount(double total);
double calculatePaymentCharges(double amount);
void displayBill();

int main()
{
    registerUser();
	int choice;
	do
    {
        cout << "\n========== ONLINE SHOPPING SYSTEM ==========\n";
        cout << "1. View Products\n";
        cout << "2. Add Product to Cart\n";
        cout << "3. Calculate Checkout Bill\n";
        cout << "4. View User Details\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayProducts();
                break;

            case 2:
                addToCart();
                break;

            case 3:
                displayBill();
                break;

            case 4:
                cout << "\nUser Name: " << userName;
                cout << "\nEmail: " << email;
                cout << "\nCity: " << city;

                if(customerType == 1)
                    cout << "\nCustomer Type: New Customer\n";
                else
                    cout << "\nCustomer Type: Returning Customer\n";
                break;

            case 5:
                cout << "\nThank You for Shopping!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}

void registerUser()
{
    cout << "========== USER REGISTRATION ==========\n";
	cin.ignore();
    cout << "Enter User Name: ";
    getline(cin, userName);

    cout << "Enter Email: ";
    getline(cin, email);

    cout << "Enter City: ";
    getline(cin, city);

    cout << "\nCustomer Type\n";
    cout << "1. New Customer\n";
    cout << "2. Returning Customer\n";
    cout << "Enter Choice: ";
    cin >> customerType;
}
void displayProducts()
{
    cout << "\n========== PRODUCT LIST ==========\n";

    for(int i = 0; i < 8; i++)
    {
        cout << i + 1 << ". "
             << products[i]
             << " - Rs. "
             << prices[i] << endl;
    }
}

void addToCart()
{
    int choice, qty;
    displayProducts();

    cout << "\nEnter Product Number: ";
    cin >> choice;
    if(choice >= 1 && choice <= 8)
    {
        cout << "Enter Quantity: ";
        cin >> qty;

        quantity[choice - 1] += qty;

        cout << "Product Added Successfully!\n";
    }
    else
    {
        cout << "Invalid Product Number!\n";
    }
}

double calculateProductTotal()
{
    double total = 0;

    for(int i = 0; i < 8; i++)
    {
        total += prices[i] * quantity[i];
    }

    return total;
}
double calculateGST(double total)
{
    return total * 0.17;
}
double calculateDeliveryCharges()
{
    if(city == "Lahore" ||
       city == "Karachi" ||
       city == "Islamabad")
    {
        return 250;
    }

    return 500;
}

double calculateCustomerDiscount(double total)
{
    if(customerType == 1)
        return total * 0.05;

    return total * 0.10;
}
double calculateOrderDiscount(double total)
{
    if(total >= 5000 && total <= 10000)
        return total * 0.05;

    else if(total > 10000)
        return total * 0.12;

    return 0;
}
double calculatePaymentCharges(double amount)
{
    int paymentMethod;
    cout << "\nSelect Payment Method\n";
    cout << "1. Cash on Delivery\n";
    cout << "2. Debit/Credit Card\n";
    cout << "Enter Choice: ";
    cin >> paymentMethod;

    if(paymentMethod == 2)
        return amount * 0.025;

    return 0;
}
void displayBill()
{
    double productTotal = calculateProductTotal();
    double gst = calculateGST(productTotal);
    double delivery = calculateDeliveryCharges();
    double customerDiscount = calculateCustomerDiscount(productTotal);
    double orderDiscount = calculateOrderDiscount(productTotal);
    double subtotal = productTotal + gst + delivery - customerDiscount - orderDiscount;

    double paymentCharges = calculatePaymentCharges(subtotal);
    double finalAmount = subtotal + paymentCharges;
    cout << fixed << setprecision(2);

    cout << "\n\n========== ONLINE SHOPPING BILL ==========\n";

    cout << "User Name: " << userName << endl;
    cout << "City: " << city << endl;

    if(customerType == 1)
        cout << "Customer Type: New Customer\n";
    else
        cout << "Customer Type: Returning Customer\n";

    cout << "\nProduct Total: Rs. " << productTotal;
    cout << "\nGST: Rs. " << gst;
    cout << "\nDelivery Charges: Rs. " << delivery;
    cout << "\nCustomer Discount: Rs. " << customerDiscount;
    cout << "\nOrder Discount: Rs. " << orderDiscount;
    cout << "\nPayment Charges: Rs. " << paymentCharges;

    cout << "\n------------------------------------------";
    cout << "\nFinal Payable Amount: Rs. "
         << finalAmount;

    cout << "\nThank You for Shopping :)";
    cout << "\n==========================================\n";
}

