#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

struct client {
  int account_id;
  char name[30];
  int balance;
};

typedef struct client Client;

void client_update() {

  FILE *fp = fopen("clients.txt", "r");

  Client centry[100];
  int i = 0;
  printf("sizeof read %lu\n", sizeof(struct client));
  /*while ((res = fread(&centry, sizeof(struct client), 1, fp)) != 0) {
    printf("Bytes read %u\n", res);
    printf("%u %s %d\n", 
      centry.account_id,
      centry.name, 
      centry.balance 
    );
    i++;
  }*/
  int res = fread(&centry, sizeof(struct client), 100, fp); 
  for (i = 0; i < res; i++)
    printf("%u %s %d\n", centry[i].account_id,
    centry[i].name, 
    centry[i].balance);

  puts("File contents printed");
  printf("%d records read\n", i);

  Client update;
  printf("position at %lu (before seek)\n", ftell(fp));
  fseek(fp, -sizeof(update)*2, SEEK_END);
  printf("position at %lu\n", ftell(fp));
  fread(&update, sizeof(update), 1, fp);
  printf("Two from back\n");
  printf("%u %s %d\n", 
    update.account_id,
    update.name, 
    update.balance);

  fclose(fp);
  exit(0);
}