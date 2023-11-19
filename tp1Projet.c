#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// les fonctions de tri

void bubbleSort(int arr[], int n)
{
    int i, j, swapped, temp;

    for (i = 0; i <= n; i++)
    {
        // Utilisé pour optimiser le tri
        swapped = 1;
        for (j = 1; j <= n - i - 1; j++)
        {
            // Comparaison et échange d'éléments si l'élément courant est plus grand que le suivant
            if (arr[j] > arr[j + 1])
            {

                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Pour Indiquer qu'un échange a eu lieu
            }
        }
        // Si aucun échange n'a eu lieu dans une itération, le tableau est déjà trié
        if (swapped == 0)
        {
            break;
        }
    }
}

//**** Tri Insertion******

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i <= n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Déplace les éléments du tableau arr[0..i-1] qui sont plus grands que key
        // vers une position à l'avant de leur position courante
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
//**** tri fusion ****
void fusionner(int tab[], int deb1, int fin1, int fin2) {
    int *table1;
    int deb2 = fin1 + 1;
    int compt1 = deb1;
    int compt2 = deb2;
    int i;
    int A = fin1 - deb1 + 1;
    table1 = (int *)malloc(A * sizeof(int));

    for (i = deb1; i <= fin1; i++) {
        table1[i - deb1] = tab[i];
    }

    for (i = deb1; i <= fin2; i++) {
        if (compt1 == deb2) {
            break;
        } else if (compt2 == (fin2 + 1)) {
            tab[i] = table1[compt1 - deb1];
            compt1++;
        } else if (table1[compt1 - deb1] < tab[compt2]) {
            tab[i] = table1[compt1 - deb1];
            compt1++;
        } else {
            tab[i] = tab[compt2];
            compt2++;
        }
    }
    free(table1);
}

void fusionsort_1(int tableau[], int deb, int fin) {
    if (deb != fin) {
        int milieu = (fin + deb) / 2;
        fusionsort_1(tableau, deb, milieu);
        fusionsort_1(tableau, milieu + 1, fin);
        fusionner(tableau, deb, milieu, fin);
    }
}

