#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Ne pas oublier d'inclure le fichier time.h

/*CODE D'ORIGINE : Maxime Gonzales
ALGORITHMIE : Maxime Gonzales et Niels Ferreira
CODE PERSONNAGES : Niels Ferreira
CODE MONSTRES : Maxime Gonzales
ADAPTATION, COMPILATION ET LEVELING : Maxime Gonzales
GITHUB : NIELS FERREIRA*/

int main(){

int i=0;
//pvs du joueur et du monstre
int nPVj1 = 25;
int nPVj2 = 20;
int nPVj3 = 35;
int nPVm1 = 35;
int nPVm2 = 30;
int nPVm3 = 25;
//sélecteurs d'attaque du joueur et du monstre
int nSelJ= 0;
int nSelM=0;
//initiative, permet de savoir si c'est le tour du joueur ou du monstre
int nInit = 1;
//indicateur de défense, activé par l'action "défense", désactivé après une attaque s'il est activé, et à la fin du tour adverse suivant
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

//indicateur de Magie Maximale. J1 = DPS ; J2=Druide ; J3=Tank
int MaMJ1=15;
int MaMJ2=35;
int MaMJ3=15;
//magie du joueur et du monstre
int nMaJ1=MaMJ1;
int nMaJ2=MaMJ2;
int nMaJ3=MaMJ3;
int nMaM1=20;
int nMaM2=15;
int nMaM3=35;
//indicateur de poison, qui contient le nombre de tours d'effet
int nPoisonJ1=0;
int nPoisonJ2=0;
int nPoisonJ3=0;
int nPoisonM1=0;
int nPoisonM2=0;
int nPoisonM3=0;
//indicateur de poison virulent, qui contient le nombre de tours d'effet
int nPoisonVM1=0;
int nPoisonVM2=0;
int nPoisonVM3=0;
//indicateur d'initiative parmi les joueurs
int nSelPJ = 0;
//indicateur d'initiative parmi les monstres
int nSelAJ=0;
//indicateur d'initiative parmi les monstres
int nInitM = 0;
//indicateur de choix d'attaque parmi les monstres
int nSelAM = 0;
//indicateur d'XP et de level
int nXPJ1 = 0;
int nXPJ2 = 0;
int nXPJ3 = 0;
//valeur d'un niveau. Lorsque l'XP atteint cette valeur, la condition de changement de niveau s'active
int nXPLVL1 = 20 ;
int nXPLVL2 = 20 ;
int nXPLVL3 = 20 ;

	while(nPVj1+nPVj2+nPVj3>0&&nPVm1+nPVm2+nPVm3>0){
		
		//RAPPEL DES PVS ET PM
		printf("Les points de vie de l'Assassin : %d.\n", nPVj1);
		for(i=0;i<nPVj1;i++){
			printf("O");
		}
		printf("\n");
		printf("Les points de Mana de l'Assassin : %d.\n", nMaJ1);
		
		printf("\n");
		printf("Les points de vie du Druide : %d.\n", nPVj2);
		for(i=0;i<nPVj2;i++){
			printf("O");
		}
		printf("\n");
		printf("Les points de Mana du Druide : %d.\n", nMaJ2);
		
		printf("\n");
		printf("Les points de vie du Paladin : %d.\n", nPVj3);
		for(i=0;i<nPVj3;i++){
			printf("O");
		}
		printf("\n");
		printf("Les points de Mana du Paladin : %d.\n", nMaJ2);
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
		if(nInit==1){
			
			nSelPJ=1;
			
			//TOUR DE L'ASSASSIN J1
			if(nSelPJ==1&&nPVj1>0){
				printf("Tour de l'Assassin !\n");
				
				//restauration du Mana
				if(nMaJ1<=nMaMJ1-1){
					nMaJ1=nMaJ1+1;
				}
				
				//effet du poison
				if(nPoisonJ1>0){
					nPVj1=nPVj1-1;
					nPoisonJ1=nPoisonJ1-1;
				}
				
				//capacités
				
				printf("Saisissez 1 pour attaquer, 2 pour vous défendre, 3 pour empoisonner votre cible, 4 pour vous soigner d'un poison, et 5 pour un coup spécial.");
				scanf("%d", &nSelJ);
				
				while(nSelJ!=1&&nSelJ!=2&&nSelJ!=3&&nSelJ!=4&&nSelJ!=5){
				printf("Choisissez entre 1 et 5.\n");
				scanf("%d",&nSelJ);
				}
				
				//DEFENSE DU JOUEUR
				if(nSelJ==2){
					printf("Vous vous defendez !\n");
					nDefJ1=1;
					nSelPJ=2;
				}
				
				//ANTIDOTE
				if(nSelJ==4){
					if(nPoisonJ1>0&&nMaJ1>=10){
						nPoisonJ1=0;
						printf("Vous vous soignez ! \n");
						nSelPJ=2;
					}
					else{
					printf("Vous n'etes pas empoisonne ou n'avez plus de Mana. Choisissez une autre action.");
					}
				}
			
				//ATTAQUE DU JOUEUR
				if(nSelJ==1){
					printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
					scanf("\n%d",&nSelAJ);
					
					while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
						printf("Sélectionnez un nombre entre 1 et 3.\n");
						scanf("%d",&nSelAJ;)
					}
					
					//SI ATTAQUE SUR MONSTRE 1
					if(nSelAJ==1&&nPVm1>0){
						
						//si le monstre ne se défend pas
						if(nDefm1==0){
							nPVm1=nPVm1-4;
							printf("Le monstre subit l'attaque de plein fouet.\nVoici ses PV : %d.\n", nPVm1);
							//LEVELING
							nXPJ1=nXPJ1+5
							if(nPVm1==0){
								nXPJ1=nXPJ1+20;
							}
							nSelPJ=2;
						}					
													
						//Si le monstre se défend
						if(nDefM1==1){
							nPVm1=nPVm1-1;
							printf("Le monstre se defend, mais vous parvenez a le toucher !\nSes points de vie : %d. \n", nPVm1);
							nDefM1=0;
							//LEVELING
							nXPJ1=nXPJ1+3
							if(nPVm1==0){
								nXPJ1=nXPJ1+20;
							}
							nSelPJ=2;
						}
									
					}
					else{
						printf("Ce monstre n'a plus de points de vie !\n");
						printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
						scanf("\n%d",&nSelAJ);
						
						while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
							printf("Sélectionnez un nombre entre 1 et 3.\n");
							scanf("%d",&nSelAJ;)
						}
						
					}
					
					//SI ATTAQUE SUR MONSTRE 2
					if(nSelAJ==2&&nPVm2>0){
						
						//si le monstre ne se défend pas
						if(nDefm2==0){
							nPVm2=nPVm2-4;
							printf("Le monstre subit l'attaque de plein fouet.\nVoici ses PV : %d.\n", nPVm2);
							//LEVELING
							nXPJ1=nXPJ1+5
							if(nPVm2==0){
								nXPJ1=nXPJ1+20;
							}
							nSelPJ=2;
						}					
													
						//Si le monstre se défend
						if(nDefM2==1){
							nPVm2=nPVm2-1;
							printf("Le monstre se defend, mais vous parvenez a le toucher !\nSes points de vie : %d. \n", nPVm2);
							nDefM2=0;
							//LEVELING
							nXPJ1=nXPJ1+3
							if(nPVm2==0){
								nXPJ1=nXPJ1+20;
							}
							nSelPJ=2;
						}
											
					}
					else{
						printf("Ce monstre n'a plus de points de vie !\n");
						printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
						scanf("\n%d",&nSelAJ);
						
						while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
							printf("Sélectionnez un nombre entre 1 et 3.\n");
							scanf("%d",&nSelAJ;)
						}
						
					}
					
					//SI ATTAQUE SUR MONSTRE 3
					if(nSelAJ==3&&nPVm3>0){
						
						//si le monstre ne se défend pas
						if(nDefm3==0){
							nPVm3=nPVm3-4;
							printf("Le monstre subit l'attaque de plein fouet.\nVoici ses PV : %d.\n", nPVm3);
							//LEVELING ATTAQUE
							nXPJ1=nXPJ1+5
							if(nPVm3==0){
								nXPJ1=nXPJ1+20;
							}
							nSelPJ=2;
						}					
													
						//Si le monstre se défend
						if(nDefM3==1){
							nPVm3=nPVm3-1;
							printf("Le monstre se defend, mais vous parvenez a le toucher !\nSes points de vie : %d. \n", nPVm3);
							nDefM3=0;
							//LEVELING DEFENSE
							nXPJ1=nXPJ1+3
							if(nPVm3==0){
								nXPJ1=nXPJ1+20;
							}
							nSelPJ=2;
						}
											
					}
					else{
						printf("Ce monstre n'a plus de points de vie !\n");
						printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
						scanf("\n%d",&nSelAJ);
						
						while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
							printf("Sélectionnez un nombre entre 1 et 3.\n");
							scanf("%d",&nSelAJ;)
						}
						
					}
				}
					
				//ATTAQUE SPECIALE DU JOUEUR
				if(nSelJ==5){
					printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
					scanf("\n%d",&nSelAJ);
					
					while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
						printf("Sélectionnez un nombre entre 1 et 3.\n");
						scanf("%d",&nSelAJ;)
					}
					
					//SI ATTAQUE SUR MONSTRE 1
					if(nSelAJ==1&&nPVm1>0){
						
						//si le monstre ne se défend pas
						if(nDefm1==0){
							nPVm1=nPVm1-8;
							printf("Le monstre subit l'attaque de plein fouet.\nVoici ses PV : %d.\n", nPVm1);
							//LEVELING ATTAQUE
							nXPJ1=nXPJ1+6
							if(nPVm1==0){
								nXPJ1=nXPJ1+20;
							}
							nSelPJ=2;
						}					
													
						//Si le monstre se défend
						if(nDefM1==1){
							nPVm1=nPVm1-2;
							printf("Le monstre se defend, mais vous parvenez a le toucher !\nSes points de vie : %d. \n", nPVm1);
							nDefM1=0;
							//LEVELING DEFENSE
							nXPJ1=nXPJ1+4
							if(nPVm1==0){
								nXPJ1=nXPJ1+20;
							}
							nSelPJ=2;
						}
									
					}
					else{
						printf("Ce monstre n'a plus de points de vie !\n");
						printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
						scanf("\n%d",&nSelAJ);
						
						while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
							printf("Sélectionnez un nombre entre 1 et 3.\n");
							scanf("%d",&nSelAJ;)
						}
						
					}
					
					//SI ATTAQUE SUR MONSTRE 2
					if(nSelAJ==2&&nPVm2>0){
						
						//si le monstre ne se défend pas
						if(nDefm2==0){
							nPVm2=nPVm2-8;
							printf("Le monstre subit l'attaque de plein fouet.\nVoici ses PV : %d.\n", nPVm2);
							//LEVELING ATTAQUE
							nXPJ1=nXPJ1+6
							if(nPVm2==0){
								nXPJ1=nXPJ1+20;
							}
							nSelPJ=2;
						}					
													
						//Si le monstre se défend
						if(nDefM2==1){
							nPVm2=nPVm2-2;
							printf("Le monstre se defend, mais vous parvenez a le toucher !\nSes points de vie : %d. \n", nPVm2);
							nDefM2=0;
							//LEVELING DEFENSE
							nXPJ1=nXPJ1+4
							if(nPVm2==0){
								nXPJ1=nXPJ1+20;
							}
							nSelPJ=2;
						}
											
					}
					else{
						printf("Ce monstre n'a plus de points de vie !\n");
						printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
						scanf("\n%d",&nSelAJ);
						
						while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
							printf("Sélectionnez un nombre entre 1 et 3.\n");
							scanf("%d",&nSelAJ;)
						}
						
					}
					
					//SI ATTAQUE SUR MONSTRE 3
					if(nSelAJ==3&&nPVm3>0){
						
						//si le monstre ne se défend pas
						if(nDefm3==0){
							nPVm3=nPVm3-8;
							printf("Le monstre subit l'attaque de plein fouet.\nVoici ses PV : %d.\n", nPVm3);
							//LEVELING ATTAQUE
							nXPJ1=nXPJ1+6
							if(nPVm2==0){
								nXPJ1=nXPJ1+20;
							}
							nSelPJ=2;
						}					
													
						//Si le monstre se défend
						if(nDefM3==1){
							nPVm3=nPVm3-2;
							printf("Le monstre se defend, mais vous parvenez a le toucher !\nSes points de vie : %d. \n", nPVm3);
							nDefM3=0;
							//LEVELING DEFENSE
							nXPJ1=nXPJ1+3
							if(nPVm3==0){
								nXPJ1=nXPJ1+20;
							}
							nSelPJ=2;
						}
											
					}
					else{
						printf("Ce monstre n'a plus de points de vie !\n");
						printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
						scanf("\n%d",&nSelAJ);
						
						while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
							printf("Sélectionnez un nombre entre 1 et 3.\n");
							scanf("%d",&nSelAJ;)
						}
						
					}
				}
				
				//POISON DU JOUEUR
				if(nSelJ==3){
					if(nPoisonM1>0||nPoisonM2>0||nPoisonM3>0){
						if(nMaJ1>10){
							
							//CHOIX DE LA CIBLE
							printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
							
							scanf("\n%d",&nSelAJ);
							
							while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
								printf("Sélectionnez un nombre entre 1 et 3.\n");
								scanf("%d",&nSelAJ;)
							}
							
							//SI LE PREMIER MONSTRE EST ATTAQUE
							if(nSelAJ==1&&nPVm1>0&&nPoisonM1==0){
								if(nPoisonM1==0&&nMaJ1>=10){
									printf("Vous empoisonnez le monstre !\n");
									nPoisonM1=5;
									nMaJ1=nMaJ1-10;
									nSelPJ=2;
								}
							}
							else{
								printf("Ce monstre est déjà empoisonné. Choisissez-en un autre !\n");
								scanf("%d",&nSelAJ);
							}
							
							//SI LE DEUXIEME MONSTRE EST ATTAQUE
							if(nSelAJ==2&&nPVm2>0&&nPoisonM2==0){
								if(nPoisonM2==0&&nMaJ1>=10){
									printf("Vous empoisonnez le monstre !\n");
									nPoisonM2=5;
									nMaJ1=nMaJ1-10;
									nSelPJ=2;
								}
							}
							else{
								printf("Ce monstre est déjà empoisonné. Choisissez-en un autre !\n");
								scanf("%d",&nSelAJ);
							}
							
							//SI LE TROISIEME MONSTRE EST ATTAQUE
							if(nSelAJ==3&&nPVm3>0&&nPoisonM3==0){
								if(nPoisonM3==0&&nMaJ1>=10){
									printf("Vous empoisonnez le monstre !\n");
									nPoisonM3=5;
									nMaJ1=nMaJ1-10;
									nSelPJ=2;
								}
							}
							else{
								printf("Ce monstre est déjà empoisonné. Choisissez-en un autre !\n");
								scanf("%d",&nSelAJ);
							}
							nXPJ1=nXPJ1+3;
						}
						else{
							printf("Vous n'avez pas assez de Mana. Choisissez une autre action.\n");
							scanf("%d",&nSelJ);
						}
					}
					else{
						printf("Tous les monstres sont déjà empoisonnés. Choisissez une autre action.\n");
						scanf("%d",&nSelJ);
					}
				
				}
					
			}
			else{
				nSelPJ=2;
			}
			
			
			//TOUR DU DRUIDE J2
			if(nSelPJ==2&&nPVj2>0){
				printf("Tour du Druide !\n");
				//restauration du Mana
				if(nMaJ2<=nMaMJ2-1){
					nMaJ2=nMaJ2+1;
				}
				
				//effet du poison
				if(nPoisonJ2>0){
					nPVj2=nPVj2-1;
					nPoisonJ2=nPoisonJ2-1;
				}
				
				//capacités
				printf("Saisissez 1 pour attaquer, 2 pour vous défendre, 3 pour empoisonner tous les monstres, 4 pour vous soigner d'un poison, et 5 pour administrer un poison virulent.");
				scanf("%d",&nSelJ);
				
				while(nSelJ!=1&&nSelJ!=2&&nSelJ!=3&&nSelJ!=4){
				printf("Choisissez entre 1 et 4.\n");
				scanf("%d",&nSelJ);
				}
				
				//DEFENSE DU JOUEUR
				if(nSelJ==2){
					printf("Vous vous defendez !\n");
					nDefJ2=1;
					nSelPJ=3;
				}
				
				//ANTIDOTE
				if(nSelJ==4){
					if(nPoisonJ2>0&&nMaJ2>=10){
						nPoisonJ2=0;
						printf("Vous vous soignez ! \n");
						nSelPJ=3;
					}
					else{
					printf("Vous n'etes pas empoisonne ou n'avez plus de Mana. Choisissez une autre action.");
					}
				}
				
				//POISON DU DRUIDE
				if(nMaJ2>=15){
					if(nPoisonM1==0||nPoisonM2==0||nPoisonM3==0){
						if(nPoisonM1==0){
							nPoisonM1=5;
							nXPJ2=nXPJ2+5;
						}
						if(nPoisonM2==0){
							nPoisonM2=5;
							nXPJ2=nXPJ2+5;
						}
						if(nPoisonM3==0){
							nPoisonM3=5;
							nXPJ2=nXPJ2+5;
						}
					}
					else{
						printf("Tous les monstres sont empoisonnes, selectionnez une autre action !\n");
						scanf("%d",&nSelJ);
					}
				}
				else{
					printf("Vous n'avez pas assez de mana. Choisissez une autre action.\n");
					scanf("%d",&nSelJ);
				}
			
				//ATTAQUE DU JOUEUR
				if(nSelJ==1){
					printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
					scanf("\n%d",&nSelAJ);
					
					while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
						printf("Selectionnez un nombre entre 1 et 3.\n");
						scanf("%d",&nSelAJ;)
					}
					
					//SI ATTAQUE SUR MONSTRE 1
					if(nSelAJ==1&&nPVm1>0){
						
						//si le monstre ne se défend pas
						if(nDefm1==0){
							nPVm1=nPVm1-4;
							printf("Le monstre subit l'attaque de plein fouet.\nVoici ses PV : %d.\n", nPVm1);
							//LEVELING ATTAQUE
							nXPJ2=nXPJ2+5
							if(nPVm1==0){
								nXPJ2=nXPJ2+20;
							}
							nSelPJ=3;
						}					
													
						//Si le monstre se défend
						if(nDefM1==1){
							nPVm1=nPVm1-1;
							printf("Le monstre se defend, mais vous parvenez a le toucher !\nSes points de vie : %d. \n", nPVm1);
							nDefM1=0;
							//LEVELING DEFENSE
							nXPJ2=nXPJ2+3
							if(nPVm1==0){
								nXPJ2=nXPJ2+20;
							}
							nSelPJ=3;
						}
									
					}
					else{
						printf("Ce monstre n'a plus de points de vie !\n");
						printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
						scanf("\n%d",&nSelAJ);
						
						while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
							printf("Sélectionnez un nombre entre 1 et 3.\n");
							scanf("%d",&nSelAJ;)
						}
						
					}
					
					//SI ATTAQUE SUR MONSTRE 2
					if(nSelAJ==2&&nPVm2>0){
						
						//si le monstre ne se défend pas
						if(nDefm2==0){
							nPVm2=nPVm2-4;
							printf("Le monstre subit l'attaque de plein fouet.\nVoici ses PV : %d.\n", nPVm2);
							//LEVELING ATTAQUE
							nXPJ2=nXPJ2+5
							if(nPVm2==0){
								nXPJ2=nXPJ2+20;
							}
							nSelPJ=3;
						}					
													
						//Si le monstre se défend
						if(nDefM2==1){
							nPVm2=nPVm2-1;
							printf("Le monstre se defend, mais vous parvenez a le toucher !\nSes points de vie : %d. \n", nPVm2);
							nDefM2=0;
							//LEVELING DEFENSE
							nXPJ2=nXPJ2+3
							if(nPVm2==0){
								nXPJ2=nXPJ2+20;
							}
							nSelPJ=3;
						}
											
					}
					else{
						printf("Ce monstre n'a plus de points de vie !\n");
						printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
						scanf("\n%d",&nSelAJ);
						
						while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
							printf("Sélectionnez un nombre entre 1 et 3.\n");
							scanf("%d",&nSelAJ;)
						}
						
					}
					
					//SI ATTAQUE SUR MONSTRE 3
					if(nSelAJ==3&&nPVm3>0){
						
						//si le monstre ne se défend pas
						if(nDefm3==0){
							nPVm3=nPVm3-4;
							printf("Le monstre subit l'attaque de plein fouet.\nVoici ses PV : %d.\n", nPVm3);
							//LEVELING ATTAQUE
							nXPJ2=nXPJ2+5
							if(nPVm3==0){
								nXPJ2=nXPJ2+20;
							}
							nSelPJ=3;
						}					
													
						//Si le monstre se défend
						if(nDefM3==1){
							nPVm3=nPVm3-1;
							printf("Le monstre se defend, mais vous parvenez a le toucher !\nSes points de vie : %d. \n", nPVm3);
							nDefM3=0;
							//LEVELING DEFENSE
							nXPJ3=nXPJ3+3
							if(nPVm3==0){
								nXPJ3=nXPJ3+20;
							}
							nSelPJ=3;
						}
											
					}
					else{
						printf("Ce monstre n'a plus de points de vie !\n");
						printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
						scanf("\n%d",&nSelAJ);
						
						while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
							printf("Sélectionnez un nombre entre 1 et 3.\n");
							scanf("%d",&nSelAJ;)
						}
						
					}
				}
									
				//POISON VIRULENT DU JOUEUR
				if(nSelJ==4){
					if(nPoisonVM1==0||nPoisonVM2==0||nPoisonVM3==0){
						if(nMaJ2>15){
							
							//CHOIX DE LA CIBLE
							printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
							
							scanf("\n%d",&nSelAJ);
							
							while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
								printf("Sélectionnez un nombre entre 1 et 3.\n");
								scanf("%d",&nSelAJ;)
							}
							
							//SI LE PREMIER MONSTRE EST ATTAQUE
							if(nSelAJ==1&&nPVm1>0&&nPoisonVM1==0){
								printf("Vous empoisonnez le monstre !\n");
								nPoisonVM1=5;
								nMaJ2=nMaJ2-15;
								nXPJ2=nXPJ2+5;
								nSelPJ=3;
							}
							else{
								printf("Ce monstre est déjà empoisonné. Choisissez-en un autre !\n");
								scanf("%d",&nSelAJ);
							}
							
							//SI LE DEUXIEME MONSTRE EST ATTAQUE
							if(nSelAJ==2&&nPVm2>0&&nPoisonVM2==0){
								printf("Vous empoisonnez le monstre !\n");
								nPoisonVM2=5;
								nMaJ2=nMaJ2-15;
								nXPJ2=nXPJ2+5;
								nSelPJ=3;
							}
							else{
								printf("Ce monstre est déjà empoisonné. Choisissez-en un autre !\n");
								scanf("%d",&nSelAJ);
							}
							
							//SI LE TROISIEME MONSTRE EST ATTAQUE
							if(nSelAJ==3&&nPVm3>0&&nPoisonVM3==0){
								printf("Vous empoisonnez le monstre !\n");
								nPoisonVM3=5;
								nMaJ2=nMaJ2-15;
								nXPJ2=nXPJ2+5;
								nSelPJ=2;
							}
							else{
								printf("Ce monstre est déjà empoisonné. Choisissez-en un autre !\n");
								scanf("%d",&nSelAJ);
							}
						}
						else{
							printf("Vous n'avez pas assez de Mana. Choisissez une autre action.\n");
							scanf("%d",&nSelJ);
						}
					}
					else{
						printf("Tous les monstres sont déjà empoisonnés. Choisissez une autre action.\n");
						scanf("%d",&nSelJ);
					}
				
				}
				
				
			}
			else{
				nSelPJ=3;
			}
			
			//TOUR DU PALADIN J3
			if(nSelPJ==3&&nPVj3>0){
				printf("Tour du Paladin !\n");
				//restauration du Mana
				if(nMaJ3<=nMaMJ3-1){
					nMaJ3=nMaJ3+1;
				}
				
				//effet du poison
				if(nPoisonJ2>0){
					nPVj2=nPVj2-1;
					nPoisonJ2=nPoisonJ2-1;
				}
				
				//capacités
				printf("Saisissez 1 pour attaquer, 2 pour vous défendre, 3 pour empoisonner votre cible, 4 pour vous soigner d'un poison, et 5 pour booster la défense de vos alliés.\n");
				scanf("%d",&nSelJ);
				
				while(nSelJ!=1&&nSelJ!=2&&nSelJ!=3&&nSelJ!=4&&nSelJ!=5){
				printf("Choisissez entre 1 et 5.\n");
				scanf("%d",&nSelJ);
				}
				
				//DEFENSE DU JOUEUR
				if(nSelJ==2){
					printf("Vous vous defendez !\n");
					nDefJ3=1;
					nDefM1=0;
					nDefM2=0;
					nDefM3=0;
					nInit=0;
				}
				
				//BUFF DEFENSIF DU JOUEUR
				if(nSelJ==5){
					if(nDefJ1==0){
						nXPJ3=nXPJ3+6;
						nDefJ1=1;
					}
					if(nDefJ2==0){
						nDefJ2=1;
						nXPJ3=nXPJ3+6;
					}
				Printf("Vous protégez vos camarades !\n");
				nDefM1=0;
				nDefM2=0;
				nDefM3=0;
				nInit=0;
				}
				
				//ANTIDOTE
				if(nSelJ==4){
					if(nPoisonJ3>0&&nMaJ3>=10){
						nPoisonJ3=0;
						printf("Vous vous soignez ! \n");
						nDefM1=0;
						nDefM2=0;
						nDefM3=0;
						nInit=0;
					}
					else{
					printf("Vous n'etes pas empoisonne ou n'avez plus de Mana. Choisissez une autre action.");
					}
				}
			
				//ATTAQUE DU JOUEUR
				if(nSelJ==1){
					printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
					scanf("\n%d",&nSelAJ);
					
					while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
						printf("Sélectionnez un nombre entre 1 et 3.\n");
						scanf("%d",&nSelAJ;)
					}
					
					//SI ATTAQUE SUR MONSTRE 1
					if(nSelAJ==1&&nPVm1>0){
						
						//si le monstre ne se défend pas
						if(nDefm1==0){
							nPVm1=nPVm1-4;
							printf("Le monstre subit l'attaque de plein fouet.\nVoici ses PV : %d.\n", nPVm1);
							//LEVELING ATTAQUE
							nXPJ3=nXPJ3+5
							if(nPVm1==0){
								nXPJ3=nXPJ3+20;
							}
							nInit=0;
						}					
													
						//Si le monstre se défend
						if(nDefM1==1){
							nPVm1=nPVm1-1;
							printf("Le monstre se defend, mais vous parvenez a le toucher !\nSes points de vie : %d. \n", nPVm1);
							nDefM1=0;
							//LEVELING DEFENSE
							nXPJ3=nXPJ3+3
							if(nPVm1==0){
								nXPJ3=nXPJ3+20;
							}
							nInit=0;
						}
									
					}
					else{
						printf("Ce monstre n'a plus de points de vie !\n");
						printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
						scanf("\n%d",&nSelAJ);
						
						while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
							printf("Sélectionnez un nombre entre 1 et 3.\n");
							scanf("%d",&nSelAJ;)
						}
						
					}
					
					//SI ATTAQUE SUR MONSTRE 2
					if(nSelAJ==2&&nPVm2>0){
						
						//si le monstre ne se défend pas
						if(nDefm2==0){
							nPVm2=nPVm2-4;
							printf("Le monstre subit l'attaque de plein fouet.\nVoici ses PV : %d.\n", nPVm2);
							//LEVELING ATTAQUE
							nXPJ3=nXPJ3+5
							if(nPVm2==0){
								nXPJ3=nXPJ3+20;
							}
							nInit=0;
						}					
													
						//Si le monstre se défend
						if(nDefM2==1){
							nPVm2=nPVm2-1;
							printf("Le monstre se defend, mais vous parvenez a le toucher !\nSes points de vie : %d. \n", nPVm2);
							nDefM2=0;
							//LEVELING DEFENSE
							nXPJ3=nXPJ3+3
							if(nPVm2==0){
								nXPJ3=nXPJ3+20;
							}
							nInit=0;
						}
											
					}
					else{
						printf("Ce monstre n'a plus de points de vie !\n");
						printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
						scanf("\n%d",&nSelAJ);
						
						while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
							printf("Sélectionnez un nombre entre 1 et 3.\n");
							scanf("%d",&nSelAJ;)
						}
						
					}
					
					//SI ATTAQUE SUR MONSTRE 3
					if(nSelAJ==3&&nPVm3>0){
						
						//si le monstre ne se défend pas
						if(nDefm3==0){
							nPVm3=nPVm3-4;
							printf("Le monstre subit l'attaque de plein fouet.\nVoici ses PV : %d.\n", nPVm3);
							//LEVELING ATTAQUE
							nXPJ3=nXPJ3+5
							if(nPVm3==0){
								nXPJ3=nXPJ3+20;
							}
							nInit=0;
						}					
													
						//Si le monstre se défend
						if(nDefM3==1){
							nPVm3=nPVm3-1;
							printf("Le monstre se defend, mais vous parvenez a le toucher !\nSes points de vie : %d. \n", nPVm3);
							nDefM3=0;
							//LEVELING DEFENSE
							nXPJ3=nXPJ3+3
							if(nPVm3==0){
								nXPJ3=nXPJ3+20;
							}
							nInit=0;
						}
											
					}
					else{
						printf("Ce monstre n'a plus de points de vie !\n");
						printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
		
						scanf("\n%d",&nSelAJ);
						
						while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
							printf("Sélectionnez un nombre entre 1 et 3.\n");
							scanf("%d",&nSelAJ;)
						}
						
					}
				}
									
				//POISON DU JOUEUR
				if(nSelJ==3){
					if(nPoisonM1>0||nPoisonM2>0||nPoisonM3>0){
						if(nMaJ3>10){
							
							//CHOIX DE LA CIBLE
							printf("\n Choix du monstre à attaquer : saisir 1 pour attaquer le monstre 1,\n saisir 2 pour attaquer le monstre 2,\n saisir 3 pour attaquer le monstre 3\n");
							
							scanf("\n%d",&nSelAJ);
							
							while(nSelAJ!=1&&nSelAJ!=2&&nSelAJ!=3){
								printf("Sélectionnez un nombre entre 1 et 3.\n");
								scanf("%d",&nSelAJ;)
							}
							
							//SI LE PREMIER MONSTRE EST ATTAQUE
							if(nSelAJ==1&&nPVm1>0&&nPoisonM1==0){
								printf("Vous empoisonnez le monstre !\n");
								nPoisonM1=5;
								nMaJ3=nMaJ3-10;
								nDefM1=0;
								nDefM2=0;
								nDefM3=0;
								nInit=0;
							}
							else{
								printf("Ce monstre est déjà empoisonné. Choisissez-en un autre !\n");
								scanf("%d",&nSelAJ);
							}
							
							//SI LE DEUXIEME MONSTRE EST ATTAQUE
							if(nSelAJ==2&&nPVm2>0&&nPoisonM2==0){
								printf("Vous empoisonnez le monstre !\n");
								nPoisonM2=5;
								nMaJ3=nMaJ3-10;
								nDefM1=0;
								nDefM2=0;
								nDefM3=0;
								nInit=0;
							}
							else{
								printf("Ce monstre est déjà empoisonné. Choisissez-en un autre !\n");
								scanf("%d",&nSelAJ);
							}
							
							//SI LE TROISIEME MONSTRE EST ATTAQUE
							if(nSelAJ==3&&nPVm3>0&&nPoisonM3==0){
								printf("Vous empoisonnez le monstre !\n");
								nPoisonM3=5;
								nMaJ3=nMaJ3-10;
								nDefM1=0;
								nDefM2=0;
								nDefM3=0;
								nInit=0;
							}
							else{
								printf("Ce monstre est déjà empoisonné. Choisissez-en un autre !\n");
								scanf("%d",&nSelAJ);
							}
							nXPJ3=nXPJ3+3;
						}
						else{
							printf("Vous n'avez pas assez de Mana. Choisissez une autre action.\n");
							scanf("%d",&nSelJ);
						}
					}
					else{
						printf("Tous les monstres sont déjà empoisonnés. Choisissez une autre action.\n");
						scanf("%d",&nSelJ);
					}
				
				}
			}
			else{
				nDefM1=0;
				nDefM2=0;
				nDefM3=0;
				nInit=0;
			
			}
			
		printf("\n");
		
		//TOUR DU MONSTRE
		if(nInit==0){
			
			//SELECTEUR DE MONSTRE
			nInitM = 1;
			
			if(nInitM==1&&nPVm1>0){
			
				if(nPoisonVM1>0){
					nPVm1=nPVm1-3;
					nPoisonVM1=nPoisonVM1-1;
					printf("Le poison virulent fait effet ! Le monstre perd 3 pv !\n");
				}
				
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
								nXPJ1=nXPJ1+3;
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
								nXPJ2=nXPJ2+3;
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
								nXPJ3=nXPJ3+3;
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
			
				if(nPoisonVM2>0){
					nPVm2=nPVm2-3;
					nPoisonVM2=nPoisonVM2-1;
					printf("Le poison virulent fait effet ! Le monstre perd 3 pv !\n");
				}
				
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
								nXPJ1=nXPJ1+3;
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
								nXPJ2=nXPJ2+3;
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
								nXPJ3=nXPJ3+3;
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
				
				if(nPoisonVM3>0){
					nPVm3=nPVm3-3;
					nPoisonVM3=nPoisonVM3-1;
					printf("Le poison virulent fait effet ! Le monstre perd 3 pv !\n");
				}
				
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
								nDefJ1=0;
								nDefJ2=0;
								nDefJ3=0;
								nXPJ1=nXPJ1+3;
								nInit=1;
							}
					
							else if (nPVj1==0){
								printf("Le monstre hésite entre deux cibles...\n.");
							}
							
							//Si le joueur ne se défend pas
							else{
								nPVj1=nPVj1-4;
								printf("Le monstre attaque le personnage 1 ! Vous subissez l'attaque de plein fouet.\nVos points de vie : %d. \n", nPVj1);
								nDefJ1=0;
								nDefJ2=0;
								nDefJ3=0;
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
								nDefJ1=0;
								nDefJ3=0;
								nXPJ2=nXPJ2+3;
								nInit=1;
							}
					
							else if (nPVj2==0){
								printf("Le monstre hésite entre deux cibles...\n.");
							}
							
							//Si le joueur ne se défend pas
							else{
								nPVj2=nPVj2-4;
								printf("Le monstre attaque le personnage 2 ! Vous subissez l'attaque de plein fouet.\nVos points de vie : %d. \n", nPVj1);
								nDefJ1=0;
								nDefJ2=0;
								nDefJ3=0;
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
								nDefJ1=0;
								nDefJ2=0;
								nXPJ2=nXPJ2+3;
								nInit=1;
							}
					
							else if (nPVj3!=0){
								printf("Le monstre hésite entre deux cibles...\n.");
							}
							
							//Si le joueur ne se défend pas
							else{
								nPVj3=nPVj3-4;
								printf("Le monstre attaque le personnage 3 ! Vous subissez l'attaque de plein fouet.\nVos points de vie : %d. \n", nPVj1);
								nDefJ1=0;
								nDefJ2=0;
								nDefJ3=0;
								nInit=1;
							}
						}
						
						
					}
									
					//DEFENSE DU MONSTRE
					if(nSelM==2){
						printf("Le troisieme monstre se defend !\n");
						nDefM3=1;
						nDefJ1=0;
						nDefJ2=0;
						nDefJ3=0;
						nInit=1;
					}
					
					//POISON DU MONSTRE
					
					if(nSelM==3){
						nSelAM=rand_c_d(c,d);
						
						if(nSelAM=1&&nPVj1>0&&nMaM3>=10&&nPoisonJ1==0){
							printf("Le troisieme monstre empoisonne le personnage 1 !\n");
							nPoisonJ1=5;
							nMaM3=nMaM3-10;
							nDefJ1=0;
							nDefJ2=0;
							nDefJ3=0;
							nInit=1;
						}
						
						if(nSelAM=2&&nPVj2>0&&nMaM3>=10&&nPoisonJ2==0){
							printf("Le troisieme monstre empoisonne le personnage 2 !\n");
							nPoisonJ2=5;
							nMaM3=nMaM3-10;
							nDefJ1=0;
							nDefJ2=0;
							nDefJ3=0;
							nInit=1;
						}
						
						if(nSelAM=3&&nPVj3>0&&nMaM3>=10&&nPoisonJ3==0){
							printf("Le troisieme monstre empoisonne le personnage 3 !\n");
							nPoisonJ3=5;
							nMaM2=nMaM3-10;
							nDefJ1=0;
							nDefJ2=0;
							nDefJ3=0;
							nInit=1;
						}
					}
				
				}
				
				
			}
			
			else{
				nInit=1;
				nDefJ1=0;
				nDefJ2=0;
				nDefJ3=0;
			}

			nDefJ1=0;
			nDefJ2=0;
			nDefJ3=0;
			
		}
		printf("\n");
		
		
		
		//CONTROLEUR QU'AUCUN PV SOIT EN DESSOUS DE ZERO
		if (nPVj1<=0){
			nPVj1=0;
		}
		if (nPVj2<=0){
			nPVj2=0;
		}
		if (nPVj3<=0){
			nPVj3=0;
		}
		if (nPVm1<=0){
			nPVm1=0;
		}
		if (nPVm2<=0){
			nPVm2=0;
		}
		if (nPVm3<=0){
			nPVm3=0;
		}
		
		//PASSAGE DE NIVEAU
		if(nXPJ1>=nXPLVL1={
			nPVJ1=25;
			nMaJ1=nMaMJ1;
			nXPJ1=0;
			nXPLVL1=nXPLVL1+10;
			printf("L'Assassin gagne un niveau ! PV : %d et PM : %d.\n", nPVj2, nMaJ2);
		}
		
		if(nXPJ2>=nXPLVL2={
			nPVJ2=20;
			nMaJ2=nMaMJ2;
			nXPJ2=0;
			nXPLVL2=nXPLVL2+10;
			printf("Le Druide gagne un niveau ! PV : %d et PM : %d.\n", nPVj2, nMaJ2);
		}
		
		if(nXPJ3>=nXPLVL3={
			nPVj3=35;
			nMaMJ3=nMaMJ3+5
			nMaJ3=nMaMJ3;
			nXPJ3=0;
			nXPLVL3=nXPLVL3+10;
			printf("Le Paladin gagne un niveau ! PV : %d et PM : %d.\n", nPVj3, nMaJ3);
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