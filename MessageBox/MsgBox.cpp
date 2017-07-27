#include "MsgBox.h"


MsgBox::MsgBox(int height, int width) : Panel(height, width)
{
	setLayer(2);
	isfocusable = false;
	Label *title = new Label(width - 2, "temp");
	Label *text = new Label(width - 2, "text text text");
	Button *okBtn = new Button(width / 2, Label::makeStringInTheMiddle(width/2, "OK"));
	CloseListener *closeListener = new CloseListener(*this);
	okBtn->addListener(*closeListener);
	title->setLayer(2);
	text->setLayer(2);
	okBtn->setLayer(2);
	title->setBorder(BorderType::Single);
	text->setBorder(BorderType::Single);
	okBtn->setBorder(BorderType::Single);
	addControl(title, 1,1);//addControll return bool -> need to think what to do with that
	addControl(text,1,4);
	addControl(okBtn, (width / 4), height-4);//We want the button to be in the middle of the msgBox
}

void MsgBox::mousePressed(short x, short y, bool isLeft) {
	//check if click is in the panel limits
	if (x < this->getLeft() || (x > this->getLeft() + this->getWidth()) ||
		y < this->getTop() || (y > this->getTop() + this->getHeight())) {
		if (isVisible()){
			hide();
		}
	}

	controls[2]->mousePressed(x, y, isLeft);
}

void MsgBox::setText(string text) {
	static_cast<Label*>(controls[1])->setValue(text);
}

void MsgBox::setTitle(string text) {
	static_cast<Label*>(controls[0])->setValue(text);
}

void MsgBox::keyDown(WORD click, CHAR chr){
	if (click == VK_RETURN) {
		hide();
	}
}

void MsgBox::show(){
	Control::show();
	openMsgBtn();
}

void MsgBox::hide(){
	Control::hide();
	closeMsgBtn();
}

