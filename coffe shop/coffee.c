#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void printInvoice(char item[], float rate, int qty, int discount) {
    float total = qty * rate;
    float afterDiscount = total - (total * discount / 100.0);
    float cgst = 0.05 * afterDiscount;
    float sgst = 0.05 * afterDiscount;
    float grandTotal = afterDiscount + cgst + sgst;

     time_t t;
    struct tm *tm_info;
    char date_time[30];

    time(&t);
    tm_info = localtime(&t);
    
    // Format date and time as "DD/MM/YYYY HH:MM:SS"
    strftime(date_time, sizeof(date_time), "%d/%m/%Y %H:%M:%S", tm_info);

    printf("\n\t\t\t-----------TAX INVOICE------------");
     printf("\n\t\t\tDATE: %s\t, date_time);
    printf("\n\t\t\t----------------------------------");
    printf("\n\t\t\t==================================");
    printf("\n\t\t\t~~~~~WELCOME TO COADING CAFE~~~~~~");
    printf("\n\t\t\tOff Kanakapura Road, Doddakalsandra");
    printf("\n\t\t\tVasanthpura, Bengaluru-62");
    printf("\n\t\t\t==================================");

    printf("\n\n*******************************************************************************");
    printf("\n* ALERT *");
    printf("\nSPECIAL OFFER: Buy more than 5 pieces and get a FLAT 10%% OFF!");
    printf("\n* OFFER IS FOR A LIMITED PERIOD ONLY *");
    printf("\n*******************************************************************************");

    printf("\n\nYou have ordered: %s", item);
    printf("\nQuantity: %d", qty);
    printf("\nRate: %.2f", rate);
    printf("\n-----------------------------------------------");
    printf("\nSub Total\t\t\t: %.2f", total);
    printf("\nDiscount Applied (%d%%)\t: -%.2f", discount, total * discount / 100.0);
    printf("\nAfter Discount\t\t\t: %.2f", afterDiscount);
    printf("\nCGST @5%%\t\t\t: %.2f", cgst);
    printf("\nSGST @5%%\t\t\t: %.2f", sgst);
    printf("\n-----------------------------------------------");
    printf("\nGRAND TOTAL\t\t\t: %.2f", grandTotal);
    printf("\n-----------------------------------------------\n");
}

int main() {
    int choice, qty, discount = 0;
    float rate;
    char item[50];

    printf("\n\nHERE IS YOUR DELICIOUS MENU CARD!!!");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\nSelect your drink:");
    printf("\n1. CAPPUCCINO (225.00)");
    printf("\n2. ROBUSTO COFFEE (450.00)");
    printf("\n3. COLD COFFEE (180.00)");
    printf("\n4. EXPRESSO (450.00)");
    printf("\n5. CAFFE MACCHIATO (300.00)");
    printf("\n6. ARABICA (250.00)");
    printf("\n7. TEA (100.00)");
    printf("\n8. GINGER TEA (150.00)");
    printf("\n9. BLACK TEA (200.00)");
    printf("\n\nSelect your Bites:");
    printf("\n10. CHEESE MAX PIZZA (350.00)");
    printf("\n11. DOUBLE CHEESE PAN PIZZA (400.00)");
    printf("\n12. SPICY PANEER BURGER (250.00)");
    printf("\n13. VEG CHEESE BURGER (200.00)");
    printf("\n14. VEG SANDWICH (180.00)");
    printf("\n15. PANEER CHEESE SANDWICH (220.00)");

    printf("\n\nPlease select your choice: ");
    scanf("%d", &choice);
    
    printf("\nEnter the quantity: ");
    scanf("%d", &qty);

    if (qty > 5) {
        discount = 10; // Apply 10% discount
    }

    switch (choice) {
        case 1:  rate = 225.00; sprintf(item, "CAPPUCCINO"); break;
        case 2:  rate = 450.00; sprintf(item, "ROBUSTO COFFEE"); break;
        case 3:  rate = 180.00; sprintf(item, "COLD COFFEE"); break;
        case 4:  rate = 450.00; sprintf(item, "EXPRESSO"); break;
        case 5:  rate = 300.00; sprintf(item, "CAFFE MACCHIATO"); break;
        case 6:  rate = 250.00; sprintf(item, "ARABICA"); break;
        case 7:  rate = 100.00; sprintf(item, "TEA"); break;
        case 8:  rate = 150.00; sprintf(item, "GINGER TEA"); break;
        case 9:  rate = 200.00; sprintf(item, "BLACK TEA"); break;
        case 10: rate = 350.00; sprintf(item, "CHEESE MAX PIZZA"); break;
        case 11: rate = 400.00; sprintf(item, "DOUBLE CHEESE PAN PIZZA"); break;
        case 12: rate = 250.00; sprintf(item, "SPICY PANEER BURGER"); break;
        case 13: rate = 200.00; sprintf(item, "VEG CHEESE BURGER"); break;
        case 14: rate = 180.00; sprintf(item, "VEG SANDWICH"); break;
        case 15: rate = 220.00; sprintf(item, "PANEER CHEESE SANDWICH"); break;
        default: 
            printf("\nInvalid choice! Please restart the program.\n");
            return 0;
    }

    printInvoice(item, rate, qty, discount);
    
    return 0;
}
