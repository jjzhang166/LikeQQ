#include "mainwidgetui.h"
#define WIDGET_WIDTH     281
#define WIDGET_HEIGHT    700
#include "MyCmd.h"

MainWidgetUI* MainWidgetUI::_instance = NULL;

MainWidgetUI *MainWidgetUI::instance(QWidget *parent)
{
    if(_instance == NULL)
    {
        _instance = new MainWidgetUI();
    }
    return _instance;
}
MainWidgetUI::MainWidgetUI(QWidget *parent) :
    QWidget(parent),logView(0),mainUi(0),currentUi(0),isHide(false),canMove(false),isEnter(false),topUi(0)
{
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowTitle(QString::fromUtf8("虎踞龙门QQ客户端"));
}
MainWidgetUI::~MainWidgetUI()
{

}
void MainWidgetUI::showMainUi()
{
    if(mainUi==NULL){
        mainUi = new QDeclarativeView(this);
        mainUi->setSource(QUrl("./qml/LikeQQ/main.qml"));
        mainUi->setWindowFlags(Qt::FramelessWindowHint);
        mainUi->setResizeMode(QDeclarativeView::SizeRootObjectToView);
        //        mainUi->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
        mainUi->setFixedSize(QSize(WIDGET_WIDTH,WIDGET_HEIGHT));
        mainUi->setWindowTitle(QString::fromUtf8("虎踞龙门QQ客户端"));
        mainUi->setAttribute(Qt::WA_TranslucentBackground);
        mainUi->setStyleSheet("background:transparent;");
    }
    currentUi = mainUi;
    this->setFixedSize(281,700);
    qDebug()<<"this:"<<this->size();
    this->move(currentPos);
}

void MainWidgetUI::showLogInView()
{
    if(NULL==logView){
        qDebug() << "hello in  Show Log view1";
        logView = new QDeclarativeView(this);
        logView->resize(QSize(400,280));
        logView->setSource(QUrl("./qml/LikeQQ/login/LoginUi.qml"));
        logView->setWindowFlags(Qt::FramelessWindowHint);
        logView->setAttribute(Qt::WA_TranslucentBackground);
        logView->setStyleSheet("background:transparent;");
        logView->setResizeMode(QDeclarativeView::SizeRootObjectToView);
        logView->setWindowTitle(QString::fromUtf8("虎踞龙门QQ客户端"));
//        logView->setWindowFlags(Qt::WindowStaysOnTopHint);
    }
    currentUi = logView;
    this->setFixedSize(logView->size());
    currentUi->show();
    this->move((QApplication::desktop()->width()-this->width())/2,(QApplication::desktop()->height()-this->height())/2);

}

void MainWidgetUI::showTopLine()
{
    if(NULL==topUi){
        qDebug() << "hello in  Show Log topUi";
        topUi = new QDeclarativeView(this);
        topUi->resize(QSize(281,4));
        topUi->setSource(QUrl("./qml/LikeQQ/login/topLine.qml"));
        topUi->setWindowFlags(Qt::FramelessWindowHint);
        topUi->setAttribute(Qt::WA_TranslucentBackground);
        topUi->setStyleSheet("background:transparent;");
        topUi->setResizeMode(QDeclarativeView::SizeRootObjectToView);
        topUi->setWindowTitle(QString::fromUtf8("虎踞龙门QQ客户端"));
//        topUi->setWindowFlags(Qt::WindowStaysOnTopHint);
    }
    currentUi = topUi;
    topUi->show();
    this->setFixedSize(topUi->size());
    currentUi->show();
    qDebug()<<"topUi :"<<topUi->pos();
    if(currentPos.y()<=0)
    {
        this->move(currentPos.x(),0);
    }else{
        this->move(currentPos);
    }

}

void MainWidgetUI::showMainUIAnimation()
{
    //执行登陆窗口切换到主窗口
    //currentUi->show();
    group = new QParallelAnimationGroup;
    connect(group,SIGNAL(finished()),this,SLOT(slotFinishedAnimation()));
    QPropertyAnimation *animation = new QPropertyAnimation(this, "size");
    animation->setDuration(800);
    animation->setStartValue(QSize(currentUi->width(),currentUi->height()));
    animation->setEndValue(QSize(0,0));

    QPropertyAnimation *animation3 = new QPropertyAnimation(this, "windowOpacity");
    animation3->setDuration(800);
    animation3->setStartValue(0.0);
    animation3->setEndValue(1.0);

    group->addAnimation(animation3);
    group->addAnimation(animation);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    group->start();
}

void MainWidgetUI::showLoginAnimation()
{
    //执行主窗口切换登陆窗口
    currentUi->show();
    group2 = new QParallelAnimationGroup;
    connect(group2,SIGNAL(finished()),this,SLOT(slotFinishedAnimation2()));
    QPropertyAnimation *animation2 = new QPropertyAnimation(this, "size");
    animation2->setDuration(500);
    animation2->setStartValue(QSize(0,0));
    animation2->setEndValue(QSize(currentUi->width(),currentUi->height()));

    QPropertyAnimation *animation4 = new QPropertyAnimation(this, "windowOpacity");
    animation4->setDuration(800);
    animation4->setStartValue(0.0);
    animation4->setEndValue(1.0);

    animation2->setEasingCurve(QEasingCurve::OutCubic);
    group2->addAnimation(animation2);
    group2->addAnimation(animation4);
    group2->start();
}

void MainWidgetUI::showMainUiTop()
{
    currentUi = mainUi;
    this->setWindowOpacity(1.0);
    this->setFixedSize(281,700);
    qDebug()<<"this:"<<this->size();
    this->move(currentPos);
}

