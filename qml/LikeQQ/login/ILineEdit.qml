import QtQuick 1.1

Item{
   id:lineEditBg
   height: imgBg.paintedHeight
   width: imgBg.paintedWidth
   property string imgSource: "qrc:/image/lineEdit_"
   property string userNam: "用户名"
   property alias defaultFocus:textIn.focus
   property alias defaultText:placeholder.text
   property alias loginTxt: textIn.text
   property int fontSize:14
   property bool pswModel: false
   property string wholeStr: ""
   signal signalTxtChanged();
   signal signalFoucs();
   signal signalShowKeyborad();

   property string rotateLeft: "\u2939"
   property string rotateRight: "\u2935"
   property string leftArrow: "\u2190"
   property string upperArrow: "\u2191"
   property string division : "\u00f7"
   property string multiplication : "\u00d7"
   property string squareRoot : "\u221a"
   property string plusminus : "\u00b1"

   Image{
       id:imgBg
       source:imgSource + "n.png"
   }
   Text {
       id: placeholder
       font.pixelSize: 12//fontSize
       verticalAlignment:Text.AlignVCenter
       visible:(!textIn.activeFocus && textIn.displayText.length==0)
       anchors.fill: lineEditBg
       anchors.margins:5
       color:"#A0A0A0"
   }
   TextInput{
       id:textIn
       anchors.fill: lineEditBg
       anchors.margins: 7
       font.pixelSize:fontSize
       color: pswModel?("#217827"):("#313131")
       anchors.centerIn:imgBg
       echoMode:pswModel?(TextInput.Password):(TextInput.Normal)
       onActiveFocusChanged: {
           if(textIn.activeFocus){
               imgBg.source = imgSource + "p.png";
//               if(!pswModel)
//               {
                   signalFoucs();
//               }
           }else{
               imgBg.source = imgSource + "n.png"
           }
       }
       onTextChanged: {
           signalTxtChanged();
       }
   }
   Image {
       id: keyBorad
       source: "qrc:/image/keyboard.png"
       anchors.right: parent.right
       anchors.rightMargin: 2
       visible: pswModel
       MouseArea{
           anchors.fill: parent
           onClicked: {
               signalShowKeyborad();
           }
       }
   }
   function setFoucs(){
       textIn.forceActiveFocus();
   }
//   function setTxt(str)
//   {
//       wholeStr +=str;
//       textIn.text = wholeStr;
//   }
   function setTxt(op) {
       var t = (textIn.activeFocus ? textIn.text : textIn.text)

       if (op == leftArrow) {
           t = t.toString().slice(0, -1)
           if (t.length == 0) {
               t = ""
           }
       } else {
           t = t + op.toString()
       }

       textIn.activeFocus ? (textIn.text = t) : (textIn.text = t)
   }
}
