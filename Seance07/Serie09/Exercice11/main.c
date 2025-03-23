#include <stdio.h>

struct Date
{
	int jour;
	int mois;
	int annee;
};

enum EtatCivil
{
	Celibataire,
	Marie,
	Divorce,
	Veuf
};

struct Individu
{
	char nom[20];
	char prenom[20];
	struct Date dateNaissance;
	enum EtatCivil etatCivil;
};

int main( void )
{
	struct Individu personnes[4] = { 0 };
	int i;

	for ( i = 0; i < 4; i++ )
	{
		printf( "\n--- Personne %d ---\n", i + 1 );

		printf( "Veuillez saisir le nom de l'individu: " );
		(void)scanf( "%19s", personnes[i].nom );

		printf( "Veuillez saisir le prénom de l'individu: " );
		(void)scanf( "%19s", personnes[i].prenom );

		printf( "Veuillez saisir la date de naissance de l'individu (jj mm aaaa): " );
		(void)scanf( "%d %d %d",
			&personnes[i].dateNaissance.jour,
			&personnes[i].dateNaissance.mois,
			&personnes[i].dateNaissance.annee );

		printf( "Veuillez saisir l'état civil de l'individu (0=Célibataire, 1=Marié, 2=Divorcé, 3=Veuf): " );
		{
			int temp;
			(void)scanf( "%d", &temp );
			if ( temp >= 0 && temp <= 3 )
			{
				personnes[i].etatCivil = (enum EtatCivil)temp;
			}
			else
			{
				printf( "État civil invalide, valeur par défaut (Célibataire) utilisée\n" );
				personnes[i].etatCivil = Celibataire;
			}
		}
	}

	printf( "\n=== INFORMATIONS SUR LES PERSONNES ===\n" );

	for ( i = 0; i < 4; i++ )
	{
		printf( "\n--- Personne %d ---\n", i + 1 );
		printf( "Nom: %s\n", personnes[i].nom );
		printf( "Prénom: %s\n", personnes[i].prenom );
		printf( "Date de naissance: %02d/%02d/%04d\n",
			personnes[i].dateNaissance.jour,
			personnes[i].dateNaissance.mois,
			personnes[i].dateNaissance.annee );

		printf( "Etat civil: " );
		switch ( personnes[i].etatCivil )
		{
			case Celibataire:
				printf( "Célibataire\n" );
				break;
			case Marie:
				printf( "Marié\n" );
				break;
			case Divorce:
				printf( "Divorcé\n" );
				break;
			case Veuf:
				printf( "Veuf\n" );
				break;
			default:
				break;
		}
	}

	return 0;
}
