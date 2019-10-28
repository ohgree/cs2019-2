#define MIN_INT -2147483648
#define SWAP(a, b, type) { \
   type temp;    \
   temp = a;     \
   a = b;        \
   b = temp;     \
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bubble_sort(int* list, int length) {
   for(int i=0 ; i<length ; i++) {
      for(int j=0 ; j<length-i-1 ; j++) {
         if(list[j] > list[j+1]) {
            SWAP(list[j], list[j+1], int);
         }
      }
   }
}
int partition(int* list, int left, int right) {
   int pivot;
   pivot = left;
   for(int i=left ; i<right ; i++) {
      if(list[right] > list[i]) {
         SWAP(list[i], list[pivot], int);
         pivot++;
      }
   }
   SWAP(list[right], list[pivot], int);
   return pivot;
}
void quick_sort(int* list, int left, int right) {
   int pivot;
   if(left >= right)
      return;
   pivot = partition(list, left, right); 
   quick_sort(list, left, pivot-1);
   quick_sort(list, pivot+1, right);
}
void adjust(int* list, int root, int n) {
   int child, rkey;
   rkey = list[root];
   child = root*2;
   while(child <= n) {
      if(child < n && list[child] < list[child+1])
         child++;

      if(rkey > list[child])
         break;

      list[child/2] = list[child];
      child *= 2;
   }
   list[child/2] = rkey;
}
void heap_sort(int* list, int n) {
   for(int i=n ; i>0 ; i--)
      list[i] = list[i-1];
   for(int i=n/2 ; i>0 ; i--) 
      adjust(list, i, n);
   for(int i=n-1 ; i>0 ; i--) {
      SWAP(list[1], list[i+1], int);
      adjust(list, 1, i);
   }
   for(int i=0 ; i<n ; i++)
      list[i] = list[i+1];
}
void radix_sort(int* data, int n);
int main(int argc, const char* argv[]) {
   int n;
   int* data;
   FILE* fp;
   if(argc != 3) {
      fprintf(stderr, "Usage: %s filename index\n", argv[0]);
      exit(1);
   }
   if(!(fp = fopen(argv[1], "r"))) {
      fprintf(stderr, "Cannot open file %s\n", argv[1]);
      exit(1);
   }
   fscanf(fp, "%d", &n);
   data = malloc(sizeof(int)*(n+1));
   for(int i=0 ; i<n ; i++)
      fscanf(fp, "%d", &data[i]);
   fclose(fp);

   clock_t start_time = clock();
   switch(atoi(argv[2])) {
      case 1: bubble_sort(data, n); break;
      case 2: quick_sort(data, 0, n-1); break;
      case 3: heap_sort(data, n); break;
      case 4: radix_sort(data, n); break;
      default:
              fprintf(stderr, "Algorithm index must be between 1-4\n");
              exit(1);
   }
   clock_t term_time = clock();

   printf("[DEBUG]\n");
   printf("%s\n%s\n%d\n%.6f\n", argv[1], argv[2], n,
         ((double)(term_time-start_time)/CLOCKS_PER_SEC));
   for(int i=0 ; i<n ; i++) {
      printf("%d ", data[i]);
   }

   return 0;
}
