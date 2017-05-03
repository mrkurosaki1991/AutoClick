#ifndef DIALOG_H
#define DIALOG_H


#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QComboBox>
#include <QCheckBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QApplication>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QList>
#include <QMap>
#include <QTimer>
#include <QTimerEvent>
#include <QThread>
#include <QEventLoop>
#include <QTimeEdit>
#include <QFile>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QEvent>
#include <QFileDialog>
#include <QProcess>
#include <QByteArray>
#include <QScreen>
#include <QBitmap>

#include "windows.h"
#include "getposition.h"
#include "action.h"
#include "standard.h"





namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();


private :
    QVBoxLayout *vBoxMain;
    QTableWidget *tbListHandle;
    QTableWidget *tbSchedule;
    QRadioButton *rbLeft;
    QRadioButton *rbRight;
    QLineEdit *leText;
    QLineEdit *leIndex;
    QLineEdit *leRepeat;
    QLineEdit *leWait;
    QTimeEdit *tTime;
    QLineEdit *leRepeatGroups;
    QLineEdit *leKeyWords;
    QLineEdit *leUrl;
    QCheckBox *chWaitingFor;
    QCheckBox *chEnter;
    QComboBox *cbSelectCBB;

    GetPosition *getPosition;
    Action *action;

    int timeId;
    QTime qTimeToStart;
    bool isWaitToTime = false;
    bool isLeftButton;
    bool isWaitingFor = false;
    bool currentWaiting = false;
    bool isSendText = true;
    QString titleWindows = "";
    QEventLoop loopWait;
    QSystemTrayIcon *trayIcon;

    QList<ManageGroup> manageGroups;
    QList<HWND> windowsHandle;
    QList<ManageHandle> manageHandles;
    QList<ManageHandle> schedule;
    HWND newHandle;

    // CallBack function for winapi
    static BOOL CALLBACK StaticEnumWindowProc(HWND hwnd, LPARAM lParam);
    BOOL EnumWindowProc(HWND hwnd);



    // function for Dialog
    void CreateUI();
    void CreateTrayIcon();
    QString GetWindowTexts(HWND hwnd);
    QString GetWindowClass(HWND hwnd);
    HWND FindHandle(HWND pHwnd, QList<POINT> listPoint);
    QList<POINT> MakeListPoint(HWND pHwnd, POINT point, HWND hwnd);

    void SetCBB(HWND hwnd);

    void SendClick(HWND hwnd, POINT point, QString cmd, int times);
    void SendText(HWND hwnd, QString text);
    void PostText(HWND hwnd, QString text);
    void SelectCBB(HWND hwnd, int index);
    void SendKey(HWND hwnd, QString keys);
    void SelectMenu(HWND hwnd, QList<int> list);

    QString CreateCmd();
    void UpdateAC(int row, int columns, QString msg);
    void Run(ManageHandle handle);
    bool IsWindowsAvailable(QString title);
    void synchronizeData(QString title, HWND pHwnd);

    void SaveData(QString url);
    void ReadData(QString url);
    POINT ConvertPoint(QString point);
    void UpdateData(QString fileUrl);

    void ExecuteFile(QString fileUrl);
    // override
    void timerEvent(QTimerEvent *event) override;
    void changeEvent(QEvent *event) override;
#ifdef DEBUG
    void WriteLog(QString data);


    void Test(ManageHandle handle);
#endif
private Q_SLOTS:
    void btGetHandleClicked();
    void btRemoveClicked();
    void btRunTestClicked();
    void getPositionHided();
    void rbLeftClicked();
    void rbRightClicked();
    void rbSendClicked();
    void rbPostClicked();
    void btSingleClickClicked();
    void btDoubleClickClicked();
    void btAddTextClicked();
    void btAddIndexClicked();
    void btAddKeyClicked();
    void btAddActionClicked();
    void tbListHandleItemChanged();

    void btRemoveActionClicked();
    void btRemoveAllActionClicked();
    void btSetConditionsClicked();
    void btSetKeyWordClicked();
    void chWaitingForClicked();
    void btLoadClicked();
    void btSaveClicked();
    void btRunClicked();
    void btSetTimeToStartClicked();
    void btBrowseClicked();

    void ShowHideTrayIcon(QSystemTrayIcon::ActivationReason reason);
};

#endif // DIALOG_H
