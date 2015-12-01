#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
   FILE *pFile;
   FILE *fp;
   long  lSize;
   size_t result;


   char c[] = "this is tutorialspoint";
   char buffer[100];

   /* Open file for both reading and writing */
  // fp = fopen("file.txt", "w+");
   fp = fopen("myfile.bin","rb");
   /* Write data to the file */
   fwrite(c, strlen(c) + 1, 1, fp);

   /* Seek to the beginning of the file */
   fseek(fp, SEEK_SET, 0);

   /* Read and display data */
   fread(buffer, strlen(c)+1, 1, fp);
   printf("%s\n", buffer);
   

   fclose(fp);
   //free (buffer);

   char * buffer2;

   pFile = fopen("myfile.bin", "r");
   fseek(pFile, 0, SEEK_END);
   lSize = ftell(pFile);
   rewind(pFile);
    // allocate memory to contain the whole file:
    buffer2 = (char*) malloc (sizeof(char)*lSize);
    if (buffer2 == NULL) {fputs ("Memory error",stderr); exit (2);}
    char arr[20];
    fread(arr, 1,1 , fp);
    fread(buffer2, 1,1,fp);
    printf("%s rr is s\n", arr);
    fclose(fp);
    free(buffer2);
   return(0);
}
