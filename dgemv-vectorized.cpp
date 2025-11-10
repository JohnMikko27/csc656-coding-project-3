const char* dgemv_desc = "Vectorized implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of vectorized vector-matrix multiply
   for (int row = 0; row < n; row++) {
      double sum = 0.0;
      // increment by 8 for vectorization and because the problem sizes are divisibly by 8
      for (int col = 0; col < n; col += 8) { 
         // row * n skips the necessary elements and gets the necessary "row" in the 1D array
         // while adding col gets the correct "column" in that "row"
         sum += A[row * n + col] * x[col];
         sum += A[row * n + col + 1] * x[col + 1];
         sum += A[row * n + col + 2] * x[col + 2];
         sum += A[row * n + col + 3] * x[col + 3];
         sum += A[row * n + col + 4] * x[col + 4];
         sum += A[row * n + col + 5] * x[col + 5];
         sum += A[row * n + col + 6] * x[col + 6];
         sum += A[row * n + col + 7] * x[col + 7];
      }
      y[row] += sum;
   }
}
