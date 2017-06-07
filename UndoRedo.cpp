#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef unsigned long long ull;

#define MAX 200

map <string, string> banco;
map <string, bool> comitted;

typedef struct a{
  char nome[MAX];
  char atributo[MAX];
  double vInit;
  double vEnd;
} rola;

void carregarBanco();
void printarBanco();
void analisarLog();

int main(void){
  carregarBanco();
  printarBanco();
  //analisarLog();
  return 0;
}

void carregarBanco(){
  FILE *f;
  int i;
  char c;
  char atributo[MAX];
  char valor[MAX];

  f = fopen("entrada.txt", "r");                                  // Abre o arquivo
  if(f == NULL){
    printf("Azedô\n");
    return;
  }
  while((c = fgetc(f)) != EOF){                                   // Enquanto nao terminar o arquivo
    for(i = 0; c != '=' && c != EOF; i++){
      atributo[i] = c;
      c = fgetc(f);
    }
    for(i = 0; c != '\n' && c != EOF; i++){                       // Enquanto ele nao chegar na nova linha
      c = fgetc(f);                                               // ou acabar o arquivo
      valor[i] = c;
    }
    valor[i] = '\0';
    if(c != EOF) banco[atributo] = valor;  // Se não for EOF, joga no map.
  }
  fclose(f);                                                      // Fecha o arquivo
  return;
}

void printarBanco(){                                              // itera no map e printa ele


  for(map<string, int>::iterator i = banco.begin(); i != banco.end(); i++){
    printf("%s = %d\n", i->first.c_str(), i->second);
  }
  printf("\n");
}

/*

void analisarLog(){
  FILE *f;
  char c, s[MAX], junk[MAX];
  ull i, size;
  bool CkptFound = false;
  f = fopen("log.txt", "r");
  fseek(f, 0, SEEK_END);
  size = ftell(f);                                              // salva o valor do tamanho do arquivo
  for(i = 1; i <= size; i++){                                   // Vai iterando até chegar no começo do arquivo
    fseek(f, size-i, SEEK_SET);
    if((c = fgetchar(f)) == '\n'){                              // Se é /n, é pq iniciou uma nova operação
      fgets(s, MAX, f);                                         // Pega essa operação.
      strcpy(junk, s);                                          // Copia para uma variavel que possa ser zoada
      junk[strlen(junk)-1] = '\0';                              // Coloca o /0 nela
      if(!strcmp(s, "<END CKPT>")) CkptFound = true;            // Se a operação for END_CKPT...
      junk[11] = '\0';
      else if(!strcmp(s, "<Start CKPT")){                       // Se a operação for start checkpoint...

      }
      junk[7] = '\0';
      else if(!strcmp(s, "<Commit")){                           // Se for um commit...

      }
      junk[6] = '\0';
      else if(!strcmp(s, "<start")){                            // Se for start transação....
      }
      else{                                                     // Se for uma operação de modificação no banco...
      }
    }
  }
}
*/
