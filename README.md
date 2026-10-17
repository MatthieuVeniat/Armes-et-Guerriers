# Jeu de Rôle et Simulation de Combat Tactique (C++)

Projet de simulation de combat tactique en tour par tour développé en C++. Ce projet met en œuvre une architecture orientée objet avancée pour gérer des affrontements complexes au sein d'un donjon entre un groupe de héros et divers adversaires.

---

##  Présentation et Objectifs

L'objectif de ce projet est de concevoir un moteur de jeu textuel modulaire et extensible, garantissant une gestion rigoureuse de la mémoire et une séparation claire des responsabilités entre les entités du jeu.

### Fonctionnalités principales :
* **Système de combat en groupe et duels** : Gestion des affrontements au tour par tour avec stratégies d'attaque, de soutien et de ciblage contextuel.
* **Gestion d'armée polymorphe** : Prise en charge d'un bataillon composé de différentes classes de personnages fonctionnant de manière hétérogène.
* **Gestion du butin et équipement** : Transfert dynamique d'armes depuis les ennemis vaincus vers les membres du groupe pour faire évoluer leurs statistiques.
* **Progression et réinitialisation** : Restauration des ressources entre les combats et paliers de difficulté adaptatifs (Gobelins, Mage du pont, Gardien du donjon).

---

##  Architecture et Concepts POO Appliqués

### 1. Gestion de la Mémoire et Structure de Base
* **Gestion dynamique de la mémoire** : Utilisation stricte de pointeurs et d'allocations dynamiques (`new` / `delete`), garantissant l'absence de fuites mémoire grâce à l'implémentation de destructeurs virtuels.
* **Classe `ChaineCar`** : Implémentation sur-mesure d'une classe de gestion de chaînes de caractères (Surcharge d'opérateurs `+`, `=`, `==`, `<<`, constructeur de copie, etc.) pour s'affranchir des contraintes des chaînes natives.

### 2. Spécialisation des Armes
La classe de base `Arme` est déclinée en plusieurs typologies offrant des calculs de dégâts spécifiques :
* **ArmeCorpsACorps** : Bonus fixe additionnel au combat rapproché.
* **ArmeDistance** : Modificateur de dégâts à portée.
* **ArmeMagique** : Amplification des dégâts basée sur la puissance magique.

### 3. Spécialisation des Personnages & Compétences
Chaque classe de héros dérive de la classe `Personnage` et possède son propre système de ressources et de prises de décision lors des tours de jeu :
* **Guerrier** : Accumule de la *Rage* en recevant des dégâts pour déclencher de puissantes frappes physiques (`Frappe de rage`).
* **Mage** : Consomme du *Mana* pour lancer des sorts de zone ou à fort impact (`Boule de feu`).
* **Soigneur** : Évalue la santé globale de ses alliés pour choisir entre le soin prioritaire du membre le plus affaibli ou le lancement d'attaques sacrées.

### 4. Collection Polymorphe (`Armee`)
La classe `Armee` gère un tableau dynamique de pointeurs `Personnage*`. Grâce au **polymorphisme et à la résolution dynamique des liaisons**, l'armée peut ordonner des actions collectives sans connaître le type précis de chaque membre à la compilation :
* Détermination automatique du premier membre vivant.
* Sélection de la cible idéale pour les soins selon le ratio de points de vie.
* Exécution des actions spécialisées propres à chaque classe via la méthode virtuelle `Agir()`.

---

##  Structure du Projet

```text
├── Armee/               # Gestion du groupe d'aventuriers et des collections polymorphes
├── Armes/               # Gestion des armes (Base, Corps à corps, Distance, Magique)
├── ChaineCar/           # Gestion personnalisée des chaînes de caractères
├── CombatGroupe/        # Moteur de résolution des combats de groupe
├── Duel/                # Moteur de gestion des affrontements 1v1
├── Personnages/         # Classes personnages (Guerrier, Mage, Soigneur)
├── Tests/               # Jeux de tests unitaires et d'intégration par module
└── src/                 # Point d'entrée principal (main.cpp - Scénario du donjon)
