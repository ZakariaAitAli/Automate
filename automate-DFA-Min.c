#include <stdio.h>
#include <stdlib.h>
#include <string.h>

	typedef struct{
		char etats[30];
		char vers[30][30];
	}classe;

	void trier(char *tab){
		char y,z,tmp;
		if(strlen(tab)>1){
		for(int i=0;i<strlen(tab);i++){
		for(int j=0;j<strlen(tab);j++){
			y=tab[i];
			z=tab[j];
			if(y<z){
				tmp=tab[i];
				tab[i]=tab[j];
				tab[j]=tmp;
			}
		}
	}
}
	}

	int tester(classe *tab1, char *tab2){
		int x=0;
		for(int i=0;i<30;i++){
			if(strcmp(tab1[i].etats,tab2)==0){
				x=1;
			}
		}
		return x;
	}


	int testerCorespondance(classe *tab1,char *tab2){
	    int ic;
	for(int i=0;i<30;i++){
        if(strcmp(tab1[i].etats,tab2)==0){
            ic=i;
        }
	}
	return ic;
	}

	void copier(classe *tab1,char *tab2,int nb_col,int num_classe){
		for(int i=0,j=0;i<nb_col;i++,j++){
			tab1[num_classe].etats[i]=tab2[j];
		}
	}

	renverser(char *initial, char * final, char transitions[30][3], int nb_transitions){

		char renv[50][3];
		char initialrev[50];
		char finalrev[50];
		char tempo;
		char tempo2[30];


		for(int i=0;i<nb_transitions;i++){
			tempo=transitions[i][0];
			transitions[i][0]=transitions[i][1];
			transitions[i][1]=tempo;
		}

		strcpy(tempo2,initial);
		strcpy(initial,final);
		strcpy(final,tempo2);

	 	 		printf("\n les etats initiaux sont :");
	for(int i=0;i<strlen(initial);i++){
		printf("\n %c",initial[i]);
	}
	printf("\n Les etats finaux sont :");
	for(int i=0;i<strlen(final);i++){
		printf("\n %c \n",final[i]);
	}

	}


	int chercherFinal(char *tab1, char *tab2){
		int x=0;
		for(int i=0;i<strlen(tab1);i++){
			for(int j=0;j<strlen(tab2);j++){
				if(tab1[i]==tab2[j]){
					x=1;
				}
			}
		}
		return x;
	}


	char testerChemin(char cara,char etat,char transitions[30][3],int nb_transition){
	int x=0,h;
	char new_etat='-';
	for(h=0;h<=nb_transition;h++){
		if(x==0){
		if(etat==transitions[h][0] && cara==transitions[h][2]){
	   		new_etat=transitions[h][1];
	   		x=1;
	   	    }
	   	 }
	}
	return new_etat;
}

//fonction tester si c est un etat final
 int testfinal(char etat,char *final) {
 	int i;
 	int r;
 	r=0;
  	for(i=0;i<30;i++){
			if(etat==final[i]){
				r=1;
			}
	}
   return r;
 }

	 int testerMot(char mot[30],char transitions[30][3],int nb_transitions,char final[30]){
   char cara,etat;
   int x,h,y;
   etat=transitions[0][0];
   x=1;
   for(int i=0;i<strlen(mot);i++){
   	if(x==1){
   	cara=mot[i];
   	y=testerChemin(cara,etat,transitions,nb_transitions);
   	if(y=='-'){
   		x=0;
	   }
	   else{
	   	etat=y;
	   }
   }
}

   if(x!=1 || testfinal(etat,final)!=1){
   	x=0;
   }

   return x;
}




