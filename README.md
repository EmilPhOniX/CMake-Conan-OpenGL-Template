# Modèle CMake-Conan-OpenGL

Un projet modèle pour configurer des applications C++ avec le système de construction CMake, le gestionnaire de paquets Conan, et les graphismes OpenGL utilisant les bibliothèques GLFW et GLEW.

## Description

Ce projet fournit une structure de base et une configuration pour développer des applications OpenGL en C++. Il démontre comment :

- Utiliser CMake pour la configuration et la construction du projet
- Gérer les dépendances avec Conan
- Configurer OpenGL avec GLFW pour la gestion des fenêtres et GLEW pour le chargement des extensions
- Créer une application OpenGL 3.3 core profile simple avec des shaders

Le code d'exemple crée une fenêtre et rend un triangle coloré en utilisant des techniques OpenGL modernes.

## Prérequis

- **CMake** : Version 3.15 ou supérieure
- **Conan** : Gestionnaire de paquets pour les dépendances C++ (`pip install conan`)
- **Compilateur C++** : Supportant le standard C++17 (par exemple, GCC, Clang, MSVC)
- **OpenGL** : Bibliothèques de développement (généralement incluses avec les pilotes graphiques)

### Spécifique à macOS
- Outils de ligne de commande Xcode : `xcode-select --install`
- Assurez-vous que libc++ est utilisé (configuré dans CMakeLists.txt)

## Configuration

1. **Installer Conan** (si pas déjà installé) :
   ```bash
   pip install conan
   ```

2. **Configurer Conan** (optionnel, mais recommandé) :
   ```bash
   conan profile detect
   ```

## Construction

### Utilisation des tâches VS Code (Recommandé)

Ce projet inclut des tâches VS Code préconfigurées pour une construction facile. Utilisez la palette de commandes (`Ctrl+Shift+P` / `Cmd+Shift+P`) et sélectionnez "Tasks: Run Task", puis choisissez :

- **setup-and-build** : Configuration complète et construction en mode Debug
- **setup-and-build-release** : Configuration complète et construction en mode Release
- **Full rebuild (Debug)** : Nettoyage et reconstruction en mode Debug
- **Full rebuild (Release)** : Nettoyage et reconstruction en mode Release

### Construction manuelle

1. **Créer le répertoire de construction** :
   ```bash
   mkdir build
   cd build
   ```

2. **Installer les dépendances avec Conan** :
   ```bash
   conan install .. --build=missing
   ```

3. **Configurer avec CMake** :
   ```bash
   cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
   ```

4. **Construire le projet** :
   ```bash
   cmake --build .
   ```

Pour une construction en Release, ajoutez `-DCMAKE_BUILD_TYPE=Release` à la commande cmake.

## Exécution

Après une construction réussie, exécutez l'exécutable :

```bash
./ProjectName  # Sur Linux/macOS
# ou
ProjectName.exe  # Sur Windows
```

L'application ouvrira une fenêtre affichant un triangle coloré. Appuyez sur ÉCHAP pour fermer.

## Structure du projet

```
├── CMakeLists.txt          # Configuration CMake principale
├── CMakePresets.json       # Préréglages CMake pour différentes configurations
├── CMakeUserPresets.json   # Préréglages CMake spécifiques à l'utilisateur
├── conanfile.txt           # Spécification des dépendances Conan
├── src/
│   └── main.cpp           # Code de l'application principale
├── build/                 # Répertoire de construction (généré)
└── README.md              # Ce fichier
```

## Dépendances

- **GLFW** (>= 3.3.2) : Gestion des fenêtres et des entrées multiplateforme
- **GLEW** (>= 2.1.0) : Bibliothèque de chargement des extensions OpenGL
- **OpenGL** : API graphique (fournie par le système)

## Configuration

### Options CMake

- `CMAKE_CXX_STANDARD` : Défini à 17
- `CMAKE_BUILD_TYPE` : Debug (par défaut) ou Release
- `CMAKE_TOOLCHAIN_FILE` : Pointe vers le fichier toolchain de Conan

### Configuration Conan

Les dépendances sont spécifiées dans `conanfile.txt`. Le projet utilise :
- Générateur CMakeDeps pour l'intégration CMake moderne
- CMakeToolchain pour la configuration toolchain multiplateforme

## Personnalisation

1. **Changer le nom du projet** : Éditez `project(ProjectName)` dans `CMakeLists.txt`
2. **Ajouter des fichiers source** : Mettez à jour la variable `SOURCES` dans `CMakeLists.txt`
3. **Ajouter des dépendances** : Modifiez `conanfile.txt` et `CMakeLists.txt`
4. **Modifier le code OpenGL** : Éditez `src/main.cpp`

## Dépannage

### Problèmes courants

- **Conan non trouvé** : Assurez-vous que Conan est installé et dans le PATH
- **OpenGL non trouvé** : Installez les pilotes graphiques ou les paquets de développement
- **Problèmes de liaison macOS** : CMakeLists.txt force l'utilisation de libc++
- **Échecs de construction** : Essayez de nettoyer le répertoire de construction et de reconstruire

### Spécifique à macOS

Si vous rencontrez des problèmes avec OpenGL sur macOS, assurez-vous d'avoir la dernière version de Xcode et des outils de ligne de commande installés.

## Contribution

N'hésitez pas à soumettre des problèmes et des demandes de tirage pour améliorer ce modèle.

## Licence

Ce projet est fourni tel quel à des fins éducatives et de développement.