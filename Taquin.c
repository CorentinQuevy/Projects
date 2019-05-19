// ----------------------------------------------------------
//           DEUST MIR - Semestre 2 - Programmation C
// ----------------------------------------------------------
//      Quévy Corentin - Taleb Ahmed Sabri - Hamou Kaddour 
// ----------------------------------------------------------
//                     Université de Lille


// Bibiliotèques utilisées
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Variable globale

int choix=0;

// Fonctions d'affichage

void logo(){
	printf("\n");
	printf("\n");
	printf(" 						    .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .-----------------.\n");
	printf("						   | .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |\n");
	printf("						   | |  _________   | || |      __      | || |    ___       | || | _____  _____ | || |     _____    | || | ____  _____  | |\n");
	printf("						   | | |  _   _  |  | || |     /  \\     | || |  .'   '.     | || ||_   _||_   _|| || |    |_   _|   | || ||_   \\|_   _| | |\n");
	printf("						   | | |_/ | | \\_|  | || |    / /\\ \\    | || | /  .-.  \\    | || |  | |    | |  | || |      | |     | || |  |   \\ | |   | |\n");
	printf("						   | |     | |      | || |   / ____ \\   | || | | |   | |    | || |  | '    ' |  | || |      | |     | || |  | |\\ \\| |   | |\n");
	printf("						   | |    _| |_     | || | _/ /    \\ \\_ | || | \\  `-'  \\_   | || |   \\ `--' /   | || |     _| |_    | || | _| |_\\   |_  | |\n");
	printf("						   | |   |_____|    | || ||____|  |____|| || |  `.___.\\__|  | || |    `.__.'    | || |    |_____|   | || ||_____|\\____| | |\n");
	printf("						   | |              | || |              | || |              | || |              | || |              | || |              | |\n");
	printf("						   | '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |\n");
	printf("						    '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' \n");
	printf("\n");
	printf("\n");
}

void menu(){
	printf("\n");
	printf("\n");
	printf("											     .-----------------------------------. \n");
	printf("											    | .---------------------------------. |\n");
	printf("											    | |                                 | |\n");
	printf("											    | |            1. Jouer             | |\n");
	printf("											    | |                                 | |\n");
	printf("											    | |        2. Comment jouer ?       | |\n");
	printf("											    | |                                 | |\n");
	printf("											    | |         3. Instruction          | |\n");
	printf("											    | |                                 | |\n");
	printf("											    | '---------------------------------' |\n");
	printf("											     '-----------------------------------' \n");
	printf("\n");
	printf("\n");
}

void tuto(){
	printf("\n");
	printf("\n");
	printf("											     .-----------------------------------. \n");
	printf("											    | .---------------------------------. |\n");
	printf("											    | |                                 | |\n");
	printf("											    | |   Entrez le numéro de la case   | |\n");
	printf("											    | |   que vous souhaitez déplacer.  | |\n");
	printf("											    | |   Doit être voisine de la case  | |\n");
	printf("											    | |               vide.             | |\n");
	printf("											    | |                                 | |\n");
	printf("											    | '---------------------------------' |\n");
	printf("											     '-----------------------------------' \n");
	printf("\n");
	printf("\n");
}

void info(){
	printf("\n");
	printf("\n");
	printf("											     .-----------------------------------. \n");
	printf("											    | .---------------------------------. |\n");
	printf("											    | |                                 | |\n");
	printf("											    | |   Pour gagner il faut reussir   | |\n");
	printf("											    | |     à remettre les chiffres     | |\n");
	printf("											    | |          dans l'ordre !         | |\n");
	printf("											    | |                                 | |\n");
	printf("											    | '---------------------------------' |\n");
	printf("											     '-----------------------------------' \n");
	printf("\n");
	printf("\n");
}

