#include "Header1.h"
#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
using namespace std;

int main() {
	std::vector<resource> sclad = {};
	std::vector<Item> menu = {};
	std::vector<actionlot> actions = {};
	std::vector<solditem> soldhist = {};
	sold weekly[2][2];
	action<int> arr[5];
	resource milk("milk", 30); //инициализаци€€ объектов класса resource
	
	/*milk++;
	++milk;*/
	sclad.push_back(milk);
	resource buff("chokolate", 200);
	resource chokolate("", 0);
	chokolate = buff;//демонстраци€ оператора присвоени€
	sclad.push_back(chokolate);
	resource coffee("coffee", 50);
	sclad.push_back(coffee);
	resource sirop("sirop", 20);
	sclad.push_back(sirop);
	resource sugar("", 0);
	sugar.consresinit();//инициализаци€ через крнсоль
	sclad.push_back(sugar);
	std::vector<resource*> cof = { &coffee, &milk, &sugar };//инициализаци€€ объектов класса compose
	std::vector<double> cs = { 0.060, 0.090, 0.060 };
	std::vector<double> cb = { 0.10, 0.150, 0.10 };
	std::vector<double> am = { 0.15, 0.0, 0.060 };
	compose capuch_small, capuch_big, amer;//инициализаци€€ объектов класса compose
	capuch_small.setcompose(cof, cs);
	capuch_big.setcompose(cof, cb);
	amer.setcompose(cof, am);
	lot ex("chockobar", 10, 100);
	lot chockobar("", 0, 0);
	chockobar = ex;
	lot cookie("cookie", 30, 80);
	lot cake("", 0, 0);
	resource* p = &cake;//демонстраци€ виртуальной функции через динамический объект
	p->consresinit();
	cake << cout;
	chockobar << cout;
	cookie << cout;
	Item cappuchino_small, cappuchino_big, americano;
	cappuchino_big.setitem("cappuchino_big", 180, capuch_big);//инициализаци€€ объектов класса item
	menu.push_back(cappuchino_big);
	cappuchino_small.setitem("cappuchino_small", 100, capuch_small);
	menu.push_back(cappuchino_small);
	americano.setitem("americano", 120, amer);
	menu.push_back(americano);
	chokolate << cout;
	milk<<cout; cout << "\n";
	cappuchino_big<<cout;
	cout << "\n";
	cappuchino_big.costchange(220);//демостраци€ функций класса item
	cappuchino_big.sostdel(1);
	cappuchino_big.sostadd(&sirop, 0.03);
	cappuchino_big<<cout;
	cout << to_string(cappuchino_big.getcost())+"\n";

	sold one, two, three, four;//инициализаци€€ объектов класса sold
	one.setsold(cappuchino_big, 8, (sold*)weekly);
	two.setsold(americano, 7, (sold*)weekly);
	cout << "Profit: "+to_string(*(one + two)) + "\n";
	three.setsold(cappuchino_small, 12, (sold*)weekly);
	four.setsold(americano, 3, (sold*)weekly);
	cout<<sold::soldinfo((sold*)weekly, 2, 2);
	milk<<cout;
	chokolate<<cout;
	cout << "\n";

	solditem x, y;//инициализаци€€ объектов класса solditem(дочерний класс sold)
	x.setsoldlot(&cookie, 10);
	y.setsoldlot(&chockobar, 6);
	soldhist.push_back(x);
	soldhist.push_back(y);
	cout << solditem::soldinfo(soldhist);

	cookie<<cout;
	chockobar<<cout;

	action<int> first, second;//инициализаци€€ объектов класса action
	first.setaction(&milk, 2, 0, arr);
	second.setaction(&chokolate, 10, 1, arr);
	action<int>::postavki();
	arr[1]<<cout;
	first<<cout; cout << "\n";
	milk<<cout;
	chokolate<<cout;

	actionlot a, b;//инициализаци€€ объектов класса actionlot(дочерний класс action)
	a.setactionitem(&cookie, 15, 1, actions);
	b.setactionitem(&chockobar, 2, 0, actions);
	a << cout; cout << "\n";
	b<<cout;

	cookie<<cout;
	chockobar<<cout;
}