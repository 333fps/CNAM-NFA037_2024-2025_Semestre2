#include <stdio.h>
#include <stdlib.h>

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
	struct Individu individu;
	int temp_etat_civil;

	printf( "Veuillez saisir le nom de l'individu: " );
	(void)scanf( "%s", individu.nom );

	printf( "Veuillez saisir le prénom de l'individu: " );
	(void)scanf( "%s", individu.prenom );

	printf( "Veuillez saisir la date de naissance de l'individu (jj mm aaaa): " );
	(void)scanf( "%d %d %d", &individu.dateNaissance.jour, &individu.dateNaissance.mois, &individu.dateNaissance.annee );

	printf( "Veuillez saisir l'état civil de l'individu (0=Célibataire, 1=Marié, 2=Divorcé, 3=Veuf): " );
	(void)scanf( "%d", &temp_etat_civil );

	if ( temp_etat_civil >= 0 && temp_etat_civil <= 3 )
	{
		individu.etatCivil = (enum EtatCivil)temp_etat_civil;
	}
	else
	{
		printf( "État civil invalide, utilisation de la valeur par défaut (Célibataire)\n" );
		individu.etatCivil = Celibataire;
	}

	printf( "\nInformations sur l'individu:\n" );
	printf( "Nom: %s\n", individu.nom );
	printf( "Prénom: %s\n", individu.prenom );
	printf( "Date de naissance: %02d/%02d/%04d\n", individu.dateNaissance.jour,
		individu.dateNaissance.mois, individu.dateNaissance.annee );

	printf( "Etat civil: " );
	switch ( individu.etatCivil )
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

	return EXIT_SUCCESS;
}
