import pandas as pd
import matplotlib.pyplot as plt

#On charge les données dans df3
df3 = pd.read_csv("data3.csv")
df3.columns = df3.columns.str.strip() #On nettoie le nom des colonnes 
# On charge les valeurs dans df4
df4 = pd.read_csv("data4.csv")
valeur_theorique = df4.iloc[0, 0]  #On extrait la valeur de df4

#Nuage de points :
plt.figure(figsize=(10, 6))
plt.scatter(df3['N'], df3['proba'], color='green', s=10, label='P_approx_2_1_main(2,3,1,2,n)')

# Tracer la droite horizontale
plt.axhline(y=valeur_theorique, color='red', linestyle='--', label=f"y = P((2,3)|(1,2)) ≈ {valeur_theorique:.4f}")

# Ajout des titres et légende
plt.xlabel("N")
plt.ylabel("Probabilité")
plt.title("Convergence de P_approx_2_1_main(2,3,1,2,n)")
plt.legend()
plt.grid(True)

# Affichage
plt.tight_layout()
plt.show()
