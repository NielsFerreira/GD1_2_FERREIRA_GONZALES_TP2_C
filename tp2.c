#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h

int main(){

int i=0;
//pvs du joueur et du monstre
int nPVj1 = 30;
int nPVj2 = 30;
int nPVj3 = 30;
int nPVm1 = 30;
int nPVm2 = 30;
int nPVm3 = 30;
//sélecteurs d'attaque du joueur et du monstre
int nSelJ= 0;
int nSelM=0;
//initiative, permet de savoir qui joue
int nInit = 1;
//indicateur de défense, activé par l'action "défense", désactivé après une attaque s'il est activé
int nDefJ1=0;
int nDefJ2=0;
int nDefJ3=0;
int nDefM1=0;
int nDefM2=0;
int nDefM3=0;
//nombre aléatoire entre int a et int b qui va servir de sélecteur au monstre.
int a=1;
int b=5;
int rand_a_b(int a, int b){
    return rand()%(b-a) +a;
}

int c = 1;
int d = 4;
int rand_c_d(int c, int d){
	return rand()%(d-c)+c;
}

//magie du joueur et du monstre
int nMaJ1=20;
int nMaM1=20;
int nMaM2=20;
int nMaM3=20;
//indicateur de poison, qui contient le nombre de tours d'effet
int nPoisonJ1=0;
int nPoisonJ2=0;
int nPoisonJ3=0;
int nPoisonM1=0;
int nPoisonM2=0;
int nPoisonM3=0;
//indicateur d'initiative parmi les monstres
int nInitM = 0;
//indicateur de choix d'attaque parmi les monstres
int nSelAM = 0;

	while(nPVj1+nPVj2+nPVj3>0&&nPVm1+nPVm2+nPVm3>0){
		
		//RAPPEL DES PVS ET PM
		printf("Vos points de vie : %d.\n", nPVj1);
		for(i=0;i<nPVj1;i++){
			printf("O");
		}
		printf("\n");
		printf("Vos points de Mana : %d.\n", nMaJ1);
		printf("\n");
		printf("Les points de vie du premier monstre : %d.\n", nPVm1);
		for(i=0;i<nPVm1;i++){
			printf("O");
		}
		printf("\n");
		printf("Les points de mana du premier monstre : %d.\n", nMaM1);
		
		printf("Les points de vie du deuxième monstre : %d.\n", nPVm2);
		for(i=0;i<nPVm2;i++){
			printf("O");
		}
		printf("\n");
		printf("Les points de mana du deuxième monstre : %d.\n", nMaM2);
		
		printf("Les points de vie du troisième monstre : %d.\n", nPVm3);
		for(i=0;i<nPVm3;i++){
			printf("O");
		}
		printf("\n");
		printf("Les points de mana du troisième monstre : %d.\n", nMaM3);
		
		
		printf("\nVous avez l'initiative.\n");
		
		//TOUR DU JOUEUR
		if(nInit=1){
			if(nPoisonJ1>0){
				nPVj1=nPVj1-1;
				nPoisonJ1=nPoisonJ1-1;
				printf("Le poison fait effet ! Vous perdez 1PV !\nVoici vos PV : %d.\nLe poison fera encore effet %d tours.\n", nPVj1, nPoisonJ1);
			}
			
			if(nMaJ1<20){
				nMaJ1=nMaJ1+1;
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
					if(nDefM1==1){
						nPVm1=nPVm1-1;
						printf("Le monstre se defend, mais vous parvenez a le toucher !\nSes points de vie : %d. \n", nPVm1);
						nDefM1=0;
						nInit=0;
					}
					
					//Si le monstre ne se défend pas
					else{
						nPVm1=nPVm1-4;
						printf("Le monstre subit l'attaque de plein fouet.\nSes points de vie : %d. \n", nPVm1);
						nInit=0;
					}
					
				}
				
				//DEFENSE DU JOUEUR
				if(nSelJ==2){
					printf("Vous vous defendez !\n");
					nDefJ1=1;
					nInit=0;
				}
				
				//POISON DU JOUEUR
				if(nSelJ==3){
					if(nPoisonM1==0&&nMaJ1>=10){
						printf("Vous empoisonnez le monstre !\n");
						nPoisonM1=5;
						nMaJ1=nMaJ1-10;
						nInit=0;
					}
					else{
						printf("Le monstre est deja empoisonne, ou vous n'avez plus de Mana. Choisissez une autre action !\n");
					}
			
				}
				//ANTIDOTE
				if(nSelJ==4){
					if(nPoisonJ1>0&&nMaJ1>=10){
						nPoisonJ1=0;
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
			
			//SELECTEUR DE MONSTRE
			nInitM = 1;
			
			if(nInitM==1&&nPVm1>0){
			
				if(nPoisonM1>0){
					nPVm1=nPVm1-1;
					nPoisonM1=nPoisonM1-1;
					printf("Le poison fait effet ! Le premier monstre perd 1PV !\nVoici ses PV : %d.\nLe poison fera encore effet %d tours.\n", nPVm1, nPoisonM1);
				}
				
				if(nMaM1<20){
					nMaM1=nMaM1+1;
				}
					
				while(nInit==0&&nInitM==1){
					
					printf("Le premier monstre choisit son mouvement.\n");
					
					nSelM=rand_a_b(a, b);
					
					//ATTAQUE DU MONSTRE
					if(nSelM==1){
						printf("Le premier monstre attaque ! \n");
						nSelAM=rand_c_d(c,d);
						
						//SI LE MONSTRE ATTAQUE LE PERSONNAGE 1
						if (nSelAM==1&&nPVj1!=0){
							//Si le joueur se défend
							if(nDefJ1==1){
								nPVj1=nPVj1-1;
								printf("Le monstre attaque le personnage 1 ! Vous vous defendez, mais perdez tout de meme de la vie !\nVos points de vie : %d. \n", nPVj1);
								nDefJ1=0;
								nInitM=2;
							}
					
							else if (nPVj1==0){
								printf("Le monstre hésite entre deux cibles...\n.");
							}
							
							//Si le joueur ne se défend pas
							else{
								nPVj1=nPVj1-4;
								printf("Le monstre attaque le personnage 1 ! Vous subissez l'attaque de plein fouet.\nVos points de vie : %d. \n", nPVj1);
								nInitM=2;
							}
						}
						
						//SI LE MONSTRE ATTAQUE LE PERSONNAGE 2
						if (nSelAM==1&&nPVj2!=0){
							//Si le joueur se défend
							if(nDefJ2==1){
								nPVj2=nPVj2-1;
								printf("Le monstre attaque le personnage 2 ! Vous vous defendez, mais perdez tout de meme de la vie !\nVos points de vie : %d. \n", nPVj2);
								nDefJ2=0;
								nInitM=2;
							}
					
							else if (nPVj2==0){
								printf("Le monstre hésite entre deux cibles...\n.");
							}
							
							//Si le joueur ne se défend pas
							else{
								nPVj2=nPVj2-4;
								printf("Le monstre attaque le personnage 2 ! Vous subissez l'attaque de plein fouet.\nVos points de vie : %d. \n", nPVj1);
								nInitM=2;
							}
						}
						
						//SI LE MONSTRE ATTAQUE LE PERSONNAGE 3
						if (nSelAM==1&&nPVj3!=0){
							//Si le joueur se défend
							if(nDefJ3==1){
								nPVj3=nPVj3-1;
								printf("Le monstre attaque le personnage 3 ! Vous vous defendez, mais perdez tout de meme de la vie !\nVos points de vie : %d. \n", nPVj1);
								nDefJ3=0;
								nInitM=2;
							}
					
							else if (nPVj3!=0){
								printf("Le monstre hésite entre deux cibles...\n.");
							}
							
							//Si le joueur ne se défend pas
							else{
								nPVj3=nPVj3-4;
								printf("Le monstre attaque le personnage 1 ! Vous subissez l'attaque de plein fouet.\nVos points de vie : %d. \n", nPVj1);
								nInitM=2;
							}
						}
						
						
					}
									
					//DEFENSE DU MONSTRE
					if(nSelM==2){
						printf("Le premier monstre se defend !\n");
						nDefM1=1;
						nInitM=2;
					}
					
					//POISON DU MONSTRE
					
					if(nSelM==3){
						nSelAM=rand_c_d(c,d);
						
						if(nSelAM=1&&nPVj1>0&&nMaM1>=10&&nPoisonJ1==0){
							printf("Le premier monstre empoisonne le personnage 1 !\n");
							nPoisonJ1=5;
							nMaM1=nMaM1-10;
							nInitM=2;
						}
						
						if(nSelAM=2&&nPVj2>0&&nMaM1>=10&&nPoisonJ2==0){
							printf("Le premier monstre empoisonne le personnage 2 !\n");
							nPoisonJ2=5;
							nMaM1=nMaM1-10;
							nInitM=2;
						}
						
						if(nSelAM=3&&nPVj3>0&&nMaM1>=10&&nPoisonJ3==0){
							printf("Le premier monstre empoisonne le personnage 3 !\n");
							nPoisonJ3=5;
							nMaM1=nMaM1-10;
							nInitM=2;
						}
					}
				
				}
				
				
			}
			
			else{
				nInitM = 2;
			}
			
			//TOUR DU DEUXIEME MONSTRE
			
			if(nInitM==2&&nPVm2>0){
			
				if(nPoisonM2>0){
					nPVm2=nPVm2-1;
					nPoisonM2=nPoisonM2-1;
					printf("Le poison fait effet ! Le deuxieme monstre perd 1PV !\nVoici ses PV : %d.\nLe poison fera encore effet %d tours.\n", nPVm2, nPoisonM2);
				}
				
				if(nMaM2<20){
					nMaM2=nMaM2+1;
				}
					
				while(nInit==0&&nInitM==2){
					
					printf("Le premier monstre choisit son mouvement.\n");
					
					nSelM=rand_a_b(a, b);
					
					//ATTAQUE DU MONSTRE
					if(nSelM==1){
						printf("Le premier monstre attaque ! \n");
						nSelAM=rand_c_d(c,d);
						
						//SI LE MONSTRE ATTAQUE LE PERSONNAGE 1
						if (nSelAM==1&&nPVj1!=0){
							//Si le joueur se défend
							if(nDefJ1==1){
								nPVj1=nPVj1-1;
								printf("Le monstre attaque le personnage 1 ! Vous vous defendez, mais perdez tout de meme de la vie !\nVos points de vie : %d. \n", nPVj1);
								nDefJ1=0;
								nInitM=3;
							}
					
							else if (nPVj1==0){
								printf("Le monstre hésite entre deux cibles...\n.");
							}
							
							//Si le joueur ne se défend pas
							else{
								nPVj1=nPVj1-4;
								printf("Le monstre attaque le personnage 1 ! Vous subissez l'attaque de plein fouet.\nVos points de vie : %d. \n", nPVj1);
								nInitM=3;
							}
						}
						
						//SI LE MONSTRE ATTAQUE LE PERSONNAGE 2
						if (nSelAM==1&&nPVj2!=0){
							//Si le joueur se défend
							if(nDefJ2==1){
								nPVj2=nPVj2-1;
								printf("Le monstre attaque le personnage 2 ! Vous vous defendez, mais perdez tout de meme de la vie !\nVos points de vie : %d. \n", nPVj2);
								nDefJ2=0;
								nInitM=3;
							}
					
							else if (nPVj2==0){
								printf("Le monstre hésite entre deux cibles...\n.");
							}
							
							//Si le joueur ne se défend pas
							else{
								nPVj2=nPVj2-4;
								printf("Le monstre attaque le personnage 2 ! Vous subissez l'attaque de plein fouet.\nVos points de vie : %d. \n", nPVj1);
								nInitM=3;
							}
						}
						
						//SI LE MONSTRE ATTAQUE LE PERSONNAGE 3
						if (nSelAM==1&&nPVj3!=0){
							//Si le joueur se défend
							if(nDefJ3==1){
								nPVj3=nPVj3-1;
								printf("Le monstre attaque le personnage 3 ! Vous vous defendez, mais perdez tout de meme de la vie !\nVos points de vie : %d. \n", nPVj1);
								nDefJ3=0;
								nInitM=3;
							}
					
							else if (nPVj3!=0){
								printf("Le monstre hésite entre deux cibles...\n.");
							}
							
							//Si le joueur ne se défend pas
							else{
								nPVj3=nPVj3-4;
								printf("Le monstre attaque le personnage 3 ! Vous subissez l'attaque de plein fouet.\nVos points de vie : %d. \n", nPVj1);
								nInitM=3;
							}
						}
						
						
					}
									
					//DEFENSE DU MONSTRE
					if(nSelM==2){
						printf("Le deuxieme monstre se defend !\n");
						nDefM2=1;
						nInitM=3;
					}
					
					//POISON DU MONSTRE
					
					if(nSelM==3){
						nSelAM=rand_c_d(c,d);
						
						if(nSelAM=1&&nPVj1>0&&nMaM2>=10&&nPoisonJ1==0){
							printf("Le deuxieme monstre empoisonne le personnage 1 !\n");
							nPoisonJ1=5;
							nMaM2=nMaM2-10;
							nInitM=3;
						}
						
						if(nSelAM=2&&nPVj2>0&&nMaM2>=10&&nPoisonJ2==0){
							printf("Le deuxieme monstre empoisonne le personnage 2 !\n");
							nPoisonJ2=5;
							nMaM2=nMaM2-10;
							nInitM=3;
						}
						
						if(nSelAM=3&&nPVj3>0&&nMaM2>=10&&nPoisonJ3==0){
							printf("Le deuxieme monstre empoisonne le personnage 3 !\n");
							nPoisonJ3=5;
							nMaM2=nMaM2-10;
							nInitM=3;
						}
					}
				
				}
				
				
			}
			
			else{
				nInitM = 3;
			}

			//TOUR DU TROISIEME MONSTRE
			
			if(nInitM==3&&nPVm3>0){
			
				if(nPoisonM3>0){
					nPVm3=nPVm3-1;
					nPoisonM3=nPoisonM3-1;
					printf("Le poison fait effet ! Le troisième monstre perd 1PV !\nVoici ses PV : %d.\nLe poison fera encore effet %d tours.\n", nPVm3, nPoisonM3);
				}
				
				if(nMaM3<20){
					nMaM3=nMaM3+1;
				}
					
				while(nInit==0&&nInitM==3){
					
					printf("Le troisieme monstre choisit son mouvement.\n");
					
					nSelM=rand_a_b(a, b);
					
					//ATTAQUE DU MONSTRE
					if(nSelM==1){
						printf("Le troisieme monstre attaque ! \n");
						nSelAM=rand_c_d(c,d);
						
						//SI LE MONSTRE ATTAQUE LE PERSONNAGE 1
						if (nSelAM==1&&nPVj1!=0){
							//Si le joueur se défend
							if(nDefJ1==1){
								nPVj1=nPVj1-1;
								printf("Le monstre attaque le personnage 1 ! Vous vous defendez, mais perdez tout de meme de la vie !\nVos points de vie : %d. \n", nPVj1);
								nDefJ1=0;
								nInit=1;
							}
					
							else if (nPVj1==0){
								printf("Le monstre hésite entre deux cibles...\n.");
							}
							
							//Si le joueur ne se défend pas
							else{
								nPVj1=nPVj1-4;
								printf("Le monstre attaque le personnage 1 ! Vous subissez l'attaque de plein fouet.\nVos points de vie : %d. \n", nPVj1);
								nInit=1;
							}
						}
						
						//SI LE MONSTRE ATTAQUE LE PERSONNAGE 2
						if (nSelAM==1&&nPVj2!=0){
							//Si le joueur se défend
							if(nDefJ2==1){
								nPVj2=nPVj2-1;
								printf("Le monstre attaque le personnage 2 ! Vous vous defendez, mais perdez tout de meme de la vie !\nVos points de vie : %d. \n", nPVj2);
								nDefJ2=0;
								nInit=1;
							}
					
							else if (nPVj2==0){
								printf("Le monstre hésite entre deux cibles...\n.");
							}
							
							//Si le joueur ne se défend pas
							else{
								nPVj2=nPVj2-4;
								printf("Le monstre attaque le personnage 2 ! Vous subissez l'attaque de plein fouet.\nVos points de vie : %d. \n", nPVj1);
								nInit=1;
							}
						}
						
						//SI LE MONSTRE ATTAQUE LE PERSONNAGE 3
						if (nSelAM==1&&nPVj3!=0){
							//Si le joueur se défend
							if(nDefJ3==1){
								nPVj3=nPVj3-1;
								printf("Le monstre attaque le personnage 3 ! Vous vous defendez, mais perdez tout de meme de la vie !\nVos points de vie : %d. \n", nPVj1);
								nDefJ3=0;
								nInit=1;
							}
					
							else if (nPVj3!=0){
								printf("Le monstre hésite entre deux cibles...\n.");
							}
							
							//Si le joueur ne se défend pas
							else{
								nPVj3=nPVj3-4;
								printf("Le monstre attaque le personnage 3 ! Vous subissez l'attaque de plein fouet.\nVos points de vie : %d. \n", nPVj1);
								nInit=1;
							}
						}
						
						
					}
									
					//DEFENSE DU MONSTRE
					if(nSelM==2){
						printf("Le troisieme monstre se defend !\n");
						nDefM3=1;
						nInit=1;
					}
					
					//POISON DU MONSTRE
					
					if(nSelM==3){
						nSelAM=rand_c_d(c,d);
						
						if(nSelAM=1&&nPVj1>0&&nMaM3>=10&&nPoisonJ1==0){
							printf("Le troisieme monstre empoisonne le personnage 1 !\n");
							nPoisonJ1=5;
							nMaM3=nMaM3-10;
							nInit=1;
						}
						
						if(nSelAM=2&&nPVj2>0&&nMaM3>=10&&nPoisonJ2==0){
							printf("Le troisieme monstre empoisonne le personnage 2 !\n");
							nPoisonJ2=5;
							nMaM3=nMaM3-10;
							nInit=1;
						}
						
						if(nSelAM=3&&nPVj3>0&&nMaM3>=10&&nPoisonJ3==0){
							printf("Le troisieme monstre empoisonne le personnage 3 !\n");
							nPoisonJ3=5;
							nMaM2=nMaM3-10;
							nInit=1;
						}
					}
				
				}
				
				
			}
			
			else{
				nInit=1;
			}

			
			
			
		}
		printf("\n");
		
		//CONTROLEUR QU'AUCUN PV SOIT EN DESSOUS DE ZERO
		if (nPVj1<0){
			nPVj1=0;
		}
		if (nPVj2<0){
			nPVj2=0;
		}
		if (nPVj3<0){
			nPVj3=0;
		}
		if (nPVm1<0){
			nPVm1=0;
		}
		if (nPVm2<0){
			nPVm2=0;
		}
		if (nPVm3<0){
			nPVm3=0;
		}
	
	}

//FIN DE PARTIE

if(nPVj1+nPVj2+nPVj3<=0 && nPVm1+nPVm2+nPVm3<=0){printf("Egalite !");}

else{
	if(nPVj1+nPVj2+nPVj3<=0){
		printf("GAME OVER");
	}
	
	if(nPVm1+nPVm2+nPVm3<=0){
		printf("Vous avez gagne !");
	}
}
}