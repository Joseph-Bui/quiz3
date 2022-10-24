#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//declare required variables
float tipPercent;
float taxPercent;

float salad = 9.95, soup = 4.55, sandwich = 13.25, pizza = 22.35;
float taxAmount = 0, tipAmount = 0, totalBill = 0;

//take in arguments from the command line
int main(int argc, char* argv[])
{
    //create a randomizer for the number of items in each bill.
    srand( time(NULL));
    int numItems = rand() % 10;
    float total = 0;

    printf("\nItems purchased in this meal: ");
    //print out each item and price
     for(int i = 0; i < numItems; i++)
    {
        //if the number is 1 then salad will be purchased
        if((rand() %(4 - 1)+1) == 1)
        {
            printf("\nSalad: $%.2f", salad);
            total += salad;
        }

        //if number is 2 then soup will be purchased
        if((rand() %(4 - 1)+1) == 2)
        {
            printf("\nSoup: $%.2f", soup);
            total += soup;
        }

        //if number is 3 then sandwich will be purchased
        if((rand() %(4 - 1)+1) == 3)
        {
            printf("\nSandwich: $%.2f", sandwich);
            total += sandwich;
        }

        //if number is 4 then pizza will be purchased
        if((rand() %(4 - 1)+1) == 4)
        {
            printf("\nPizza: $%.2f", pizza);
            total += pizza;
        }
    }

    //store command line arguments in to variables
    tipPercent = atoi(argv[2]);
    taxPercent = atoi(argv[1]);

    //calculate the tax, tip, and bill amount
    taxAmount = (taxPercent/100) * total;
    tipAmount = (tipPercent/100) * total;
    totalBill = taxAmount + tipAmount + total;

    //print the final values
    printf("\n---------------");
    printf("\n\nMeal cost: $%.2f", total);
    printf("\nTax amount: $%.2f", taxAmount);
    printf("\nTip amount: $%.2f", tipAmount);
    printf("\nTotal Bill Amount: $%.2f\n", totalBill);
    
}