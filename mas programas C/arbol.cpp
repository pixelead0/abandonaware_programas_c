#include  <stdio.h>
#include  <conio.h>
struct arbol {
  int dato;
  arbol *izq, *der;
} *arb, *bor, *aux1;

int dato;

void insertar(int x){
  arbol *a;
  if (arb == NULL) {
    arb = new arbol;
    arb->dato = x;
    arb->izq = NULL;
    arb->der = NULL;
  } else {
    if (x  <arb->dato) {
      a = arb; arb = arb->izq;
      insertar (x);
      a->izq = arb; arb = a;
    } else {
      a = arb; arb = arb->der;
      insertar (x);
      a->der = arb; arb = a;
    }
  }
}

void orden() {
  arbol *a;
  if (arb != NULL) {
    a = arb; arb = arb->izq;
    orden ();
    arb = a;
    printf ("\t%d", arb->dato);
    a = arb; arb = arb->der;
    orden ();
    arb = a;
  }
}

void preorden() {
  arbol *a;
  if (arb != NULL) {
    printf ("\t%d", arb->dato);
    a = arb; arb = arb->izq;
    preorden ();
    arb = a;
    a = arb; arb = arb->der;
    preorden ();
    arb = a;
  }
}

void postorden() {
  arbol *a;
  if (arb != NULL) {
    a = arb; arb = arb->izq;
    postorden ();
    arb = a;
    a = arb; arb = arb->der;
    postorden ();
    arb = a;
    printf ("\t%d", arb->dato);
  }
}

void borra () {
  arbol *a;
    if (bor->der != NULL) {
      a = bor; bor = bor->der;
      borra();
      a->der = bor; bor = a;
    } else {
      aux1->dato = bor->dato;
      aux1 = bor; bor = bor->izq;
    }
}

void eliminar(int v) {
  arbol *a;
    if (arb == NULL) printf ("El dato no existe...");
    else if (v  <arb->dato) {
      a = arb; arb = arb->izq; eliminar (v); a->izq = arb; arb = a;
    } else if (v > arb->dato) {
      a = arb; arb = arb->der; eliminar (v); a->der = arb; arb = a;
    } else {
      aux1 = arb;
        if (aux1->der == NULL) arb = aux1->izq;
        else if (aux1->izq == NULL) arb = aux1->der;
        else {
          bor = aux1->izq; borra();
          aux1->izq = bor;
        }
    }
}

void main () {
  clrscr();
  arb = NULL;
  int op;
  do {
    clrscr();
    printf ("\n\n\tMen£ de opciones: ");
    printf ("\nInsertar......[1]");
    printf ("\nEliminar......[2]");
    printf ("\nVis.Orden.....[3]");
    printf ("\nVis.preorden..[4]");
    printf ("\nVis.postorden.[5]");
    printf ("\nSalir.........[6]");
    printf ("\n\tElija su opci¢n: ");
    scanf ("%d", &op); printf ("\n\n");
    switch (op) {
      case 1 : printf (" Dato a insertar: ");
               scanf ("%d", &dato);
               insertar(dato);
               break;
      case 2 : printf (" Dato a eliminar: ");
               scanf ("%d", &dato);
               eliminar(dato);
               break;
      case 3 : orden(); break;
      case 4 : preorden(); break;
      case 5 : postorden(); break;
    }
    getch();
  } while (op != 6);
}
