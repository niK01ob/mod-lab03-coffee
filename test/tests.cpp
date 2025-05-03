#include <gtest/gtest.h>
#include "Automata.h"

TEST(AutomataTest, StartState) {
	Automata a = Automata();
	ASSERT_EQ(STATES::OFF, a.getState());
}

TEST(AutomataTest, CoinWhenOff) {
	Automata a = Automata();
	a.coin(10);
	ASSERT_EQ(STATES::OFF, a.getState());
	ASSERT_EQ(0, a.getCash());
}

TEST(AutomataTest, ChooseWhenOff) {
	Automata a = Automata();
	a.choice("Americano");
	ASSERT_EQ(STATES::OFF, a.getState());
}

TEST(AutomataTest, CancelWhenOFF) {
	Automata a = Automata();
	a.cancel();
	ASSERT_EQ(STATES::OFF, a.getState());
	ASSERT_EQ(0, a.getCash());
}

TEST(AutomataTest, SwitchOn) {
	Automata a = Automata();
	a.on();
	ASSERT_EQ(STATES::WAIT, a.getState());
}

TEST(AutomataTest, InsertCoin) {
	Automata a = Automata();
	a.on();
	a.coin(5);
	ASSERT_EQ(STATES::ACCEPT, a.getState());
	ASSERT_EQ(50, a.getCash());
}

TEST(AutomataTest, CoinAndCancel) {
	Automata a = Automata();
	a.on();
	a.coin(50);
	a.cancel();
	ASSERT_EQ(STATES::WAIT, a.getState());
	ASSERT_EQ(50, a.getCash());
}

TEST(AutomataTest, ChooseWithoutCoins) {
	Automata a = Automata();
	a.on();
	a.choice("Americano");
	ASSERT_EQ(STATES::WAIT, a.getState());
}

TEST(AutomataTest, StateAfterCoin) {
	Automata a = Automata();
	a.on();
	a.coin(5);
	ASSERT_EQ(STATES::ACCEPT, a.getState());
	ASSERT_EQ(5, a.getCash());
}

TEST(AutomataTest, CorrectChoice) {
	Automata a = Automata();
	a.on();
	a.coin(40);
	a.choice("Americano");
	a.change();
	ASSERT_EQ(STATES::WAIT, a.getState());
	ASSERT_EQ(10, a.getCash());
}

TEST(AutomataTest, InvalidDrink) {
	Automata a = Automata();
	a.on();
	a.coin(40);
	a.choice("Americcano");
	ASSERT_EQ(STATES::WAIT, a.getState());
	ASSERT_EQ(40, a.getCash());
}

TEST(AutomataTest, SwitchOffWhenAccept) {
	Automata a = Automata();
	a.on();
	a.coin(5);
	a.off();
	ASSERT_EQ(STATES::ACCEPT, a.getState());
	ASSERT_EQ(100, a.getCash());
}

TEST(AutomataTest, MainScenario) {
	Automata a = Automata();
	a.on();
	a.coin(90);
	a.choice("Espresso");
	a.off();
	ASSERT_EQ(STATES::OFF, a.getState());
}
