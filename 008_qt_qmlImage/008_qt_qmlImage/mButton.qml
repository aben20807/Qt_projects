import QtQuick 2.5
import QtQuick.Controls 1.4

Item {
    id: root
    Button {
        anchors.fill: parent
        Text {
            id: text
            font.family: "微軟正黑體"
            font.pointSize: 16
            anchors.centerIn: parent
        }
    }
}
