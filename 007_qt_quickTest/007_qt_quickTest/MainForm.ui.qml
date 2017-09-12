import QtQuick 2.5

Rectangle {
    property alias mouseArea: mouseArea
    property alias textEdit: textEdit

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.rightMargin: 1
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
    }

    TextEdit {
        id: textEdit
        text: qsTr("Enter some text...")
        anchors.horizontalCenterOffset: 0
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 33
        Rectangle {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            anchors.rightMargin: -10
            anchors.bottomMargin: -10
            anchors.leftMargin: -10
            anchors.topMargin: -10
            border.width: 1
        }
    }
}
