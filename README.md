# SAE1.01-LecteurDiaporama


## Type nécessaires déclarés

##### Diaporamas
Description : Alias pour un vecteur de Diaporama.
Utilisation : Permet de définir un type Diaporamas qui peut être utilisé pour stocker une collection de diaporamas.
Déclaration : typedef vector<Diaporama> Diaporamas;
Exemple d'utilisation : Diaporamas mesDiaporamas;

##### ImagesDuDiaporama
Description : Alias pour un vecteur de imageDansDiaporama.
Utilisation : Permet de définir un type ImagesDuDiaporama qui peut être utilisé pour stocker une collection d'images dans un diaporama.
Déclaration : typedef vector<imageDansDiaporama> ImagesDuDiaporama;
Exemple d'utilisation : ImagesDuDiaporama imagesDiaporama;

##### Images
Description : Alias pour un vecteur d'Image.
Utilisation : Permet de définir un type Images qui peut être utilisé pour stocker une collection d'images.
Déclaration : typedef vector<Image> Images;
Exemple d'utilisation : Images mesImages;


### Classe Lecteur

#### Attributs
Diaporamas _allDiapos : Un vecteur contenant tous les diaporamas gérés par le lecteur.1
unsigned int _numDiapoCourant : Le numéro du diapo courant.
Images _allImages : Un vecteur contenant toutes les images gérées par le lecteur.

#### Méthodes publiques
##### Constructeurs
Lecteur() : Constructeur par défaut de la classe Lecteur.
Lecteur(Diaporamas diapos, unsigned int numDiapoCourant) : Constructeur prenant en paramètres un vecteur de diaporamas et le numéro du diaporama courant.
##### Getters
Diaporamas getAllDiapos() const : Retourne une copie du vecteur de tous les diaporamas.
Diaporama& getDiapoCourant() : Retourne une référence vers le diaporama courant.
unsigned int getNumDiapoCourant() const : Retourne le numéro du diaporama courant.
unsigned int getNombreDiapos() const : Retourne le nombre total de diaporamas.
##### Setters
void setAllDiapos(const Diaporamas& vecteurDiapos) : Définit le vecteur de tous les diaporamas.
void setNumDiapoCourant(unsigned int numDiapoCourant) : Définit le numéro du diaporama courant.
Autres méthodes
void afficherDiapoCourant() : Affiche les détails du diaporama courant.
void declencherAction(char pChoixAction) : Déclenche une action spécifique sur le lecteur en fonction du choix de l'utilisateur.
void saisieVerifChoixActionSurImageCourante(char& pChoixAction) : Saisie et vérifie le choix de l'utilisateur concernant les actions sur l'image courante.
unsigned int saisieVerifChoixDiaporama() : Saisie et vérifie le choix de l'utilisateur pour changer de diaporama.
void charger(Images& images) : Charge un ensemble d'images.
void chargerDiapos(Images images) : Charge les diaporamas à partir d'un ensemble d'images.





