#define MIN_INT -2147483648
#define SWAP(a, b, type) { \
   type temp;    \
   temp = a;     \
   a = b;        \
   b = temp;     \
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
// unused function
void bubble_sort(int* list, int length) {
   for(int i=0 ; i<length ; i++) {
      for(int j=0 ; j<length-i-1 ; j++) {
         if(list[j] > list[j+1]) {
            SWAP(list[j], list[j+1], int);
         }
      }
   }
}
void insertion_sort(int* list, int n) {
   int j;
   int key;
   for(int i=1 ; i<n ; i++) {
      key = list[i];
      for(j=i-1 ; j>=0 && list[j] > key; j--) {
         list[j+1] = list[j];
      }
      list[j+1] = key;
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
   int child;
   int rkey;
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
   //save last element
   int last = list[n];
   //shift list right by one, to use heap
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
   //restore last element
   list[n] = last;
}
int* median3(int* a, int* b, int* c) {
   if(*a <= *b && *b <= *c)
      return b;
   if(*a <= *c && *c <= *b)
      return c;
   if(*b <= *a && *a <= *c)
      return a;
   if(*b <= *c && *c <= *a)
      return c;
   if(*c <= *a && *a <= *b)
      return a;
   if(*c <= *b && *b <= *a)
      return b;
   return NULL;
}
void intro_sort(int* data, int from, int to, int depth) {
   int pivot;
   int from2, to2;
   int* m;
   from2 = from;
   to2 = to;
   //improve performance using tail recursion optimisation
   while(to2 > from2) {
      if(to2-from2+1 <= 16) {
         //use insertion sort when size <= 16 elements
         insertion_sort(data+from2, to2-from2+1);
         return;
      }
      if(!depth) {
         //using heapsort when depth reached its limit
         heap_sort(&data[from2], to2-from2+1);
         return;
      }
      depth--;
      m = median3(&data[from2], &data[(from2+to2)/2], &data[to2]);
      SWAP(*m, data[to2], int);
      pivot = partition(data, from2, to2);

      if(pivot < (from2+to2)/2) {
         intro_sort(data, from2, pivot-1, depth);
         from2 = pivot+1;
      } else {
         intro_sort(data, pivot+1, to2, depth);
         to2 = pivot-1;
      }
   }
}
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
      exit(-1);
   }
   fscanf(fp, "%d", &n);
   data = malloc(sizeof(int)*(n+1));
   for(int i=0 ; i<n ; i++)
      fscanf(fp, "%d", &data[i]);
   fclose(fp);

   clock_t start_time = clock();
   switch(atoi(argv[2])) {
      case 1: insertion_sort(data, n); break;
      case 2: quick_sort(data, 0, n-1); break;
      case 3: heap_sort(data, n); break;
      case 4: intro_sort(data, 0, n-1, 2*(int)log2(n)); break;
      default:
              fprintf(stderr, "Algorithm index must be between 1-4\n");
              exit(1);
   }
   clock_t term_time = clock();

   //TODO: use strchr() to correctly implement filename
   char* inputfile;
   inputfile = malloc(sizeof(char)*strlen(argv[1])+1);
   strcpy(inputfile, argv[1]);

   int fnameLen = 10;
   fnameLen += strlen(inputfile);
   char* fname;
   fname = malloc(sizeof(char)*strlen(argv[1]) + 1);

   char* path = inputfile;
   char* lastslash = path;
   while((path = strchr(path, '/'))) {
      lastslash = path;
   }
   path = NULL;
   strncpy(fname, inputfile, lastslash-inputfile+1);
   strcat(fname, "result_");
   strcat(fname, argv[2]);
   strcat(fname, "_");
   strcat(fname, lastslash+1);

   if(!(fp = fopen(fname, "w"))) {
      fprintf(stderr, "Writing to file %s failed\n", fname);
      exit(-1);
   }

   free(inputfile);
   free(fname);

   fprintf(fp, "%s\n%s\n%d\n%.6f\n", argv[1], argv[2], n,
         ((double)(term_time-start_time)/CLOCKS_PER_SEC));
   for(int i=0 ; i<n-1; i++) {
      fprintf(fp, "%d ", data[i]);
   }
   fprintf(fp, "%d", data[n-1]);
   fclose(fp);
   free(data);

   return 0;
}
