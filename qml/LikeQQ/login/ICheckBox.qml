import QtQuick 1.1

Item{
   id:btnBg
   width: img.paintedWidth + text.paintedWidth
   height: 20
   property bool isChecked:false
   property string checkSource:"qrc:/image/check_"
   property string checkText:"记住密码"
   property string textColor :"#217827"
   property bool canChecked :true
   signal signalItemClicked(bool isClick);
   Image{
       id:img
       source: checkSource + "no_n.png"
       anchors.verticalCenter: parent.verticalCenter
       smooth: true
       MouseArea{
           anchors.fill: parent
           anchors.margins: -2
           enabled: canChecked
           hoverEnabled: canChecked
           onEntered: {
               if(isChecked){
                   img.source = checkSource + "p.png"
               }else{
                   img.source = checkSource + "no_p.png"
               }
           }
           onExited: {
               if(isChecked){
                   img.source = checkSource + "n.png"
               }else{
                   img.source = checkSource + "no_n.png"
               }
           }
           onClicked: {
               if(canChecked){
                  isChecked = !isChecked;
               }
               signalItemClicked(isChecked);
           }
       }
   }
   Text{
       id: text
       anchors.verticalCenter: parent.verticalCenter
       text: checkText
       anchors.left: img.right
       anchors.leftMargin: 3
       color:textColor
       font.family: "微软雅黑"
   }
   onIsCheckedChanged:{
       if(isChecked){
           img.source = checkSource + "n.png"
       }else{
           img.source = checkSource + "no_n.png"
       }
   }
   function getDataOut()
   {
        if(isChecked)
        {
            return text.text;
        }else{
            return "";
        }
   }
   function getDataOutFinally()
   {
        if(isChecked)
        {
//            return (text.text);
            return "1"
        }else{
//            return ""
            return "2"
        }
   }
}
