#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

typedef struct client {
  int account_id;
  char name[30];
  int balance;
} Client;

int main() {

  // CHANGE 0 - make the necessary change to fopen
  FILE *fp = fopen("clients.txt", "r");
  Client entries[100];
  int i = 0;
  int res = fread(&entries, sizeof(Client), 100, fp); 

  printf("%d records read\n", res);
  for (i = 0; i < res; i++)
    printf("- %u %s %d\n", entries[i].account_id,
    entries[i].name, 
    entries[i].balance);

  puts("File contents printed");

  // code that is required to update an entry 
  Client update;
  puts("\nUpdate 2nd account from last");
  puts("with balance = 10000");
  printf("position at %lu (before seek)\n", ftell(fp));
  // write the code to move FP using fseek
  // to the right location
  // CHANGE 1 
  // 
  printf("position at %lu (after seek)\n", ftell(fp));
  fread(&update, sizeof(update), 1, fp);
  printf("%u %s %d\n\n", update.account_id,
    update.name, 
    update.balance);

  // CHANGE 2 - the right value? 
  update.balance = -100;

  // provide code to write to file
  // CHANGE 3 - the two functions calls 
  //
  //

  // verify whether it has happened correctly
  // if not, use the unix command 
  // cp clients.txt.bak clients.txt 
  // and try again
  puts("Validating update");
  rewind(fp);
  res = fread(&entries, sizeof(Client), 100, fp); 
  for (i = 0; i < res; i++)
    printf("- %u %s %d\n", entries[i].account_id,
    entries[i].name, 
    entries[i].balance);

  fclose(fp);
  return 0;
}