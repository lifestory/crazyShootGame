#include "cocos2d.h"
#include"../../../../public/parameterManager/ParameterManager.h"
#include"../../Model/Constant/Constant.h"
USING_NS_CC;

#define pi 3.141592654

class Enemy :public cocos2d::Node{
public :
	/*
	默认在图的右上角生成有一个模式为2的敌人
	*/
	Enemy();
	/*
	在（_locX, _locY）处，生成一个血量被_blood，模式为_mode的敌人
	*/
	Enemy* createEnemy(float _locX, float locY, int _blood, int _mode);
	/*
	创建一个哥布林：攻击力为5。（死亡条件：一支普通箭即可击杀）
	*/
	void createEnemyOne(Enemy* _enemy);
	/*
	创建一个战士战士：近战攻击，攻击力为10。（死亡条件：两箭才能击杀）
	*/
	void createEnemyTwo(Enemy* _enemy);
	/*
	弓箭手：不会移动，但会远程攻击，攻击力为10。（死亡条件：两箭才能击杀）
	*/
	void createEnemyArrow(Enemy* _enemy);
	/*
	魔法师：远程攻击，每3秒瞬时移动一个其他位置，是最难击杀的一个，
	攻击力为15。（死亡条件：三箭才能击杀）
	*/
	void createEnemyMagic(Enemy* _enemy);

	void updateTimeToArrowAttack(float dt);

	void setBlood(int _blood);

	Sprite* death(Sprite* s, int _mode);

	int attack(Sprite* s, int _mode);

	int getPower();
	int getBlood();
	int getMode();

private:
	//初始的X，Y坐标
	float locX;
	float locY;
	//	血量
	int blood;
	/*敌人模式
	mode 0   Undefined
	mode 1   Move enemy
	mode 2   Arrow enemy
	*/
	int mode;
	int power;
};