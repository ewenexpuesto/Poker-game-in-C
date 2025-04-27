import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Charger les données
empirique = pd.read_csv('C11/P_approx_2.csv')
theorique = pd.read_csv('C11/loi_theorique.csv')

# Créer le graphique
plt.figure(figsize=(12, 6))

# Définir les positions et largeur des barres
x = np.arange(len(empirique['(C2_1.C2_2)']))  # Positions des groupes de barres
width = 0.35  # Largeur des barres

# Tracer les barres empiriques et théoriques côte à côte
plt.bar(x - width/2, empirique['P_approx_2'], width, label='Empirique', color='blue')
plt.bar(x + width/2, theorique['P(C2_1.C2_2)'], width, label='Théorique', color='red')

# Ajouter les étiquettes et titres
plt.xlabel('(C2_1,C2_2)')
plt.ylabel('Probabilité')
plt.title('Histogramme lois empirique et théorique')
plt.xticks(x, empirique['(C2_1.C2_2)'])  # Étiquettes de l'axe x
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)

# Ajuster l'espacement
plt.tight_layout()
plt.show()