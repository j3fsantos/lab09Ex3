#include <stdlib.h>
#include <stdio.h>
#include "Ex3.h"


Set makeNode(int v) {
	Set n = (Set)malloc(sizeof(struct NodeS)); 
	n->val = v; 
  n->next = 0;
	return n; 
}


Set set_add(Set s, int i) {
  if (s == NULL) {
    return makeNode(i);
  }

  if (s->val == i) {
    return s; 
  }

  Set prev = s; 
  Set cur = s->next;
  while(cur != NULL) {
    if((cur != NULL) && (cur->val == i)) {
      return s; 
    }
    prev = cur; 
    cur = cur->next; 
  }

  Set aux = makeNode(i); 
  prev->next = aux; 
  return s; 
}


Set remove_s(Set s, int i) {
  if (s == NULL) {
    return s;
  }

  if (s->val == i) {
    return NULL; 
  }

  Set prev = s; 
  Set cur = s->next;
  while(cur != NULL) {
    if(cur->val == i) {
      prev->next = cur->next;
      return s;  
    }
    prev = cur; 
    cur = cur->next; 
  }

  return s; 
}

Set set_union (Set s1, Set s2) {
  while (s2 != NULL) {
    s1 = set_add(s1, s2->val);
    s2 = s2->next; 
  }
  return s1; 
} 

Set diff (Set s1, Set s2) {
  while (s2 != NULL) {
    s1 = remove_s(s1, s2->val);
    s2 = s2->next; 
  }
  return s1; 
}

int find (Set s, int i) {
  while (s != NULL) {
    if (s->val == i) {
      return 1;
    } 
  }
  return 0; 
}

int count (Set s) {
  int c = 0; 
  while (s != NULL) {
    c++; s = s->next;
  }
  return c; 
}

void printSet (Set s) {
	while (s != NULL) {
		printf("<v: %d>", s->val);
		if (s->next != NULL) {
			printf(", ");
		}
		s = s->next; 
	}
	printf("\n");
}









