
#Nuage de points :
plt.figure(figsize=(10, 6))
plt.scatter(df3['N'], df3['proba'], color='pink', s=10, label='P_approx_2_1_main(2,3,1,2,n)')

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
