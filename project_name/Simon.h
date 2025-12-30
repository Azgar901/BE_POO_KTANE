/* faire une boucle for ou je fais clignoté une led à chaque fois fonction
PS: Il n'y a que 3 essaies possibles
1) une procedure de configuation des pins (les 5 leds et 4 boutons poussoir)
2) une procedure qui allume une led à led d'un bouton poussoir: prend 2 pin en argument ? (1 pour la led et l'autre le bouton)
3) procedure qui regarde quelle couleur a été appuyé et en fonction, allume le voyant vert ou déclenche la bombe au bout de 3 essaies
PS: tant qu'il y a une erreur, on reste sur le voyant actuel 
*/
#ifndef Simon_h
#define Simon_h

#include <Arduino.h>


class Simon {

  public: 
    Simon(); 
    void config_pin();
    void Led_ON(); // allume la LED si on appuie sur le bouton poussoir
    void to_flash(int flash); // pour faire clignoter une LED
    void Is_OK(); // verifie qu'on a bien suivi la bonne séquence
    void Error1(int err);
    void Error2(int err);
    void Test_error(int err);

    ~Simon();
  };

#endif