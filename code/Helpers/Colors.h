#ifndef COLORS_H
#define COLORS_H

#include <QColor>

namespace MyColors {
const QColor blue(0, 125, 176);
const QColor white(243, 234, 226);
const QColor red(182, 47, 68);
const QColor light_red(192, 57, 78);
const QColor black(25,25,25);
const QColor green(102, 160, 105);
}

namespace ButtonStyles {
const QString switch_button_on = "QPushButton {\ncolor: rgb(243, 234, 226);\nbackground-color: rgb(0, 125, 176);\nborder-radius: 5px;\nborder: 2px solid;\nborder-color: rgb(243, 234, 226);\n}\nQPushButton:hover {\nbackground-color: rgba(0, 125, 176, 220);\n}";
const QString switch_button_off = "QPushButton {\ncolor: rgb(243, 234, 226);\nbackground-color: transparent;\n\nborder-radius: 5px;\nborder: 2px solid;\nborder-color: rgb(243, 234, 226);\n}\nQPushButton:enabled:hover {\nbackground-color: rgba(255,255,255,30);\n}";

}

#endif // COLORS_H
