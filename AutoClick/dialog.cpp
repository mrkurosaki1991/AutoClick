#include "dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    this->CreateUI();
}

Dialog::~Dialog()
{

}

void Dialog::CreateUI()
{
    //setWindowTitle("Debug AutoClick");
    setWindowTitle("AutoClick " + QTime::currentTime().toString("HH:mm:ss"));
    setWindowFlags(Qt::WindowMinimizeButtonHint
                   | Qt::WindowMaximizeButtonHint
                   | Qt::WindowCloseButtonHint);
    setWindowIcon(QIcon(":/Images/Piggy-Sleep-icon.png"));
    vBoxMain = new QVBoxLayout();
    setLayout(vBoxMain);
    // hBoxLayer1
    QHBoxLayout *hBoxLayer1 = new QHBoxLayout();
    vBoxMain->addLayout(hBoxLayer1);
    // hBoxLayer1 -> vBoxWindows
    QVBoxLayout *vBoxWindows = new QVBoxLayout();
    hBoxLayer1->addLayout(vBoxWindows);
    // hBoxLayer1 -> vBoxWindows -> gbGetHandle
    QGroupBox *gbGetHandle = new QGroupBox("Get Handle");
    vBoxWindows->addWidget(gbGetHandle);
    // hBoxLayer1 -> vBoxWindows -> gbGetHandle -> vBoxGetHandle
    QVBoxLayout *vBoxGetHandle = new QVBoxLayout();
    gbGetHandle->setLayout(vBoxGetHandle);
    QPushButton *btGetHandle = new QPushButton("Get Handle");
    connect(btGetHandle, SIGNAL(clicked(bool)), this, SLOT(btGetHandleClicked()));
    vBoxGetHandle->addWidget(btGetHandle,10,Qt::AlignCenter);
    // hBoxLayer1 -> vBoxWindows -> gbGetHandle -> vBoxGetHandle End
    // hBoxLayer1 -> vBoxWindows -> gbGetHandle End

    // hBoxLayer1 -> gbAction -> hBoxAction
    QGroupBox *gbAction = new QGroupBox("Action");
    hBoxLayer1->addWidget(gbAction);
    QHBoxLayout *hBoxAction = new QHBoxLayout();
    gbAction->setLayout(hBoxAction);
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbClick
    QGroupBox *gbClick = new QGroupBox("Click");
    hBoxAction->addWidget(gbClick);
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbClick -> vBoxClick
    QVBoxLayout *vBoxClick = new QVBoxLayout();
    gbClick->setLayout(vBoxClick);
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbClick -> vBoxClick -> hBoxSelectMouse
    QHBoxLayout *hBoxSelectMouse = new QHBoxLayout();
    vBoxClick->addLayout(hBoxSelectMouse);
    rbLeft = new QRadioButton("Left Mouse");
    rbLeft->setChecked(true);
    isLeftButton = true;
    connect(rbLeft, SIGNAL(clicked(bool)), this, SLOT(rbLeftClicked()));
    hBoxSelectMouse->addWidget(rbLeft);
    rbRight = new QRadioButton("Right Mouse");
    connect(rbRight, SIGNAL(clicked(bool)), this, SLOT(rbRightClicked()));
    hBoxSelectMouse->addWidget(rbRight);
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbClick -> vBoxClick -> hBoxSelectMouse End

    // hBoxLayer1 -> gbAction -> hBoxAction -> gbClick -> vBoxClick -> hBoxClick
    QHBoxLayout *hBoxClick = new QHBoxLayout();
    vBoxClick->addLayout(hBoxClick);
    QPushButton *btSingleClick = new QPushButton("Single Click");
    connect(btSingleClick, SIGNAL(clicked(bool)), this, SLOT(btSingleClickClicked()));
    hBoxClick->addWidget(btSingleClick);
    QPushButton *btDoubleClick = new QPushButton("Double Click");
    connect(btDoubleClick, SIGNAL(clicked(bool)), this, SLOT(btDoubleClickClicked()));
    hBoxClick->addWidget(btDoubleClick);
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbClick -> vBoxClick -> hBoxClick
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbClick -> vBoxClick End
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbClick End

    // hBoxLayer1 -> gbAction -> hBoxAction -> gbSendText
    QGroupBox *gbSendText = new QGroupBox("Send Text");
    hBoxAction->addWidget(gbSendText);
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbSendText -> vBoxSendText
    QVBoxLayout *vBoxSendText = new QVBoxLayout();
    gbSendText->setLayout(vBoxSendText);
    QHBoxLayout *hBoxSendPost = new QHBoxLayout();
    vBoxSendText->addLayout(hBoxSendPost);
    QRadioButton *rbSend = new QRadioButton("Send");
    rbSend->setChecked(true);
    connect(rbSend, SIGNAL(clicked(bool)), this, SLOT(rbSendClicked()));
    hBoxSendPost->addWidget(rbSend);
    QRadioButton *rbPost = new QRadioButton("Post");
    connect(rbPost, SIGNAL(clicked(bool)), this, SLOT(rbPostClicked()));
    hBoxSendPost->addWidget(rbPost);
    leText = new QLineEdit();
    vBoxSendText->addWidget(leText);
    QPushButton *btAddText = new QPushButton("Add Text");
    connect(btAddText, SIGNAL(clicked(bool)), this, SLOT(btAddTextClicked()));
    vBoxSendText->addWidget(btAddText);
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbSendText -> vBoxSendText End
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbSendText End

    // hBoxLayer1 -> gbAction -> hBoxAction -> gbSendKey
    QGroupBox *gbSendKey = new QGroupBox("Send Key");
    hBoxAction->addWidget(gbSendKey);
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbSendKey -> vBoxSendKey
    QVBoxLayout *vBoxSendKey = new QVBoxLayout();
    gbSendKey->setLayout(vBoxSendKey);
    chEnter = new QCheckBox("Enter");
    vBoxSendKey->addWidget(chEnter);
    QPushButton *btAddKey = new QPushButton("Set Key");
    connect(btAddKey, SIGNAL(clicked(bool)), this, SLOT(btAddKeyClicked()));
    vBoxSendKey->addWidget(btAddKey);
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbSendKey -> vBoxSendKey End
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbSendKey End

    // hBoxLayer1 -> gbAction -> hBoxAction -> gbSelectCbb
    QGroupBox *gbSelectCbb = new QGroupBox("Select Combobox Item");
    hBoxAction->addWidget(gbSelectCbb);
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbSelectCbb -> vBoxCbb
    QVBoxLayout *vBoxCbb = new QVBoxLayout();
    gbSelectCbb->setLayout(vBoxCbb);

    QLabel *lbIndex = new QLabel("Index :");
    lbIndex->setFixedWidth(50);
    vBoxCbb->addWidget(lbIndex);
    cbSelectCBB = new QComboBox();
    vBoxCbb->addWidget(cbSelectCBB);
    QPushButton *btAddIndex = new QPushButton("Add");
    connect(btAddIndex, SIGNAL(clicked(bool)), this, SLOT(btAddIndexClicked()));
    vBoxCbb->addWidget(btAddIndex);
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbSelectCbb -> vBoxCbb End
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbSelectCbb End
    // hBoxLayer1 -> gbAction -> hBoxAction End

    // hBoxLayer1 -> gbConditions
    QGroupBox *gbConditions = new QGroupBox("Conditions");
    hBoxLayer1->addWidget(gbConditions);
    // hBoxLayer1 -> gbConditions -> vBoxConditions
    QVBoxLayout *vBoxConditions = new QVBoxLayout();
    gbConditions->setLayout(vBoxConditions);
    // hBoxLayer1 -> gbConditions -> vBoxConditions -> hBoxRepeat
    QHBoxLayout *hBoxRepeat = new QHBoxLayout();
    vBoxConditions->addLayout(hBoxRepeat);
    QLabel *lbRepeat = new QLabel("Repeat :");
    lbRepeat->setFixedWidth(50);
    hBoxRepeat->addWidget(lbRepeat);
    leRepeat = new QLineEdit();
    hBoxRepeat->addWidget(leRepeat);
    // hBoxLayer1 -> gbConditions -> vBoxConditions -> hBoxRepeat End

    // hBoxLayer1 -> gbConditions -> vBoxConditions -> hBoxWait
    QHBoxLayout *hBoxWait = new QHBoxLayout();
    vBoxConditions->addLayout(hBoxWait);
    QLabel *lbWait = new QLabel("Wait(ms) :");
    lbWait->setFixedWidth(50);
    hBoxWait->addWidget(lbWait);
    leWait = new QLineEdit();
    hBoxWait->addWidget(leWait);
    chWaitingFor = new QCheckBox("Waiting For Its");
    connect(chWaitingFor, SIGNAL(stateChanged(int)), this, SLOT(chWaitingForClicked()));
    chWaitingFor->setChecked(false);
    hBoxWait->addWidget(chWaitingFor);
    // hBoxLayer1 -> gbConditions -> vBoxConditions -> hBoxWait End

    // hBoxLayer1 -> gbConditions -> vBoxConditions -> hBoxWaitFor
    QHBoxLayout *hBoxWaitFor = new QHBoxLayout();
    vBoxConditions->addLayout(hBoxWaitFor);
    leKeyWords = new QLineEdit();
    hBoxWaitFor->addWidget(leKeyWords);
    QPushButton *btSetKeyWord = new QPushButton("Set KeyWord");
    connect(btSetKeyWord, SIGNAL(clicked(bool)), this, SLOT(btSetKeyWordClicked()));
    hBoxWaitFor->addWidget(btSetKeyWord);
    // hBoxLayer1 -> gbConditions -> vBoxConditions -> hBoxWaitFor End

    QPushButton *btSetConditions = new QPushButton("Set Conditions");
    connect(btSetConditions, SIGNAL(clicked(bool)), this, SLOT(btSetConditionsClicked()));
    vBoxConditions->addWidget(btSetConditions);
    // hBoxLayer1 -> gbConditions -> vBoxConditions End
    // hBoxLayer1 -> gbConditions End
#if TEST_FUNCTION > 0
    // hBoxLayer1 -> gbGroups
    QGroupBox *gbGroups = new QGroupBox("Group");
    hBoxLayer1->addWidget(gbGroups);
    // hBoxLayer1 -> gbGroups -> vBoxGroups
    QVBoxLayout *vBoxGroups = new QVBoxLayout();
    gbGroups->setLayout(vBoxGroups);
    // hBoxLayer1 -> gbGroups -> vBoxGroups -> hBoxRepeatGroups
    QHBoxLayout *hBoxRepeatGroups = new QHBoxLayout();
    vBoxGroups->addLayout(hBoxRepeatGroups);
    QLabel *lbRepeatGroups = new QLabel("Repeat :");
    lbRepeatGroups->setFixedWidth(70);
    hBoxRepeatGroups->addWidget(lbRepeat);
    leRepeatGroups = new QLineEdit();
    hBoxRepeatGroups->addWidget(leRepeatGroups);
    // hBoxLayer1 -> gbGroups -> vBoxGroups -> hBoxRepeatGroups End

    // hBoxLayer1 -> gbGroups -> vBoxGroups -> hBoxTimer
    QHBoxLayout *hBoxTimer = new QHBoxLayout();
    vBoxGroups->addLayout(hBoxTimer);
    QLabel *lbTimer = new QLabel("Time to start :");
    lbTimer->setFixedWidth(70);
    hBoxTimer->addWidget(lbTimer);
    tTime = new QTimeEdit();
    tTime->setDisplayFormat("HH:mm:ss");
    tTime->setTime(QTime::currentTime());
    hBoxTimer->addWidget(tTime);
    QPushButton *btSetTimeToStart = new QPushButton("Set");
    connect(btSetTimeToStart, SIGNAL(clicked(bool)), this, SLOT(btSetTimeToStartClicked()));
    hBoxTimer->addWidget(btSetTimeToStart);
    // hBoxLayer1 -> gbGroups -> vBoxGroups -> hBoxTimer End
    // hBoxLayer1 -> gbGroups -> vBoxGroups -> hBoxFileExe
    QHBoxLayout *hBoxFileExe = new QHBoxLayout();
    vBoxGroups->addLayout(hBoxFileExe);
    leUrl = new QLineEdit();
    hBoxFileExe->addWidget(leUrl);
    QPushButton *btBrowse = new QPushButton("Browse");
    connect(btBrowse, SIGNAL(clicked(bool)), this, SLOT(btBrowseClicked()));
    hBoxFileExe->addWidget(btBrowse);
    // hBoxLayer1 -> gbGroups -> vBoxGroups -> hBoxFileExe End
    // hBoxLayer1 -> gbGroups -> vBoxGroups End
    // hBoxLayer1 -> gbGroups End
#endif
    // hBoxHandle
    QHBoxLayout *hBoxHandle = new QHBoxLayout();
    vBoxMain->addLayout(hBoxHandle);
    // hBoxHandle -> gbListHandle
    QGroupBox *gbListHandle = new QGroupBox("List Handle");
    hBoxHandle->addWidget(gbListHandle);
    // hBoxHandle -> gbListHandle -> vBoxListHandle
    QVBoxLayout *vBoxListHandle = new QVBoxLayout();
    gbListHandle->setLayout(vBoxListHandle);
    // hBoxHandle -> gbListHandle -> vBoxListHandle -> tbListHandle
    tbListHandle = new QTableWidget();
    tbListHandle->setColumnCount(7);
    tbListHandle->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    tbListHandle->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    tbListHandle->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    tbListHandle->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    tbListHandle->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    tbListHandle->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    tbListHandle->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
    tbListHandle->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tbListHandle->setHorizontalHeaderItem(0, new QTableWidgetItem("Title"));
    tbListHandle->setHorizontalHeaderItem(1, new QTableWidgetItem("Parent"));
    tbListHandle->setHorizontalHeaderItem(2, new QTableWidgetItem("Type"));
    tbListHandle->setHorizontalHeaderItem(3, new QTableWidgetItem("X"));
    tbListHandle->setHorizontalHeaderItem(4, new QTableWidgetItem("Y"));
    tbListHandle->setHorizontalHeaderItem(5, new QTableWidgetItem("Actions"));
    tbListHandle->setHorizontalHeaderItem(6, new QTableWidgetItem("Conditions"));
    connect(tbListHandle, SIGNAL(currentItemChanged(QTableWidgetItem*,QTableWidgetItem*)), this, SLOT(tbListHandleItemChanged()));
    vBoxListHandle->addWidget(tbListHandle);
    // hBoxHandle -> gbListHandle -> vBoxListHandle -> tbListHandle End

    // hBoxHandle -> gbListHandle -> vBoxListHandle -> hBoxListHandleButton
    QHBoxLayout *hBoxListHandleButton = new QHBoxLayout();
    vBoxListHandle->addLayout(hBoxListHandleButton);
    QPushButton *btRemove = new QPushButton("Remove");
    connect(btRemove, SIGNAL(clicked(bool)), this, SLOT(btRemoveClicked()));
    hBoxListHandleButton->addWidget(btRemove);
    QPushButton *btRunTest = new QPushButton("Run Test");
    connect(btRunTest, SIGNAL(clicked(bool)), this, SLOT(btRunTestClicked()));
    hBoxListHandleButton->addWidget(btRunTest);
    // hBoxHandle -> gbListHandle -> vBoxListHandle -> hBoxListHandleButton End
    // hBoxHandle -> gbListHandle -> vBoxListHandle End
    // hBoxHandle -> gbListHandle End

    // hBoxHandle -> vBoxBt
    QVBoxLayout *vBoxBt = new QVBoxLayout();
    hBoxHandle->addLayout(vBoxBt);
    QPushButton *btAddAction = new QPushButton("Add");
    connect(btAddAction, SIGNAL(clicked(bool)), this, SLOT(btAddActionClicked()));
    vBoxBt->addWidget(btAddAction);
    QPushButton *btRemoveAction = new QPushButton("Remove");
    connect(btRemoveAction, SIGNAL(clicked(bool)), this, SLOT(btRemoveActionClicked()));
    vBoxBt->addWidget(btRemoveAction);
    QPushButton *btRemoveAllAction = new QPushButton("Remove All");
    connect(btRemoveAllAction, SIGNAL(clicked(bool)), this, SLOT(btRemoveAllActionClicked()));
    vBoxBt->addWidget(btRemoveAllAction);
    // hBoxHandle -> vBoxBt End

    // hBoxHandle -> gbSchedule
    QGroupBox *gbSchedule = new QGroupBox("Schedule");
    hBoxHandle->addWidget(gbSchedule);
    // hBoxHandle -> gbSchedule -> vBoxSchedule
    QVBoxLayout *vBoxSchedule = new QVBoxLayout();
    gbSchedule->setLayout(vBoxSchedule);
    // hBoxHandle -> gbSchedule -> vBoxSchedule -> tbSchedule
    tbSchedule = new QTableWidget();
    tbSchedule->setColumnCount(8);
    tbSchedule->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
    tbSchedule->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    tbSchedule->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    tbSchedule->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    tbSchedule->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);
    tbSchedule->horizontalHeader()->setSectionResizeMode(5, QHeaderView::ResizeToContents);
    tbSchedule->horizontalHeader()->setSectionResizeMode(6, QHeaderView::ResizeToContents);
    tbSchedule->horizontalHeader()->setSectionResizeMode(7, QHeaderView::ResizeToContents);
    tbSchedule->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tbSchedule->setHorizontalHeaderItem(0, new QTableWidgetItem("Title"));
    tbSchedule->setHorizontalHeaderItem(1, new QTableWidgetItem("Parent"));
    tbSchedule->setHorizontalHeaderItem(2, new QTableWidgetItem("Type"));
    tbSchedule->setHorizontalHeaderItem(3, new QTableWidgetItem("X"));
    tbSchedule->setHorizontalHeaderItem(4, new QTableWidgetItem("Y"));
    tbSchedule->setHorizontalHeaderItem(5, new QTableWidgetItem("Actions"));
    tbSchedule->setHorizontalHeaderItem(6, new QTableWidgetItem("Conditions"));
    tbSchedule->setHorizontalHeaderItem(7, new QTableWidgetItem("Group"));
    vBoxSchedule->addWidget(tbSchedule);
    // hBoxHandle -> gbSchedule -> vBoxSchedule -> tbSchedule End

    // hBoxHandle -> gbSchedule -> vBoxSchedule -> hBoxBottomButton
    QHBoxLayout *hBoxBottomButton = new QHBoxLayout();
    vBoxSchedule->addLayout(hBoxBottomButton);
    QPushButton *btLoad = new QPushButton("Load");
    connect(btLoad, SIGNAL(clicked(bool)), this, SLOT(btLoadClicked()));
    hBoxBottomButton->addWidget(btLoad);
    QPushButton *btSave = new QPushButton("Save");
    connect(btSave, SIGNAL(clicked(bool)), this, SLOT(btSaveClicked()));
    hBoxBottomButton->addWidget(btSave);
    QPushButton *btRun = new QPushButton("Run");
    connect(btRun, SIGNAL(clicked(bool)), this, SLOT(btRunClicked()));
    hBoxBottomButton->addWidget(btRun);
    // hBoxHandle -> gbSchedule -> vBoxSchedule -> hBoxBottomButton End
    // hBoxHandle -> gbSchedule -> vBoxSchedule End
    // hBoxHandle -> gbSchedule End
    // hBoxHandle End

    getPosition = new GetPosition();
    connect(getPosition, SIGNAL(MousePressed(bool)), this, SLOT(getPositionHided()));


}
// Static for EnumWindowProc
WINBOOL Dialog::StaticEnumWindowProc(HWND hwnd, LPARAM lParam)
{
    Dialog *pThis = reinterpret_cast<Dialog *> (lParam);
    return pThis->EnumWindowProc(hwnd);
}
// Callback function for EnumWindow
WINBOOL Dialog::EnumWindowProc(HWND hwnd)
{
    windowsHandle << hwnd;
    return true;
}

