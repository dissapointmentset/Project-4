#pragma once
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class resource {
private:
	string name;
	double kolvo;
public:
	string getname() {
		return name;
	}
	unsigned int getkol() {
		return kolvo;
	}
	void setresource(string imya, double kolich) {
		name = imya;
		kolvo = kolich;
	}
	string showres() {
		string outp;
		outp = this->name + " : " + to_string(this->kolvo) + "\n";
		return outp;
	}	
	void consresinit() {
		cout << "Input resource name:";
		cin >> this->name;
		cout << "Input resource quantity:";
		cin >> this->kolvo;
	}
	void reducekol(double a) {
		this->kolvo -= a;
	}
	void upkol(double a) {
		this->kolvo += a;
	}
};

class compose
{
public:
	vector <resource> sost;
	unsigned int k;
	vector <double> n;
	void setcompose(vector <resource> cons, vector <double> m) {
		int i = 0;
		for (i; i < cons.size(); i++) {
			sost.push_back(cons[i]);
			n.push_back(m[i]);
		}k = cons.size();
	}
	unsigned int getlen() {
		return k;
	}void reduselen(unsigned int a) {
		k-=a;
	}
	void uplen() {
		k+=1;
	}
};

class Item
{
private:
	string name;
	unsigned int cost;
	compose sost;
public:
	void setitem(string imya, unsigned int price, compose *n) {
		name = imya;
		cost = price;
		sost = *n;
	}
	string showsost() {
		string outp="";
		for (int i = 0; i < this->sost.n.size(); i++) {
			outp += (this->sost.sost[i].getname() + ": " + to_string(this->sost.n[i]) + "\n");
		}return outp;
	}
	unsigned int getcost() {
		return this->cost;
	}
	string getname() {
		return name;
	}
	compose* getsost() {
		return &sost;
	}
	void costchange(unsigned int b) {
		cost = b;
	}
	void sostadd( resource res, double k) {
		this->sost.sost.push_back(res);
		this->sost.n.push_back(k);
		this->sost.uplen();
	}
	void sostdel(int b) {
		for (int i = 0; i < b; i++) {
			this->sost.sost.pop_back();
			this->sost.n.pop_back();
		}this->sost.reduselen(b);
	}
};

class sold
{
private:
	Item item;
	unsigned int kolvo;
	int profit;
public:
	void setsold(Item coffee, unsigned int kolich, vector <sold> *soldhist) {
		item = coffee;
		kolvo = kolich;
		profit = kolich * coffee.getcost();
		for (int i = 0; i < item.getsost()->getlen();i++) {
			item.getsost()->sost[i].reducekol(item.getsost()->n[i] * kolvo);
		}soldhist->push_back(*this);		
	}string soldinfo(vector <sold> soldhist) {
		int summ=0;
		string outp = "";
		for (int i = 0; i < soldhist.size(); i++) {
			outp += soldhist[i].item.getname() + ": " + to_string(soldhist[i].kolvo) + " = " + to_string(soldhist[i].profit) + "\n";
			summ += soldhist[i].profit;
		}outp += "profit:" + to_string(summ)+"\n"; return outp;
	}
};
class action
{
private:
	resource res;
	double kolvo;
	int f;
public:
	int getacttype() { return f; }
	void setaction(resource a, unsigned int b, bool flag, vector <action> *acthist) {
		res = a;
		kolvo = b;
		f = flag;
		acthist->push_back(*this);
		if (f) {
			res.upkol(kolvo);
		}
		else { res.reducekol(kolvo); }
	}
	string acthist() {
		string outp = "";
		if (this->getacttype() == 1) {
				outp += res.getname() + ": " + to_string(kolvo) + "\n";
			}
			else { outp += res.getname() + ": " + to_string(kolvo * (-1)) + "\n"; }
		return outp;
	}
};
//Item inititem(string name, unsigned int cost, compose a);
//resource initresource(string name, unsigned int kolvo);
//sold initsold(Item item, unsigned int kolvo);
//action initaction(resource a, unsigned int b, bool f);
//compose initcompose(vector<resource> m, vector <unsigned int> n);
//void showres(vector<resource> m);
//void showmenu(vector <Item> m);
//void acthist(vector <action> m);
//void showing(Item p);
//void solddata(vector <sold> m);
//void costchange(Item p, unsigned int b);
//void sostadd(compose comp, resource r, unsigned int b);
//void sostdel(compose comp, unsigned int b);
//resource consresinit();