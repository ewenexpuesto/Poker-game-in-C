import pandas as pd
import matplotlib.pyplot as plt

# On charge les données dans df1 et df2
df1 = pd.read_csv('data1.csv')
df2 = pd.read_csv('data2.csv')

bins = [f"({i},{j})" for i in range(1,4) for j in range(i,4)]

#On trace l'histogramme
plt.figure(figsize=(10,6))
plt.bar(bins, df1['proportion'], width=0.4, label='Empirique', alpha=0.7) #empirirque
plt.bar(bins, df2['resultat'], width=0.4, label='Théorique', alpha=0.7) #theorique

#titre de l'histogramme
plt.title('Loi conditionnelle de (C²₁,C²₂) sachant (C¹₁,C¹₂)=(1,2)')
plt.xlabel('Valeurs (i,j)')
plt.ylabel('Probabilité')
plt.legend()
plt.grid(True, axis='y', linestyle='--', alpha=0.7)
plt.tight_layout()
plt.show()