double FusionSort(int tab[], int N) {
    double temps_exe;
    clock_t start = clock();
    if (N > 0) {
        fusionsort_1(tab, 0, N - 1);
    }
    clock_t end = clock();
    temps_exe = (double)(end - start) / CLOCKS_PER_SEC;

    return temps_exe;
}
//****** quick sort *******
// Fonction pour échanger deux éléments dans un tableau
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction pour placer l'élément pivot à la bonne position dans le tableau
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choix du pivot comme dernier élément
    int i = (low - 1);     // Index du plus petit élément
    int j;
    for (j = low; j <= high - 1; j++)
    {
        // Si l'élément actuel est plus petit ou égal au pivot
        if (arr[j] <= pivot)
        {
            i++; // Incrémente l'index du plus petit élément
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Fonction principale pour trier un tableau en utilisant le tri rapide
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Trouve l'élément pivot tel que l'élément pivot est maintenant à la bonne position
        int pi = partition(arr, low, high);

        // Trie les éléments avant et après la position de pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fonction pour réorganiser un tas (max-heap) avec la racine à l'index i
void maxHeapify(int arr[], int n, int i)
{
    int largest = i;       // Initialise la racine comme le plus grand élément
    int left = 2 * i + 1;  // Indice du fils gauche
    int right = 2 * i + 2; // Indice du fils droit

    // Si le fils gauche est plus grand que la racine
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Si le fils droit est plus grand que la racine
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Si le plus grand n'est pas la racine
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        // Récursivement réorganiser le sous-arbre affecté
        maxHeapify(arr, n, largest);
    }
}

// Fonction pour trier un tableau en utilisant le tri par tas
void heapSort(int arr[], int n)
{
    // Construit un tas (max-heap)
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extrait les éléments un par un du tas
    for (i = n - 1; i > 0; i--)
    {
        // Déplace la racine actuelle à la fin
        swap(&arr[0], &arr[i]);

        // Appelez maxHeapify() sur le tas réduit
        maxHeapify(arr, i, 0);
    }
}

// Remplissage et Affichage
/*
void printArray(int arr[], int n)
{
    int i;
    printf("{");
    for (i = 1; i <= n; i++)
    {
        printf("%d", arr[i]);
        if (i < n)
        {
            printf(",");
        }
    }
    printf("} \n");
}*/

int *remplissageRandom(int n)
{
    int *arr = malloc(sizeof(int)*n);
    int i;
    for (i = 1; i <= n; i++)
    {
        arr[i] = rand() % 10;
    }
    return arr;
}
int *RemplissageParIndex( int n){
    int *arr = malloc(sizeof(int)*n);
    for(int i=1; i<=n; i++){
        arr[i]=i;
    }
    return arr;
}



int *RemplissageParIndexInverse( int n){
    int *arr = malloc(sizeof(int)*n);
    for(int i=0; i<=n; i++){
        arr[i]=n+1-i;
    }
    return arr;
}

//*********************************
int main()
{
    //int tableau[] = {1};
    int n;
    printf("Donnez une taille a votre tableau: \n");
    scanf("%d", &n);

    int *tableau = remplissageRandom(n);
    int *tableau2 = RemplissageParIndex(n);
    int *tableau3 = RemplissageParIndexInverse(n);

    int t1, t2;
    double tempsExec;
    int choix;
    printf("Choisisez votre tri [1,2,3,4,5] : \n");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        printf("Vous avez choisi le tri par insetion.\n");
        printf("Tableau avec valeurs random");
        t1 = clock();
        insertionSort(tableau, n);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        printf("Tableau avec valeurs de 1 à n");
        t1 = clock();
        insertionSort(tableau2, n);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        printf("Tableau avec valeurs de n à 1");
        t1 = clock();
        insertionSort(tableau3, n);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);

        break;
    case 2:
        printf("Vous avez choisi le tri à bulles.\n");
        printf("Tableau avec valeurs random");
        t1 = clock();
        bubbleSort(tableau, n);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        printf("Tableau avec valeurs de 1 à n");
        t1 = clock();
        bubbleSort(tableau2, n);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        printf("Tableau avec valeurs de n à 1");
        t1 = clock();
        bubbleSort(tableau3, n);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        break;
    case 3:
        printf("Vous avez choisi le tri Fusion.\n");
        tempsExec = FusionSort(tableau, n);
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        printf("Tableau avec valeurs de 1 à n");
        tempsExec = FusionSort(tableau2, n);
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        printf("Tableau avec valeurs de n à 1");
        tempsExec = FusionSort(tableau3, n);
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        break;
    case 4:
        printf("Vous avez choisi le tri rapide (quick sort).\n");
        printf("Donnez le minimum et le maximum du subarray.\n");
        int min, max;
        scanf("%d, %d",&min, &max);
        printf("Tableau avec valeurs random");
        t1 = clock();
        quickSort(tableau, min, max);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        printf("Tableau avec valeurs de 1 à n");
        t1 = clock();
        quickSort(tableau2, min, max);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        printf("Tableau avec valeurs de n à 1");
        t1 = clock();
        quickSort(tableau3, min, max);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        break;
    case 5:
        printf("Vous avez choisi le tri par tas (heap sort).\n");
        printf("Tableau avec valeurs random");
        t1 = clock();
        heapSort(tableau, n);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        printf("Tableau avec valeurs de 1 à n");
        t1 = clock();
        heapSort(tableau2, n);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        printf("Tableau avec valeurs de n à 1");
        t1 = clock();
        heapSort(tableau3, n);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        break;
    default:
        printf("Il existe que 5 tris dans ce programme!!\n");
    }


    return 0;
}
