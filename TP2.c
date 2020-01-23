#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int pv_dps = 30;					// statistiques du dps
	int mana_dps = 15;
	int poison_dps = 0;
	int lame_tranchante = 0;
	int Esquive = 0;
	
	int pv_druide = 40;					//statistiques du druide
	int mana_druide = 20;
	int poison_druide = 0;
	int invocation_foudre = 0;
	int malediction = 0;
	
	int pv_tank = 50;					//statistiques du tank
	int mana_tank = 15;
	int poison_tank = 0;
	int contre_attaque = 0;
	int cri_de_guerre = 0;
	
	int pv_groupe = 120; 				//points de vie du groupe
	
	int poison_monstre = 0;
	

	//pv_dps + pv_druide + pv_tank = pv_groupe;  		//liaison des PV des differents joueurs en PV de groupe
	

	scanf("%d\n",&personnage);					//test boucle poison dps et choix personnage
	
	
	// VERIFICATION DE L'EMPOISONNEMENT CHEZ CHACUN DES JOUEURS
	while(pv_groupe>0){
		
		
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
		
	}
}