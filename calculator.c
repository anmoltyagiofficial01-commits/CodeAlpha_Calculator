/*
 * ============================================
 *   Calculator Program
 *   CodeAlpha C Programming Internship
 *   Task 1: Basic Calculator
 * ============================================
 *   Features:
 *   1. Addition
 *   2. Subtraction
 *   3. Multiplication
 *   4. Division (with divide-by-zero check)
 *   5. Modulus
 *   6. Power
 *
 *   Uses: Switch-case, Functions, Loops
 * ============================================
 */

#include <stdio.h>
#include <math.h>

/* ---- Function Prototypes ---- */
float addition(float a, float b);
float subtraction(float a, float b);
float multiplication(float a, float b);
float division(float a, float b);
int   modulus(int a, int b);
float power(float base, float exp);
void  printHeader();
void  printSeparator();
void  displayResult(float result);

/* ============================================
   MAIN FUNCTION
   ============================================ */
int main() {
    int   choice;
    float num1, num2;
    int   running = 1;

    printHeader();

    while (running) {
        printf("           SELECT OPERATION           \n");
        printf("  1.  Addition       ( + )            \n");
        printf("  2.  Subtraction    ( - )            \n");
        printf("  3.  Multiplication ( * )            \n");
        printf("  4.  Division       ( / )            \n");
        printf("  5.  Modulus        ( %% )            \n");
        printf("  6.  Power          ( ^ )            \n");
        printf("  7.  Exit                            \n");
        printf("  Enter your choice: ");
        scanf("%d", &choice);

        // Exit early
        if (choice == 7) {
            printf("\n  [OK] Thank you for using the Calculator!\n");
            printf("  Goodbye!\n\n");
            break;
        }

        // Validate choice
        if (choice < 1 || choice > 7) {
            printf("\n  [ERROR] Invalid choice! Please select between 1 and 7.\n");
            continue;
        }

        // Get input numbers
        printf("\n  Enter first number  : ");
        scanf("%f", &num1);
        printf("  Enter second number : ");
        scanf("%f", &num2);

        printSeparator();

        switch (choice) {

            case 1: // Addition
                printf("  %.2f + %.2f = ", num1, num2);
                displayResult(addition(num1, num2));
                break;

            case 2: // Subtraction
                printf("  %.2f - %.2f = ", num1, num2);
                displayResult(subtraction(num1, num2));
                break;

            case 3: // Multiplication
                printf("  %.2f x %.2f = ", num1, num2);
                displayResult(multiplication(num1, num2));
                break;

            case 4: // Division
                if (num2 == 0) {
                    printf("\n  [ERROR] Error: Division by zero is not allowed!\n");
                } else {
                    printf("  %.2f / %.2f = ", num1, num2);
                    displayResult(division(num1, num2));
                }
                break;

            case 5: // Modulus (integers only)
                if ((int)num2 == 0) {
                    printf("\n  [ERROR] Error: Modulus by zero is not allowed!\n");
                } else {
                    printf("  %d %% %d = %d\n", (int)num1, (int)num2, modulus((int)num1, (int)num2));
                }
                break;

            case 6: // Power
                printf("  %.2f ^ %.2f = ", num1, num2);
                displayResult(power(num1, num2));
                break;
        }

        printSeparator();
    }

    return 0;
}

/* ============================================
   FUNCTION: Print Welcome Header
   ============================================ */
void printHeader() {
    printf("         CALCULATOR PROGRAM           \n");
    printf("       CodeAlpha Internship           \n");
}

/* ============================================
   FUNCTION: Print Separator Line
   ============================================ */
void printSeparator() {
    printf("\n  ===========================\n");
}

/* ============================================
   FUNCTION: Display Result
   ============================================ */
void displayResult(float result) {
    printf("%.4f\n", result);
}

/* ============================================
   FUNCTION: Addition
   ============================================ */
float addition(float a, float b) {
    return a + b;
}

/* ============================================
   FUNCTION: Subtraction
   ============================================ */
float subtraction(float a, float b) {
    return a - b;
}

/* ============================================
   FUNCTION: Multiplication
   ============================================ */
float multiplication(float a, float b) {
    return a * b;
}

/* ============================================
   FUNCTION: Division
   ============================================ */
float division(float a, float b) {
    return a / b;
}

/* ============================================
   FUNCTION: Modulus (integers)
   ============================================ */
int modulus(int a, int b) {
    return a % b;
}

/* ============================================
   FUNCTION: Power (using math.h)
   ============================================ */
float power(float base, float exp) {
    return (float)pow(base, exp);
}
