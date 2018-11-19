#include "lab4.h"


/*coloque tua resposta aqui*/

#include <stdlib.h>

//funcao abre arquivo
FILE *abre_arquivo(const char *arquivo){

    printf("abre arquivo");

	if (arquivo!=NULL){
		return fopen(arquivo, "rb");
	}
	return NULL;
}
//funcao fech arquivo
int fecha_arquivo(FILE *arq){
	return fclose(arq);
}
//abre um arquivo e retorna um vetor
times_t *le_times(const char *arquivo, unsigned int *numero_de_times){
  printf("--- le_times ----");
  if(numero_de_times == NULL) return NULL;

	FILE * arq = abre_arquivo(arquivo);
	if(arq==NULL){
        
        return NULL;
    }

	times_t * vet = NULL;
	times_t d;
	unsigned int cont=0;	

	vet=(times_t *)malloc(sizeof (times_t));
	
	if (vet!=NULL){
        //puts(arquivo nao existente);
		while (fread(&d, sizeof(times_t),1, arq) != 0){

			//printf("\n cont de times  %d\n", cont );
			//printf("\n leu time..");			

			vet=(times_t *)realloc(vet, sizeof(times_t)*(cont+1) );
			
			if (vet!=NULL) {
				printf("Realocou memoria..");
				vet[cont]=d;
			}
			else {
				printf("Erro na realocacao..");
			    *numero_de_times = 0;
				free (vet);
				vet = NULL;
				return NULL;
			}
			cont=cont+1;
	    }
      fecha_arquivo(arq);
  		*numero_de_times = cont;
  		return vet;
    }
    
    *numero_de_times = 0;
	return NULL;

}


/*
 * Encontra o jogador com a maior relacao entre cartao vermelho e numero de jogos (proporcao entre cartoes vermelhos e numero de jogos).
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor.
 * O jogador com essa maior relacao deve ser retornado dentro do ponteiro "jogador" e o time desse jogador deve ser retornado dentro do ponteiro "time".
 */

void encontra_jogador_cartao_vermelho_e_jogos(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){

	if (times == NULL || jogador == NULL || *jogador == NULL || time == NULL || *time == NULL )return;
    double propocao;
    double aux2;
    unsigned int i1 = 0,j1 = 0;
    aux2= (times[0].jogadores[0].cartoes_vermelhos)/(double)(times[0].jogadores[0].numero_jogos);
    for (unsigned int i = 0; i < num_times;i++ ){
      propocao = 0.0;

        for (unsigned int j = 0; j < NUM_JOGADORES; j++){
            propocao = (times[i].jogadores[j].cartoes_vermelhos)/(double)(times[i].jogadores[j].numero_jogos) ;
            if (propocao > aux2){

                aux2= propocao;
                i1=i;
                j1=j;


            }
        }

    }
    //print_jogador( jogador)

    *jogador = &times[i1].jogadores[j1]; //utilizacao de & por ser um ponteiro para ponteiro;
	*time = &times[i1];


	return ;

}

/*
 * Encontra o jogador artilheiro, aquele que fez mais gols.
 * O ponteiro "times" contem o vetor com todos os times e a variavel inteira "num_times" contem o numero total de times do vetor.
 * O jogador artilheiro deve ser retornado dentro do ponteiro "jogador" e o time do artilheiro deve ser retornado dentro do ponteiro "time".
 */

 void encontra_jogador_artilheiro(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
  

   if (times == NULL || jogador == NULL || *jogador == NULL || time == NULL || *time == NULL )return;
   unsigned int aux;
   unsigned int maior;
   unsigned int i1 = 0,j1 = 0;
   maior = (times[0].jogadores[0].gols_marcados);
   for (unsigned int i = 0; i < num_times;i++ ){
        for (unsigned int j = 0; j < NUM_JOGADORES; j++){
            aux = (times[i].jogadores[j].gols_marcados);
             if (aux > maior){

                maior = aux ;
                 i1=i;
                 j1=j;


           }
       }

   }
   //print_jogador( jogador)

   *jogador = &times[i1].jogadores[j1]; //utilizacao de & por ser um ponteiro para ponteiro;
*time = &times[i1];

	 return ;


 }
 /*
  * Encontra o jogador mais eficiente, aquele que fez mais gols em menos jogos.
  * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor.
  * O jogador mais eficiente deve ser retornado dentro do ponteiro "jogador" e o time desse jogador deve ser retornado dentro do ponteiro "time".
  */

