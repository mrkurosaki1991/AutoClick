#ifndef ACTION_H
#define ACTION_H

#include "standard.h"

#include <QDialog>


class Action : public QDialog
{
    Q_OBJECT
public:
    Action(ManageHandle handle);
    ~Action();

    void setHandle(const ManageHandle &value);

private :
    ManageHandle handle;
};

#endif // ACTION_H
