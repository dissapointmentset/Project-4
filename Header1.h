#pragma once
#include <iostream>
#include <string>
#include <vector>


using namespace std;

class resource {
protected:
	string name;
	double kolvo;
public:
	resource(string imya, double kolich) {
		this->name = imya;
		this->kolvo = kolich;
	}
	string getname() {
		return name;
	}
	unsigned int getkol() {
		return kolvo;
	}
	ostream& operator <<(ostream& outp) {
		outp << this->name + " : " + to_string(this->kolvo) + "\n";
		return outp;
	}	
	virtual void consresinit() {
		cout << "Input resource name:";
		cin >> this->name;
		bool w;
		do {cout << "Input resource quantity:";
		w = true;
			cin >> this->kolvo;//try catch блоки для защиты ввода числа
			try
			{
				if (this->kolvo < 0) {
					throw exception("Amount of resource can not be lower than 0\n");
				}
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
				w = false;
			}
		} while (!w);
	}
	void reducekol(double a) {
		this->kolvo -= a;
	}
	void upkol(double a) {
		this->kolvo += a;
	}
	resource & operator ++() {
		this->kolvo++;
		return *this;
	}
	resource& operator ++(int num) {
		this->kolvo++;
		return *this;
	}
	void operator =(const resource &other) {
		
		this->kolvo = other.kolvo;
		this->name = other.name;
	}
};
class lot :public resource {
private:
	double cost;
public:
	lot(string name, double kolvo, double cost) :resource(name, kolvo) {
		this->cost = cost;
	}
	string getname() {
		return name;
	}
	unsigned int getkol() {
		return kolvo;
	}
	double getcost() {
		return cost;
	}
	ostream& operator <<(ostream& outp) {
		outp << this->name + " " + to_string(this->cost) + "p : " + to_string(this->kolvo) + "\n";
		return outp;
	}
	void reducekol(double a) {
		this->kolvo -= a;
	}
	void upkol(double a) {
		this->kolvo += a;
	}
	void operator = (const lot &other) {
		this->kolvo = other.kolvo;
		this->name = other.name;
		this->cost = other.cost;
	}
	void consresinit() {
		resource::consresinit();
		/*cout << "Input lot name:";
		cin >> this->name;
		bool w;
		do {
			cout << "Input number of lots:";
			w = true;
			cin >> this->kolvo;
			try
			{
				if (this->kolvo < 0) {
					throw exception("Amount of resource can not be lower than 0\n");
				}
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
				w = false;
			}
		} while (!w);*/
		cout << "Input price: ";
		cin >> this->cost;
	}
};
class compose
{
public:
	vector <resource*> sost;
	unsigned int k;
	vector <double> n;
	void setcompose(vector <resource*> cons, vector <double> m) {
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
class absitem {//абстрактный класс
public :
	virtual void costchange(unsigned int) = 0;
	virtual unsigned int getcost() = 0;
	virtual compose getsost() = 0;
};
class Item:public absitem
{
private:
	string name;
	unsigned int cost;
	compose sost;
public:
	void setitem(string imya, unsigned int price, compose n) {
		this->name = imya;
		this->cost = price;
		this->sost = n;
	}
	friend string showsost(Item item);

	compose getsost() override
	{
		return sost;
	}
	unsigned int getcost() override
	{
		return cost;
	}
	string getname() {
		return name;
	}
	void costchange(unsigned int b) override {
		cost = b;
	}
	void sostadd(resource* res, double k)
	{
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
	ostream& operator <<(ostream& outp) {
		outp << showsost(*this) + "\n";
		return outp;
	}

};
string showsost(Item item) {//дружественная функция
	string outp = "";
	for (int i = 0; i < item.sost.n.size(); i++) {
		outp += (item.sost.sost[i]->getname() + ": " + to_string(item.sost.n[i]) + "\n");
	}return outp;
}
class sold
{
protected:	
	unsigned int kolvo;
	int profit;
private:
	Item item;
public:
	static int counter;
	void setsold(Item coffee, unsigned int kolich, sold* ptr) {
		this->item = coffee;
		this->kolvo = kolich;
		this->profit = kolich * coffee.getcost();
		for (int i = 0; i < item.getsost().getlen(); i++) {
			item.getsost().sost[i]->reducekol(item.getsost().n[i] * kolvo);
		}ptr[counter] = *this; counter++;
	}static string soldinfo(sold* ptr, int str, int cols) {
		int summ = 0;
		string outp = "";
		for (int i = 0; i < str * cols; i++) {
			outp += ptr[i].item.getname() + ": " + to_string(ptr[i].kolvo) + " = " + to_string(ptr[i].profit) + "\n";
			summ += ptr[i].profit;
		}outp += "profit:" + to_string(summ) + "\n"; return outp;
	}
	int* operator +(sold& other) {
		int i;
		i = this->profit + other.profit;
		return &i;
	}

};
class solditem :public sold {
private:
	lot *obj;
public:
	void setsoldlot(lot *coffee, unsigned int kolich) {
		this->obj = coffee;
		this->kolvo = kolich;
		this->profit = kolich * coffee->getcost();
		coffee->reducekol(kolvo);
	}
	static string soldinfo(vector<solditem>ptr) {
		int summ = 0;
		string outp = "";
		//cout <<"\n" + to_string(ptr.size()) + "\n";
		for (int i = 0; i < ptr.size(); i++) {
			outp += ptr[i].obj->getname() + ": " + to_string(ptr[i].kolvo) + " = " + to_string(ptr[i].profit) + "\n";
			summ += ptr[i].profit;
		}outp += "profit:" + to_string(summ) + "\n"; return outp;
	}
};
int sold::counter = 0;

template<typename T>//шаблон класса
class action
{
private:
	resource* res;
protected:
	T kolvo;
	int f;
public:
	static int count;
	int getacttype() { return f; }
	void setaction(resource* a, T b, int flag, action arr[]) {
		this->res = a;
		this->kolvo = b;
		this->f = flag;
		arr[count] = *this;
		count++;
		if (f) {
			res->upkol(kolvo);
		}
		else { res->reducekol(kolvo);}
	}
	static void postavki() { 
		cout << "\nPostavki: " + to_string(count)+"\n";
	}
	string acthist() {
		string outp = "";
		if (getacttype() > 0) {
			outp += res->getname() + ": " + to_string(kolvo) + "\n";
		}
		else { outp += res->getname() + ": " + to_string(kolvo * (-1)) + "\n"; }
		return outp;
	}
	ostream& operator <<(ostream& outp) {
		outp << this->acthist() + "\n";
		return outp;
	}
}; 
class actionlot :public action<int> {
private:
	lot *item;
public:
	static int counter;
	void setactionitem(lot *a, int b, int flag, vector<actionlot> arr) {
		this->item = a;
		this->kolvo = b;
		this->f = flag;
		arr.push_back(*this);
		if (f) {
			item->upkol(kolvo);
		}
		else { item->reducekol(kolvo); }
	}
	string acthist() {
		string outp = "";
		if (getacttype() > 0) {
			outp += item->getname() + ": " + to_string(this->kolvo) + "\n";
		}
		else { outp += item->getname() + ": " + to_string(this->kolvo * (-1)) + "\n"; }
		return outp;
	}
	ostream& operator <<(ostream& outp) {
		outp << this->acthist() + "\n";
		return outp;
	}
	static void postavki() {
		cout << "\nPostavki tovarov : " + to_string(counter) + "\n";
	}
}; int action<int>::count = 0;
int actionlot::counter = 0;