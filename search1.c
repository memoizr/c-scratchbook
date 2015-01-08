void *lsearch (void *key, void *base, int n, int elemSize, int (*cmpfn)(void *, vnd*))
{
  for (int i=0; i < n; i++) {
    void *elemAddr = (char*) base + i *elemSize;
    if (cmpfn(key, elemAddr) == 0)
      return elemAddr;
  }
  return NULL;
}


int IntCmp(void *elem1, void *elem2) {
  int *ip1 = elem1;
  int *ip2 = elem2;

  return *ip1 - *ip2;
}
