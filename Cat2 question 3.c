// a program to print out scores in a loop 
/*
Name : Ongangi Joseph Jeff 
Reg no:CT100/G/21645/25

*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    FILE *input, *output;

    int number, sum = 0;
    float average;

    input = fopen("input.txt", "w");
    if (input == NULL) {
        printf("Error opening the file for writing.\n");
        return 1;
    }
    
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &number);
        fprintf(input, "%d\n", number);
    }

    fclose(input);
    printf("Integers have been written to input.txt\n");

    input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error opening the file for the integers\n");
        return 1;
    }
    while (fscanf(input, "%d", &number) == 1) {
        sum += number;
    }
    fclose(input);
    average = sum / 10;

    output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error opening the file for writing output.\n");
        return 1;
    }
    
    fprintf(output, "Sum: %d\n", sum);
    fprintf(output, "Average: %.2f\n", average);
    fclose(output);
    printf("Results have been written to output.txt\n");

    printf("Sum and Average have been written to output.txt\n")
    printf("\nContents of input.txt:\n");
    input = fopen("input.txt", "r");
    while ((number = fgetc(input)) != EOF) {
        putchar(number);
    }
    
    fclose(input);
    printf("\n\nContents of output.txt:\n");
    output = fopen("output.txt", "r");
    while ((number = fgetc(output)) != EOF) {
        putchar(number);
    }
    
    fclose(output);

    return 0;
}