void encontra_jogador_mais_eficiente(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
     if (times == NULL || jogador == NULL || *jogador == NULL || time == NULL || *time == NULL )return;
     unsigned int aux, aux2;
     unsigned int maior, menor;
     unsigned int i1 = 0,j1 = 0;
     maior = (times[0].jogadores[0].gols_marcados);
     menor= (times[0].jogadores[0].numero_jogos);
     for (unsigned int i = 0; i < num_times;i++ ){
          for (unsigned int j = 0; j < NUM_JOGADORES; j++){
              aux = (times[i].jogadores[j].gols_marcados);
              aux2= (times[i].jogadores[j].numero_jogos);
               if (aux > maior &&   aux2 < menor){

                  maior = aux ;
                  menor = aux2;
                   i1=i;
                   j1=j;


             }
         }

     }
     //print_jogador( jogador)

     *jogador = &times[i1].jogadores[j1]; //utilizacao de & por ser um ponteiro para ponteiro;
    *time = &times[i1];


	return;
}

/*
 * Encontra o time que possui mais titulos, sendo uma proporcao entre o numero de titulos (soma de todos os titulos) e o ano de fundacao (considere apenas o ano).
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor.
 * O time com mais titulos deve ser retornado dentro do ponteiro "time".
 */
void encontra_time_com_mais_titulos(times_t *times, unsigned int num_times, times_t **time){
 
     if (times == NULL || time == NULL || *time == NULL ) return;
    
    double aux = 0.0, proporcao= 0.0;
    unsigned int i1 = 0;

    
    aux = (times[0].numero_tit_estadual + times[0].numero_tit_brasileiros + times[0].numero_tit_libertadores)/ (double) (2018 - times[0].ano_fundacao );
    
    for (unsigned int i = 0; i < num_times; i++){
      proporcao = (times[i].numero_tit_estadual + times[i].numero_tit_brasileiros + times[i].numero_tit_libertadores)/ (double) (2018 - times[i].ano_fundacao);
      printf ("\n prop fora = %f",proporcao);
      
      if (proporcao > aux){
         aux = proporcao;
         printf ("\n aux  = %f",aux);
         i1 = i;
        
      }
    }
     printf ("\n ---- > %d \n", i1);
    *time = &times[i1];
	return ;

}

/*
 * Encontra o goleiro que defendeu mais penaltis em funcao do numero de jogos.
 * O ponteiro "times" contem o vetor contendo todos os times e a variavel inteira "num_times" contem o numero total de times do vetor.
 * O goleiro que defendeu mais times deve ser retornado dentro do ponteiro "jogador" e o time desse goleiro deve ser retornado dentro do ponteiro "time".
 */
void encontra_goleiro_que_defendeu_mais_penaltis(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){

  if (times == NULL || jogador == NULL || *jogador == NULL || time == NULL || *time == NULL )return;
  unsigned int aux, aux2;
  unsigned int maior, menor;
  unsigned int i1 = 0,j1 = 0;
  maior = (times[0].jogadores[0].penalti_defendidos);
  menor= (times[0].jogadores[0].numero_jogos);
  for (unsigned int i = 0; i < num_times;i++ ){
       for (unsigned int j = 0; j < NUM_JOGADORES; j++){
           aux = (times[i].jogadores[j].penalti_defendidos);
           aux2= (times[i].jogadores[j].numero_jogos);
            if (aux > maior &&   aux2 < menor){

               maior = aux ;
               menor = aux2;
                i1=i;
                j1=j;


          }
      }

  }
  //print_jogador( jogador)

  *jogador = &times[i1].jogadores[j1]; //utilizacao de & por ser um ponteiro para ponteiro;
  *time = &times[i1];


	return ;

}

/* * Encontra o jogador mais agressio, considerando peso 5 para cartao vermelho, 1 para amarelo e 0.2 para faltas cometidas.
 * O ponteiro "times" contem o vetor contendo todos os timese a variavel inteira "num_times" contem o numero total de times do vetor.
 * O jogador mais agressivo deve ser retornado dentro do ponteiro "jogador" e o time desse jogador deve ser retornado dentro do ponteiro "time".
 */
void encontra_jogador_mais_agressivo(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){

		if (times == NULL || jogador == NULL || *jogador == NULL || time == NULL || *time == NULL )return;
        unsigned int aux;
        unsigned int maior;
        unsigned int i1 = 0,j1 = 0;
        maior = (0.5 * (times[0].jogadores[0].cartoes_vermelhos) + (times[0].jogadores[0].cartoes_amarelos) + 0.2 *(times[0].jogadores[0].faltas_cometidas));
        for (unsigned int i = 0; i < num_times;i++ ){
             for (unsigned int j = 0; j < NUM_JOGADORES; j++){
                 aux = (0.5 * (times[i].jogadores[j].cartoes_vermelhos) + (times[i].jogadores[j].cartoes_amarelos) + 0.2 *(times[i].jogadores[j].faltas_cometidas));
                  if (aux > maior){

                     maior = aux ;
                      i1=i;
                      j1=j;


                }
            }

        }
        //print_jogador( jogador)

        *jogador = &times[i1].jogadores[j1]; //utilizacao de & por ser um ponteiro para ponteiro;
        *time = &times[i1];


}
