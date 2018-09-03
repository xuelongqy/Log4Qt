import QtQuick 2.11
import QtQuick.Controls 2.3
import com.knoyo.logger 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Log4Qt")

    Logger {
        id: logger
    }

    Item {
        anchors.fill: parent

        Column {
            anchors.centerIn: parent

            Button {
                text: "DEBUG"
                onClicked: {
                    logger.d("main.qml -> Log debug!")
                }
            }
            Button {
                text: "INFO"
                onClicked: {
                    logger.i("main.qml -> Log info!")
                }
            }
            Button {
                text: "WARNING"
                onClicked: {
                    logger.w("main.qml -> Log warning!")
                }
            }
            Button {
                text: "ERROR"
                onClicked: {
                    logger.e("main.qml -> Log error!")
                }
            }
        }
    }
}