QString Dialog::GetWindowTexts(HWND hwnd)
{
    WCHAR title[1024];
    if(GetWindowText(hwnd, title, 1024)){
        return QString::fromWCharArray(title);
    }
    return "Null";
}

QString Dialog::GetWindowClass(HWND hwnd)
{
    WCHAR title[1024];
    if(GetClassName(hwnd, title, 1024)){
        return QString::fromWCharArray(title);
    }
    return "Null";
}

HWND Dialog::FindHandle(HWND pHwnd, QList<POINT> listPoint)
{
    foreach (POINT p, listPoint) {
        pHwnd = RealChildWindowFromPoint(pHwnd, p);
    }
    return pHwnd;
}

QList<POINT> Dialog::MakeListPoint(HWND pHwnd, POINT point, HWND hwnd)
{
#ifdef DEBUG
    WriteLog(QString(__FUNCTION__) + " " + "MakeListPoint");
#endif
    POINT childPoint;
    QList<POINT> listPoint;
    while(pHwnd != hwnd){
        childPoint = point;
        if(ScreenToClient(pHwnd, &childPoint)){
            listPoint << childPoint;
            pHwnd = RealChildWindowFromPoint(pHwnd, childPoint);
        }else{
            break;
        }
    }
    return listPoint;
}

void Dialog::SetCBB(HWND hwnd)
{
    int cbbCount = SendMessage(hwnd, CB_GETCOUNT, 0, 0);
    cbSelectCBB->clear();
    WCHAR text[1024];
    if(cbbCount > 0){
        for(int i = 0; i < cbbCount; i++){
            SendMessage(hwnd, CB_GETLBTEXT, i, (LPARAM)&text);
            cbSelectCBB->addItem(QString::fromWCharArray(text));
        }
        leText->setDisabled(true);
    }else{
        leText->setEnabled(true);
    }
}

