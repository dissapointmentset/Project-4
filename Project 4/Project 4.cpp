#pragma once

#include <stdio.h>
#include <string.h>

struct Item
{
	char name[50];
	unsigned int cost;
};
struct compose
{
	Item *p;
	resource m[50];
	unsigned int n[50];
}; 
struct sold
{
	Item a;
	unsigned int kolvo;
};
struct resource
{
	char name[50];
	unsigned int kolvo;
};
struct action
{
	resource a[50];
	unsigned int n;
	bool f;	
}; 
Item inititem(char name[50], unsigned int cost);
resource initresource(unsigned int kolvo);
sold initsold(Item a, unsigned int kolvo);
action initaction(resource a, unsigned int b, bool f);
compose initcompose(Item* p, resource m[], unsigned int n[]);
void showres(unsigned int n, resource m[]);
void showmenu(Item m[]);
void acthist(action m[]);
void showsost(Item *p);
void solddata(sold m[]);
