void updatePtrs(int* ptrA, int* ptrB, const int* val);

void updatePtrs(int* ptrA, int* ptrB, const int* val)
{
  *ptrA += *val;
  *ptrB += *val;
}