void Dialog::SendClick(HWND hwnd, POINT point, QString cmd, int times)
{
    int mouseDown = 0;
    int mouseUp = 0;
    int i = 0;
    if(cmd == "LM"){
        mouseDown = WM_LBUTTONDOWN;
        mouseUp = WM_LBUTTONUP;
    }else{
        mouseDown = WM_RBUTTONDOWN;
        mouseUp = WM_RBUTTONUP;
    }
    while(i < times){
        SendMessage(hwnd, mouseDown, 1, MAKELPARAM(point.x, point.y));
        SendMessage(hwnd, mouseUp, 0, MAKELPARAM(point.x, point.y));
        i++;
#ifdef DEBUG
    WriteLog(QString(__FUNCTION__) + " " + "Send " + cmd + " click.");
#endif
    }

}

void Dialog::SendText(HWND hwnd, QString text)
{
    WCHAR content[1024];
    text.toWCharArray(content);
    content[text.length()] = '\0';
    SendMessage(hwnd, WM_SETTEXT, 0, (LPARAM)&content);
#ifdef DEBUG
    WriteLog(QString(__FUNCTION__) + " " + "Send " + text);
#endif
}

void Dialog::PostText(HWND hwnd, QString text)
{
    QString qStr = text.toUpper();
    WCHAR test[1024];
    qStr.toWCharArray(test);
    PostMessage(hwnd, WM_KEYDOWN, VK_SHIFT, 0);
    for(int i = 0; i < qStr.length(); i++){
        PostMessage(hwnd, WM_KEYDOWN, (WPARAM)test[i], 0);
    }
}

