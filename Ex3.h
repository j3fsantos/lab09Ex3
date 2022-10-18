
#ifndef EX3
#define EX3


typedef struct NodeS {
	int val; 
	struct NodeS* next; 
}* Set; 


Set set_add(Set s, int i);
Set remove_s(Set s, int i);
Set set_union (Set s1, Set s2);
Set diff (Set s1, Set s2);
int find (Set s, int i);
int count (Set s);
void printSet (Set s);
int validSet(Set s);

#endif