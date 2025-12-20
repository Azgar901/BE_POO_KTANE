# BE_POO_Template
# Premier Module


Voici le module "Thread":

Il s'agit de la première configuration (de 5 fils) dont le vrai fil à couper est le premier (fil vert, bleu ou un autre peu importe) s'il y a deux fils jaunes et un seul fil rouge.
Pour cela, j'ai fais une classe "Thread" qui aura principalement une fonction permettant de configurer en mode Input les 5 pins (31, 32, 33, 34 et 35) que l'on utilisera pour les fils et une fonction qui permettra de détecter, en fonction de l'état des ports d'entrée de la carte (si une des pins n'est plus alimentée) permettra de savoir si un fil est déconnecté de la pin.
Si le fil coupé n'est pas la pin 31, la bombe se déclenche.

