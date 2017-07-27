#include <string>
#include "../Panel/Panel.h"
#include "../CheckList/CheckList.h"
#include "../ComboBox/ComboBox.h"
#include "../Graphics/Graphics.h"
#include "../TextBox/TextBox.h"
#include "../RadioList/RadioList.h"
#include "../EventEngine/EventEngine.h"
#include "../NumericBox/NumericBox.h"
#include "../MessegeBox/MsgBox.h"

using namespace std;

struct MyListener : public MouseListener
{
	MyListener(Control &c) : _c(c) { }
	void mousePressed(Control& b, short x, short y, bool isLeft)
	{
		//Panel::toggleMsgBox();
		_c.show();
		Control::setFocus(&_c);
	}
private:
	Control &_c;
};


int main(void){

	Label lName(20, "Name: ");
	//lName.setText("Name: ");

	Label lAddress(20, "Address:");
	//lAddress.setValue("Address:");
	Label lCountry(20, "Counrty:");
	//lCountry.setValue("Counrty:");
	Label lSex(20, "Sex:");
	//lSex.setValue("Sex:");
	Label lInterests(20, "Interests:");
	//lInterests.setValue("Interests:");
	Label lAge(20, "Age:");
	//lAge.setValue("Age:");
	TextBox tName(20);
	tName.setValue("Sherlock Holmes");
	tName.setBorder(BorderType::Single);
	TextBox tAddress(25);
	tAddress.setValue("221B Baker Street, London");
	tAddress.setBorder(BorderType::Single);
	ComboBox cCountry(20, { "Israel", "Great Britain", "United States" });
	cCountry.setSelectedIndex(1);
	cCountry.setBorder(BorderType::Single);
	RadioList rSex(8, 15, { "Male", "Female" });
	rSex.setBorder(BorderType::Single);
	CheckList clInterests(11, 20, { "Sports", "Books", "Movies" });
	clInterests.selectIndex(1);
	clInterests.setBorder(BorderType::Single);
	NumericBox nAge(15, 18, 120);
	nAge.setValue(23);
	nAge.setBorder(BorderType::Single);

	MsgBox msgBox(15, 20);
	msgBox.hide();
	msgBox.setBorder(BorderType::Double);
	msgBox.setBackGround(BackgroundColor::White);
	msgBox.setForeground(ForegroundColor::Purple);

	MyListener* listener = new MyListener(msgBox);
	Button bSubmit(10, "Submit");
	bSubmit.addListener(*listener);
	bSubmit.setBorder(BorderType::Double);


	Panel main(50, 70);
	main.addControl(&msgBox, 15, 15);
	main.addControl(&lName, 1, 2);
	main.addControl(&lAddress, 1, 5);
	main.addControl(&lCountry, 1, 8);
	main.addControl(&lSex, 1, 13);
	main.addControl(&lInterests, 1, 21);
	main.addControl(&lAge, 1, 32);
	main.addControl(&tName, 25, 2);
	main.addControl(&tAddress, 25, 5);
	main.addControl(&cCountry, 25, 8);
	main.addControl(&rSex, 25, 13);
	main.addControl(&clInterests, 25, 21);
	main.addControl(&nAge, 25, 32);

	main.addControl(&bSubmit, 1, 35);
	Control::setFocus(&tName);
	EventEngine engine;
	engine.run(main);
	return 0;

}