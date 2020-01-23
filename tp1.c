#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h

int main(){

int i=0;
//pvs du joueur et du monstre
int nPVj = 40;
int nPVm = 40;
//sélecteurs d'attaque du joueur et du monstre
int nSelJ= 0;
int nSelM=0;
//initiative, permet de savoir qui joue
int nInit = 1;
//indicateur de défense, activé par l'action "défense", désactivé après une attaque s'il est activé
int nDefJ = 0;
int nDefM=0;
//nombre aléatoire entre int a et int b qui va servir de sélecteur au monstre.
int a=1;
int b=5;
int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}
//magie du joueur et du monstre
int nMaJ=20;
int nMaM=20;
//indicateur de poison, qui contient le nombre de tours d'effet
int nPoisonJ=0;
int nPoisonM=0;

	while(nPVj>0&&nPVm>0){
		
		//RAPPEL DES PVS ET PM
		printf("Vos points de vie : %d.\n", nPVj);
		for(i=0;i<nPVj;i++){
			printf("O");
		}
		printf("\n");
		printf("Vos points de Mana : %d.\n", nMaJ);
		printf("\n");
		printf("Les points de vie du monstre : %d.\n", nPVm);
		for(i=0;i<nPVm;i++){
			printf("O");
		}
		printf("\n");
		printf("Les points de mana du monstre : %d.\n", nMaM);
		
		printf("\nVous avez l'initiative.\n");
		
		//TOUR DU JOUEUR
		if(nInit=1){
			if(nPoisonJ>0){
				nPVj=nPVj-1;
				nPoisonJ=nPoisonJ-1;
				printf("Le poison fait effet ! Vous perdez 1PV !\nVoici vos PV : %d.\nLe poison fera encore effet %d tours.\n", nPVj, nPoisonJ);
			}
			
			if(nMaJ<20){
				nMaJ=nMaJ+1;
			}
			
			while(nInit==1){	
				printf("Voulez vous attaquer ? Saisissez : 1. Voulez vous vous defendre ? Saisissez 2. Lancer le sort de poison (10 PM) : saisissez 3. Lancer le sort d'antidote (10 PM) : saisissez 4.\n");
				scanf("%d",&nSelJ); 

				if(nSelJ!=1&&nSelJ!=2&&nSelJ!=3&&nSelJ!=4){
					printf("Choisissez entre 1 et 3.\n");
					scanf("%d",&nSelJ);
				}
				
				//ATTAQUE DU JOUEUR
				if(nSelJ==1){
					printf ("\n\nAttaque en cours !\n");
					
					//Si le monstre se défend
					if(nDefM==1){
						nPVm=nPVm-1;
						printf("Le monstre se defend, mais vous parvenez a le toucher !\nSes points de vie : %d. \n", nPVm);
						nDefM=0;
						nInit=0;
					}
					
					//Si le monstre ne se défend pas
					else{
						nPVm=nPVm-4;
						printf("Le monstre subit l'attaque de plein fouet.\nSes points de vie : %d. \n", nPVm);
						nInit=0;
					}
					
				}
				
				//DEFENSE DU JOUEUR
				if(nSelJ==2){
					printf("Vous vous defendez !\n");
					nDefJ=1;
					nInit=0;
				}
				
				//POISON DU JOUEUR
				if(nSelJ==3){
					if(nPoisonM==0&&nMaJ>=10){
						printf("Vous empoisonnez le monstre !\n");
						nPoisonM=5;
						nMaJ=nMaJ-10;
						nInit=0;
					}
					else{
						printf("Le monstre est deja empoisonne, ou vous n'avez plus de Mana. Choisissez une autre action !\n");
					}
			
				}
				//ANTIDOTE
				if(nSelJ==4){
					if(nPoisonJ>0&&nMaJ>=10){
						nPoisonJ=0;
						printf("Vous vous soignez ! \n");
						nInit=0;
					}
					else{
					printf("Vous n'etes pas empoisonne ou n'avez plus de Mana. Choisissez une autre action.");
					}
				}
			}
		}
		printf("\n");
		
		//TOUR DU MONSTRE
		if(nInit==0){
			if(nPoisonM>0){
				nPVm=nPVm-1;
				nPoisonM=nPoisonM-1;
				printf("Le poison fait effet ! Le monstre perd 1PV !\nVoici ses PV : %d.\nLe poison fera encore effet %d tours.\n", nPVm, nPoisonM);
			}
			
			if(nMaM<20){
				nMaM=nMaM+1;
			}
				
			while(nInit==0){
				
				printf("Le monstre choisit son mouvement.\n");
				
				nSelM=rand_a_b(a, b);
				
				//ATTAQUE DU MONSTRE
				if(nSelM==1){
					printf("Le monstre attaque ! \n");
				
					//Si le joueur se défend
					if(nDefJ==1){
						nPVj=nPVj-1;
						printf("Vous vous defendez, mais perdez tout de meme de la vie !\nVos points de vie : %d. \n", nPVj);
						nDefJ=0;
						nInit=1;
					}
				
					//Si le joueur ne se défend pas
					else{
						nPVj=nPVj-4;
						printf("Vous subissez l'attaque de plein fouet.\nVos points de vie : %d. \n", nPVj);
						nInit=1;
					}
				}
				
				//DEFENSE DU MONSTRE
				if(nSelM==2){
					printf("Le monstre se defend !\n");
					nDefM=1;
					nInit=1;
				}
				
				//POISON DU MONSTRE
				
				if(nSelM==3){
					if(nPoisonJ==0&&nMaM>=10){
						printf("Le monstre vous empoisonne !\n");
						nPoisonJ=5;
						nMaM=nMaM-10;
						nInit=1;
					}
				}		
			}
		}
		printf("\n");
	}

//FIN DE PARTIE

if(nPVj<=0&&nPVm<=0){printf("Egalite !");}

else{
	if(nPVj<=0){
		printf("GAME OVER");
	}
	
	if(nPVm<=0){
		printf("Vous avez gagne !");
	}
}
}