void Dialog::SelectCBB(HWND hwnd, int index)
{
    PostMessage(hwnd, CB_SETCURSEL, index, 0);
}

void Dialog::SendKey(HWND hwnd, QString keys)
{
//    keybd_event(VK_RETURN, 0x9c, 0, 0);
//    keybd_event(VK_RETURN, 0x9c, KEYEVENTF_KEYUP, 0);
    PostMessage(hwnd, WM_KEYDOWN, VK_RETURN, 0);
    PostMessage(hwnd, WM_KEYUP, VK_RETURN, 0);
}

void Dialog::SelectMenu(HWND hwnd, QList<int> list)
{
    HMENU mainMenu = GetMenu(hwnd);
    for(int i = 0; i <  list.length() - 1; i++){
        mainMenu = GetSubMenu(mainMenu, list[i]);
    }
    int id = GetMenuItemID(mainMenu, list[list.length() - 1]);
    PostMessage(hwnd, WM_COMMAND, id, 0);
}

QString Dialog::CreateCmd()
{
    if(isLeftButton){
        return "Mouse_LM_";
    }else{
        return "Mouse_RM_";
    }
}

void Dialog::UpdateAC(int row, int columns, QString msg)
{
    tbListHandle->setItem(row, columns, new QTableWidgetItem(msg));
    if(columns == 5){
        manageHandles[row].cmd = msg;
    }else{
        manageHandles[row].conditions = msg;
    }
}

