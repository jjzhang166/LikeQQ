import QtQuick 1.1

Item {
    width: 200
    height: 32
    property string userNam: "账号:"
    property bool isEcho: false
    property string userContents: ""
    signal signalFoucusOn();
    signal signalKeyBoradShow();
    Row{
        spacing: 2
        Text{
            id:userName
            anchors.verticalCenter: parent.verticalCenter
            text:userNam
            font.pixelSize: 12
            font.family: "微软雅黑"
            color: "#217827"
        }
        ILineEdit{
            id:line
            pswModel:isEcho
            onSignalFoucs: {
                signalFoucusOn();
            }
            onSignalShowKeyborad: {
                signalKeyBoradShow();
            }
        }
    }
    function setFoucs()
    {
        line.setFoucs();
    }
    function setTxt(str)
    {
       line.setTxt(str);
    }

}
