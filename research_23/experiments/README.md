#Mes expériences 
Mon expérience 1 change le nombre de tours entre 3 et 20 tours à chaque partie avec un nombre de cartes constant à 80 et mon expérience 2 ne change pas le nombre de tours =3 d'une partie mais change le nombre de cartes à 12,16,20,24,28 cartes.

#Les deux expériences se trouvent dans le fichier exp1.c, afin de réaliser l'expérience il faut mettre l'expérience 2 en commentaire et vice-versa pour réaliser l'expérience 2

##Compilation expérience 1 :
Il faut tout d'abord aller dans le dossier include et vérifier que le nombre de cartes est à 40 et le mettre à 40 si cela n'est pas le cas 
Pour compiler le programme, utilisez make puis ./exec 
Après avoir compiler le code en C il faut :
- installer python3
-créer un environnement virtuel avec la commande python3 -m venv .ven
-l'activer avec source .ven/bin/activate
-installer pandas avec pip install pandas et matplotlib avec pip install matplotlib
-run le code python avec le venv avec python research_23/experiments/resultexp1.py pour l'expérience 1 et python research_23/experiments/resultexp2.py pour la deuxième expérience

##Compilation expérience 2 : 
-aller dans board.h puis mettre NB_CARDS = 12
Pour compiler le programme, utilisez make puis ./exec 
Après avoir compiler le code en C il faut :
- installer python3
-créer un environnement virtuel avec la commande python3 -m venv .ven
-l'activer avec source .venv/bin/activate
-installer pandas avec pip install pandas et matplotlib avec pip install matplotlib
-run le code python avec le venv avec python research_23/experiments/resultexp1.py pour l'expérience 1 et python research_23/experiments/resultexp2.py
-Puis recommencer la manipulation avec NB_CARDS = 16 sans re installer python3 ainsi que les bibliothèques et sans créer de nouvel environnement 