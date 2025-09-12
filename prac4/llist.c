#include <stdio.h>
#include <stdlib.h>

typedef struct book_node_{
  char *name;
  double price;
  int numOfPages;
  char *language;
  double weight;
  int yearPublished;

  struct book_node_ *next;
}book_node;

book_node *getBookNode(char *name, double price, int numOfPages, char *language, double weight, int yearPublished){
  book_node *node = malloc(sizeof(book_node));

  if(!node){
    // practically never happens, so aborting looks better to me
    printf("could not allocate\n");
    exit(-1);
  }

  *node = (book_node){
    .name = name,
    .price = price,
    .numOfPages = numOfPages,
    .language = language,
    .weight = weight,
    .yearPublished = yearPublished,

    .next = NULL
  };

  return node;
}

void insertBookNode(book_node *root, book_node *node){
  if(!root) return;

  while(root->next) root = root->next;
  root->next = node;
}

void bookListFree(book_node *root){
  book_node *cur;

  while(root){
    cur = root;
    root = root->next;

    free(cur);
  }
}

void printBookList(book_node *root){
  while(root){
    printf("Book title: %s\n", root->name);
    printf("Price: %.2f UAH\n", root->price);
    printf("Number of pages: %d\n", root->numOfPages);
    printf("Language: %s\n", root->language);
    printf("Weight: %.3f kg\n", root->weight);
    printf("Year published: %d\n", root->yearPublished);
    printf("______________________\n");

    root = root->next;
  }
}

int main(){
  book_node *head = getBookNode(
    "Гаррі Поттер і філософський камінь",
    400,
    320,
    "Ukrainian",
    0.325,
    2017
  );

  insertBookNode(
      head,
      getBookNode(
        "Гаррі Поттер і таємна кімната",
        520,
        370,
        "Ukrainian",
        0.431,
        2025
      )
  );

  insertBookNode(
      head,
      getBookNode(
        "Гаррі Поттер і в’язень Азкабану",
        380,
        384,
        "Ukrainian",
        0.365,
        2017
      )
  );

  insertBookNode(
      head,
      getBookNode(
        "Гаррі Поттер і келих вогню",
        420,
        670,
        "Ukrainian",
        0.584,
        2017
      )
  );

  insertBookNode(
      head,
      getBookNode(
        "Гаррі Поттер i Орден Фенікса",
        450,
        816,
        "Ukrainian",
        0.676,
        2017
      )
  );

  insertBookNode(
      head,
      getBookNode(
        "Гаррі Поттер і Напівкровний Принц",
        420,
        576,
        "Ukrainian",
        0.5, // not stated
        2017
      )
  );

  insertBookNode(
      head,
      getBookNode(
        "Гаррі Поттер і Смертельні реліквії",
        420,
        640,
        "Ukrainian",
        0.563,
        2017
      )
  );

  printBookList(head);

  bookListFree(head);
}
