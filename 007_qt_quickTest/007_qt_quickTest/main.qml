import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.3

Window {
    visible: true
    id: root
    width: 640
    height: 480
    title: qsTr("Hello World")

    Slider {
       id: ss
       width: parent.width
       anchors.bottom: parent.bottom
       minimumValue: 0
       maximumValue: 360
       onValueChanged: {
           rr.rotation = ss.value
       }
    }

    Button {
        id: reset
        Text{
            text: "reset"
            font.family: "微軟正黑體"
            anchors.centerIn: parent
        }
        onClicked: {
            tt.text = "Hello"
            tt.color = "white"
            ss.value = 0
        }
    }

    Rectangle{
        id: rr
        width: 100
        height: 100
        color: "red"//TODO: change to "blue"
        anchors.centerIn: parent
        //FIXME: GG
        MouseArea {
            anchors.fill: parent//NOTE: must exist
            onClicked: {
                tt.text = "blue"
                tt.color = "blue"
            }
        }

        Text{
            id: tt
            anchors.centerIn: rr
            font.family: "微軟正黑體"
            font.bold: true
            font.pointSize: 16
            text: "Hello"
            color: "white"
        }
        Image {
            id: ii
            source: "/image/qtlogo.png"
            anchors.top: parent.bottom
        }
    }
}
