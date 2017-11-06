#include "state.h"
#include "state_menu.h"
#include "ui.h"
#include "ui_menu.h"
#include "buttons.h"


static const unsigned char searchIcon[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xFF, 0x80, 0x00, 0x01, 0xFF, 0xE0, 0x00, 0x03, 0xFF, 0xF0, 0x00, 0x07, 0xE3, 0xF0, 0x00,
    0x0F, 0x80, 0xF8, 0x00, 0x0F, 0x00, 0x78, 0x00, 0x0F, 0x00, 0x3C, 0x00, 0x0E, 0x00, 0x3C, 0x00,
    0x0E, 0x00, 0x3C, 0x00, 0x0E, 0x00, 0x3C, 0x00, 0x0F, 0x00, 0x3C, 0x00, 0x0F, 0x00, 0x78, 0x00,
    0x0F, 0x80, 0xF8, 0x00, 0x07, 0xC1, 0xF8, 0x00, 0x07, 0xFF, 0xF8, 0x00, 0x03, 0xFF, 0xFC, 0x00,
    0x00, 0xFF, 0xFE, 0x00, 0x00, 0x3F, 0x1F, 0x00, 0x00, 0x00, 0x0F, 0x80, 0x00, 0x00, 0x07, 0xC0,
    0x00, 0x00, 0x03, 0xE0, 0x00, 0x00, 0x01, 0xF0, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x00, 0x40,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char bandScanIcon[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x3F, 0xFC, 0x00, 0x03, 0xFF, 0xFF, 0xC0, 0x07, 0xFF, 0xFF, 0xE0, 0x3F, 0xFF, 0xFF, 0xFC,
    0x7F, 0xFE, 0x7F, 0xFE, 0xFF, 0xFE, 0x7F, 0xFF, 0xFF, 0xFE, 0x7F, 0xFF, 0x7F, 0xFF, 0xFF, 0xFE,
    0x7F, 0xFF, 0xFF, 0xFE, 0x1F, 0xFE, 0x7F, 0xF8, 0x1F, 0xFE, 0x7F, 0xF8, 0x0F, 0xFE, 0x7F, 0xF0,
    0x07, 0xFE, 0x7F, 0xE0, 0x03, 0xFE, 0x7F, 0xC0, 0x01, 0xFE, 0x7F, 0x80, 0x01, 0xFE, 0x7F, 0x80,
    0x00, 0xFE, 0x7F, 0x00, 0x00, 0x7F, 0xFE, 0x00, 0x00, 0x3F, 0xFC, 0x00, 0x00, 0x1F, 0xF8, 0x00,
    0x00, 0x1F, 0xF8, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x07, 0xE0, 0x00, 0x00, 0x03, 0xC0, 0x00,
    0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static const unsigned char settingsIcon[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x0F, 0xF0, 0x00,
    0x00, 0x0F, 0xF0, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x07, 0x1F, 0xF8, 0xE0, 0x07, 0xFF, 0xFF, 0xE0,
    0x0F, 0xFF, 0xFF, 0xF0, 0x0F, 0xFF, 0xFF, 0xF0, 0x1F, 0xFF, 0xFF, 0xF8, 0x1F, 0xFF, 0xFF, 0xF8,
    0x1F, 0xFC, 0x3F, 0xF8, 0x1F, 0xF8, 0x1F, 0xF8, 0x07, 0xF0, 0x0F, 0xE0, 0x03, 0xF0, 0x0F, 0xC0,
    0x03, 0xF0, 0x0F, 0xC0, 0x07, 0xF0, 0x0F, 0xE0, 0x1F, 0xF8, 0x1F, 0xF8, 0x1F, 0xFC, 0x3F, 0xF8,
    0x1F, 0xFF, 0xFF, 0xF8, 0x1F, 0xFF, 0xFF, 0xF8, 0x0F, 0xFF, 0xFF, 0xF0, 0x0F, 0xFF, 0xFF, 0xF0,
    0x07, 0xFF, 0xFF, 0xE0, 0x07, 0x1F, 0xF8, 0xE0, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x0F, 0xF0, 0x00,
    0x00, 0x0F, 0xF0, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

static void searchMenuHandler();
static void bandScannerMenuHandler();
static void settingsMenuHandler();


void StateMachine::MenuStateHandler::onEnter() {
    this->menu.reset();
    this->menu.addItem("Search", searchIcon, searchMenuHandler);
    this->menu.addItem("Band Scan", bandScanIcon, bandScannerMenuHandler);
    this->menu.addItem("Settings", settingsIcon, settingsMenuHandler);
}


void StateMachine::MenuStateHandler::onButtonChange(
    Button button,
    Buttons::PressType pressType
) {
    if (pressType != Buttons::PressType::SHORT)
        return;

    switch (button) {
        case Button::UP:
            this->menu.selectPreviousItem();
            Ui::needUpdate();
            break;

        case Button::DOWN:
            this->menu.selectNextItem();
            Ui::needUpdate();
            break;

        case Button::MODE:
            this->menu.activateItem();
            break;
    }
}


static void searchMenuHandler() {
    StateMachine::switchState(StateMachine::State::SEARCH);
};

static void bandScannerMenuHandler() {
    StateMachine::switchState(StateMachine::State::BANDSCAN);
};

static void settingsMenuHandler() {
    StateMachine::switchState(StateMachine::State::SETTINGS);
};
