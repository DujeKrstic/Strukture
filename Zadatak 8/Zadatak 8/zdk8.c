/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int main() {
    
    //Node head = {
    //     .value = 0,
    //     .left = NULL,
    //     .right = NULL,
    //     };
    
                                                    //20:39
    Position root = NULL;

    int rootValue = 0;
    printf("\033[0;32mEnter root value: \033[0m");
    scanf("%d", &rootValue);
    root = insert(root, rootValue);

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

    return EXIT_SUCCESS;
}

Position createNode(int value) {                    //20:40
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

Position insert(Position root, int value) {                 //20:33         //20:41 - 20:54
    if (root == NULL)
        return createNode(value);

    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value >= root->value)
        root->right = insert(root->right, value);

    return root;
}

int inorder(Position root) {                    //20:35         //20:54 - 21:00
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
    return EXIT_SUCCESS;
}

int preorder(Position root) {                   //20:36         //21:00 - 21:03
    if (root != NULL) {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
    return EXIT_SUCCESS;
}

int postorder(Position root) {                  //20:36             //21:03 - 21:06
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->value);
    }
    return EXIT_SUCCESS;
}

int levelOrder(Position root) {
    if (root == NULL)
        return;

    // Red za èekanje èvorova koji se trebaju posetiti
    Position queue[100];
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

Position search(Position root, int value) {                 //20:34
    if (root == NULL || root->value == value)
        return root;

    if (value < root->value)
        return search(root->left, value);

    return search(root->right, value);
}

Position deleteNode(Position root, int value) {
    if (root == NULL)
        return root;

    // Pronalazak èvora koji se treba obrisati
    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {
        // Èvor sa samo jednim ili bez dece
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

        // Èvor sa dvoje dece, pronaði najmanji èvor u desnom podstablu (naslednika)
        Position temp = root->right;
        while (temp->left != NULL)
            temp = temp->left;

        // Kopiranje vrednosti najmanjeg èvora u trenutni èvor
        root->value = temp->value;

        // Brisanje najmanjeg èvora iz desno podstabla
        root->right = deleteNode(root->right, temp->value);
    }

    return root;
}

//20:32 pocea snimat
*/

//8. Napisati program koji omogucava rad s binarnim stablom pretrazivanja.Treba
//omoguciti unosenje novog elementa u stablo, ispis elemenata(inorder, preorder, postorder i
//level order), brisanje i pronalazenje nekog elementa.

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
Position search(int el, Position root);
Position deleteElement(int el, Position root);
int inorder(Position root);
int preorder(Position root);
int postorder(Position root);
int levelOrder(Position root);

int main() {

    Position root = NULL;
    int el = 0;
    printf("Unesite vrijednost prvog clana binarnog stabla: ");
    scanf("%d", &el);
    root = insert(el, root);


    int command = 1;
    do {
        printf("\nMenu:\n");
        printf("1 - Unos novog elementa\n");
        printf("2 - Ispis binarnog stabla - inorder\n");
        printf("3 - Ispis binarnog stabla - preorder\n");
        printf("4 - Ispis binarnog stabla - postorder\n");
        printf("5 - Ispis binarnog stabla - level order\n");
        printf("6 - Pretrazivanje binarnog stabla\n");
        printf("7 - Brisanje nekog elementa\n");
        printf("8 - izlaz\n");
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
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            levelOrder(root);
            break;
        case 6:
            printf("Unesite vrijednost elementa kojeg zelite traziti: ");
            scanf("%d", &el);
            Position result = search(el, root);
            if (result != NULL) {
                printf("Element postoji u stablu\n");
            }
            else {
                printf("Element ne postoji u stablu\n");
            }
            break;
        case 7:
            printf("Unesite vrijednost elementa kojeg zelite izbrisati: ");
            scanf("%d", &el);
            deleteElement(el, root);
            break;
        case 8:
            printf("Izlaz\n");
            break;
        default:
            printf("Ne postoji ta naredba\n");
        }
    } while (command != 8);

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
    else if (el >= root->el) {
        root->right = insert(el, root->right);
    }
    return root;
}

Position search(int el, Position root) {
    if (root == NULL) {
        return NULL;
    }
    else if (el < root->el) {
        root->left = search(el, root->left);
    }
    else if (el > root->el) {
        root->right = search(el, root->right);
    }
    else {
        return root;
    }
}

Position  (int el, Position root) {
    if (root == NULL) {
        printf("Nema ga");
    }

    // Pronalazak cvora koji se treba obrisati
    else if (el < root->el) {
        root->left = deleteElement(el, root->left);
    }
    else if (el > root->el) {
        root->right = deleteElement(el, root->right);
    }
    //pronaden element za brisanje

    //ako element koji se brise ima livo i desno dite
    else if (root->left != NULL && root->right != NULL) {
        //pronalazak najmanjeg djeteta na desnoj strani(moze i najveceg na livoj strani)
        Position temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        //element za brisanje se zamjenjuje sa pronadenim najmanjim elementom
        root->el = temp->el;
        //ne zamjenjuje se zapravo element nego vrijednost najmanjeg se stavlja na element kojeg se tribalo brisat

        //brisanje
        root->right = deleteElement(root->el, root->right);
    }
    //ako element za brisanje nema oba diteta
    else {
        Position temp = root;
        if (root->left == NULL) {
            root = root->right;
        }
        else {
            root = root->left;
        }
        free(temp);
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

int preorder(Position root) {
    if (root != NULL) {
        printf("%d ", root->el);
        preorder(root->left);
        preorder(root->right);
    }
    return 0;
}

int postorder(Position root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->el);
    }
    return 0;
}

int levelOrder(Position root) {
    if (root == NULL) {
        return 0;
    }

    Position element[20] = { 0 }; //ukupan broj elemenata u stablu
    int front = 0, rear = 0;

    element[rear++] = root;

    while (front < rear) {
        Position current = element[front++];

        printf("%d ", current->el);

        if (current->left != NULL) {
            element[rear++] = current->left;
        }

        if (current->right != NULL) {
            element[rear++] = current->right;
        }
    }
    return 0;
}