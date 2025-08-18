//Write an openMPi program to transform each element with A[i]=3*A[i]+2 using hash prgma omp parllel for schrdule (dynamic ,2) then switch to (static ,2) int A1[6]={1,2,3,4,5,6};(for dynamic),int a2[6]={1,2,3,4,5,6}(for static})
#include <stdio.h>
#include <omp.h>

int main() {
    int A1[6] = {1, 2, 3, 4, 5, 6};  
    int A2[6] = {1, 2, 3, 4, 5, 6};  

    printf("Using schedule(dynamic, 2):\n");
    #pragma omp parallel for schedule(dynamic, 2)
    for (int i = 0; i < 6; i++) {
        A1[i] = 3 * A1[i] + 2;
        printf("Thread %d processed A1[%d] = %d\n", omp_get_thread_num(), i, A1[i]);
    }

    printf("\nUsing schedule(static, 2):\n");
    #pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < 6; i++) {
        A2[i] = 3 * A2[i] + 2;
        printf("Thread %d processed A2[%d] = %d\n", omp_get_thread_num(), i, A2[i]);
    }

    return 0;
}