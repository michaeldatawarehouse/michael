#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Trajet Trajet ;
//DECLARATION DE LA STRUSTURE D'UN ELEMENT(TRAJET) DE LE PLIE
struct Trajet
{
	char depart[20];
	char arriver[20];
	 int cout;
	 int temps;
	 int b;
	struct  Trajet *suivant;
};
//DECLARATION DE LA SRTUCTURE DE CONTROLLE DE LE PILE
typedef struct Pile Pile;
 struct Pile
 {
 	Trajet *premier;
 };
 //FOCNTION INITIALISATION DE LA PILE DE TRAJET
 Pile* init()
 {
     Pile *p=(Pile*)malloc(sizeof(Pile*));
     p->premier=NULL;
     return p;
 }
 int nombre(Pile *p)
 {
     int v=0;
     Trajet *actuel=p->premier;
    	if(actuel==NULL)
		{
		exit(EXIT_FAILURE);
		}
    	while(actuel!= NULL)
    	{
    	    v++;

    			actuel=actuel->suivant;
		}

		return v;
 }
 //FONCTION D'AJOUT D'UN ELEMENT DANS LA PILE
  void ajouter(Pile *p,char depa[],char arrivera[],int couta ,int tempsa)
   {
   	Trajet *nouveau=malloc(sizeof(*nouveau));
   	if (nouveau == NULL)
	   {
	   exit(EXIT_FAILURE);
	   }
	  nouveau->suivant=p->premier;
	  p->premier=nouveau;
	  nouveau->cout=couta;
	  nouveau->temps=tempsa;
	 strcpy(nouveau->depart,depa);
	  strcpy(nouveau->arriver,arrivera);

   }
   // FONCTION D'AFFICHAGE DE LA PILE
    void afficher(Pile *p)
    {
    	Trajet *actuel2=p->premier;
    	if(actuel2==NULL)
		{
		exit(EXIT_FAILURE);
		}
    	while(actuel2!= NULL)
    	{
    		printf("(* depart:%s \n (*arriver:%s\n (*cout:%d \n (*temps:%d minutes\n \n",actuel2->depart,actuel2->arriver,actuel2->cout,actuel2->temps);
    		actuel2=actuel2->suivant;
		}
	}
		//DERNIER TRAJET  REALISER
	void der(Pile *p)
	{
	Trajet *actuel=p->premier;
    	if(actuel==NULL)
		{
		exit(EXIT_FAILURE);
		}
		printf(" le dernier trajet realiser  est:\n");
		printf("(* depart:%s \n (*arriver:%s\n (*cout:%d \n (*temps:%d minutes\n \n",actuel->depart,actuel->arriver,actuel->cout,actuel->temps);
	}
	// PREMIER TRAJET  REALISER
	void pre(Pile *p)
	{
	Trajet *actuel=p->premier;
    	if(actuel==NULL)
		{
		exit(EXIT_FAILURE);
		}
    	while(actuel->suivant!=NULL)
    	{
    		actuel=actuel->suivant;
		}
		printf(" le premier trajet realiser  est:\n");
		printf("(* depart:%s \n (*arriver:%s\n (*cout:%d \n (*temps:%d minutes\n \n",actuel->depart,actuel->arriver,actuel->cout,actuel->temps);
	}
		//SUPRESSION D'UN PLAT CONSOMMER
	void depiler(Pile *p)
	{
	int i=0,c=0;
		Trajet *actuel=p->premier;
    	if(actuel==NULL)
		{
		exit(EXIT_FAILURE);
		}
                    p->premier=actuel->suivant;
                    free(actuel);
		}
	//fonction de recherche d'un trajet
	void recherche(Pile *p,char t[20],char s[20])
	{
	    int i=0,c=0,k=0;
		Trajet *actuel=p->premier;
    	if(actuel==NULL)
		{
		exit(EXIT_FAILURE);
		}
    	while(actuel!=NULL)
    	{
    	   if((strcmp(actuel->depart,t)==0)&& (strcmp(actuel->arriver,s)==0))
    	    { i++;
k=c;
        }
c++;
 actuel=actuel->suivant;
    	    }
    	    if(i==0)
        {
            printf("trajet non trouver dans liste  DE trajet disponible\n");
        }
        else
            {
               printf(" trajet retrouver:\t");
    	        printf("vous l'avez deja realiser %d fois\n",i);
        }
	}
	// DEPENSE TOTALE pOUR TRANSPORT
