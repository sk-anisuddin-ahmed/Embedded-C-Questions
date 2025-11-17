typedef struct Node {
    int data;
    struct Node* next;
}Node;

typedef struct NodeMulti {
    int data;
    struct NodeMulti* next;
    struct NodeMulti* child;
} NodeMulti;

struct Node* createNode(int data);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data) ;
void insertAfter(struct Node* prevNode, int data);
void deleteNode(struct Node** head, int key);
int search(struct Node* head, int key);
void printList(struct Node* head);
void deleteList(struct Node** head);
int countNodes(struct Node* head);

NodeMulti* createMultiLLNode(int data);
void printMultiList(NodeMulti* head);

typedef struct Node_randomList {
    int data;
    struct Node_randomList* random;
    struct Node_randomList* next;
} Node_randomList;

Node_randomList* createNode_randomList(int data);
void insertAtEnd_randomList(Node_randomList** head, int data);
void printList_randomList(Node_randomList* head);