/* Défintion de la fonction qui va permettre de stocker l'automate dans un fichier .dot */
char StockerAutomate(char tab[255][3],char initial[50],char final[50],int nb_transitions,int nb_initial,int nb_final,FILE* file){
	int i;
	if(file!=NULL){
		fputs("digraph{\n",file);
		for(i=0;i<nb_initial;i++){
			fprintf(file,"initial->%c \n",initial[i]);
		}
		for(i=0;i<nb_transitions;i++){
		fprintf(file,"%c->%c [label=%c] \n",tab[i][0],tab[i][1],tab[i][2]);
	}
	for(i=0;i<nb_final;i++){
			fprintf(file,"%c->final \n",final[i]);
		}
	fputs("}",file);
	}
}
/* Fin de la fonction */
	/* Déterminisation de l'automate : */
	char determiniser(classe *tab,char *initial, char *final, char transitions[30][3],int j,int pi,int pf,char new_transitions[30][3],int *num_transition){
	int p=0,x,nb_classe=0,nb_col=0,tmp;
	 char etiquette[30];
	 
	 trier(initial);
// Extraction des étiquettes existant dans l'automate sans répétition
	for(int i=0;i<j;i++){
		x=1;
		for(int k=0;k<p;k++){
			if(etiquette[k]==transitions[i][2]){
				x=0;
			}
		}
		if(x==1){
		etiquette[p]=transitions[i][2];
		p++;
	}
	}
// Fin extraction .

	char etat,new_classe[30];
// Initialisation de la nouvelle classe avec les états initiaux.
	for(int i=0;i<pi;i++){
		tab[0].etats[i]=initial[i];
	}
//
	    for(int ii=0;ii<30;ii++){
		for(int i=0;i<30;i++){
		tab[ii].vers[0][i]=etiquette[i];
	}
}
for(int ii=0;ii<30;ii++){
	for(int iii=1;iii<30;iii++){
		for(int i=0;i<30;i++){
		tab[ii].vers[iii][i]='-';
	}
}
}

printf("\n Les nouveaux classes  \n %s \n",initial);
tmp=1;
	for(int ic=0;ic<30;ic++){
			for(int ia=0;ia<p;ia++){
			int nb_etat=1;
			for(int i=0;i<strlen(tab[ic].etats);i++){
			etat=tab[ic].etats[i];
			for(int it=0;it<j;it++){
			if(transitions[it][0]==etat && transitions[it][2]==etiquette[ia]){
				tab[ic].vers[nb_etat++][ia]=transitions[it][1];
			}
		}
		}
	}

		int new_etat=0;
		for(int ivc=0;ivc<p;ivc++){
			nb_col=0;
			int ajouter=1;
		for(int iv=1;iv<30;iv++){
			if(tab[ic].vers[iv][ivc]!='-'){
				for(int m=0;m<nb_col;m++){                     // On teste si l'état est déja écrite dans la variable new_classe.
					if(tab[ic].vers[iv][ivc]==new_classe[m]){
						ajouter=0;
					}											// Fin du test.
				}
				if(ajouter!=0){
				new_classe[nb_col++]=tab[ic].vers[iv][ivc];     // On ajoute l'état dans la new_classe.
				}
				ajouter=1;
		}
		}
		trier(new_classe); 		// On trie new_classe pour qu'on facilite le test de l'existence de la classe.
			if(tester(tab,new_classe)==0 && nb_col!=0){
					copier(tab,new_classe,nb_col,tmp);
					printf("\n %s \n",new_classe);
					tmp++;
			}

			for(int i=0;i<30;i++){     // On vide la variable new_classe.
					new_classe[i]='\0';
					}

}

}


*num_transition=0;
for(int ic=0;ic<10;ic++){
    for(int ivc=0;ivc<p;ivc++){
    	new_transitions[*num_transition][0]=ic+'0';
			nb_col=0;
		for(int iv=1;iv<30;iv++){
			if(tab[ic].vers[iv][ivc]!='-'){
				new_classe[nb_col++]=tab[ic].vers[iv][ivc];
		}
		}
		trier(new_classe);
		if(new_classe[0]!='\0'){
		new_transitions[*num_transition][1]=testerCorespondance(tab,new_classe)+'0';
		new_transitions[*num_transition][2]=tab[ic].vers[0][ivc];
		(*num_transition)++;
	}
		for(int i=0;i<30;i++){
        new_classe[i]='\0';
        }


    }

}
char ancien_final[30];

			strcpy(ancien_final,final);

			for(int i=0;i<30;i++){
                    initial[i]='\0';
					final[i]='\0';
				}
                initial[0]='0';
				int nb_final=0;

			  for(int ic=0;ic<10;ic++){                 // On cherche quels sont les nouveaux états finaux.
			  	if(chercherFinal(tab[ic].etats,ancien_final)==1){
			  		final[nb_final++]='0'+ic;
				  }
			  }
				pi=1;
				pf=nb_final;

	printf("\n les etats initiaux sont :\n");
	for(int i=0;i<pi;i++){
		printf("\n %c",initial[i]);
	}
	printf("\n Les etats finaux sont :\n");
	for(int i=0;i<pf;i++){
		printf("\n %c",final[i]);
	}


}