void MainWidgetUI::closeAnimation()
{
    group3 = new QParallelAnimationGroup;
    connect(group3,SIGNAL(finished()),this,SLOT(slotFinishedAnimation3()));
    QPropertyAnimation *animation2 = new QPropertyAnimation(this, "size");
    animation2->setDuration(800);
    animation2->setStartValue(QSize(currentUi->width(),currentUi->height()));
    animation2->setEndValue(QSize(currentUi->width(),0));

    QPropertyAnimation *animation4 = new QPropertyAnimation(this, "windowOpacity");
    animation4->setDuration(500);
    animation4->setStartValue(1.0);
    animation4->setEndValue(0.0);

    animation2->setEasingCurve(QEasingCurve::InOutQuad);
    group3->addAnimation(animation2);
    group3->addAnimation(animation4);
    group3->start();
}

void MainWidgetUI::requestData(int cmd, QStringList processResult)
{

}

void MainWidgetUI::responseNotifyUI(bool error, int cmd, QStringList processResult)
{
    if(error)return;
    switch(cmd){
    case WIDGET_MOVE:{
        int xtmp = processResult.at(0).toInt();
        int ytmp = processResult.at(1).toInt();
        int localx = this->x();
        int localy = this->y();
        if((localx+xtmp <0) ||(localy+ytmp)<0)
        {

        }else{
            this->move(localx + xtmp, localy + ytmp);
            currentPos = this->pos();
        }
    }break;
    case 1010:
    {
        qDebug()<<"processResult MAINUI "<<processResult;
        currentUi->hide();
        showMainUIAnimation();
        showMainUi();
    }break;
    case 1011:
    {
        qDebug()<<"processResult "<<processResult;
        currentUi->hide();
        showLoginAnimation();
        showLogInView();
    }break;
    case MIN:
    {
        this->showMinimized();
    }break;
    case CLOSE:
    {
//        this->close();
        closeAnimation();
    }break;
    case SHOW_NORMAL:
    {
        topUi->hide();
        showMainUi();
    }break;
    }
}

void MainWidgetUI::changeEvent(QEvent *e)
{
    if(e->type()==QEvent::WindowStateChange && this->windowState() == Qt::WindowNoState)
    {
        repaint();
    }
}

void MainWidgetUI::slotFinishedAnimation()
{
    qDebug()<<"slotFinishedAnimation";
    logView->hide();
    currentUi->show();
//    currentUi->resize(281,700);
//    this->resize(281,700);
}

void MainWidgetUI::slotFinishedAnimation2()
{
    mainUi->hide();
    currentUi->hide();
    this->repaint();
    currentUi->show();
//    showLogInView();
    qDebug()<<"slotFinishedAnimation2 ";

}

void MainWidgetUI::slotFinishedAnimation3()
{
    this->hide();
    this->close();
}
void MainWidgetUI::enterEvent(QEvent *e)
{
    qDebug()<<"in it enterEvent "<<e->type()<<"\n"<<this->pos()<<"\n"<<isHide;
    if(e->type() == QEvent::Enter  && isHide &&currentUi == mainUi)
    {
        isEnter = false;
        group4 = new QParallelAnimationGroup;
        connect(group4,SIGNAL(finished()),this,SLOT(slotFinishedAnimation4()));
        QPropertyAnimation *animation = new QPropertyAnimation(this, "size");
        animation->setDuration(200);
        animation->setStartValue(QSize(281,4));
        animation->setEndValue(QSize(281,700));

        QPropertyAnimation *animation3 = new QPropertyAnimation(this,"windowOpacity");
        animation3->setDuration(500);
        animation3->setStartValue(1.0);
        animation3->setEndValue(1.0);

        group4->addAnimation(animation);
        group4->addAnimation(animation3);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        group4->start();
    }
}

void MainWidgetUI::leaveEvent(QEvent *e)
{
    qDebug()<<"in it leaveEvent "<<isHide<<"\n"<<this->pos().y();
    if(this->pos().y() <=0 && !isHide && currentUi == mainUi)
    {
        qDebug()<<"start..................";
        isEnter = true;
        group5 = new QParallelAnimationGroup;
        connect(group5,SIGNAL(finished()),this,SLOT(slotFinishedAnimation5()));
        QPropertyAnimation *animation = new QPropertyAnimation(currentUi, "size");
        animation->setDuration(800);
        animation->setStartValue(QSize(281,700));
        animation->setEndValue(QSize(281,4));

        QPropertyAnimation *animation3 = new QPropertyAnimation(currentUi, "windowOpacity");
        animation3->setDuration(500);
        animation3->setStartValue(1.0);
        animation3->setEndValue(0.2);

        group5->addAnimation(animation);
        group5->addAnimation(animation3);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        group5->start();
    }
}
void MainWidgetUI::slotFinishedAnimation4()
{
    isHide =false;
    currentUi = mainUi;
    this->update();
    this->resize(281,700);
    if(this->y() <=0)
    {
        this->move(this->x(),0);
    }
    this->show();
    delete group4;
}

void MainWidgetUI::slotFinishedAnimation5()
{
    qDebug()<<"slotFinishedAnimation5";
    isHide =true;
    currentUi = topUi;
    delete group5;
    showTopLine();
    this->update();
}
void MainWidgetUI::mousePressEvent(QMouseEvent *e)
{
    if( (e->pos().x()>= 10) && (e->pos().y()<=45))
    {
        canMove = true;
    }
    else
    {
        canMove = false;
        e->accept();
        return;
    }
    oldPos = e->pos();
    e->accept();
}
void MainWidgetUI::mouseMoveEvent(QMouseEvent *e)
{
    currentPos = e->pos();
    qDebug()<<"mouseMoveEvent "<<this->pos();
    if(canMove)
    {
        move(e->globalPos() - oldPos);
    }
    e->accept();
}