// Fonction qui génère une grille aleatoire
void GenereGrille (int largeur, int hauteur)
{
	// Déclarations
    int nb_cases = largeur * hauteur;
    int *tab = NULL, *tmp_tab = NULL;
    int i, n, nb_changements;
    int x, tmp;
    int similitude;
    int cpt = -1;
    tab = malloc(nb_cases* sizeof *tab), tmp_tab = malloc(nb_cases * sizeof *tab);
    int saisie;
    int boucle=1;

    do
    {
        nb_changements = 0;
        // Initialise le tableau 
        for ( i=0 ; i<nb_cases ; i++ )
        {
            tab[i] = i;
        }
        // Le génère aléatoirement
        for ( i=0 ; i<nb_cases ; i++ )
        {
            x = i + (rand() % (nb_cases-i));
            tmp = tab[i];
            tab[i] = tab[x];
            tab[x] = tmp;
        }
        // cherche les similitudes
        for ( i=0; tab[i] != 0; i++ );
        similitude = (largeur-1) + (hauteur-1) - ((i/largeur) + (i%largeur));
        // copie du tableau pour comptage 
        memcpy(tmp_tab, tab, nb_cases * sizeof *tab);
        // On positionne 0 en fin 
        if (i < nb_cases-1)
        {
            tmp = tmp_tab[nb_cases-1];
            tmp_tab[nb_cases-1] = tmp_tab[i];
            tmp_tab[i] = tmp;
            nb_changements++;
        }
        // comptage des changements restants
        for ( i=nb_cases-1; i>0; i-- )
        {
            if (tmp_tab[i-1] < i)
            {
                for (n=i-1; n>=0; n--)
                {
                    if (tmp_tab[n] == i)
                    {
                        tmp = tmp_tab[n];
                        tmp_tab[n] = tmp_tab[i-1];
                        tmp_tab[i-1] = tmp;
                        nb_changements++;
                    }
                }
            }
        }
    }
    while (((nb_changements%2)^(similitude%2)));


    // Affichage du tableau melangé

 	printf("       0    1    2    3\n");
    for ( i=0 ; i<nb_cases ; i++ )
    {
        if (!(i%largeur))
        {
            printf("\n");
            printf("      ----+----+----+----\n");
            printf("%2i   |", cpt = cpt +1);
        }
        printf(" %2i |", tab[i]);
    }
    printf("\n");
    printf("      ----+----+----+----\n");
    cpt =-1;


    // Boucle qui permet de jouer tant que la grille n'est pas dans la position gagnante
    do
    {
    	for(i=0 ; i<nb_cases; i++)
    	{
	        if(tab[i]==0)
	        {

	            printf("\nEntrez le numéro de la case que vous souhaitez déplacer :");
	            scanf("%2i", &saisie);
	            // Si la saisie est égale au chiffre situé à gauche
	       		if(saisie==tab[i-1])
	       		{
	       			// Echange la case de gauche avec le zéro
	       			tab[i]=tab[i-1];
	       			// Réinitialise la case à 0
	       			tab[i-1]=0; 
	       			// Et réimprime le tableau
	       			printf("       0    1    2    3\n");
	       			for ( i=0 ; i<nb_cases ; i++ )
					   {
					       if (!(i%largeur))
					        {
					            printf("\n");
					            printf("      ----+----+----+----\n");
					            printf("%2i   |", cpt = cpt +1);
					        }
					        printf(" %2d |", tab[i]);
					   }
					   printf("\n");
					   printf("      ----+----+----+----\n");
					   printf("\n");
					   tab[i]=0;
					   cpt = -1;
				}
				if(saisie==tab[i-4])
	       		{
	       			// Echange la case du haut avec le zéro
	       			tab[i]=tab[i-4];
	       			// Réinitialise la case à 0
					tab[i-4]=0;
					// Et réimprime le tableau
	       			printf("       0    1    2    3\n");
	       			for ( i=0 ; i<nb_cases ; i++ )
					   {
					       if (!(i%largeur))
					        {
					            printf("\n");
					            printf("      ----+----+----+----\n");
					            printf("%2i   |", cpt = cpt +1);
					        }
					        printf(" %2d |", tab[i]);
					   }
					   printf("\n");
					   printf("      ----+----+----+----\n");
					   printf("\n");
					   tab[i]=0;
					   cpt = -1;
				}
				if(saisie==tab[i+1])
	       		{
	       			// Echange la case de droite avec le zéro
	       			tab[i]=tab[i+1];
	       			// Réinitialise la case à 0
	       			tab[i+1]=0;
	       			// Et réimprime le tableau
	       			printf("       0    1    2    3\n");
	       			for ( i=0 ; i<nb_cases ; i++ )
					   {
					       if (!(i%largeur))
					        {
					            printf("\n");
					            printf("      ----+----+----+----\n");
					            printf("%2i   |", cpt = cpt +1);
					        }
					        printf(" %2d |", tab[i]);
					   }
					   printf("\n");
					   printf("      ----+----+----+----\n");
					   printf("\n");
					   tab[i]=0;
					   cpt = -1;
				}
				if(saisie==tab[i+4])
	       		{
	       			// Echange la case du bas avec le zéro
	       			tab[i]=tab[i+4];
	       			// Réinitialise la case à 0
	       			tab[i+4]=0;
	       			// Et réimprime le tableau
	       			printf("       0    1    2    3\n");
	       			for ( i=0 ; i<nb_cases ; i++ )
					   {
					       if (!(i%largeur))
					        {
					            printf("\n");
					            printf("      ----+----+----+----\n");
					            printf("%2i   |", cpt = cpt +1);
					        }
					        printf(" %2d |", tab[i]);
					   }
					   printf("\n");
					   printf("      ----+----+----+----\n");
					   printf("\n");
					   tab[i]=0;
					   cpt= -1;
				}
				// Position gagnante
				 if(tab[i]==0 && tab[i-1]==15 && tab[i-2]==14 && tab[i-3]==13 && tab[i-4]==12 && tab[i-5]==11 && tab[i-6]==10 && tab[i-7]==9 && tab[i-8]==8 && tab[i-9]==7 && tab[i-10]==6 && tab[i-11]==5 && tab[i-12]==4 && tab[i-13]==3 && tab[i-14]==2 && tab[i-15]==1)
				   	{
				   		// On met la boucle à 2 pour sortir du while
				   		boucle = 2;
				   		printf("\n\nTaquin résolu ! Bien joué !\n");
				   		
				    }

				

       		}
       			

        }
        
    }
    while(boucle==1);

    // libère la mémoire
    free(tmp_tab);
    free (tab);
}


