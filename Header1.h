#pragma once
#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>


using namespace std;

struct resource
{
	string name;
	unsigned int kolvo;
};
struct compose
{
	vector <resource> sost;
	vector <unsigned int> n;
};
struct Item
{
	string name;
	unsigned int cost;
	compose *p;
};
struct sold
{
	Item item;
	unsigned int kolvo;
	int profit;
};
struct action
{
	resource resource;
	unsigned int kolvo;
	bool f;
};
Item inititem(string name, unsigned int cost, compose a);
resource initresource(string name, unsigned int kolvo);
sold initsold(Item item, unsigned int kolvo);
action initaction(resource a, unsigned int b, bool f);
compose initcompose(vector<resource> m, vector <unsigned int> n);
void showres(vector<resource> m);
void showmenu(vector <Item> m);
void acthist(vector <action> m);
void showing(Item p);
void solddata(vector <sold> m);
void costchange(Item p, unsigned int b);
void sostadd(compose comp, resource r, unsigned int b);
void sostdel(compose comp, unsigned int b);
resource consresinit();