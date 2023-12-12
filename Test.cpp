#include "Header1.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
using namespace std;

int main() {
	std::vector<resource*> sclad = {};
	std::vector<Item*> menu = {};
	std::vector<action> actions = {};
	std::vector<sold> soldhist = {};
	resource milk, coffee, sugar, chokolate, sirop;
	milk.setresource("milk", 30, &sclad);
	chokolate.setresource("chokolate", 200, &sclad);
	coffee.setresource("coffee", 50, &sclad);
	sirop.setresource("sirop", 20, &sclad);
	sugar.consresinit(&sclad);
	std::vector<resource> cof = { coffee, milk, sugar };
	std::vector<double> cs = { 0.060, 0.090, 0.060 };
	std::vector<double> cb = { 0.10, 0.150, 0.10 };
	std::vector<double> am = { 0.15, 0.0, 0.060 };
	compose capuch_small, capuch_big, amer;
	capuch_small.setcompose(cof, cs);
	capuch_big.setcompose(cof, cb);
	amer.setcompose(cof, am);
	Item cappuchino_small, cappuchino_big, americano;
	cappuchino_big.setitem("cappuchino_big", 180, &capuch_big, &menu);
	cappuchino_small.setitem("cappuchino_small", 100, &capuch_small, &menu);
	americano.setitem("americano", 120, &amer, &menu);
	cout << milk.showres();
	cout << cappuchino_big.showsost();
	cappuchino_big.costchange(220);
	cappuchino_big.sostdel(1);
	cappuchino_big.sostadd(sirop, 0.03);
	cout << cappuchino_big.showsost();
	cout << to_string(cappuchino_big.getcost())+"\n";

	sold one, two;
	one.setsold(cappuchino_big, 5, &soldhist);
	two.setsold(americano, 7, &soldhist);
	cout<<one.soldinfo(soldhist);
	cout << milk.showres();

	action first, second;
	first.setaction(milk, 2, 0, &actions);
	second.setaction(chokolate, 10, 1, &actions);
	cout << second.acthist();
	cout << first.acthist();
	cout << milk.showres();
}