#pragma once

class AttributeComponent{
public:
	//Leveling
	int level;
	int exp;
	int expNext;
	int attributePoints;

	//Atributi
	int vitality;
	int strength;
	int dexterity;
	int agility;
	int intelligence;
	
	//Stati
	int hp;
	int hpMax;
	int damageMin;
	int damageMax;
	int accuracy;
	int defence;
	int luck;

	//Konstruktor / Destruktor
	AttributeComponent(int level, int startHP, int maxHP);
	virtual ~AttributeComponent();

	//Funkcije
	std::string debugPrint() const;

	void loseHP(const int hp);
	void gainHP(const int hp);
	void loseEXP(const int exp);
	void gainExp(const int exp);

	const bool isDead() const;

	void updateStats(const bool reset);
	void updateLevel();

	void update();
};

