#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// les fonctions de tri

void bubbleSort(int arr[], int n)
{
    int temp;
    int swapped;
    int i, j;
    for (i = 0; i <= n; i++)
    {
        swapped = 1; // Utilisé pour optimiser le tri
        for (j = 1; j <= n - i - 1; j++)
        {
            // Comparaison et échange d'éléments si l'élément courant est plus grand que le suivant
            if (arr[j] > arr[j + 1])
            {
                // Échange des éléments
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Indique qu'un échange a eu lieu
            }
        }
        // Si aucun échange n'a eu lieu dans une itération, le tableau est déjà trié
        if (swapped == 0)
        {
            break;
        }
    }
}

//**** insertion Sort ******
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
void triFusion(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crée des tableaux temporaires
    int L[n1], R[n2];

    // Copie les données dans les tableaux temporaires L[] et R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Fusionne les tableaux temporaires de retour dans arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copie les éléments restants de L[], s'il y en a
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copie les éléments restants de R[], s'il y en a
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
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
}

void remplissageRandom(int arr[], int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        arr[i] = rand() % 10;
    }
}
int RemplissageParIndex(int arr[], int n){
    //int *arr = malloc(sizeof(int)*n);
    for(int i=1; i<=n; i++){
        arr[i]=i;
    }
    
}

int RemplissageParIndexInverse(int arr[], int n){
    //int *arr = malloc(sizeof(int)*n);
    for(int i=0; i<=n; i++){
        arr[i]=n+1-i;
    }

}
//*********************************
int main()
{
    //int tableau[] = {1};
    int n;
    printf("Donnez une taille a votre tableau: \n");
    scanf("%d", &n);
    int* tableau = (int*)malloc(n * sizeof(int));
    int* tableau2 = (int*)malloc(n * sizeof(int));
    int* tableau3 = (int*)malloc(n * sizeof(int));

    
        
    printf("Tableau remplis avec random.\n");
    remplissageRandom(tableau,n);
    printArray(tableau, n);
    
    printf("Tableau remplis avec des valeurs de 1 à n.\n");
    RemplissageParIndex(tableau2,n);
    printArray(tableau2, n);
    
    printf("Tableau remplis avec des valeurs de n à 1.\n");
    RemplissageParIndexInverse(tableau3,n);
    printArray(tableau3, n);
        
    

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
        //printArray(tableau, n);
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
       
        int left, right, middle;
        printf("Donnez les valeurs left, middle, right pour créer les 2 subarrays.\n");
        scanf("%d, %d, %d",&left, &middle, &right);
        printf("Tableau avec valeurs random");
        t1 = clock();
        triFusion(tableau, left, middle, right);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        printf("Tableau avec valeurs de 1 à n");
        t1 = clock();
        triFusion(tableau2, left, middle, right);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
        printf(" Le temps d'execution est calcul est comme suit : %f \n", tempsExec);
        printf("Tableau avec valeurs de n à 1");
        t1 = clock();
        triFusion(tableau3, left, middle, right);
        t2 = clock();
        tempsExec = t2 - t1;
        tempsExec = ((double)tempsExec)/CLOCKS_PER_SEC;
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

    // insertionSort(tableau, 100);
    // printArray(tableau, 100);
    return 0;
}
