/*
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <time.h>

    // Struktura èvora binarnog stabla
    struct _node;
    typedef struct _node* Position;
    typedef struct _node {
        int value;
        Position left;
        Position right;
    } Node;

    Position createNode(int value);
    Position insert(Position root, int value);
    int inorder(Position root);
    int preorder(Position root);
    int postorder(Position root);
    int levelOrder(Position root);
    Position search(Position root, int value);
    Position deleteNode(Position root, int value);
    int replace(Position root);
    int random();

    int main() {
        Position root = NULL;
        Position rootRand = NULL;
        srand(time(0));

        //int rootValue = 0;
        //printf("\033[0;32mEnter root value: \033[0m");
        //scanf("%d", &rootValue);
        //root = insert(root, rootValue);

        root = insert(root, 2);
        insert(root, 5);
        insert(root, 7);
        insert(root, 8);
        insert(root, 11);
        insert(root, 1);
        insert(root, 4);
        insert(root, 2);
        insert(root, 3);
        insert(root, 7);

        levelOrder(root);

        replace(root);

        printf("\n");
        levelOrder(root);

        rootRand = insert(rootRand, random());
        for (int i = 0; i < 10; i++) {
            insert(rootRand, random());
        }

        printf("\n");
        levelOrder(rootRand);

        //rand()

        /*
            while (1) {
                printf("\nMenu:\n");
                printf("1 - Insert node\n");
                printf("2 - Search node\n");
                printf("3 - Delete node\n");
                printf("4 - Print preorder\n");
                printf("5 - Print inorder\n");
                printf("6 - Print postorder\n");
                printf("7 - Print level order\n");
                printf("8 - exit\n");

                char choice[10] = { 0 };
                printf("Enter your choice: ");
                scanf("%s", choice);

                if (strcmp(choice, "1") == 0) {
                    int value = 0;
                    printf("\033[0;32mEnter value: \033[0m");
                    scanf("%d", &value);
                    insert(root, value);
                }
                else if (strcmp(choice, "2") == 0) {
                    int value = 0;
                    Position result = NULL;
                    printf("\033[0;32mEnter value: \033[0m");
                    scanf("%d", &value);
                    result = search(root, value);
                    if (result != NULL)
                        printf("\033[0;32mNode %d is found.\033[0m\n", value);
                    else
                        printf("\033[0;32mNode %d is not found.\033[0m\n", value);
                }
                else if (strcmp(choice, "3") == 0) {
                    int value = 0;
                    printf("\033[0;32mEnter value: \033[0m");
                    scanf("%d", &value);
                    deleteNode(root, value);
                }
                else if (strcmp(choice, "4") == 0) {
                    printf("\033[0;32mPreorder: \033[0m");
                    preorder(root);
                    printf("\n");
                }
                else if (strcmp(choice, "5") == 0) {
                    printf("\033[0;32mInorder: \033[0m");
                    inorder(root);
                    printf("\n");
                }
                else if (strcmp(choice, "6") == 0) {
                    printf("\033[0;32mPostorder: \033[0m");
                    postorder(root);
                    printf("\n");
                }
                else if (strcmp(choice, "7") == 0) {
                    printf("\033[0;32mLevel-order: \033[0m");
                    levelOrder(root);
                    printf("\n");
                }
                else if (strcmp(choice, "8") == 0) {
                    printf("\033[0;32mExiting the program.\033[0m\n");
                    break;
                }
                else {
                    printf("\033[0;31mInvalid choice. Please enter a valid option.\033[0m\n");
                }
            }

            vamo je kraj komentara

        return EXIT_SUCCESS;
    }
    
    Position createNode(int value) {
        Position newNode = NULL;
        newNode = (Position)malloc(sizeof(Node));
        if (!newNode) {
            printf("Can't allocate memory!\n");
            return NULL;
        }
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    Position insert(Position root, int value) {
        if (root == NULL)
            return createNode(value);

        if (value < root->value)
            root->left = insert(root->left, value);
        else if (value >= root->value)
            root->right = insert(root->right, value);

        return root;
    }

    int inorder(Position root) {
        if (root) {
            inorder(root->left);
            printf("%d ", root->value);
            inorder(root->right);
        }
        return EXIT_SUCCESS;
    }

    int preorder(Position root) {
        if (root) {
            printf("%d ", root->value);
            preorder(root->left);
            preorder(root->right);
        }
        return EXIT_SUCCESS;
    }

    int postorder(Position root) {
        if (root) {
            postorder(root->left);
            postorder(root->right);
            printf("%d ", root->value);
        }
        return EXIT_SUCCESS;
    }

    int levelOrder(Position root) {
        if (root == NULL)
            return;

        Position queue[100] = { 0 };
        int front = 0, rear = 0;

        queue[rear++] = root;

        while (front < rear) {
            Position current = queue[front++];

            printf("%d ", current->value);

            if (current->left != NULL)
                queue[rear++] = current->left;

            if (current->right != NULL)
                queue[rear++] = current->right;
        }
        return EXIT_SUCCESS;
    }

    Position search(Position root, int value) {
        if (root == NULL || root->value == value)
            return root;

        if (value < root->value)
            return search(root->left, value);

        return search(root->right, value);
    }

    Position deleteNode(Position root, int value) {
        if (root == NULL)
            return root;

        // Find node
        if (value < root->value)
            root->left = deleteNode(root->left, value);
        else if (value > root->value)
            root->right = deleteNode(root->right, value);
        else {
            // Node with one or no children
            if (root->left == NULL) {
                Position temp = root->right;
                free(root);
                return temp;
            }
            else if (root->right == NULL) {
                Position temp = root->left;
                free(root);
                return temp;
            }

            // Node with two children, find smallest in the right tree
            Position temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;

            // Copy value from smallest to current node
            root->value = temp->value;

            // Delete smallest from the right tree
            root->right = deleteNode(root->right, temp->value);
        }

        return root;
    }

    int replace(Position root) {  //2:55
        if (root == NULL) {
            return 0;
        }

        // Recursively update left and right subtrees first
        int leftValue = replace(root->left);
        int rightValue = replace(root->right);

        // Store the original value
        int originalValue = root->value;

        // Update the value of the current node to be the sum of its children
        root->value = leftValue + rightValue;

        // Return the sum of the node's value and the sum of its children
        return originalValue + root->value;
    }

    int random() {
        return (rand() % (90 - 10 + 1)) + 10;
    }
*/

