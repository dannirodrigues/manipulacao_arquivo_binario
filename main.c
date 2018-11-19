#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"



void print_time(times_t* time){
  printf("\n ----------times ------------- \n");
	printf(" esta = %s\t d = %d\t m %d\t a = %d\t titu b = %d\t  n copa b = %d\t tit lib = %d\t tit est = %d\n",     time->estado,
												           time->dia_fundacao,
												           time->mes_fundacao,
												           time->ano_fundacao,
												           time->numero_tit_brasileiros,
												           time->numero_copas_brasil,
												           time->numero_tit_libertadores,
												           time->numero_tit_estadual);

}

void print_jogador(jogador_t* jogador){

	printf("nome = %s\n pos = %d\n gols = %d\n bolas roubads = %d\n num de jogs = %d\n final certas = %d\n final erradas = %d\n falt receb %d\n falt cometids = %d\n cart verme = %d\n cart amare = %d\n penal de fe = %d\n defesa = %d\n ", jogador->nome,
																				jogador->posicao,
																				jogador->gols_marcados,
																				jogador->bolas_roubadas,
																				jogador->numero_jogos,
																				jogador->finalizoes_certas,
																				jogador->finalizoes_erradas,
																				jogador->faltas_recebidas,
																				jogador->faltas_cometidas,
																				jogador->cartoes_vermelhos,
																				jogador->cartoes_amarelos,
																				jogador->penalti_defendidos,
																				jogador->defesas);

}




int main(){
	printf("--- main () ----");
	
	unsigned int numero_de_times;
    times_t *vet;
	
    vet = le_times("arq.dat", &numero_de_times);
    /*printf("\n numros de times = %d\n", numero_de_times);
    printf ("\n \n");
    for (unsigned int i = 0; i < numero_de_times; i++){
		for (unsigned int j = 0; j< NUM_JOGADORES; j++){
          print_jogador(&vet[i].jogadores[j]);
		}
    }*/printf ("\n ----- TIMES ---------\n");
    for (unsigned int i = 0; i < numero_de_times; i++){
		print_time(&vet[i]);
		
	}
    jogador_t *jogador ;
    times_t *time;
    encontra_time_com_mais_titulos(vet , numero_de_times, &time);
    
    printf ("\n ------Time ------\n");
	print_time (time);
	printf ("\n------Jogador-------\n");
	//print_jogador(jogador);
   return 0;

}