void Dialog::Run(ManageHandle handle)
{
    QStringList cmd = handle.cmd.split("_");
    QStringList conditions = handle.conditions.split(" ");
    QStringList repeat = conditions[0].split("_");
    QStringList wait = conditions[1].split("_");
    unsigned int waitTime = 0;
    unsigned int repeatTime = 1;
    unsigned int count = 0;
    QEventLoop loop;
    if(repeat[1] != ""){
        repeatTime = repeat[1].toInt();
    }

    if(wait[1] != ""){
        if(wait[1] == "forIts"){
            WriteLog(QString(QString(__FUNCTION__)) + " " + "forIts");
            currentWaiting = true;
            titleWindows = handle.pKeyWordForTitle;
            timeId = startTimer(1000);
            loopWait.exec();
            handle.pHwnd = newHandle;
            this->synchronizeData(titleWindows, handle.pHwnd);

        }else{
            waitTime = wait[1].toInt();
        }
    }
    handle.hwnd = this->FindHandle(handle.pHwnd, handle.pointForSearch);
    titleWindows = "";
    while(count < repeatTime){
        if(waitTime > 0){
            QTimer::singleShot(waitTime, &loop, SLOT(quit()));
            loop.exec();
        }
        if(cmd[0] == "Mouse"){
            this->SendClick(handle.hwnd, handle.point, cmd[1], cmd[2].toInt());
#ifdef DEBUG
            WriteLog(QString(__FUNCTION__) + " " + cmd[0] + " " + cmd[1] + " " + cmd[2]);
#endif
        }else if(cmd[0] == "Text"){
            if(cmd[1] == "S"){
                this->SendText(handle.hwnd, cmd[2]);
            }else{
                this->PostText(handle.hwnd, cmd[2]);
            }

#ifdef DEBUG
            WriteLog(QString(__FUNCTION__) + " " + cmd[0] + " " + cmd[1]);
#endif
        }else if(cmd[0] == "CBB"){
            this->SelectCBB(handle.hwnd, cmd[1].toInt());
#ifdef DEBUG
            WriteLog(QString(__FUNCTION__) + " " + cmd[0] + " " + cmd[1]);
#endif
        }else if(cmd[0] == "SK"){
            this->SendKey(handle.hwnd, cmd[1]);
#ifdef DEBUG
            WriteLog(QString(__FUNCTION__) + " " + cmd[0] + " " + cmd[1]);
            qDebug() << cmd[1];
#endif
        }
        count++;
    }
}

bool Dialog::IsWindowsAvailable(QString title)
{
    EnumWindows(StaticEnumWindowProc, reinterpret_cast<LPARAM> (this));
    foreach (HWND hwnd, windowsHandle) {
        if(this->GetWindowTexts(hwnd).indexOf(title) > -1){
            newHandle = hwnd;
            return true;
        }
    }
    return false;
}

void Dialog::synchronizeData(QString title, HWND pHwnd)
{
    for(int i = 0; i < schedule.length(); i++){
        if(schedule[i].pLatestTitle == title){
            qDebug() << "synchronizeData";
            schedule[i].pHwnd = pHwnd;
        }
    }
    for(int i = 0; i < manageHandles.length(); i++){
        if(manageHandles[i].pLatestTitle == title){
            manageHandles[i].pHwnd = pHwnd;
        }
    }
}

void Dialog::SaveData(QString url)
{
    QFile file(url);
    if(file.open(QIODevice::WriteOnly)){
        QTextStream out(&file);
        out << "==============> ManageHandles : " << QString::number(manageHandles.length()) << " <==============\n";
        foreach(ManageHandle handle, manageHandles){
            out << "LatestTitle : " << handle.latestTitle << "\n";
            out << "Type : " << handle.type << "\n";
            out << "PLatestTitle : " << handle.pLatestTitle << "\n";
            out << "PKeyWordForTitle : " << handle.pKeyWordForTitle << "\n";
            out << "PType : " << handle.type << "\n";
            out << "Cmd : " << handle.cmd << "\n";
            out << "Conditions : " << handle.conditions << "\n";
            out << "Point : " << QString::number(handle.point.x) << "-" << QString::number(handle.point.y) << "\n";
            out << "PointForSeach : ";
            foreach (POINT point, handle.pointForSearch) {
                out << point.x << "-" << point.y << ",";
            }
            out << "\n";
        }
        WriteLog(QString(__FUNCTION__) + " " + "Write ManageHandles " + QString::number(manageHandles.length()) + " data");
        out << "==============> Schedules : " << QString::number(schedule.length()) << " <==============\n";
        foreach(ManageHandle handle, schedule){
            out << "LatestTitle : " << handle.latestTitle << "\n";
            out << "Type : " << handle.type << "\n";
            out << "PLatestTitle : " << handle.pLatestTitle << "\n";
            out << "PKeyWordForTitle : " << handle.pKeyWordForTitle << "\n";
            out << "PType : " << handle.type << "\n";
            out << "Cmd : " << handle.cmd << "\n";
            out << "Conditions : " << handle.conditions << "\n";
            out << "Point : " << QString::number(handle.point.x) << "-" << QString::number(handle.point.y) << "\n";
            out << "PointForSeach : ";
            foreach (POINT point, handle.pointForSearch) {
                out << point.x << "-" << point.y << ",";
            }
            out << "\n";
        }
        WriteLog(QString(__FUNCTION__) + " " + "Write Schedules " + QString::number(schedule.length()) + " data");
    }
    file.close();
}

void Dialog::ReadData(QString url)
{
    QFile file(url);
    QStringList line;
    int amount = 0;
    qDebug() << "ReadData()";
    if(file.open(QIODevice::ReadOnly)){
        QTextStream in(&file);
        line = in.readLine().split(" : ");
        if(line[0].indexOf("ManageHandles") > -1){
            QStringList text = line[1].split(" ");
            amount = text[0].toInt();
        }
        WriteLog(QString(__FUNCTION__) + " " + "ManageHandles have " + QString::number(amount) + " data");
        if(amount > 0){
            ManageHandle handle;
            for(int i = 0; i < amount; i++){
                line = in.readLine().split(" : ");
                handle.latestTitle = line[1];
                line = in.readLine().split(" : ");
                handle.type = line[1];
                line = in.readLine().split(" : ");
                handle.pLatestTitle = line[1];
                line = in.readLine().split(" : ");
                handle.pKeyWordForTitle = line[1];
                line = in.readLine().split(" : ");
                handle.pType = line[1];
                line = in.readLine().split(" : ");
                handle.cmd = line[1];
                line = in.readLine().split(" : ");
                handle.conditions = line[1];
                line = in.readLine().split(" : ");
                handle.point = this->ConvertPoint(line[1]);
                line = in.readLine().split(" : ");
                QList<POINT> points;
                foreach(QString point, line[1].split(",")){
                    if(point != ""){
                        points << this->ConvertPoint(point);
                    }
                }
                handle.pointForSearch = points;
                manageHandles << handle;
            }
        }
        WriteLog(QString(__FUNCTION__) + " " + "manageHandles.length() " + QString::number(manageHandles.length()));

        line = in.readLine().split(" : ");
        amount = 0;
        if(line[0].indexOf("Schedules") > -1){
            QStringList text = line[1].split(" ");
            amount = text[0].toInt();
        }
        WriteLog(QString(__FUNCTION__) + " " + "Schedules have " + QString::number(amount) + " data");
        if(amount > 0){
            ManageHandle handle;
            for(int i = 0; i < amount; i++){
                line = in.readLine().split(" : ");
                handle.latestTitle = line[1];
                line = in.readLine().split(" : ");
                handle.type = line[1];
                line = in.readLine().split(" : ");
                handle.pLatestTitle = line[1];
                line = in.readLine().split(" : ");
                handle.pKeyWordForTitle = line[1];
                line = in.readLine().split(" : ");
                handle.pType = line[1];
                line = in.readLine().split(" : ");
                handle.cmd = line[1];
                line = in.readLine().split(" : ");
                handle.conditions = line[1];
                line = in.readLine().split(" : ");
                handle.point = this->ConvertPoint(line[1]);
                line = in.readLine().split(" : ");
                QList<POINT> points;
                foreach(QString point, line[1].split(",")){
                    if(point != ""){
                        points << this->ConvertPoint(point);
                    }
                }
                handle.pointForSearch = points;
                schedule << handle;
            }
        }
        WriteLog(QString(__FUNCTION__) + " " + "schedule.length() " + QString::number(schedule.length()));
    }
    file.close();
}

