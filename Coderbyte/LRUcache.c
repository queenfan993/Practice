#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char* val;
    struct Node* next;
    struct Node* prev;
} node;

node* createNode(char* str) {
    node* temp = (node*)calloc(1, sizeof(node));
    char* x = (char*)calloc(strlen(str) + 1, sizeof(char));
    strcpy(x, str);
    temp -> val = x;
    temp -> next = NULL;
    temp -> prev = NULL;
    return temp;
}

void freeNode(node* temp) {
  free(temp -> val);
  free(temp);
}

void addNodeFromTail(node* tail, char* str) {
    node* nNode = createNode(str);
    if (tail->prev != NULL) {
        tail->prev->next = nNode;
        nNode->prev = tail->prev;
    }
    tail->prev = nNode;
    nNode->next = tail;
}


void removeNode(node* head, char* str) {
    node* temp = head->next;
    while (temp != NULL) {
        if (strcmp(temp->val, str) == 0) {
            //printf("%s\n", "cmp");
            temp->prev->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            freeNode(temp);
            break;
        }
        temp = temp->next;
    }
}

int find(int* hash, char alphabet) {
  if(hash[alphabet - 'A']) {
    return 1;
  }
  return 0;
}


void printList(node* head, int size) {
    node* temp = head->next;
    int count = 0;
    while (temp -> next && count < size-1) {
        count++;
        printf("%s-", temp->val);
        temp = temp->next;
    }
    printf("%s", temp->val);
}


void LRUCache(char * strArr[], int arrLength) {
  
  char nu[] = " ";
  node* head = createNode(nu);
  node* tail = createNode(nu);
  head -> next = tail;
  tail -> prev = head;
  int curSize = 0;
  int hash[26] = {0};

  for(int i = 0; i < arrLength; i++) {
    if(find(hash, strArr[i][0])) {
      removeNode(head, strArr[i]);
      addNodeFromTail(tail, strArr[i]);
    } else {
      if(curSize < 5) {
        addNodeFromTail(tail, strArr[i]);
        hash[strArr[i][0] - 'A'] = true;
        curSize++;
      } else {
        removeNode(head, head -> next -> val);
        hash[strArr[i][0] - 'A'] = false;
        addNodeFromTail(tail, strArr[i]);
      }
    }
  }
  printList(head, curSize);

}

int main(void) { 
   
  // keep this function call here
  /*-
  char matrix[][20] = {
    "A", "B", "C", "D", "A", "E", "D"
  };
  char * A[] = {matrix[0], matrix[1], matrix[2], matrix[3], matrix[4], matrix[5], matrix[6]};
  */
  
  char matrix[][20] = {
    "A", "A", "A", "A"
  };
  char * A[] = {matrix[0], matrix[1], matrix[2], matrix[3]};
  
  /*
  char matrix[][20] = {
    "A", "B", "C", "D", "E", "D", "Q", "Z", "C"
  };
  char * A[] = {matrix[0], matrix[1], matrix[2], matrix[3], matrix[4], matrix[5], matrix[6], matrix[7], matrix[8]};
  */
  //char * A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  LRUCache(A, arrLength);
  return 0;
    
}