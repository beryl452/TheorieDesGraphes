# TheorieDesGraphes

# Sommaire:

        1.)    Connexion entre deux sommets;
        2.)    Connexité et  Composantes connexe:
        2.)    Listes de toutes les Chaines entre deux sommets du graphe;
 
# Compilation :
 gcc main.c -o main
 
 
# Exécution :
 ./main
  
 
# Explication:
1.)    Connexion entre deux sommets:
Il s'agit de dire si deux (02) sommets sont connectés ou pas et s'ils le sont de donner  ~.~  lenombre d'arc qui les sépares.
Pour se faire, dans un premier temps on vérifie si nous avons 01 à l'interception 
(colonne  et ligne) des deux(02) sommets dans la matrice d'adjacence précedement entrer par 
l'utilisateur, si c'est le cas, les deux (02) sont connectés et sont adjacent puisqu'ils sont 
reliés par un seul arc.
    Si, à l'interception, on trouve au contraire 00, nous calculons le carré de la matrice 
puis refaisons le controle précédent.Ici les deux sommets dans le cas où elles sont connectés
sont réliés par deux(02) arcs.
    Si à cette étape, elles ne sont pas toujours connectés, on refait l'opération préedente
jusqu'à l'ordre du graphe. Le nombre d'arc qui sépare les deux (02) sommets est déterminé
par l' exposant à laquelle les deux sommets seront connectés. 
  
    Exemple :
 
    Input: graphe1.txt
        Premier chiffre: L'ordre du graphe.
        Le reste des chiffres: La matrice d'adjacence;

    Output:
       ______________________________________________________________________________
      |                Votre matrice d'adjacence est la suivante:                    |
      |              0  1  1  0  0  0  0                                             |   
      |              1  0  0  0  0  0  0                                             |   
      |              1  0  0  1  1  1  0                                             |   
      |              0  0  1  0  0  0  1                                             |   
      |              0  0  1  0  0  0  0                                             |   
      |              0  0  1  0  0  0  0                                             |   
      |              0  0  0  1  0  0  0                                             |   
      |                                                                              |       
      |              _-_-_-_-_---------_-_-_-_-_-_                                   |       
      |              _-_-_-_-    MENU    -_-_-_-_                                    |       
      |              _-_-_-_-_---------_-_-_-_-_-_                                   |       
      |                                                                              |           
      |              1: Connexion de deux sommets                                    |   
      |              2: Composantes connexes                                         |  
      |              3: Chaine                                                       |  
      |              1                                                               |
      |                                                                              |
      |              Entrer le sommet 1                                              |   
      |              1                                                               |           
      |              Entrer le sommet 2                                              |           
      |              3                                                               |   
      |              Les sommets, 1 et 3 sont connectes et separes par 3 arc(s)      |       
      |                                                                              |  
       ______________________________________________________________________________
 
 
2.)     Composantes connexe:
    Il s'agit de dire s'il existe une chaine entre n'importe quelle paire de sommet du graphe 
ou pas et de préciser le nombre de composantes connexes que nous avons.
Dans un premier temps, nous avons mis tout les sommets comme étant "non visité" (Mettre 
0 pour non visité) au départ,grace à un tableau dont chaque index correspond à un sommet du 
 graphe.
Dans un second temps, on parcourt la table des "visites", en commençant par le premier 
élément, qu'on met pour le coup à visité(Mettre 1 pour dire visité). Ensuite on vérifie si, cesommet est connecté à ses voisins puis si c'est le cas, on met chaque voisin à qui il est 
connecté à "visité". 
Aussi, si en parcourant, le tableau on a un sommet à "non visité", donc qui n'est pas
connecté aux sommets qui le précède alors on incrémente le nombre de composant connexe de un(01) 
Enfin, si le nombre de composant connexe est égal à un (01), alors on conclut que le 
graphe est connexe, et dans la cas contraire, il ne l'est pas et à n composant connexe. 

        Exemple :
        Input: graphe1.txt
  
        Output:
       _________________________________________________________________________
      |           Votre matrice d'adjacence est la suivante:                    |
      |         0  1  1  0  0  0  0                                             |
      |         1  0  0  0  0  0  0                                             |
      |         1  0  0  1  1  1  0                                             |
      |         0  0  1  0  0  0  1                                             |
      |         0  0  1  0  0  0  0                                             |
      |         0  0  1  0  0  0  0                                             |
      |         0  0  0  1  0  0  0                                             |
      |                                                                         |
      |         _-_-_-_-_---------_-_-_-_-_-_                                   |
      |         _-_-_-_-    MENU    -_-_-_-_                                    |
      |         _-_-_-_-_---------_-_-_-_-_-_                                   |
      |                                                                         |
      |         1: Connexion de deux sommets                                    |
      |         2: Composantes connexes                                         |
      |         3: Chaine                                                       |
      |         2                                                               |
      |         Votre graphe est CONNEXE et donc possede 01 composante connexe  |
      ___________________________________________________________________________      
    
3.)     Chaine:
Il s'agit de trouver tout les chemins (chaine), possible entre
un sommet source(PreSom) 's' et un sommet de destination 'd'(SecoSom). 
Pour se faire, nous utliserons la technique du parcours en profondeur ou DFS (Depth 
First Traversal) en Anglais
      
On commence donc notre parcours en profondeur (DFS) à partir de la source.
Et comme dans les consignes précédentes, on met à visité tout les sommets parcouru
afin que la traversée ne se déroule pas dans un cycle. 
      
On stocke aussi les sommets visités dans un tableau  dites 'chemin []'.
Si le sommet de destination (SecoSommet) est atteint, on affiche le contenu de chemin [].   
    Notons qu'avant toute chose qu'on vérifie si les deux (02) sommets sont connectés, afin  
    de ne pas faire le parcours en vin.             
    Nos sources pour cette partie du TP sont les suivantes :
   -) Parcours en PROFONDEUR (DFS) d'un graphe (version détaillée) [Vidéo de la chaine 
 ['À la découverte des graphes']
    -) Print all paths from a given source to a destination[Un article sur le site 
 geeksforgeeks]

            Exemple :
                Input: graphe2.txt
                Output:
               _________________________________________________________________________
                |        Votre matrice d'adjacence est la suivante:                     |
                |    0  1  0  1                                                         |            
                |    1  0  1  0                                                         |    
                |    0  1  0  1                                                         |    
                |    1  0  1  0                                                         |    
                |                                                                       |    
                |    _-_-_-_-_---------_-_-_-_-_-_                                      |            
                |    _-_-_-_-    MENU    -_-_-_-_                                       |    
                |    _-_-_-_-_---------_-_-_-_-_-_                                      |    
                |                                                                       |    
                |    1: Connexion de deux sommets                                       |        
                |    2: Composantes connexes                                            |    
                |    3: Chaine                                                          |            
                |    3                                                                  |            
                |                                                                       |    
                |    Entrer le premier sommet de votre chaine                           |        
                |    1                                                                  |            
                |    Entrer le second sommet de votre chaine                            |        
                |    3                                                                  |        
                |    Les chaines qui relient vos deux sommets sont:                     |        
                |    1 0 3                                                              |            
                |    1 2 3                                                              |    
               _|_______________________________________________________________________|_  