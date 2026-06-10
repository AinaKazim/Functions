#include <iostream>
#include <string>
using namespace std;

string clientName, businessName, businessType;
int campaignDuration;
int selectedPlatform = -1;

string platforms[3] = {"Instagram", "Facebook", "LinkedIn"};
double platformCharges[3] = {15000, 12000, 20000};

void registerClient();
void displayPlatforms();
void selectPlatform();
double calculatePostDesignCost();
double calculateAdHandlingFee(double adBudget);
double calculateExtraDurationCharges();
double calculateGST(double amount);
double calculateDiscount(double amount);
void displayFinalBill();
void displayClientDetails();

int main()
{
    int choice;

    registerClient();

    do
    {
        cout << "\n========== SOCIAL MEDIA MANAGEMENT SYSTEM ==========\n";
        cout << "1. View Platforms\n";
        cout << "2. Select Campaign Platform\n";
        cout << "3. Calculate Campaign Cost\n";
        cout << "4. View Client Details\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                displayPlatforms();
                break;

            case 2:
                selectPlatform();
                break;

            case 3:
                displayFinalBill();
                break;

            case 4:
                displayClientDetails();
                break;

            case 5:
                cout << "\nThank You For Using The System!\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}
void registerClient()
{
    cin.ignore();
	cout << "========== CLIENT REGISTRATION ==========\n";
	cout << "Enter Client Name: ";
    getline(cin, clientName);

    cout << "Enter Business Name: ";
    getline(cin, businessName);

    cout << "Enter Business Type (Small Business / Medium Business / Corporate Business): ";
    getline(cin, businessType);

    cout << "Enter Campaign Duration (Days): ";
    cin >> campaignDuration;
}
void displayPlatforms()
{
    cout << "\n========== SOCIAL MEDIA PLATFORMS ==========\n";

    for(int i = 0; i < 3; i++)
    {
        cout << i + 1 << ". "
             << platforms[i]
             << " - Rs. "
             << platformCharges[i]
             << endl;
    }
}
void selectPlatform()
{
    displayPlatforms();

    cout << "\nSelect Platform Number: ";
    cin >> selectedPlatform;

    if(selectedPlatform < 1 || selectedPlatform > 3)
    {
        cout << "Invalid Platform Selection!\n";
        selectedPlatform = -1;
    }
    else
    {
        cout << "Platform Selected Successfully!\n";
    }
}
double calculatePostDesignCost()
{
    int staticPosts, reelPosts, carouselPosts;

    cout << "\nEnter Number of Static Posts: ";
    cin >> staticPosts;

    cout << "Enter Number of Reel/Video Posts: ";
    cin >> reelPosts;

    cout << "Enter Number of Carousel Posts: ";
    cin >> carouselPosts;

    double totalCost =
        (staticPosts * 1000) +
        (reelPosts * 2500) +
        (carouselPosts * 1800);

    return totalCost;
}

double calculateAdHandlingFee(double adBudget)
{
    if(adBudget < 50000)
        return adBudget * 0.05;

    else if(adBudget <= 100000)
        return adBudget * 0.08;

    else
        return adBudget * 0.10;
}

double calculateExtraDurationCharges()
{
    if(campaignDuration > 30)
    {
        return (campaignDuration - 30) * 500;
    }

    return 0;
}

double calculateGST(double amount)
{
    return amount * 0.16;
}

double calculateDiscount(double amount)
{
    if(businessType == "Small Business" || businessType == "small business")
    {
        return amount * 0.05;
    }

    else if(businessType == "Medium Business" || businessType == "medium business")
    {
        return amount * 0.08;
    }

    else if(businessType == "Corporate Business" || businessType == "corporate business")
    {
        return amount * 0.10;
    }

    return 0;
}
void displayFinalBill()
{
    if(selectedPlatform == -1)
    {
        cout << "\nPlease Select A Platform First!\n";
        return;
    }

    double postDesignCost;
    double adBudget;
    double handlingFee;
    double extraCharges;
    double gst;
    double discount;
    double serviceCost;
    double finalCost;

    postDesignCost = calculatePostDesignCost();

    cout << "\nEnter Advertisement Budget: Rs. ";
    cin >> adBudget;

    handlingFee = calculateAdHandlingFee(adBudget);
    extraCharges = calculateExtraDurationCharges();
    serviceCost = platformCharges[selectedPlatform - 1] + postDesignCost + adBudget + handlingFee + extraCharges;
    gst = calculateGST(serviceCost);
    discount = calculateDiscount(serviceCost);
    finalCost = serviceCost + gst - discount;

    cout << "\n\n========== SOCIAL MEDIA CAMPAIGN BILL ==========\n";
    cout << "Client Name: " << clientName << endl;
    cout << "Business Name: " << businessName << endl;
    cout << "Business Type: " << businessType << endl;
    cout << "Selected Platform: "
         << platforms[selectedPlatform - 1] << endl;
    cout << "Campaign Duration: "
         << campaignDuration << " Days\n";

    cout << "\nPlatform Management Charges: Rs. "
         << platformCharges[selectedPlatform - 1];

    cout << "\nPost Design Cost: Rs. "
         << postDesignCost;

    cout << "\nAd Budget: Rs. "
         << adBudget;

    cout << "\nAd Handling Fee: Rs. "
         << handlingFee;

    cout << "\nExtra Duration Charges: Rs. "
         << extraCharges;

    cout << "\nGST (16%): Rs. "
         << gst;

    cout << "\nDiscount: Rs. "
         << discount;

    cout << "\n------------------------------------------------";

    cout << "\nFinal Campaign Cost: Rs. "
         << finalCost;

    cout << "\n================================================\n";
}

void displayClientDetails()
{
    cout << "\n========== CLIENT DETAILS ==========\n";

    cout << "Client Name: " << clientName << endl;
    cout << "Business Name: " << businessName << endl;
    cout << "Business Type: " << businessType << endl;
    cout << "Campaign Duration: " << campaignDuration << " Days" << endl;

    if(selectedPlatform != -1)
    {
        cout << "Selected Platform: "
             << platforms[selectedPlatform - 1] << endl;
    }
    else
    {
        cout << "Selected Platform: Not Selected Yet\n";
    }
}
