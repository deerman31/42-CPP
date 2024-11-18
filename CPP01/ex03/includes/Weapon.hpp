#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon {
	public:
		Weapon(void);
		Weapon(std::string name);
		const std::string	&getType(void);
		void				setType(std::string name);
	private:
		std::string	_name;
};

#endif

/*
- プライベート属性の型（文字列）。
- 型への定数参照を返す getType() メンバ関数。
- パラメータとして渡された新しい型を使って型を設定するsetType()メンバ関数。
次に、2 つのクラスを作成します： HumanA と HumanB です。どちらもWeaponと名前を持っています。また、attack()というメンバ関数もあります：
- <name> attacks with their <weapon type>
<name>は<weapon type>で攻撃します。
*/