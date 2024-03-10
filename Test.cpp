#include "Header1.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
using namespace std;

int main() {
	std::vector<resource> sclad = {};
	std::vector<Item> menu = {};
	std::vector<action*> actions = {};
	std::vector<sold> soldhist = {};
	resource milk, coffee, sugar, chokolate, sirop;
	milk.setresource("milk", 30);
	sclad.push_back(milk);
	chokolate.setresource("chokolate", 200);
	sclad.push_back(chokolate);
	coffee.setresource("coffee", 50);
	sclad.push_back(coffee);
	sirop.setresource("sirop", 20);
	sclad.push_back(sirop);
	sugar.consresinit();
	sclad.push_back(sugar);
	std::vector<resource*> cof = { &coffee, &milk, &sugar };
	std::vector<double> cs = { 0.060, 0.090, 0.060 };
	std::vector<double> cb = { 0.10, 0.150, 0.10 };
	std::vector<double> am = { 0.15, 0.0, 0.060 };
	compose capuch_small, capuch_big, amer;
	capuch_small.setcompose(cof, cs);
	capuch_big.setcompose(cof, cb);
	amer.setcompose(cof, am);
	Item cappuchino_small, cappuchino_big, americano;
	cappuchino_big.setitem("cappuchino_big", 180, capuch_big);
	menu.push_back(cappuchino_big);
	cappuchino_small.setitem("cappuchino_small", 100, capuch_small);
	menu.push_back(cappuchino_small);
	americano.setitem("americano", 120, amer);
	menu.push_back(americano);
	cout << chokolate.showres();
	cout << milk.showres(); cout << "\n";
	cout << cappuchino_big.showsost();
	cout << "\n";
	cappuchino_big.costchange(220);
	cappuchino_big.sostdel(1);
	cappuchino_big.sostadd(&sirop, 0.03);
	cout << cappuchino_big.showsost();
	cout << to_string(cappuchino_big.getcost())+"\n";

	sold one, two;
	one.setsold(cappuchino_big, 8, soldhist);
	soldhist.push_back(one);
	two.setsold(americano, 7, soldhist);
	soldhist.push_back(two);
	cout<<one.soldinfo(soldhist);
	cout << milk.showres();
	cout << chokolate.showres();
	cout << "\n";

	action first, second;
	first.setaction(&milk, 2, 0, actions);
	second.setaction(&chokolate, 10, 1, actions);
	cout << second.acthist();
	cout << first.acthist(); cout << "\n";
	cout << milk.showres();
	cout << chokolate.showres();
}