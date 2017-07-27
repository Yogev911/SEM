#include "TextBox.h"


<<<<<<< HEAD
TextBox::TextBox(int width) : Control(width) , curserPosition(){}
=======
TextBox::TextBox(int width) : Control(width), curserPosition() {}
>>>>>>> f93efb7b1399c85c0040808a5f70e2655a1644a8

void TextBox::setValue(string val) {
	value = val.substr(0, getWidth() - 2);
	curserPosition = value.substr(0, getWidth() - 2).length() + 1;
}

string TextBox::getValue() {
	return value;
}

void TextBox::draw(Graphics& graphics, int x, int y, size_t layer) {
	if (getLayer() != layer) return;
	Control::draw(graphics, x, y, layer);
	graphics.setBackground(graphics.convertToColor(getBackGround()));
	graphics.setForeground(graphics.convertToColor(getForeground()));
	string toPrint = value.substr(0, getWidth() - 2);
	if (toPrint.length() < getWidth() - 2) {
		toPrint = toPrint + string(getWidth() - 2 - toPrint.length(), ' ');
	}
	graphics.write(getBodyLeft(), getBodyTop(), toPrint);
	if (isFocus()) {
<<<<<<< HEAD
		if(Control::getFocus() == this) graphics.setCursorVisibility(true);
	} 
=======
		if (Control::getFocus() == this) graphics.setCursorVisibility(true);
	}
>>>>>>> f93efb7b1399c85c0040808a5f70e2655a1644a8
	graphics.resetColors();
}

int TextBox::getCurserPosition() {
	return curserPosition;
}

<<<<<<< HEAD
void TextBox::moveCurser(Graphics g){
	if (getCurserPosition() > getWidth()-2){
		g.moveTo(getBodyLeft() + getCurserPosition() - 2, getBodyTop());
	}
	else if (curserPosition == 1){
		g.moveTo(getBodyLeft(), getBodyTop());
	} else {
=======
void TextBox::moveCurser(Graphics g) {
	if (getCurserPosition() > getWidth() - 2) {
		g.moveTo(getBodyLeft() + getCurserPosition() - 2, getBodyTop());
	}
	else if (curserPosition == 1) {
		g.moveTo(getBodyLeft(), getBodyTop());
	}
	else {
>>>>>>> f93efb7b1399c85c0040808a5f70e2655a1644a8
		g.moveTo(getBodyLeft() + getCurserPosition() - 1, getBodyTop());
	}
}

void TextBox::keyDown(WORD kind, CHAR c) {

	switch (kind)
	{
<<<<<<< HEAD
		case VK_DOWN:
		case VK_UP:
		case VK_RETURN:
			break;

		case VK_RIGHT:
			moveRight();
			break;

		case VK_LEFT:
			moveLeft();
			break;

		case VK_RWIN:
			moveRight();
			break;

		case VK_LWIN:
			moveLeft();
			break;

		case VK_BACK:
			deleteLeft();
			break;

		case VK_DELETE:
			deleteRight();
			break;

		default:
			addCharecter(c);
			break;
	}
}

void TextBox::mousePressed(short x, short y, bool b){
=======
	case VK_DOWN:
	case VK_UP:
	case VK_RETURN:
		break;

	case VK_RIGHT:
		moveRight();
		break;

	case VK_LEFT:
		moveLeft();
		break;

	case VK_RWIN:
		moveRight();
		break;

	case VK_LWIN:
		moveLeft();
		break;

	case VK_BACK:
		deleteLeft();
		break;

	case VK_DELETE:
		deleteRight();
		break;

	default:
		addCharecter(c);
		break;
	}
}

void TextBox::mousePressed(short x, short y, bool b) {
>>>>>>> f93efb7b1399c85c0040808a5f70e2655a1644a8
	Control::mousePressed(x, y, b);
}


<<<<<<< HEAD
void TextBox::moveRight(){
	int x = getBodyLeft() + getWidth();
	if (getBodyLeft() + curserPosition > getBodyLeft() +  getWidth() - 3) return;
	curserPosition++;
}

void TextBox::moveLeft(){
	if (curserPosition ==  1) return;
	curserPosition--;
}

void TextBox::deleteLeft(){
=======
void TextBox::moveRight() {
	int x = getBodyLeft() + getWidth();
	if (getBodyLeft() + curserPosition > getBodyLeft() + getWidth() - 3) return;
	curserPosition++;
}

void TextBox::moveLeft() {
	if (curserPosition == 1) return;
	curserPosition--;
}

void TextBox::deleteLeft() {
>>>>>>> f93efb7b1399c85c0040808a5f70e2655a1644a8
	if (curserPosition == 1 || !value.length()) {
		moveLeft();
		return;
	}
	value.erase(curserPosition - 2, 1);
	moveLeft();
}

<<<<<<< HEAD
void TextBox::deleteLast(){
	value.erase(getWidth() - 2, 1);
}

void TextBox::deleteRight(){
=======
void TextBox::deleteLast() {
	value.erase(getWidth() - 2, 1);
}

void TextBox::deleteRight() {
>>>>>>> f93efb7b1399c85c0040808a5f70e2655a1644a8
	if (curserPosition > value.length()) return;
	value.erase(curserPosition - 1, 1);
}

<<<<<<< HEAD
void TextBox::addCharecter(CHAR c){
=======
void TextBox::addCharecter(CHAR c) {
>>>>>>> f93efb7b1399c85c0040808a5f70e2655a1644a8
	if (value.length() == getWidth() - 2) {
		return;
	}
	else if (!value.length()) {
		value = string("");
		value.insert(0, 1, c);
	}
	else value.insert(curserPosition - 1, 1, c);
	moveRight();
}


TextBox::~TextBox() {}
