#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

#define MAX 200

map <string, int> banco;

void carregarBanco();
void printarBanco();

int main(void){
  carregarBanco();
  printarBanco();
  return 0;
}

void carregarBanco(){
  FILE *f;
  int i;
  char c;
  char atributo[MAX];
  char valor[MAX];
  printf("vou comecar a ler\n");
  f = fopen("entrada.txt", "r");
  if(f == NULL){
    printf("fodeu\n");
    return;
  }
  while((c = fgetc(f)) != EOF){
    for(i = 0; c != '=' && c != EOF; i++){
      atributo[i] = c;
      c = fgetc(f);
    }
    for(i = 0; c != '\n' && c != EOF; i++){
      c = fgetc(f);
      valor[i] = c;
    }
    valor[i] = '\0';
    if(c != EOF) banco[atributo] = ((int) strtol(valor, 0, 10));
  }
  printf("li\n");
  fclose(f);
  return;
}

void printarBanco(){

  for(map<string, int>::iterator i = banco.begin(); i != banco.end(); i++){
    printf("%s = %d\n", i->first.c_str(), i->second);
  }
  printf("\n");
}
