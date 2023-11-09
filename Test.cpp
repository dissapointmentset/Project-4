#include "Header1.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
	resource coffee = initresource("coffee", 1000);
	resource milk = initresource("milk", 1000);
	resource sugar = initresource("sugar", 1000);
	resource sirop_chocolate = initresource("sirop_chocolate", 1000);
	resource chocolate = initresource("chocolate", 1000);
	resource sirop_nuts = initresource("sirop_nuts", 1000);
	resource sirop_cherry = initresource("sirop_cherry", 1000);
	resource cacao = initresource("cacao", 1000);

	std::vector<resource> cs = { coffee, milk, sugar};
	std::vector<unsigned int> csn = {30, 90, 30};
	compose comp_capuchino_small = initcompose(cs, csn);
	Item capuchino_small = inititem("capuchino_small", 150, comp_capuchino_small);
	sold cap_small = initsold(capuchino_small, 4);

	std::vector<resource> hc = { chocolate, milk, sugar };
	std::vector<unsigned int> hcn = { 50, 90, 30 };
	compose comp_hot_chocolate = initcompose(hc, hcn);
	Item hot_chocolate = inititem("hot_chocolate", 200, comp_hot_chocolate);
	sold hot_choc = initsold(hot_chocolate, 7);

	action one = initaction(coffee, 100, 1);
	action two = initaction(milk, 150, 0);

	std::vector<resource> sclad = { coffee, milk, sugar, sirop_cherry, chocolate, sirop_chocolate, sirop_nuts, cacao };
	std::vector<Item> menu = {capuchino_small, hot_chocolate};
	std::vector<action> acts = {one, two};
	showres(sclad);
	showmenu(menu);
	acthist(acts);
	showing(capuchino_small);
	std::vector<sold> mondaysold = { hot_choc, cap_small };
	solddata(mondaysold);

	sostdel(comp_capuchino_small, 1);
	sostadd(comp_capuchino_small, sirop_cherry, 20);
	costchange(capuchino_small, 180);
	showing(capuchino_small);
	sold cherry_small_cap = initsold(capuchino_small, 10);
	std::vector<sold> demonstrate = { cherry_small_cap };
	solddata(demonstrate);
	showres(sclad);
	resource newres = consresinit();
}