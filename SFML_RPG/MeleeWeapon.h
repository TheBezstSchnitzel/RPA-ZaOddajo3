#pragma once

#include "Weapon.h"

class MeleeWeapon : public Weapon{
private:

protected:

public:
	MeleeWeapon(unsigned level, unsigned damageMin, unsigned damageMax, unsigned range,
		unsigned value, 
		std::string texture_file);
	virtual ~MeleeWeapon();

	//Funkcije
	virtual MeleeWeapon* clone() = 0;
	virtual void generate(const unsigned levelMin, const unsigned levelMax);

	virtual void update(const sf::Vector2f& mouse_pos_view, const sf::Vector2f center) = 0;
	virtual void render(sf::RenderTarget& target, sf::Shader* shader) = 0;
};