#include <QApplication>
#include "qtquick2applicationviewer.h"
#include "mainwidgetui.h"
#include "datainterface.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    qmlRegisterType<DataInterface>("MyDataInterface",1,1,"DataInterface");
    MainWidgetUI* mainUi = MainWidgetUI::instance();

//    mainUi->showLogInView();
    mainUi->showMainUi();
    mainUi->move((QApplication::desktop()->width() - mainUi->width())/2,
            (QApplication::desktop()->height() - mainUi->height())/2);
    mainUi->show();
    return app.exec();
}
