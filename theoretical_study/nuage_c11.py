import pandas as pd
import matplotlib.pyplot as plt

# Charger les fichiers CSV
nuage = pd.read_csv('C11/nuage_C10.csv')
nuage_alter = pd.read_csv('C11/nuage_alter_C10.csv')

n1 = nuage['n']
P_approx_2_values = nuage['P_approx_2(2.3.n)']

n2 = nuage_alter['n']
P_approx_2_alter_values = nuage_alter['P_approx_2_alter(2.3.n)']  

# Valeur constante pour la droite horizontale
P_2_3 = 4/15

# Création du graphique
plt.figure(figsize=(10,6))

# Nuage de points 1
plt.scatter(n1, P_approx_2_values, color='blue', label='P_approx_2(2,3,n)', s=1)

# Nuage de points 2
plt.scatter(n2, P_approx_2_alter_values, color='red', label='P_approx_2_alter(2,3,n)', s=1)

# Droite horizontale
plt.axhline(y=P_2_3, color='green', linestyle='--', label=f'Droite horizontale P(2,3)')

# Paramètres du graphique
plt.xlabel('n')
plt.ylabel('P_approx')
plt.title('Nuage de points et droite horizontale')
plt.legend()

# Affichage du graphique
plt.show()
