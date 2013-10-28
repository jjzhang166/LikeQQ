import QtQuick 1.0
import MyDataInterface 1.1
import "./../../../MyCmdJs.js" as MyCmdJs
import "../../../ops.js" as MyOpJs
import "../"

Rectangle{
    width: 400
    height: 280
    smooth: true
    property int iStatus: 0
    MouseArea {
        id:ma
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton
        property int ix:0
        property int iy:0
        onPressed:{
            ma.ix = mouseX;
            ma.iy = mouseY;
            parent.focus = true; vk.state = "inactive";
        }
        onPositionChanged: {
            var dyx = mouseX - ma.ix;
            var dyy = mouseY - ma.iy;
            var arryTmp = [dyx,dyy];
            dataInterface.slotResponseNotifyUI(false, MyCmdJs.WIDGET_MOVE, arryTmp);//slotMoveUi(dyx, dyy)
        }
    }

    BorderImage {
        id: borImg
        anchors.fill: parent
        source: "qrc:/image/bg_2.png"
        width: 400; height: 280
        border.left: 0; border.top: 0
        border.right: 0; border.bottom: 0
    }
    Row{
        anchors.right: parent.right
        ICutomBtn{
            id:minBtn
            imgSource:"qrc:/image/minBtn_"
            onSignalClicked: {
                //console.log("min clicked")
                dataInterface.slotResponseNotifyUI(false,MyCmdJs.MIN,"");
            }
        }
        ICutomBtn{
            id:closeBtn
            onSignalClicked: {
                //console.log("close clicked")
                dataInterface.slotResponseNotifyUI(false,MyCmdJs.CLOSE,"");
            }
        }
    }
    Text{
        id:mainTx
        anchors.left:parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        text: "虎踞龙门QQ客户端"
        font.pixelSize: 15
        font.family: "微软雅黑"
        color: "#217827"
    }
    Rectangle{
        id:line
        anchors.left: parent.left
        anchors.top:mainTx.bottom
        anchors.topMargin: 6
        anchors.right: parent.right
        height: 1
        color: "#93FFCE"
        visible: true
    }
    Image {
        id: logo
        source: "qrc:/image/tigerlogo.png"
        anchors.left: parent.left
        anchors.leftMargin: 6
        anchors.top:parent.top
        anchors.topMargin: 100
    }
    LineItem{
        id:userName
        anchors.left: parent.left
        anchors.leftMargin: 74
        anchors.top:parent.top
        anchors.topMargin: 100
        width: 200
        height: 30
        Keys.onTabPressed: {
            userName2.setFoucs();
            parent.focus = false; vk.state = "inactive";
        }
        onSignalFoucusOn: {
            iStatus = 0;
            parent.focus = false; vk.state = "inactive";
            //vk.state = "active"; parent.focus = true;
        }
    }
    LineItem{
        id:userName2
        anchors.left: parent.left
        anchors.leftMargin: 74
        anchors.top:userName.bottom
        anchors.topMargin: 4
        height: 30
        userNam: "密码:"
        isEcho: true
        onSignalFoucusOn: {
            vk.state = "inactive"; parent.focus = false;
        }
        onSignalKeyBoradShow: {
            iStatus = 1;
            vk.state = "active"; parent.focus = false;
        }
    }
    ITextShow{
        id:showTxt
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.top:parent.top
        anchors.topMargin: 105
    }

    Item{
        id:che
        anchors.left: parent.left
        anchors.leftMargin: 100
        anchors.top: userName2.bottom
        anchors.topMargin: 10
        width: 150
        height: 30
        Row{
            spacing: 8
            ICheckBox{
                id:rem
                checkText: "记住密码"
            }
            ICheckBox{
                id:anto
                checkText: "自动登陆"
            }
        }
    }

    DataInterface{
        id:dataInterface
    }
    Rectangle{
        id:btn
//        anchors.right: parent.right
//        anchors.rightMargin: 6
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        color: "#93FFCE"
        width: 100
        height: 30
        radius: 5
        Text {
            id: name
            text: "登陆主界面"
            font.family: "微软雅黑"
            anchors.centerIn: parent
            color: "#217827"
        }
        MouseArea{
            id:ma1
            anchors.fill: parent
            onClicked: {
                var arr= [1,1];
                console.log("saflkaslkaglakglak")
                dataInterface.slotResponseNotifyUI(false,1010,arr);
            }
        }
    }
    VirtualKeyboard {
        id: vk;
        onButtonPressed: {
            console.log("Keyboard sent: " + op);
            if(iStatus == 0)
            {
               userName.setTxt(op);
            }else if(iStatus == 1)
            {
               userName2.setTxt(op);
            }
        }
    }
    function getradom()
    {
        var i = Math.random(1);
    }

}
