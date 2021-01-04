void updatePtrs(int* restrict ptrA, int* restrict ptrB,
                const int* restrict val);

void updatePtrs(int* restrict ptrA, int* restrict ptrB, const int* restrict val)
{
  *ptrA += *val;
  *ptrB += *val;
}
