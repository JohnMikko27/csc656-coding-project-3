const char* dgemv_desc = "Basic implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of basic matrix multiply
   for (int row = 0; row < n; row++) {
      double sum = 0.0;
      for (int col = 0; col < n; col++) {
         // row * n skips the necessary elements and gets the necessary "row" in the 1D array
         // while adding col gets the correct "column" in that "row"
         sum += A[row * n + col] * x[col];
      }
      y[row] += sum;
   }
}
