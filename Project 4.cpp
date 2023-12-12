//#include <iostream>
//#include <vector>
//#include <string>
//
//
//using namespace std;
//
//struct resource
//{
//	string name;
//	unsigned int kolvo;
//};
//struct compose
//{
//	vector <resource> sost;
//	vector <unsigned int> n;
//};
//struct Item
//{
//	string name;
//	unsigned int cost;
//	compose* p;
//};
//struct sold
//{
//	Item item;
//	unsigned int kolvo;
//	int profit;
//};
//struct action
//{
//	resource resource;
//	unsigned int kolvo;
//	bool f;
//};
//
//Item inititem(string name, unsigned int cost, compose compose) {
//	Item item;
//	item.name = name;
//	item.cost = cost;
//	item.p = &compose;
//}
//resource initresource(string name, unsigned int kolvo) {
//	resource resource;
//	resource.name = name;
//	resource.kolvo = kolvo;
//}
//compose initcompose(vector<resource> m, vector< unsigned int> n) {
//	compose compose;	
//	int i;
//	for (i = 0; i < (m.size()); i++) {
//		compose.sost[i] = m[i];
//	}
//}
//sold initsold(Item item, unsigned int kolvo){
//	sold sold;
//	sold.item = item;
//	sold.kolvo = kolvo;
//	sold.profit = kolvo * (sold.item.cost);
//	int i, k;
//	k = sold.item.p->sost.size();
//	for (i = 0; i < k; i++) {
//		(sold.item.p->sost[i].kolvo) -= sold.item.p->n[i];
//	}
//}
//action initaction(resource resource, unsigned int b, bool f){
//	action action;
//	action.resource = resource;
//	action.kolvo = b;
//	action.f = f;
//	if (f) {action.resource.kolvo += b;}
//	else{action.resource.kolvo -= b;}
//}
//void showres(vector<resource> m) {
//	cout << "Resourses:";
//	for (int i = 0; i < m.size(); i++) {
//		cout << m[i].name + " " + to_string(m[i].kolvo)+"\n";
//	}
//}
//void showmenu(vector <Item> m){
//	cout << "Menu:";
//	for (int i = 0; i < m.size(); i++) {
//		cout << m[i].name + " " + to_string(m[i].cost) + "\n";
//	}
//}
//void acthist(vector<action> m){
//	for (int i = 0; i < m.size(); i++) {
//		if (m[i].f) {
//			cout << m[i].resource.name + " " + to_string(m[i].kolvo) + "\n";
//		}else{ cout << m[i].resource.name + " " + to_string(m[i].kolvo*(-1)) + "\n"; }
//	}
//}
//void showing(Item it){
//	int i;
//	for (i = 0; i < it.p->sost.size(); i++) {
//		cout << it.p->sost[i].name + " " + to_string(it.p->sost[i].kolvo) + "\n";
//	}
//}
//void solddata(vector<sold> m){
//	int i, k, summ = 0;
//	k = m.size();
//	for (i = 0; i < k; i++) {
//		cout << m[i].item.name + " - " + to_string(m[i].kolvo) + ": " + to_string(m[i].profit)+"\n";
//		summ += m[i].profit;
//	}cout << "Total:" + to_string(summ) << endl;
//}
//void costchange(Item p, unsigned int b) { p.cost = b; }
//void sostadd(compose k, resource res,  unsigned int n){
//		k.sost.push_back(res);
//		k.n.push_back(n);
//}
//void sostdel(compose k, unsigned int b) {
//	for (int i = 0; i < b;i++) {
//		k.sost.pop_back();
//		k.n.pop_back();
//	}
//}
//resource consresinit() {
//	resource res;
//	cout << "Input resource name:";
//	cin >> res.name;
//	cout << "Input resource quantity:";
//	cin >> res.kolvo;
//}