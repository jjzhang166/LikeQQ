import QtQuick 1.0

Rectangle {
    id: vk

    property string rotateLeft: "\u2939"
    property string rotateRight: "\u2935"
    property string leftArrow: "\u2190"
    property string upperArrow: "\u2191"
    property string division : "\u00f7"
    property string multiplication : "\u00d7"
    property string squareRoot : "\u221a"
    property string plusminus : "\u00b1"

    signal buttonPressed(string op)

    // span the parent's width
    anchors {
        left: parent.left
        right: parent.right
//        bottom: parent.bottom
//        bottomMargin: 4
    }

    // A virtual keyboard (VK) is attached the the bottom of an Item
    // and slides up when activated.
    // this item is called the surface
    property Item surface: parent

    // By default the VK's height is at the bottom of the surface
    y: surface.height

    // Depending on the parent's focus, set the initial state
    state: parent.activeFocus ? "active" : "inactive"

    Column {
        id: vkc;

        anchors {
            horizontalCenter: parent.horizontalCenter
            margins: 4
        }

        spacing: 3

        Row {
            spacing: 3
            anchors.horizontalCenter: parent.horizontalCenter
            Button { text: "q"; op: "q"; shiftText: "1"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "w"; op: "w"; shiftText: "2"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "e"; op: "e"; shiftText: "3"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "r"; op: "r"; shiftText: "4"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "t"; op: "t"; shiftText: "5"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "y"; op: "y"; shiftText: "6"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "u"; op: "u"; shiftText: "7"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "i"; op: "i"; shiftText: "8"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "o"; op: "o"; shiftText: "9"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "p"; op: "p"; shiftText: "0"; Component.onCompleted: clicked.connect(buttonPressed)}
        }
        Row {
            spacing: 3
            anchors.horizontalCenter: parent.horizontalCenter
            Button { text: "a"; op: "a"; shiftText: "@"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "s"; op: "s"; shiftText: "#"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "d"; op: "d"; shiftText: "%"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "f"; op: "f"; shiftText: "&"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "g"; op: "g"; shiftText: "*"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "h"; op: "h"; shiftText: "-"; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "j"; op: "j"; shiftText: "+"; shiftOp: "+" ; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "k"; op: "k"; shiftText: "="; shiftOp: "=" ; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "l"; op: "l"; shiftText: "/"; shiftOp: "/" ; Component.onCompleted: clicked.connect(buttonPressed)}
        }
        Row {
            spacing: 3
            anchors.horizontalCenter: parent.horizontalCenter
            Button { text: "z"; op: "z"; shiftText: "_"; shiftOp: "_" ; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "x"; op: "x"; shiftText: "$"; shiftOp: "$" ; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "c"; op: "c"; shiftText: "^"; shiftOp: "%" ; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "v"; op: "v"; shiftText: "\""; shiftOp: "&" ; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "b"; op: "b"; shiftText: "\'"; shiftOp: "*" ; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "n"; op: "n"; shiftText: ":"; shiftOp: "-" ; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "m"; op: "m"; shiftText: ";"; shiftOp: "+" ; Component.onCompleted: clicked.connect(buttonPressed)}
        }
        Row {
            spacing: 3
            anchors.horizontalCenter: parent.horizontalCenter
            Button { text: upperArrow; op: upperArrow ; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { text: "Alt"; op: "" ; Component.onCompleted: clicked.connect(buttonPressed)}
            Button { width: 150; height: vk.h; text: "Space"; op: " "; Component.onCompleted: clicked.connect(buttonPressed) }
            Button { width: 80; text: ".com"; op: ".com"; Component.onCompleted: clicked.connect(buttonPressed) }
            Button { text: leftArrow; op: leftArrow; Component.onCompleted: clicked.connect(buttonPressed) }
        }
    }

    states: [
        State {
            name: "active"
            PropertyChanges { target: vk; y: (surface.height - vkc.height); }
        },
        State {
            name: "inactive"
            PropertyChanges { target: vk; y: surface.height + 8; }
        }
    ]

    transitions: Transition {
        NumberAnimation {
            target: vk
            property: "y"
            easing.type: "OutQuad"
            duration: 250
        }
    }
}
