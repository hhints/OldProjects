#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp


//method let user hit direction key
void TunnelMan::doSomething() {

	// if dead return immedatailty 
	if (!isAlive()) {
		return;
	}
	// make a digging sound for tunnnel man 

	if (getWorld()->dig(getX(), getY())) {
		//GameController::getInstance().playSound(SOUND_DIG);
		
	}
	

	//get user input and determine action 

	int ch;
	//get cordindates
	int x = getX();
	int y = getY();

	if (getWorld()->getKey(ch) == true) {
		//uuser hit a key this tick!
		switch (ch) {
		case KEY_PRESS_ESCAPE:
			makeDead();
			break;
		case KEY_PRESS_SPACE:
			// add squirt infront of the player 
			// add squier and decreasse water level
			if (m_waterSquirt != 0) {
				if (getDirection() == right && getX() < 60) {
					getWorld()->fireSquirt(getX() + 4, getY(), right);
					//decrease wayer level
					m_waterSquirt--;
				}

				if (getDirection() == left && getX() >0) {
					getWorld()->fireSquirt(getX() - 4, getY(), left);
					
					m_waterSquirt--;
				}

				if (getDirection() == up && getY() < 60) {
					getWorld()->fireSquirt(getX(), getY()+4, up);

					m_waterSquirt--;
				}

				if (getDirection() == down && getX() > 0) {
					getWorld()->fireSquirt(getX(), getY()-4, down);

					m_waterSquirt--;
				}

			}


			break;

		case KEY_PRESS_LEFT:
			//move player to the left
			moveTo(x + 3, y);
			break;
		case KEY_PRESS_RIGHT:
			//move player to the right
			moveTo(x - 3, y);
			break;

		case KEY_PRESS_TAB:
			if (m_goldNuggets != 0) {
				getWorld()->dropGold(getX() , getY());
				m_goldNuggets--;
			}

			break;
			//if press Z show all hidden objects and decrease sonar
		case'z':
			if (m_sonarCharge != 0) {
				getWorld()->showHidden(getX(), getY());
				m_sonarCharge--;
			}
	
		default:
			break;
		}
	}
	
}

bool TunnelMan::giveup() {
	makeDead();
	//GameController::getInstance().playSound(SOUND_PLAYER_GIVE_UP);
	return true;
}


