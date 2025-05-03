#include "Automata.h"

int main() {
	Automata machine = Automata();
	machine.on();
	machine.getMenu();
	machine.coin(20);
	machine.coin(15);
	machine.choice("Americano");
}