void depense(Pile* p)
{
    float k=0;
    Trajet *actuel=p->premier;
    while(actuel!=NULL)
    {
        k=k+actuel->cout;
        actuel=actuel->suivant;
    }
    printf("VOUS AVEZ DEJA DEPENSER %0.f fcfa  pour votre transport\n",k);

}

// DEPENSE TOTALE pOUR TRANSPORT
void time(Pile* p)
{
    int k=0;
    int heure,minute;
    Trajet *actuel=p->premier;
    while(actuel!=NULL)
    {
        k=k+actuel->temps;
        actuel=actuel->suivant;
    }
    heure=k/60;
    minute=(k-(heure*60));
    printf("VOUS AVEZ DEJA  passer   %d heures  et %d minute pour votre transport\n",heure,minute);

}

  typedef struct Traje Traje;
struct Traje
{
	char depart[20];
	char arriver[20];
	 int cout;
	 int temps;
	 int b;
};
   void tri(Pile* p,int v)
    {
        int i=0;
       struct Traje t[v];
        Trajet *actuel3=p->premier;

        while((actuel3!=NULL)&&(i!=v))
        {
            t[i].temps=actuel3->temps;
            t[i].cout=actuel3->cout;
            strcpy(t[i].depart,actuel3->depart);
            strcpy(t[i].arriver,actuel3->arriver);
             actuel3=actuel3->suivant;
             i++;
        }
        int j;
         struct Traje k;
        for(i=0;i<v;i++)
    {
    for(j=i+1;j<v;j++)
    {
        if(t[i].cout<t[j].cout)
        {
            k=t[i];
            t[i]=t[j];
            t[j]=k;
        }
    }

}
        free(p);
       p=init();
      for(i=0;i<v;i++)
        {
            ajouter(p,t[i].depart,t[i].arriver,t[i].cout,t[i].temps);
           }
printf("en ordre croissant ont a");
        afficher(p);
    }

void trit(Pile* p,int v)
    {
        int i=0;
       struct Traje t[v];
        Trajet *actuel3=p->premier;

        while((actuel3!=NULL)&&(i!=v))
        {
            t[i].temps=actuel3->temps;
            t[i].cout=actuel3->cout;
            strcpy(t[i].depart,actuel3->depart);
            strcpy(t[i].arriver,actuel3->arriver);
             actuel3=actuel3->suivant;
             i++;
        }
        int j;
         struct Traje k;
        for(i=0;i<v;i++)
    {
    for(j=i+1;j<v;j++)
    {
        if(t[i].temps<t[j].temps)
        {
            k=t[i];
            t[i]=t[j];
            t[j]=k;
        }
    }

}
        free(p);
       p=init();
      for(i=0;i<v;i++)
        {
            ajouter(p,t[i].depart,t[i].arriver,t[i].cout,t[i].temps);
           }
printf("en ordre croissant ont a");
        afficher(p);
    }
