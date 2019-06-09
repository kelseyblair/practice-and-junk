// linked_lists.c

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} node;

//create new node
node* create(int data, node* next)
{
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL)
    {
      printf("Error creating new node\n");
      exit(0);
    }
    new_node->data = data;
    new_node->next = next;

    return new_node;
}

//add new node to beginning of linkedlist (new head)
node* prepend(node* head, int data)
{
    node* new_node = create(data, head);
    head = new_node;

    return head;
}

// return number of items in list
int count(node* head)
{
    node* cursor = head;
    int c = 0;
    while( cursor != NULL )
    {
      c++;
      cursor = cursor->next;
    }
    return c;
}

// add new node to end of list
node* append(node* head, int data)
{
    // traverse to end of list
    node* cursor = head;
    while(cursor->next != NULL)
    {
      cursor = cursor->next;
    }

    node* new_node = create(data, NULL);
    cursor->next = new_node;

    return head;
}

//delete a node from the list
node* delete(node* head, node* del)
{
    // delete item at head
    if(del == head)
    {
      //empty list
      if(head == NULL)
      {
        return NULL;
      }
      node* front = head;
      head = head->next;
      front->next = NULL;
      // only one item in list
      if(front == head)
      {
        head = NULL;
      }
      free(front);

      return head;
    }

    // delete last item
    if(del->next == NULL)
    {
      if(head == NULL)
      {
        return NULL;
      }
      // traverse to end of list
      node* cursor = head;
      node* back = NULL;
      while(cursor->next != NULL)
      {
        back = cursor;
        cursor = cursor->next;
      }
      if(back != NULL)
      {
        back->next = NULL;
      }

      // only node in list
      if(cursor == head)
      {
        head = NULL;
      }
      free(cursor);

      return head;
    }

    // delete in middle of list
    node* cursor = head;
    while(cursor != NULL)
    {
      if(cursor->next == del)
      {
        break;
      }
      cursor = cursor->next;
    }

    if(cursor == NULL)
    {
      node* tmp = cursor->next;
      cursor->next = tmp->next;
      tmp->next = NULL;
      free(tmp);
    }

    return head;

}

void print_list(node* head)
{
  node* cursor = head;

  while(cursor != NULL)
  {
    printf("%d ", cursor->data);
    cursor = cursor->next;
  }

  printf("\n");
}

node* search(node* head, int data)
{
  node* cursor = head;
  while(cursor != NULL)
  {
    if(cursor->data == data)
    {
      return cursor;
    }
    cursor = cursor->next;
  }

  return NULL;
}

int main()
{
    node* head = create(1, NULL);

    for(int i = 2; i <= 10; i++)
    {
      head = append(head, i);
    }

    print_list(head);

    head = delete(head, head);

    print_list(head);



    return 0;
}
