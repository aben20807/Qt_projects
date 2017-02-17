import QtQuick 2.0

Rectangle {
    id: root
    property alias text: label.text
    //alias宣告一個變數名稱讓外部可以呼叫這一個變數
    signal clicked
    //signal宣告可以讓外部呼叫clicked這一個信號
    signal pressed
    signal entered
    signal exited
    signal released
    signal canceled
    signal pressAndHold

    width   : 120
    height  : 25
    color: "lightsteelblue"
    border.color: "slategrey"

    Text {
        id: label
        anchors.centerIn: parent
        text: "Start"
        font.family: "微軟正黑體"
        font.bold: true
        font.pointSize: 24
    }
    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        //表示可執行左鍵與右鍵功能
        hoverEnabled:true
        //與signal的onEntered()有關
        onClicked: {
            root.clicked()
        }
        onPressed: {
            root.pressed()
            if (mouse.button == Qt.RightButton){
                //右鍵更換背景顏色
                parent.color = "blue"
            }
            else{
                parent.color = "#4f8bd3"
            }
        }
        onEntered: {
            root.entered()
            root.color = "#6fabf3"
            root.border.color = "gray"
            root.border.width = 3
        }
        onExited: {
            root.exited()
            root.color = "lightsteelblue"
            parent.border.width = 0
        }

        onReleased: {
            root.released()
            root.color = "#6fabf3"
            root.border.color = "slategrey"
        }
        onCanceled: {
            root.canceled()
        }
        onPressAndHold: {
            root.pressAndHold()
        }

        //Signal Documentation
        //onCanceled()-當滑鼠事件被攔截時調用
        //onClicked()-滑鼠點擊一下時調用
        //onDoubleClicked()-滑鼠點擊兩下時調用
        //onEntered()-滑鼠進入指定區域時調用
        //onExited()-滑鼠離開指定區域時調用
        //onPositionChanged()-滑鼠位置產生變化時調用
        //onPressAndHold()-滑鼠按住超過800ms時調用
        //onPressed()-滑鼠點擊按下時調用
        //onReleased()-滑鼠點擊放開時調用
    }
}
