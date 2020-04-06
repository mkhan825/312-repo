/* 
 * EE312 Simple CRM Project
 *
 * Masaad Khan
 */

#include <stdio.h>
#include <assert.h>
#include "MyString.h"
#include "Invent.h"
#include <stdlib.h>
//#include <header.txt>

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];

int previousb = 0;
int previousd = 0;
int previousr = 0;
int num_customers = 0;
int boolean = 0;

/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */
/* clear the inventory and reset the customer database to empty */
void reset(void) {
	/* your code here */
	boolean = 0;
	previousd = 0;
	previousr = 0;
	previousb = 0;
	num_customers = 0;
	for(int i = 0; i < 1000; i++) {
	    StringDestroy(&customers[i].name);
	    customers[i].diapers = 0;
	    customers[i].bottles = 0;
	    customers[i].rattles = 0;
	}
}

void processSummarize() {
    int biggestd = customers[0].diapers;
    int biggestb = customers[0].bottles;
    int biggestr = customers[0].rattles;
    //Print Bottles, Rattles, Diapers
    printf("There are %d Bottles, %d Diapers, %d Rattles in inventory\n", previousb, previousd, previousr);
    //Print how many customers came to the store
    printf("we have had a total of %d different customers\n", num_customers);
    //Summary should mention who bought the most diapers and how many
    int j = 0;
    int k = 0;
    int l = 0;
    //Most Bottles
    for(int i = 0; i < num_customers; i++) {
        if(customers[i].bottles > biggestb) {
            biggestb = customers[i].bottles;
            k = i;
        }
    }
    if(biggestb == 0) {
        printf("no one has purchased any Bottles\n");
    } else {
        StringPrint(&customers[k].name);
        printf(" has purchased the most Bottles (%d)\n", biggestb);
    }
    //Most Diapers
    for(int i = 0; i < num_customers; i++) {
        if(customers[i].diapers > biggestd) {
            biggestd = customers[i].diapers;
            j = i;
        }
    }
    if(biggestd == 0) {
        printf("no one has purchased any Diapers\n");
    } else {
        StringPrint(&customers[j].name);
        printf(" has purchased the most Diapers (%d)\n", biggestd);
    }
    //Most rattles
    for(int i = 0; i < num_customers; i++) {
        if(customers[i].rattles > biggestr) {
            biggestr = customers[i].rattles;
            l = i;
        }
    }
    if(biggestr == 0) {
        printf("no one has purchased any Rattles\n");
    } else {
        StringPrint(&customers[l].name);
        printf(" has purchased the most Rattles (%d)\n", biggestr);
    }
}

void processPurchase() {
    int numofitems;
    String bottlesptr = StringCreate("Bottles");
    String rattlesptr = StringCreate("Rattles");
    String diapersptr = StringCreate("Diapers");
    String in;
    String in2;
    readString(&in);
    readString(&in2);
    readNum(&numofitems);
    if(numofitems <= 0) {
        StringDestroy(&bottlesptr);
        StringDestroy(&diapersptr);
        StringDestroy(&rattlesptr);
        StringDestroy(&in);
        StringDestroy(&in2);
        return;
    }
    // Check if amount of inventory items is enough before you create a new person
    if(StringIsEqualTo(&in2, &bottlesptr) && (numofitems > previousb)){
        //Bottles update
        //error
        printf("Sorry ");
        StringPrint(&in);
        printf(", we only have %d ", previousb);
        StringPrint(&bottlesptr);
        printf("\n");
        StringDestroy(&bottlesptr);
        StringDestroy(&rattlesptr);
        StringDestroy(&diapersptr);
        StringDestroy(&in);
        StringDestroy(&in2);
        return;
    }
    if(StringIsEqualTo(&in2, &diapersptr) && (numofitems > previousd)){
        //Diapers update
        //error
        printf("Sorry ");
        StringPrint(&in);
        printf(", we only have %d ", previousd);
        StringPrint(&diapersptr);
        printf("\n");
        StringDestroy(&bottlesptr);
        StringDestroy(&rattlesptr);
        StringDestroy(&diapersptr);
        StringDestroy(&in);
        StringDestroy(&in2);
        return;
    }
    if(StringIsEqualTo(&in2, &rattlesptr) && (numofitems > previousr)){
        //Rattles update
        //error
        printf("Sorry ");
        StringPrint(&in);
        printf(", we only have %d ", previousr);
        StringPrint(&rattlesptr);
        printf("\n");
        StringDestroy(&bottlesptr);
        StringDestroy(&rattlesptr);
        StringDestroy(&diapersptr);
        StringDestroy(&in);
        StringDestroy(&in2);
        return;
    }
    // Check the person's name in the database
    if(num_customers == 0) {
        num_customers = 1;
        /*for(int i = 0; i < 1000; i++) {
            customers[i].name = StringCreate("");
        }*/
    }
    int i = 0;
    for (; i < num_customers ; i++) {
        if(StringIsEqualTo(&in, &customers[i].name) == 1) {
            break;
        } else {
            if ((StringIsEqualTo(&in, &customers[i].name) == 0) && (i == (num_customers - 1))) {
                //if their name doesnt exist
                if(boolean == 0) {
                    boolean = 1;
                    goto label;
                }
                num_customers++;
                label:
                i = num_customers-1;
                customers[i].name = StringDup(&in);
                customers[i].bottles = 0;
                customers[i].rattles = 0;
                customers[i].diapers = 0;
                break;
            }
        }
    }

    // Update their information and Inventory
    if(StringIsEqualTo(&in2, &bottlesptr)){
        //Bottles update
        customers[i].bottles += numofitems;
        previousb = previousb - numofitems;
    }
    if(StringIsEqualTo(&in2, &diapersptr)){
        //Diapers update
        customers[i].diapers += numofitems;
        previousd = previousd - numofitems;
    }
    if(StringIsEqualTo(&in2, &rattlesptr)){
        //Rattles update
        customers[i].rattles += numofitems;
        previousr = previousr - numofitems;
    }

    StringDestroy(&bottlesptr);
    StringDestroy(&rattlesptr);
    StringDestroy(&diapersptr);
    StringDestroy(&in);
    StringDestroy(&in2);
}

void processInventory() {
    //Read item type
    String bottlesptr = StringCreate("Bottles");
    String rattlesptr = StringCreate("Rattles");
    String diapersptr = StringCreate("Diapers");
    String in;
    int numofitems;
    readString(&in);
    readNum(&numofitems);
    if(numofitems <= 0) {
        StringDestroy(&bottlesptr);
        StringDestroy(&rattlesptr);
        StringDestroy(&diapersptr);
        StringDestroy(&in);
        return;
    }
    //Read what type
    if(StringIsEqualTo(&in, &bottlesptr)){
        //Initialize Bottles and Update
        previousb = previousb + numofitems;
    }
    if(StringIsEqualTo(&in, &diapersptr)){
        //Initialize Diapers and Update
        previousd = previousd + numofitems;
    }
    if(StringIsEqualTo(&in, &rattlesptr)){
        //Initialize Rattles and Update
        previousr = previousr + numofitems;
    }
    StringDestroy(&bottlesptr);
    StringDestroy(&rattlesptr);
    StringDestroy(&diapersptr);
    StringDestroy(&in);
}