int main()
{
   Pile *pi=init();
   char depc[20],arrc[20];
   int choix2;

   ajouter(pi,"polytecnique","mokolo",200,10);
   ajouter(pi,"atangana-mballa","chateau",150,15);
   ajouter(pi,"chateau"	,"deartement_info",0,5);
    ajouter(pi,"ekounou","atangana-mballa",150,20);
     ajouter(pi,"carrefour_amadou","mvan",300,30);
     ajouter(pi,"amasia","ekounou",12,0);
     ajouter(pi,"MOKOLO","briqueterie",150,3);
     ajouter(pi,"EKOUNOU","carrefour_soya",500,50);
  int choix1;
      int choix;
do{

	printf("0: Quitter le programme \n");
   	printf("1: MODULE DE GESTION DES TRAJETS:  \n");
   	printf("2: MODULE STATISTIQUE DES TRAJETS: \n");
	printf("\n\n\n");
	int nb=nombre(pi);
   	printf("Entrer votre choix \n");
   	scanf("%d",&choix);
   	switch(choix){
	 	case 0: break;
   		case 1:
            do{printf("*****BIENVENU DANS LE MODULE GESTION ******\n");
                    printf("VOICIE LES DIFFERENTS FONCTIONS QUE REALISE CE MODULE:\n");

            printf("0: QUITTER LE MODULE  \n");
        printf(" 1:EMPILER UN TRAJET :\n\n");
        printf("2:DEPILER UN TRAJET \n");
        printf("3:AFFICHER LA PILE DE TRAJET DISPONIBLE \n");
        printf("4:RECHERCHER D'UN TRAJET DANS LA PILE\n");
   		printf("\n\n\n");
   	printf("Entrer votre choix \n");
   	scanf("%d",&choix1);
   	switch(choix1){
	 	case 0: break;
   		case 1: system("cls");
            printf("entrer le nombre de trajet parcourue a ajouter \n");
            int n,i,j;
            scanf("%d",&n);
            for(i=0;i<=n;i++)
            { char depa[20];
                printf("entrer depart du trajet numero:%d a ajouter  ",i+1);
                scanf("%s",&depa);
                char arra[10];
                int tempa,couta;
                printf("entrer l'arriver du trajet numero:%d a ajouter  ",i+1);
                scanf("%s",&arra);
                printf("entrer le temps mis sur le trajet numero:%d a ajouter  ",i+1);
                scanf("%d",&tempa);
                printf("entrer le tarif du trajet numero:%d a ajouter  ",i+1);
                scanf("%d",&couta);
                ajouter(pi,depa,arra,couta,tempa);
            }
            printf("\n\n");
   		 break;
   		case 2:
                system("cls");
                depiler(pi);
   		 break;
   		case 3:
                afficher(pi);
                printf("\n\n");
   		 break;
   		case 4:
                printf("entrer le depart du trajet que vous rechercher");
                scanf("%s",&depc);
                 printf("entrer l'arriver du trajet que vous rechercher");
                scanf("%s",&arrc);
                recherche(pi,depc,arrc);
                printf("\n\n");
   		     break;
	}

	}while(choix1!=0);
printf("\n\n");
   		 break;
    case 2:
   		   do{

                    printf("*****BIENVENU DANS LE MODULE STATISTIQUE ******\n");
                    printf("VOICIE LES DIFFERENTS FONCTIONS QUE REALISE CE MODULE:\n");
            printf("0: QUITTER LE MODULE  \n");
        printf(" 1:RETROUVER LE DERNIER TRAJET REALISER\n");
        printf("2:RETROUVER LE PREMIER TRAJET REALISER\n ");
        printf("3:TRIER LA PILE DE TRAJET EN FONCTION DU COUT\n ");
        printf("4:TRIER LA PILE DE TRAJET EN FONCTION DU TEMPS MIS\n ");
   		printf("\n\n\n");
   	printf("Entrer votre choix \n");
   	scanf("%d",&choix2);
   	switch(choix2){
	 	case 0: break;
   		case 1:
   		der(pi);
   		printf("\n\n");
   		 break;
   		case 2:
              pre(pi);
              printf("\n\n");
   		 break;
   		case 3:
              tri(pi,nb);
   		 break;
   		 case 4:
              trit(pi,nb);
   		 break;
	}

                } while(choix2!=0);
printf("\n\n");
    break;
   		printf("\n\n\n");
   	}

   	}while(choix!=0);

    return 0;
}
