 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

	int main(){
		
		int personnage = 0;					//choix du personnage jouable
		
		int pv_dps = 30;					// statistiques du dps
		int mana_dps = 15;
		int poison_dps = 0;
		int lame_tranchante = 0;
		
		int esquive = 0;
		int a=1;
		int b=10;
		/*int rand_a_b(int a, int b){
			//return rand()%(b-a) +a;
		}*/
		
		int choixdps = 0;					//action choisie par le dps
		int choixmonstre = 0;				//monstre choisi par le dps
		
		int pv_druide = 40;					//statistiques du druide
		int mana_druide = 20;
		int poison_druide = 0;
		int invocation_foudre = 0;
		int malediction = 0;
		
		int choixdruide = 0;
		
		int i = 0;
		
		int pv_tank = 50;					//statistiques du tank
		int mana_tank = 15;
		int poison_tank = 0;
		int contre_attaque = 0;
		int cri_de_guerre = 0;
		
		int choixtank = 0;
		
		
		int pv_groupe = 120; 				//points de vie du groupe
		
		
		int pv_monstre = 30;
		int monstre_cible = 0;
		int monstre_attaque = 0;
		
		int pv_monstre_2 = 30;
		int monstre_2_cible = 0;
		int monstre_2_attaque = 0;

		int pv_monstre_3 = 30;
		int monstre_3_cible = 0;
		int monstre_3_attaque = 0;

		
		
		int poison_monstre = 0;
		

		//pv_dps + pv_druide + pv_tank = pv_groupe;  		//liaison des PV des differents joueurs en PV de groupe
		
		
		printf(" PERSONNAGE : Taper 1 pour jouer le dps, taper 2 pour jouer le druide, taper 3 pour jouer le tank\n");
		
		scanf("%d\n",&personnage);	
		
		
		printf("\n debut du combat\n");
		
		
		/////////////////////	DEBUT DU COMBAT
		
		
		while(pv_groupe>0 && pv_monstre>0){
			
			if(personnage == 1){				//DPS
				
				printf("\n MONSTRE A ATTAQUER: taper 1 pour attaquer le monstre 1,\n taper 2 pour attaquer le monstre 2,\n taper 3 pour attaquer le monstre 3\n");
				
				scanf("\n%d",&choixmonstre);
				
				if(choixmonstre == 1){			//MONSTRE ENNEMI 1
					
					printf("\n Vous avez choisi d'attaquer le monstre 1 !\n");
					
					printf("\n ACTION A EFFECTUER : taper 1 pour utiliser une attaque normale,\n taper 2 pour utiliser attaque puissante,\n taper 3 pour utiliser esquive,\n taper 4 pour se defendre.\n");
				
					scanf("\n%d\n", &choixdps);
					
					if(choixdps == 1){  // coup normal !		//ATTAQUE DPS 1
				
						printf("Vous decidez d'attaquer avec un coup normal!\n");
				
						pv_monstre = pv_monstre-6;
						
						printf("\n Le monstre 1 a maintenant %d points de vie.", pv_monstre);
						
						mana_dps = mana_dps +2;
						
						printf("\n le mana du DPS est de %d\n", mana_dps);
					}
					
					if(choixdps == 2){  //coup puissant ! 		//ATTAQUE DPS 2
						
						printf("Vous decidez d'attaquer avec un coup PUISSANT!\n");
						
						pv_monstre = pv_monstre - 10;
						
						printf("\n le monstre 1 a maintenant %d points de vie.", pv_monstre);
						
						mana_dps = mana_dps - 10;
						
						printf("\n le mana du DPS est de %d\n", mana_dps);
					}
						
					if(choixdps == 3)  //esquive !				//ATTAQUE DPS 3
					
						printf("Vous tentez d'esquiver le prochain coup du monstre !");
						
						//esquive=rand_a_b(a, b);
						
						if(esquive >= 4){
							
							monstre_attaque = 0;
							
							printf("\n Le dps a esquive l'attaque !");
							
							monstre_attaque = 5;
						}
				}
					
					
					
				if(choixmonstre == 2){				//MONSTRE ENNEMI 2
					
					printf("\n Vous avez choisi d'attaquer le monstre 2 !\n");
					
					printf("\n ACTION A EFFECTUER : taper 1 pour utiliser une attaque normale,\n taper 2 pour utiliser attaque puissante,\n taper 3 pour utiliser esquive,\n taper 4 pour se defendre.\n");
				
					scanf("\n%d\n", &choixdps);
					
					if(choixdps == 1){  // coup normal !		//ATTAQUE DPS 1
				
						printf("Vous decidez d'attaquer avec un coup normal!\n");
				
						pv_monstre_2 = pv_monstre_2-6;
						
						printf("\n Le monstre 2 a maintenant %d points de vie.", pv_monstre);
						
						mana_dps = mana_dps +2;
						
						printf("\n le mana du DPS est de %d\n", mana_dps);
					}
					
					if(choixdps == 2){  //coup puissant !		//ATTAQUE DPS 2
						
						printf("Vous decidez d'attaquer avec un coup PUISSANT!\n");
						
						pv_monstre_2 = pv_monstre_2 - 10;
						
						printf("\n le monstre 2 a maintenant %d points de vie.", pv_monstre);
						
						mana_dps = mana_dps - 10;
						
						printf("\n le mana du DPS est de %d\n", mana_dps);
					}
						
					if(choixdps == 3)  //esquive !				//ATTAQUE DPS 3
					
						printf("Vous tentez d'esquiver le prochain coup du monstre 2!");
						
						//esquive=rand_a_b(a, b);
						
						if(esquive >= 4){
							
							monstre_2_attaque = 0;
							
							printf("\n Le dps a esquive l'attaque !");
							
							monstre_2_attaque = 5;
						}
				}
				
				//////////////////////////MANQUE CHOIX DPS 4/////////////
				
				if(choixmonstre == 3){				// MONSTRE ENNEMI 3
					
					printf("\n Vous avez choisi d'attaquer le monstre 3 !\n");
					
					printf("\n ACTION A EFFECTUER : taper 1 pour utiliser une attaque normale,\n taper 2 pour utiliser attaque puissante,\n taper 3 pour utiliser esquive,\n taper 4 pour se defendre.\n");
				
					scanf("\n%d\n", &choixdps);
					
					if(choixdps == 1){  // coup normal !	//ATTAQUE DPS 1
				
						printf("Vous decidez d'attaquer avec un coup normal!\n");
				
						pv_monstre_3 = pv_monstre_3-6;
						
						printf("\n Le monstre 3 a maintenant %d points de vie.", pv_monstre);
						
						mana_dps = mana_dps +2;
						
						printf("\n le mana du DPS est de %d\n", mana_dps);
					}
					
					if(choixdps == 2){  //coup puissant !   //ATTAQUE DPS 2
						
						printf("Vous decidez d'attaquer avec un coup PUISSANT!\n");
						
						pv_monstre_3 = pv_monstre_3 - 10;
						
						printf("\n le monstre 2 a maintenant %d points de vie.", pv_monstre);
						
						mana_dps = mana_dps - 10;
						
						printf("\n le mana du DPS est de %d\n", mana_dps);
					}
						
					if(choixdps == 3){  //esquive !			//ATTAQUE DPS 3
					
						printf("Vous tentez d'esquiver le prochain coup du monstre 3!");
						
						//esquive=rand_a_b(a, b);
						
						if(esquive >= 4){
							
							monstre_3_attaque = 0;
							
							printf("\n Le dps a esquive l'attaque !");
							
							monstre_3_attaque = 5;
						}
					}
					
					///////////MANQUE ATTAQUE DPS 4///////////////////////
					
				}		
					/*if(choixdps == 4){
						
						if(monstre_cible == 1){
							
							printf("\n vous bloquez les degats du monstre 1");
							
							pv_dps = pv_dps - 3;
							
							printf("\n vous avez maintenant %d points de vie", pv_dps);
						}
						
						if(monstre_2_cible == 1){
							
							printf("\n vous bloquez les degats du monstre 2");
							
							pv_dps = pv_dps - 3;
							
							printf("\n vous avez maintenant %d points de vie", pv_dps);
						}
						
						if(monstre_3_cible == 1){
							
							printf("\n vous bloquez les degats du monstre 3");
							
							pv_dps = pv_dps - 3;
							
							printf("\n vous avez maintenant %d points de vie", pv_dps);
						}
						*/
						
						
				
					
			}
			
			
			if(personnage == 3){			//TANK
				
				printf("\n MONSTRE A ATTAQUER: taper 1 pour attaquer le monstre 1,\n taper 2 pour attaquer le monstre 2,\n taper 3 pour attaquer le monstre 3\n");
				
				scanf("\n%d",&choixmonstre);
				
				if(choixmonstre == 1){		//MONSTRE ENNEMI 1
					
					printf("\n Vous avez choisi d'attaquer le monstre 1 !\n");
					
					printf("\n ACTION A EFFECTUER : taper 1 pour utiliser une attaque normale,\n taper 2 pour utiliser attaque puissante,\n taper 3 pour utiliser esquive,\n taper 4 pour se defendre.\n");
				
					scanf("\n%d\n", &choixtank);
					
					if(choixtank == 1){  // coup normal !		//ATTAQUE TANK 1
				
						printf("Vous decidez d'attaquer avec un coup normal!\n");
				
						pv_monstre = pv_monstre - 5;
						
						printf("\n Le monstre 1 a maintenant %d points de vie.", pv_monstre);
						
						mana_tank = mana_tank + 2;
						
						printf("\n le mana du TANK est de %d\n", mana_tank);
					}
					
					if(choixtank == 2){  //coup puissant !		//ATTAQUE TANK 2
						
						printf("Vous decidez d'attaquer avec un coup PUISSANT!\n");
						
						pv_monstre = pv_monstre - 8;
						
						printf("\n le monstre 1 a maintenant %d points de vie.", pv_monstre);
						
						mana_tank = mana_tank - 10;
						
						printf("\n le mana du TANK est de %d\n", mana_tank);
					}
						
					if(choixtank == 3){  //cri de guerre !		//ATTAQUE TANK 3
					
						printf("\n Vos allies frappent plus forts !");
						
						mana_tank = mana_tank - 10;
						
						printf("\n Le mana du TANK est de %d\n", mana_tank);
					}
					
				if(choixmonstre == 2){			//MONSTRE ENNEMI 2
					
					printf("\n Vous avez choisi d'attaquer le monstre 2 !\n");
					
					printf("\n ACTION A EFFECTUER : taper 1 pour utiliser une attaque normale,\n taper 2 pour utiliser attaque puissante,\n taper 3 pour utiliser esquive,\n taper 4 pour se defendre.\n");
				
					scanf("\n%d\n", &choixtank);
					
					if(choixtank == 1){  // coup normal !		//ATTAQUE TANK 1
				
						printf("Vous decidez d'attaquer avec un coup normal!\n");
				
						pv_monstre_2 = pv_monstre_2 - 5;
						
						printf("\n Le monstre 2 a maintenant %d points de vie.", pv_monstre_2);
						
						mana_tank = mana_tank + 2;
						
						printf("\n le mana du TANK est de %d\n", mana_tank);
					}
					
					if(choixtank == 2){  //coup puissant !		//ATTAQUE TANK 2
						
						printf("Vous decidez d'attaquer avec un coup PUISSANT!\n");
						
						pv_monstre_2 = pv_monstre_2 - 8;
						
						printf("\n le monstre 2 a maintenant %d points de vie.", pv_monstre_2);
						
						mana_tank = mana_tank - 10;
						
						printf("\n le mana du TANK est de %d\n", mana_tank);
					}
						
					if(choixtank == 3){  //cri de guerre !		//ATTAQUE TANK 3
					
						printf("\nVos allies frappent plus fort !\n");
						
						mana_tank = mana_tank - 10;
						
						printf("\nLe mana du TANK est de %d.\n", mana_tank);
					}
				}
						
				if(choixmonstre == 3){			//MONSTRE ENNEMI 3
					
					printf("\n Vous avez choisi d'attaquer le monstre 3 !\n");
					
					printf("\n ACTION A EFFECTUER : taper 1 pour utiliser une attaque normale,\n taper 2 pour utiliser attaque puissante,\n taper 3 pour utiliser esquive,\n taper 4 pour se defendre.\n");
				
					scanf("\n%d\n", &choixtank);
					
					if(choixtank == 1){  // coup normal !    //ATTAQUE TANK 1
				
						printf("Vous decidez d'attaquer avec un coup normal!\n");
				
						pv_monstre_3 = pv_monstre_3-5;
						
						printf("\n Le monstre 3 a maintenant %d points de vie.", pv_monstre_3);
						
						mana_tank = mana_tank + 2;
						
						printf("\n le mana du TANK est de %d\n", mana_tank);
					}
					
					if(choixtank == 2){  //coup puissant !			//ATTAQUE TANK 2
						
						printf("Vous decidez d'attaquer avec un coup PUISSANT!\n");
						
						pv_monstre_3 = pv_monstre_3 - 8;
						
						printf("\n le monstre 3 a maintenant %d points de vie.", pv_monstre_3);
						
						mana_tank = mana_tank - 10;
						
						printf("\n le mana du tank est de %d\n", mana_tank);
					}
						
					if(choixdps == 3){  //cri de guerre !			//ATTAQUE TANK 3
					
						printf("\nVos allies frappent plus fort !\n");
						
						mana_tank = mana_tank - 10;
						
						printf("\nLe mana du TANK est de %d.\n", mana_tank);
					
					}
				}
			}
			

			if(personnage == 2){		//DRUIDE
				
				printf("\n MONSTRE A ATTAQUER: taper 1 pour attaquer le monstre 1,\n taper 2 pour attaquer le monstre 2,\n taper 3 pour attaquer le monstre 3\n");
				
				scanf("\n%d",&choixmonstre);
				
				if(choixmonstre == 1){		//MONSTRE ENNEMI 1
					
					printf("\n Vous avez choisi d'attaquer le monstre 1 !\n");
					
					printf("\n ACTION A EFFECTUER : taper 1 pour utiliser une attaque normale,\n taper 2 pour utiliser attaque puissante,\n taper 3 pour utiliser poison,\n taper 4 pour soigner.\n");
				
					scanf("\n%d\n", &choixdruide);
					
					if(choixdruide == 1){  // coup normal !		//ATTAQUE DRUIDE 1
				
						printf("Vous decidez d'attaquer avec un coup normal!\n");
				
						pv_monstre = pv_monstre - 4;
						
						printf("\n Le monstre 1 a maintenant %d points de vie.", pv_monstre);
						
						mana_druide = mana_druide + 2;
						
						printf("\n le mana du DRUIDE est de %d\n", mana_druide);
					}
					
					if(choixdruide == 2){  //coup puissant !		//ATTAQUE DRUIDE 2
						
						printf("Vous decidez d'attaquer avec un coup PUISSANT!\n");
						
						pv_monstre = pv_monstre - 7;
						
						printf("\n le monstre 1 a maintenant %d points de vie.", pv_monstre);
						
						mana_druide = mana_druide - 10;
						
						printf("\n le mana du DRUIDE est de %d\n", mana_druide);
					}
						
					if(choixdruide == 3){  //poison !		//ATTAQUE DRUIDE 3
						
						for(i=0;i<pv_monstre;i--){
							
							pv_monstre = pv_monstre-3;
						
						printf("\nLe monstre est empoisonne.");
						
						mana_druide = mana_druide - 10;
						
						printf("\nLe druide a %d points de mana.",mana_druide);
						}
					
					}
					
					if(choixdruide == 4){ //heal !			//ATTAQUE DRUIDE 4
						
						printf("\nVous redonnez des pv aux allies.");
						
						pv_dps = pv_dps + 4;
						
						pv_tank = pv_tank +4;
					}
				}
				
					
				if(choixmonstre == 2){			//MONSTRE ENNEMI 2
					
					printf("\n Vous avez choisi d'attaquer le monstre 2 !\n");
					
					printf("\n ACTION A EFFECTUER : taper 1 pour utiliser une attaque normale,\n taper 2 pour utiliser attaque puissante,\n taper 3 pour utiliser poison,\n taper 4 pour soigner.\n");
				
					scanf("\n%d\n", &choixdruide);
					
					if(choixdruide == 1){  // coup normal !			//ATTAQUE DRUIDE 1
				
						printf("Vous decidez d'attaquer avec un coup normal!\n");
				
						pv_monstre_2 = pv_monstre_2-4;
						
						printf("\n Le monstre 2 a maintenant %d points de vie.", pv_monstre_2);
						
						mana_druide = mana_druide +2;
						
						printf("\n le mana du DPS est de %d\n", mana_druide);
					}
					
					if(choixdruide == 2){  //coup puissant !			//ATTAQUE DRUIDE 2
						
						printf("Vous decidez d'attaquer avec un coup PUISSANT!\n");
						
						pv_monstre_2 = pv_monstre_2 - 7;
						
						printf("\n le monstre 2 a maintenant %d points de vie.", pv_monstre_2);
						
						mana_druide = mana_druide - 10;
						
						printf("\n le mana du DPS est de %d\n", mana_druide);
					}
						
					if(choixdruide == 3){  //poison !			//ATTAQUE DRUIDE 3
					
						for(i=0;i<pv_monstre;i--){
							
							pv_monstre_2 = pv_monstre_2 - 3;
						
						printf("\nLe monstre est empoisonne.");
						
						mana_druide = mana_druide - 10;
						
						printf("\nLe druide a %d points de mana.",mana_druide);
						}
					}
					
					if(choixdruide == 4){ //heal !			//ATTAQUE DRUIDE 4
						
						printf("\nVous redonnez des pv aux allies.");
						
						pv_dps = pv_dps + 4;
						
						pv_tank = pv_tank +4;
					}
						
				}
						
				if(choixmonstre == 3){			//MONSTRE ENNEMI 3
					
					printf("\n Vous avez choisi d'attaquer le monstre 3 !\n");
					
					printf("\n ACTION A EFFECTUER : taper 1 pour utiliser une attaque normale,\n taper 2 pour utiliser attaque puissante,\n taper 3 pour utiliser poison,\n taper 4 pour soigner.\n");
				
					scanf("\n%d\n", &choixdruide);
					
					if(choixdruide == 1){  // coup normal !		//ATTAQUE DRUIDE 1
				
						printf("Vous decidez d'attaquer avec un coup normal!\n");
				
						pv_monstre_3 = pv_monstre_3 - 4;
						
						printf("\n Le monstre 3 a maintenant %d points de vie.", pv_monstre_3);
						
						mana_druide = mana_druide + 2;
						
						printf("\n le mana du DRUIDE est de %d\n", mana_druide);
					}
					
					if(choixdruide == 2){  //coup puissant !		//ATTAQUE DRUIDE 2
						
						printf("Vous decidez d'attaquer avec un coup PUISSANT!\n");
						
						pv_monstre_3 = pv_monstre_3 - 7;
						
						printf("\n le monstre 3 a maintenant %d points de vie.", pv_monstre_3);
						
						mana_druide = mana_druide - 10;
						
						printf("\n le mana du DRUIDE est de %d\n", mana_druide);
					}
						
					if(choixdruide == 3){       //poison !			//ATTAQUE DRUIDE 3
					
						for(i=0;i<pv_monstre;i--){
							
							pv_monstre_3 = pv_monstre_3 - 3;
						
						printf("\nLe monstre 3 est empoisonne.");
						
						mana_druide = mana_druide - 10;
						
						printf("\nLe druide a %d points de mana.",mana_druide);
						}
					}
					
					if(choixdruide == 4){ //heal !			//ATTAQUE DRUIDE 4
						
						printf("\nVous redonnez des pv aux allies.");
						
						pv_dps = pv_dps + 4;
						
						pv_tank = pv_tank +4;
					}
					
				}		
					
				
			}
			
			}
					
		}
			//CONDITION DE FIN DE COMBAT
		
			if(pv_monstre && pv_monstre_2 && pv_monstre_3 > 0){
				
				printf("\n\nLe combat continue.");
				
			}
			else{
				
				printf("\n\n Le combat est termine.");
				
				return 0;
			}
		
	}	
				
				
				
				
				
				
				
				
				
				
				
				
				
				
		/*		
				
				scanf("%d",&poison_dps);		//test écriture d'une valeur pour voir si poison agit
				
				
				if(pv_dps > 0 && poison_dps > 0){
				
						pv_dps = pv_dps - 3;
				
						pv_groupe = pv_groupe - 3;
				
						printf("[DPS]   Je suis empoisonne ! J'ai maintenant %d points de vie !\n",pv_dps);
				
						printf("[GROUPE]   Le groupe a maintenant un total de %d points de vie.\n\n",pv_groupe);
					
						poison_dps = poison_dps-1;
				}
				else if(poison_dps == 0){
					
						printf("[DPS]   Je ne suis plus empoisonne !\n");
						
				}
		}		
				
		
				scanf("%d",&poison_druide);		//test écriture d'une valeur pour voir si poison agit
			
				if(pv_druide > 0 && poison_druide > 0){			//verification de l'empoisonnement du druide
				
					pv_druide = pv_druide - 3;
				
					pv_groupe = pv_groupe - 3;
				
					printf("[DRUIDE]   Je suis empoisonne ! J'ai maintenant %d points de vie !\n",pv_druide);
				
					printf("[GROUPE]   Le groupe a maintenant un total de %d points de vie.\n\n",pv_groupe);
				
					poison_druide = poison_druide-1;
				}
				else if (poison_druide == 0){
					
					printf("[DRUIDE] Je ne suis plus empoisonne !\n");
				}
				
			
			
				
			scanf("%d",&poison_tank);		//test écriture d'une valeur pour voir si poison agit
			
			if(pv_tank > 0 && poison_tank>0){			//verification de l'empoisonnement du tank
				
				pv_tank = pv_tank - 3;
				
				pv_groupe = pv_groupe - 3;
				
				printf("[TANK]   Je suis empoisonne ! J'ai maintenant %d points de vie !\n",pv_tank);
				
				printf("[GROUPE]   Le groupe a maintenant un total de %d points de vie.\n\n",pv_groupe);
				
				poison_tank = poison_tank - 1;
			}
			else if(poison_tank == 0){
				
				printf("[TANK] Je ne suis plus empoisonne !\n");
			}
			
		}*/
