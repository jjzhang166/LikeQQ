import QtQuick 1.0
import MyDataInterface 1.1
import "./../../MyCmdJs.js" as MyCmdJs

Rectangle {
    width: 281
    height: 700
    border.width: 2
    border.color: "gray"
    radius: 5
    smooth: true
    color: "#85CBED"
    MouseArea {
        id:ma
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton
        property int ix:0
        property int iy:0
        onPressed:{
            ma.ix = mouseX;
            ma.iy = mouseY;
            //console.log("top bar pressed");
        }
        onPositionChanged: {
            var dyx = mouseX - ma.ix;
            var dyy = mouseY - ma.iy;
            var arryTmp = [dyx,dyy];
            dataInterface.slotResponseNotifyUI(false, MyCmdJs.WIDGET_MOVE, arryTmp);//slotMoveUi(dyx, dyy)
        }
    }
    Text {
        id:lefeTxt
        text: ("虎踞龙门QQ客户端")
        anchors.left:parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        font.pixelSize: 20
        font.family: "微软雅黑"
        color: "#217827"
    }
    Rectangle{
        id:line
        anchors.left: parent.left
        anchors.leftMargin: 2
        anchors.top:lefeTxt.bottom
        anchors.topMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 2
        height: 1
        color: "black"
    }
    Rectangle{
        id:btn
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        color: "#218728"
        width: 60
        height: 30
        radius: 5
        Text {
            id: name
            text: "切换界面"
            font.family: "微软雅黑"
            anchors.centerIn: parent
            color: "white"
        }
        MouseArea{
            id:ma1
            anchors.fill: parent
            onClicked: {
                var arr= [1,1];
                console.log("saflkaslkaglakglak")
                dataInterface.slotResponseNotifyUI(false,1011,arr);
            }
        }
    }
    DataInterface{
        id:dataInterface
    }
}
