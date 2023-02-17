#include <stdio.h>
#define MONTHS 12
const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


void sales_report(float sales[MONTHS]){
    int i;
    const char *months[] = {"January", "February", "March", "April", "May", 
                            "June", "July", "August", "September", "October", "November", "December"};
    printf("Monthly sales report for 2022:\n");
    printf(" \n");
    printf("Month\t\tSales\n");
    for (i = 0; i < MONTHS; i++){
        printf("%-15s $%-15f\n", months[i], sales[i]);
    }
}

void sales_summary(float sales[MONTHS]){
    int i = 0;
    int min = sales[0];
    int min_index = 0;
    int max = sales[0];
    int max_index = 0;
    float sum_of_number = 0;
    float average;
    for (i = 0; i < MONTHS; i++){
        if (sales[i] < min){
            min_index = i;
            min = sales[i];
        }
        if (sales[i] > max){
            max_index = i;
            max = sales[i];
        }
        sum_of_number += sales[i]; 
    }
    average =  sum_of_number/12;


    printf("Sales summary: \n");
    printf(" \n");
    printf("%-15s $%-15f %s %s %s\n","Minimum sales: ", sales[min_index], "(", months[min_index], ")");
    printf("%-15s $%-15f %s %s %s\n", "Maximum sales: ", sales[max_index], "(", months[max_index], ")");
    printf("%-15s %-15f\n", "Average sales: ", average);
}

void six_month_average(float sales[MONTHS]){
    printf("Six-Month Moving Average Report:\n");
    printf("\n");
    int i = 0;
    float sum = 0;
    float average = 0;
    for (i = 0; i < MONTHS - 5; i++){
        sum = sales[i] + sales[i + 1] + sales[i + 2] + sales[i + 3] + sales[i + 4] + sales[i + 5];
        average = sum/6;
        printf("%-10s %s %-10s $%-10f\n", months[i], "-", months[i+5], average);    
    }
}

void sales_report_order(float sales[MONTHS], int month_numbers[MONTHS]){
    int i, j;
    float temp;
    for (i = 0; i < 12 - 1; i++){
        for (j = i + 1; j < 12; j++){
            if(sales[i] < sales[j]){
                temp = sales[i];
                sales[i] = sales[j];                
                sales[j] = temp;
                temp = month_numbers[i];
                month_numbers[i] = month_numbers[j];
                month_numbers[j] = temp;
            }
        }
    }
    printf("%-15s %-15s\n", " Months", "    Sales");
    printf("\n");
    for (i = 0; i < MONTHS; i++){
        printf("%-15s $%-15f\n", months[month_numbers[i]], sales[i]);
    }
}

int main() {
    float sales[MONTHS];
    FILE *fp;
    int num;
    fp = fopen("input.txt","r");
    if (fp == NULL){
       printf("Error! opening file"); 
       return 1;
    }
    
    for (int num = 0; num < MONTHS; num++){
        fscanf(fp, "%f", &sales[num]);   
    }
    int month_numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    sales_report(sales);
    printf(" \n");
    sales_summary(sales);
    printf(" \n");
    six_month_average(sales);
    printf(" \n");
    sales_report_order(sales, month_numbers);
    return 0;
}
//    char months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
