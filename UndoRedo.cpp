#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

typedef unsigned long long ull;

#define MAX 200

typedef struct a{
  string nome;
  string atributo;
  string velho;
  string novo;
} transaction_t;

map <string, string> banco;
map <string, bool> committed;
stack <transaction_t> redo;
queue <transaction_t> undo;

void carregarBanco();
void printarBanco();
void analisarLog();

int main(void){
  carregarBanco();
  //printarBanco();
  analisarLog();
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
    atributo[i] = '\0';
    for(i = 0; c != '\n' && c != EOF; i++){                       // Enquanto ele nao chegar na nova linha
      c = fgetc(f);                                               // ou acabar o arquivo
      valor[i] = c;
    }
    valor[i] = '\0';
    if(c != EOF) banco[atributo] = valor;                         // Se não for EOF, joga no map.
  }
  fclose(f);                                                      // Fecha o arquivo
  return;
}

void printarBanco(){                                              // itera no map e printa ele

  printf("\n");
  for(map<string, string>::iterator i = banco.begin(); i != banco.end(); i++){
    printf("%s = %s\n", i->first.c_str(), i->second.c_str());
  }
  printf("\n");
}

void analisarLog(){
  FILE *f;
  char c, s[MAX], junk[MAX], tmpname[MAX];
  ull i, j, k, size;
  bool CkptFound = false;
  f = fopen("log.txt", "r");
  fseek(f, 0, SEEK_END);
  size = ftell(f);                                              // salva o valor do tamanho do arquivo
  for(i = 2; i <= size; i++){                                   // Vai iterando até chegar no começo do arquivo
    fseek(f, size-i, SEEK_SET);
    if((c = fgetc(f)) == '\n'){                                 // Se é /n, é pq iniciou uma nova operação
      fgets(s, MAX, f);                                         // Pega essa operação.
      strcpy(junk, s);                                          // Copia para uma variavel que possa ser zoada
      junk[strlen(junk)-1] = '\0';                              // Coloca o /0 nela
      if(!strcmp(s, "<END CKPT>")) CkptFound = true;            // Se a operação for END_CKPT...
      else if(junk[11] = '\0', !strcmp(junk, "<Start CKPT")){      // Se a operação for start checkpoint...

      }
      else if(junk[7] = '\0', !strcmp(junk, "<Commit")){           // Se for um commit...
        for(j = 8, k = 0; s[j] != '>' ;j++){
          tmpname[k++] = s[j];
        }
        tmpname[k] = '\0';
        committed[tmpname] = true;
        printf("%s\n", tmpname);
      }
      else if(junk[6] = '\0', !strcmp(junk, "<start")){            // Se for start transação....
      }
      else{                                                     // Se for uma operação de modificação no banco...
        
      }
    }
  }
}
