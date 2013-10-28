import QtQuick 1.1
import MyDataInterface 1.1
import "../../../MyCmdJs.js" as MyCmdJs

Rectangle {
    width: 280
    height: 4
    radius: 2
    border.width: 1
    border.color: "#85CBED"
    color: "#85CBED"
    MouseArea{
        id:ma
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {
             var arr= [1,1];
             dataInterface.slotResponseNotifyUI(false, MyCmdJs.SHOW_NORMAL, arr);
        }
        onExited: {

        }
    }

    DataInterface{
        id:dataInterface
    }
}
