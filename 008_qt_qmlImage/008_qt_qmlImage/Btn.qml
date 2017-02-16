import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Button {
    id: root
    height: 40
    style: ButtonStyle{
        label:Text {
            font.family: "微軟正黑體"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pointSize: 10
            text: control.text
        }
    }
}
