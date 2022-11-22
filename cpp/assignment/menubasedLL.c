#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNodeLL(int n)
{
    Node *head, *curr, *temp;
    int i;
    head = (Node *)malloc(sizeof(Node));
    printf("Enter the elements: ");
    scanf("%d", &(head->data));
    head->next = NULL;
    curr = head; // current points to the last node//
    for (i = 0; i < n - 1; i++)
    {
        temp = (Node *)malloc(sizeof(Node));
        scanf("%d", &(temp->data));
        temp->next = NULL;
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void printLL(Node *head)
{
    if (head == NULL)
    {
        printf("\nEmpty list\n");
        return;
    }
    Node *temp;
    temp = head;
    printf("\nList: ");
    printf("%d", head->data);
    head = head->next;
    while (head != NULL)
    {
        printf(" --> %d ", (head->data));
        head = head->next;
    }
    printf("\n");
    head = temp;
}

Node *insertLL(Node *head, int i)
{
    printf("\nEnter the data of the Node: ");
    Node *temp = (Node *)malloc(sizeof(Node));
    scanf("%d", (&temp->data));
    int j;
    Node *curr, *x;
    if (i == 0)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    curr = head;
    for (j = 1; j < i && curr != NULL; j++)
        curr = curr->next;

    // if((curr == NULL) && (i>0)) return head;

    temp->next = curr->next;
    curr->next = temp;
    return head;
}
Node *createNodeCL(int n)
{
    Node *tail, *curr, *temp;
    int i;
    tail = (Node *)malloc(sizeof(Node));
    printf("Enter the elements: ");
    scanf("%d", &(tail->data));
    tail->next = tail;
    curr = tail;
    for (i = 0; i < n - 1; i++)
    {
        temp = (Node *)malloc(sizeof(Node));
        scanf("%d", &(temp->data));
        temp->next = tail;
        curr->next = temp;
        curr = temp;
    }
    return temp;
}
Node *insertCL(Node *tail, int i)
{
    printf("\nEnter the data of the Node: ");
    Node *temp = (Node *)malloc(sizeof(Node));
    scanf("%d", (&temp->data));

    if (tail == NULL)
    {
        temp->next = temp;
        tail = temp;
        return tail;
    }

    if (i == 0)
    {
        temp->next = tail->next;
        tail->next = temp;
        return tail;
    }
    Node *curr = tail->next;
    int pos = 1;
    do
    {
        if (pos == i)
        {
            // Adjusting the links.
            temp->next = curr->next;

            // Adding newly allocated node after p.
            curr->next = temp;

            // Checking for the last node.
            if (curr == tail)
                tail = temp;

            return tail;
        }
        curr = curr->next;
        pos++;
    } while (curr != tail->next);
}
void printCL(Node *tail)
{
    if (tail == NULL)
    {
        printf("\nEmpty list\n");
        return;
    }
    Node *temp;
    temp = tail->next;
    int i = 0;
    printf("\nList: \n");
    printf("%d", temp->data);
    temp = temp->next;
    do
    {
        printf(" -> %d", temp->data);
        temp = temp->next;
        i++;
    } while (temp != tail->next);
    printf("\n");

    for (int j = 0; j <= i; j++)
    {
        printf(" <- ");
    }

    printf("\n");
}
void deleteCL(Node **tail, int key)
{

    if (*tail == NULL)
        return;

    // Find the required node
    Node *curr = *tail, *prev;
    while (curr->data != key)
    {
        if (curr->next == *tail)
        {
            printf("\nGiven node is not found in the list!\n");
            break;
        }

        prev = curr;
        curr = curr->next;
    }

    // Check if node is only node
    if (curr->next == *tail)
    {
        *tail = NULL;
        free(curr);
        return;
    }

    // If more than one node, check if
    // it is first node
    if (curr == *tail)
    {
        prev = *tail;
        while (prev->next != *tail)
            prev = prev->next;
        *tail = curr->next;
        prev->next = *tail;
        free(curr);
    }

    // check if node is last node
    else if (curr->next == *tail && curr == *tail)
    {
        prev->next = *tail;
        free(curr);
    }
    else
    {
        prev->next = curr->next;
        free(curr);
    }
}
Node *concatenateLL(Node *head, Node *new_node)
{
    Node *curr;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new_node;
    }
    return head;
}

Node *reverseLL(Node *head)
{
    Node *prev, *curr, *forw;
    prev = NULL;
    curr = head;
    forw = curr->next;
    while (curr->next != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = forw;
        forw = curr->next;
    }
    curr->next = prev;
    return curr;
}
void deleteLL(Node **head, int position)
{
    Node *temp;
    Node *prev;
    temp = *head;
    prev = *head;
    for (int i = 0; i < position; i++)
    {

        if (i == 0 && position == 1)
        {
            *head = (*head)->next;
            free(temp);
        }
        else
        {
            if (i == position - 1 && temp)
            {
                prev->next = temp->next;
                free(temp);
            }
            else
            {
                prev = temp;

                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}

void menu0()
{
    printf("\n1. Singly Linked list\n2. Circular Linked\n3. Exit\n\nEnter your choice: ");
}

void menuForLinear()
{
    int i = -1;
    Node *head;
    printf("\nSingly Linked List\n");
    int n, ch, pos;
    while (i != 7)
    {
        printf("\n1. Create Node\n2. Insert a Node\n3. Delete Node\n4. Print List\n5. Reverse a List\n6. Concatenate two list\n7. Go Back\n\nEnter your choice: ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("\nEnter the size of the list: ");
            scanf("%d", &n);
            head = createNodeLL(n);
            printf("\n%d nodes List created!\n", n);
            break;

        case 2:
            // printf("=%d\n",n);
            printf("\n1. To insert at Start\n2. To insert at End\n3. To insert in middle\n\nEnter your choice: ");
            scanf("%d", &ch);
            if (ch == 1)
                pos = 0;
            else if (ch == 2)
                pos = n;
            else
            {
                while (1)
                {
                    printf("\nEnter the index: ");
                    scanf("%d", &pos);
                    if (pos > 0 && pos < n)
                        break;
                }
            }
            // printf("%d",pos);
            head = insertLL(head, pos);
            n++;
            break;

        case 3:
            printf("\n1. To delete Head node\n2. To delete Tail node\n3. To delete middle node\n\nEnter your option: ");
            scanf("%d", &ch);
            if (ch == 1)
                pos = 1;
            else if (ch == 2)
                pos = n;
            else if (ch == 3)
            {
                while (1)
                {
                    printf("\nEnter the index: ");
                    scanf("%d", &pos);
                    if (pos > 0 && pos < n)
                        break;
                }
            }
            deleteLL(&head, pos);
            printf("Node deleted\n");
            n--;
            break;

        case 4:
            printLL(head);
            break;

        case 5:
            head = reverseLL(head);
            printf("\nList reversed!\n");
            break;

        case 6:
            printf("Enter the size of the other list: ");
            int m;
            scanf("%d", &m);
            Node *head1 = createNodeLL(m);
            head = concatenateLL(head, head1);
            n += m;
            printf("\nTwo list are concatenated\n");
            break;

        case 7:
            return;

        default:
            printf("\nEnter a valid option\n");
            break;
        }
    }
}
void menuForCircular()
{
    int i;
    Node *tail = NULL;
    int n, ch, pos;
    printf("\nCircular Linked List\n");
    while (1)
    {
        printf("\n1. Create Nodes\n2. Insert a Node\n3. Delete Node\n4. Print List\n5. Go Back\n\nEnter your choice: ");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("\nEnter the size of the list: ");
            scanf("%d", &n);
            tail = createNodeCL(n);
            printf("\n%d nodes List created!\n", n);
            break;

        case 2:
            printf("1. To insert at Start\n2. To insert at End\n3. To insert in middle\n\nEnter your choice");
            scanf("%d", &ch);
            if (ch == 1)
                pos = 1;
            else if (ch == 2)
                pos = n - 1;
            else
            {
                while (1)
                {
                    printf("\nEnter the index: ");
                    scanf("%d", &pos);
                    if (pos > 0 && pos < n)
                        break;
                }
            }
            // printf("%d",pos);
            pos--;
            tail = insertCL(tail, pos);
            printf("\nNode inserted\n");
            n++;
            break;

        case 3:
            printf("\nEnter the data to be deleted: ");
            int key;
            scanf("%d", &key);
            deleteCL(&tail, key);
            printf("\nNode deleted\n");
            n--;
            break;

        case 4:
            printCL(tail);
            break;

        case 5:
            return;

        default:
            break;
        }
    }
}
int main()
{

    int j = -1;
    while (1)
    {
        menu0();
        scanf("%d", &j);
        // For linear
        if (j == 1)
            menuForLinear();

        // For Circular
        else if (j == 2)
            menuForCircular();

        // To exit
        else
            break;
    }
}