//9. Zadan je niz brojeva 2, 5, 7, 8, 11, 1, 4, 2, 3, 7 koji su spremljeni u cvorove binarnog stabla.
//a) Napisati funkciju insert koja dodaje element u stablo tako da se pozivima te funkcije za
//sve element zadanog niza brojeva stvori stablo kao na slici Slika 1. Funkcije vraca
//pokazivac na korijen stabla.
    //b) Napisati funkciju replace koja ?e svaki element stabla zamijeniti sumom elemenata u
    //njegovom lijevom i desnom podstablu(tj.sumom svih potomaka prije zamjene
//    vrijednosti u tim potomcima).Npr.stablo sa slike Slika 1 transformirat ?e se u stablo na
//    slici Slika 2.
//    c) Prepraviti program na nacin da umjesto predefiniranog cjelobrojnog polja koristenjem
//    funkcije rand() generira slucajne brojeve u rasponu <10, 90>.Takoder, potrebno je
//    upisati u datoteku sve brojeve u inorder prolasku nakon koristenja funkcije iz a), zatim b)
//    dijela zadatka.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _binaryTree;
typedef struct _binaryTree* Position;
typedef struct _binaryTree {
    int el;
    Position left;
    Position right;
} BinaryTree;

Position insert(int el, Position root);
int inorder(Position root);
int replace(Position root);
int random(Position root);
int inorderInFile(Position root, FILE* filePointer);

int main() {

    Position root = NULL;
    int el = 0;
    printf("Unesite vrijednost prvog clana binarnog stabla: ");
    scanf("%d", &el);
    root = insert(el, root);

    FILE* filePointer = NULL;
    filePointer = fopen("binaryTree.txt", "w");

    int command = 1;
    do {
        printf("\nMenu:\n");
        printf("1 - Unos novog elementa\n");
        printf("2 - Ispis binarnog stabla - inorder\n");
        printf("3 - Replace (mjenja element sa zbrojem djece)\n");
        printf("4 - Random generiranje elemenata stabla\n");
        printf("5 - Ispis binarnog stabla u tekstualnu datoteku - inorder\n");
        printf("6 - izlaz\n");
        printf("[----->");
        scanf("%d", &command);

        switch (command) {
        case 1:
            printf("Unesite vrijednost novog elementa: ");
            scanf("%d", &el);
            insert(el, root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            replace(root);
            break;
        case 4:
            random(root);
            break;
        case 5:
            inorderInFile(root, filePointer);
            break;
        case 6:
            printf("Izlaz\n");
            break;
        default:
            printf("Ne postoji ta naredba\n");
        }
    } while (command != 6);

    fclose(filePointer);
    return 0;
}

Position insert(int el, Position root) {
    if (root == NULL) {
        Position newElement = (Position)malloc(sizeof(BinaryTree));
        if (newElement == NULL) {
            printf("Kivo alocirana memorija\n");
            return -1;
        }
        else {
            newElement->el = el;
            newElement->left = NULL;
            newElement->right = NULL;
        }
        root = newElement;
    }
    else if (el < root->el) {
        root->left = insert(el, root->left);
    }
    else if (el > root->el) {
        root->right = insert(el, root->right);
    }
    return root;
}

int inorder(Position root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->el);
        inorder(root->right);
    }
    return 0;
}

int replace(Position root) {
    if (root == NULL) { //ako je root dosa do kraja vraca se 0 
        return 0;
    }

    int sumLeft = 0, sumRight = 0;

    sumLeft += replace(root->left);
    sumRight += replace(root->right);

    int temp = root->el;
    root->el = sumLeft + sumRight;
    return temp + root->el;
}

int random(Position root) {
    int randomnumber = 0;
    randomnumber = rand() % 90 + 1;
    printf("%d ", randomnumber);
    insert(randomnumber, root);
    return 0;
}

int inorderInFile(Position root, FILE* filePointer) {
    if (root != NULL) {
        inorderInFile(root->left, filePointer);
        fprintf(filePointer, "%d ", root->el);
        inorderInFile(root->right, filePointer);
    }
    return 0;
}