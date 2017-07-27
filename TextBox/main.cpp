#include <string>
#include "../EventEngine/EventEngine.h"
#include "TextBox.h"
#include "../Panel/Panel.h"
using namespace std;


int main(int argc, char **argv)
{
	TextBox tName(20);
	Panel p(25, 50);
	tName.setValue("Sherlock Holmes sfasaf");
	tName.setBorder(BorderType::Double);
<<<<<<< HEAD
	tName.setBackGround(BackgroundColor::Red); 
=======
	tName.setBackGround(BackgroundColor::Red);
>>>>>>> f93efb7b1399c85c0040808a5f70e2655a1644a8
	tName.setForeground(ForegroundColor::Cyan);
	Control::setFocus(&tName);
	p.setBorder(BorderType::Double);
	p.addControl(&tName, 10, 20);
	EventEngine engine;
	engine.run(p);
	return 0;
}