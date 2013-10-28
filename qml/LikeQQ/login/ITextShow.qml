import QtQuick 1.1

Item {
    width: 80
    height: 62
    property string str1:"注册账号"
    property string str2:"找回密码"

    Column{
        id:txtR
        spacing:10
        Text {
            id: name1
            text: str1
            font.pixelSize: 15
            font.family: "微软雅黑"
            color: "#217827"
        }
        Text{
            id:name2
            text: str2
            font.pixelSize: 15
            font.family: "微软雅黑"
            color: "#217827"
        }
    }
}
