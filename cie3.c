//modify the code to find the largest prime number less than n

#include <stdio.h>
#include <stdbool.h>
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}
int largestPrimeLessThanN(int n) {
    for (int i = n - 1; i >= 2; i--) {
        if (isPrime(i)) return i;
    }
    return -1; 
}
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int result = largestPrimeLessThanN(n);
    if (result != -1)
        printf("Largest prime less than %d is %d\n", n, result);
    else
        printf("No prime number found less than %d\n", n);

    return 0;
}