POINT Dialog::ConvertPoint(QString point)
{
    QStringList p = point.split("-");
    return {p[0].toInt(), p[1].toInt()};
}

void Dialog::UpdateData(QString fileUrl)
{
    manageHandles.clear();
    schedule.clear();
    tbListHandle->setRowCount(0);
    tbSchedule->setRowCount(0);
    this->ReadData(fileUrl);
    if(manageHandles.length() > 0){
        for(int i = 0; i < manageHandles.length(); i++) {
            int count = tbListHandle->rowCount();
            tbListHandle->setRowCount(count + 1);
            tbListHandle->setItem(count, 0, new QTableWidgetItem(manageHandles[i].latestTitle));
            tbListHandle->setItem(count, 1, new QTableWidgetItem(manageHandles[i].pLatestTitle));
            tbListHandle->setItem(count, 2, new QTableWidgetItem(manageHandles[i].type));
            tbListHandle->setItem(count, 3, new QTableWidgetItem(QString::number(manageHandles[i].point.x)));
            tbListHandle->setItem(count, 4, new QTableWidgetItem(QString::number(manageHandles[i].point.y)));
            tbListHandle->setItem(count, 5, new QTableWidgetItem(manageHandles[i].cmd));
            tbListHandle->setItem(count, 6, new QTableWidgetItem(manageHandles[i].conditions));
            tbListHandle->setCurrentCell(count, 0);
            if(this->IsWindowsAvailable(manageHandles[i].pKeyWordForTitle)){
                manageHandles[i].pHwnd = newHandle;
                manageHandles[i].hwnd = this->FindHandle(manageHandles[i].pHwnd, manageHandles[i].pointForSearch);
                qDebug() << QString(__FUNCTION__) + " " + "pHwnd " << manageHandles[i].pHwnd;
                qDebug() << QString(__FUNCTION__) + " " + "hwnd " << manageHandles[i].hwnd;
            }
        }
    }
    if(schedule.length() > 0){
        for(int i = 0; i < schedule.length(); i++) {
            int count = tbSchedule->rowCount();
            tbSchedule->setRowCount(count + 1);
            tbSchedule->setItem(count, 0, new QTableWidgetItem(schedule[i].latestTitle));
            tbSchedule->setItem(count, 1, new QTableWidgetItem(schedule[i].pLatestTitle));
            tbSchedule->setItem(count, 2, new QTableWidgetItem(schedule[i].type));
            tbSchedule->setItem(count, 3, new QTableWidgetItem(QString::number(schedule[i].point.x)));
            tbSchedule->setItem(count, 4, new QTableWidgetItem(QString::number(schedule[i].point.y)));
            tbSchedule->setItem(count, 5, new QTableWidgetItem(schedule[i].cmd));
            tbSchedule->setItem(count, 6, new QTableWidgetItem(schedule[i].conditions));
            tbSchedule->setCurrentCell(count, 0);
            if(this->IsWindowsAvailable(schedule[i].pKeyWordForTitle)){
                schedule[i].pHwnd = newHandle;
                schedule[i].hwnd = this->FindHandle(schedule[i].pHwnd, schedule[i].pointForSearch);
                qDebug() << QString(__FUNCTION__) + " " + "pHwnd " << schedule[i].pHwnd;
                qDebug() << QString(__FUNCTION__) + " " + "hwnd " << schedule[i].hwnd;
            }
        }
    }
}

void Dialog::ExecuteFile(QString fileUrl)
{
    QString cmd = "\"" + fileUrl + "\"";
    QProcess *qProcess = new QProcess();
    qDebug() << cmd;
    qProcess->start(cmd);
}

void Dialog::CreateTrayIcon()
{
    trayIcon = new QSystemTrayIcon(QIcon("icon.ico"));
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(ShowHideTrayIcon(QSystemTrayIcon::ActivationReason)));
    QAction *actionExit = new QAction("Exit", trayIcon);
    connect(actionExit, SIGNAL(triggered(bool)), this, SLOT(reject()));
    QAction *actionShow = new QAction("Show", trayIcon);
    connect(actionShow, SIGNAL(triggered(bool)), this, SLOT(ShowHideTrayIcon(QSystemTrayIcon::ActivationReason)));
    QMenu *trayIconMenu = new QMenu();
    trayIconMenu->addAction(actionExit);
    trayIconMenu->addAction(actionShow);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->show();
    this->hide();
}


void Dialog::timerEvent(QTimerEvent *event)
{
    QTime qTime = QTime::currentTime();
    if(isWaitToTime){
        qDebug() << qTime << " " << qTimeToStart;
        if(qTime.hour() == qTimeToStart.hour() && qTime.minute() == qTimeToStart.minute() && qTime.second() == qTimeToStart.second()){
            isWaitToTime = false;
            this->ExecuteFile(leUrl->text());
            WriteLog(QString(__FUNCTION__) + " " + "Timeout");
            killTimer(timeId);
            loopWait.quit();
        }
    }else{
        if(currentWaiting){
            if(IsWindowsAvailable(titleWindows)){
                WriteLog(QString(__FUNCTION__) + " " + "Find Windows");
                currentWaiting = false;
                killTimer(timeId);
                loopWait.quit();
            }
        }
    }

}

