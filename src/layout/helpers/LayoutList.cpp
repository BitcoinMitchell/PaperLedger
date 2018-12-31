#include "LayoutList.h"

LayoutList::LayoutList(Render *_render) {
    render = _render;
};

LayoutList::~LayoutList() {
};

void LayoutList::init(int _x, int _y, int _w, int _h, int _fontSize, int _color) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    fontSize = _fontSize;
    color = _color;

    render->setFont(fontSize);
    render->getTextBounds(x, y, "Hey|", textWidth, textHeight);

    activeRow = 0;
}

void LayoutList::add(const char *text) {
    rows[rowLen] = text;
    rowLen++;
}

void LayoutList::setActive(int index) {
    if(index >= 0 && index <= rowLen) {
        activeRow = index;
        draw();
    }
}

int LayoutList::getActive() {
    return activeRow;
}

void LayoutList::draw() {
    // // Draw boundary
    // render->drawRectangle(x, y, w, h, !color, true);

    render->drawRectangle(x, y, w, h, !color, true);

    Serial.println(textWidth);
    Serial.println(textHeight);

    // Start where bounding box starts
    // Custom font starts at the bottom, while
    // system font starts at the top
    // int currentHeight = y + textHeight - textMargin;
    int currentHeight = y + textHeight;

    // Draw rows
    for(int i = 0; i < rowLen; i++) {
        // int tY = y + textHeight;

        int textColor = color;



        if(i == activeRow) {
            // Custom font starts at the bottom, thus need to
            // subtract by textHeight
            // To center bounding box, need to add margin
            render->drawRectangle(x, currentHeight - textHeight + (textHeight / 4), w, textHeight, color, true);
            textColor = !color;
        }

        render->drawText(x + textMargin , currentHeight, rows[i].c_str(), fontSize, textColor, w);

        currentHeight += textHeight;
    }

    // render->draw();
    render->draw(x, y, w, h, true);
}

// void LayoutList::draw() {
//     // // Draw boundary
//     render->drawRectangle(x, y, w, h, !color);

//     // Draw rows
//     for(int i = 0; i < rowLen; i++) {
//         int tY = (y + (textHeight * i));

//         int textColor = color;



//         if(i == activeRow) {
//             // render->drawRectangle(x, tY - textHeight + textMargin, w, textHeight + textMargin, color);
//             // textColor = !color;
//         }

//         render->drawText(x + textMargin, tY + textMargin * i, rows[i].c_str(), fontSize, textColor, w);
//     }

//     // render->draw();
//     render->draw(x, y, w, h, true);
// }