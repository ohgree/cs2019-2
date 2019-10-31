#include <stdio.h>
#include <stdlib.h>
int main(int argc, const char* argv[]) {
   FILE* fp;
   if(argc < 3) {
      fprintf(stderr, "Usage: %s filename num min max [seed]\n", argv[0]);
      exit(1);
   }
   if(!(fp = fopen(argv[1], "w"))) {
      fprintf(stderr, "Error while opening file %s\n", argv[0]);
      exit(1);
   }
   int num = atoi(argv[2]);
   int min = atoi(argv[3]);
   int max = atoi(argv[4]);
   srand(atoi(argv[5]));
   fprintf(fp, "%d ", num);
   for(int i=0 ; i<num-1 ; i++) {
      fprintf(fp, "%d ", rand()%(max-min) + min);
   }
   fprintf(fp, "%d", rand()%(max-min) + min);
   fclose(fp);

   return 0;
}
