import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

Window {
    visible: true
    width: 640
    height: 480
    id: root
    title: qsTr("010")
    property int clickNum: 0
    Column {
        id: col
        anchors.fill: parent
        anchors.margins: 7
        Rectangle {
            id: frame
            width: parent.width
            border.color: "gray"
            height: root.height * 3/4
            Text {
                id: output
                anchors.fill: parent
                font.family: "微軟正黑體"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 50
                state: "face0"
                states: [
                    State {
                        name: "face0"
                        PropertyChanges {
                            target: output
                            text: "(´  ･ω･  `)"
                        }
                    },
                    State {
                        name: "face1"
                        PropertyChanges {
                            target: output
                            text: "(´  ･ω･`)"
                        }
                    },
                    State {
                        name: "face2"
                        PropertyChanges {
                            target: output
                            text: "(´･ω･  `)"
                        }
                    },
                    State {
                        name: "face3"
                        PropertyChanges {
                            target: output
                            text: "((ﾟДﾟ；))"
                        }
                    },
                    State {
                        name: "face4"
                        PropertyChanges {
                            target: output
                            text: "((；ﾟДﾟ))"
                        }
                    },
                    State {
                        name: "face5"
                        PropertyChanges {
                            target: output
                            text: "((；ﾟДﾟ；))"
                        }
                    },
                    State {
                        name: "face6"
                        PropertyChanges {
                            target: output
                            text: "-`д´-"
                        }
                    },
                    State {
                        name: "face7"
                        PropertyChanges {
                            target: output
                            text: "凸(｀⌒´メ)凸"
                        }
                    },
                    State {
                        name: "face8"
                        PropertyChanges {
                            target: output
                            text: "Ψ(☆ｗ☆)Ψ"
                        }
                    },
                    State {
                        name: "face9"
                        PropertyChanges {
                            target: output
                            text: "_(:3」∠)_"
                        }
                    }
                ]
            }
        }
        Button {
            id: btn
            text: "不要按"
            width: parent.width
            height: root.height - (frame.height + 14)
            onClicked: {
                clickNum++
                if(clickNum < 10){
                    output.state = "face"+clickNum%3
                }
                else if(clickNum < 20){
                    output.state = "face"+(clickNum%3 + 3)
                    btn.text = "就說不要按了"
                }
                else if(clickNum < 25){
                    output.state = "face6"
                    btn.text = "生氣囉"
                }
                else if(clickNum < 30){
                    output.state = "face7"
                    btn.text = "還按 凸"
                }
                else if(clickNum < 35){
                    output.state = "face8"
                    btn.text = "...."
                }
                else if(clickNum < 40){
                    output.state = "face9"
                    btn.text = "我輸了...."
                }
                else{
                    clickNum = 0
                    subWindow.open()
                }
            }
        }
    }
    Window {
        id: subWindow
        title: "快離開ˋˊ"
        width: 400
        height: 200
        visible: false
        function open(){
            visible = true
        }
        function close(){
            visible = false
        }
        Column {
            anchors.fill: parent
            anchors.margins: 7
            Text {
                id: t
                width: parent.width
                height: subWindow.height * 2/3
                text: qsTr("不玩了，自己按OK離開吧(´･ω･`)")
                font.family: "微軟正黑體"
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 12
                horizontalAlignment: Text.AlignHCenter
            }
            Button {
                text: "OK"
                width: parent.width
                height: subWindow.height - (t.height+14)
                onClicked: {
                    subWindow.close()
                    Qt.quit()
                }
            }
        }
    }
}
