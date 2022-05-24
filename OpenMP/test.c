// OpenMP header
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
  
int main(int argc, char* argv[])
{
    int nthreads, tid;
  
    // Begin of parallel region
    #pragma omp parallel private(nthreads, tid)
    {
        // Getting thread number
        tid = omp_get_thread_num();
        printf("Beinvenue sur GFreya OS = %d\n",
               tid);
  
        if (tid == 0) {
  
            // Only master thread does this
            nthreads = omp_get_num_threads();
            printf("Le nombre de fils = %d\n",
                   nthreads);
        }
    }
}
