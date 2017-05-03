#include "action.h"

Action::Action(ManageHandle handle)
{
    QVBoxLayout *vBoxMain = new QVBoxLayout();
    this->setLayout(vBoxMain);
    qDebug() << __FUNCTION__;
    // Detail Groups
    QGroupBox *gbDetail = new QGroupBox("Detail");
    vBoxMain->addWidget(gbDetail);
    // Detail Groups -> vBoxDetail
    QVBoxLayout *vBoxDetail = new QVBoxLayout();
    gbDetail->setLayout(vBoxDetail);
    // Detail Groups -> vBoxDetail -> hBoxChild
    QHBoxLayout *hBoxChild = new QHBoxLayout();
    vBoxDetail->addLayout(hBoxChild);
    QLabel *lbWindowText = new QLabel("Window Text : " + handle.latestTitle);
    hBoxChild->addWidget(lbWindowText);
    QLabel *lbWindowClass = new QLabel("Window Class :" + handle.type);
    hBoxChild->addWidget(lbWindowClass);
    // Detail Groups -> vBoxDetail -> hBoxChild End

    // Detail Groups -> vBoxDetail -> hBoxPWindow
    QHBoxLayout *hBoxPWindow = new QHBoxLayout();
    vBoxDetail->addLayout(hBoxPWindow);
    QLabel *lbPWindowText = new QLabel("P_Window Text : " + handle.pLatestTitle);
    hBoxPWindow->addWidget(lbPWindowText);
    QLabel *lbPWindowClass = new QLabel("P_Window Class :" + handle.pType);
    hBoxPWindow->addWidget(lbPWindowClass);
    // Detail Groups -> vBoxDetail -> hBoxPWindow End

    // Detail Groups -> vBoxDetail -> hBoxPosition
    QHBoxLayout *hBoxPosition = new QHBoxLayout();
    vBoxDetail->addLayout(hBoxPosition);
    QLabel *lbX = new QLabel("X : " + QString::number(handle.point.x));
    hBoxPosition->addWidget(lbX);
    QLabel *lbY = new QLabel("Y :" + QString::number(handle.point.y));
    hBoxPosition->addWidget(lbY);
    // Detail Groups -> vBoxDetail -> hBoxPosition End
    // Detail Groups -> vBoxDetail End
    // Detail Groups End
/*
    // Action Groups
    QGroupBox *gbAction = new QGroupBox("Action");
    vBoxMain->addWidget(gbAction);
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
    leIndex = new QLineEdit();
    vBoxCbb->addWidget(leIndex);
    QPushButton *btAddIndex = new QPushButton("Add");
    connect(btAddIndex, SIGNAL(clicked(bool)), this, SLOT(btAddIndexClicked()));
    vBoxCbb->addWidget(btAddIndex);
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbSelectCbb -> vBoxCbb End
    // hBoxLayer1 -> gbAction -> hBoxAction -> gbSelectCbb End
    // hBoxLayer1 -> gbAction -> hBoxAction End
    // Action Groups End
    */
}

Action::~Action()
{

}

void Action::setHandle(const ManageHandle &value)
{
    handle = value;
}
