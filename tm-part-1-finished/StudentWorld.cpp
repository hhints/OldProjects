#include "StudentWorld.h"
#include <string>
#include<iomanip>
#include<cmath>
#include<sstream>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp


StudentWorld::~StudentWorld()
{
}
int StudentWorld::init()
{
	// initialized
	/*
	 * create  oilfeilds level
	 * populate with :  Earth, Boulders, Barrels of Oil, and Gold Nuggets 
	 */
	m_TunnelMan = new TunnelMan(this);

B = min(int(getLevel() / 2 + 2), 9);
// intilize Gold Nugget 

G = max(int(5 - getLevel() / 2), 2);

//initilize oil barrel
L = min(int(2 + getLevel()), 21);

//initilize Earth 

for (int i = 0; i < 64; i++)
{
	for (int j = 0; j < 60; j++) {
		if (i>= 30 && i <= 33 && i > 3)
		{
			m_eartharr[i] = nullptr;
		}
		else {
			m_eartharr[i] = new Earth(i, j, this);
			m_Display[i][j] = 'E';
		}
}
}


	return GWSTATUS_CONTINUE_GAME;
}

/* move()
	{
		// This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
		// Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
		decLives();
		return GWSTATUS_PLAYER_DIED;
	}
	*/
// during each tick ask TM to do something 
int StudentWorld::move()
{
	updateDisplayText();
	// do something 
	m_TunnelMan->doSomething();
//Give each Actor a chance to do something 
	vector<Actor*>::iterator it = m_actors.begin();
	for (it=m_actors.begin(); it != m_actors.end(); it++)
	{
		//if curr actor is alive do somethinf 
		if((*it)->isAlive()){
			(*it)->doSomething();
		}
		// ask each actor to do something (e.g. move) 

		if (isPlayerDeadInCurrTick () == true) {
			decLives();
			return GWSTATUS_PLAYER_DIED;
		}
		if (playerCompletedCurrLevel() == true) {
			return GWSTATUS_FINISHED_LEVEL;
		}
	}

	decLives();

	return GWSTATUS_CONTINUE_GAME;


	//return GWSTATUS_PLAYER_DIED;
}
//check player dead status

bool StudentWorld::isPlayerDeadInCurrTick() {
	if (m_TunnelMan->isAlive()) {
		return false;
	}
	
	return true;


}
//check if pass curr level 
bool StudentWorld::playerCompletedCurrLevel() {
	if (numBarrelOil == 0) {
		//play sound finished 
		//GameController::getInstance().playSound(SOUND_FINISHED_LEVEL);
	
		return true;

	}
	return false;
}

bool StudentWorld::fireSquirt(int x, int y, GraphObject::Direction currDirection)
{

	return false;
}

bool StudentWorld::dig(int x, int y) {
	return true;
}

// update curr text on display
void StudentWorld::updateDisplayText() {
	int score, lives, level;
	int health = m_TunnelMan->getCurrHealth();
	int squirts = m_TunnelMan->getSquirtCount();
	int gold = m_TunnelMan->getGoldNuggetCount();
	int barrelsLeft = m_TunnelMan->getLeftOverBarrelCount();
	int sonar = m_TunnelMan->getSonarChargeCount();
	score = getScore();
	lives = getLives();
	level = getLevel();
	
	// Next, create a string from your statistics, of the form:
// Lvl: 52 Lives: 3 Hlth: 80% Wtr: 20 Gld: 3 Oil Left: 2 Sonar: 1 Scr: 32100
	ostringstream oss;



	oss= formateText(level, lives, health,squirts, gold, barrelsLeft, sonar, score);
	string s = oss.str();
	setGameStatText(s);


}

ostringstream StudentWorld::formateText(int level, int lives, int health, int squirts, int gold, int barrelsLeft, int sonar, int score) {
	ostringstream oss;
	oss.setf(ios::fixed);
	oss << "Lvl:" << setw(2) << setfill(' ') << level
	<< "Hlth:" << setw(3) << setfill(' ') << lives<<"%";
	oss << "Wtr:" << setw(2) << setfill(' ') << squirts;
	oss << "Gld:" << setw(2) << setfill(' ') << gold;
	oss << "Oil Left:" << setw(2) << setfill(' ') << barrelsLeft;
	oss << "Sonar:" << setw(2) << setfill(' ') << sonar;
	oss << "Scr:" << setw(2) << setfill(' ') << score;
	return oss;
}
 void StudentWorld::cleanUp()
 {
	 //delete Tunnelman 
	 delete m_TunnelMan;
	 //delete earth 
	 for (int i = 0; i < numEarth; i++) {
		 delete m_eartharr[i];
		 m_eartharr[i] = nullptr;

	 }

	 vector<Actor*> ::iterator it = m_actors.begin();
	 while (it != m_actors.end()) {
		 delete (*it);
		 it++;
	 }

 }

 bool StudentWorld::showHidden(int x, int y) {
	 return true;
 }

 bool StudentWorld::dropGold(int x, int y) {
	 return true;
 }