import QtQuick 1.0

BorderImage {
    id: button

    property alias text: buttonText.text
    property string op: buttonText.op
    property alias shiftText: buttonShiftText.text
    property string shiftOp: buttonShiftText.text

    signal clicked(string op)

    width: 22
    height: 22

    source: "qrc:/image/bg1.png"; clip: true
    border { left: 1; top: 1; right: 1; bottom: 1 }

    Rectangle {
        id: shade
        anchors {fill: button;}
        radius: 10;
        color: "black";
        opacity: 0
    }

    Text {
        id: buttonText
        anchors { centerIn: parent; }
        font.family: "Times New Roman"
        font.pixelSize: parent.width > parent.height ? parent.height * .6 : parent.width * .6
        style: Text.Sunken;
        color: "#217827";
//        styleColor: "black";
        smooth: true
    }

    Text {
        id: buttonShiftText
        anchors {
            top: parent.top
            right: parent.right
            rightMargin: 4
        }

        font.pixelSize: parent.width > parent.height ? parent.height * .25 : parent.width * .25
      //  style: Text.Sunken;
        color: "black";
        styleColor: "black";
        smooth: true
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: button.clicked(op)
    }

    states: State {
        name: "pressed"; when: mouseArea.pressed == true
        PropertyChanges { target: shade; opacity: .3 }
    }
}
