# 📹 C++ Real-Time Motion Detector (OpenCV)

Un projet C++ complet de détection de mouvement en temps réel exploitant la bibliothèque **OpenCV** et la méthode de la soustraction d'images (*Frame Differencing*). Ce dépôt contient tout le nécessaire pour comprendre, compiler, exécuter et contribuer au projet.

---

## 📌 Sommaire

- [Présentation & Fonctionnalités](#-présentation--fonctionnalités)
- [Arborescence du Projet](#-arborescence-du-projet)
- [Code Source Complet (`motion_detector.cpp`)](#-code-source-complet-motion_detectorcpp)
- [Fichier `Makefile`](#-fichier-makefile)
- [Prérequis & Dépendances](#-prérequis--dépendances)
- [Installation, Compilation et Exécution](#-installation-compilation-et-exécution)
- [Option Alternative : Compilation via CMake](#-option-alternative--compilation-via-cmake)
- [Fonctionnement Étape par Étape (Algorithme)](#-fonctionnement-étape-par-étape-algorithme)
- [Résolution des Problèmes Courants (Dépannage)](#-résolution-des-problèmes-courants-dépannage)
- [Licence & Auteur](#-licence--auteur)

---

## 🌟 Présentation & Fonctionnalités

- **Flux Vidéo en Temps Réel** : Capture automatique de la webcam avec `cv::VideoCapture`.
- **Traitement du Bruit** : Réduction du bruit numérique de la caméra via un lissage gaussien (`cv::GaussianBlur`).
- **Soustraction d'Images** : Analyse différentielle absolue entre deux frames successives ($\vert{}Frame_t - Frame_{t+1}\vert{}$).
- **Seuillage & Morphologie** : Binarisation dynamique (`cv::threshold`) et dilatation (`cv::dilate`) pour isoler les mouvements.
- **Encadrement Automatique** : Détection des contours (`cv::findContours`) et dessin de rectangles englobants verts (`cv::boundingRect`).
- **Indicateur d'Alerte** : Texte dynamique **"MOUVEMENT DETECTE !"** incrusté sur la vidéo.

---

## 📂 Arborescence du Projet

```text
motion-detector/
├── motion_detector.cpp   # Fichier source C++ principal
├── Makefile              # Fichier de compilation rapide
├── CMakeLists.txt        # Script de configuration CMake (optionnel)
└── README.md             # Documentation globale

# 📹 C++ Real-Time Motion Detector (OpenCV)

![Version](https://img.shields.io/badge/Version-1.0-brightgreen)
![Language](https://img.shields.io/badge/C%2B%2B-14-blue)
![OpenCV](https://img.shields.io/badge/OpenCV-4.x-red)
![License](https://img.shields.io/badge/License-MIT-yellow)

Un projet C++ complet de détection de mouvement en temps réel exploitant la bibliothèque **OpenCV** et la méthode de la soustraction d'images (*Frame Differencing*).

---

## Installation :

* `sudo apt update`
* `sudo apt install -y g++ git cmake make pkg-config libopencv-dev`
* `git clone https://github.com/evhane07/motion-detector.git`
* `cd motion-detector`

> **BUILD** : `make`

> **Run** : `./motion_detector`

## Single Command :

```bash
sudo apt update ; sudo apt install -y g++ git cmake make pkg-config libopencv-dev ; git clone [https://github.com/evhane07/motion-detector.git](https://github.com/evhane07/motion-detector.git) ; cd motion-detector ; make ; ./motion_detector