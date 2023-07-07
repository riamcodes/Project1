//Ria Mukherji CS1342 LAB1 HOWARD
#include <iostream>
using namespace std;

// function prints out the menu and returns the users choice
int displayMenuGetOption() {
    int userChoice;
   cout << "MENU \n1. Generate product hash value \n2. Generate SKU from product hash value \n3. Verify SKU \n9. Exit \nEnter choice:";
   cin >> userChoice;
   cin.clear();
   return userChoice;
}// end displayMenuGetOption

//Function to count digits in a number
//returns count the number of digits
//parameter num the number to have digits counted
int countDigits(int num) {
    int count = 0;
    while(num) {
        count++;
        num /= 10;
    }
    return count;
}// end countDigits

//function for if user chooses 1 to create hash value. Prompts user for a description then turns it into ASCII value sum.
//returns totalAscii the sum of all the letters ascii values
int optionOne(){
    string describe;
    int totalAscii = 0;
    int totalDigits = 0;

    cout <<"Enter description:";
    cin.ignore();
    getline(cin,describe);

  // loop through and add the ASCII values of characters in describe
    for (int i = 0; i < describe.size(); i++){
        totalAscii += describe.at(i);
    }

    //count digits in totalAscii value make sure 5 minimum. If not 5 add 0 to end until 5
   for ( totalDigits = countDigits(totalAscii); totalDigits < 5; totalDigits ++){
       totalAscii *= 10;
   }
return totalAscii;
}// end optionOne


//function for option two generates the SKU based on the hash number
//param hashParam is type int passed into option 2
// function returns evenMultipleAdded the last digit that should be added to turn a hash into an sku
int optionTwo(int hashParam){
    int oddSum = 0;
    int evenSum = 0;
    int resultSum;
    int evenMultipleAdded;

    // 5 digits but if it was more loop makes it manageable to expand as long as its an odd number
    for (int i = 0; i < 2; i++)
    {
        oddSum += hashParam % 10;
        hashParam /= 10;
        evenSum += hashParam % 10;
        hashParam /= 10;
    }
    oddSum +=  hashParam % 10;
    hashParam /= 10;

    //3 comes from the number they gave us to multiply by
    oddSum *=3;
    resultSum = oddSum + evenSum;
    evenMultipleAdded = (10 - (resultSum % 10));
return evenMultipleAdded;

}// end optionTwo

//Third user choice function returns true or false based on if the hash value matches the sku
//param skuParam is an int to be passed into the function
//function returns true or false boolean
bool optionThree(int skuParam)
{
    //check to see if its accurate by taking the last digit of the 6 hash and comparing it to what the parameter without that digit had been used in optionTwo
    if ((skuParam%10) == (optionTwo(skuParam/10))){
        return true;
    }
    else
    {
        return false;
    }

}// end optionThree


//main
int main() {
// local variables
int hashValue;
int hashParam1;
int sku;
int sixDigitSku;

 //forever loop that only breaks if user enters 9
 while (true) {

     //displays the menu and branches
     int userChoice1 = displayMenuGetOption();


     if(userChoice1 == 1)
     {
        //hashValue = optionOne();
        hashValue = optionOne();
        cout << "Product number: " << hashValue << endl;
        cout << endl;

     }
     else if (userChoice1 == 2)
     {
         cout << endl;
         cout << "Enter 5-digit product hash value:";
         cin >> hashParam1;
         sku = optionTwo(hashParam1);
         //output statement
         cout << "SKU with check digit = " << hashParam1 << sku << endl;
         cout << endl;
     }
     else if(userChoice1 == 3)
     {
         cout << "Enter 6-digit SKU:";
         cin >> sixDigitSku;
         if (optionThree(sixDigitSku) == true) {
             cout << "SKU is valid" << endl;
             cout << endl;
         }
         else {
             cout << "SKU is not valid" << endl;
             cout << endl;
         }
     }
     else if (userChoice1 == 9)
     {
         break;
     }
     else
     {
        cout << "Error: try entering a different number" << endl;
        cout << endl;
     }

 }//end while
}// end main