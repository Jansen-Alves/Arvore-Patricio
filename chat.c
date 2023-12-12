#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 128

// Estrutura para representar um nó da árvore Patricia
typedef struct PatriciaNode {
    int isLeaf; // Flag indicando se o nó é uma folha
    union {
        char* key; // Chave do nó (NULL para nós internos)
        struct PatriciaNode* child; // Nó filho para nós internos
    } data;
    struct PatriciaNode* left;
    struct PatriciaNode* right;
} PatriciaNode;

// Função auxiliar para criar um novo nó folha
PatriciaNode* createLeafNode(char* key) {
    PatriciaNode* newNode = (PatriciaNode*)malloc(sizeof(PatriciaNode));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nó\n");
        exit(EXIT_FAILURE);
    }

    newNode->isLeaf = 1;
    newNode->data.key = strdup(key);
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Função auxiliar para criar um novo nó interno
PatriciaNode* createInternalNode(int index, PatriciaNode* left, PatriciaNode* right) {
    PatriciaNode* newNode = (PatriciaNode*)malloc(sizeof(PatriciaNode));
    if (newNode == NULL) {
        fprintf(stderr, "Erro ao alocar memória para o nó\n");
        exit(EXIT_FAILURE);
    }

    newNode->isLeaf = 0;
    newNode->data.child = NULL;
    newNode->left = left;
    newNode->right = right;

    return newNode;
}

// Função auxiliar para encontrar o índice do primeiro bit diferente entre duas strings
int bitDifference(char* key1, char* key2) {
    int i = 0;
    while (key1[i] && key2[i] && key1[i] == key2[i]) {
        i++;
    }

    // Retorna o índice do primeiro bit diferente
    return i * 8;
}

// Função auxiliar para inserir uma chave em um nó folha
PatriciaNode* insertLeafNode(PatriciaNode* leaf, char* key) {
    int diffBit = bitDifference(leaf->data.key, key);

    if (diffBit == 0) {
        // As chaves são iguais
        return leaf;
    } else {
        // Encontra o índice do primeiro bit diferente
        int bitIndex = diffBit % 8;
        int byteIndex = diffBit / 8;

        // Cria um nó interno
        PatriciaNode* internalNode = createInternalNode(bitIndex, NULL, NULL);

        // Decide para qual lado a nova chave deve ir
        if (key[byteIndex] & (1 << (7 - bitIndex))) {
            internalNode->left = leaf;
            internalNode->right = createLeafNode(key + byteIndex);
        } else {
            internalNode->left = createLeafNode(key + byteIndex);
            internalNode->right = leaf;
        }

        return internalNode;
    }
}

// Função auxiliar para inserir uma chave na árvore Patricia
PatriciaNode* insertPatriciaNode(PatriciaNode* root, char* key) {
    if (root == NULL) {
        // Árvore vazia, cria um novo nó folha
        return createLeafNode(key);
    }

    if (root->isLeaf) {
        // Nó folha, insere a nova chave
        return insertLeafNode(root, key);
    } else {
        // Nó interno, decide para qual lado a nova chave deve ir
        int diffBit = bitDifference(root->left->data.key, key);

        if (diffBit == 0) {
            // As chaves são iguais, insere recursivamente no nó filho
            root->left = insertPatriciaNode(root->left, key);
        } else {
            // Encontra o índice do primeiro bit diferente
            int bitIndex = diffBit % 8;

            if (key[diffBit / 8] & (1 << (7 - bitIndex))) {
                root->right = insertPatriciaNode(root->right, key);
            } else {
                root->left = insertPatriciaNode(root->left, key);
            }
        }

        return root;
    }
}

// Função auxiliar para imprimir as chaves na árvore Patricia
void printKeys(PatriciaNode* root, char* prefix) {
    if (root == NULL) {
        return;
    }

    if (root->isLeaf) {
        printf("%s%s\n", prefix, root->data.key);
    } else {
        printKeys(root->left, prefix);
        printKeys(root->right, prefix);
    }
}

// Função principal para criar, inserir, imprimir e liberar a árvore Patricia
int main() {
    PatriciaNode* patricia = NULL;

    // Inserir chaves na árvore Patricia
    patricia = insertPatriciaNode(patricia, "car");
    patricia = insertPatriciaNode(patricia, "cat");
    patricia = insertPatriciaNode(patricia, "bat");
    patricia = insertPatriciaNode(patricia, "batman");

    // Imprimir chaves existentes
    printf("Chaves existentes:\n");
    printKeys(patricia, "");

    // Remover uma chave (implementação não fornecida, pois é mais complexa)
    // ...

    // Liberar memória (implementação não fornecida, pois é mais complexa)
    // ...

    return 0;
}
