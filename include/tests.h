#ifndef __TESTS_H__
#define __TESTS_H__

#include <stdio.h>


#define ISO6429_REMISE_A_ZERO "0"
#define ISO6429_GRAS "1"
#define ISO6429_SOULIGNE "4"
#define ISO6429_CLIGNOTE "5"
#define ISO6429_FIN_CLIGNOTE "25"
#define ISO6429_INVERSE "7"
#define ISO6429_FONTE(n) "1" ISO6429_str(n)
#define ISO6429_NOIR "0"
#define ISO6429_ROUGE "1"
#define ISO6429_VERT "2"
#define ISO6429_JAUNE "3"
#define ISO6429_BLEU "4"
#define ISO6429_MAGENTA "5"
#define ISO6429_CYAN "6"
#define ISO6429_BLANC "7"
#define ISO6429_TEXTE(couleur) "3" couleur
#define ISO6429_FOND(couleur) "4" couleur
#define ISO6429_SEP ";"
#define ISO6429_CSI "\33["
#define ISO6429_CMD_COULEUR "m"
#define ISO6429_COULEUR(spec) ISO6429_CSI spec ISO6429_CMD_COULEUR

/*
  Utilisation:
  FONTE(5)  -> "15" // fontes entre 10 et 19
  COULEUR(GRAS SEP TEXTE(BLEU)) --> "\33[1;34m" // texte entre 30 et 37
  COULEUR(FOND(ROUGE)) --> "\33[1;41m" // fond entre 40 et 47
*/

#define ISO6429_CURSEUR_HAUT(n)           ISO6429_CSI #n "A"
#define ISO6429_CURSEUR_BAS(n)            ISO6429_CSI #n "B"
#define ISO6429_CURSEUR_DROIT(n)          ISO6429_CSI #n "C"
#define ISO6429_CURSEUR_GAUCHE(n)         ISO6429_CSI #n "D"
#define ISO6429_LIGNE_SUIVANTE(n)         ISO6429_CSI #n "E"
#define ISO6429_LIGNE_PRECEDENTE(n)       ISO6429_CSI #n "F"
#define ISO6429_CURSEUR_POS_X(n)          ISO6429_CSI #n "G"
#define ISO6429_CURSEUR_POS_Y(n)          ISO6429_CSI #n "H"
#define ISO6429_CLEAR_SCREEN_ABOVE        ISO6429_CSI "1J"
#define ISO6429_CLEAR_SCREEN_BELOW        ISO6429_CSI "0J"
#define ISO6429_CLEAR_SCREEN              ISO6429_CSI "2J"
#define ISO6429_SUPPRIME_LIGNE_AVANT      ISO6429_CSI "1K"
#define ISO6429_SUPPRIME_LIGNE_APRES      ISO6429_CSI "0K"
#define ISO6429_SUPPRIME_LIGNE_TOUT       ISO6429_CSI "2K"
#define ISO6429_PAGE_DESSUS(n)            ISO6429_CSI #n "S"
#define ISO6429_PAGE_DESSOUS(n)           ISO6429_CSI #n "T"
#define ISO6429_POSITIONNE(x,y)           ISO6429_CSI #y ISO6429_SEP #x "f"
#define ISO6429_SAUVE_POSITION_CURSEUR    ISO6429_CSI "s"
#define ISO6429_RESTAURE_POSITION_CURSEUR ISO6429_CSI "u"
#define ISO6429_CACHE_CURSEUR             ISO6429_CSI "?25l"
#define ISO6429_MONTRE_CURSEUR            ISO6429_CSI "?25h"

struct iso6429_point {
  int x ;
  int y ;
} ;


/*
  Pour l'utiliser sans probl�mes, il vaut mieux que les entr�es soient "hot"
 */
struct iso6429_point
iso6429_position_curseur ( )
{
  struct iso6429_point point ;
  printf ( ISO6429_CSI "6n" ) ;
  scanf ( "\33[%d;%dR" , &(point.x) , &(point.y) ) ;
  return point ;
}


#define POSITION "Fichier "__FILE__ ", ligne %d (fonction %s):\n"

#ifdef USECOLORS
#define COULEUR_SUCCES  ISO6429_COULEUR(ISO6429_GRAS ISO6429_SEP ISO6429_TEXTE(ISO6429_VERT))
#define COULEUR_ECHEC   ISO6429_COULEUR(ISO6429_GRAS ISO6429_SEP ISO6429_TEXTE(ISO6429_ROUGE))
#define COULEUR_INFO    ISO6429_COULEUR(ISO6429_GRAS ISO6429_SEP ISO6429_TEXTE(ISO6429_BLEU))
#define COULEUR_NORMALE ISO6429_COULEUR(ISO6429_REMISE_A_ZERO)
#else
#define COULEUR_SUCCES  ""
#define COULEUR_ECHEC   ""
#define COULEUR_INFO    ""
#define COULEUR_NORMALE ""
#endif


#ifdef production

#define VAL_INT(n)  ((void)0)

#define TEST_RES(x) ((void)0)

#define ASSERT(x)   ((void)0)

#define debug(...)  ((void)0)

#define test(x)     ((void)0)

#else

#define TEST_str(x) #x

#define VAL_INT(n)  fprintf ( stderr , COULEUR_INFO POSITION "\t" TEST_str(n) " = %d\n" \
			     COULEUR_NORMALE , __LINE__ , __func__ , n )
#define VAL_CHAR(n)  fprintf ( stderr , COULEUR_INFO POSITION "\t" TEST_str(n) " = %c\n" \
			     COULEUR_NORMALE , __LINE__ , __func__ , n )
#define VAL_STRING(n)  fprintf ( stderr , COULEUR_INFO POSITION "\t" TEST_str(n) " = %s\n" \
			     COULEUR_NORMALE , __LINE__ , __func__ , n )
#define VAL_FLOAT(n)  fprintf ( stderr , COULEUR_INFO POSITION "\t" TEST_str(n) " = %f\n" \
			     COULEUR_NORMALE , __LINE__ , __func__ , n )
#define VAL_POINTER(n)  fprintf ( stderr , COULEUR_INFO POSITION "\t" TEST_str(n) " = %p\n" \
				  COULEUR_NORMALE , __LINE__ , __func__ , (void *) n )
#define TEST_RES(x) ( x ) ? \
      fprintf ( stderr , COULEUR_SUCCES POSITION "\t" TEST_str(x)  " --> vrai \n" \
		COULEUR_NORMALE , __LINE__ , __func__ ) :		\
      fprintf ( stderr , COULEUR_ECHEC POSITION "\t" TEST_str(x)  " --> faux \n" \
		COULEUR_NORMALE , __LINE__ , __func__ )

#define ASSERT(x)   do { \
    if ( ! ( x ) ) {							\
      fprintf ( stderr , COULEUR_ECHEC POSITION "\t" TEST_str(x)  " --> faux \n" \
		COULEUR_NORMALE , __LINE__ , __func__ ) ;		\
      exit ( EXIT_FAILURE ) ;						\
    } } while ( 0 )

#define debug(...) fprintf ( stderr ,COULEUR_INFO __VA_ARGS__ )
#define test(x) TEST_RES(x)

#endif

#endif