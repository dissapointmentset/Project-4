#include <stdio.h>
#include <string.h>
#include <Project4.cpp>

Item inititem(char name[50] = "medium capuchino", unsigned int cost) {
	Item capuchinom;
	capuchinom.name = name;
	capuchinom.cost = 180;
}
resource initresource(unsigned int kolvo) {
	resource coffee;
	coffee.kolvo = 5000;
}
resource initresource(unsigned int kolvo) {
	resource milk;
	milk.kolvo = 10000;
}
resource initresource(unsigned int kolvo) {
	resource sugar;
	sugar.kolvo = 2000;
}
resource m[3] = [coffee, milk, sugar];

compose initcompose(* capuchino, m[], unsigned int n[]) {

}