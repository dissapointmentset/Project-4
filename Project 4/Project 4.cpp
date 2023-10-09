#include <stdio.h>
#include <conio.h>
#include <string.h>
struct Item
{
	char name[50];
	int cost;
	void inititem(char s[50], int a);
};
void Item::inititem(char s[50], int a) {
	strcpy(name, s);
	cost = a;
};


struct compose
{
	Item *a;
	int colvo;
	int sostav[];
	void initcompose(Item *m, int a, int mas[20]);
}; 
struct sold
{
	Item a;
	int b;
	void initsold(Item a, int b);
};
struct action
{
	resource a;
	void initdel(resource a, int b);
	void initsup(resource a, int b);
}; 
struct resource
{
	int key, kolvo;
};