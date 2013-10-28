import QtQuick 1.1

Image{
   id:btnBg
   property string imgSource: "qrc:/image/close_"

   source:imgSource + "n.png"
   signal signalClicked();
   MouseArea{
       anchors.fill: parent
       hoverEnabled: true
       onEntered: {
           btnBg.source = imgSource + "h.png"
       }
       onExited: {
           btnBg.source = imgSource + "n.png"
       }
       onPressed:{
           btnBg.source = imgSource + "p.png"
       }
       onReleased: {
           btnBg.source = imgSource + "n.png"
       }
       onClicked: {
           signalClicked();
       }
   }
}
