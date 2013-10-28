#ifndef MAINWIDGETUI_H
#define MAINWIDGETUI_H

#include <QWidget>
#include <QtDeclarative/QtDeclarative>
#include <QDebug>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>

class MainWidgetUI : public QWidget
{
    Q_OBJECT
public:
    static MainWidgetUI* instance(QWidget *parent=0);
    ~MainWidgetUI();

    void showMainUi();
    void showLogInView();

    void showTopLine();

    void hideMainUi();
    void hideLogInView();
    void showMainUIAnimation();
    void showLoginAnimation();

    void showMainUiTop();
    void closeAnimation();

    void requestData(int cmd, QStringList processResult);
    void responseNotifyUI(bool error, int cmd, QStringList processResult);


    bool isExpand;
    bool isHide;
    QPoint oldPos;
    bool canMove;
    bool isEnter;
    QPoint currentPos;

    QParallelAnimationGroup* group;
    QParallelAnimationGroup *group2;
    QParallelAnimationGroup *group3;
    QParallelAnimationGroup *group4;
    QParallelAnimationGroup *group5;
protected:
    static MainWidgetUI *_instance;
    explicit MainWidgetUI(QWidget *parent = 0);
    void changeEvent(QEvent *);
signals:
signals:
    void signalNotifyUI(bool,int,QStringList);
    void signalResponseDataReady(bool,int,QStringList);
private:
    QDeclarativeView* logView;
    QDeclarativeView* mainUi;
    QDeclarativeView* currentUi;
    QDeclarativeView* topUi;
public slots:
    void slotFinishedAnimation();
    void slotFinishedAnimation2();
    void slotFinishedAnimation3();
protected:
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
public slots:
    void slotFinishedAnimation4();
    void slotFinishedAnimation5();
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);


};

#endif // MAINWIDGETUI_H
