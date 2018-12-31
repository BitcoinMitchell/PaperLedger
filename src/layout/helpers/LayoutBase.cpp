#include "LayoutBase.h"

LayoutBase::LayoutBase(Render* _render, Display *_display) {
    render = _render;
    display = _display;
    initButtons();
};

void LayoutBase::initButtons() {
    Serial.println("LayoutBase BUTTONS INIT");

    leftButton = new Pushbutton(LEFT_BUTTON);
    rightButton = new Pushbutton(RIGHT_BUTTON);
    okButton = new Pushbutton(OK_BUTTON);
};

void LayoutBase::updateButtons() {
    if (leftButton->getSingleDebouncedPress()) {
        leftButtonClicked();
    }
    if (rightButton->getSingleDebouncedPress()) {
        rightButtonClicked();
    }
    if (okButton->getSingleDebouncedPress()) {
        okButtonClicked();
    }
}

void LayoutBase::update() {
    updateButtons();
}