void Dialog::changeEvent(QEvent *event)
{
    if(event->type() == QEvent::WindowStateChange){
        qDebug() << this->windowState();
        qDebug() << Qt::WindowMaximized;
        if(this->windowState() == 1){
            qDebug() << "W";
            this->CreateTrayIcon();
        }
    }
}
#ifdef DEBUG
void Dialog::WriteLog(QString data)
{
    QFile file("log.txt");
    if(file.open(QIODevice::WriteOnly | QIODevice::Append)){
        QTextStream out(&file);
        out << QTime::currentTime().toString("HH:mm:ss.zzzz") + " " + data + "\n";
    }
    file.close();
}

void Dialog::Test(ManageHandle handle)
{
    //SendMessage(handle.hwnd, WM_LBUTTONDOWN, 1, MAKELPARAM(handle.point.x, handle.point.y));
    SendMessage(handle.hwnd, WM_MOUSEHOVER, MK_LBUTTON, MAKELPARAM(handle.point.x, handle.point.y));
    WCHAR menu[1024];
    HMENU hMenu = GetMenu(handle.pHwnd);
    //qDebug() << hMenu;
    this->WriteLog(QString(__FUNCTION__) + " Menu :" + QString::number(GetMenuItemCount(hMenu)));
    if(GetMenuString(hMenu, 0, menu, 1024, 0)){
        this->WriteLog(QString(__FUNCTION__) + " Menu :" + QString::fromWCharArray(menu));
    }
    HMENU hMenuFile = GetSubMenu(hMenu, 0);
    //qDebug() << hMenuFile;
    this->WriteLog(QString(__FUNCTION__) + " Menu :" + QString::number(GetMenuItemCount(hMenuFile)));
    int id = GetMenuItemID(hMenuFile, 1);
    qDebug() << id;
    this->WriteLog(QString(__FUNCTION__) + " Menu :" + QString::number(id));
    //PostMessage(handle.pHwnd, WM_COMMAND, id, 0);
    // Capture image
    QFile file("test.png");
    file.open(QIODevice::WriteOnly);
    //QPixmap::grabWindow((WId)handle.hwnd).save(&file, "PNG");
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen)
    {
        QPixmap ss = screen->grabWindow((WId)handle.hwnd);
        ss.save(&file, "PNG");
    }
    // Capture image


}
#endif

void Dialog::btGetHandleClicked()
{
    this->hide();
    getPosition->show();
}

void Dialog::btRemoveClicked()
{
    int currentRow = tbListHandle->currentRow();
    int count = tbListHandle->rowCount();
    tbListHandle->removeRow(currentRow);
    tbListHandle->setRowCount(count - 1);
    tbListHandle->setCurrentCell(0, 0);
    manageHandles.removeAt(currentRow);

}

void Dialog::btRunTestClicked()
{
    int index = tbListHandle->currentRow();
    this->Run(manageHandles[index]);
}

void Dialog::getPositionHided()
{
    POINT point = {getPosition->getX(), getPosition->getY()};
    getPosition->hide();
    ManageHandle handle;
    HWND hwnd = WindowFromPoint(point);
    HWND pHwnd = GetAncestor(hwnd, GA_ROOT);
#ifdef DEBUG
    WriteLog(QString(__FUNCTION__) + " GLOBAL X : " + QString::number(point.x) + " Y : " + QString::number(point.y));
    WriteLog(QString(__FUNCTION__) + " Title : " + GetWindowTexts(hwnd) + " Class : " + GetWindowClass(hwnd));
    WriteLog(QString(__FUNCTION__) + " GetAncestor(hwnd, GA_ROOT)");
    WriteLog(QString(__FUNCTION__) + " Title : " + GetWindowTexts(pHwnd) + " Class : " + GetWindowClass(pHwnd));
#endif
    POINT pPoint = point;
    if(!ScreenToClient(hwnd, &point)){
    }
    handle.hwnd = hwnd;
    handle.latestTitle = GetWindowTexts(hwnd);
    handle.type = GetWindowClass(hwnd);
    handle.point = point;
    handle.pHwnd = pHwnd;
    handle.pLatestTitle = GetWindowTexts(pHwnd);
    handle.pKeyWordForTitle = GetWindowTexts(pHwnd);
    handle.pType = GetWindowClass(pHwnd);
    handle.pointForSearch = MakeListPoint(handle.pHwnd, pPoint, handle.hwnd);
    manageHandles << handle;
#ifdef DEBUG
    WriteLog(QString(__FUNCTION__) + " handle.pointForSearch.length() : " + QString::number(handle.pointForSearch.length()));
#endif
    int count = tbListHandle->rowCount();
    tbListHandle->setRowCount(count + 1);
    tbListHandle->setItem(count, 0, new QTableWidgetItem(handle.latestTitle));
    tbListHandle->setItem(count, 1, new QTableWidgetItem(handle.pLatestTitle));
    tbListHandle->setItem(count, 2, new QTableWidgetItem(handle.type));
    tbListHandle->setItem(count, 3, new QTableWidgetItem(QString::number(handle.point.x)));
    tbListHandle->setItem(count, 4, new QTableWidgetItem(QString::number(handle.point.y)));
    tbListHandle->setItem(count, 5, new QTableWidgetItem(""));
    tbListHandle->setItem(count, 6, new QTableWidgetItem(""));
    tbListHandle->setCurrentCell(count, 0);
    leKeyWords->setText(handle.pLatestTitle);
    this->SetCBB(handle.hwnd);
    //this->PostText(handle.hwnd, "Test");
    //SendKey(handle.hwnd, "");
    //PostMessage(handle.hwnd, WM_KEYDOWN, (WPARAM)65, 0);
    this->Test(handle);
    this->show();

//    action = new Action(handle);
//    qDebug() << __FUNCTION__;
//    action->show();
//    action->raise();
}

void Dialog::rbLeftClicked()
{
    isLeftButton = true;
#ifdef DEBUG
    WriteLog(QString(__FUNCTION__) + " isLeftButton : " + isLeftButton);
#endif
}

void Dialog::rbRightClicked()
{
    isLeftButton = false;
#ifdef DEBUG
    WriteLog(QString(__FUNCTION__) + " isLeftButton : " + isLeftButton);
#endif
}

void Dialog::rbSendClicked()
{
    isSendText = true;
}

void Dialog::rbPostClicked()
{
    isSendText = false;
}

