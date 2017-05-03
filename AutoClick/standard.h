#ifndef STANDARD_H
#define STANDARD_H

#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>

#include "windows.h"

// Macro
#define ACTION_COLUMNS 5
#define CONDITION_COLUMNS 6

#define VERSION 1.0
#define DEBUG 0
#define DEBUG_GetPositionHided 1
#define DEBUG_Action 10
#define DEBUG_Action_Mouse 11
#define DEBUG_Action_SendText 12
#define DEBUG_Action_SendHotKey 13
#define DEBUG_Action_SelectCBB 14
#define DEBUG_Condition 20

#define TEST_FUNCTION 1


struct ManageHandle{
    HWND hwnd;
    QString latestTitle; // GetWindowsText
    QString type; //GetClassName
    POINT point;
    HWND pHwnd;
    QString pLatestTitle; // GetWindowsText
    QString pKeyWordForTitle;
    QString pType; //GetClassName
    QString pKeyWordForType;
    QList<POINT> pointForSearch;
    QString cmd;
    QString conditions = "R_ W_";
};
struct ManageGroup{
    QList<int> listHandle;
    QString waitingForWindow = "";
    unsigned int repeat = 1;
    unsigned int wait = 0;
};

#endif // STANDARD_H
