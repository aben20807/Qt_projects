import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    id: root
    visible: true
    visibility: Window.Maximized//Maximized window init
    title: qsTr("008")
    Rectangle{
        id: view
        width: root.width
        height: root.height
        AnimatedImage {
            id: pigeon
            source: "/gif/pigeon"
            anchors.centerIn: view
        }
    }

    Column {
        Row {
            Btn {
                text: "Reset"
                onClicked: {
                    pigeon.fillMode = Image.Stretch
                    pigeon.width = pigeon.sourceSize.width
                    pigeon.height = pigeon.sourceSize.height
                    pigeon.anchors.centerIn = view
                    pigeon.clip = false
                }
            }

            Btn {
                text: "Stretch"
                onClicked: {
                    pigeon.fillMode = Image.Stretch
                    pigeon.width = pigeon.sourceSize.width * 1.5
                    pigeon.height = pigeon.sourceSize.height / 2
                }
            }

            Btn {
                text: "PreserveAspectFit"
                onClicked: {
                    pigeon.fillMode = Image.PreserveAspectFit
                    pigeon.width = pigeon.sourceSize.width * 1.5
                    pigeon.height = pigeon.sourceSize.height / 2
                }
            }

            Btn {
                text: "PreserveAspectCrop"
                onClicked: {
                    pigeon.fillMode = Image.PreserveAspectCrop
                    pigeon.width = pigeon.sourceSize.width * 1.5
                    pigeon.height = pigeon.sourceSize.height / 2
                    pigeon.clip = true
                }
            }

            Btn {
                text: "Tile"
                onClicked: {
                    pigeon.fillMode = Image.Tile
                    pigeon.width = view.width
                    pigeon.height = view.height
                }
            }

            Btn {
                text: "TileHorizontally"
                onClicked: {
                    pigeon.fillMode = Image.TileHorizontally
                    pigeon.width = view.width
                    pigeon.height = view.height
                }
            }

            Btn {
                text: "TileVertically"
                onClicked: {
                    pigeon.fillMode = Image.TileVertically
                    pigeon.width = view.width
                    pigeon.height = view.height
                }
            }
        }
    }
}
