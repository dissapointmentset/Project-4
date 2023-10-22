#pragma once

#include <stdio.h>
#include <string.h>

struct Item
{
	char name[50];
	int cost;
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
	int kolvo;
	void initsold(Item a, int b);
};
struct resource
{
	int key, kolvo;
	char name[50];
};
struct action
{
	resource a;
	void initdel(resource a, int b);
	void initsup(resource a, int b);
}; 
Item inititem(char name[50], int cost);
resource initresource(char name[50], int key, int kolvo);
sold initsold(Item a, int kolvo);