int main(){
	int i,j,k,pi,pf,tmp,iv,ivc,num_transition;
	char initial[50],final[50],vide[30],new_transitions[30][3];
	FILE* fichier=NULL;
	FILE* fichier2=NULL;
	char c,t[255],transitions[50][3];
	fichier=fopen("automate.dot","r+");
	if(fichier!=NULL){
	c=fgetc(fichier);
	k=0;
	/* On enregistre tout caractéres écrit dans le fichier .dot */
	while(c!=EOF){
		if(c!=' '){ /*Pour ne pas prendre en consdération les espaces*/
		t[k]=c;
		k++;
		}
	c=fgetc(fichier);
	}
	j=0;
	/* On visualise tout le texte du fichier .dot (juste pour tester)*/
	printf("Tous ce qui est ecrit dans le fichier .dot sans espace \n");
	for(i=0;i<k;i++){
		printf("%c",t[i]);
	}
	/* On va collecter les informations nécessaires tel que les transitions (états et étiquette) */
for(i=0;i<k;i++){
		if(t[i+1]=='-' && t[i+2]=='>'){
			transitions[j][0]=t[i];
			transitions[j][1]=t[i+3];
		}
		if(t[i]=='='){
		  	transitions[j][2]=t[i+1];
		  	j++;
		}	}
	/* On affiche les transitions */
	printf("\n Les transitions sont :");
	for(i=0;i<j;i++){
		printf("\n %c->%c %c ",transitions[i][0],transitions[i][1],transitions[i][2]);
	}

	/*Extraction des états initiaux et finaux*/
	pi=0;
	pf=0;
	for(i=0;i<k;i++){
		if(t[i]=='i' && t[i+1]=='n' && t[i+6]=='l'){ /* Le début de l'automate on le définit avec un état qui a pour nom <initial>, donc les états initiaux sont tous lié avec cet état.*/
			initial[pi]=t[i+9];
			pi++;
		}
		if(t[i]=='f' && t[i+1]=='i' && t[i+4]=='l'){ /* La fin de l'automate on le définit avec un état qui a pour nom <final>, donc les états d'acceptation sont tous lié avec cet état.*/
			final[pf]=t[i-3];
			pf++;
		}
	}
	/* On affiche les états initiaux et finaux */
	printf("\n les etats initiaux sont :");
	for(i=0;i<pi;i++){
		printf("\n %c",initial[i]);
	}
	printf("\n Les etats finaux sont :");
	for(i=0;i<pf;i++){
		printf("\n %c",final[i]);
	}


}

/* Appelant la fonction de determinisation */
printf("\n \n \n _______________________Determinisation de l automate_________________________ \n");
	classe tab[30];
	determiniser(tab,initial,final,transitions,j,pi,pf,new_transitions,&num_transition);
	printf("\n L automate deterministe \n");
	for(int i=0;i<num_transition;i++){
    printf("%c -> %c %c \n",new_transitions[i][0],new_transitions[i][1],new_transitions[i][2]);
}
/* Fin de déterminisation */
/* On stocke l'automate dans un autre fichier en appelant la fonction StockerAutomate*/
FILE *f_DFA;
	f_DFA=fopen("auto_dfa.dot","w+");
	StockerAutomate(new_transitions,initial,final,num_transition,strlen(initial),strlen(final),f_DFA);

/*minimisation*/
printf("\n \n \n _______________________Minimisation de l automate______________________________ \n");
	classe tab2[30],tab3[30];
	int num_transition2,num_transition3;
	char new_transitions2[30][3],new_transitions3[30][3];
	printf("\n L automate renverse n 1 \n");
    renverser(initial,final,new_transitions,num_transition);
    for(int i=0;i<num_transition;i++){
    printf("%c -> %c %c \n",new_transitions[i][0],new_transitions[i][1],new_transitions[i][2]);
	}
	determiniser(tab2,initial,final,new_transitions,num_transition,strlen(initial),strlen(final),new_transitions2,&num_transition2);
	printf("\n L automate deterministe n 1 \n");
		for(int i=0;i<num_transition2;i++){
    printf("%c -> %c %c \n",new_transitions2[i][0],new_transitions2[i][1],new_transitions2[i][2]);
}
//
	 printf("\n L automate renversé n 2 \n");
	renverser(initial,final,new_transitions2,num_transition2);
    for(int i=0;i<num_transition;i++){
    printf("%c -> %c %c \n",new_transitions[i][0],new_transitions[i][1],new_transitions[i][2]);
	}
	determiniser(tab3,initial,final,new_transitions2,num_transition2,strlen(initial),strlen(final),new_transitions3,&num_transition3);
	printf("\n L automate minimal \n");
	for(int i=0;i<num_transition3;i++){
    printf("%c -> %c %c \n",new_transitions3[i][0],new_transitions3[i][1],new_transitions3[i][2]);
	}

	// Fin minimisation.

	/* On stocke l'automate dans un autre fichier en appelant la fonction StockerAutomate*/
FILE *f_MIN;
	f_MIN=fopen("auto_min.dot","r+");
	StockerAutomate(new_transitions3,initial,final,num_transition3,strlen(initial),strlen(final),f_MIN);

	/* ______________________________________________________________________*/
   char mot[30],cara,etat;
   int x,h,y;
   printf("\n entrer le mot pour le tester") ;
   scanf("%s",mot);
   etat=new_transitions3[0][0];
   x=1;
   for(int i=0;i<strlen(mot);i++){
   	if(x==1){
   	cara=mot[i];
   	y=testerChemin(cara,etat,new_transitions3,j);
   	if(y=='-'){
   		x=0;
	   }
	   else{
	   	etat=y;
	   }
   }
}

   if(x==1 && testfinal(etat,final)==1){
   	printf("\n Oui, le mot appartient \n");
   }
   else{
   		printf("\n Non, le mot n appartient pas \n");
   }


    /* ______________________________________________________________________*/
 FILE *f_mot;
 char ch[30];
 f_mot=fopen("mots.txt","r");
 if(f_mot!=NULL){
 	printf("\n Les mots engendres par cet automate a partir du fichier <mots.txt> sont : \n");
 	while(!feof(f_mot)){
 		fscanf(f_mot,"%s",ch);
 		if(testerMot(ch,new_transitions3,num_transition3,final)==1){
 			printf("%s \n",ch);
		 }
	 }
 }
}