// Fonction permettant de revenir au menu principal

void backToMainMenu(){
	printf("										   Pour revenir au Menu principal, appuyez sur la touche 0 :");
	scanf("%i", &choix);
	
	// Empèche l'utilisateur de mettre autre choses que zéro
	while(choix!=0){
		scanf("%i", &choix);
	}

	// Si l'utilisateur tape 0 alors on revient au menu principale
	if(choix==0){
		system ("clear");
		logo();
		menu();
	}

	printf("											    	 Veuillez entrer votre choix : ");
	scanf("%i", &choix);
}

// Fonction principale

int main(void){

   	int infiniteLoop=1;

   	// Affiche le menu tant que infiniteLoop est égale à 1
	while(infiniteLoop==1){
		system("clear");
	    logo();
	    menu();

	    printf("											    	 Veuillez entrer votre choix : ");
	    

	    // Redemande le choix tant que celui si n'est pas égale à ceux affiché
	    while(choix!=1 && choix!=2 && choix!=3){
	    	printf("\b");
	    	scanf("%i", &choix);
	    }
	    // Affiche le tutoriel
	    if(choix==2){
	    	system("clear");
			logo();
			tuto();
			backToMainMenu();

	    }
	    // Affiche les informations
	    else if (choix==3){
	    	system("clear");
	    	logo();
	    	info();
	    	backToMainMenu();
	    
	    }
	    // Affiche le jeu
	    else if (choix==1){
	    	system("clear");
	    	srand(time(NULL));
	    	GenereGrille (4,4);
	    	printf("\n");
	    	return 0;

	    }

	    
	}

}
