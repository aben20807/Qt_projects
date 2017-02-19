import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("011")
    FontDialog {
        id: fontDialog
        modality: Qt.WindowModal
        title: "挑個字型~"
        font.family: "微軟正黑體"
        font.pointSize: 14
    }
    ColorDialog {
        id: colorDialog
        modality: Qt.WindowModal
        title: "挑個顏色~"
        color: "blue"
    }
    Column {
        anchors.fill: parent
        anchors.margins: 7
        Row {
            id: toolBar
            width: parent.width
            Button {
                id:font
                height: 40
                Text {
                    id: btn1
                    anchors.centerIn: parent
                    text: qsTr("字型")
                    font.family: "微軟正黑體"
                    font.pointSize: 14
                }
                onClicked: {
                    fontDialog.open()
                }
            }
            Button {
                id:color
                height: 40
                Text {
                    id: btn2
                    anchors.centerIn: parent
                    text: qsTr("顏色")
                    font.family: "微軟正黑體"
                    font.pointSize: 14
                }
                onClicked: {
                    colorDialog.open()
                }
            }
            TextField {
                id: input
                height: 40
                width: parent.width - (font.width + color.width)
                text: "輸入文字...."
                font.family: "微軟正黑體"
                font.pointSize: 14
            }
        }
        Rectangle {
            id: frame2
            width: parent.width
            height: parent.height - toolBar.height
            border.color: "gray"
            border.width: 2
            Text {
                id: display
                anchors.centerIn: parent
                text: input.text
                font: fontDialog.font
                color: colorDialog.color
            }
        }
    }
}
