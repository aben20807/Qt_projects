import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4

Window {
    visible: true
    width: 640
    height: 480
    id: root
    title: qsTr("009")

    Column {
        id: col
        anchors.fill: parent
        anchors.margins: 5
        spacing: 3
        Rectangle {
            id: frame1
            width: parent.width
            height: 40
            border.color: "gray"
            border.width: 4
            TextInput {
                id: txtPlain
                font.family: "微軟正黑體"
                font.pointSize: 10
                anchors.fill: parent
                anchors.margins: 5
                verticalAlignment: Text.AlignVCenter
                onTextChanged: {
                    txtEncode.text = Qt.btoa(txtPlain.text)
                }
            }
        }
        Rectangle {
            id: frame2
            width: parent.width
            height: parent.height - (frame1.height + col.spacing)
            border.color: "gray"
            border.width: 4
            TextArea {
                id: txtEncode
                font.family: "微軟正黑體"
                font.pointSize: 10
                anchors.fill: parent
                anchors.margins: 5
            }
        }
    }
}
