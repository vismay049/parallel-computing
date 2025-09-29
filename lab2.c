#include <stdio.h>
#include <omp.h>

int main() {
    int num_iterations;
    printf("Enter the number of iterations: ");
    scanf("%d", &num_iterations);

    double start_time = omp_get_wtime();  // Start timing

    #pragma omp parallel
    {
        #pragma omp for schedule(static,2)
        for (int i = 0; i < num_iterations; i++) {
            printf("Thread %d: Iteration %d\n", omp_get_thread_num(), i);
        }
    }

    double end_time = omp_get_wtime();  // End timing

    // Print time taken from the main thread only
    printf("\nTime taken: %f seconds\n", end_time - start_time);

    return 0;
}