void Dialog::btSingleClickClicked()
{
    int currentRow = tbListHandle->currentRow();
    QString msg = CreateCmd() + "1";
    this->UpdateAC(currentRow, ACTION_COLUMNS, msg);
#ifdef DEBUG
    WriteLog(QString(__FUNCTION__) + " " + "btSingleClickClicked");
#endif
}

void Dialog::btDoubleClickClicked()
{
    int currentRow = tbListHandle->currentRow();
    QString msg = CreateCmd() + "2";
    this->UpdateAC(currentRow, ACTION_COLUMNS, msg);
#ifdef DEBUG
    WriteLog(QString(__FUNCTION__) + " " + "btDoubleClickClicked");
#endif
}

void Dialog::btAddTextClicked()
{
    int currentRow = tbListHandle->currentRow();
    QString msg = "Text_";
    if(isSendText){
        msg += "S_";
    }else{
        msg += "P_";
    }
    msg += leText->text();
    this->UpdateAC(currentRow, ACTION_COLUMNS, msg);
    leText->setText("");
#ifdef DEBUG
    WriteLog(QString(__FUNCTION__) + " " + "btAddTextClicked : " + msg);
#endif
}

void Dialog::btAddIndexClicked()
{
    int currentRow = tbListHandle->currentRow();
    QString msg = "CBB_" + QString::number(cbSelectCBB->currentIndex());
    this->UpdateAC(currentRow, ACTION_COLUMNS, msg);
#ifdef DEBUG
    WriteLog(QString(__FUNCTION__) + " " + "btAddIndexClicked : " + msg);
#endif
}

void Dialog::btAddKeyClicked()
{
    int currentRow = tbListHandle->currentRow();
    QString listKey;
    if(chEnter->isChecked()){
        listKey = "Enter";
    }
    QString msg = "SK_" + listKey;
    this->UpdateAC(currentRow, ACTION_COLUMNS, msg);
#ifdef DEBUG
    WriteLog(QString(__FUNCTION__) + " " + "btAddKeyClicked : " + msg);
#endif
}

void Dialog::btAddActionClicked()
{
    int index = tbListHandle->currentRow();
    int count = tbSchedule->rowCount();
    ManageHandle handle = manageHandles[index];
    tbSchedule->setRowCount(count + 1);
    tbSchedule->setItem(count, 0, new QTableWidgetItem(handle.latestTitle));
    tbSchedule->setItem(count, 1, new QTableWidgetItem(handle.pLatestTitle));
    tbSchedule->setItem(count, 2, new QTableWidgetItem(handle.type));
    tbSchedule->setItem(count, 3, new QTableWidgetItem(QString::number(handle.point.x)));
    tbSchedule->setItem(count, 4, new QTableWidgetItem(QString::number(handle.point.y)));
    tbSchedule->setItem(count, 5, new QTableWidgetItem(handle.cmd));
    tbSchedule->setItem(count, 6, new QTableWidgetItem(handle.conditions));
    tbSchedule->setCurrentCell(count, 0);
    schedule << handle;
}

void Dialog::tbListHandleItemChanged()
{
    int currentRow = tbListHandle->currentRow();
    if(currentRow > -1){
        leKeyWords->setText(manageHandles[currentRow].pKeyWordForTitle);
        this->SetCBB(manageHandles[currentRow].hwnd);
    }else{
        leKeyWords->clear();
        cbSelectCBB->clear();
    }

}

void Dialog::btRemoveActionClicked()
{
    int count = tbSchedule->rowCount();
    int index = tbSchedule->currentRow();
    tbSchedule->removeRow(index);
    tbSchedule->setRowCount(count - 1);
    schedule.removeAt(index);
}

void Dialog::btRemoveAllActionClicked()
{
    tbSchedule->setRowCount(0);
    schedule.clear();
}

void Dialog::btSetConditionsClicked()
{
    int index = tbListHandle->currentRow();
    QString msg = "R_";
    if(leRepeat->text() != ""){
        msg += leRepeat->text();
    }
    msg += " W_";
    if(isWaitingFor){
        msg += "forIts";
    }else{
        if(leWait->text() != ""){
            msg += leWait->text();
        }
    }
    this->UpdateAC(index, 6, msg);
    manageHandles[index].conditions = msg;
}

void Dialog::btSetKeyWordClicked()
{
    int index = tbListHandle->currentRow();
    manageHandles[index].pKeyWordForTitle = leKeyWords->text();
    WriteLog(QString(__FUNCTION__) + " " + manageHandles[index].pLatestTitle + " : " + manageHandles[index].pKeyWordForTitle);
}

void Dialog::chWaitingForClicked()
{
    isWaitingFor = chWaitingFor->isChecked();
    leWait->setDisabled(isWaitingFor);
}

void Dialog::btLoadClicked()
{
    QString fileUrl = QFileDialog::getOpenFileName(this, "Open a file", "", "Text file (*.txt)");
    if(fileUrl != ""){
        this->UpdateData(fileUrl);
    }
}

void Dialog::btSaveClicked()
{
    QString fileUrl = QFileDialog::getSaveFileName(this, "Save a file", "D:\\", "Text file(*.txt)");
    if(fileUrl != ""){
        this->SaveData(fileUrl);
    }
}

void Dialog::btRunClicked()
{
    CreateTrayIcon();
    int count = 0;
    int repeat = 1;
    if(isWaitToTime){
        timeId = startTimer(990);
        loopWait.exec();
    }
    if(schedule.length() > 0){
        if(leRepeatGroups->text() != ""){
            repeat = leRepeatGroups->text().toInt();
        }
        while(count < repeat){
            for(int i = 0; i < schedule.length(); i++){
                this->Run(schedule[i]);
            }
            leRepeatGroups->setText(QString::number(repeat - count));
            count++;
        }
    }
    this->show();
    this->setFocus();
    this->raise();
    trayIcon->hide();
    if(isWaitToTime){
        this->btRunClicked();
    }
}

void Dialog::btSetTimeToStartClicked()
{
    isWaitToTime = true;
    qTimeToStart = tTime->time();
}

void Dialog::btBrowseClicked()
{
    QString url = QFileDialog::getOpenFileName(this, "Choosen a file", "", "Execute file (*.exe)");
    if(url != ""){
        leUrl->setText(url);
    }
}

void Dialog::ShowHideTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    if(reason){
        if(reason != QSystemTrayIcon::DoubleClick){
            return;
        }
    }
    trayIcon->hide();
    this->setWindowState(Qt::WindowNoState);
    this->show();
    this->raise();
    this->setFocus();
}
